#include <fstream>

using namespace std;

const int Nmax = 1025;

int a[Nmax], b[Nmax], d[Nmax][Nmax], v[Nmax];

int main()
{
    ifstream fin("cmlsc.in");
    ofstream fout("cmlsc.out");

    int n, m, scmax, i, j;

    fin >> n >> m;

    for(i = 1; i <= n; i++){
        fin >> a[i];
    }

    for(j = 1; j <= m; j++){
        fin >> b[j];
    }

    d[0][0] = 0;
    scmax = 0;
    for(int i = 1; i <= n; i++){
        for(int j = 1; j <= m; j++){
            if(a[i] == b[j]){
                d[i][j] = d[i - 1][j - 1] + 1;

                if(d[i][j] > scmax){
                    scmax = d[i][j];
                }
            }
            else{
                d[i][j] = max(d[i - 1][j], d[i][j - 1]);
            }
        }

    }

    fout << scmax << '\n';

    scmax = d[n][m];
    i = n;
    j = m;

    while(scmax > 0){
        if(d[i - 1][j] == scmax){
            i--;
        }
        else if(d[i][j - 1] == scmax){
            j--;
        }
        else{
            scmax--;
            i--;
            j--;
            v[scmax] = a[i];
        }
    }

    for(i = 0; i < d[n][m]; i++){
        fout << v[i] << " ";
    }
    return 0;
}
