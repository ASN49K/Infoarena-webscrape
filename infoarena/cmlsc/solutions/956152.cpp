#include <fstream>
using namespace std;

fstream fin("cmlsc.in", ios::in);
fstream fout("cmlsc.out", ios::out);

short a[1025],b[1025],l[1025];
short M,N,mm;

int main()
{
    short i,j,p=0;
    fin>>M>>N;
    for(i=1; i<=M; i++)
    {
        fin>>a[i];
    }
    for(i=1; i<=N; i++)
    {
        fin>>b[i];
        for(j=p+1; j<=M; j++)
        {
            if(b[i]==a[j])
            {
                p=j;
                l[++mm]=b[i];
                break;
            }
        }
    }
    fout<<mm<<'\n';
    for(i=1; i<=mm; i++) fout<<l[i]<<' ';
    fin.close(); fout.close();
    return 0;
}
