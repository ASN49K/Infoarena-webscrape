#include <fstream>

using namespace std;

int d[2000][2000];
pair < int,int> t[2000][2000];
int main() {

    int n,m, sir1[2000],sir2[2000];
    ifstream fin ("cmlsc.in");
    ofstream fout ("cmlsc.out");
    fin >> n >> m;
    for ( int i = 1; i <= n; ++i) {
        fin >> sir1[i];
    }
    for ( int j = 1; j <= m; ++j) {
        fin >> sir2[j];
    }

    //d[i][j] = cel mai lung subsir comun cu primele i din sir1 si primele j din sir2
    d[1][0] = 0;
    d[0][1] = 1;
    for ( int i = 1; i <= n; ++i )
    for ( int j  = 1; j <= m; ++j) { 
        if(sir1[i] == sir2[j]) {
          d[i][j] = d[i-1][j-1] + 1;  
        }
        if(d[i][j] < d[i-1][j]) {
             d[i][j] = d[i-1][j];
        }
        if(d[i][j] < d[i][j-1]) {
             d[i][j] = d[i][j-1];
        }
        
    }
    fout << d[n][m] << "\n";
    int sol[2002],cnt = 0;
    int i = n, j = m;
    while(i >0  && j > 0) {
         if(sir1[i] == sir2[j]) {
            sol[++cnt] = sir1[i];
            --i;
            --j;
        }
       if(d[i][j] == d[i-1][j]) {
             --i;
        }
        if(d[i][j] == d[i][j-1]) {
           --j;
        }
        
    }
    for ( int i = cnt; i >= 1; --i) 
        fout << sol[i] << " ";
}