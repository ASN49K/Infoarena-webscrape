#include<fstream>

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

        while(a != b)
        {
            if (a > b)
                a = a - b;
            else
                b = b - a;



        }
        ofs << a << std::endl;

    }

    return 0;
}
