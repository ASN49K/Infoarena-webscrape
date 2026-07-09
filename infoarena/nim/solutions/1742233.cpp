#include <iostream>
#include <fstream>
using namespace std;
ifstream in("nim.in");
ofstream out("nim.out");
int main()
{
    int t,nr,x,suma;
    in >> t;
    while(t--)
    {
        in >> nr;
        suma = 0;
        for(int i = 0 ; i < nr ; i++)
        {
            in >> x;
            suma ^= x;
        }
        if(suma>0)
            out<<"DA\n";
        else
            out<<"NU\n";
    }
    return 0;
}
