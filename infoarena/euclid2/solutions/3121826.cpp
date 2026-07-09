#include <iostream>
#include <bits/stdc++.h>
using namespace std;
ifstream fin ("euclid2.in");
ofstream fout ("euclid2.out");
int main()
{int T,i;
long long a,b;
fin>>T;
for(i=1;i<=T;i++)
{
    fin>>a>>b;
    while(b!=0)
    {
        int r=a%b;
        a=b;
        b=r;
    }
    fout<<a<<'\n';
}
    return 0;
}
