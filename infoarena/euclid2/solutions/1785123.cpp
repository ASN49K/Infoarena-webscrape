#include <iostream>
#include <fstream>
#include <cstdint>

using namespace std;

uint32_t ae(uint32_t a, uint32_t b)
{
    if(b == 0)
        return a;
    return ae(b, a % b);
}

int main()
{
    ifstream in;
    ofstream out;

    in.open("euclid2.in");
    out.open("euclid2.out");

    uint32_t t, a, b;
    in >> t;

    for(; t > 0; --t){
        in >> a >> b;
        out << ae(a, b) << endl;
    }
    return 0;
}
