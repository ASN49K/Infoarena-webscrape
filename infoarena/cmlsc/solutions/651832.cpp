#include <fstream>

#define aL 1025
#define bL 1025
#define solL 1025

using namespace std;

ifstream in;
ofstream out;

int a[aL];
int b[bL];
int c[aL][bL];
int sol[solL];

inline int max(int a,int b)
{
    if(a>b) return a;
    return b;
}

int main()
{
    int M,N;

    in.open("cmlsc.in");

    in>>M>>N;
    for(int i=1;i<=M;++i) in>>a[i];
    for(int i=1;i<=N;++i) in>>b[i];

    in.close();

    for(int i=1;i<=M;++i)
        for(int j=1;j<=N;++j)
            if(a[i]==b[j]) c[i][j]=c[i-1][j-1]+1;
            else c[i][j]=max(c[i-1][j],c[i][j-1]);

    out.open("cmlsc.out");

    out<<c[M][N]<<'\n';
    for(int i=M,j=N;c[M][N];)
        if(c[i][j]==c[i-1][j-1]+1)
        {
            sol[++sol[0]]=a[i];
            --i;
            --j;
            --c[M][N];
        }
        else
        if(c[i][j]==c[i-1][j]) --i;
        else --j;
    for(int i=sol[0];i>1;--i)
        out<<sol[i]<<' ';
    out<<sol[1]<<'\n';

    out.close();

    return 0;
}
