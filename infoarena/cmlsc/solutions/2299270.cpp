#include <fstream>
using namespace std;
int n, m, i, j;
int tata[1025][1025], d[1025][1025], a[1025], b[1025];
ifstream fin ("cmlsc.in");
ofstream fout ("cmlsc.out");

void reconst (int x, int y)
{
  if(tata[x][y]!=0)
    if (tata[x][y]==1) {
        reconst(x-1, y-1);
        fout<<a[x]<<" ";
    } else if (tata[x][y]==2)
        reconst(x-1, y);
    else if (tata[x][y]==3)
        reconst(x,y-1);

}

int main () {
    fin>>n>>m;
    for (i=1;i<=n;i++) {
        fin>>a[i];
    }
    for (i=1;i<=m;i++)
        fin>>b[i];

    for (i=1;i<=n;i++) {
        for (j=1;j<=m;j++) {
            if (a[i]==b[j]) {
                d[i][j]=d[i-1][j-1]+1;
                tata[i][j]=1;
            } else if (a[i]!=b[j]) {
                d[i][j]=max(d[i-1][j], d[i][j-1]);
                if (d[i][j]==d[i][j-1])
                    tata[i][j]=3;
                else if (d[i][j]==d[i-1][j])
                    tata[i][j]=2;
            }
        }
    }

    fout<<d[n][m]<<"\n";
    reconst(n, m);
    return 0;
}
