#include <fstream>
using namespace std;
#include <string.h>

int v[1024][1024],sir[1024],a[1024],b[1024];
int n,m,bst;

void matrice()
{
    int i,j;
    for(i=1;i<=m;i++)
        for(j=1;j<=n;j++)
        {
            if(a[i]==b[j])
                v[i][j]=v[i-1][j-1]+1;
            else if(v[i-1][j]>v[i][j-1]) v[i][j]=v[i-1][j];
                 else v[i][j]=v[i][j-1];
        }
}

void citire()
{
    int i,j;


	for (i = m, j = n; i;)
	
		if (a[i] == b[j])
		sir[++bst] = a[i], --i, --j;
		else if (v[i-1][j] < v[i][j-1])
			--j;
		else
			--i;
}

void scriere()
{
	int i;
	ifstream in("cmlsc.in");
	in>>m>>n;
	for(i=1;i<=m;i++)
		in>>a[i];
	for(i=1;i<=n;i++)
		in>>b[i];
	in.close();
}


int main()
{
	int i;
    ofstream out("cmlsc.out");
    scriere();
    matrice();
    citire();
	out<<bst<<'\n';
    for(i=bst;i>=1;i--)
    {
        out<<sir[i]<<" ";
    }
    out.close();
    return 0;


}
