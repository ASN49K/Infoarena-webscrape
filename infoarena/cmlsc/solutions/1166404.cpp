//O(N*M) - Cel mai lung subsir comun
#include <fstream>
#include <algorithm>
#include <vector>
#define Nmax 1099
#define pb push_back
using namespace std;
ifstream f("cmlsc.in");
ofstream g("cmlsc.out");

int N,M,a[Nmax],b[Nmax],D[Nmax][Nmax];
vector < int > sol;


void MakeDynamic(int a[],int b[],int N,int M,int D[Nmax][Nmax])
{
    for(int i=1;i<=N;++i)
      for(int j=1;j<=M;++j)
        if(a[i]==b[j]) D[i][j]=D[i-1][j-1]+1;
            else if(D[i-1][j]>D[i][j-1]) D[i][j]=D[i-1][j];
                                    else D[i][j]=D[i][j-1];
}

void MakeCMLSC(int D[Nmax][Nmax])
{
     for(int i=N,j=M; i>0 ; )
        if(a[i]==b[j])sol.pb(a[i]),--i,--j;
        else if(D[i-1][j]>D[i][j-1])--i;
                               else --j;
}


void ReadInput(),PrintOutput();

int main()
{
    f>>N>>M;
    for(int i=1;i<=N;++i)f>>a[i];
    for(int i=1;i<=M;++i)f>>b[i];
    MakeDynamic(a,b,N,M,D);
    MakeCMLSC(D);
    g<<D[N][M]<<'\n';
    for(int i=sol.size()-1; i>=0; --i)g<<sol[i]<<' ';
    g<<'\n';
    f.close();g.close();
    return 0;
}
