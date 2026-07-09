#include <iostream>
#include <fstream>
using namespace std;

int cmmdc(int a, int b){
    int r = a%b;

    while(r){
        a = b;
        b = r;
        r = a%b;
    }

    return b;
}

int main()
{
    ifstream f("euclid2.in");
    ofstream g("euclid2.out");


    int t;
    int a, b;
    f >> t;

    for(int i = 1; i <= t; i++){
        f >> a >> b;

        g << cmmdc(a, b) << endl;
    }

    f.close();
    g.close();

    return 0;
}
