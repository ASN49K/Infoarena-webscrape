#include <iostream>
#include <fstream>
using namespace std;

ifstream f("euclid2.in");
ofstream g("euclid2.out");

int cmmdc(int a, int b){
    int c;
    while (b) {
        c = a % b;
        a = b;
        b = c;
    }
    return a;
}

int main()
{
    int n,a,b;
    f>>n;

    for(int i=0; i<n; i++){
            f>>a>>b;
            g<<cmmdc(a,b)<<endl;
    }

    return 0;
}
