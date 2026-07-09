#include <bits/stdc++.h>
#define nmax 50005
#define pb push_back
using namespace std;
ifstream f("euclid2.in");
ofstream g("euclid2.out");
int tt,t,i,n,m,r,verifica[nmax],a,b,k,d[nmax],x,y,c,cost1,cost,nod,vec,ok;
vector <pair<int,int> > v[nmax];
priority_queue <pair<int,int> > q;
int eu(int a,int b)
{
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
   f>>k;
   for(i=1;i<=k;i++)
   {
       f>>a>>b;
       g<<eu(a,b)<<'\n';
   }
    return 0;
}
