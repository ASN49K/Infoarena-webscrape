#import<fstream>
#import<vector>
#import<bitset>
#import<cmath>
#import<queue>
using namespace std;
int a[100001][19];
int lg2[100001];
int gcd(int a,int b)
{
    if(b==0)
    {
        return a;
    }
    return gcd(b,a%b);
}
ifstream cin("gcdseq.in");
ofstream cout("gcdseq.out");
main()
{
    int n;
    cin>>n;
    for(int i=1;i<=n;i++)
    {
        cin>>a[i][0];
    }
    for(int j=1;(1<<j)<=n;j++)
    {
        int l=(1<<(j-1));
        for(int i=1;i+l<=n;i++)
        {
            a[i][j]=max(a[i][j-1],a[i+l][j-1]);
        }
    }
    for(int i=2;i<=n;i++)
    {
        lg2[i]=lg2[i/2]+1;
    }
    long long s=0;
    for(int k=1;k<=n;k++)
    {
        for(int i=k;i<=n;i++)
        {
            int x=i-k+1;
            int h=max(a[x][lg2[k]],a[i-(1<<lg2[k])+1][lg2[k]]);
            s+=(long long)gcd(k,h);
        }
    }
    cout<<s;
}
