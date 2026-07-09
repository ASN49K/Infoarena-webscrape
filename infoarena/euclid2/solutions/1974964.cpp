#include <iostream>
#include <fstream>

using namespace std;

ifstream f("euclid2.in");
ofstream g("euclid2.out");

int cmmdc(int a, int b){
    int c = 0;
    while(b){
        c = a % b;
        a = b;
        b = c;
    }
    return a;
}

int a, b, T;

int main()
{
    f >> T;
    for(int i = 0; i < T; i++){
        f >> a >> b;
        g << cmmdc(a,b) << '\n';
    }
    return 0;
}
