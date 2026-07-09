#include <iostream>
#include <fstream>
using namespace std;
ifstream f("cmlsc.in");
ofstream g("cmlsc.out");

int main() {

    int a[1024], b[1024];
    int n; f >> n;
    int m; f >> m;
    for (size_t i = 0; i < n; i++) f >> a[i];
    for (size_t i = 0; i < m; i++) f >> b[i];

    int common[1024], in = -1;
    int l = 0;
    for (int i = 0; i < n; i++)
        for (size_t j = 0; j < m; j++)
            if (a[i] == b[j]) {
                if (in == -1 || j >= common[in]) common[++in] = j;
                else {
                    int st = 0, dr = in;
                    while (st < dr) {
                        int mij = (st + dr) / 2;
                        if (common[mij] > j) dr = mij;
                        else {
                            if (dr - st != 1) st = mij;
                            else st = dr;
                        }
                    }
                    common[st] = j;
                }
                break;
            }
   
    g << in;
}