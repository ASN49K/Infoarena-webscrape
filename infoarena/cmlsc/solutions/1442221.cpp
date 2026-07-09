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
#define nleft (n<<1)
#define nright (nleft+1)

#include<vector>

using namespace std;
#include<fstream>
ifstream fin("cmlsc.in");
ofstream fout("cmlsc.out");

#define NMAX 1030

typedef long long LL;
typedef pair<int, int> PII;
typedef long double K;
typedef pair<K, K> PKK;
typedef vector<int> VI;

const int dx[] = {0,0,-1,1}; //1,1,-1,1};
const int dy[] = {-1,1,0,0}; //1,-1,1,-1};

int x[NMAX], y[NMAX];

int dp[NMAX][NMAX];
int sol[NMAX];

int n,m,i,j,r;

int main()
{
	fin>>n>>m;
	
	REP(i,n)
		fin>>x[i];
	REP(i,m)
		fin>>y[i];
	REP(i,n){
		REP(j,m)
		{
			if(x[i] == y[j])
				dp[i][j]=dp[i-1][j-1]+1;
			else
				dp[i][j]=MAX(dp[i-1][j], dp[i][j-1]);
			//fout<<dp[i][j]<<" ";
		}
		//fout<<"\n";
	}
	fout<<dp[n-1][m-1]<<"\n";
	
	// backingtrack
	i=n-1;
	j=m-1;
	r=dp[n-1][m-1]-1;
	while(i!=-1 && j!=-1)
	{
		if(x[i]==y[j]) sol[r]=x[i], i--, j--, r--;
		else
			if(dp[i-1][j]>dp[i][j-1])
				i--;
			else
				j--;
	}
	
	REP(i,dp[n-1][m-1])
		fout<<sol[i]<<" ";

	return 0;
}




















