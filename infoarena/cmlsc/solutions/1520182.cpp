#include<fstream>
#include<cmath>
using namespace std;
ifstream fin("cmlsc.in");
ofstream fout("cmlsc.out");

int m,n,v1[1025],v2[1025],d[1025][1025],s[1025],k=1;

int main()
{

    fin>>m;
    fin>>n;

    for(int i=1;i<=m;i++)
        fin>>v1[i];
    for(int j=1;j<=n;j++)
        fin>>v2[j];

    for(int i=1;i<=m;i++)
    {
        for(int j=1;j<=n;j++)
        {
            if(v1[i]==v2[j])
            {
                d[i][j] = 1 + d[i-1][j-1];
                s[k]=v1[i];
                k++;
            }

            else
                d[i][j] = max(d[i-1][j], d[i][j-1]);

        }
    }
    fout<<d[m][n]<<endl;
    for(int i=1;i<k;i++)
        fout<<s[i]<<" ";

}
