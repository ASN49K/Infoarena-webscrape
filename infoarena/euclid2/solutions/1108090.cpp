#include <iostream>
#include <fstream>
using namespace std;
int main()
{
    ifstream in("euclid2.in");
    ofstream out("euclid2.out");
    int n,a,b,i;
    in>>n;
    for (i=0;i<n;i++)
    {
        in>>a>>b;
        while(a!=b)
            if(a>b)
                a=a-b;
            else b=b-a;
        out<<b<<'\n';
    }
}
