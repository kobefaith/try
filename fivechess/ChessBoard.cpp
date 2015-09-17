//ChessBoard.cpp
#include"ChessBoard.h"
 
ChessBoard::ChessBoard()    
{   
    for(int i=1;i<ROW-1;i++)
        for(int j=1;j<COL-1;j++)
            m_cSquare[i][j]=' ';
    for(int j=0;j<COL;j++)
        m_cSquare[0][j]=m_cSquare[ROW-1][j]='-';
    for(int i=1;i<ROW;i++)
        m_cSquare[i][0]=m_cSquare[i][COL-1]='|';    
}
 
void ChessBoard::show()
{
    system("cls");  
    for(int i=0;i<ROW;i++)
    {   for(int j=0;j<COL;j++)
            cout<<m_cSquare[i][j]<<' ';//����ġ� <<' ' ������Ҫ����������ʹ��Ļ��ROW*COL���Ϊ����
        cout<<endl;
    }
}