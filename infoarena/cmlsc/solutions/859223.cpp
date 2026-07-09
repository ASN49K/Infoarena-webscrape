#include<fstream>
using namespace std;
ifstream in("cmlsc.in");
ofstream out("cmlsc.out");
int a[1025][1025], v[1025], k[1025], subsir[1025];
int main()
{
	long n, m, x, i, j;
    in >> n >> m;
    for(i=1;i<=n;i++)
        in >> v[i];
    for(i=1;i<=m;i++)
        in >> k[i];
    for(i=1;i<=n;i++)
        for(j=1;j<=m;j++) {
            if(v[i]==k[j])
                a[i][j]=a[i-1][j-1]+1;
            else
                a[i][j]=max(a[i][j-1],a[i-1][j]);
        }
    i=n;
    j=m;
    while(a[i][j])
	{
        while(a[i][j]==a[i-1][j])
            i--;
            while(a[i][j]==a[i][j-1])
                j--;
        x++;
        subsir[x]=v[i];
        i--;
        j--;
        }
        out << a[n][m] << "\n";
        for(i=x;i>=1;i--)
        out << subsir[i] << " ";
		in.close();
		out.close();
        return 0;
}