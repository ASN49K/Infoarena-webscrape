#include <iostream>
#include <fstream>

using namespace std;

long long cmmdc(long long a, long long b){
    long long c;
    while (b){
        c = a % b;
        a = b;
        b = c;
    }
    return a;
}

int main()
{
    ifstream in("euclid2.in");
    ofstream out("euclid2.out");

    long long a, b, n;
    in >> n;

    for (int i = 0; i < n; i++){
        in >> a >> b;
        out << cmmdc(a, b) << endl;
    }

    in.close();
    out.close();
    return 0;
}
