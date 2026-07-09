#include <fstream>

ifstream q("euclid.in")
ofstream p("euclid.out")

using namespace std;

int main()
{
    int a, b;
    fin >> a >> b;
    while(a != b)
    {
        if(a > b)
            a = a - b;
        if(b > a)
            b = b - a;
    }
    fout << a;
    return 0;
}
