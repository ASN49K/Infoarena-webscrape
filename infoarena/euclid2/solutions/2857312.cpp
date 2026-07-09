#include <iostream>
#include <fstream>

using namespace std;

ifstream fin("euclid2.in");
ofstream fout("euclid2.out");

int main()
{
    int a, b, n;

    fin >> n;
    for(int i= 0;i<n;i++)
    {
        fin >> a >> b;
        if(a == 0 or b == 0)
            fout << 0 << endl;
        else
            {
                while(b!=0)
                {
                    int mentes=a;
                    a = b;
                    b = mentes % a;
                }
                fout << a <<'\n';
            }
    }
    return 0;
}
