#include <iostream>
#include <fstream>
#include <algorithm>
#define len(x) x&(-x)
#define inf 2147000000
using namespace std;
ifstream f("scmax.in");
ofstream g("scmax.out");

struct vec
{ int x,pos; }v[100005];
int n,a[100005],aib[100005],dp[100005],eg[100005],lim=100005,mx,mxp,sol[100005],nsol,last;

void Update(int x,int val)
{ int i;
  for(i=x;i<=lim;i+=len(i))
   aib[i]=max(aib[i],val);
}

int Query(int x)
{ int i,res=0;
   for(i=x;i>0;i-=len(i))
    res=max(res,aib[i]);

  return res;
}

bool comp(vec a, vec b)
{ return a.x<b.x; }

int main()
{ int i,ord=0;
    f>>n;
    for(i=1;i<=n;i++)
      {f>>a[i];
       v[i].x=a[i]; v[i].pos=i;
      }

      sort(v+1,v+n+1,comp);

    for(i=1;i<=n;i++)
    { if (i==1 || v[i].x>v[i-1].x) ord++;
      a[v[i].pos]=ord;
      eg[ord]=v[i].x;
    }


    for(i=1;i<=n;i++)
    { dp[i]=Query(a[i]-1)+1;
      Update(a[i],dp[i]);
      if (dp[i]>mx) mx=dp[i];

    }

    last=inf;
    for(i=n;i>=1;i--)
    {
      if (dp[i]==mx && a[i]<last)
      { nsol++; sol[nsol]=a[i];
        mx--; if (!mx) break;
      }
    }

     g<<nsol<<"\n";
    for(i=nsol;i>=1;i--)
     g<<eg[sol[i]]<<" ";

    return 0;
}
