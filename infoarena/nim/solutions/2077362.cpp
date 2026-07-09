#include<iostream>
#include<fstream>
#include<cmath>
#include<algorithm>
#include<bitset>
#define DN 10005
using namespace std;
ifstream fin("nim.in");
ofstream fout("nim.out");
int t,n,a,b;
int main()
{
    fin>>t;
    for(int h=1;h<=t;h++)
    {
        fin>>n;
        a=0;
        for(int i=1;i<=n;i++)
        {
            fin>>b;
            a^=b;
        }
        if(a>0)
            fout<<"DA";
        else
            fout<<"NU";
        fout<<'\n';
    }
}
