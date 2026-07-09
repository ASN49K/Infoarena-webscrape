#define REP(a,b) for(int a=0; a<(b); ++a)
#define FWD(a,b,c) for(int a=(b); a<(c); ++a)
#define FWDS(a,b,c,d) for(int a=(b); a<(c); a+=d)
#define BCK(a,b,c) for(int a=(b); a>(c); --a)
#define ALL(a) (a).begin(), (a).end()
#define SIZE(a) ((int)(a).size())
#define VAR(x) #x ": " << x << " "
#define FILL(x,y) memset(x,y,sizeof(x))
#define MIN(a,b) (((a)<(b))?(a):(b))
#define MAX(a,b) (((a)>(b))?(a):(b))
#define x first
#define y second
#define st first
#define nd second
#define pb push_back
#define l(n) (n<<1)
#define r(n) ((n<<1)+1)
#define f(n) (n>>1)
#define lsb(a) (a&-a)

#include<vector>

using namespace std;
#include<fstream>
ifstream cin("euclid2.in");
ofstream cout("euclid2.out");

const int NMAX = 100000;
const int INF = 0x3f3f3f3f;
const int dx[] = {0,0,-1,1}; //1,1,-1,1};
const int dy[] = {-1,1,0,0}; //1,-1,1,-1};

typedef long long LL;
typedef pair<int, int> PII;
typedef long double K;
typedef pair<K, K> PKK;
typedef vector<int> VI;

int t,n,m,i,j;

int gcd(int a, int b)
{
	if(!b) return a;
	return gcd(b, a%b);
}

int main()
{
	cin>>t;
	while(t--)
	{
		cin>>n>>m;
		cout<<gcd(n,m)<<"\n";
	}
	return 0;
}

