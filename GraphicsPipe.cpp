/**************************************************************************
@ Project: Magshimim C++ Course Semester 1 Lesson 7-8 Chess Project
@ File: GraphicsPipe.cpp
@ Version: 1.0
@ Made By: Lior Yehezkely // lior5654 // Th3Wh1t3Kn19ht & Jacob Galam // JacobGalam
***************************************************************************/

// INCLUDES
#include "GraphicsPipe.h"

GraphicsPipe::GraphicsPipe() {};

/*
[?] Description: A constructor for the GraphicsPipe class.
[<-] char initMsgToGraphics[MSG_SIZE]: The initial message to be send through the pipe.
[->] X
*/
GraphicsPipe::GraphicsPipe(char initMsgToGraphics[MSG_SIZE]) :
	_p()
{
	Sleep(3000);
	bool isConnect = this->_p.connect();

	string ans;
	while (!isConnect)
	{
		std::cout << "cant connect to graphics" << endl;
		std::cout << "Do you try to connect again or exit? (0-try again, 1-exit)" << endl;
		std::cin >> ans;

		if (ans == "0")
		{
			std::cout << "trying connect again.." << endl;
			Sleep(5000);
			isConnect = this->_p.connect();
		}
		else
		{
			throw "Could not connect to the frontend :(";  // this should never happen, just making sure
		}
	}
	this->_p.sendMessageToGraphics(initMsgToGraphics);  // sending the intial message to be sent
	this->acceptGraphicsReply(); // accepting a reply
}

/*
[?] Description: A deconstructor for the GraphicsPipe class.
[<-] X (none)
[->] X
*/
GraphicsPipe::~GraphicsPipe()
{
	this->_p.close();  // closing the pipe.
}

/*
[?] Description: A method of the GraphicsPipe class that sends a given MoveCode through the pipe.
[<-] const MoveCode& moveCodeToSend: The move code to be sent.
[->] X (void)
*/
void GraphicsPipe::sendMoveCode(const MoveCode& moveCodeToSend)
{
	char msgToGraphics[MSG_SIZE] = { 0 };
	msgToGraphics[0] = (char)((unsigned int)moveCodeToSend + '0');
	msgToGraphics[1] = 0;
	this->_p.sendMessageToGraphics(msgToGraphics);
}

/*
[?] Description: A method of the GraphicsPipe class that accepts a reply from the pipe.
[<-] X (none)
[->] X (void)
*/
void GraphicsPipe::acceptGraphicsReply()
{
	this->_latestReply = this->_p.getMessageFromGraphics();
	if (this->_latestReply.length() != VALID_REPLY_LENGTH)
	{
		throw "Invalid Graphics Reply Length";  // should never happen, again, just making sure
	}
}

/*
[?] Description: A getter of the latestReply field of the GraphicsPipe class.
[<-] X (none)
[->] std::string: the latest reply recieved.
*/
std::string GraphicsPipe::getLatestReply()
{
	return this->_latestReply;
}