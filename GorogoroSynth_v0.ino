#include <Mozzi.h>
#include <Oscil.h>
#include <tables/sin2048_int8.h>
#include <tables/smoothsquare8192_int8.h>
#include <tables/square_no_alias_2048_int8.h>
#include <tables/Goro.h>
#include <ADSR.h>
#include <EventDelay.h>
#include <LowPassFilter.h>

#define CONTROL_RATE 64

//Oscil <SIN2048_NUM_CELLS, MOZZI_AUDIO_RATE> Goro(SIN2048_DATA);
//Oscil <SQUARE_NO_ALIAS_2048_NUM_CELLS, AUDIO_RATE> Goro(SQUARE_NO_ALIAS_2048_DATA);
Oscil <SIN2048_NUM_CELLS, MOZZI_AUDIO_RATE> lfoSin(SIN2048_DATA);
Oscil <SMOOTHSQUARE8192_NUM_CELLS, MOZZI_AUDIO_RATE> lfoSq(SMOOTHSQUARE8192_DATA);
Oscil <Goro2_NUM_CELLS, MOZZI_AUDIO_RATE> Goro(Goro2_DATA);
ADSR <AUDIO_RATE, AUDIO_RATE> envelope;
EventDelay timer;
LowPassFilter lpf;

int input_vco_freq;
int input_lfo_modDepth;
int input_lfo_freq;
bool input_lfo_wave;
bool input_lfo_wave_past;
int input_env_attack;
int input_env_release;
bool input_env_on;
bool input_env_on_past;
int input_vcf_freq;
int input_vcf_res;
int input_vcf_modDepth;

float vco_freq;
float lfo_modDepth;
float lfo_freq;
bool lfo_wave;
int env_attack;
int env_release;
bool env_on;
byte vcf_freq;
uint8_t vcf_res;
int vcf_modDepth;

//const int BasicFrequency = (float) Goro_SAMPLERATE / (float) Goro_NUM_CELLS;

void setup() {
  // put your setup code here, to run once:
  //Serial.begin(9600);
  startMozzi(CONTROL_RATE);
  pinMode(2,INPUT);
  pinMode(3,INPUT);

  input_lfo_wave_past = false;
  lfo_wave = true;
  input_env_on_past = false;
  env_on = false;
  envelope.setADLevels(255,255);
  timer.set(1000);
  timer.start();
}

void updateControl(){
  input_vco_freq = mozziAnalogRead(0);
  input_lfo_modDepth = mozziAnalogRead(1);
  input_lfo_freq = mozziAnalogRead(5);
  input_lfo_wave = digitalRead(2);
  input_env_attack = mozziAnalogRead(6);
  input_env_release = mozziAnalogRead(7);
  input_env_on = digitalRead(3);
  input_vcf_freq = mozziAnalogRead(2);
  input_vcf_res = mozziAnalogRead(3);
  input_vcf_modDepth = mozziAnalogRead(4);

  vco_freq = pow(2,input_vco_freq/128.00);
  lfo_modDepth = map(input_lfo_modDepth,0,1023,0,10);
  lfo_freq = pow(2,input_lfo_freq/256.00);
  if(input_lfo_wave_past && !(input_lfo_wave)){
    lfo_wave = !(lfo_wave);
  }

  env_attack = map(input_env_attack,0,1023,5,2000);
  env_release = map(input_env_release,0,1023,5,2000);
  if(input_env_on_past && !(input_env_on)){
    env_on = !(env_on);
  }
  envelope.setTimes(env_attack,0,0,env_release);
  if(timer.ready()){
    envelope.noteOn();
    timer.set(env_attack + env_release + 10);
    timer.start();
  }

  vcf_freq = map(input_vcf_freq,0,1023,0,250); //0-8191Hz
  vcf_res = (uint8_t)map(input_vcf_res,0,1023,0,255);
  vcf_modDepth = map(input_vcf_modDepth,0,1023,0,4);
  vcf_freq += vcf_modDepth * lfoSin.next() >> 6;
  lpf.setCutoffFreqAndResonance(vcf_freq, vcf_res);

  Goro.setFreq(vco_freq);
  lfoSin.setFreq(lfo_freq);
  lfoSq.setFreq(lfo_freq);
  /*
  Serial.print(vco_freq);
  Serial.print(" ");
  Serial.print(lfo_modDepth);
  Serial.print(" ");
  Serial.print(lfo_freq);
  Serial.print(" ");
  Serial.println(lfo_wave);
  Serial.print(env_attack);
  Serial.print(" ");
  Serial.print(env_release);
  Serial.print(" ");
  Serial.println(env_on);
  Serial.print(input_vcf_freq);
  Serial.print(" ");
  Serial.print(input_vcf_res);
  Serial.print(" ");
  Serial.println(input_vcf_modDepth);
  Serial.print(vcf_freq);
  Serial.print(" ");
  Serial.println(vcf_res);
  */

  input_lfo_wave_past = input_lfo_wave;
  input_env_on_past = input_env_on;
}

AudioOutput updateAudio(){
  envelope.update();
  Q15n16 vibrato = 0;
  if(lfo_wave){
    vibrato = (Q15n16) lfo_modDepth * lfoSin.next();
  }else{
    vibrato = (Q15n16) lfo_modDepth * lfoSq.next();
  }

  if(env_on){
    return lpf.next(Goro.phMod(vibrato)*envelope.next()>>8);
  }else{
    return lpf.next(Goro.phMod(vibrato));
  }

  return Goro.next();
}

void loop() {
  // put your main code here, to run repeatedly:
  audioHook();
}

