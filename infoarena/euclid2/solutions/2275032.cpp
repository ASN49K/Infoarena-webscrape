#include <bits/stdc++.h>
#define MAX 100000
#define swap(a, b, tmp) do {\
    tmp = a;\
    a = b;\
    b = tmp;\
} while (0)

using namespace std;
int main()
{
    int n, a[MAX], b[MAX], tmp;
    ifstream fin("euclid2.in", std::ifstream::in);
    ofstream fout("euclid2.out", std::ofstream::out);
    fin >> n;
    for (int i = 0;i < n;i++) {
        fin >> a[i] >> b[i];
    }
    for (int i = 0;i < n;i++) {
        while (b[i]) {
            if (a[i] < b[i]) {
                swap(a[i], b[i], tmp);
            }
            tmp = a[i] % b[i];
            a[i] = b[i];
            b[i] = tmp;
        }
        fout << a[i] << endl;
    }
    fin.close();
    fout.close();
    return 0;
}
