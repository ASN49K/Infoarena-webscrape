#include <iostream>
#include <fstream>
using namespace std;
ifstream fin("cmlsc.in");
ofstream fout("cmlsc.out");
int v[1025],c[1025],i,j,in,k,pozfin,m,n,x;
int main()
{
    fin>>m>>n;
    for(i=1;i<=m;i++)fin>>v[i];
    while(j<=n)
    {
        j++;cout<<1;
        fin>>x;
        in=pozfin;
        for(i=1;i<=m;i++)if(v[i]==x)
                                {
                                    if(i>pozfin)
                                        {cout<<2;
                                            k++;
                                            c[k]=x;
                                            pozfin=i;

                                            ///v[i]=257; or break;
                                            break;
                                        }

                                    if(i<pozfin)
                                        {cout<<3;
                                            ///k e acelasi
                                            c[k]=x;
                                            pozfin=i;

                                            ///v[i]=257; or break;
                                            break;
                                        }
                                }cout<<4<<"j= "<<j<<endl;

    }
    /*for(i=1;i<=m;i++)fout<<v[i]<<" ";
    fout<<endl;*/
    for(i=1;i<=k;i++)fout<<c[i]<<" ";

    return 0;
}
