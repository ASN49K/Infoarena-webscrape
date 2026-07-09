#include <bits/stdc++.h>
using namespace std;
ifstream fin("euclid2.in");
ofstream fout("euclid2.out");
int teste,a,b;
inline int  Cmmdc(int x,int y)
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
void Rezolvare()
{
    int i,x;
    fin>>teste;
    for(i=1;i<=teste;i++)
    {
        fin>>a>>b;
        x=Cmmdc(a,b);
        fout<<x<<"\n";
    }
}
int main()
{
    Rezolvare();
    fin.close();
    fout.close();
    return 0;
}
