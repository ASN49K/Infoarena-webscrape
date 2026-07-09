#include <fstream>

int sub_gcd(int a, int b)
{
    if (a == 0)
        return b;

    if (b == 0)
        return a;

    while (a != b) {
        if (a > b)
            a -= b;
        else
            b -= a;
    }

    return a;
}

int div_gcd(int a, int b)
{
    // int r;

    // while (b != 0) {
    //     r = a % b;
    //     a = b;
    //     b = r;
    // }
    
    for (int r; b != 0; a = b, b = r)
        r = a % b;

    return a;
}

int main()
{
    int n;
    std::ifstream fin("euclid2.in");
    std::ofstream fout("euclid2.out");

    fin >> n;

    for (int a, b, i = 0; i < n; ++i) {
        fin >> a >> b;
        fout << div_gcd(a, b) << '\n';
    }
        
    fin.close();
    fout.close();

    return 0;
}
