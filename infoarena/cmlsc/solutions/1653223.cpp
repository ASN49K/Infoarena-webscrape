#include <iostream>
#include <fstream>
using namespace std;

#define FOR(i,a,b) for(int i=(a);i<=(b);++i)
#define MAX(a,b) ((a)>(b)? (a):(b))
#define DIM 1030

fstream fin("cmlsc.in",ios::in);
fstream fout("cmlsc.out",ios::out);

int a[DIM],b[DIM],sir[DIM+DIM],mat[DIM][DIM],n,m,best=1;

void read(){

    fin >> n >> m;
    FOR(i,1,n)
    fin >> a[i];
    FOR(i,1,m)
    fin >> b[i];
    fin.close();
}

void done(){
    FOR(i,1,n)
        FOR(j,1,m)
            if(a[i] == b[j])
                mat[i][j] = 1+mat[i-1][j-1];
            else mat[i][j] = MAX(mat[i-1][j],mat[i][j-1]);

    for(int i=n,j=m; i; )
            if(a[i] == b[j])
                sir[best++]=a[i],i--,j--;
            else if(mat[i-1][j] < mat[i][j-1]) j--;
            else i--;
    fout << best-1 << "\n";
    for(int i=best-1;i;--i)
        fout << sir[i] << " ";
    fout.close();
}

int main()
{
    read();
    done();
    return 0;
}
