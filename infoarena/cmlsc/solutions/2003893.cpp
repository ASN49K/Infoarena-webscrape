#include <fstream>
#define in "cmlsc.in"
#define out "cmlsc.out"
#define max(a,b) (a>b ? a:b)
#define N 1030

using namespace std;

ifstream fin(in);
ofstream fout(out);

short a[N],b[N],v[N][N];
int s[N];
int n,m;

void afisare()
{
    for(int i=1; i<=n; ++i)
    {
        for(int j=1; j<=m; ++j)
            fout<<v[i][j]<<" ";
        fout<<"\n";
    }
}

int main()
{
    fin>>n>>m;

    for(int i=1; i<=n; ++i)
        fin>>a[i];
    for(int i=1; i<=m; ++i)
        fin>>b[i];

    for(int i=1; i<=n; ++i)
        for(int j=1; j<=m; ++j)
            v[i][j] = max(max(v[i-1][j] , v[i][j-1]) , (a[i] == b[j] ? v[i-1][j-1]+1 : 0));

    //afisare();

    int i2,j2;
    i2 = n; j2 = m;
    bool gasit;
    int ct = 0;

    int sol = v[n][m];

    while(v[i2][j2]!=0)
    {
        do
        {
            gasit = false;
            if(v[i2-1][j2] == v[i2][j2])
            {
                gasit = true;
                --i2;
            }
            if(v[i2][j2-1] == v[i2][j2])
            {
                gasit = true;
                --j2;
            }

        } while(gasit == true);

        s[++ct] = a[i2];
        --i2; --j2;
    }

    fout<<sol<<"\n";
    for(int i=sol;  i>0; --i)
        fout<<s[i]<<" ";

    fin.close(); fout.close();
    return 0;
}
