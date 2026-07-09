#include <fstream>
using namespace std;

fstream fin("cmlsc.in", ios::in);
fstream fout("cmlsc.out", ios::out);

short a[1025],b[1025],lcs[1025][1025],d[1025];
short M,N;

int main()
{
    short i,j,k,h;
    fin>>M>>N;
    for(i=1; i<=M; i++)
    {
        fin>>a[i];
    }
    for(i=1; i<=N; i++)
    {
        fin>>b[i];
    }

    for(i=1; i<=N; i++)
    {
        for(j=1; j<=M; j++)
        {
            if(a[j]==b[i]) lcs[i][j]=lcs[i-1][j-1]+1;
            else
            {
                if(lcs[i-1][j]>lcs[i][j-1]) lcs[i][j]=lcs[i-1][j];
                else lcs[i][j]=lcs[i][j-1];
            }
        }
    }
    fout<<lcs[N][M]<<'\n';
    for(i=0, k=N, h=M; lcs[k][h]; )
    {
        if(a[h]==b[k])
        {
            d[++i]=a[h];
            h--; k--;
        }
        else
        {
            if(lcs[k][h]==lcs[k-1][h]) k--;
            else h--;
        }
    }
    for(k=i; k>0; k--) fout<<d[k]<<' ';

    /*for(i=1; i<=N; i++)
    {
        for(j=1; j<=M; j++) fout<<lcs[i][j]<<' ';
        fout<<'\n';
    }*/


    fin.close(); fout.close();
    return 0;
}
