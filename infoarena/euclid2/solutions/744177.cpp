#include <fstream>
#include <iostream>
using namespace std;

int divz(int a,int b)
{
    int r = a % b;
    while(r)
    {
        a = b;
        b = r;
        r = a % b;
    }
    return b;
}
int main()
{
    ifstream in("euclid2.in");
    ofstream out("euclid2.out");
    long long unsigned int a,b;
    unsigned int T;
    in >> T;
    for(int i = 0;i<T;i++)
    {
        in >> a >> b;
        if(a>b) out << divz(a,b) << "\n";
        else out << divz(b,a) << "\n";
    }
    in.close();
    out.close();
    return 0;
}
