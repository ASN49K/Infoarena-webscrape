#include<cstdio>
#include<vector>
using namespace std;
#define NM 1025
class cmlscl
{
private:
	int a[NM][NM];
public:
	//cmlscl(int &, int &);
	void read(int[] ,int[]);
	int solve(int[], int[]);
	int maxim (int x,int y) {return (x<y)? (y):(x);}
	void reset(int , int );
	void remake(int ,int[], int[]);
};
void cmlscl::reset(int N, int M)
{
	for (int i=0;i<=N; ++i)
		for (int j=0; j<=M; ++j)
			a[i][j]=0;
}
void cmlscl::read(int s1[],int s2[])
{
	scanf("%d%d",&s1[0],&s2[0]);
	for (int i=1; i<=s1[0]; ++i) 
		scanf("%d",&s1[i]);
	for (int i=1; i<=s2[0]; ++i) 
		scanf("%d",&s2[i]);
	this->reset(s1[0],s2[0]);
}
void cmlscl::remake(int lung,int s1[],int s2[])
{
	int x=s1[0],y=s2[0];
	#define pb push_back
	vector<int>rez;
	while (x && y)
	{
		if (s1[x]==s2[y])
		{
			rez.pb(s1[x]);
			--x;
			--y;
			continue;
		}
		if (a[x-1][y]<a[x][y-1])
			--y;
		else
			--x;
	}
	x=rez.size();
	printf("%d\n",lung);
	for (y=lung-1; y>=0; --y)
		printf("%d ",rez[y]);
}
int cmlscl::solve(int s1[],int s2[])
{
	for (int i=1; i<=s1[0]; ++i)
		for (int j=1; j<=s2[0]; ++j)
		{
			if (s1[i]==s2[j])
			{
				a[i][j]=1+a[i-1][j-1];
				continue;
			}
			a[i][j]=this->maxim(a[i][j-1],a[i-1][j]);
		}
	return a[s1[0]][s2[0]];
}
int main()
{
	freopen("cmlscl.in","r",stdin);
	freopen("cmlscl.out","w",stdout);
	cmlscl *ab=new cmlscl;
	int s[2][NM];
	ab->read(s[0],s[1]);
	ab->remake(ab->solve(s[0],s[1]),s[0],s[1]);
	return 0;
}
