#include <fstream>
#define max(a, b) ((a>b)?a:b)
#define nmax 1025

using namespace std;

ifstream f("cmlsc.in");
ofstream g("cmlsc.out");

int m,n,len,A[nmax],B[nmax],rez[nmax],d[nmax][nmax],i,j;

int main() {
    f>>m>>n;
    for(i=0;i<m;i++)
        f>>A[i];
    for(i=0;i<n;i++)
        f>>B[i];
    for(i=0;i<m;i++)
        for(j=0;j<n;j++) {
            if(A[i]==B[j])
                d[i][j]=1+d[i-1][j-1];
            else
                d[i][j]=max(d[i-1][j],d[i][j-1]);
        }
    len=0;
    for(i=m-1,j=n-1;i+1;) {
        if(A[i]==B[j])
            rez[++len]=A[i],--i,--j;
        else if (d[i-1][j]<d[i][j-1])
            --j;
        else
            --i;
    }
    g<<len<<'\n';
    for(i=len;i;i--)
        g<<rez[i]<<' ';
    g<<'\n';
    /*for(i=0;i<m;i++) {
        for(j=0;j<n;j++)
            g<<d[i][j]<<' ';
        g<<'\n';
    }*/
}
