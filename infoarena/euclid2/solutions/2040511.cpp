#include <iostream>
#include <fstream>
using namespace std;

int main()
{
    ifstream f("euclid2.in");
    ofstream g("euclid2.out");
    int a,b,a1,b1,i,n;
    f>>n;
    for(i=1;i<=n;i++)
    {
        f>>a>>b;
        a1=a;
        b1=b;
        while(a1!=b1)
        {
            if(a1>b1)
                a1=a1-b1;
            else
                b1=b1-a1;
        }
        g<<a1<<" "<<endl;
    }
    return 0;
}
