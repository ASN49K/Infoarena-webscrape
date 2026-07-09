#include<bits/stdc++.h>
using namespace std;

ifstream fin("euclid2.in");
ofstream fout("euclid2.out");

int a,b,t;

int al(int a,int b)
{
    if(a==0||b==0)
        if(a>b)
        return a;
    else
        return b;
    int r;
    r=a%b;
    while(r!=0)
    {
        a=b;
        b=r;
        r=a%b;
    }
    return b;
}

void returnare()
{
    fout<<al(a,b)<<'\n';
}

int main()
{
    fin>>t;
    for(int i=1;i<=t;i++)
    {
        fin>>a>>b;
        returnare();
    }
    return 0;
}
