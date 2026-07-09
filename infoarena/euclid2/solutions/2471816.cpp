#include <iostream>
#include <fstream>
using namespace std;
ifstream fin("euclid2.in");
ofstream fout("euclid2.out");
int t, a, b;
int main()
{
    int c;
    fin>>t;
    while(t!=0)
    {
        fin>>a>>b;
        while (b)
        {
            c = a % b;
            a = b;
            b = c;
        }
       fout<<a<<endl;
        t--;
    }

    return 0;
}
