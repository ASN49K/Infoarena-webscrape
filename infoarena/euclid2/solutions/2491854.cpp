#include <iostream>
#include <fstream>

using namespace std;

ifstream fin ("euclid2.in");
ofstream fout ("euclid2.out");

int n, a, b, d = 1;

int euklidesz (int a, int b)
{
    int i = 2;
    while(i <= b)
    {
        if(a%i == 0 && b%i == 0)
        {
            d *= i;
            a /= i;
            b/=i;
            i = 2;
        }
        else
            i++;
    }
    return d;
}

int main()
{
    fin >> n;
    for(int i = 0; i < n; ++i)
    {
        fin >> a >> b;
        if(a < b)
        {
            int x = a;
            a = b;
            b = x;
        }
        fout << euklidesz(a, b) << '\n';
        d = 1;
    }
}
