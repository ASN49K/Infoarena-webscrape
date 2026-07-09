#include <iostream>
#include <fstream>

using namespace std;

int main ()
{
    ifstream cin("euclid2.in");
    ofstream cout("euclid2.out");
    int a, b, r;
    cin>>a>>b;
    while(b)
    {
        r=a%b;
        a=b;
        b=r;
    }
    
    cout<<a;
    return 0;
}