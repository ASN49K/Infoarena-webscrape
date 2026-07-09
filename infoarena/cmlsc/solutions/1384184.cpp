#include <fstream>

using namespace std;
short a[1026][1026];
short b[1026],c[1026],sir[1026],bst;
int maxime(int x,int y)
{
    if(x>y)
        return x;
    else
        return y;
}
int main()
{
    ifstream f("cmlsc.in");
    ofstream g("cmlsc.out");
    int n,m,i,j;
    f>>m>>n;
        for(i=1;i<=m;i++){
            f>>b[i];
        }
    //f>>m;
    for(i=1;i<=n;i++){
        f>>c[i];
    }
    //N COLOANE
    //M LINII
    for(i=1;i<=m;i++)
        for(j=1;j<=n;j++){
           if (b[i] == c[j])
                a[i][j] = 1 + a[i-1][j-1];
            else
                a[i][j] = maxime(a[i-1][j], a[i][j-1]);
        }

    for (i = m, j = n; i; )
        if (b[i] == c[j])
            sir[++bst] = b[i], --i, --j;
        else if (a[i-1][j] < a[i][j-1])
            --j;
        else
            --i;
    g<<bst<<'\n';
    for(i=bst;i>=1;i--)
        g<<sir[i]<<" ";
    f.close();
    g.close();
    return 0;
}
