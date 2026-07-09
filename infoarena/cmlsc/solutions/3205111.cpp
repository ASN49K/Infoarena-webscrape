#include <fstream>

using namespace std;
ifstream fin("cmlsc.in");
ofstream fout("cmlsc.out");
int n,m,a[2000],b[2000],d[2000],tata[2000],val[2000];
void afis(int i)
{
    if(tata[val[i]]>0)
    {
        afis(tata[val[i]]);
        fout<<b[val[i]]<<" ";
    }
    else
    fout<<b[val[i]]<<" ";
}
int main()
{
    fin>>n>>m;
    for(int i=1;i<=n;i++)
        fin>>a[i];
    for(int j=1;j<=m;j++)
        fin>>b[j];
    for(int i=1;i<=n;i++)
    {
        for(int j=1;j<=m;j++)
        {
            if(a[i]==b[j])
            {
                if(d[j]<d[j-1]+1)
                {
                    d[j]=d[j-1]+1;
                    tata[j]=val[j-1];
                    val[j]=j;
                }

            }
        }
        for(int j=1;j<m;j++)
        {
            if(d[j+1]<d[j])
            {
                d[j+1]=d[j];
                val[j+1]=val[j];
            }
        }

    }
    fout<<d[m]<<"\n";
    afis(m);


    return 0;
}
