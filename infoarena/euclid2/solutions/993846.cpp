#include <iostream>
#include <fstream>
using namespace std;
ifstream in("euclid2.in");
ofstream out("euclid2.out");
int a,b,n,rest;
int main()
{
    in >> n;
    for(int i=0;i<n;i++)
        {
            in >> a >> b;
            while(b!=0)
            {
                rest=a%b;
                a=b;
                b=rest;
            }
        out << a << "\n";
        }
    return 0;
}
