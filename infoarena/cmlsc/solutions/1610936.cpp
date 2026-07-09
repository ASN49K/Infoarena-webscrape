#include<fstream>
using namespace std;
ifstream f("cmlsc.in");
ofstream g("cmlsc.out");
int x[1025],y[1025],lcs[1025][1025],n,m;
void cmlsc()
{
    for(int k=1;k<=n;k++)
        for(int h=1;h<=m;h++)
            if(x[k]==y[h])
                lcs[k][h]=1+lcs[k-1][h-1];
            else
                if (lcs[k-1][h]>lcs[k][h-1])
                    lcs[k][h]=lcs[k-1][h];
                else
                    lcs[k][h]=lcs[k][h-1];
}
void afiseaza(int k,int h)
{
    if(lcs[k][h])
        if(x[k]==y[h])
        {
            afiseaza(k-1,h-1);
            g<<x[k]<<" ";
        }
        else
        {
            if (lcs[k][h]==lcs[k-1][h])
                afiseaza(k-1,h);
            else
                if (lcs[k][h]==lcs[k][h-1])
                        afiseaza(k,h-1);
        }
}
int main()
{
    f>>n>>m;
    for(int i=1;i<=n;i++)
        f>>x[i];
    for(int i=1;i<=m;i++)
        f>>y[i];
    cmlsc();
    g<<lcs[n][m]<<"\n";
    afiseaza(n,m);
}

