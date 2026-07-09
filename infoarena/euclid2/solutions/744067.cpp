#include<fstream>

int main(void)
{
    std::ifstream ifs;
    std::ofstream ofs;

    ifs.open("euclid2.in");
    ofs.open("euclid2.out");

    int n, a, b;

    ifs >> n;

    int temporar;

    for (int contor = 0; contor < n; contor++)
    {
        ifs >> a >> b;
        temporar = a % b;

        while(temporar > 0)
        {
            a = b;
            b = temporar;
            temporar = a % b;

        }

        ofs << b << std::endl;

    }

    return 0;
}
