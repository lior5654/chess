/**************************************************************************
@ Project: Magshimim C++ Course Semester 1 Lesson 7-8 Chess Project
@ File: GraphicsPipe.h
@ Version: 1.0
@ Made By: Lior Yehezkely // lior5654 // Th3Wh1t3Kn19ht & Jacob Galam // JacobGalam
***************************************************************************/
#pragma once

// INCLUDES
#include "Pipe.h"
#include <string>
#include <iostream>
#include "enums.h"

using chessEnums::Color;
using chessEnums::MoveCode;
// DEFINE CONSTANTS
#define MSG_SIZE 1024
#define VALID_REPLY_LENGTH 4
#define SRC_COL_IDX 0
#define SRC_ROW_IDX 1
#define DST_COL_IDX 2
#define DST_ROW_IDX 3

class GraphicsPipe
{
public:
	GraphicsPipe(char initMsgToGraphics[MSG_SIZE]);
	GraphicsPipe();
	~GraphicsPipe();
	void sendMoveCode(const MoveCode& moveCodeToSend);
	void acceptGraphicsReply();
	std::string getLatestReply();
private:
	Pipe _p;
	std::string _latestReply;
};

