#include <bits/stdc++.h>
using namespace std;
ifstream fin("euclid2.in");
ofstream fout("euclid2.out");
int T;
long long a,b;
int GCD(int a,int b)
{
    if(b==0) return a;
     return GCD(b,a%b);
}
int main()
{   fin>>T;
    for(int i=1;i<=T;i++)
    {
        fin>>a>>b;
        fout<<GCD(a,b)<<endl;
    }
    return 0;
}
