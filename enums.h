/**************************************************************************
@ Project: Magshimim C++ Course Semester 1 Lesson 7-8 Chess Project
@ File: enums.h
@ Version: 1.0
@ Made By: Lior Yehezkely // lior5654 // Th3Wh1t3Kn19ht & Jacob Galan // JacobGalm
***************************************************************************/
#pragma once

namespace chessEnums
{
	enum class Color { WHITE, BLACK };
	enum class MoveCode { VALID_MOVE, CAUSES_CHECK, ORIGIN_NOT_OWNED, DEST_OWNED, IMPLIES_SELF_CHECK, OUT_OF_BOUNDS, DEFIES_SOLLIDER_MOVE_PATTERN, ORIGIN_AND_DEST_EQUALITY, CHECKMATE };
}
