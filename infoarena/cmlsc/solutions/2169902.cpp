#include<fstream>
using namespace std;
ifstream fin("cmlsc.in");
ofstream fout("cmlsc.out");
struct cel{
    int x, y;
};
cel b[1100][1100]={0};
int i,j,n,m,v1[1100],v2[1100],a[1100][1100];
void traseu(int i, int j)
{
    if(i!=0)
    {
        traseu(b[i][j].x,b[i][j].y);
        fout<<v2[i]<<" ";
    }

}
int main()
{
    fin>>n>>m;
    for(i=1;i<=n;i++)
        fin>>v1[i];
    for(i=1;i<=m;i++)
        fin>>v2[i];
    for(i=1;i<=m;i++)
    {
        for(j=1;j<=n;j++)
        {
            if(v1[j]==v2[i])
            {
                a[i][j]=a[i-1][j-1]+1;
                if(b[i][j].x==0)
                    b[i][j]=b[i-1][j-1];
                b[i+1][j].x=i;
                b[i+1][j].y=j;
                b[i][j+1].x=i;
                b[i][j+1].y=j;
                b[i+1][j+1].x=i;
                b[i+1][j+1].y=j;
            }
            else
            {
                if(a[i-1][j]>a[i][j-1])
                {
                    a[i][j]=a[i-1][j];
                    if(b[i][j].x==0)
                        b[i][j]=b[i-1][j];
                }
                else
                {
                    if(a[i-1][j]==a[i][j-1])
                    {
                        if(b[i][j].x==0)
                        {
                            if(b[i-1][j].x>b[i][j-1].x)
                                b[i][j]=b[i-1][j];
                            else
                                b[i][j]=b[i][j-1];
                        }
                        a[i][j]=a[i-1][j];

                    }
                    else
                    {
                        a[i][j]=a[i][j-1];
                        if(b[i][j].x==0)
                            b[i][j]=b[i][j-1];
                    }

                }
            }
        }
    }
    fout<<a[m][n]<<'\n';
    traseu(b[m][n].x,b[m][n].y);
    if(v2[m]==v1[n])
        fout<<v2[m]<<" ";
    return 0;
}
