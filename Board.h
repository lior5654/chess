#pragma once
#include <vector>
#include <string>

#include "Solider.h"
#include "Position.h"

using std::vector;
using std::string;

class Board
{
public:
	Board(const string boardMap);
	void move(const Position origin, const Position dest);
	~Board();
	void delete_solider(unsigned int index);
private:
	vector<Solider*> _map;
};

