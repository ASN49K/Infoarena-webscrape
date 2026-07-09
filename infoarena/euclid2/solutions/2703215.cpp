#include <iostream>
#include <fstream>
#include <string>

using namespace std;

ifstream fin("euclid2.in");
ofstream fout("euclid2.out");

int main()
{
    int k;
    fin >> k;
    int a, b, r;
    for(int i = 0; i < k; i ++)
    {
        fin >> a >> b;
        r = a % b;
        while(r)
        {
            a = b;
            b = r;
            r = a % b;
        }
        fout << b;
    }
}