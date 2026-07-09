#include <iostream>
#include <fstream>
using namespace std;

ifstream f("euclid2.in");
ofstream g("euclid2.out");

int cmmdc(int a, int b){

    while (a != b){
        if (a > b)
            a -= b;
        else
            b -= a;
    }
    return a;

}

int main(){

    int T, a, b;
    f >> T;
    while (T){
        f >> a >> b;
        g << cmmdc(a,b) << endl;
        T--;
    }
    f.close();
    g.close();
    return 0;

}
