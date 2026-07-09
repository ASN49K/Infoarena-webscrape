#include <bits/stdc++.h>

using namespace std;

/// code {

const string FILENAME="euclid2";
#define read(FILENAME) freopen((FILENAME + ".in").c_str(), "r", stdin)
#define write(FILENAME) freopen((FILENAME + ".out").c_str(), "w", stdout)
#define files(FILENAME) read(FILENAME), write(FILENAME)

typedef long long ll;
typedef long double ld;

#define mp make_pair
#define pb push_back
#define ff first
#define ss second
#define all v.begin(),v.end()
#define y1 y228
#define left left228
#define right right228
#define next next228
#define rank rank228
#define prev prev228

const int N=0;
const int MOD=1000000007;

inline int add(int a,int b)
{
    a+=b;
    if(a>=MOD) a-=MOD;
    if(a<0) a+=MOD;
    return a;
}

inline int mul(int a,int b)
{
    return a*(long long)b%MOD;
}

int gcd(int a,int b)
{
    if(b==0) return a;
    return gcd(b,a%b);
}

inline int expow(int a,int b)
{
    int ans=1;
    while(b)
    {
        if(b&1) ans=mul(ans,a);
        a=mul(a,a);
        b>>=1;
    }
    return ans;
}

const int ROFLAN=1000000000;

class big
{
    private :
        int cif[20];
        short int len;
    public :
        void operator = (const int &other)
        {
            int aux=other;
            len=0;
            while(aux)
            {
                cif[++len]=aux%ROFLAN;
                aux/=ROFLAN;
            }
        }
        void operator += (const big &other)
        {
            big ans;
            int i=1,rezid=0,sum;
            for(i=1;i<=len || i<=other.len || rezid>0;i++)
            {
                sum=rezid;
                if(i<=len)
                    sum+=cif[i];
                if(i<=other.len)
                    sum+=other.cif[i];
                ans.cif[i]=sum%ROFLAN;
                rezid=sum/ROFLAN;
            }
            ans.len=i-1;
            len=ans.len;
            for(int i=1;i<=len;i++)
                cif[i]=ans.cif[i];
        }
        void afis()
        {
            printf("%d",cif[len]);
            for(int j=len-1;j>=1;j--)
            {
                printf("%.9d",cif[j]);
            }
            printf("\n");
        }
};

class disjoint_set
{
    private :
        int h[N],t[N];
    public :
        inline void build(int n)
        {
            for(int i=1;i<=n;i++)
                h[i]=1, t[i]=1;
        }
        inline int dad(int a)
        {
            if(a==t[a])
                return a;
            t[a]=dad(t[a]);
            return t[a];
        }
        inline void unite(int a,int b)
        {
            a=dad(a);
            b=dad(b);
            if(a==b) return;
            if(h[a]<h[b])
                t[a]=b;
            else
            {
                t[b]=a;
                if(h[a]==h[b])
                    h[b]++;
            }
        }
};

/// code }

int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    files(FILENAME);
    int t; cin>>t;
    while(t--)
    {
        int a,b; cin>>a>>b;
        cout<<gcd(a,b)<<"\n";
    }
    return 0;
}
