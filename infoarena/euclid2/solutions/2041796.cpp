#include <iostream>
#include <fstream>
using namespace std;

int main()
{
    int n;
    int a, b;
    ifstream be("euclid2.in");
    be>>n;
    ofstream ki("euclid2.out");
    for(int i = 0; i < n; i++)
    {
        be>>a>>b;
        while(a)
        {
            if(a < b)
                swap(a,b);
            a = a % b;
        }
        ki<<b<<"\n";
    }

    return 0;
}
