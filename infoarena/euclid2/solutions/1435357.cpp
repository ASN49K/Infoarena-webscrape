#include <iostream>
#include <fstream>
#include <cmath>

using namespace std;

ifstream in("euclid2.in");
ofstream out("euclid2.out");

typedef unsigned long long long_type;

long_type determinare_cmmdc_euclid(long_type a, long_type b)
{
    long_type c;
    while (b){
        c = a % b;
        a = b;
        b = c;
    }
    return a;
}

int main()
{
    long_type nr_elemente, a, b;
    in >> nr_elemente;
    for (long_type i = 1; i <= nr_elemente; i++){
        in >> a >> b;
        out << determinare_cmmdc_euclid(a, b) << "\n";
    }
    return 0;
}
