#include <fstream>
#include <cstring>

#define X1 1025

using namespace std;

ifstream in;
ofstream out;

short m[X1][X1];
short A[X1],B[X1],sol[X1];

inline int max(int a,int b)
{
    if(a>b) return a;
    else return b;
}

int main()
{
    short M,N,x,y,cnt;

    in.open("cmlsc.in");
    in>>M>>N;
    for(short i=1;i<=M;++i) in>>A[i];
    for(short i=1;i<=N;++i) in>>B[i];
    in.close();

    memset(m,0,sizeof(m));
    for(short i=1;i<=M;++i)
        for(short j=1;j<=N;++j)
            if(A[i]==B[j]) m[i][j]=m[i-1][j-1]+1;
            else m[i][j]=max(m[i-1][j],m[i][j-1]);

    out.open("cmlsc.out");
    out<<m[M][N]<<'\n';
    memset(sol,0,sizeof(sol));
    x=M;
    y=N;
    cnt=m[x][y];
    while(cnt)
    {
        while(m[x][y]==m[x-1][y]) --x;
        while(m[x][y]==m[x][y-1]) --y;
        sol[cnt]=A[x];
        --x;
        --y;
        --cnt;
    }
    for(short i=1;i<=m[M][N];++i) out<<sol[i]<<' ';
    out<<'\n';
    out.close();

    return 0;
}
