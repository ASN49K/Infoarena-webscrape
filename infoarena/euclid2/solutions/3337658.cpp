#include <iostream>
#include <fstream>
using namespace std;
ifstream fin("euclid2.in");
ofstream fout("euclid2.out");
int main()
{
    int t;
    fin >> t;
    for(int i = 1;i<=t;i++)
    {
        int a, b;
        fin >> a >> b;
        while(b!=0)
        {
            int r = a % b;
            a = b;
            b = r;
        }
        fout << a << endl;
    }
    return 0;
}
