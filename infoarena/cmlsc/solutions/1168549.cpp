#include<fstream>
using namespace std;
ifstream fin("cmlsc.in");
ofstream fout("cmlsc.out");
int x[1025],y[1025],c[1025][1025],sol[1025],m,n,k;
int main()
{
    int i,j;
    fin>>m>>n;

    for(i=1;i<=m;i++) fin>>x[i];

    for(i=1;i<=n;i++) fin>>y[i];

    for(i=1;i<=m;i++)
        for(j=1;j<=n;j++)
           if(x[i]==y[i]) c[i][j]=c[i-1][j-1]+1;
           else c[i][j]=max(c[i-1][j],c[i][j-1]);

    for (i=m,j=n; i>0;)
		if (x[i]==y[j])
			{
				k++;
				sol[k]=x[i];
				j--;
				i--;
			}
		else if (c[i][j-1]>c[i-1][j]) j--;
		else i--;

    fout<<k<<'\n';
    for(i=k;i>0;i--)
        fout<<sol[i]<<' ';
    fout.close();
    fin.close();
    return 0;
}