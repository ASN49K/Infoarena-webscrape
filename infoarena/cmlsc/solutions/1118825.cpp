#include <cstdio>
#include <vector>
#define filein "cmlsc.in"
#define fileout "cmlsc.out"
#define max(a,b) (a>b)?a:b
using namespace std;

int a[1025];
int b[1025];
int n,m;
int l[1025][1025];
vector <int> v;
vector <int>::iterator it;

void citire();
void generare();
void afisare();

int main()
{
    citire();
    generare();
    int x=n,y=m;
    while (x!=0 && y!=0)
    {
        if (l[x][y]==l[x-1][y])
            x--;
        else if (l[x][y]==l[x][y-1])
            y--;
        else
        {
            v.push_back(a[x]);
            x--;
            y--;
        }
    }
    afisare();
    return 0;
}

void citire()
{
    FILE *in;
    in=fopen(filein,"r");
    fscanf(in,"%d %d",&n,&m);
    int i;
    for (i=1; i<=n; i++)
        fscanf(in,"%d",a+i);
    for (i=1; i<=m; i++)
        fscanf(in,"%d",b+i);
    fclose(in);
}

void generare()
{
    int i,j;
    for (i=1; i<=n; i++)
        for (j=1; j<=m; j++)
        {
            if (a[i]==b[j])
                l[i][j]=l[i-1][j-1]+1;
            else
                l[i][j]=max(l[i-1][j],l[i][j-1]);
        }
}

void afisare()
{
    FILE *out;
    out=fopen(fileout,"w");
    fprintf(out,"%d\n",l[n][m]);
    for (it=v.end()-1; it>=v.begin(); it--)
        fprintf(out,"%d ",(*it));
    fclose(out);
}
