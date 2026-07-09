#include <iostream>
#include <fstream>
using namespace std;

void cmmdc(int a, int b){
    int r = a%b;

    while(r){
        a = b;
        b = r;
        r = a%b;
    }

    g << b << '\n';
}

int main()
{
    ifstream f("euclid2.in");
    ofstream g("euclid2.out");

    int t, a, b;
    f >> t;

    for(int i = 1; i <= t; i++){
        f >> a >> b;

        cmmdc(a, b);
    }

    return 0;
}
