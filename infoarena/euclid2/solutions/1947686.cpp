#include <iostream>
#include <fstream>
using namespace std;
int nr,a,b,c;
int main()
{
    ifstream f("euclid2.in");
    ofstream g("euclid2.out");
    f>>nr;
    for (int i=1;i<=nr;i++)
    {
        f>>a>>b;
        while (b!=0)
        {
            c=a%b;
            a=b;
            b=c;
        }
        g <<a<<"\n";
    }
    return 0;
}
