#include <fstream>
using namespace std;

ifstream in; ofstream out;
short int a[1025],b[1025],d[1025],N,M;
short int c[1025][1025]={};

short int max (short int x, short int y) {
      if (c[x][y-1]>c[x-1][y]) return c[x][y-1];
      else return c[x-1][y];
}

int main () {
    in.open ("cmlsc.in"); out.open ("cmlsc.out");
    in>>M>>N;
    short int i,j,k;
    for (i=1; i<=M; i++) in>>a[i];
    for (i=1; i<=N; i++) in>>b[i];
    for (i=1; i<=M; i++)
        for (j=1; j<=N; j++)
            if (a[i]==b[j]) c[i][j]=c[i-1][j-1]+1;
            else c[i][j]=max (i,j);
    out<<c[M][N]<<"\n";
    j=M; k=N;
    for (i=c[M][N]; i; i--) {
        while (c[j][k-1]==i) k--;
        while (c[j-1][k]==i) j--;
        d[i]=a[j];
        j--; k--;
    }
    for (i=1; i<=c[M][N]; i++) out<<d[i]<<" ";
    out<<"\n";
    in.close (); out.close ();
    return 0;
}
