#include<iostream>
#include<fstream>
using namespace std;
ifstream f("euclid2.in");
ofstream fout("euclid2.out");
int main()
{
    int T,a,b,c;
    f>>T;
    for(int i=1;i<=T;i++)
    {
        f>>a>>b;
        while(b!=0)
        {
            c=a%b;
            a=b;
            b=c;
        }
        fout<<a<<'\n';
    }
}
