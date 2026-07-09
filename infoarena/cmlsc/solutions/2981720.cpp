#include <iostream>
#include <fstream>
using namespace std;

int maxim(int a, int b){
    return a > b ? a : b;
}

short int a[1024], b[1024], v[1024][1024], sir[1024];
int main(){
    short int m, n, i, j, k = 0;
    ifstream fr("cmlsc.in");
    // Citire dimenisuni vector
    fr >> m >> n;

    // Citire elemente vector
    for(i = 1; i <= m; ++i)
        fr >> a[i];
    for(i = 1; i <= n; ++i)
        fr >> b[i];

    fr.close();
    for(i = 1; i <= m; ++i){
        for(j = 1; j <= n; ++j){
            if(a[i] == b[j])
                v[i][j] = v[i-1][j-1] + 1;
            else
                v[i][j] = maxim(v[i][j-1], v[i-1][j]);
        }
    }

    ofstream fw("cmlsc.out");
    fw << v[m][n] << '\n';
    for(i = m, j = n; i && j;){
        if(a[i] == b[j]){
            sir[k++] = a[i];
            --i;
            --j;
        }
        else if(v[i][j-1] > v[i-1][j]){
            --j;
        }
        else{
            --i;
        }
    }

    for(i = k-1; i >= 0; --i)
        fw << sir[i] << ' ';

    fw.close();
    return 0;
}
