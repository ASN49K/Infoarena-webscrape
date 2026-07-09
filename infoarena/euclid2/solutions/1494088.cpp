#include <iostream>
#include <fstream>
using namespace std;

int main()
{
    ifstream f("euclid1.in");
    ofstream g("euclid2.out");
    int T;
    unsigned long a,b,r;
    f>>T;
    for(int i=0; i<T;i++) {
        f>>a>>b;
        r=a%b;
        while(r) {
            a=b;
            b=r;
            r=a%b;
        }
        g<<b<<endl;

    }
    f.close();
    return 0;
}
