#include <iostream>
#include <fstream>

using namespace std;


int cmmdc(int a,int b)
{
    while(a!=b)//12 != 42  30
    {
        if(a>b)
        {
           a=a-b;
        }
        else
            b=b-a;
    }
    return a;
}


int main()
{ int x,y,n;


cin>>n;
for(int i=1;i<=n;i++)
{

    cin>>x>>y;
    cout<<cmmdc(x,y);
}





    return 0;
}
