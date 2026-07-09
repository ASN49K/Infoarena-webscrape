#include <iostream>
#include <fstream>

using namespace std;

#define get(i) (i<0)?0:i

ifstream fin("clmsc.in");
ofstream fout("cmlsc.out");

int n, m;
int *v, *w;
int **c, **b;

//b[i,j]
//1 = up
//-1 = left
//0 = upper left

void lcs_length(int *x, int *y, int **b ) {
    int **c = new int*[m+1];
    for(int i = 0 ;i <= m; i++) c[i] = new int[n+1];
    for(int i = 0; i <= m; i++) {
            c[i][0] = 0;
    }
    for(int j = 0; j <= n; j++) c[0][j] = 0;

    for(int i = 1; i <= m; i++)
    for(int j = 1; j <= n; j++) {
        if(x[i] == y[j]) {
            c[i][j] = c[i-1][j-1] + 1;
            b[i][j] = 0;
        }
        else if(c[i-1][j] >= c[i][j-1]) {
            //choose longer current route
            c[i][j] = c[i-1][j];
            b[i][j] = 1;
        }
        else {
            c[i][j] = c[i][j-1];
            b[i][j] = -1;
        }
    }
    fout << c[m][n] << ' ' << '\n';
}

inline void print_lcs(int **b, int *x, int i, int j) {
   if( i== 0 || j == 0) return;
   if(b[i][j] == 0) {
        print_lcs(b,x,i-1,j-1); //stanga sus
        fout << x[i] << ' ';    //printare pentru ca x[i] == y[i] la stanga sus
   }
   else if (b[i][j] == 1) {
        print_lcs(b,x,i-1,j);   //sus
    }
   else print_lcs(b,x,i,j-1);   //stanga
}

int main()
{
    ios::sync_with_stdio(false);
    fin >> m >> n;
    v = new int[m+1];
    w = new int[n+1];

    for(int i = 1; i <= m; i++ ) fin>> v[i];
    for(int i = 1; i <= n; i++ ) fin>> w[i];

    b = new int*[m+1];

    for(int i = 1; i <= m; i++) {
        b[i] = new int[n+1];
    }
    lcs_length(v,w,b);
    print_lcs(b,v,m,n);
    fout<<'\n';
    return 0;
}
