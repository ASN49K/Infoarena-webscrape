#include <bits/stdc++.h>

using namespace std;
ifstream fin("euclid2.in");
ofstream fout("euclid2.out");
int n;
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
    fin>>n;
    for(int i=1;i<=n;i++)
    {
        int x,y;
        fin>>x>>y;
        int aux=Cmmdc(x,y);
        fout<<aux<<"\n";
    }
    fin.close();
    fout.close();
    return 0;
}
