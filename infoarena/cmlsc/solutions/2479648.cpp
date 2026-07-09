#include <bits/stdc++.h>
#define FAST ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
#define f(i,a,b) for(int i=a;i<b;i++)
#define fd(i,a,b) for(int i=a;i>b;i--)
#define ll long long
#define codechef FAST int t;cin>>t;while(t--)
const int MAX=200000000;
const int MOD=9973;
int sp[1005][1005],dp[1005];
using namespace std;
int v[1000005], d[1000005], cnt, p[1000005], vect[1000005];
int main()
{
    FAST
    ifstream in("cmlsc.in");
    ofstream out("cmlsc.out");
    int n;
    in>>n;
    for(int i=1; i<=n; ++i)
    {
        in>>v[i];
    }
    d[1]=1;
    for(int i=2; i<=n; ++i)
    {
        int maxim=0,prev;
        for(int j=i-1; j>=1; --j)
        {
            if(v[i]>v[j]){
                if(maxim<d[j]){
                    maxim=d[j];
                    prev=j;
                }
            }
        }
        d[i]=maxim+1;
        p[i]=prev;
    }
    int maxx=-1;
    int k=-1;
    for(int i=1; i<=n; ++i)
        if(d[i]>maxx){
            maxx=d[i];
            k=i;
        }
    out<<maxx<<"\n";
    for(int i=1;i<=maxx;i++){
        vect[i]=v[k];
        k=p[k];
    }
    for(int i=maxx; i>=1; --i)
        out<<vect[i]<<" ";
    return 0;
}
