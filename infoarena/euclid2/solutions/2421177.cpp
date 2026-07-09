#include <iostream>
#include <fstream>
using namespace std;
ifstream f("euclid2.in");
ofstream g("euclid2.out");
int main()
{
    int T, a, b, i;
    cin>>T;
    for(i=1;i<=T;i++)
    {
        cin>>a>>b;
        while(a!=b)
        {
            if(a>b)
                a=a-b;
            else
                b=b-a;
        }
        cout<<a;
    }
    return 0;
}
