#include <iostream>
#include <fstream>

using namespace std;

ifstream fin("euclid2.in");
ofstream fout("euclid2.out");

int n , a , b;

void euclid(int c1,int c2)
{
    int c;
    while(c2)
    {
        c = c1%c2;
        c1 = c2;
        c2 = c;
    }
    fout << c1 << '\n';
}

void citire()
{
    fin >> n;
    for(int i=1;i<=n;i++)
    {
        fin >> a >> b;
        euclid(a,b);
    }
}

int main()
{
    citire();
    return 0;
}
