#pragma once

#include "Pipe.h"
#include <string>
#include <iostream>
#include "enums.h"
#define MSG_SIZE 1024
#define VALID_REPLY_LENGTH 4

class GraphicsPipe
{
public:
	GraphicsPipe(char initMsgToGraphics[MSG_SIZE]);
	~GraphicsPipe();
	void sendMoveCode(const MoveCode& moveCodeToSend);
	void acceptGraphicsReply();

private:
	Pipe _p;
	std::string _latestReply;
};

