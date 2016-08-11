#include<iostream>
using namespace std;

int main()
{
	int pre_year;
	int pre_mon;
	int pre_date;
	int next_year;
	int next_mon;
	int next_date;
	int result = 0;
	int diff_mon[12] = {31,28,31,30,31,30,31,31,30,31,30,31};
	cout<<"Please input the pre year:"<<endl;
	cin>>pre_year;
	cout<<"Please input the pre mon:"<<endl;
	cin>>pre_mon;
	cout<<"Please input the pre date:"<<endl;
	cin>>pre_date;
    cout<<"Please input the next year:"<<endl;
	cin>>next_year;
	cout<<"Please input the next mon:"<<endl;
	cin>>next_mon;
	cout<<"Please input the next date:"<<endl;
	cin>>next_date;
	for(int i = pre_mon-1; i < 12; i++){
          result += diff_mon[i];
	}
    result -= pre_date-1;

	for(int i = 0; i < next_mon-1; i++){
		result += diff_mon[i];
	}
	result += next_date;

	result += (next_year - pre_year-1)*365;
	cout<<pre_year<<"年 "<<pre_mon<<"月 "<<pre_date<<"日 和 "<<next_year<<"年 "<<next_mon<<"月 "<<next_date<<"日 之间差 "<<result<<" 天"<<endl;



}