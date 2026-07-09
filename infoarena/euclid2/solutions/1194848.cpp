#include <iostream>
#include <fstream>

using namespace std;
int cmmdc (int a, int b){
    int r;
    while (b){
        r= a%b;
        a=b;
        b=r;
    }
    return a;
}


int main()
{
    ifstream in("./euclid2.in");
    int a, b;
    in>> a >> b;
    int ras = cmmdc(a, b);
    ofstream out("./euclid2.out");
    out<< ras;
    return 0;
}
