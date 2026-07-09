#include <iostream>
#include <fstream>

std::ifstream f("euclid2.in);
std::ofstream g("euclid2.out);

int Cmmdc(int a, int b)
{
    if(b==0)
      return a;
    else
      return Cmmdc(b, a%b);
}

void file_p()
{
    int T, a, b;
    std::f>>T;
    while(std::f>>a>>b)
        std::g<<Cmmdc(a,b)<<"\n";
}

void Main()
{
    file_p();
    f.close();
    u.close();
}