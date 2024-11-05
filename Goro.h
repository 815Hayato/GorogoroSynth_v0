#ifndef Goro2_H_
#define Goro2_H_
 
#include <Arduino.h>
#include "mozzi_pgmspace.h"
 
#define Goro2_NUM_CELLS 8192
#define Goro2_SAMPLERATE 8192
 
CONSTTABLE_STORAGE(int8_t) Goro2_DATA [] = {0, 1, 1, 2, 4, 6, 8, 9, 11, 12, 13,
14, 16, 17, 19, 20, 21, 22, 23, 23, 24, 24, 24, 25, 25, 25, 25, 25, 25, 25, 26,
26, 26, 26, 26, 26, 27, 27, 26, 27, 27, 27, 27, 27, 27, 27, 26, 25, 24, 24, 22,
22, 21, 21, 20, 20, 19, 18, 17, 17, 16, 16, 15, 14, 14, 13, 12, 12, 12, 12, 11,
11, 11, 11, 11, 10, 9, 9, 9, 8, 7, 7, 7, 6, 7, 7, 6, 7, 7, 7, 6, 7, 6, 8, 9, 10,
18, 26, 28, 39, 61, 67, 71, 73, 68, 62, 59, 57, 53, 56, 59, 61, 60, 58, 55, 51,
50, 51, 51, 51, 52, 51, 50, 49, 48, 46, 46, 45, 45, 45, 44, 43, 42, 40, 39, 38,
37, 36, 34, 33, 31, 30, 28, 27, 26, 25, 23, 22, 22, 21, 21, 19, 18, 18, 16, 16,
15, 13, 12, 11, 10, 8, 7, 5, 4, 3, 1, 0, -1, -3, -3, -4, -5, -6, -7, -8, -9,
-10, -11, -11, -12, -13, -14, -14, -15, -16, -16, -17, -18, -19, -20, -21, -21,
-22, -22, -23, -24, -24, -24, -25, -25, -26, -26, -26, -27, -27, -27, -27, -27,
-28, -28, -28, -28, -29, -29, -29, -29, -29, -29, -29, -29, -28, -28, -28, -29,
-28, -28, -28, -28, -28, -28, -28, -28, -28, -28, -29, -28, -29, -28, -28, -28,
-28, -29, -29, -30, -30, -30, -30, -30, -31, -32, -33, -34, -35, -36, -38, -39,
-40, -41, -43, -45, -47, -48, -50, -53, -56, -59, -62, -65, -69, -73, -78, -82,
-87, -91, -95, -100, -104, -109, -114, -117, -119, -121, -122, -123, -122, -121,
-117, -112, -102, -88, -69, -51, -38, -32, -31, -33, -36, -34, -31, -24, -17,
-11, -7, -6, -7, -7, -6, -4, 1, 5, 9, 12, 14, 15, 16, 18, 20, 22, 24, 25, 25,
25, 24, 24, 23, 23, 23, 22, 22, 21, 20, 19, 18, 18, 18, 17, 18, 17, 17, 17, 17,
17, 16, 16, 16, 16, 15, 15, 15, 13, 13, 12, 11, 11, 10, 9, 9, 8, 7, 6, 6, 5, 5,
4, 4, 3, 3, 3, 2, 2, 2, 2, 2, 2, 1, 0, 0, 1, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 1, 0,
0, -1, 0, -1, -1, -1, -2, -2, -1, -2, -2, -2, -1, 1, 1, 4, 13, 19, 20, 42, 61,
64, 70, 68, 62, 56, 55, 50, 50, 54, 57, 58, 55, 52, 47, 44, 44, 45, 45, 46, 46,
45, 44, 43, 41, 40, 40, 40, 38, 37, 36, 34, 33, 33, 31, 30, 29, 26, 25, 24, 22,
21, 20, 18, 18, 17, 16, 15, 14, 13, 12, 11, 10, 9, 8, 7, 5, 5, 3, 2, 0, -1, -3,
-4, -6, -8, -9, -10, -11, -13, -14, -15, -16, -17, -17, -18, -19, -20, -20, -21,
-22, -22, -23, -24, -25, -25, -26, -26, -27, -27, -28, -28, -29, -30, -30, -31,
-32, -32, -32, -33, -34, -34, -34, -35, -35, -34, -34, -34, -34, -35, -36, -36,
-36, -36, -36, -36, -37, -37, -37, -37, -37, -37, -37, -36, -36, -36, -36, -36,
-37, -36, -37, -36, -36, -35, -35, -35, -35, -35, -35, -35, -36, -36, -36, -36,
-36, -37, -37, -37, -38, -38, -39, -40, -40, -41, -41, -42, -44, -45, -47, -48,
-51, -53, -56, -58, -60, -65, -69, -73, -79, -83, -89, -95, -100, -105, -110,
-114, -118, -122, -123, -124, -126, -127, -128, -126, -123, -117, -107, -93,
-73, -51, -35, -27, -24, -26, -30, -30, -27, -20, -12, -4, 1, 4, 4, 2, 2, 4, 8,
13, 18, 22, 25, 27, 28, 29, 31, 32, 34, 35, 36, 38, 38, 38, 38, 38, 38, 38, 38,
38, 37, 36, 36, 37, 37, 37, 37, 37, 37, 37, 36, 36, 36, 36, 36, 36, 36, 36, 36,
35, 35, 35, 35, 34, 33, 32, 31, 30, 30, 29, 28, 28, 28, 28, 28, 27, 27, 26, 25,
25, 24, 25, 25, 25, 25, 24, 24, 23, 23, 23, 22, 22, 22, 22, 22, 22, 23, 22, 23,
23, 22, 21, 21, 21, 20, 20, 21, 21, 21, 21, 22, 22, 26, 33, 40, 41, 55, 82, 88,
94, 95, 88, 81, 78, 75, 71, 76, 80, 83, 81, 78, 72, 68, 66, 67, 68, 68, 69, 68,
67, 66, 65, 63, 64, 64, 63, 62, 61, 59, 57, 57, 56, 54, 52, 51, 49, 47, 45, 43,
41, 41, 40, 38, 37, 35, 34, 33, 32, 31, 30, 29, 28, 26, 25, 23, 22, 20, 18, 17,
15, 14, 12, 10, 10, 8, 6, 6, 4, 3, 2, 1, -1, -2, -3, -4, -5, -5, -6, -6, -8, -8,
-9, -10, -11, -12, -12, -13, -14, -15, -15, -16, -17, -18, -18, -20, -20, -20,
-21, -21, -22, -23, -23, -23, -24, -24, -24, -24, -25, -25, -25, -25, -26, -26,
-26, -26, -26, -26, -26, -26, -26, -26, -26, -26, -26, -26, -25, -25, -25, -26,
-25, -26, -26, -26, -25, -25, -26, -25, -25, -26, -26, -26, -27, -27, -28, -28,
-30, -31, -32, -33, -34, -37, -38, -40, -43, -45, -48, -52, -55, -58, -62, -66,
-71, -75, -79, -85, -90, -95, -101, -106, -110, -112, -113, -114, -115, -116,
-117, -116, -113, -105, -95, -82, -65, -47, -34, -25, -21, -21, -21, -20, -17,
-11, -5, 1, 6, 8, 9, 9, 9, 12, 15, 19, 23, 26, 29, 31, 32, 33, 35, 37, 38, 39,
40, 40, 40, 40, 39, 39, 37, 37, 36, 36, 36, 35, 35, 35, 34, 34, 33, 33, 32, 33,
34, 34, 34, 33, 33, 32, 32, 32, 31, 31, 30, 29, 28, 27, 26, 24, 24, 23, 22, 21,
20, 20, 19, 18, 17, 17, 16, 15, 15, 13, 13, 11, 10, 9, 8, 7, 5, 4, 3, 2, 1, -1,
-2, -2, -4, -5, -6, -7, -8, -9, -10, -11, -11, -12, -13, -14, -14, -15, -16,
-17, -18, -18, -19, -20, -21, -21, -22, -22, -23, -24, -24, -25, -25, -25, -26,
-26, -26, -27, -27, -27, -27, -28, -28, -28, -28, -28, -29, -29, -29, -29, -29,
-29, -29, -28, -28, -28, -28, -28, -28, -29, -28, -28, -28, -28, -28, -28, -28,
-29, -29, -29, -28, -28, -28, -28, -29, -29, -29, -30, -30, -30, -30, -31, -31,
-32, -33, -34, -35, -37, -38, -39, -41, -42, -44, -46, -47, -49, -51, -55, -57,
-60, -64, -67, -71, -75, -79, -84, -89, -93, -97, -102, -107, -111, -115, -118,
-120, -121, -122, -123, -122, -120, -115, -108, -96, -80, -61, -44, -34, -31,
-32, -35, -35, -33, -28, -21, -14, -9, -6, -6, -7, -7, -5, -2, 3, 7, 10, 13, 15,
15, 17, 19, 21, 23, 24, 25, 25, 24, 24, 23, 23, 23, 23, 22, 22, 21, 20, 19, 18,
18, 17, 17, 18, 17, 17, 17, 17, 17, 16, 16, 16, 16, 15, 15, 14, 13, 13, 12, 11,
10, 9, 9, 8, 7, 6, 6, 6, 5, 5, 4, 4, 3, 3, 3, 2, 2, 2, 2, 2, 1, 0, 0, 0, 1, 0,
1, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0, -1, -1, 0, -1, -1, -1, -2, -2, -2, -2, -2, -2,
0, 1, 2, 8, 17, 18, 27, 53, 62, 67, 70, 65, 59, 56, 54, 49, 52, 55, 58, 56, 53,
49, 45, 44, 45, 45, 45, 46, 45, 44, 44, 42, 41, 40, 40, 39, 38, 37, 35, 34, 33,
32, 31, 30, 28, 25, 25, 23, 22, 21, 19, 18, 18, 17, 15, 15, 14, 12, 12, 11, 10,
9, 8, 6, 5, 4, 2, 1, -1, -2, -4, -5, -7, -8, -9, -11, -12, -14, -15, -15, -16,
-17, -18, -18, -19, -20, -20, -21, -22, -23, -24, -24, -25, -25, -26, -27, -27,
-27, -28, -28, -29, -30, -31, -31, -32, -32, -32, -33, -34, -34, -34, -35, -34,
-34, -34, -34, -35, -35, -36, -36, -36, -36, -36, -37, -37, -37, -37, -37, -37,
-37, -36, -36, -36, -36, -36, -36, -37, -37, -36, -36, -36, -35, -35, -35, -35,
-35, -35, -35, -36, -36, -37, -36, -37, -37, -36, -37, -38, -38, -39, -40, -40,
-41, -41, -43, -44, -46, -47, -49, -52, -54, -57, -59, -62, -67, -71, -76, -81,
-86, -92, -97, -102, -107, -112, -116, -120, -122, -123, -125, -126, -128, -127,
-125, -121, -113, -101, -84, -63, -43, -30, -25, -25, -28, -31, -29, -24, -16,
-8, -1, 3, 4, 3, 2, 3, 6, 11, 16, 20, 24, 26, 28, 29, 30, 31, 33, 35, 36, 37,
38, 38, 38, 38, 38, 38, 38, 38, 37, 37, 36, 36, 37, 37, 37, 37, 37, 37, 37, 36,
36, 36, 36, 36, 36, 36, 36, 35, 35, 35, 35, 34, 33, 33, 32, 31, 30, 29, 29, 28,
28, 28, 28, 28, 27, 26, 26, 25, 25, 24, 25, 25, 25, 25, 24, 23, 23, 23, 23, 22,
22, 22, 22, 22, 23, 22, 23, 23, 23, 22, 21, 21, 21, 20, 20, 21, 21, 21, 21, 22,
23, 29, 37, 41, 44, 69, 86, 90, 96, 92, 85, 79, 78, 72, 73, 78, 81, 83, 80, 76,
70, 67, 66, 68, 68, 69, 68, 67, 67, 65, 64, 63, 64, 64, 62, 61, 60, 58, 57, 56,
55, 53, 52, 50, 48, 46, 44, 42, 41, 40, 39, 38, 36, 35, 34, 33, 32, 31, 30, 29,
27, 26, 25, 22, 21, 20, 18, 17, 15, 13, 11, 10, 9, 7, 6, 5, 4, 2, 2, 0, -1, -3,
-3, -4, -5, -5, -6, -7, -8, -9, -10, -11, -12, -12, -13, -13, -14, -15, -16,
-17, -17, -18, -19, -20, -20, -21, -21, -22, -22, -23, -23, -24, -24, -24, -24,
-25, -25, -25, -25, -25, -26, -26, -26, -26, -26, -26, -27, -26, -26, -26, -26,
-26, -26, -25, -25, -25, -26, -26, -25, -26, -26, -26, -25, -25, -25, -25, -25,
-26, -26, -27, -27, -27, -28, -29, -30, -31, -32, -34, -35, -37, -39, -41, -44,
-46, -50, -53, -56, -60, -64, -68, -73, -77, -82, -88, -93, -98, -103, -108,
-111, -113, -114, -114, -115, -117, -117, -115, -110, -101, -90, -74, -57, -40,
-29, -22, -20, -21, -21, -19, -14, -9, -2, 3, 7, 9, 9, 9, 10, 13, 17, 21, 24,
27, 30, 32, 33, 34, 36, 37, 38, 39, 40, 40, 40, 39, 39, 38, 36, 36, 35, 35, 34,
33, 32, 32, 31, 30, 30, 30, 30, 30, 30, 30, 29, 29, 29, 28, 28, 28, 27, 27, 26,
25, 24, 24, 23, 21, 21, 20, 19, 19, 18, 17, 16, 15, 15, 14, 14, 14, 13, 12, 11,
10, 10, 9, 9, 9, 9, 9, 8, 8, 8, 8, 8, 8, 8, 9, 9, 9, 9, 9, 9, 8, 8, 8, 7, 8, 7,
7, 7, 7, 7, 8, 9, 13, 20, 29, 29, 52, 71, 73, 82, 78, 74, 68, 67, 62, 60, 64,
67, 69, 66, 63, 58, 55, 55, 55, 55, 56, 55, 54, 53, 52, 50, 50, 50, 50, 49, 48,
47, 45, 43, 42, 42, 40, 39, 37, 37, 35, 34, 33, 32, 32, 31, 30, 29, 29, 28, 27,
26, 25, 23, 21, 19, 18, 17, 16, 14, 12, 10, 9, 8, 5, 4, 2, 0, -1, -2, -4, -5,
-6, -8, -9, -10, -11, -12, -12, -13, -14, -15, -16, -16, -17, -18, -18, -19,
-20, -20, -21, -22, -23, -24, -24, -25, -26, -26, -27, -28, -28, -28, -29, -29,
-30, -31, -31, -32, -32, -32, -33, -34, -34, -34, -34, -34, -34, -34, -34, -35,
-35, -36, -36, -36, -36, -36, -37, -37, -37, -37, -37, -37, -37, -36, -36, -36,
-36, -36, -37, -37, -37, -36, -36, -36, -35, -35, -35, -35, -35, -35, -35, -36,
-36, -37, -36, -37, -37, -36, -37, -38, -38, -39, -40, -40, -41, -42, -44, -45,
-46, -48, -50, -52, -55, -57, -59, -64, -68, -72, -77, -82, -88, -93, -99, -104,
-108, -113, -117, -121, -123, -124, -125, -127, -128, -127, -124, -119, -110,
-97, -79, -57, -39, -28, -25, -26, -29, -31, -28, -22, -14, -6, 0, 4, 4, 2, 2,
3, 7, 12, 17, 21, 24, 27, 28, 29, 30, 32, 33, 35, 36, 37, 38, 38, 38, 38, 38,
38, 38, 38, 37, 37, 36, 36, 37, 37, 37, 37, 37, 37, 36, 36, 36, 36, 36, 36, 36,
36, 36, 35, 35, 35, 35, 34, 33, 32, 32, 30, 30, 29, 29, 28, 28, 28, 28, 28, 27,
26, 25, 25, 25, 24, 25, 25, 25, 25, 24, 23, 23, 23, 23, 22, 22, 22, 22, 22, 23,
22, 23, 23, 23, 22, 21, 21, 21, 20, 21, 21, 21, 21, 22, 22, 24, 30, 39, 41, 48,
76, 87, 92, 96, 90, 83, 78, 77, 71, 74, 79, 82, 82, 79, 74, 68, 66, 67, 68, 68,
69, 68, 67, 66, 65, 64, 63, 64, 63, 62, 61, 59, 57, 57, 56, 55, 53, 52, 50, 47,
45, 43, 42, 41, 40, 38, 37, 36, 34, 33, 33, 31, 31, 29, 28, 27, 25, 24, 22, 21,
19, 17, 16, 14, 12, 11, 10, 8, 7, 6, 5, 3, 2, 1, 0, -2, -3, -3, -5, -5, -5, -6,
-7, -8, -9, -10, -11, -12, -12, -13, -13, -15, -15, -16, -17, -17, -18, -19,
-20, -20, -21, -21, -22, -23, -23, -23, -24, -24, -24, -24, -25, -25, -25, -25,
-25, -26, -26, -26, -26, -26, -26, -27, -26, -26, -26, -26, -26, -26, -25, -25,
-25, -26, -25, -25, -26, -26, -25, -25, -26, -25, -25, -25, -26, -26, -27, -27,
-28, -28, -29, -31, -31, -33, -34, -36, -38, -40, -42, -45, -47, -51, -54, -57,
-61, -65, -69, -74, -78, -83, -89, -94, -99, -105, -109, -111, -113, -114, -114,
-116, -117, -116, -114, -108, -98, -86, -69, -52, -37, -27, -21, -21, -21, -21,
-18, -13, -7, -1, 5, 8, 9, 9, 9, 11, 14, 18, 22, 25, 28, 31, 32, 33, 34, 36, 38,
39, 40, 40, 40, 40, 39, 39, 37, 36, 36, 35, 34, 34, 33, 32, 31, 31, 30, 30, 30,
30, 30, 30, 30, 29, 29, 29, 28, 28, 28, 27, 27, 26, 25, 24, 23, 22, 21, 21, 20,
19, 18, 18, 17, 16, 15, 15, 14, 14, 14, 12, 12, 11, 10, 10, 9, 9, 9, 9, 9, 8, 8,
8, 8, 8, 8, 8, 9, 9, 9, 9, 9, 9, 8, 9, 8, 8, 7, 7, 6, 7, 7, 7, 8, 10, 14, 23,
29, 32, 60, 72, 76, 82, 77, 72, 67, 66, 60, 61, 65, 68, 68, 65, 62, 57, 55, 55,
55, 55, 56, 55, 54, 53, 52, 50, 50, 50, 50, 49, 47, 46, 44, 43, 42, 41, 40, 39,
37, 37, 35, 34, 33, 32, 31, 31, 30, 29, 29, 27, 27, 25, 24, 22, 20, 19, 18, 16,
16, 13, 11, 9, 9, 6, 4, 2, 0, -1, -3, -4, -6, -7, -8, -10, -11, -12, -13, -13,
-13, -14, -14, -15, -16, -16, -17, -18, -18, -19, -20, -20, -21, -22, -23, -24,
-24, -25, -26, -27, -27, -28, -28, -29, -29, -30, -30, -30, -30, -30, -30, -30,
-30, -30, -31, -31, -31, -31, -30, -30, -29, -29, -29, -29, -29, -29, -29, -29,
-28, -28, -28, -28, -28, -27, -28, -27, -27, -27, -27, -27, -27, -27, -27, -27,
-28, -28, -28, -28, -29, -30, -30, -31, -31, -31, -31, -33, -35, -36, -38, -39,
-40, -42, -44, -46, -48, -52, -54, -57, -60, -62, -66, -70, -74, -78, -82, -85,
-90, -93, -97, -100, -102, -104, -105, -106, -107, -107, -106, -105, -101, -94,
-83, -68, -48, -30, -18, -13, -13, -16, -17, -16, -11, -4, 3, 9, 13, 13, 13, 12,
14, 16, 20, 24, 27, 31, 33, 35, 37, 39, 40, 42, 43, 43, 44, 44, 44, 44, 44, 42,
41, 41, 40, 40, 40, 39, 39, 38, 38, 37, 37, 37, 36, 36, 36, 36, 36, 35, 35, 34,
34, 33, 33, 32, 32, 31, 30, 30, 29, 29, 28, 27, 27, 27, 26, 26, 26, 26, 25, 24,
24, 23, 22, 23, 22, 22, 22, 21, 21, 19, 19, 19, 19, 19, 20, 20, 20, 19, 19, 19,
19, 20, 19, 20, 20, 19, 19, 19, 18, 18, 19, 19, 19, 19, 19, 19, 20, 21, 19, 23,
33, 40, 43, 63, 84, 88, 93, 90, 85, 79, 78, 74, 72, 75, 79, 80, 76, 72, 68, 66,
66, 67, 66, 66, 67, 66, 65, 63, 62, 61, 60, 60, 59, 58, 56, 56, 53, 52, 50, 48,
47, 46, 44, 42, 40, 38, 37, 35, 34, 33, 32, 31, 30, 29, 28, 28, 26, 25, 24, 22,
21, 19, 18, 17, 15, 14, 11, 10, 8, 7, 5, 4, 3, 2, 1, -1, -1, -2, -3, -4, -5, -6,
-6, -7, -8, -8, -9, -10, -11, -12, -14, -15, -16, -17, -18, -19, -20, -21, -22,
-23, -24, -25, -26, -26, -27, -28, -29, -29, -30, -30, -31, -32, -33, -34, -35,
-37, -38, -40, -42, -43, -46, -49, -52, -55, -59, -63, -67, -71, -75, -79, -83,
-87, -91, -93, -96, -98, -101, -103, -103, -102, -99, -93, -83, -68, -50, -36,
-28, -25, -26, -30, -30, -27, -21, -13, -5, 1, 4, 4, 2, 2, 4, 8, 13, 18, 22, 25,
27, 28, 29, 30, 32, 34, 35, 36, 37, 38, 38, 38, 38, 38, 38, 38, 38, 37, 37, 36,
36, 37, 37, 37, 37, 37, 37, 36, 36, 36, 36, 36, 36, 36, 36, 36, 35, 35, 35, 35,
34, 33, 32, 31, 30, 30, 29, 28, 28, 28, 28, 28, 28, 27, 26, 25, 25, 24, 24, 25,
25, 25, 24, 24, 23, 23, 23, 23, 22, 22, 22, 22, 22, 23, 22, 23, 23, 22, 21, 21,
21, 21, 20, 21, 21, 21, 21, 22, 22, 25, 31, 40, 41, 51, 79, 87, 93, 95, 89, 82,
78, 76, 71, 75, 79, 82, 82, 78, 73, 68, 66, 67, 68, 68, 69, 68, 67, 66, 65, 63,
64, 64, 63, 62, 61, 59, 57, 57, 56, 55, 53, 51, 49, 47, 45, 43, 41, 41, 40, 38,
37, 35, 34, 33, 32, 31, 30, 29, 28, 26, 25, 24, 22, 21, 19, 17, 16, 14, 12, 10,
10, 8, 7, 6, 5, 3, 2, 1, 0, -2, -3, -4, -5, -5, -5, -6, -7, -8, -9, -10, -11,
-12, -12, -13, -14, -15, -15, -16, -17, -18, -18, -19, -20, -20, -21, -21, -22,
-23, -23, -23, -24, -24, -24, -24, -25, -25, -25, -25, -26, -26, -26, -26, -26,
-26, -26, -27, -26, -26, -26, -26, -26, -26, -25, -25, -25, -26, -25, -25, -26,
-26, -25, -25, -26, -25, -25, -25, -26, -26, -27, -27, -28, -28, -29, -31, -32,
-33, -34, -36, -38, -40, -42, -45, -48, -52, -54, -57, -61, -65, -70, -74, -79,
-84, -90, -94, -100, -105, -109, -112, -113, -114, -114, -116, -117, -116, -113,
-107, -97, -84, -67, -50, -35, -26, -21, -21, -21, -20, -17, -12, -6, 0, 5, 8,
9, 9, 9, 11, 14, 18, 22, 26, 29, 31, 32, 33, 35, 36, 38, 39, 40, 40, 40, 40, 39,
38, 37, 36, 36, 35, 34, 34, 33, 32, 31, 31, 30, 30, 30, 30, 30, 30, 30, 29, 29,
29, 28, 28, 28, 27, 27, 26, 25, 24, 23, 22, 21, 20, 20, 19, 18, 17, 17, 16, 15,
14, 14, 14, 13, 12, 12, 11, 10, 10, 9, 9, 9, 9, 9, 8, 8, 8, 8, 8, 8, 8, 9, 9, 9,
9, 9, 9, 8, 9, 8, 8, 7, 7, 6, 7, 6, 7, 8, 10, 15, 25, 28, 35, 63, 72, 77, 81,
76, 71, 67, 66, 59, 62, 65, 68, 68, 65, 61, 57, 55, 55, 55, 55, 56, 55, 54, 53,
51, 50, 50, 50, 50, 49, 47, 46, 44, 42, 42, 41, 40, 38, 37, 36, 34, 34, 33, 32,
31, 30, 30, 29, 28, 27, 26, 25, 24, 22, 20, 19, 18, 16, 15, 13, 11, 9, 9, 6, 4,
2, 0, -1, -3, -4, -6, -8, -9, -10, -11, -12, -13, -13, -14, -14, -14, -15, -16,
-16, -17, -18, -18, -19, -20, -20, -21, -22, -23, -24, -25, -26, -26, -27, -27,
-28, -28, -29, -29, -30, -30, -30, -30, -30, -30, -30, -30, -30, -31, -31, -31,
-30, -30, -30, -29, -29, -29, -29, -29, -29, -29, -29, -28, -28, -28, -28, -27,
-27, -28, -27, -27, -27, -27, -27, -27, -27, -27, -27, -28, -28, -28, -28, -29,
-30, -30, -31, -31, -31, -32, -33, -35, -36, -38, -39, -40, -42, -44, -46, -49,
-52, -55, -58, -60, -63, -67, -71, -74, -79, -82, -86, -90, -93, -97, -100,
-102, -104, -105, -106, -107, -107, -106, -104, -100, -93, -81, -65, -46, -28,
-17, -13, -13, -16, -17, -15, -11, -3, 4, 10, 13, 13, 13, 13, 14, 17, 21, 24,
28, 31, 33, 36, 38, 39, 40, 42, 43, 43, 44, 44, 44, 44, 43, 42, 41, 41, 40, 40,
40, 39, 38, 38, 38, 37, 37, 37, 36, 36, 36, 36, 36, 35, 35, 34, 34, 33, 33, 32,
32, 31, 30, 30, 29, 28, 28, 27, 27, 27, 26, 26, 26, 25, 25, 24, 23, 23, 22, 22,
22, 22, 22, 21, 20, 19, 19, 19, 19, 19, 20, 20, 19, 19, 19, 19, 20, 20, 20, 20,
20, 19, 19, 19, 18, 18, 19, 19, 19, 19, 19, 19, 20, 21, 19, 24, 34, 41, 45, 67,
85, 89, 93, 89, 84, 79, 78, 74, 72, 76, 79, 79, 76, 72, 68, 66, 66, 67, 66, 66,
67, 66, 65, 63, 62, 61, 60, 60, 59, 57, 56, 55, 52, 52, 50, 48, 47, 45, 44, 41,
40, 38, 37, 35, 34, 33, 31, 31, 30, 29, 28, 28, 26, 25, 24, 22, 21, 19, 18, 17,
15, 13, 11, 10, 8, 7, 5, 4, 2, 2, 0, -1, -2, -2, -3, -4, -5, -6, -6, -7, -8, -8,
-9, -10, -11, -12, -13, -14, -15, -16, -17, -17, -18, -19, -20, -20, -21, -22,
-23, -23, -24, -24, -24, -25, -25, -26, -26, -26, -26, -27, -27, -28, -28, -28,
-28, -29, -29, -29, -29, -29, -29, -29, -29, -29, -29, -29, -29, -29, -28, -29,
-29, -29, -28, -28, -28, -27, -27, -27, -27, -27, -28, -28, -27, -28, -28, -29,
-28, -29, -30, -30, -32, -32, -33, -34, -35, -37, -38, -40, -41, -43, -46, -48,
-51, -54, -56, -60, -63, -67, -70, -74, -80, -84, -90, -95, -100, -106, -110,
-113, -116, -117, -119, -120, -122, -123, -123, -121, -115, -106, -93, -75, -56,
-40, -31, -27, -28, -30, -30, -27, -22, -15, -9, -3, 0, 1, 0, 1, 3, 6, 10, 14,
18, 21, 23, 26, 27, 28, 30, 32, 34, 35, 36, 36, 37, 36, 36, 36, 35, 34, 34, 34,
33, 33, 32, 31, 31, 30, 30, 30, 30, 30, 30, 30, 30, 29, 29, 29, 28, 28, 28, 27,
27, 26, 25, 24, 23, 22, 21, 21, 20, 19, 18, 18, 17, 16, 15, 15, 14, 14, 14, 13,
12, 11, 10, 10, 9, 9, 9, 9, 9, 8, 8, 8, 8, 8, 8, 8, 9, 9, 9, 9, 9, 9, 8, 9, 8,
8, 8, 7, 6, 7, 7, 7, 8, 10, 14, 22, 29, 31, 58, 72, 75, 82, 77, 73, 67, 66, 60,
61, 65, 68, 68, 65, 62, 57, 55, 55, 55, 55, 56, 55, 54, 53, 52, 50, 50, 50, 50,
49, 47, 46, 45, 43, 42, 41, 40, 39, 37, 37, 35, 34, 33, 32, 32, 31, 30, 29, 29,
27, 27, 26, 24, 23, 21, 19, 18, 16, 16, 13, 11, 10, 9, 7, 4, 3, 0, -1, -3, -4,
-6, -7, -8, -10, -11, -12, -13, -13, -13, -14, -14, -15, -16, -16, -17, -18,
-18, -19, -20, -20, -21, -22, -23, -24, -24, -25, -26, -27, -27, -28, -28, -29,
-29, -30, -30, -30, -30, -30, -30, -30, -30, -30, -31, -31, -31, -31, -30, -30,
-29, -29, -29, -29, -29, -29, -29, -29, -28, -28, -28, -28, -28, -27, -28, -27,
-27, -27, -27, -27, -27, -27, -27, -27, -28, -28, -28, -28, -29, -30, -30, -31,
-31, -31, -31, -32, -35, -36, -38, -39, -40, -42, -43, -46, -48, -51, -54, -57,
-60, -62, -66, -70, -73, -78, -82, -85, -89, -93, -97, -100, -102, -104, -105,
-106, -107, -107, -107, -105, -101, -95, -84, -69, -50, -31, -19, -13, -13, -15,
-17, -16, -12, -5, 3, 9, 13, 13, 13, 12, 14, 16, 20, 23, 27, 30, 33, 35, 37, 39,
40, 41, 43, 43, 44, 44, 44, 44, 44, 43, 42, 41, 40, 40, 40, 39, 39, 38, 38, 37,
37, 37, 36, 36, 36, 36, 36, 35, 35, 34, 34, 33, 33, 32, 32, 31, 30, 30, 29, 29,
28, 27, 27, 27, 26, 26, 26, 26, 25, 24, 24, 23, 22, 23, 22, 22, 22, 21, 21, 20,
19, 19, 19, 19, 20, 20, 20, 19, 19, 19, 19, 20, 19, 20, 20, 19, 19, 19, 18, 18,
19, 19, 19, 19, 19, 19, 19, 21, 19, 23, 32, 40, 43, 61, 84, 88, 93, 91, 85, 80,
78, 75, 72, 75, 79, 80, 76, 73, 68, 66, 66, 67, 66, 66, 67, 66, 65, 63, 62, 61,
60, 60, 59, 58, 56, 56, 53, 52, 50, 48, 47, 46, 44, 42, 40, 38, 37, 35, 34, 33,
32, 31, 30, 29, 28, 28, 27, 26, 24, 23, 21, 19, 18, 17, 16, 14, 12, 10, 8, 7, 5,
4, 3, 2, 1, -1, -1, -2, -3, -4, -5, -5, -6, -7, -8, -8, -9, -10, -11, -12, -13,
-14, -15, -15, -16, -17, -18, -18, -19, -20, -21, -22, -23, -23, -23, -24, -24,
-25, -25, -25, -26, -26, -26, -27, -27, -28, -28, -28, -28, -28, -29, -29, -29,
-29, -29, -29, -29, -29, -29, -29, -29, -29, -29, -28, -29, -29, -28, -28, -28,
-27, -27, -28, -27, -27, -28, -28, -27, -28, -28, -29, -28, -29, -30, -30, -31,
-32, -33, -33, -35, -37, -37, -39, -41, -43, -45, -48, -50, -53, -56, -59, -62,
-66, -70, -74, -78, -83, -89, -94, -99, -105, -110, -113, -116, -117, -119,
-121, -123, -124, -124, -122, -117, -108, -94, -76, -55, -39, -30, -27, -30,
-34, -34, -31, -25, -18, -11, -5, -4, -4, -6, -6, -4, 0, 4, 9, 12, 15, 17, 18,
18, 20, 22, 24, 26, 27, 27, 27, 27, 26, 25, 25, 25, 26, 26, 25, 25, 25, 24, 24,
24, 24, 25, 25, 25, 25, 25, 26, 25, 25, 26, 26, 26, 26, 26, 25, 24, 23, 22, 22,
22, 21, 21, 20, 20, 19, 18, 18, 18, 18, 17, 17, 17, 16, 16, 16, 16, 16, 16, 15,
16, 16, 15, 15, 15, 15, 15, 14, 15, 15, 14, 14, 14, 14, 14, 13, 13, 13, 13, 12,
12, 11, 12, 12, 13, 12, 12, 13, 14, 15, 17, 24, 34, 37, 45, 70, 78, 82, 84, 78,
73, 71, 68, 63, 66, 68, 70, 69, 65, 62, 59, 58, 59, 59, 59, 59, 59, 57, 57, 57,
55, 54, 53, 53, 52, 49, 48, 46, 44, 44, 42, 41, 40, 37, 36, 35, 33, 32, 31, 30,
30, 29, 28, 28, 27, 26, 26, 25, 24, 23, 22, 21, 19, 17, 16, 14, 13, 12, 10, 8,
7, 5, 4, 2, 1, 0, -1, -2, -3, -4, -4, -5, -5, -6, -7, -7, -8, -9, -9, -10, -11,
-11, -12, -13, -14, -15, -16, -16, -17, -18, -19, -19, -20, -21, -21, -21, -22,
-24, -24, -25, -25, -25, -25, -25, -26, -26, -27, -27, -28, -28, -28, -28, -29,
-29, -30, -30, -30, -29, -29, -29, -30, -30, -31, -31, -30, -30, -29, -30, -31,
-32, -32, -32, -32, -33, -32, -33, -34, -34, -34, -34, -35, -36, -38, -39, -41,
-43, -44, -46, -47, -49, -53, -56, -60, -64, -69, -74, -79, -84, -89, -94, -100,
-106, -111, -116, -119, -120, -121, -123, -125, -127, -128, -128, -124, -115,
-102, -85, -64, -45, -33, -28, -29, -32, -35, -33, -28, -22, -14, -8, -4, -4,
-4, -4, -3, 0, 4, 8, 12, 14, 16, 18, 18, 20, 22, 25, 28, 30, 31, 31, 31, 30, 30,
31, 31, 32, 31, 31, 31, 30, 30, 30, 31, 31, 32, 32, 32, 32, 32, 32, 33, 33, 32,
33, 33, 32, 32, 31, 31, 30, 30, 29, 28, 28, 27, 27, 26, 25, 25, 25, 24, 24, 23,
23, 23, 22, 21, 19, 18, 17, 16, 15, 14, 12, 10, 9, 8, 5, 3, 1, -1, -2, -3, -4,
-7, -8, -9, -10, -12, -12, -13, -13, -14, -14, -14, -16, -16, -16, -17, -18,
-18, -20, -20, -20, -22, -22, -23, -24, -25, -26, -26, -27, -28, -28, -28, -29,
-29, -30, -30, -30, -30, -30, -30, -30, -30, -30, -31, -31, -31, -30, -30, -30,
-29, -29, -29, -29, -29, -29, -29, -29, -28, -28, -28, -28, -27, -27, -28, -27,
-27, -27, -27, -27, -27, -27, -27, -27, -28, -28, -28, -28, -29, -30, -31, -31,
-31, -31, -32, -34, -35, -37, -39, -39, -41, -42, -45, -47, -49, -53, -55, -58,
-61, -64, -68, -72, -75, -80, -83, -87, -91, -95, -98, -101, -103, -105, -106,
-107, -107, -107, -106, -103, -99, -90, -77, -60, -40, -24, -15, -12, -14, -17,
-17, -14, -9, -1, 6, 11, 13, 13, 12, 13, 15, 18, 22, 25, 29, 31, 34, 36, 38, 40,
41, 42, 43, 43, 44, 44, 44, 44, 43, 42, 41, 41, 40, 40, 39, 39, 38, 38, 38, 37,
37, 37, 36, 36, 36, 36, 35, 35, 34, 34, 34, 33, 33, 32, 31, 31, 30, 29, 29, 28,
27, 27, 27, 26, 26, 26, 26, 25, 24, 24, 23, 22, 23, 22, 22, 22, 21, 21, 20, 19,
19, 19, 19, 19, 20, 20, 19, 19, 19, 19, 20, 19, 20, 20, 20, 19, 19, 19, 18, 18,
19, 19, 19, 19, 19, 19, 20, 20, 20, 27, 37, 41, 49, 74, 87, 90, 93, 88, 83, 78,
77, 73, 73, 77, 80, 78, 75, 71, 67, 66, 67, 67, 66, 67, 66, 65, 64, 63, 61, 61,
60, 60, 59, 57, 56, 55, 52, 51, 49, 48, 46, 45, 43, 41, 39, 37, 36, 34, 34, 32,
31, 31, 30, 29, 28, 27, 26, 25, 24, 22, 20, 19, 18, 16, 15, 13, 11, 9, 7, 6, 5,
4, 2, 1, 0, -1, -2, -2, -4, -4, -5, -6, -6, -7, -8, -8, -9, -11, -12, -12, -13,
-14, -15, -16, -17, -17, -18, -19, -20, -20, -21, -22, -23, -23, -24, -24, -25,
-25, -25, -26, -26, -26, -27, -27, -28, -28, -28, -28, -28, -29, -29, -29, -29,
-29, -29, -29, -29, -29, -29, -29, -29, -29, -28, -29, -29, -29, -28, -28, -28,
-27, -28, -27, -27, -28, -28, -28, -27, -28, -28, -28, -28, -29, -30, -31, -32,
-33, -33, -34, -36, -37, -38, -40, -42, -44, -46, -49, -51, -55, -57, -61, -64,
-68, -71, -76, -81, -86, -91, -96, -101, -107, -111, -114, -117, -118, -120,
-122, -124, -124, -123, -120, -113, -102, -86, -65, -46, -34, -28, -28, -32,
-34, -33, -29, -22, -15, -8, -4, -4, -5, -6, -5, -2, 2, 7, 11, 14, 16, 17, 18,
19, 21, 23, 25, 26, 27, 27, 27, 27, 26, 25, 25, 26, 26, 26, 25, 25, 24, 24, 24,
24, 25, 25, 25, 25, 25, 25, 26, 25, 26, 26, 26, 26, 26, 25, 24, 23, 23, 22, 22,
21, 21, 21, 20, 19, 19, 18, 18, 18, 18, 17, 17, 17, 16, 16, 16, 16, 16, 15, 15,
16, 15, 15, 15, 15, 15, 14, 15, 15, 15, 14, 14, 14, 14, 13, 13, 13, 13, 13, 12,
12, 11, 12, 13, 12, 12, 13, 13, 15, 15, 20, 29, 37, 38, 58, 76, 79, 84, 81, 76,
71, 70, 65, 64, 67, 69, 70, 67, 63, 60, 58, 59, 59, 59, 59, 59, 58, 57, 57, 56,
54, 53, 53, 52, 51, 49, 47, 45, 44, 43, 41, 40, 39, 37, 36, 34, 32, 31, 31, 31,
30, 28, 28, 27, 26, 26, 25, 24, 23, 22, 21, 20, 18, 16, 15, 14, 12, 11, 9, 8, 6,
5, 3, 1, 0, -1, -2, -2, -3, -4, -4, -5, -6, -6, -7, -8, -9, -9, -10, -10, -11,
-12, -13, -14, -14, -15, -16, -17, -17, -18, -19, -20, -20, -21, -21, -22, -23,
-24, -25, -25, -25, -25, -25, -26, -26, -27, -27, -27, -28, -28, -28, -29, -29,
-29, -30, -30, -30, -29, -29, -30, -30, -30, -31, -30, -30, -29, -30, -31, -31,
-32, -32, -32, -32, -32, -32, -33, -34, -34, -34, -34, -35, -37, -38, -40, -42,
-44, -45, -46, -48, -51, -54, -58, -62, -67, -72, -76, -81, -86, -91, -97, -102,
-108, -114, -117, -120, -121, -122, -124, -126, -128, -128, -126, -120, -109,
-95, -75, -54, -38, -30, -28, -31, -34, -35, -31, -25, -18, -11, -6, -4, -4, -4,
-4, -2, 2, 6, 10, 13, 15, 17, 18, 19, 21, 22, 24, 26, 27, 27, 27, 26, 26, 25,
25, 24, 23, 23, 22, 22, 21, 21, 21, 21, 21, 21, 21, 20, 21, 21, 21, 21, 21, 21,
20, 20, 19, 19, 19, 18, 17, 16, 16, 15, 14, 14, 13, 12, 12, 11, 10, 10, 10, 9,
10, 9, 9, 9, 8, 8, 7, 7, 7, 7, 7, 7, 7, 6, 5, 6, 5, 6, 5, 5, 5, 5, 5, 5, 5, 5,
5, 5, 4, 5, 7, 6, 10, 18, 26, 27, 46, 64, 66, 72, 69, 65, 60, 59, 54, 53, 56,
58, 60, 57, 55, 51, 49, 50, 49, 50, 50, 50, 49, 48, 47, 46, 45, 45, 44, 44, 42,
40, 38, 37, 36, 35, 34, 32, 30, 29, 27, 26, 24, 23, 23, 22, 21, 19, 18, 16, 14,
13, 11, 10, 8, 7, 5, 3, 2, 0, -2, -3, -5, -7, -8, -10, -12, -13, -15, -16, -17,
-18, -20, -21, -23, -24, -25, -27, -29, -30, -32, -34, -37, -39, -41, -44, -46,
-50, -53, -57, -61, -64, -68, -72, -76, -80, -83, -86, -89, -91, -93, -94, -95,
-96, -95, -91, -84, -74, -58, -39, -24, -16, -12, -14, -17, -17, -14, -9, -1, 6,
11, 13, 13, 12, 13, 15, 18, 22, 25, 29, 31, 34, 36, 38, 40, 41, 42, 43, 43, 44,
44, 44, 44, 43, 42, 41, 41, 40, 40, 39, 39, 38, 38, 38, 37, 37, 37, 36, 36, 36,
36, 35, 35, 34, 34, 34, 33, 33, 32, 31, 31, 30, 29, 29, 28, 27, 27, 27, 26, 26,
26, 26, 25, 24, 24, 23, 22, 23, 22, 22, 22, 21, 21, 20, 19, 19, 19, 19, 19, 20,
20, 19, 19, 19, 19, 20, 19, 20, 20, 20, 19, 19, 19, 18, 18, 19, 19, 19, 19, 19,
19, 20, 20, 20, 27, 37, 41, 49, 75, 87, 90, 93, 88, 82, 78, 77, 72, 73, 77, 80,
78, 74, 71, 67, 66, 67, 67, 66, 67, 66, 65, 64, 63, 61, 61, 60, 60, 59, 57, 56,
54, 52, 51, 49, 48, 46, 45, 43, 41, 39, 37, 36, 34, 34, 32, 31, 31, 30, 29, 28,
27, 26, 25, 24, 22, 20, 19, 18, 16, 15, 13, 11, 9, 7, 6, 5, 3, 2, 1, 0, -1, -2,
-2, -4, -4, -5, -6, -6, -7, -8, -8, -9, -11, -12, -12, -13, -14, -15, -16, -17,
-17, -18, -19, -20, -20, -21, -22, -23, -23, -24, -24, -25, -25, -25, -26, -26,
-26, -27, -27, -28, -28, -28, -28, -28, -29, -29, -29, -29, -29, -29, -29, -29,
-29, -29, -29, -29, -29, -28, -29, -29, -29, -28, -28, -28, -27, -28, -27, -27,
-28, -28, -28, -27, -28, -28, -28, -28, -29, -30, -31, -32, -33, -33, -34, -36,
-37, -38, -40, -42, -44, -46, -49, -51, -55, -57, -61, -64, -68, -72, -76, -81,
-86, -91, -96, -102, -107, -111, -114, -117, -118, -120, -122, -124, -124, -123,
-120, -113, -102, -85, -65, -46, -33, -28, -28, -32, -34, -33, -29, -22, -14,
-8, -4, -4, -5, -6, -5, -2, 2, 7, 11, 14, 16, 17, 18, 19, 21, 23, 25, 26, 27,
27, 27, 27, 26, 25, 25, 26, 26, 26, 25, 25, 24, 24, 24, 24, 25, 25, 25, 25, 25,
25, 26, 25, 26, 26, 26, 26, 26, 25, 24, 23, 23, 22, 22, 21, 21, 21, 20, 19, 19,
18, 18, 18, 18, 17, 17, 17, 16, 16, 16, 16, 16, 15, 15, 16, 15, 15, 15, 15, 15,
14, 15, 15, 15, 14, 14, 14, 14, 13, 13, 13, 13, 13, 12, 12, 11, 12, 13, 12, 12,
13, 13, 15, 15, 20, 30, 37, 38, 58, 76, 79, 85, 81, 76, 71, 70, 65, 64, 67, 69,
70, 67, 63, 60, 58, 59, 59, 59, 59, 59, 58, 57, 57, 56, 54, 53, 53, 52, 51, 48,
47, 45, 44, 43, 41, 40, 38, 37, 36, 34, 32, 31, 31, 31, 30, 28, 28, 27, 26, 26,
25, 24, 23, 22, 21, 20, 18, 16, 15, 14, 12, 11, 9, 8, 6, 5, 3, 1, 0, -1, -2, -2,
-3, -4, -4, -5, -6, -6, -7, -8, -9, -9, -10, -10, -11, -12, -13, -14, -15, -15,
-16, -17, -17, -18, -19, -20, -20, -21, -21, -22, -23, -24, -25, -25, -25, -25,
-25, -26, -26, -27, -27, -27, -28, -28, -28, -29, -29, -29, -30, -30, -30, -29,
-29, -30, -30, -30, -31, -30, -30, -29, -30, -31, -31, -32, -32, -32, -32, -32,
-32, -34, -34, -34, -34, -34, -35, -37, -38, -40, -42, -44, -45, -46, -48, -51,
-54, -58, -62, -67, -72, -76, -81, -86, -91, -97, -103, -109, -114, -118, -120,
-121, -122, -124, -126, -128, -128, -126, -120, -109, -94, -74, -53, -38, -30,
-28, -31, -34, -35, -31, -25, -18, -11, -6, -4, -4, -4, -4, -2, 2, 6, 10, 13,
15, 17, 18, 19, 21, 22, 24, 26, 27, 27, 27, 26, 26, 25, 25, 24, 23, 23, 22, 22,
21, 21, 21, 21, 21, 21, 21, 20, 21, 21, 21, 21, 21, 21, 20, 20, 19, 19, 19, 18,
17, 16, 16, 15, 14, 14, 13, 12, 12, 11, 10, 10, 10, 9, 10, 9, 9, 9, 8, 7, 7, 7,
7, 7, 7, 7, 7, 6, 5, 6, 5, 6, 5, 5, 5, 5, 5, 5, 5, 5, 4, 5, 4, 5, 7, 6, 10, 18,
26, 27, 47, 64, 66, 72, 69, 65, 60, 59, 54, 53, 56, 58, 60, 57, 54, 51, 49, 50,
49, 50, 50, 50, 49, 48, 47, 46, 45, 45, 44, 44, 42, 40, 38, 37, 36, 35, 34, 32,
30, 29, 27, 26, 24, 23, 23, 22, 21, 20, 19, 18, 17, 16, 15, 14, 12, 12, 10, 9,
8, 6, 5, 4, 2, 0, -1, -3, -4, -5, -7, -8, -9, -10, -11, -12, -13, -14, -14, -15,
-16, -16, -17, -17, -18, -18, -19, -20, -20, -21, -22, -23, -24, -25, -25, -26,
-26, -27, -28, -29, -29, -30, -30, -31, -31, -31, -31, -31, -32, -32, -32, -32,
-32, -32, -32, -32, -32, -32, -32, -32, -32, -32, -32, -33, -33, -33, -33, -33,
-33, -33, -33, -33, -33, -33, -33, -33, -33, -33, -33, -33, -33, -34, -34, -35,
-35, -36, -36, -37, -38, -39, -41, -42, -44, -46, -48, -51, -53, -56, -59, -63,
-66, -69, -74, -78, -83, -87, -93, -98, -104, -109, -112, -115, -116, -116,
-117, -118, -118, -118, -116, -111, -102, -89, -73, -54, -38, -28, -24, -25,
-27, -29, -27, -22, -15, -9, -4, -1, -1, -2, -2, 0, 3, 7, 11, 14, 17, 19, 20,
20, 21, 23, 24, 26, 26, 27, 27, 27, 26, 25, 25, 25, 25, 25, 24, 24, 24, 23, 23,
23, 23, 24, 24, 24, 24, 24, 24, 25, 25, 25, 25, 25, 25, 25, 25, 24, 23, 23, 22,
22, 21, 21, 21, 20, 19, 19, 18, 18, 18, 18, 17, 17, 17, 16, 16, 16, 16, 16, 15,
15, 16, 15, 15, 15, 15, 15, 14, 15, 15, 15, 14, 14, 14, 14, 13, 13, 13, 13, 12,
12, 12, 11, 12, 13, 12, 12, 13, 13, 15, 15, 21, 30, 37, 39, 60, 77, 79, 85, 81,
76, 71, 70, 65, 64, 67, 69, 70, 67, 63, 60, 58, 59, 59, 59, 59, 59, 58, 57, 57,
55, 54, 53, 53, 52, 50, 48, 47, 45, 44, 43, 41, 40, 38, 37, 36, 34, 32, 31, 30,
31, 29, 28, 28, 27, 26, 26, 25, 24, 23, 22, 21, 20, 18, 16, 15, 14, 12, 11, 9,
8, 6, 5, 3, 1, 0, -1, -2, -2, -3, -4, -5, -5, -6, -6, -7, -8, -9, -9, -10, -10,
-11, -12, -13, -14, -15, -15, -16, -17, -17, -18, -19, -20, -20, -21, -21, -22,
-23, -24, -25, -25, -25, -25, -25, -26, -26, -27, -27, -27, -28, -28, -28, -29,
-29, -29, -30, -30, -29, -29, -29, -30, -30, -30, -31, -30, -30, -29, -30, -31,
-31, -32, -32, -32, -32, -32, -32, -34, -34, -34, -34, -34, -35, -37, -39, -40,
-42, -44, -45, -46, -48, -51, -54, -59, -63, -67, -72, -76, -82, -87, -92, -97,
-103, -109, -114, -118, -120, -121, -122, -124, -126, -128, -128, -126, -120,
-108, -93, -73, -52, -37, -30, -28, -31, -34, -35, -31, -24, -17, -10, -6, -4,
-4, -4, -4, -2, 2, 6, 10, 13, 15, 17, 18, 19, 21, 22, 24, 26, 27, 27, 27, 26,
26, 25, 25, 24, 23, 23, 22, 22, 21, 21, 21, 21, 21, 21, 21, 20, 21, 21, 21, 21,
21, 21, 20, 20, 19, 19, 19, 18, 17, 16, 16, 15, 14, 14, 13, 12, 12, 11, 10, 10,
10, 9, 10, 9, 9, 9, 8, 7, 7, 7, 7, 7, 7, 7, 7, 6, 5, 6, 5, 6, 5, 6, 5, 5, 5, 5,
5, 5, 4, 5, 4, 5, 7, 7, 11, 18, 26, 28, 49, 65, 67, 73, 69, 65, 60, 59, 54, 53,
56, 58, 60, 56, 54, 51, 49, 50, 49, 50, 50, 50, 49, 48, 47, 46, 45, 45, 44, 43,
42, 40, 38, 37, 36, 35, 34, 31, 30, 29, 27, 25, 24, 23, 23, 21, 21, 20, 19, 18,
17, 16, 15, 14, 12, 12, 10, 9, 8, 6, 5, 4, 2, 0, -1, -3, -5, -5, -7, -8, -9,
-10, -11, -12, -13, -14, -14, -15, -16, -17, -17, -17, -18, -18, -19, -20, -20,
-21, -22, -23, -24, -25, -25, -26, -26, -27, -28, -29, -29, -30, -30, -31, -31,
-31, -31, -31, -32, -32, -32, -32, -32, -32, -32, -32, -32, -32, -32, -32, -32,
-32, -32, -33, -33, -33, -33, -33, -33, -33, -33, -33, -33, -34, -33, -33, -33,
-33, -33, -33, -33, -34, -35, -34, -35, -36, -36, -37, -38, -39, -41, -42, -44,
-46, -48, -51, -53, -56, -59, -63, -66, -69, -74, -79, -83, -87, -93, -98, -104,
-109, -112, -115, -116, -117, -117, -118, -118, -118, -115, -110, -101, -88,
-71, -52, -37, -27, -24, -24, -27, -28, -25, -20, -13, -7, -2, 0, 0, 0, 0, 2, 6,
10, 14, 17, 19, 21, 21, 22, 23, 24, 25, 26, 27, 27, 27, 26, 25, 25, 24, 24, 23,
22, 22, 21, 20, 20, 20, 19, 20, 20, 20, 19, 20, 19, 19, 19, 19, 19, 19, 19, 18,
17, 16, 15, 14, 14, 13, 12, 11, 11, 10, 9, 8, 8, 7, 7, 6, 6, 6, 6, 5, 5, 4, 4,
4, 3, 3, 3, 3, 2, 2, 1, 1, 1, 1, 1, 1, 0, 0, 0, 0, 0, 0, 0, -1, 0, 0, -1, 0, -1,
1, 1, 3, 9, 17, 21, 24, 46, 59, 61, 65, 61, 55, 51, 49, 44, 45, 48, 52, 52, 50,
47, 43, 42, 42, 43, 43, 44, 44, 43, 41, 40, 39, 39, 38, 39, 38, 35, 34, 33, 31,
30, 29, 28, 27, 26, 25, 23, 22, 20, 19, 18, 18, 18, 18, 17, 17, 16, 16, 15, 15,
14, 13, 12, 10, 10, 9, 8, 7, 6, 5, 4, 3, 2, 0, -1, -2, -3, -4, -5, -5, -6, -7,
-8, -8, -9, -9, -10, -10, -10, -11, -12, -13, -13, -14, -15, -15, -16, -16, -17,
-17, -18, -19, -19, -20, -21, -20, -21, -21, -22, -22, -22, -22, -22, -22, -22,
-23, -23, -24, -24, -24, -24, -24, -23, -23, -23, -23, -23, -23, -23, -23, -22,
-22, -21, -21, -21, -20, -19, -19, -20, -20, -21, -21, -22, -22, -21, -21, -22,
-23, -23, -25, -28, -31, -33, -34, -36, -38, -40, -42, -46, -49, -52, -56, -60,
-64, -68, -72, -75, -80, -85, -91, -96, -99, -102, -103, -105, -106, -107, -109,
-110, -108, -103, -94, -79, -61, -39, -24, -16, -14, -18, -22, -23, -21, -15,
-8, -1, 4, 7, 6, 5, 4, 6, 9, 14, 18, 22, 24, 26, 26, 27, 28, 29, 31, 33, 34, 34,
34, 33, 32, 31, 30, 30, 30, 30, 30, 29, 29, 28, 27, 27, 27, 28, 30, 31, 31, 32,
32, 31, 30, 29, 29, 29, 29, 28, 26, 25, 23, 22, 22, 21, 20, 19, 19, 19, 18, 18,
18, 17, 17, 17, 17, 16, 15, 15, 15, 14, 14, 15, 15, 14, 14, 14, 14, 14, 13, 13,
13, 13, 12, 12, 12, 12, 12, 12, 11, 12, 11, 12, 12, 11, 11, 11, 11, 10, 11, 11,
11, 11, 11, 12, 14, 14, 18, 27, 35, 36, 53, 73, 77, 82, 80, 75, 71, 70, 66, 63,
66, 68, 70, 67, 64, 60, 58, 59, 59, 59, 59, 59, 59, 57, 57, 56, 54, 53, 53, 52,
51, 49, 47, 45, 44, 43, 41, 40, 39, 37, 36, 34, 32, 31, 31, 31, 30, 28, 28, 27,
26, 26, 25, 24, 24, 22, 21, 20, 18, 16, 15, 14, 12, 11, 9, 8, 6, 5, 3, 2, 0, 0,
-1, -2, -3, -4, -4, -5, -6, -6, -7, -8, -9, -9, -9, -10, -11, -12, -12, -14,
-14, -15, -16, -17, -17, -18, -19, -20, -20, -21, -21, -22, -23, -24, -25, -25,
-25, -25, -25, -26, -26, -27, -27, -27, -28, -28, -28, -29, -29, -29, -30, -30,
-30, -29, -29, -29, -30, -30, -31, -30, -30, -29, -30, -31, -31, -32, -32, -32,
-32, -32, -32, -33, -34, -34, -34, -34, -35, -36, -38, -40, -42, -44, -45, -46,
-48, -51, -54, -58, -62, -66, -71, -76, -81, -86, -91, -96, -102, -108, -113,
-117, -120, -121, -121, -123, -125, -127, -128, -127, -121, -110, -96, -77, -56,
-39, -31, -28, -30, -34, -35, -32, -26, -19, -12, -6, -4, -4, -4, -4, -2, 1, 6,
10, 13, 15, 17, 18, 19, 20, 22, 24, 26, 27, 27, 27, 26, 26, 25, 25, 24, 23, 23,
22, 22, 21, 21, 21, 21, 21, 21, 21, 20, 21, 21, 21, 21, 21, 21, 20, 20, 19, 19,
19, 18, 17, 17, 16, 15, 14, 14, 13, 12, 12, 11, 11, 10, 10, 9, 10, 9, 9, 9, 8,
8, 7, 7, 7, 7, 7, 7, 7, 6, 5, 6, 5, 6, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 4, 4, 7, 6,
10, 17, 25, 26, 43, 64, 66, 72, 70, 66, 61, 59, 55, 53, 56, 58, 60, 57, 55, 52,
49, 50, 49, 49, 50, 50, 49, 48, 47, 46, 45, 45, 45, 44, 42, 41, 39, 37, 36, 35,
34, 32, 30, 29, 27, 26, 25, 23, 23, 22, 21, 20, 19, 18, 17, 16, 15, 14, 12, 12,
11, 9, 8, 6, 5, 4, 2, 1, -1, -3, -4, -5, -7, -8, -9, -10, -11, -12, -12, -13,
-14, -15, -16, -16, -17, -17, -17, -18, -18, -20, -20, -21, -22, -23, -24, -25,
-25, -26, -26, -27, -28, -29, -29, -30, -30, -31, -31, -31, -31, -31, -32, -32,
-32, -32, -32, -32, -32, -32, -32, -32, -32, -32, -32, -32, -32, -33, -33, -33,
-33, -33, -33, -33, -33, -33, -33, -33, -33, -33, -33, -33, -33, -33, -33, -34,
-34, -35, -34, -35, -36, -37, -38, -39, -41, -42, -44, -45, -48, -50, -52, -56,
-59, -62, -66, -68, -73, -78, -82, -86, -92, -97, -103, -109, -111, -115, -116,
-116, -117, -118, -118, -118, -116, -111, -103, -91, -75, -56, -39, -28, -24,
-24, -26, -28, -26, -21, -15, -8, -3, 0, 0, 0, 0, 1, 2, 3, 2, 1, };

#endif /* Goro2_H_ */
