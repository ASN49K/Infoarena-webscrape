#include <fstream>

using namespace std;

ifstream fin("cmlsc.in");
ofstream fout("cmlsc.out");

int v[257], a[1025];

int main()
{
    int n, m, x, k = 0;

    fin >> n >> m;

    for(int i = 0; i < n; i++){
        fin >> x;

        v[x]++;
    }

    for(int i = 0; i < m; i++) {
        fin >> x;

        if(v[x]) {
            v[x]--;
            a[k++] = x;
        }
    }

    fout << k << '\n';

    for(int i = 0; i < k; i++)
        fout << a[i] << " ";
}
