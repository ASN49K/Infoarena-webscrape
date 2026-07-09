#include <iostream>
#include <fstream>
using namespace std;

int n,a,b;
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
    ifstream f("euclid2.in");
    ofstream g("euclid2.out");
    f>>n;
    for(int i=0; i<n; i++){
        f>>a>>b;
        g<<cmmdc(a,b)<<endl;
    }
    f.close();
    g.close();
    return 0;
}
