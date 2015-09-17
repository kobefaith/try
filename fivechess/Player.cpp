//Player.cpp
#include"Player.h"
 
bool Player::isInChessBoard(int x,int y)
{
    if(x<ROW-1 && x>0 && y<COL-1 && y>0)
        return true;
    else
        return false;
}
/*�����Ǻ��Ĵ��룺����ж������Ƿ������ߡ�
������õ�������Ҵ˿̷��µ�����Ϊ���ģ������ַ�������ж��Ƿ��ڴ˷�������������
���ｫ�ĸ������ϵ��ж϶�����һ�𣬱������Ĵε��ò�ͬ�����ϵ��жϣ�
����for�����һ��switch��Щ��Ť���ɶ������ƺ�����*/
bool Player::isLine(int x,int y)
{
    for(int direc=HORIZON;direc<=LEFTTOPTORIGHTBOTTOM;direc++)//�ĸ�����Ȩ��֮��
    {
        int tempX,tempY,cnt=1;//cnt:�������е�ͬ��������ӵĸ������ﵽ�����÷�Ӯ
        for(int i=-4;i<=4;i++)
        {
            if(i==0)continue;//��ʱѭ��һ���൱��ʲô��û��
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
            if(cnt==5)//���ӳ���
                return true;
        }
    }return false;
}
 
void Player::setChess()
{   
    cout<<"���������"<<m_name<<"��x�����y���꣺"<<endl;
    cin>>m_x>>m_y;
    while(cin.fail() || m_ptBoard->m_cSquare[m_x][m_y]!=' ')//���벻��int�ͱ������ߴ�λ������������
    {
        cout<<"�����������ٴ��������"<<m_name<<"��x�����y���꣺"<<endl;
        cin.clear();    //���fail״̬  
        cin.sync();   //���������
        cin>>m_x>>m_y;
    }
    if(isInChessBoard(m_x,m_y))
        m_ptBoard->m_cSquare[m_x][m_y]=m_chessType;  
}
 
bool Player::isWin()
{   
    return isLine(m_x,m_y)?true:false;
}
