#include <fstream>
#include <vector>
using namespace std;
ifstream fin("cmlsc.in");
ofstream fout("cmlsc.out");
const int nmax = 1024;

int n, m;
int d[nmax + 5][nmax + 5];
int a[nmax + 5];
int b[nmax + 5];

int mx = -1;
pair<int,int> mx_poz;

int main()
{
    fin>>n>> m;
    for(int i = 1; i <= n; i++) fin>>a[i];
    for(int i = 1; i <= m; i++) fin>>b[i];

    for (int i = 1; i <= n; i++)
        for (int j = 1; j <= m; j++){
            if (a[i] == b[j]) {
                d[i][j] = d[i-1][j-1] + 1;
                if (d[i][j] > mx) {
                    mx = d[i][j];
                    mx_poz = {i,j};
                }
                continue;
            }
            if (d[i-1][j] > d[i][j-1]) {
                d[i][j] = d[i-1][j];
                if (d[i][j] > mx) {
                    mx = d[i][j];
                    mx_poz = {i,j};
                }
                continue;
            }
            d[i][j] = d[i][j-1];
            if (d[i][j] > mx) {
                mx = d[i][j];
                mx_poz = {i,j};
            }

        }
    fout<<mx<<'\n';
    int i = n;
    int j = m;
    vector <int> stk;
    while (i > 0 && j > 0) {
        if (a[i] == b[j]) {
            stk.push_back(a[i]);
            i--;
            j--;
            continue;
        }
        if (d[i-1][j] > d[i][j-1]) {
            i--;
            continue;
        }
        j--;
    }
    while (!stk.empty()) {
        fout<<stk.back()<<' ';
        stk.pop_back();
    }

}
