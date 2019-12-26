#include "GraphicsPipe.h"
GraphicsPipe::GraphicsPipe() {};
GraphicsPipe::GraphicsPipe(char initMsgToGraphics[MSG_SIZE]) :
	_p()
{
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
			throw "Could not connect to the frontend :(";
		}
	}
	this->_p.sendMessageToGraphics(initMsgToGraphics);
	this->acceptGraphicsReply();
}

GraphicsPipe::~GraphicsPipe()
{
	this->_p.close();
}

void GraphicsPipe::sendMoveCode(const MoveCode& moveCodeToSend)
{
	char msgToGraphics[1024] = { 0 };
	msgToGraphics[0] = (char)((unsigned int)moveCodeToSend + '0');
	msgToGraphics[1] = 0;
	this->_p.sendMessageToGraphics(msgToGraphics);
}

void GraphicsPipe::acceptGraphicsReply()
{
	this->_latestReply = this->_p.getMessageFromGraphics();
	if (this->_latestReply.length() != VALID_REPLY_LENGTH)
	{
		throw "Invalid Graphics Reply Length";
	}
}

std::string GraphicsPipe::getLatestReply()
{
	return this->_latestReply;
}