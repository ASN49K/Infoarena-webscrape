#include <iostream>
#include <fstream>

using namespace std;

int main()
{int n,a,b;
    ifstream f("euclid2.in");
    ofstream g("euclid2.out");
    f>>n;cout<<n;
    for(int i=0;i<n;i++)
    {

        f>>a>>b;
        while(a!=b)
        {

            if(a>b)
                a=a-b;
            else
            b=b-a;
        }
        g<<a<<endl;
    }
    return 0;
}
