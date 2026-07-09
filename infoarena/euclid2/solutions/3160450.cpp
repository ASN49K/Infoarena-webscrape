#include <iostream>
#include <fstream>

using namespace std;

//ifstream fin("./date.txt");
ifstream fin("euclid2.in");
ofstream fin("euclid2.out");


int cmmdc(int a, int b)
{
    while (b)
    {
        int r = a % b;
        a = b;
        b = r;
    }
    return a;
}

int main()
{
    int t;
    fin >> t;
    while (t--)
    {
        int a, b;
        fin >> a >> b;
        cout << cmmdc(a, b) << '\n';
    }
}
