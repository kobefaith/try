//ChessBoard.h
#pragma once
#define ROW 15
#define COL 15
#include<iostream>
using namespace std;
 
class ChessBoard//������
{
public:
    char m_cSquare[ROW][COL];   
public:
    ChessBoard();
    void show();    
};