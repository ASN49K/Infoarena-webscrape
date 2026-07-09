#include <bits/stdc++.h>

using namespace std;

ifstream fin("euclid2.in");
ofstream fout("euclid2.out");

#define cin fin
#define cout fout

long long n,a,b;

long long cmmdc(long long a ,long long b)
{
    while(a!=b)
    {
        if(a<b) b-=a;
        else a-=b;
    }
    return a;
}

int main()
{
   cin>>n;
   for(int i=1;i<=n;i++)
   {
       cin>>a>>b;
       cout<< cmmdc(a,b)<<"\n";
   }
   return 0;
}

