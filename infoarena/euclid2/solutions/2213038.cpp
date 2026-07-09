#include <iostream>
#include <fstream>
using namespace std;

int a,b,n,r;

ifstream f("euclid2.in");
ofstream g("euclid2.out");

int main()
{   cin>>n;
    f>>n;
    for(int i=1; i<=n; i++)

    {

     f>>a>>b;
cin>>a>>b;
            while(a%b==0)
        {   r=a%b;
            a=b;
            b=r;
        }
        g<<b<<endl;
        cout<<b<<endl;
        }




    return 0;
}
