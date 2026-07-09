#include <iostream>
#include <fstream>
#define nmax 1025
#define max(a,b) ((a)>(b))?(a):(b)

using namespace std;

int m, n, nr=0;
int a[nmax], b[nmax], d[nmax][nmax], s[nmax];

void citire(){
    int i;
    ifstream in("cmlsc.in");
    in >> n >> m;
    for(i=1;i<=n;++i)
        in >> a[i];
    for(i=1;i<=m;++i)
        in >> b[i];
    in.close();
}

void rezolv(){
    int i, j;
    for(i=1;i<=n;++i)
        for(j=1;j<=m;++j)
            if(a[i] == b[j]) d[i][j] = 1 + d[i-1][j-1];
            else d[i][j] = max(d[i][j-1], d[i-1][j]);
    i = n; j = m;
    while(i>0 && j>0){
        if(i && j && a[i] == b[j]) {
            s[++nr] = a[i];
            --i;--j;
            continue;
        }
        if(i && j && d[i-1][j] == d[i][j]){
            --i;
            continue;
        }
        if(i && j && d[i][j-1] == d[i][j]){
            --j;
        }

    }
}

void afis(){
    ofstream out("cmlsc.out");
    out << nr << '\n';
    for(int i=nr;i>0;--i)
        out << s[i] << " ";
    out.close();
}

int main()
{
    citire();
    rezolv();
    afis();
    return 0;
}
