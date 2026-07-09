#include <iostream>
#include <fstream>

using namespace std;

int main()
{
    ifstream in ("nim.in");
    ofstream out ("nim.out");

    int n, t, xor, aux;
    in>>t;
    while(t--)
    {
        xor = 0;
        in>>n;
        for(int i = 0; i < n; ++i)
            {
                in>>aux;
                xor = xor ^ aux;
            }
        if(!xor)
            out<<"NU\n";
        else
            out<<"DA\n";
    }
    return 0;
}
