#include <iostream>
#include <fstream>

using namespace std;
int gcd(int a,int b)
{
    if(b==0)
        return a;
    else return gcd(b,a%b);
}

int main()
{
    ifstream f("euclid2.in");
    ofstream g("euclid2.out");
    int i,n,a,b;
    f>>n;
    for(i=0;i<n;i++)
    {
        f>>a>>b;
        cout<<gcd(a,b)<<endl;
    }
}
