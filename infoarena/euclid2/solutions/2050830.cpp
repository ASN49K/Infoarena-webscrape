#include <iostream>
#include <fstream>

using namespace std;

ifstream in("euclid2.in");
ofstream out("euclid2.out");

int euclid(int a, int b)
{
    int c;
    while (b) {
        c = a % b;
        a = b;
        b = c;
    }
    return a;
}

int main()
{
    int a,b,t;
    in>>t;
    for(int i=0 ; i<t;i++)
    {
       in>>a>>b;
       out<<euclid(a, b);
       out<<"\n";
    }
    return 0;
}
