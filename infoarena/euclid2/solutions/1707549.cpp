#include <iostream>
#include <fstream>

using namespace std;

int main()
{
    ifstream in("euclid2.in");
    ofstream out("euclid2.out");

    int n, a, b, i, r;
    in>>n;

    for (i=0; i<n; i++) {
        in>>a>>b;

        while (b) {
            r = a%b;
            a = b;
            b = r;
        }

        out<<a<<endl;
    }

    in.close();
    out.close();
    return 0;
}
