#include <iostream>
#include <fstream>

unsigned int Euclid(unsigned int a, unsigned int b)
{
    if(!b)
        return a;
    else
        return Euclid(b, a%b);
}

int main()
{
    std::ifstream fin("euclid2.in");
    std::ofstream fout("euclid2.out");
    unsigned int T, a, b;

    fin >> T;
    for(unsigned int i = 0; i < T; i++)
    {
        fin >> a >> b;
        fout << Euclid(a, b) << "\n";

    }
    fin.close();
    fout.close();

    return 0;
}
