#include <bits/stdc++.h>

using namespace std;
ifstream fin("euclid2.in");
ofstream fout("euclid2.out");
int n;
int x,y;
void CMMDC()
{
    if(x>y)swap(x,y);
    while(x!=0)
    {
        int r=y%x;
        y=x;
        x=r;
    }
   fout<<y<<'\n';
}
int main()
{
    fin>>n;
    while(n)
    {
        --n;
        fin>>x>>y;
        CMMDC();
    }
    return 0;
}
