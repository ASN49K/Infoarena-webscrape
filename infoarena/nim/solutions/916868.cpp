#include <fstream>
using namespace std;
ifstream fin("pietre.in");
ofstream fout("pietre.out");
int i,j,n,s,nr,aux,m;
int main()
{
    fin>>n;
    for(i=1;i<=n;++i)
        {
            fin>>m>>aux>>aux;
            s=0;
            for(j=1;j<=m;++j)
            {
                fin>>nr;
                for(int k=1;k<=nr;++k)
                    fin>>aux>>aux;
                s^=nr;
            }
         if(s==0)
            fout<<0<<'\n';
        else
            fout<<1<<'\n';
        }
    return 0;
}