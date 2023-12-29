#pragma once
#include <iostream>
#include "LinkList.h"
using namespace std;
const int N = 9;
class Game
{
public:
	int arr[N][N];
	int board[N][N];
	Game();
	bool isValid( int, int, int);
	void generateSudoku( int);
	void printSudoku();
};

