#include <iostream>
#include <fstream>
std::ifstream fin("euclid2.in");
std::ofstream fout("euclid2.out");
int main()
{
    unsigned int T;
    fin >> T;
    unsigned long long a,b;
    for (unsigned int i=0;i<T;i++)
    {
        fin >> a >> b;
        unsigned long long x=std::max(a,b),y=std::min(a,b);
        while (x!=0 && y!=0) {
            x%=y;
            std::swap(x,y);
        }
        fout << std::max(x,y);
    }
    return 0;
}
