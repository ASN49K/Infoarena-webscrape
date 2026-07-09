#include <iostream>
#include <fstream>
using namespace std;

int main()
{
    ifstream in("euclid2.in");
    ofstream out("euclid2.out");
    int a, b, n,i,c;
    in>>n;
    for (i=1; i<=n; i++)
    {
        in>>a>>b;
        while (b!=0)
        {
            c=a%b;
            a=b;
            b=c;
        }
        out<<a<<endl;
    }
    return 0;
}
