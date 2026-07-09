#include <iostream>
#include <fstream>

using namespace std;
int div(int a,int b)
{

    while(a!=b)
    {

        if(a>b)
        {
            a=a-b;
        }
        else
        {
            b=b-a;
        }
    }
    return a;
}
int main()
{int a,b,n;
ifstream f("euclid2.in");
f>>n;
cin >>n;
    for(int i=1;i<=n;i++)
    {
        f>>a>>b;
        cin>>a>>b;
        ofstream g("euclid2.out");
        g<<div(a,b);
       cout<< div(a,b);
    }


    return 0;
}
