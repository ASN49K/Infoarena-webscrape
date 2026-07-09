#include <iostream>
#include <fstream>

using namespace std;

ifstream in("euclid2.in");
ofstream out("euclid2.out");

int euclid(int a,int b)
{
    if(!b)
        return a;
    return euclid(b,a%b);
}
int main()
{
    int n;
    in>>n;
    int nr1,nr2;
    for(int i=0;i<n;i++)
    {
        in>>nr1>>nr2;
        out<<euclid(nr1,nr2)<<'\n';
    }
    return 0;
}
