#include <bits/stdc++.h>
using namespace std;

ifstream fin("euclid2.in");
ofstream fout("euclid2.out");


int cmmdc(int a,int b)
{
    int c;
    while(b)
    {
        c=a%b;
        a=b;
        b=c;
    }
    return a;
}
int main()
{

    int n,x,y;
    fin>>n;
    for(int i=1;i<=n;i++)
    {
        fin>>x>>y;
        fout<<cmmdc(x,y)<<"\n";
    }








    return 0;
}
