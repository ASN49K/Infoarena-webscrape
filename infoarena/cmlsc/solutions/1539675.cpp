#include<fstream>
#include<cmath>

using namespace std;

ifstream fin("cmlsc.in");
ofstream fout("cmlsc.out");

int m,n,a[1025],b[1025],i,j,c[1025][1025];

void afis (int i, int j, int k) {
    if (k<=c[m][n]) {
        if (i<=m)
            if (j<=n) {
                if (a[i]==b[j]) {
                    fout<<a[i]<<" ";
                    afis(i, j+1, k+1);
                }
                else afis (i,j+1,k);
            }
        else afis (i+1,1,k);
    }
}

int main()
{
	fin>>m>>n;
	for(i=1;i<=m;++i)fin>>a[i];
	for(i=1;i<=n;++i)fin>>b[i];
	for(i=1;i<=m;++i)
       for(j=1;j<=n;++j)
	   if(a[i]==b[j])c[i][j]=c[i-1][j-1]+1;
	   else c[i][j]=max(c[i-1][j],c[i][j-1]);
	fout<<c[m][n]<<'\n';
	afis(1,1,1);
	return 0;
}

