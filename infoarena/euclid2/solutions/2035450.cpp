#include <iostream>
#include <fstream>

using namespace std;
ifstream in("euclid2.in");
ofstream out("euclid2.out");

int main()
{
    int n,a,b;
    in>>n;
    while(n)
    {
        in>>a>>b;
        int c;
        while (b)
        {
            c = a % b;
            a = b;
            b = c;
        }
        out<<a<<'\n';
        n--;
    }

    return 0;
}
