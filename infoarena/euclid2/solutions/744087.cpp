#include<fstream>

int euclid(int a, int b)
{
    if ( b == 0)
        return a;

    else
        return euclid(b, a % b);
}

int main(void)
{
    std::ifstream ifs;
    std::ofstream ofs;

    ifs.open("euclid2.in");
    ofs.open("euclid2.out");

    int n, a, b;

    ifs >> n;

    for (int contor = 0; contor < n; contor++)
    {
        ifs >> a >> b;

        ofs << euclid(a, b) << std::endl;

    }

    return 0;
}
