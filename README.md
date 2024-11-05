# GorogoroSynth_v0
![GorogoroSynth_v0](https://github.com/user-attachments/assets/19989741-cda9-4059-a5a5-6a29002c87d0)

## 使用技術
Arduino(C/C++),電子回路

## 制作時期
2024年秋-(今後もv1制作に向けて継続)

## 概要
猫のゴロゴロ声(purring-sound)を基本波形に用いたシンセサイザ

## 使用例
後日収録

## 特徴
1. 猫のゴロゴロ声(本物)で音作りができる
2. VCO,VCF,VCA,LFO,EG(ARのみ)を実装
3. 音声は全てArduinoでの信号処理によって生成(Mozziライブラリによる実装)

## 機能
(配線省略)
![GorogoroSynth_function](https://github.com/user-attachments/assets/abac1af6-68f9-41f5-ac75-a66fdecc9e02)
GorogoroSynthは、ノイズトースターと呼ばれるアナログシンセサイザの機能(の一部)を実装したものです。ノイズトースターの詳細については、『Make: Analog Synthesizers』をご参照ください。  
1. VCO：基本波形の生成に関わる。左から周波数コントローラー(Frequency)、周波数変調コントローラ(LFO ModDepth)。
2. LFO：周波数変調に関わる。VCOよりも低周波数の振動を生成する。左から変調レートコントローラー(Rate)、波形切り替えボタン(Waveform Select)、正弦波と矩形波を切り替えることが出来る。
3. EG：エンベロープの生成に関わる。ここではアタック(A)とリリース(R)を設定し、ゲインの変化に反映できる。左からアタックコントローラー(Attack)、リリースコントローラ(Release)、エンベロープON/OFFボタン。コントローラはそれぞれの時間幅を指定する。ボタンはONであればゲインにエンベロープを反映する。
4. VCF：波形の倍音成分の調整に関わる。左からカットオフ周波数コントローラ(Cutoff Frequency)、レゾナンスコントローラー(Resonance)、カットオフ周波数変調度コントローラ(Mod Depth)。カットオフ周波数以上の高音成分は抑制される。レゾナンスが高いほどカットオフ周波数付近の成分は強調される。

## 改善点・今後の展望
1. 基板上での実装：邪魔なジャンプワイヤーを省いて使いやすくする
2. レイアウト・デザインを整える：見栄えをよくする、操作性を上げる
3. ノイズの改善：クリップノイズが時折見られるので、コードを見直す
4. エフェクタの作成：リバーブ、ディレイ、コンプレッサなどの機能を実装する
5. MIDIキーボードとの接続：作った音で実際に演奏できるようにする
6. 他の生物の声の実装：犬の唸り声、蝉の鳴き声、鈴虫の声など

## 参照
1. 『Make: Analog Synthesizers』(オライリー・ジャパン、Ray Wilson)
2. 『Mozzi Documentation』(https://sensorium.github.io/Mozzi/doc/html/index.html)
3. 『Pythonではじめる音のプログラミング』(オーム社、青木直史)
