#pragma once

// INCLUDES
#include <string>
#include <map>
#include "Solider.h"
#include "Position.h"
#include "enums.h"
#include "King.h"
#include "Bishop.h"
#include "Knight.h"
#include "Pawn.h"
#include "Queen.h"
#include "Rook.h"
// DEFINE CONSTANTS
#define EMPTY_BOARD_POSITION_SYMBOL '#'
#define KING_SYMBOL 'k'
#define QUEEN_SYMBOL 'q'
#define ROOK_SYMBOL 'r'
#define KNIGHT_SYMBOL 'n'
#define BISHOP_SYMBOL 'b'
#define PAWN_SYMBOL 'p'


// maybe could replace map to a vector and use .at instead of two different indexing methods seperated by const
class Board
{
public:
	Board();
	Board(const std::string& boardMap);
	MoveCode move(const Position& origin, const Position& dest);
	~Board();
	void deleteSolider(const Position& origin);
	Solider*& operator[](const unsigned int index);
	Solider* operator[](const unsigned int index) const;
	Solider*& operator[](const Position& index);
	Solider* operator[](const Position& index) const;
	Color currentPlayer(void) const;
	MoveCode canPieceMove(const Position& origin, const Position& dest);
private:
	Solider* _map[BOARD_SIZE][BOARD_SIZE];
	Color _currentPlayer;
	std::map<Color, King*> playerKings;
};

