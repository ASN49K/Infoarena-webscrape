#include <iostream>
#include <fstream>

using namespace std;

int main()
{
    int n,a,b,r;
    ifstream in("euclid2.in");
    ofstream out("euclid2.out");
    in>>n;
    while(n!=0)
    {
        in>>a>>b;
        while(b!=0)
        {
            r=a%b;
            a=b;
            b=r;
        }
        out << a <<endl;
        n--;
    }
    return 0;
}
