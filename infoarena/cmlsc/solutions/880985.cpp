#include <iostream>
#include <fstream>
using namespace std;
ifstream in ("cmlsc.in");
ofstream out("cmlsc.out");
int i,n,m,v1[1300],v2[1300],sol[1300][1300],fin[1300],q,j;
int main()
{
    in>>n>>m;
    for(i=1;i<=n;i++)
        in>>v1[i];

    for(i=1;i<=m;i++)
        in>>v2[i];

    for(i=1;i<=n;i++)
        for(j=1;j<=m;j++)
           {
            if(v1[i]==v2[j])
                sol[i][j]=sol[i-1][j-1]+1;
            else
                if(sol[i-1][j]>sol[i][j-1])
                    sol[i][j]=sol[i-1][j];
                else
                    sol[i][j]=sol[i][j-1];
           }

    for (i = n, j = m; i;)
        if(v1[i]==v2[j])
            {fin[++q]=v1[i];i--;j--;}
        else
            if(sol[i-1][j]<sol[i][j-1])
                j--;
            else
                i--;
    out<<q<<'\n';
    for(i=q;i>=1;i--)
        out<<fin[i]<<" ";
    out.close();
    in.close();
    return 0;
}
