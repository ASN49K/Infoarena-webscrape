#include<fstream>
#define maxim(a, b) ((a > b) ? a : b)
using namespace std;
int m,n,a[1024],b[1024],d[1024][1024],sir[1024],bst;
int main()
{
    int i, j;
    ifstream f("cmlsc.in");
    ofstream g("cmlsc.out");
    f>>m>>n;
    for(i=1;i<=m;i++)
        f>>a[i];
    for(i=1;i<=n;i++)
        f>>b[i];
    for(i=1;i<=m;i++)
        for(j=1;j<=n;j++)
            if(a[i]==b[j])
                d[i][j]=1+d[i-1][j-1];
            else
                d[i][j]=maxim(d[i-1][j],d[i][j-1]);
    i=m;
	j=n;
	while(i)
        if (a[i]==b[j])
		{
            sir[++bst]=a[i];
			--i;
			--j;
		}
        else 
			if (d[i-1][j]<d[i][j-1])
				--j;
			else
				--i;
	g<<bst<<"\n";
    for (i=bst;i>=1;--i)
       g<<sir[i]<<" ";
    return 0;
}


