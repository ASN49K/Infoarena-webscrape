#include <fstream>
using namespace std;
ifstream fin ("cmlsc.in");
ofstream fout ("cmlsc.out");
short int lg[1025][1025],a[1025],b[1025],n,m;
void citire()
{
    int i;
    fin>>n>>m;
    for(i=1;i<=n;i++)
        fin>>a[i];
    for(i=1;i<=m;i++)
        fin>>b[i];
}
void cmlsc(int i, int j)
{
    if(i==0 || j==0)
        return;
    if(a[i]==b[j])
        {
            cmlsc(i-1,j-1);
            fout<<a[i]<<" ";
        }
    else
        if(lg[i-1][j]>lg[i][j-1])
            cmlsc(i-1,j);
        else
            cmlsc(i,j-1);
}

int main()
{
   int i,j;
   citire();
   for(i=1;i<=n;i++)
    for(j=1;j<=m;j++)
        if(a[i]==b[j])
            lg[i][j]=lg[i-1][j-1]+1;
        else
            lg[i][j]=max(lg[i-1][j],lg[i][j-1]);
    fout<<lg[n][m]<<endl;
    cmlsc(n,m);
    return 0;
}
