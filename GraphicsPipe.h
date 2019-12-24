#pragma once

#include "Pipe.h"
#include <string>
#include <iostream>
#include "enums.h"
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

