#include <iostream>
#include <fstream>

using namespace std;

int n, m;
short a[1025], b[1025], c[1025];
short poz[1025];

bool bun(int i) {
    for(int j = 1; j < i; j ++) if(c[i] == c[j]) return false;
    bool ok = false;
    for(int j = poz[i - 1] + 1; j <= m && !ok; j ++) {
        if(b[j] == a[c[i]]) {
            ok = true;
            poz[i] = j;
        }
    }
    return ok;
}

int main()
{
    ifstream f("cmlsc.in");
    ofstream g("cmlsc.out");

    f >> n >> m;
    for(int i = 1; i <= n; i ++) {
        f >> a[i];
    }

    for(int i = 1; i <= m; i ++) {
        f >> b[i];
    }

    int i = 1, maxx = 0, mx[i];

    while(i != 0) {
        while(i != 0 && i <= n) {
            c[i] ++;
            if(c[i] > n) c[i] = 0, i --;
            else if(bun(i)) {
                i ++;
                if((i - 1) > maxx) {
                    maxx = i - 1;
                    for(int i = 1; i <= maxx; i ++)
                        mx[i] = a[c[i]];
                }
            }
            if(i > n) i = n;
        }

    }

    if(maxx) {
        g << maxx << "\n";
        for(int i = 1; i <= maxx; i ++)
            g << mx[i] << " ";
        g << "\n";
    }
    else g << "0\n";
    return 0;
}
