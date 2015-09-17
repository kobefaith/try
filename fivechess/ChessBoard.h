//ChessBoard.h
#pragma once
#define ROW 15
#define COL 15
#include<iostream>
using namespace std;
 
class ChessBoard//∆Â≈Ã¿‡
{
private:
	ChessBoard();	
	ChessBoard(const ChessBoard &s){}
	ChessBoard& operator=(const ChessBoard &s){}
public:
    char m_cSquare[ROW][COL];
	
public:
	static ChessBoard* GetInstance()
	{
		static ChessBoard instance;
		return &instance;
	}
    void show();    
};