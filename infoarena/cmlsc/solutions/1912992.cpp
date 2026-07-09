#include <iostream>
#include <fstream>
#include <algorithm>

#define infile "cmlsc.in"
#define outfile "cmlsc.out"

using namespace std;

ifstream in(infile);
ofstream out(outfile);

int a[1024];
int b[1024];

int comun[1024];

int o[1024][1024];

int n, m;
int pos;


int main()
{
    in >> n >> m;

    for(int i=1; i<=n; i++){
        in >> a[i];
    }
    for(int i=1; i<=m; i++){
        in >> b[i];
    }

    for(int i=1; i<=n; i++){
        for(int j=1; j<=m; j++){
            if(a[i] == b[j]){
                o[i][j] = 1 + o[i-1][j-1];
            }else{
                o[i][j] = max(o[i-1][j], o[i][j-1]);
            }
        }
    }


    for(int i=n, j=m; i;){
        if(a[i] == b[j]){
            pos++;
            comun[pos] = a[i];
            i--;
            j--;
        }else{
            if(o[i-1][j] > o[i][j-1]){
                i--;
            }else{
                j--;
            }
        }
    }

    out << o[n][m] << '\n';

    for(int i=pos; i; i--){
        out << comun[i] << ' ';
    }

    return 0;
}
