#include<bits/stdc++.h>

#pragma gcc optimize("O3")

#define all(s) s.begin(),s.end()
#define rc(x) return cout<<x<<endl,0
#define forn(i,n) for(int i=0;i<int(n);i++)
#define len(a) (int) (a).size()

#define pb push_back
#define mp make_pair
#define fr first
#define sc second

typedef long long ll;
typedef long double ld;

const int nmax=1025;
const int mod=998244353;
const ll inf=0x3f3f3f3f3f3f3f3f;

using namespace std;

int a[nmax], b[nmax], c[nmax][nmax], s[nmax];

int main()
{
  freopen("cmlsc.in","r",stdin);
  freopen("cmlsc.out","w",stdout);
  ios_base::sync_with_stdio(0); cin.tie(0);
  int n,m,k=0;
  int i=0,j=0;
  cin>>n>>m;
  for(int i=1;i<=n;i++) cin>>a[i];
  for(int i=1;i<=m;i++) cin>>b[i];
  for(int i=1;i<=n;i++)
   for(int j=1;j<=m;j++)
    if(a[i]==b[j])
     c[i][j]=c[i-1][j-1]+1; else
     c[i][j]=max(c[i-1][j],c[i][j-1]);
  i=n;j=m;
  while(i!=0)
  {
   if(a[i]==b[j])
    s[++k]=a[i],--i,--j; else
   if(c[i-1][j]<c[i][j-1])
    --j; else
    --i;
  }
    cout<<k<<"\n";
    for(int i=k;i>=1;i--) cout<<s[i]<<" ";
}
