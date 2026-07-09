#include <fstream>
#include <iostream>

using namespace std;

int main()
{
    ifstream in("cmlsc.in");
    ofstream out("cmlsc.out");
    int n,m;
    in>>n>>m;
    int vn[n+1],vm[m+1],i,j,tab[n+1][m+1];
    for(i=1;i<=n;i++)
        {
            in>>vn[i];
        }
    for(i=1;i<=m;i++)
        {
            in>>vm[i];
        }
    for(i=0;i<=n;i++)
        {
            for(j=0;j<=m;j++)
                {
                    tab[i][j]=0;
                }
        }
    int sir[min(n,m)],k=0;
    for(i=1;i<=n;i++)
        {
            for(j=1;j<=m;j++)
                {
                    if(vn[i]==vm[j])
                        {
                            tab[i][j]=1+tab[i-1][j-1];
                            sir[k]=vn[i];
                            k++;
                        }
                    else
                        {
                            if(tab[i-1][j]>tab[i][j-1])
                                {
                                    tab[i][j]=tab[i-1][j];
                                }
                            else
                                {
                                    tab[i][j]=tab[i][j-1];
                                }
                        }
                }
        }
    out<<tab[n][m]<<"\n";
    for(i=0;i<k;i++)
        {
            out<<sir[i]<<" ";
        }
    in.close();
    out.close();
    return 0;
}
