#include <iostream>
#include <fstream>

using namespace std;

fstream fin("euclid2.in");
fstream fout("euclid2.out");

int main()
{
    int a, b, n;

    fin >> n;
    for(int i= 0;i<n;i++)
    {
        fin >> a >> b;

        while(b!=0)
        {
            int mentes=a;
            a = b;
            b = mentes % a;
        }
        fout << a <<'\n';
    }
    return 0;
}
