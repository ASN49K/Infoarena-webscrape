#include<iostream.h>
int main()
{
    int a,b,r,c;
    cout<<"a=";cin>>a;
    cout<<"b=";cin>>b;
    while(a%b!=0)
    {
                 r=a%b;
                 a=b;
                 b=r;
    }
    cout<<b;
    
    system("pause");
    
return 0;    

}
