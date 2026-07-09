#include <iostream>
#include <fstream>>

using namespace std;

int main () {
    ifstream in ("cmmdc.in");
    ofstream out ("cmmdc.out");

    int a;
    int b;
    int res;
    in >> a >> b;

    int min_value = min(a,b);

    for(int d = min_value; d>=1; d--) {
        if(a % d == 0 && b % d == 0) {
           res = d;
           break;
        }
    }

    if(res == 1) {
        out << 0;
    }
    else {
        out << res;
    }

    return 0;
}
