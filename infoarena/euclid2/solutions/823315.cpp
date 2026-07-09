#include <iostream>
#include <fstream>
using namespace std;
long long int t,a,b;
int main()
{
    ifstream ka("euclid2.in");
    ofstream ki("euclid2.out");
    ka>>t;
    for(int i=1;i<=t;i++)
    {
        ka>>a>>b;
        while(a!=b)
        {
            if(a>b)a=a-b;
            else b=b-a;
        }
        ki<<a<<'\n';
    }
}
