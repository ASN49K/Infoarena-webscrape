#include <iostream>
#include <fstream>
using namespace std;
int Euclid (int a, int b){
    if (a == 0) {
        return b;
    }
    int c;
    while (b) {
        c = a%b;
        a = b;
        b = c;
    }
    return a;
}

int main()
{
    ifstream in("euclid2.in");
    ofstream out("euclid2.out");
    int a, b, n;
    in>>n;
    for (int i=0; i<n; i++) {
        in>>a>>b;
        out<<Euclid(a, b)<<"\n";
    }
    return 0;
}