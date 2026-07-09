#include <bits/stdc++.h>
#define N 10005
using namespace std;
ifstream fin("nim.in");
ofstream fout("nim.out");
int n,x,sol;
bool Nim()
{
    fin>>n;
    fin>>x;sol=x;
    for(int i=2;i<=n;i++)
        fin>>x,sol^=x;
    return sol;
}
int main()
{
    int q;
    fin>>q;
    while(q--)
        fout<<(Nim()?"DA":"NU")<<"\n";
    return 0;
}
