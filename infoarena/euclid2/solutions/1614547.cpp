#include <iostream>
#include <fstream>

using namespace std;

ifstream in ("euclid2.in");
ofstream out ("euclid2.out");

int T,arr[100000][2];
int getCMMDC(int a,int b)
{
	int t;
	if(a<b)
	{
		t=a;
		a=b;
		b=t;
	}
	while (b!=0)
	{
		t=a/b;
		a-=b*t;
		t=a;
		a=b;
		b=t;
	}
	return a;
}
void Read()
{
	in>>T;
	for(int i=1;i<=T;i++)
		in>>arr[i][0]>>arr[i][1];
}

int main()
{
	Read();
	for(int i=1;i<=T;i++)
		out<<getCMMDC(arr[i][0],arr[i][1])<<endl;
	return 0;
}