#include <iostream>
#include <fstream>
using namespace std;

int main()
{
    ifstream f ("euclid2.in");
    ofstream g ("euclid2.out");
    int n,a,b,i,o=0;
    f>>n;
    while (n>0){
        f>>a>>b;
        if (a>b) i=b;
            else i=a;
        while (i>=1&&o==0) {
            if (a%i==0&&b%i==0)
                o=i;
            i--;
        }
        g<<o<<endl;
        o=0;
        n--;
    }



    return 0;
}
