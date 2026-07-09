#include <iostream>
#include <fstream>

using namespace std;

int e(int a, int b) {
    while(a != 0 && b != 0) {
        if(a > b) {
            a = a - b;
        }else {
            b = b - a;
        }
    }
    if(a == 0) {
        return b;
    }else if(b == 0) {
        return a;
    }else {
        return 1;
    }
}

int main()
{
    ifstream in("euclid2.in");
    ofstream out("euclid2.out");
    int n, a, b;
    in >> n;
    for(int i = 1;i <= n;i++) {
        in >> a >> b;
        out << e(a, b) << endl;
    }
    return 0;
}
