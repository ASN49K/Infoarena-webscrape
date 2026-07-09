#include <fstream>

std::ifstream in("euclid2.in");
std::ofstream out("euclid2.out");

int cmmdc(int a, int b)
{
    int r;
    do
    {
        r = a % b;
        a = b;
        b = r;
    } while (b);
    return a;
}

void readAndShow(int a, int b)
{
    in >> a >> b;
    out << cmmdc(a, b) << '\n';
}

int main()
{
    int T, x, y;
    in >> T;
    while (T--)
        readAndShow(x, y);
    in.close();
    out.close();
    return 0;
}