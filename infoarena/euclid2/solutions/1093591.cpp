#include <iostream>
#include<fstream>
using namespace std;
int sub(int a,int b)
{

    while(a!=b)
    {
        if(a>b)
            a=a-b;
    else
        b=b-a;
    }
    return b;
}
int main()
{
    ifstream f("euclid2.in");
    ofstream g("euclid2.out");
    int t,a,b,i;
    f>>t;
    for(i=1;i<=t;i++)
    {
        f>>a>>b;
        g<<sub(a,b)<<endl;
    }
    return 0;

}
