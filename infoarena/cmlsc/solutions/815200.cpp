
#include <fstream>
#define maxim(a,b) ((a>b) ? a : b)
int n, m, A[1024], B[1024], D[1024][1024], sir[1024], bst;
using namespace std;
int main()
{
	int i,j;
	ifstream in( "cmlsc.in" );
	ofstream out( "cmlsc.out" );
		in>>m>>n;
			for(i = 1;i <= m;i++) {
				in>>A[i];
			}
			for(i = 1;i <= n;i++) {
				in>>B[i];
			}
				for (i = 1;i <= m;i++) {
					for (j = 1;j <=n;j++) {
						if (A[i] == B [j])
							D[i][j] = D[i-1][j-1] + 1;
						else
							D[i][j] = maxim(D[i-1][j],D[i][j-1]);
					}
				}
				for (i = m, j = n; i ; ) {
					if (A[i] == B[j])
						sir[++bst] = A[i],--i,--j;
					else if (D[i-1][j] < D[i][j-1]) --j;
					else --i;
				}
			out<<bst<<endl;
				for (i = bst;i; i--)
					out<<sir[i]<<" ";
			return 0;
}


						