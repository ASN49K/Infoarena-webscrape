#include <iostream>
#include <fstream>
using namespace std;

ifstream fin ("euclid2.in");
ofstream fout ("euclid2.out");

int euclid (int a, int b)
{
    int r;
    while(b)
    {
        r=a%b;
        a=b;
        b=r;
    }
    return a;
}

int main()
{
    ios_base::sync_with_stdio(false);
    int a, b, t;
    fin >> t;
    while(t--)
    {
        fin >> a >> b;
        fout << euclid(a, b) << "\n";
    }
    fin.close();
    fout.close();
    return 0;
}
