

#include <iostream>
#include <fstream>

using namespace std;

ifstream fin("euclid2.in");
ofstream fout("euclid2.out");

int cmmdc(int nr1, int nr2)
{
    if (nr2 < nr1)
        swap(nr2, nr1);
    while (nr1 != 0)
    {
        int r = nr2 % nr1;
        nr2 = nr1;
        nr1 = r;
    }
    return nr2;
}

int main()
{
    int n,nr1,nr2;
    fin >> n;
    for (int i = 0; i < n; i++)
    {
        cin >> nr1 >> nr2;
        fout << cmmdc(nr1, nr2);

    }
    return 0;
}

