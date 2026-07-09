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
    int n, a, b, tmp;
    ifstream fin("euclid2.in", std::ifstream::in);
    ofstream fout("euclid2.out", std::ofstream::out);
    fin >> n;
    for (int i = 0;i < n;i++) {
        fin >> a >> b;
        while (a % b) {
            if (a < b) {
                swap(a, b, tmp);
            }
            tmp = a % b;
            a = b;
            b = tmp;
        }
        fout << b << endl;
    }
    fin.close();
    fout.close();
    return 0;
}
