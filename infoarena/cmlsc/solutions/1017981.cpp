# include <iostream>
# include <fstream>
# define maxn 1024
# include <algorithm>
# include <cstdio>
using namespace std;

ifstream f("cmlsc.in");
FILE *g;

int a[maxn], b[maxn], sol[maxn][maxn],n,m;

void back(int i, int j)
{
    if((i==0) || (j==0))
        return;
    else
    {
        if(a[i]==b[j])
        {
           // g<<a[i]<<" ";
            return back(i-1, j-1);
        }
        else
        {
            if(sol[i-1][j]>sol[i][j-1])
                return back(i-1,j);
            else
                return back(i,j-1);
        }
    }
}

int main()
{
    int i,j;
    f>>n>>m;
    for(i=1; i<=n; i++)
        f>>a[i];
    for(j=1; j<=m; j++)
        f>>b[j];

    //g=fopen("cmlsc.out","w");
    //fprintf(g, "\n" );
    for(i=1; i<=n; i++)
        for(j=1; j<=m; j++)
        {
            if(a[i]==b[j])
            {
                sol[i][j]=sol[i-1][j-1]+1;
                //fprintf (g, "%d ", a[i]);
            }
            else
                sol[i][j]=max(sol[i-1][j],sol[i][j-1]);

        }

        //fclose(g);
        g=fopen("cmlsc.out", "w");
        fprintf(g, "%d", sol[n][m]);

        //back(n,m);

    return 0;
}
