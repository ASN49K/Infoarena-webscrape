#include <bits/stdc++.h>

using namespace std;

ifstream fin("euclid2.in");
ofstream fout("euclid2.out");

#define cin fin
#define cout fout

long long n,a,b;

long long cmmdc(long long a ,long long b)
{
    if(a>b)  swap(b,a);
    while(a!=b && b%a!=0)
    {
        b=b%a;
        swap(b,a);
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

