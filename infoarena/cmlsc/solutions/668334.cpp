#include<fstream>
using namespace std;

ifstream fin("cmlsc.in");
ofstream fout("cmlsc.out");

int v1[1025],v2[1025],sol[1025],mat[1025][1025],nr,i,n,m,j;
int main()
{   fin >> n >> m;
    for (i=1;i<=n;++i)
		fin >> v1[i];
	for(i=1;i<=m;++i)
		fin >> v2[i];
	for(i=1;i<=n;++i)
		for(j=1;j<=m;++j)
			if (v1[i] == v2[j])
				mat[i][j] = 1 + mat[i-1][j-1];
			else
				mat[i][j] = max(mat[i-1][j],mat[i][j-1]);
	--i;
	--j;
	while (i)
		if (v1[i] == v2[j])
		{	sol[++nr] = v1[i];
		    --i;
			--j;
		}
		else 
			if (mat[i-1][j] < mat[i][j-1])
				--j;
            else
			    --i;
	fout << nr << '\n';
    for (i=1;i<=nr;++i)
		fout << sol[i] << " ";
	return 0;
}
