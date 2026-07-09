#include <fstream>
#include <stack>
const int N=1026;
using namespace std;
ifstream f("cmlsc.in");
ofstream g("cmlsc.out");
stack <int> s;
int n,m,i,j;
int a[N],b[N];
int mat[N][N];
int main()
{
    f>>n>>m;
    for(i=1;i<=n;i++)
    {
        f>>a[i];
    }
    for(i=1;i<=m;i++)
    {
        f>>b[i];
    }
    for(i=1;i<=n;i++)
    {
        for(j=1;j<=m;j++)
        {
            if(a[i]==b[j])
            {
                mat[i][j]=mat[i-1][j-1]+1;
            }
            else
            {
                mat[i][j]=max(mat[i-1][j],max(mat[i][j-1],mat[i-1][j-1]));
            }
            //g<<mat[i][j]<<" ";
        }
        //g<<"\n";
    }
    int pozx,pozy;
    pozx=n;
    pozy=m;
    while(pozx>=1&&pozy>=1)
    {
        //g<<pozx<<" "<<pozy<<"\n";
        if(a[pozx]==b[pozy])
        {
            s.push(a[pozx]);
            pozx--;pozy--;
        }
        else
        {
            i=pozx;
            j=pozy;
            if(mat[i-1][j]==mat[i][j])
            {
                pozx--;
            }
            else
            {
                if(mat[i-1][j-1]==mat[i][j])
                {
                    pozx--;pozy--;
                }
                else
                {
                    if(mat[i][j-1]==mat[i][j])
                    {
                        pozy--;
                    }
                }
            }
        }
    }
    g<<mat[n][m]<<"\n";
    while(!s.empty())
    {
        g<<s.top()<<" ";
        s.pop();
    }

    f.close();
    g.close();
    return 0;
}
