#include <iostream>
#include <fstream>

using namespace std;

int t, a, b;

int cmmdc(int a, int b){
    while(a != b){
        if(a > b)
            a-=b;
        if(b > a)
            b -= a;
    }
    return a;
}

int main()
{
    ifstream f("euclid2.in");
    ofstream g("euclid2.out");
    f >> t;
    for(int i=1; i<=t; i++){
        f >> a >> b;
        g << cmmdc(a, b) << "\n";
    }
    return 0;
}
