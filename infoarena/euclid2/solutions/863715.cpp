#include<fstream>
#include<stdio.h>
using namespace std;
int a,b,c,T,i;
int main()
{
ifstream cin("euclid2.in");
ofstream cout("euclid2.out");
    cin>>T;
    for(i=1;i<=T;++i)
    {
        cin>>a>>b;
        if(b>a)
        {
            c=a;
            a=b;
            b=c;
        }
        while(b!=0)
        {
            c=a;
            a=b;
            b=c%a;
        }
        cout<<a<<endl;
    }
    return 0;
}
