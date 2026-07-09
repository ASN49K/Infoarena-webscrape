#include <fstream>
using namespace std;
//c[i][j] primele i elem a lui A si primele j ale lui B
int n,m,i,j,a[1025],b[1025];
ifstream f("cmlsc.in");
ofstream g("cmlsc.out");
int c[1025][1025];
void tipar(int i,int j)
{
    if(i>=1&&j>=1)
    {
        if(a[i]!=b[j])
        {
            if(c[i][j-1]>c[i-1][j]) tipar(i,j-1);
            else tipar(i-1,j);
        }
        else {tipar(i-1,j-1);g<<a[i]<<" ";}
    }
}
int main()
{
	f>>n>>m;
	c[0][0]=0;
	for(i=1;i<=n;i++)
        f>>a[i];
    for(j=1;j<=m;j++)
        f>>b[j];
    for(i=1;i<=n;i++)
        for(j=1;j<=m;j++)
        if(a[i]==b[j]) c[i][j]=c[i-1][j-1]+1;
    else c[i][j]=max(c[i-1][j],c[i][j-1]);
    g<<c[n][m]<<endl;
    tipar(n,m);
    return 0;
}
