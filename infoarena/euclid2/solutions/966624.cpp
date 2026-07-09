#include <fstream>

using namespace std;

int cmmdc (int a, int b) {
    if (!b)
        return a;
    else
        return cmmdc (b, a%b);

}

int main()
{
    fstream fi ("euclid2.in", ios :: in),
            fo ("euclid2.out", ios :: out);
    int a, b, n, i;

    fi >> n;

    for (i = 1; i <= n; i++) {
        fi >> a >> b;
        fo << cmmdc (a, b) << '\n';
    }

    fi.close();
    fo.close();

    return 0;
}
