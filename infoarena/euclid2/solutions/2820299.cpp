#include <iostream>
#include <fstream>

using namespace std;

int main()
{
    ifstream cinn("euclid2.in");
    ofstream coutt("euclid2.out");
    int n, a, b, r;
    cinn>>n;
    while(n){
        cinn>>a>>b;
        r = a % b;
        while(r) {
            a = b;
            b = r;
            r = a % b;
        }
        coutt<<b<<endl;
        n--;
    }
    return 0;
}
