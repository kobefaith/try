//Player.cpp
#include"Player.h"
 
bool Player::isInChessBoard(int x,int y)
{
    if(x<ROW-1 && x>0 && y<COL-1 && y>0)
        return true;
    else
        return false;
}
/*下面是核心代码：如何判断五子是否连成线。
这里采用的是以玩家此刻放下的棋子为中心，从四种方向逐个判断是否在此方向上连成了线
这里将四个方向上的判断都放在一起，避免了四次调用不同方向上的判断，
但在for里面放一个switch有些别扭，可读性上似乎不好*/
bool Player::isLine(int x,int y)
{
    for(int direc=HORIZON;direc<=LEFTTOPTORIGHTBOTTOM;direc++)//四个方向，权宜之计
    {
        int tempX,tempY,cnt=1;//cnt:连续排列的同种类的棋子的个数，达到五个则该方赢
        for(int i=-4;i<=4;i++)
        {
            if(i==0)continue;//此时循环一遍相当于什么都没做
            switch(direc)
            {
            case HORIZON:
                tempX=x;    tempY=y+i;      break;
            case VERTICAL:  
                tempX=x+i;  tempY=y;        break;
            case LEFTBOTTOMTORIGHTTOP:
                tempX=x-i;  tempY=y+i;      break;
            case LEFTTOPTORIGHTBOTTOM:
                tempX=x+i;  tempY=y+i;      break;
            }
            if(isInChessBoard(tempX,tempY) && m_ptBoard->m_cSquare[tempX][tempY]==m_chessType)
                cnt++;
            else
                cnt=0;
            if(cnt==5)//五子成线
                return true;
        }
    }return false;
}
 
void Player::setChess()
{   
    cout<<"请输入玩家"<<m_name<<"的x坐标和y坐标："<<endl;
    cin>>m_x>>m_y;
    while(cin.fail() || m_ptBoard->m_cSquare[m_x][m_y]!=' ')//输入不是int型变量或者此位置上已有棋子
    {
        cout<<"输入有误，请再次输入玩家"<<m_name<<"的x坐标和y坐标："<<endl;
        cin.clear();    //清除fail状态  
        cin.sync();   //清除缓冲区
        cin>>m_x>>m_y;
    }
    if(isInChessBoard(m_x,m_y))
        m_ptBoard->m_cSquare[m_x][m_y]=m_chessType;  
}
 
bool Player::isWin()
{   
    return isLine(m_x,m_y)?true:false;
}
