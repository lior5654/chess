#include "Board.h"

Board::Board() {};

Solider* &Board::operator[](const Position& index)
{
	// using position due to the fact that exceptions are already handled in it
	return this->_map[index.row()][index.column()];
}
Solider* Board::operator[](const Position& index) const
{
	// using position due to the fact that exceptions are already handled in it
	return this->_map[index.row()][index.column()];
}
Solider*& Board::operator[](const unsigned int index)
{
	// using position due to the fact that exceptions are already handled in it
	Position indexPos = Position(index % BOARD_SIZE, index / BOARD_SIZE);
	return (*this)[indexPos];
}
Solider* Board::operator[](const unsigned int index) const
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
	this->playerKings[WHITE] = nullptr;
	this->playerKings[BLACK] = nullptr;
	if (boardMap.length() != BOARD_SIZE * BOARD_SIZE)
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
			currentColor = (std::isalpha(boardMap[i])) ? (WHITE) : (BLACK);
			switch (std::tolower(boardMap[i]))
			{
			case KING_SYMBOL:
				if (this->playerKings[currentColor] != nullptr)
				{
					throw "There can only be 1 king of each color";
				}
				(*this)[i] = new King(Position(i), currentColor);
				this->playerKings[currentColor] = (King*)(*this)[i];
				break;
			case ROOK_SYMBOL:
				(*this)[i] = new Rook(Position(i), currentColor);
				break;
			case KNIGHT_SYMBOL:
				(*this)[i] = new Knight(Position(i), currentColor);
				break;
			case BISHOP_SYMBOL:
				(*this)[i] = new Bishop(Position(i), currentColor);
				break;
			case QUEEN_SYMBOL:
				(*this)[i] = new Queen(Position(i), currentColor);
				break;
			case PAWN_SYMBOL:
				(*this)[i] = new Pawn(Position(i), currentColor);
				break;
			default:
				throw "Unkown Solider Char Given to Board Ctor";
			}
			if (this->playerKings[WHITE] == nullptr || this->playerKings[BLACK] == nullptr)
			{
				throw "Missing Kings In Board Map Given to Board Ctor";
			}
		}
	}
}

MoveCode Board::move(const Position& origin, const Position& dest)
{
	MoveCode resultantMoveCode = VALID_MOVE;
	resultantMoveCode = this->canPieceMove(origin, dest);
	if (resultantMoveCode == VALID_MOVE)
	{
		this->deleteSolider(dest);
		(*this)[dest] = (*this)[origin];
		(*this)[origin] = nullptr;
	}
	return resultantMoveCode;
}

MoveCode Board::canPieceMove(const Position& origin, const Position& dest)
{
	if ((*this)[origin]->position() == dest)
	{
		return ORIGIN_AND_DEST_EQUALITY;
	}
	else if (this->currentPlayer() != (*this)[origin]->color)
	{
		return ORIGIN_NOT_OWNED;
	}
	else if (this->currentPlayer() != (*this)[dest]->color)
	{
		return DEST_OWNED;
	}
	else if (origin == dest)
	{
		return ORIGIN_AND_DEST_EQUALITY;
	}
	else if (!(*this)[origin]->canMove(dest, (*this)))
	{
		return DEFIES_SOLLIDER_MOVE_PATTERN;
	}
	// TODO: add check & checkmate check
	return VALID_MOVE;
}