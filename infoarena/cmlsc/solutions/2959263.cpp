#include <fstream>

using namespace std;

ifstream fin("cmlsc.in");
ofstream fout("cmlsc.out");

const int Nmax = 1025;

int a[Nmax], b[Nmax], d[Nmax][Nmax], prv[Nmax];

void reconst(int x){
    if(prv[x] == -1){
        fout << a[x] << " ";
        return;
    }
    reconst(prv[x]);
    fout << a[x] << " ";
}

int main()
{
    int n, m, scmax, t;
    bool ok;

    fin >> n >> m;

    for(int i = 1; i <= n; i++){
        fin >> a[i];
    }

    for(int j = 1; j <= m; j++){
        fin >> b[j];
    }

    d[0][0] = 0;
    scmax = 0;
    prv[1] = -1;
    for(int i = 1; i <= n; i++){
        ok = 0;
        for(int j = 1; j <= m; j++){
            if(a[i] == b[j]){
                d[i][j] = d[i - 1][j - 1] + 1;
                ok = 1;

                if(d[i][j] > scmax){
                    scmax = d[i][j];
                    t = i;
                }
            }
            else{
                d[i][j] = max(d[i - 1][j], d[i][j - 1]);
            }
        }
        if(i != n){
            if(ok == 0){
                prv[i + 1] = prv[i];
            }
            else{
                prv[i + 1] = i;
            }
        }

    }

    fout << scmax << '\n';

    reconst(t);

    return 0;
}
