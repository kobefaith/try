//main.cpp
#include"ChessBoard.h"
#include"Player.h"
 
int main()
{
    ChessBoard board;   
    Player playA("aaa",'*');//玩家aaa的棋子形状是'*'
    playA.attachToBoard(&board);
    Player playB("bbb",'#');//玩家bbb的棋子形状是'#'
    playB.attachToBoard(&board);    
    board.show();
    while(1)
    {
        playA.setChess();//玩家A放下一个棋子
        if(playA.isWin())
        {   cout<<"Winer!"; break;}       
        board.show();
 
        playB.setChess();//玩家B放下一个棋子
        if(playB.isWin())
        {   cout<<"Winer!"; break;}   
        board.show();
    }
    return 1;
}