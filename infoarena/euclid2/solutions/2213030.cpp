#include <iostream>
#include <fstream>
using namespace std;

int a,b,n;

ifstream f("euclid2.in");
ofstream g("euclid2.out");

int main()
{
    f>>n;
    for(int i=1; i<=n; i++)

    {

     f>>a>>b;

            while(a!=b)
        {   if(a>b)
                a=a-b;
            if(b>a)
                b=b-a;

        }
        g<<b<<endl;
    }




    return 0;
}
