#include <iostream>
#include <fstream>

using namespace std;

int main()
{
    int i, j, t, a, b, c;
    ifstream f("euclid2.in");
    ofstream g("euclid2.out");

    f>>t;
    for(i=1;i<=t;i++)
    {
        f>>a>>b;
        while(b){
            c=a%b;
            a=b;
            b=c;
        }
        g<<a<<"\n";
    }
}
