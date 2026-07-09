#include <iostream>
#include <fstream>

using namespace std;

ifstream in("euclid2.in");
ofstream out("euclid2.out");

int cmmdc(int a, int b)
{
    if(1 > b)
    {
        return a;
    }
    else
    {
        return cmmdc(b, a % b);
    }
}
int main()
{
    int n, a, b;
    in >> n;
    for(int i = 0;i < n;i++)
    {
        in >> a>> b;
        out << cmmdc(a, b)<< endl;

    }
    return 0;
}
