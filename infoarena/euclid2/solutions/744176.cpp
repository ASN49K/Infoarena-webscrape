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
    if(b == 1)return 0;
    return b;
}
int main()
{
    ifstream in("euclid2.in");
    ofstream out("euclid2.out");
    int a,b;
    in >> a >> b;
    if(a>b) out << divz(a,b);
    else out << divz(b,a);
    in.close();
    out.close();
    return 0;
}
