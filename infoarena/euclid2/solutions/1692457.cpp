#include <iostream>
#include <fstream>

using namespace std;

fstream fileIn, fileOut;
long a,n,b,i;

long Euclid(long a, long b) {
    if (a == b) return a;
    if (a > b) return Euclid(a-b, b);
    if (a < b) return Euclid(a, b-a);
}

int main()
{
    fileIn.open("euclid2.in", ios_base::in);
    fileOut.open("euclid2.out", ios_base::out);
    fileIn >> n;
    for(i = 1; i <= n; i++) {
        fileIn >> a >> b;
        fileOut << Euclid(a, b) << endl;
    }
    fileIn.close();
    fileOut.close();
    return 0;
}
