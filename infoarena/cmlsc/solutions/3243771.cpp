#include <iostream>
#include <fstream>

using namespace std;

ifstream fin("cmlsc.in");
ofstream fout("cmlsc.out");

int main()
{
    int m, n;
    fin >> m >> n;

    int v1[1030], v2[1030];

    for(int i = 0; i < m; i++) {
        fin >> v1[i];
    }

    for(int i = 0; i < n; i++) {
        fin >> v2[i];
    }

    int lmax = 0, s[1030], k = 0, li = 0, lj = 0;
    for(int i = li; i < m; i++) {
        for(int j = lj; j < n; j++) {
            if(v1[i] == v2[j]) {
                s[k] = v1[i];
                k++;
                lmax++;
                li = i + 1;
                lj = j + 1;
            }
        }
    }

    fout << lmax << endl;

    for(int i = 0; i < k; i++) {
        fout << s[i] << " ";
    }

    return 0;
}
