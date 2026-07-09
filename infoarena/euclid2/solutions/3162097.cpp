#include <iostream>
#include <fstream>
using namespace std;

int main()
{
    ifstream f ("euclid2.in");
    ofstream g ("euclid2.out");
    int n,a,b,i,o,j;
    f>>n;
    while (n>0){
        f>>a>>b;
        if (a>b) i=b;
            else i=a;
        for (j=1;j<=i;j++) {
            if (a%j==0&&b%j==0)
                o=j;
        }
        g<<o<<endl;
        n--;
    }



    return 0;
}
