#include <fstream>

using namespace std;

ofstream out("cmlsc.out");

int n,m,a[1025],b[1025],i,v[1025][1025],j,sum,t;

void afiseaza_solutie_max(int i,int j)
{
    if(v[i][j])
        if(a[i]==b[j])
        {
            sum++;
            afiseaza_solutie_max(i-1,j-1);
            if(!t)
            {
                out<<sum<<'\n';
                t++;
            }
            out<<a[i]<<' ';
        }
        else
        {
            if (v[i][j]==v[i-1][j])
                afiseaza_solutie_max(i-1,j);
            else if (v[i][j]==v[i][j-1])
                afiseaza_solutie_max(i,j-1);
        }
}
int main()
{
    freopen("cmlsc.in","r",stdin);
    scanf("%d%d",&n,&m);
    for(i = 1 ; i <= n ; i++)
        scanf("%d",&a[i]);
    for(i = 1 ; i <= m ; i++)
        scanf("%d",&b[i]);
    for(i = 1 ; i <= n ; i++)
        for(j = 1 ; j <= m ; j++)
        {
            if(a[i]==b[j])
            {
                sum++;
                v[i][j]=sum;
            }
            else
                if (v[i-1][j]>v[i][j-1])
                v[i][j]=v[i-1][j];
            else v[i][j]=v[i][j-1];
        }
    sum=0;
    afiseaza_solutie_max(n,m);
    return 0;
}
