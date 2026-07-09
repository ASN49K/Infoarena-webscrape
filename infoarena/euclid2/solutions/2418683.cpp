#include <fstream>

std::ifstream fin ("euclid2.in");
std::ofstream fout("euclid2.out");

std::size_t Euclid(std::size_t a, std::size_t b)
{
    if(b == 0)  return a;
    return Euclid(b, a%b);
}

int main()
{
    std::size_t n, a, b;
    fin >> n;

    for(std::size_t i = 0; i < n; ++i)
    {
        fin >> a >> b;
        fout << Euclid(a, b);
    }

    fin.close();
    fout.close();
}
