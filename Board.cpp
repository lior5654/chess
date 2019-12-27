#include "Board.h"

Solider*& Board::operator[](const Position& index)
{
	// using position due to the fact that exceptions are already handled in it
	return this->_map[index.row()][index.column()];
}
Solider* Board::operator[](const Position& index) const
{
	// using position due to the fact that exceptions are already handled in it
	return this->_map[index.row()][index.column()];
}
void Board::deleteSolider(const Position& origin)
{
	if ((*this)[origin] != nullptr)
	{
		delete (*this)[origin];
		(*this)[origin] = nullptr;
	}
}
Solider*& Board::operator[](const unsigned int& index)
{
	// using position due to the fact that exceptions are already handled in it
	Position indexPos = Position(index % BOARD_SIZE, index / BOARD_SIZE);
	return (*this)[indexPos];
}
Solider* Board::operator[](const unsigned int& index) const
{
	// using position due to the fact that exceptions are already handled in it
	Position indexPos = Position(index % BOARD_SIZE, index / BOARD_SIZE);
	return (*this)[indexPos];
}

Color Board::currentPlayer(void) const
{
	return this->_currentPlayer;
}
Board::Board(const std::string& boardMap)
{
	unsigned int i = 0;  // loop variable
	Color currentColor = WHITE;
	this->_currentPlayer = BLACK;
	this->playerKings[WHITE] = nullptr;
	this->playerKings[BLACK] = nullptr;
	if (boardMap.length() != BOARD_SIZE * BOARD_SIZE + 1)
	{
		throw "invalid initial board map length";
	}
	for (unsigned int i = 0; i < BOARD_SIZE * BOARD_SIZE; i++)
	{
		if (boardMap[i] == EMPTY_BOARD_POSITION_SYMBOL)
		{
			(*this)[i] = nullptr;
		}
		else if (!std::isalpha(boardMap[i]))
		{
			throw "Invalid Board Char Given to Board Ctor";
		}
		else
		{
			currentColor = (std::isupper(boardMap[i])) ? (BLACK) : (WHITE);
			switch (std::tolower(boardMap[i]))
			{
			case KING_SYMBOL:
				if (this->playerKings[currentColor] != nullptr)
				{
					throw "There can only be 1 king of each color";
				}
				(*this)[i] = new King(Position(i), currentColor, this);
				this->playerKings[currentColor] = (King*)(*this)[i];
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
				throw "Unkown Solider Char Given to Board Ctor";
			}
		}
	}
	if (this->playerKings[WHITE] == nullptr || this->playerKings[BLACK] == nullptr)
	{
		throw "Missing Kings In Board Map Given to Board Ctor";
	}
}

MoveCode Board::move(const Position& origin, const Position& dest)
{
	MoveCode resultantMoveCode = VALID_MOVE;
	resultantMoveCode = this->canPieceMove(origin, dest);
	if (resultantMoveCode == VALID_MOVE || resultantMoveCode == CAUSES_CHECK)
	{
		this->deleteSolider(dest);
		(*this)[dest] = (*this)[origin];
		(*this)[origin] = nullptr;
		(*this)[dest]->setPosition(dest);
		this->_currentPlayer = (this->currentPlayer() == WHITE) ? (BLACK) : (WHITE);
	}
	return resultantMoveCode;
}

MoveCode Board::canPieceMove(const Position& origin, const Position& dest)
{
	Solider* pDestSoldier = nullptr;
	MoveCode resultantMoveCode = VALID_MOVE;
	if ((*this)[origin] == nullptr || (int)this->currentPlayer() != (*this)[origin]->color())
	{
		resultantMoveCode = ORIGIN_NOT_OWNED;
	}
	else if ((*this)[dest] != nullptr && this->currentPlayer() == (*this)[dest]->color())
	{
		resultantMoveCode = DEST_OWNED;
	}
	else if (origin == dest)
	{
		resultantMoveCode = ORIGIN_AND_DEST_EQUALITY;
	}
	else if (!(*this)[origin]->canMove(dest))
	{
		resultantMoveCode = DEFIES_SOLLIDER_MOVE_PATTERN;
	}
	else
	{
		pDestSoldier = this->moveWithoutDeletion(origin, dest);
		if (this->playerKings[this->currentPlayer()]->isAlerted())
		{
			resultantMoveCode = IMPLIES_SELF_CHECK;
		}
		else if (this->playerKings[((this->currentPlayer() == WHITE) ? (BLACK) : (WHITE))]->isAlerted())
		{
			resultantMoveCode = CAUSES_CHECK;
		}
		else
		{
			resultantMoveCode = VALID_MOVE;
		}
		(*this)[origin] = (*this)[dest];
		(*this)[dest] = pDestSoldier;
	}
	return resultantMoveCode;
}

Solider* Board::moveWithoutDeletion(const Position& origin, const Position& dest)
{
	Solider* pDestSoldier = nullptr;
	pDestSoldier = (*this)[dest];
	(*this)[dest] = (*this)[origin];
	(*this)[origin] = nullptr;
	return pDestSoldier;
}

Board::~Board()
{
	for (int i = 0; i < BOARD_SIZE * BOARD_SIZE; i++)
	{
		Solider* solider = (*this)[i];
		if (solider == nullptr)
		{
			continue;
		}
		else
		{
			delete solider;
		}
	}
}
