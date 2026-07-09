#include <bits/stdc++.h>
#define Dim 10009
using namespace std;
ifstream f("nim.in");
ofstream g("nim.out");
int T,N,sum,a;

int main()
{
    f>>T;
    for(int t=1;t<=T;t++)
    {
       f>>N;
       sum=0;
       for(int i=1;i<=N;i++)
       {
           f>>a;
           sum^=a;
       }
       if(sum) g<<"DA"<<'\n';
       else g<<"NU"<<'\n';
    }
    return 0;
}
