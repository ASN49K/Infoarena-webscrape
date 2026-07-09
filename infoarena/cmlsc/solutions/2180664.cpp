#include<fstream>
using namespace std;
ifstream f("cmlsc.in");
ofstream g("cmlsc.out");
int n, m, a[1025], b[1025], mat[1025][1025], lg, sol[1025];
int main()
{
    f>>n>>m;
    for(int i = 1;i <= n;i++)
        f>>a[i];
    for(int j = 1;j <= m;j++)
        f>>b[j];
    for(int i = 1;i <= n;i++)
        for(int j = 1;j <= m;j++)
            if(a[i] == b[j])
            {
                mat[i][j] = mat[i-1][j-1]+1;
            }
            else
            {
                mat[i][j]=max(mat[i-1][j], mat[i][j-1]);
            }
    int i = n;
    int j = m;
    while(i >= 1&&j >= 1)
    {
        while(mat[i][j] == mat[i-1][j])
        {
            i--;
        }
        while(mat[i][j] == mat[i][j-1])
        {
            j--;
        }
        if(i >= 1&&j >= 1)
        {
            lg++;
            sol[lg] = a[i];
        }
        i--;
        j--;
    }
    g<<lg<<"\n";
    for(i = lg;i >= 1;i--)
        g<<sol[i]<<" ";
    return 0;
}
