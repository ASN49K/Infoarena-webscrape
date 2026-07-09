
#include <cstdio>
#include <fstream>
#include <vector>
#include <algorithm>

using namespace std;

const int N=1025;

#define pb push_back

int A[N],B[N],bst[N][N],n,m;
vector<int> sol;

void read ()
{

	ifstream in ("cmlsc.in");
	
	in>>n>>m;
	
	for(int i=1;i<=n;++i)
		in>>A[i];
	
	for(int i=1;i<=n;++i)
		in>>B[i];

}

void solve ()
{
	
	for(int i=1;i<=n;++i)
		for(int j=1;j<=m;++j)
			if(A[i]==B[j])
				bst[i][j]=bst[i-1][j-1]+1;
			else
				bst[i][j]=max(bst[i][j-1],bst[i-1][j]);

	for(int i=n,j=m;i&&j;)
		if(A[i]==B[j])
		{
			sol.pb(A[i]);
			--i;
			--j;
		}
		else
			if(bst[i-1][j]<bst[i][j-1])
				--j;
			else
				--i;

}

void out ()
{
	
	freopen ("cmlsc.out","w",stdout);
	printf("%d\n",sol.size());
	for(vector<int>::iterator it=sol.end()-1;it>=sol.begin();--it)
		printf("%d ",*it);
	
}

int main ()
{

	read ();
	solve ();
	out ();

	return 0;
}
