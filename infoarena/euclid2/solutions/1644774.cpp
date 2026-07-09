#include <iostream>
#include <fstream>
using namespace std;
ifstream f("euclid2.in");
ofstream o("euclid2.out");
int main()
{
    long long n,a ,b,r;
    f >> n;
    for(int i = 1; i <= n;i++)
    {
        f >> a >> b;
        if(a < b)
        {
            int aux = a;
            a = b; b = aux;
        }
        while(b != 0)
        {
            r = a % b;
            a = b;
            b = r;
        }
        o << a << endl;
    }

    return 0;
}
