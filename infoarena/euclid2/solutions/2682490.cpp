#include <iostream>
#include <fstream>


int cmmdc (int a, int b)
{
    if(!b)
        return (a);
    return cmmdc(b,a%b);
}


int main() {
    std::fstream in ("euclid2.in");
    std::ofstream out ("euclid2.out");

    int T, a,b;
    in>>T;

    while (T !=0)
    {
        in>>a>>b;
        out<<cmmdc(a,b)<<'\n';
        T--;
    }

    return 0;
}
