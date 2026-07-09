#include <iostream>
#include <fstream>
using namespace std;

ifstream fin("euclid2.in");
ofstream fout("euclid2.out");

int main()
{
	long long a,b,r,x;
    fin>>x;
    for(int i=1;i<=x;i++)
    {
        fin>>a>>b;
    if(a==0&&b==0)
        fout<<"-1";
    else
    {
        while(b!=0)
        {
        r=a%b;
        a=b;
        b=r;
        }
        fout<<a<<endl;
    }
    }
	return 0;
}

