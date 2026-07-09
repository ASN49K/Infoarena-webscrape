#include <iostream>
#include <bits/stdc++.h>
using namespace std;
ifstream fin ("euclid2.in");
ofstream fout ("euclid2.out");

vector<int> mp[2000000];


int euclid(int a, int b)
{
    if(a<b)
        swap(a,b);
    int r;
    while(b)
    {
        r=a%b;
        a=b;
        b=r;
    }
    return a;
}

int main()
{
    int n,m,i,j,k,t,q,nr,minim,maxim;
    fin>>n;
    while(n--)
    {
        fin>>i>>j;
        fout<<euclid(i,j)<<'\n';
    }
    return 0;
}
