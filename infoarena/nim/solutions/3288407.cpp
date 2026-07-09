#include <bits/stdc++.h>
using namespace std;

class inParser {
private:
    FILE *fin; char *buff; int id;
    char readCh( ) {
        ++id;
        if (id == 4096) { id = 0; fread(buff, sizeof(char), 4096, fin); }
        return buff[id];
    }
public:
    inParser (const char *name) {
        fin = fopen(name, "r");
        buff = new char[4096]( );
        id = 4095;
    }

    inParser& operator >> (int &num) {
        char ch;
        while (!isdigit(ch = readCh( )));
        num = ch - '0';
        while (isdigit(ch = readCh( )))
            num = num * 10 + ch - '0';
        return *this;
    }
};

inParser in ("nim.in");
ofstream out ("nim.out");

#define maxsze 1002
#define inf 0x3f3f3f3f

void solve( ) {
    int n; in >> n;

    int sum = 0;
    for (int i = 1; i <= n; ++i) {
        int cur; in >> cur;
        sum ^= cur;
    }
    out << (sum == 0 ? "NU" : "DA") << '\n';
}

int main( ) {
    int q; in >> q;
    while (q--) solve( );
    return 0;
}
