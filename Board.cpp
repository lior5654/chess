/**************************************************************************
@ Project: Magshimim C++ Course Semester 1 Lesson 7-8 Chess Project
@ File: Board.cpp
@ Version: 1.0
@ Made By: Lior Yehezkely // lior5654 // Th3Wh1t3Kn19ht & Jacob Galam // JacobGalam
***************************************************************************/

// ICNLUDES
#include "Board.h"

/*
[?] Description: A Position based indexing operator for the Board class.
[<-] const Position& index: A constant reference to the map index to be accessed position based.
[->] Solider*&: A reference to the solider pointer in the given index.
*/
Solider*& Board::operator[](const Position& index)
{
	// using position due to the fact that exceptions are already handled in it
	return this->_map[index.y()][index.x()];
}

/*
[?] Description: A Position based indexing operator for the Board class. (const version)
[<-] const Position& index: A constant reference to the map index to be accessed position based.
[->] Solider*: The solider pointer in the given index.
*/
Solider* Board::operator[](const Position& index) const
{
	// using position due to the fact that exceptions are already handled in it
	return this->_map[index.y()][index.x()];
}

/*
[?] Description: An unsigned int based indexing operator for the Board class.
[<-] const Position& index: A constant reference to the map index to be accessed unsigned int based.
[->] Solider*&: A reference to the solider pointer in the given index.
*/
Solider*& Board::operator[](const unsigned int& index)
{
	// using position due to the fact that exceptions are already handled in it
	Position indexPos = Position(index % BOARD_SIZE, index / BOARD_SIZE);
	return (*this)[indexPos];
}

/*
[?] Description: An unsigned int based indexing operator for the Board class. (const version)
[<-] const Position& index: A constant reference to the map index to be accessed unsigned int based.
[->] Solider*: The solider pointer in the given index.
*/
Solider* Board::operator[](const unsigned int& index) const
{
	// using position due to the fact that exceptions are already handled in it
	Position indexPos = Position(index % BOARD_SIZE, index / BOARD_SIZE);
	return (*this)[indexPos];
}

/*
[?] Description: A method of the baord class that deletes a solider at a given location.
[<-] const Position& origin: the origin of the solider to be deleted.
[->] X (void)
*/
void Board::deleteSolider(const Position& origin)
{
	if ((*this)[origin] != nullptr)
	{
		delete (*this)[origin];
		(*this)[origin] = nullptr;
	}
}

/*
[?] Description: A getter of the current player filed of the board class.
[<-] X (none)
[->] Color: the Color of the current player.
*/
Color Board::currentPlayer(void) const
{
	return this->_currentPlayer;
}

/*
[?] Description: A constructor for the Board class.
[<-] const std::string& boardMap: the board map to be used.
[->] X
*/
Board::Board(const std::string& boardMap)
{
	unsigned int i = 0;  // loop variable
	Color currentColor = Color::WHITE;
	this->_currentPlayer = Color::BLACK;
	this->playerKings[Color::WHITE] = nullptr;
	this->playerKings[Color::BLACK] = nullptr;
	if (boardMap.length() != BOARD_SIZE * BOARD_SIZE + 1)
	{
		throw "invalid initial board map length";  // this should never happen, just making sure
	}
	for (unsigned int i = 0; i < BOARD_SIZE * BOARD_SIZE; i++)
	{
		if (boardMap[i] == EMPTY_BOARD_POSITION_SYMBOL)
		{
			(*this)[i] = nullptr;
		}
		else if (!std::isalpha(boardMap[i]))
		{
			throw "Invalid Board Char Given to Board Ctor";  // this should never happen, just making sure
		}
		else
		{
			currentColor = (std::isupper(boardMap[i])) ? (Color::BLACK) : (Color::WHITE);
			switch (std::tolower(boardMap[i]))
			{
			case KING_SYMBOL:
				if (this->playerKings[currentColor] != nullptr)
				{
					throw "There can only be 1 king of each color";  // this should never happen, just making sure
				}
				(*this)[i] = new King(Position(i), currentColor, this);
				this->playerKings[currentColor] = (King*)((*this)[i]);
				break;
			case ROOK_SYMBOL:
				(*this)[i] = new Rook(Position(i), currentColor, this);
				break;
			case KNIGHT_SYMBOL:
				(*this)[i] = new Knight(Position(i), currentColor, this);
				break;
			case BISHOP_SYMBOL:
				(*this)[i] = new Bishop(Position(i), currentColor, this);
				break;
			case QUEEN_SYMBOL:
				(*this)[i] = new Queen(Position(i), currentColor, this);
				break;
			case PAWN_SYMBOL:
				(*this)[i] = new Pawn(Position(i), currentColor, this);
				break;
			default:
				throw "Unkown Solider Char Given to Board Ctor";  // this should never happen, just making sure
			}
		}
	}
	if (this->playerKings[Color::WHITE] == nullptr || this->playerKings[Color::BLACK] == nullptr)
	{
		throw "Missing Kings In Board Map Given to Board Ctor";  // this should never happen, just making sure
	}
}

/*
[?] Description: A method of the Board class that plays a move from a given origin to a given destination. returns a move code that represents the move according to the pipe protocol.
[<-] const Position& origin: the origin of the move.
[<-] const Position& dest: the destination of the move.
[->] MoveCode resultantMoveCode: the resultant move code.
*/
MoveCode Board::move(const Position& origin, const Position& dest)
{
	MoveCode resultantMoveCode = MoveCode::VALID_MOVE;
	Solider* pDestSolider = nullptr;
	resultantMoveCode = this->canPieceMove(origin, dest);
	if (resultantMoveCode == MoveCode::VALID_MOVE)
	{
		pDestSolider = this->moveWithoutDeletion(origin, dest);
		if (pDestSolider != nullptr)
		{
			delete pDestSolider;
		}
		resultantMoveCode = this->getCheckStatus();
		this->_currentPlayer = (this->currentPlayer() == Color::WHITE) ? (Color::BLACK) : (Color::WHITE);
	}
	return resultantMoveCode;
}

/*
[?] Description: A method of the Board class that checks whether or not there exists a solider in a given position that can be eaten by the opposing group if it were to be their turn. (essentially mainly used for a check test).
[<-] const Position& positionToBeTested: the position to be tested.
[->] bool: a boolean represnetation of whether or not there exist an alereted solider in the given position.
*/
bool Board::isPositionAlerted(const Position& positionToBeTested)
{
	unsigned int i = 0;
	if ((*this)[positionToBeTested] == nullptr)  // a position that lacks a solider is considered to be a non alerted solider.
	{
		return false;
	}
	for (i = 0; i < BOARD_SIZE * BOARD_SIZE; i++)
	{

		if ((*this)[i] == nullptr || i == positionToBeTested)
		{
			continue;
		}
		if ((*this)[i]->color() != (*this)[positionToBeTested]->color() && (*this)[i]->canMove((*this)[positionToBeTested]->position()))
		{
			return true;
		}
	}
	return false;
}

MoveCode Board::getCheckStatus(void)
{
	unsigned int i = 0;
	unsigned int j = 0;
	bool canProtect = false;
	Solider* pDestSoldier = nullptr;
	King* kingToTest = nullptr;
	kingToTest = this->playerKings[((this->currentPlayer() == Color::WHITE) ? (Color::BLACK) : (Color::WHITE))];
	if (!this->isPositionAlerted(kingToTest->position()))
	{
		return MoveCode::VALID_MOVE;
	}
	this->_currentPlayer = (this->currentPlayer() == Color::WHITE) ? (Color::BLACK) : (Color::WHITE);
	for (i = 0; i < BOARD_SIZE * BOARD_SIZE && !canProtect; i++)
	{
		if ((*this)[i] != nullptr && (*this)[i]->color() == kingToTest->color())
		{
			for (j = 0; j < BOARD_SIZE * BOARD_SIZE && !canProtect; j++)
			{
				if (this->canPieceMove(i, j) == MoveCode::VALID_MOVE)
				{
					// temporairly moving
					pDestSoldier = this->moveWithoutDeletion(i, j);
					if (!this->isPositionAlerted(kingToTest->position()))
					{
						canProtect = true;
					}
					// undoing the temporary move
					this->moveWithoutDeletion(j, i);
					(*this)[j] = pDestSoldier;
				}
			}
		}
	}
	this->_currentPlayer = (this->currentPlayer() == Color::WHITE) ? (Color::BLACK) : (Color::WHITE);
	return (canProtect) ? (MoveCode::CAUSES_CHECK) : (MoveCode::CHECKMATE);
}
/*
[?] Description: A method of the Board class that returns the move code that fits a given move based on the current Board's state (IMPORTANT, if the move code should be VALID or CAUSES_CHECK or CHECKMATE, valid is still returned. CHECK CAUSE AND CHECKMATE are checked outside of this function).
[<-] const Position& origin: the origin of the move.
[<-] const Position& dest: the destination of the move.
[->] MoveCode resultantMoveCode: the resultant move code.
*/
MoveCode Board::canPieceMove(const Position& origin, const Position& dest)
{
	unsigned int i = 0;
	unsigned int j = 0;
	Solider* pDestSoldier = nullptr;
	MoveCode resultantMoveCode = MoveCode::VALID_MOVE;
	if ((*this)[origin] == nullptr || this->currentPlayer() != (*this)[origin]->color())
	{
		resultantMoveCode = MoveCode::ORIGIN_NOT_OWNED;
	}
	else if ((*this)[dest] != nullptr && this->currentPlayer() == (*this)[dest]->color())
	{
		resultantMoveCode = MoveCode::DEST_OWNED;
	}
	else if (origin == dest)
	{
		resultantMoveCode = MoveCode::ORIGIN_AND_DEST_EQUALITY;
	}
	else if (!(*this)[origin]->canMove(dest))
	{
		resultantMoveCode = MoveCode::DEFIES_SOLLIDER_MOVE_PATTERN;
	}
	else
	{
		// temporairly moving
		pDestSoldier = this->moveWithoutDeletion(origin, dest);
		if (this->isPositionAlerted(this->playerKings[this->currentPlayer()]->position()))
		{
			resultantMoveCode = MoveCode::IMPLIES_SELF_CHECK;
		}
		else
		{
			resultantMoveCode = MoveCode::VALID_MOVE;
		}
		// undoing the temporary move
		this->moveWithoutDeletion(dest, origin);
		(*this)[dest] = pDestSoldier;
	}
	return resultantMoveCode;
}

/*
[?] Description: A method of the Board class that performs a move without deleting the dest solider.
[<-] const Position& origin: the origin of the move.
[<-] const Position& dest: the destination of the move.
[->] Solider* pDestSoldier: the dest's old solider pointer.
*/
Solider* Board::moveWithoutDeletion(const Position& origin, const Position& dest)
{
	Solider* pDestSoldier = nullptr;
	pDestSoldier = (*this)[dest];
	(*this)[dest] = (*this)[origin];
	(*this)[origin] = nullptr;
	(*this)[dest]->setPosition(dest);
	return pDestSoldier;
}

/*
[?] Description: A destructor for the board class
[<-] X (none)
[->] X
*/
Board::~Board()
{
	for (int i = 0; i < BOARD_SIZE * BOARD_SIZE; i++)
	{
		if ((*this)[i] != nullptr)  // technically if it's not nullptr it will be checked again in deleteSolider which is location based but we wanted to avoid code duplication. O(kn) + O(C) = O(n) anyways, so we allowed that to happen inorder to keep modularity in some other places.
		{
			this->deleteSolider((*this)[i]->position());
		}
	}
}
