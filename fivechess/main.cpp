//main.cpp
#include"ChessBoard.h"
#include"Player.h"
 
int main()
{
    ChessBoard board;   
    Player playA("aaa",'*');//���aaa��������״��'*'
    playA.attachToBoard(&board);
    Player playB("bbb",'#');//���bbb��������״��'#'
    playB.attachToBoard(&board);    
    board.show();
    while(1)
    {
        playA.setChess();//���A����һ������
        if(playA.isWin())
        {   cout<<"Winer!"; break;}       
        board.show();
 
        playB.setChess();//���B����һ������
        if(playB.isWin())
        {   cout<<"Winer!"; break;}   
        board.show();
    }
    return 1;
}