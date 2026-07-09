#include<fstream>
#define Nmax 1025
using namespace std;
ifstream f("cmlsc.in");
ofstream g("cmlsc.out");
int n,mat[Nmax][Nmax],a[Nmax],b[Nmax],m,sol[Nmax];
int maxim(int a,int b)
{
    if(a>=b)
        return a;
    else
        return b;
}

void solve()
{

    for(int i=1; i<=m; i++)
    {
       	for(int j=1; j<=n; j++)
       	{
       	   if(a[i]==b[j])
       	       mat[i][j]=mat[i-1][j-1]+1;
           else
               mat[i][j]=maxim(mat[i-1][j], mat[i][j-1]);
        }
    }

    int k=0;
    int i=m;
    int j=n;
    while(i && j)
    {
        if(a[i]==b[j])
        {
            sol[++k]=a[i];
            i--;
            j--;
        }
        else
            if(mat[i][j-1]>mat[i-1][j])
                j--;
            else
                i--;
    }

    g<<k<<"\n";
    for(i=k; i>=1; i--)
	g<<sol[i]<<" ";


}
int main()
{
    int i;
    f>>m>>n;
    for(i=1;i<=m;i++)
        f>>a[i];
    for(i=1;i<=n;i++)
        f>>b[i];

    solve();

    f.close();
    g.close();
    return 0;
}
