#pragma once

/*****************************************************
 *
 * 盤面サイズ、座標系の定義
 * 1路分の盤外拡張がなされた21x21の盤面の1次元座標系
 * 左下(0)→…→右下(20)→…→左上(420)→…→右上(440)
 *
 * Definition of board size, coordinate system
 * and conversion array.
 *
 * 1-D coordinate system for 21x21 board with
 * inner real board (19x19) and extended outer boundary.
 * Bottom left (0) => ... => Bottom right (20) => ...
 * => Upper left (420) => ... => Upper right (440)
 *
 *****************************************************/

// AQ-PS
extern int keypoint;
extern int custom_keypoint;
extern double penalty_each_ko;
extern bool test_sgfs;

// 実盤面のサイズ
// Size of real board.
constexpr int BSIZE = 19;

// 拡張盤面のサイズ
// Size of extended board. = 21.
constexpr int EBSIZE = BSIZE + 2;

// 実盤面の交点数
// Number of real-board vertexes. = 361.
constexpr int BVCNT = BSIZE * BSIZE;

// 拡張盤面の交点数
// Number of extended-board vertexes. = 441.
constexpr int EBVCNT = EBSIZE * EBSIZE;

// パスの座標（= 441）
// 通常の盤面座標は [0, 440]の範囲を取る
// Position index of pass move. = 441.
// Normal positions range from 0 to 440.
constexpr int PASS = EBVCNT;

// Null座標. 初期化などに使用する (= 442)
// Position index of 'null' move,
// used for initialization etc. = 442.
constexpr int VNULL = EBVCNT + 1;

// デフォルトのコミ
// Default Komi for the Chinese rule.
constexpr double KOMI = 7.5;

// 隣接する座標への移動量｛N, E, S, W｝
// Shift amount to the next position. {N, E, S, W}
constexpr int VSHIFT[4] = {EBSIZE, 1, -EBSIZE, -1};


/**
 * 実盤面 -> 拡張盤面　の変換配列
 * Conversion array: real board -> extended board
 */
constexpr int rtoe[BVCNT] = {
		22,  23,  24,  25,  26,  27,  28,  29,  30,  31,  32,  33,  34,  35,  36,  37,  38,  39,  40,
		43,  44,  45,  46,  47,  48,  49,  50,  51,  52,  53,  54,  55,  56,  57,  58,  59,  60,  61,
		64,  65,  66,  67,  68,  69,  70,  71,  72,  73,  74,  75,  76,  77,  78,  79,  80,  81,  82,
		85,  86,  87,  88,  89,  90,  91,  92,  93,  94,  95,  96,  97,  98,  99,  100, 101, 102, 103,
		106, 107, 108, 109, 110, 111, 112, 113, 114, 115, 116, 117, 118, 119, 120, 121, 122, 123, 124,
		127, 128, 129, 130, 131, 132, 133, 134, 135, 136, 137, 138, 139, 140, 141, 142, 143, 144, 145,
		148, 149, 150, 151, 152, 153, 154, 155, 156, 157, 158, 159, 160, 161, 162, 163, 164, 165, 166,
		169, 170, 171, 172, 173, 174, 175, 176, 177, 178, 179, 180, 181, 182, 183, 184, 185, 186, 187,
		190, 191, 192, 193, 194, 195, 196, 197, 198, 199, 200, 201, 202, 203, 204, 205, 206, 207, 208,
		211, 212, 213, 214, 215, 216, 217, 218, 219, 220, 221, 222, 223, 224, 225, 226, 227, 228, 229,
		232, 233, 234, 235, 236, 237, 238, 239, 240, 241, 242, 243, 244, 245, 246, 247, 248, 249, 250,
		253, 254, 255, 256, 257, 258, 259, 260, 261, 262, 263, 264, 265, 266, 267, 268, 269, 270, 271,
		274, 275, 276, 277, 278, 279, 280, 281, 282, 283, 284, 285, 286, 287, 288, 289, 290, 291, 292,
		295, 296, 297, 298, 299, 300, 301, 302, 303, 304, 305, 306, 307, 308, 309, 310, 311, 312, 313,
		316, 317, 318, 319, 320, 321, 322, 323, 324, 325, 326, 327, 328, 329, 330, 331, 332, 333, 334,
		337, 338, 339, 340, 341, 342, 343, 344, 345, 346, 347, 348, 349, 350, 351, 352, 353, 354, 355,
		358, 359, 360, 361, 362, 363, 364, 365, 366, 367, 368, 369, 370, 371, 372, 373, 374, 375, 376,
		379, 380, 381, 382, 383, 384, 385, 386, 387, 388, 389, 390, 391, 392, 393, 394, 395, 396, 397,
		400, 401, 402, 403, 404, 405, 406, 407, 408, 409, 410, 411, 412, 413, 414, 415, 416, 417, 418
		};


/**
 * 拡張盤面 -> 実盤面　の変換配列
 * Conversion array: extended board -> real board
 */
constexpr int etor[EBVCNT] = {
		442, 442, 442, 442, 442, 442, 442, 442, 442, 442, 442, 442, 442, 442, 442, 442, 442, 442, 442, 442, 442,
		442, 0,   1,   2,   3,   4,   5,   6,   7,   8,   9,   10,  11,  12,  13,  14,  15,  16,  17,  18,  442,
		442, 19,  20,  21,  22,  23,  24,  25,  26,  27,  28,  29,  30,  31,  32,  33,  34,  35,  36,  37,  442,
		442, 38,  39,  40,  41,  42,  43,  44,  45,  46,  47,  48,  49,  50,  51,  52,  53,  54,  55,  56,  442,
		442, 57,  58,  59,  60,  61,  62,  63,  64,  65,  66,  67,  68,  69,  70,  71,  72,  73,  74,  75,  442,
		442, 76,  77,  78,  79,  80,  81,  82,  83,  84,  85,  86,  87,  88,  89,  90,  91,  92,  93,  94,  442,
		442, 95,  96,  97,  98,  99,  100, 101, 102, 103, 104, 105, 106, 107, 108, 109, 110, 111, 112, 113, 442,
		442, 114, 115, 116, 117, 118, 119, 120, 121, 122, 123, 124, 125, 126, 127, 128, 129, 130, 131, 132, 442,
		442, 133, 134, 135, 136, 137, 138, 139, 140, 141, 142, 143, 144, 145, 146, 147, 148, 149, 150, 151, 442,
		442, 152, 153, 154, 155, 156, 157, 158, 159, 160, 161, 162, 163, 164, 165, 166, 167, 168, 169, 170, 442,
		442, 171, 172, 173, 174, 175, 176, 177, 178, 179, 180, 181, 182, 183, 184, 185, 186, 187, 188, 189, 442,
		442, 190, 191, 192, 193, 194, 195, 196, 197, 198, 199, 200, 201, 202, 203, 204, 205, 206, 207, 208, 442,
		442, 209, 210, 211, 212, 213, 214, 215, 216, 217, 218, 219, 220, 221, 222, 223, 224, 225, 226, 227, 442,
		442, 228, 229, 230, 231, 232, 233, 234, 235, 236, 237, 238, 239, 240, 241, 242, 243, 244, 245, 246, 442,
		442, 247, 248, 249, 250, 251, 252, 253, 254, 255, 256, 257, 258, 259, 260, 261, 262, 263, 264, 265, 442,
		442, 266, 267, 268, 269, 270, 271, 272, 273, 274, 275, 276, 277, 278, 279, 280, 281, 282, 283, 284, 442,
		442, 285, 286, 287, 288, 289, 290, 291, 292, 293, 294, 295, 296, 297, 298, 299, 300, 301, 302, 303, 442,
		442, 304, 305, 306, 307, 308, 309, 310, 311, 312, 313, 314, 315, 316, 317, 318, 319, 320, 321, 322, 442,
		442, 323, 324, 325, 326, 327, 328, 329, 330, 331, 332, 333, 334, 335, 336, 337, 338, 339, 340, 341, 442,
		442, 342, 343, 344, 345, 346, 347, 348, 349, 350, 351, 352, 353, 354, 355, 356, 357, 358, 359, 360, 442,
		442, 442, 442, 442, 442, 442, 442, 442, 442, 442, 442, 442, 442, 442, 442, 442, 442, 442, 442, 442, 442
		};


/**
 * 実盤面 -> x座標　の変換配列
 * Conversion array: real board -> column index (x-coordinate)
 */
constexpr int rtox[BVCNT] = {
		0,  1,  2,  3,  4,  5,  6,  7,  8,  9,  10, 11, 12, 13, 14, 15, 16, 17, 18,
		0,  1,  2,  3,  4,  5,  6,  7,  8,  9,  10, 11, 12, 13, 14, 15, 16, 17, 18,
		0,  1,  2,  3,  4,  5,  6,  7,  8,  9,  10, 11, 12, 13, 14, 15, 16, 17, 18,
		0,  1,  2,  3,  4,  5,  6,  7,  8,  9,  10, 11, 12, 13, 14, 15, 16, 17, 18,
		0,  1,  2,  3,  4,  5,  6,  7,  8,  9,  10, 11, 12, 13, 14, 15, 16, 17, 18,
		0,  1,  2,  3,  4,  5,  6,  7,  8,  9,  10, 11, 12, 13, 14, 15, 16, 17, 18,
		0,  1,  2,  3,  4,  5,  6,  7,  8,  9,  10, 11, 12, 13, 14, 15, 16, 17, 18,
		0,  1,  2,  3,  4,  5,  6,  7,  8,  9,  10, 11, 12, 13, 14, 15, 16, 17, 18,
		0,  1,  2,  3,  4,  5,  6,  7,  8,  9,  10, 11, 12, 13, 14, 15, 16, 17, 18,
		0,  1,  2,  3,  4,  5,  6,  7,  8,  9,  10, 11, 12, 13, 14, 15, 16, 17, 18,
		0,  1,  2,  3,  4,  5,  6,  7,  8,  9,  10, 11, 12, 13, 14, 15, 16, 17, 18,
		0,  1,  2,  3,  4,  5,  6,  7,  8,  9,  10, 11, 12, 13, 14, 15, 16, 17, 18,
		0,  1,  2,  3,  4,  5,  6,  7,  8,  9,  10, 11, 12, 13, 14, 15, 16, 17, 18,
		0,  1,  2,  3,  4,  5,  6,  7,  8,  9,  10, 11, 12, 13, 14, 15, 16, 17, 18,
		0,  1,  2,  3,  4,  5,  6,  7,  8,  9,  10, 11, 12, 13, 14, 15, 16, 17, 18,
		0,  1,  2,  3,  4,  5,  6,  7,  8,  9,  10, 11, 12, 13, 14, 15, 16, 17, 18,
		0,  1,  2,  3,  4,  5,  6,  7,  8,  9,  10, 11, 12, 13, 14, 15, 16, 17, 18,
		0,  1,  2,  3,  4,  5,  6,  7,  8,  9,  10, 11, 12, 13, 14, 15, 16, 17, 18,
		0,  1,  2,  3,  4,  5,  6,  7,  8,  9,  10, 11, 12, 13, 14, 15, 16, 17, 18
		};


/**
 * 実盤面 -> y座標　の変換配列
 * Conversion array: real board -> rank index (y-coordinate)
 */
constexpr int rtoy[BVCNT] = {
		0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,
		1,  1,  1,  1,  1,  1,  1,  1,  1,  1,  1,  1,  1,  1,  1,  1,  1,  1,  1,
		2,  2,  2,  2,  2,  2,  2,  2,  2,  2,  2,  2,  2,  2,  2,  2,  2,  2,  2,
		3,  3,  3,  3,  3,  3,  3,  3,  3,  3,  3,  3,  3,  3,  3,  3,  3,  3,  3,
		4,  4,  4,  4,  4,  4,  4,  4,  4,  4,  4,  4,  4,  4,  4,  4,  4,  4,  4,
		5,  5,  5,  5,  5,  5,  5,  5,  5,  5,  5,  5,  5,  5,  5,  5,  5,  5,  5,
		6,  6,  6,  6,  6,  6,  6,  6,  6,  6,  6,  6,  6,  6,  6,  6,  6,  6,  6,
		7,  7,  7,  7,  7,  7,  7,  7,  7,  7,  7,  7,  7,  7,  7,  7,  7,  7,  7,
		8,  8,  8,  8,  8,  8,  8,  8,  8,  8,  8,  8,  8,  8,  8,  8,  8,  8,  8,
		9,  9,  9,  9,  9,  9,  9,  9,  9,  9,  9,  9,  9,  9,  9,  9,  9,  9,  9,
		10, 10, 10, 10, 10, 10, 10, 10, 10, 10, 10, 10, 10, 10, 10, 10, 10, 10, 10,
		11, 11, 11, 11, 11, 11, 11, 11, 11, 11, 11, 11, 11, 11, 11, 11, 11, 11, 11,
		12, 12, 12, 12, 12, 12, 12, 12, 12, 12, 12, 12, 12, 12, 12, 12, 12, 12, 12,
		13, 13, 13, 13, 13, 13, 13, 13, 13, 13, 13, 13, 13, 13, 13, 13, 13, 13, 13,
		14, 14, 14, 14, 14, 14, 14, 14, 14, 14, 14, 14, 14, 14, 14, 14, 14, 14, 14,
		15, 15, 15, 15, 15, 15, 15, 15, 15, 15, 15, 15, 15, 15, 15, 15, 15, 15, 15,
		16, 16, 16, 16, 16, 16, 16, 16, 16, 16, 16, 16, 16, 16, 16, 16, 16, 16, 16,
		17, 17, 17, 17, 17, 17, 17, 17, 17, 17, 17, 17, 17, 17, 17, 17, 17, 17, 17,
		18, 18, 18, 18, 18, 18, 18, 18, 18, 18, 18, 18, 18, 18, 18, 18, 18, 18, 18
		};


/**
 * 拡張盤面 -> x座標　の変換配列
 * Conversion array: extended board -> column index (x-coordinate)
 */
constexpr int etox[EBVCNT] = {
		0,  1,  2,  3,  4,  5,  6,  7,  8,  9,  10, 11, 12, 13, 14, 15, 16, 17, 18, 19, 20,
		0,  1,  2,  3,  4,  5,  6,  7,  8,  9,  10, 11, 12, 13, 14, 15, 16, 17, 18, 19, 20,
		0,  1,  2,  3,  4,  5,  6,  7,  8,  9,  10, 11, 12, 13, 14, 15, 16, 17, 18, 19, 20,
		0,  1,  2,  3,  4,  5,  6,  7,  8,  9,  10, 11, 12, 13, 14, 15, 16, 17, 18, 19, 20,
		0,  1,  2,  3,  4,  5,  6,  7,  8,  9,  10, 11, 12, 13, 14, 15, 16, 17, 18, 19, 20,
		0,  1,  2,  3,  4,  5,  6,  7,  8,  9,  10, 11, 12, 13, 14, 15, 16, 17, 18, 19, 20,
		0,  1,  2,  3,  4,  5,  6,  7,  8,  9,  10, 11, 12, 13, 14, 15, 16, 17, 18, 19, 20,
		0,  1,  2,  3,  4,  5,  6,  7,  8,  9,  10, 11, 12, 13, 14, 15, 16, 17, 18, 19, 20,
		0,  1,  2,  3,  4,  5,  6,  7,  8,  9,  10, 11, 12, 13, 14, 15, 16, 17, 18, 19, 20,
		0,  1,  2,  3,  4,  5,  6,  7,  8,  9,  10, 11, 12, 13, 14, 15, 16, 17, 18, 19, 20,
		0,  1,  2,  3,  4,  5,  6,  7,  8,  9,  10, 11, 12, 13, 14, 15, 16, 17, 18, 19, 20,
		0,  1,  2,  3,  4,  5,  6,  7,  8,  9,  10, 11, 12, 13, 14, 15, 16, 17, 18, 19, 20,
		0,  1,  2,  3,  4,  5,  6,  7,  8,  9,  10, 11, 12, 13, 14, 15, 16, 17, 18, 19, 20,
		0,  1,  2,  3,  4,  5,  6,  7,  8,  9,  10, 11, 12, 13, 14, 15, 16, 17, 18, 19, 20,
		0,  1,  2,  3,  4,  5,  6,  7,  8,  9,  10, 11, 12, 13, 14, 15, 16, 17, 18, 19, 20,
		0,  1,  2,  3,  4,  5,  6,  7,  8,  9,  10, 11, 12, 13, 14, 15, 16, 17, 18, 19, 20,
		0,  1,  2,  3,  4,  5,  6,  7,  8,  9,  10, 11, 12, 13, 14, 15, 16, 17, 18, 19, 20,
		0,  1,  2,  3,  4,  5,  6,  7,  8,  9,  10, 11, 12, 13, 14, 15, 16, 17, 18, 19, 20,
		0,  1,  2,  3,  4,  5,  6,  7,  8,  9,  10, 11, 12, 13, 14, 15, 16, 17, 18, 19, 20,
		0,  1,  2,  3,  4,  5,  6,  7,  8,  9,  10, 11, 12, 13, 14, 15, 16, 17, 18, 19, 20,
		0,  1,  2,  3,  4,  5,  6,  7,  8,  9,  10, 11, 12, 13, 14, 15, 16, 17, 18, 19, 20
		};


/**
 * 拡張盤面 -> y座標　の変換配列
 * Conversion array: extended board -> rank index (y-coordinate)
 */
constexpr int etoy[EBVCNT] = {
		0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,
		1,  1,  1,  1,  1,  1,  1,  1,  1,  1,  1,  1,  1,  1,  1,  1,  1,  1,  1,  1,  1,
		2,  2,  2,  2,  2,  2,  2,  2,  2,  2,  2,  2,  2,  2,  2,  2,  2,  2,  2,  2,  2,
		3,  3,  3,  3,  3,  3,  3,  3,  3,  3,  3,  3,  3,  3,  3,  3,  3,  3,  3,  3,  3,
		4,  4,  4,  4,  4,  4,  4,  4,  4,  4,  4,  4,  4,  4,  4,  4,  4,  4,  4,  4,  4,
		5,  5,  5,  5,  5,  5,  5,  5,  5,  5,  5,  5,  5,  5,  5,  5,  5,  5,  5,  5,  5,
		6,  6,  6,  6,  6,  6,  6,  6,  6,  6,  6,  6,  6,  6,  6,  6,  6,  6,  6,  6,  6,
		7,  7,  7,  7,  7,  7,  7,  7,  7,  7,  7,  7,  7,  7,  7,  7,  7,  7,  7,  7,  7,
		8,  8,  8,  8,  8,  8,  8,  8,  8,  8,  8,  8,  8,  8,  8,  8,  8,  8,  8,  8,  8,
		9,  9,  9,  9,  9,  9,  9,  9,  9,  9,  9,  9,  9,  9,  9,  9,  9,  9,  9,  9,  9,
		10, 10, 10, 10, 10, 10, 10, 10, 10, 10, 10, 10, 10, 10, 10, 10, 10, 10, 10, 10, 10,
		11, 11, 11, 11, 11, 11, 11, 11, 11, 11, 11, 11, 11, 11, 11, 11, 11, 11, 11, 11, 11,
		12, 12, 12, 12, 12, 12, 12, 12, 12, 12, 12, 12, 12, 12, 12, 12, 12, 12, 12, 12, 12,
		13, 13, 13, 13, 13, 13, 13, 13, 13, 13, 13, 13, 13, 13, 13, 13, 13, 13, 13, 13, 13,
		14, 14, 14, 14, 14, 14, 14, 14, 14, 14, 14, 14, 14, 14, 14, 14, 14, 14, 14, 14, 14,
		15, 15, 15, 15, 15, 15, 15, 15, 15, 15, 15, 15, 15, 15, 15, 15, 15, 15, 15, 15, 15,
		16, 16, 16, 16, 16, 16, 16, 16, 16, 16, 16, 16, 16, 16, 16, 16, 16, 16, 16, 16, 16,
		17, 17, 17, 17, 17, 17, 17, 17, 17, 17, 17, 17, 17, 17, 17, 17, 17, 17, 17, 17, 17,
		18, 18, 18, 18, 18, 18, 18, 18, 18, 18, 18, 18, 18, 18, 18, 18, 18, 18, 18, 18, 18,
		19, 19, 19, 19, 19, 19, 19, 19, 19, 19, 19, 19, 19, 19, 19, 19, 19, 19, 19, 19, 19,
		20, 20, 20, 20, 20, 20, 20, 20, 20, 20, 20, 20, 20, 20, 20, 20, 20, 20, 20, 20, 20
		};


/**
 * xy座標 -> 実盤面　の変換配列
 * Conversion array: (x,y) -> real board
 */
constexpr int xytor[BSIZE][BSIZE] = {
		{ 0, 19, 38, 57, 76, 95, 114, 133, 152, 171, 190, 209, 228, 247, 266, 285, 304, 323, 342},
		{ 1, 20, 39, 58, 77, 96, 115, 134, 153, 172, 191, 210, 229, 248, 267, 286, 305, 324, 343},
		{ 2, 21, 40, 59, 78, 97, 116, 135, 154, 173, 192, 211, 230, 249, 268, 287, 306, 325, 344},
		{ 3, 22, 41, 60, 79, 98, 117, 136, 155, 174, 193, 212, 231, 250, 269, 288, 307, 326, 345},
		{ 4, 23, 42, 61, 80, 99, 118, 137, 156, 175, 194, 213, 232, 251, 270, 289, 308, 327, 346},
		{ 5, 24, 43, 62, 81, 100, 119, 138, 157, 176, 195, 214, 233, 252, 271, 290, 309, 328, 347},
		{ 6, 25, 44, 63, 82, 101, 120, 139, 158, 177, 196, 215, 234, 253, 272, 291, 310, 329, 348},
		{ 7, 26, 45, 64, 83, 102, 121, 140, 159, 178, 197, 216, 235, 254, 273, 292, 311, 330, 349},
		{ 8, 27, 46, 65, 84, 103, 122, 141, 160, 179, 198, 217, 236, 255, 274, 293, 312, 331, 350},
		{ 9, 28, 47, 66, 85, 104, 123, 142, 161, 180, 199, 218, 237, 256, 275, 294, 313, 332, 351},
		{ 10, 29, 48, 67, 86, 105, 124, 143, 162, 181, 200, 219, 238, 257, 276, 295, 314, 333, 352},
		{ 11, 30, 49, 68, 87, 106, 125, 144, 163, 182, 201, 220, 239, 258, 277, 296, 315, 334, 353},
		{ 12, 31, 50, 69, 88, 107, 126, 145, 164, 183, 202, 221, 240, 259, 278, 297, 316, 335, 354},
		{ 13, 32, 51, 70, 89, 108, 127, 146, 165, 184, 203, 222, 241, 260, 279, 298, 317, 336, 355},
		{ 14, 33, 52, 71, 90, 109, 128, 147, 166, 185, 204, 223, 242, 261, 280, 299, 318, 337, 356},
		{ 15, 34, 53, 72, 91, 110, 129, 148, 167, 186, 205, 224, 243, 262, 281, 300, 319, 338, 357},
		{ 16, 35, 54, 73, 92, 111, 130, 149, 168, 187, 206, 225, 244, 263, 282, 301, 320, 339, 358},
		{ 17, 36, 55, 74, 93, 112, 131, 150, 169, 188, 207, 226, 245, 264, 283, 302, 321, 340, 359},
		{ 18, 37, 56, 75, 94, 113, 132, 151, 170, 189, 208, 227, 246, 265, 284, 303, 322, 341, 360}
		};


/**
 * xy座標 -> 拡張盤面　の変換配列
 * Conversion array: (x,y) -> extended board
 */
constexpr int xytoe[EBSIZE][EBSIZE] = {
		{ 0, 21, 42, 63, 84, 105, 126, 147, 168, 189, 210, 231, 252, 273, 294, 315, 336, 357, 378, 399, 420},
		{ 1, 22, 43, 64, 85, 106, 127, 148, 169, 190, 211, 232, 253, 274, 295, 316, 337, 358, 379, 400, 421},
		{ 2, 23, 44, 65, 86, 107, 128, 149, 170, 191, 212, 233, 254, 275, 296, 317, 338, 359, 380, 401, 422},
		{ 3, 24, 45, 66, 87, 108, 129, 150, 171, 192, 213, 234, 255, 276, 297, 318, 339, 360, 381, 402, 423},
		{ 4, 25, 46, 67, 88, 109, 130, 151, 172, 193, 214, 235, 256, 277, 298, 319, 340, 361, 382, 403, 424},
		{ 5, 26, 47, 68, 89, 110, 131, 152, 173, 194, 215, 236, 257, 278, 299, 320, 341, 362, 383, 404, 425},
		{ 6, 27, 48, 69, 90, 111, 132, 153, 174, 195, 216, 237, 258, 279, 300, 321, 342, 363, 384, 405, 426},
		{ 7, 28, 49, 70, 91, 112, 133, 154, 175, 196, 217, 238, 259, 280, 301, 322, 343, 364, 385, 406, 427},
		{ 8, 29, 50, 71, 92, 113, 134, 155, 176, 197, 218, 239, 260, 281, 302, 323, 344, 365, 386, 407, 428},
		{ 9, 30, 51, 72, 93, 114, 135, 156, 177, 198, 219, 240, 261, 282, 303, 324, 345, 366, 387, 408, 429},
		{ 10, 31, 52, 73, 94, 115, 136, 157, 178, 199, 220, 241, 262, 283, 304, 325, 346, 367, 388, 409, 430},
		{ 11, 32, 53, 74, 95, 116, 137, 158, 179, 200, 221, 242, 263, 284, 305, 326, 347, 368, 389, 410, 431},
		{ 12, 33, 54, 75, 96, 117, 138, 159, 180, 201, 222, 243, 264, 285, 306, 327, 348, 369, 390, 411, 432},
		{ 13, 34, 55, 76, 97, 118, 139, 160, 181, 202, 223, 244, 265, 286, 307, 328, 349, 370, 391, 412, 433},
		{ 14, 35, 56, 77, 98, 119, 140, 161, 182, 203, 224, 245, 266, 287, 308, 329, 350, 371, 392, 413, 434},
		{ 15, 36, 57, 78, 99, 120, 141, 162, 183, 204, 225, 246, 267, 288, 309, 330, 351, 372, 393, 414, 435},
		{ 16, 37, 58, 79, 100, 121, 142, 163, 184, 205, 226, 247, 268, 289, 310, 331, 352, 373, 394, 415, 436},
		{ 17, 38, 59, 80, 101, 122, 143, 164, 185, 206, 227, 248, 269, 290, 311, 332, 353, 374, 395, 416, 437},
		{ 18, 39, 60, 81, 102, 123, 144, 165, 186, 207, 228, 249, 270, 291, 312, 333, 354, 375, 396, 417, 438},
		{ 19, 40, 61, 82, 103, 124, 145, 166, 187, 208, 229, 250, 271, 292, 313, 334, 355, 376, 397, 418, 439},
		{ 20, 41, 62, 83, 104, 125, 146, 167, 188, 209, 230, 251, 272, 293, 314, 335, 356, 377, 398, 419, 440}
		};


/**
 * 対称変換のための配列
 * Conversion array for symmetrical operation.
 */
struct SymmetricalVertex {

	// 拡張座標の対称点
	// Symmetrical position for extended-board vertex.
	int ev[8][EBVCNT][2];

	// 実座標の対称点
	// Symmetrical position for real-board vertex.
	int rv[8][BVCNT][2];

	// axis=0: symmetrical index.
	//         0->original, 1->90deg rotation, ...
	// axis=1: original position
	// axis=2: transform([0]) or inverse transform([1])
	//
	// Ex. sym_v = sv.ev[sym_idx][v][0]
	//     inv_v = sv.ev[sym_idx][sym_v][1]
	//     then, inv_v is corresponding to v.

	SymmetricalVertex() {
		for(int i=0;i<8;++i){
			bool is_inverted = (i >= 4);
			int rotation_cnt = i % 4;

			for(int j=0;j<EBVCNT;++j){
				int ex = etox[j];
				int ey = etoy[j];

				if(is_inverted) ex = EBSIZE - 1 - ex;
				for(int k=0;k<rotation_cnt;++k){
					int ex_cpy = ex;
					ex = ey;
					ey = EBSIZE - 1 - ex_cpy;
				}

				int sym_ev = xytoe[ex][ey];

				ev[i][j][0] = sym_ev;
				ev[i][sym_ev][1] = j;
			}

			for(int j=0;j<BVCNT;++j){
				int x = rtox[j];
				int y = rtoy[j];

				if(is_inverted) x = BSIZE - 1 - x;
				for(int k=0;k<rotation_cnt;++k){
					int x_cpy = x;
					x = y;
					y = BSIZE - 1 - x_cpy;
				}

				int sym_rv = xytor[x][y];

				rv[i][j][0] = sym_rv;
				rv[i][sym_rv][1] = j;
			}
		}
	}

}; const SymmetricalVertex sv;
