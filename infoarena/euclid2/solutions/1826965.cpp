#include <bits/stdc++.h>
using namespace std;
ifstream fin("euclid2.in");
ofstream fout("euclid2.out");
int teste;
inline int Cmmdc(int x,int y)
{
    int r;
    while(y)
    {
        r=x%y;
        x=y;
        y=r;
    }
    return x;
}
int main()
{
    int i,x,y,sol;
    fin>>teste;
    for(i=1;i<=teste;i++)
    {
        fin>>x>>y;
        sol=Cmmdc(x,y);
        fout<<sol<<"\n";
    }
    fin.close();
    fout.close();
    return 0;
}
