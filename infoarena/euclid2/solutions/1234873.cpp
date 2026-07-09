#include <iostream>
#include <fstream>

using namespace std;

ifstream in("euclid2.in");
ofstream out("euclid2.out");

int cmmdc(int a, int b){
    while(a && b) {
        if(a > b) {
            a = a % b;
        }
        else {
            b = b % a;
        }
    }
    if(a)
        return a;
    return b;
}

int main()
{
    int n, i, nr1, nr2;
    in >> n;
    for(i = 1; i <= n; i++) {
        in >> nr1 >> nr2;
        out << cmmdc(nr1, nr2) << "\n";
    }
    in.close();
    out.close();
    return 0;
}
