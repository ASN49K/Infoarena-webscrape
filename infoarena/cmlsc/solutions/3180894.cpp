#include <iostream>
#include <fstream>

using namespace std;
ifstream fin("cmlsc.in");
ofstream fout("cmlsc.out");
int n,i,j,a[1030],b[1030],l[1030][1030],m,k,c[1030];
void constr(int i , int j)
{
    if(l[i][j]>0)
        if(a[i]==b[j])
            {constr(i-1,j-1);k++;c[k]=a[i];}
        else
            {
                if(l[i-1][j]>l[i][j-1])
                    constr(i-1,j);
                else constr(i,j-1);
            }
}

int main()
{
    fin>>n;fin>>m;
    for(i=1;i<=n;i++)
        fin>>a[i];
    for(i=1;i<=m;i++)
        fin>>b[i];
    for(i=0;i<=n;i++)
        l[i][0]=0;
    for(i=1;i<=m;i++)
        l[0][i]=0;
    for(i=1;i<=n;i++)
    {
        for(j=1;j<=m;j++)
        {
            if(a[i]==b[j])
                l[i][j]=l[i-1][j-1]+1;
            else
            {
                l[i][j]=max(l[i-1][j],l[i][j-1]);
            }
        }
    }
    constr(n,m);
    fout<<k<<'\n';
    for(i=1;i<=k;i++)
        fout<<c[i]<<' ';


    return 0;
}
