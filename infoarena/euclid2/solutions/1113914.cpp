#include <fstream>
#include <iostream>
#include <vector>

const char InFile[] = "euclid2.in";
const char OutFile[] = "euclid2.out";

int euclid(int a, int b)
{
    int r = a % b;
    if( r == 0 )
        return b;
    return euclid(b,r);
}

int main(void)
{
    int a, b, n;
    std::ifstream in(InFile);
    std::ofstream out(OutFile);

    in >> n;

    for( int i=0 ; i<n ; i++ ){
        in >> a >> b;
        out << euclid(a,b) << '\n';
    }

    return 0;
}


