#include<iostream.h>
int main()
{
    int a,b,n;
    cout<<"a=";cin>>a;
    cout<<"b=";cin>>b;
    if(a>b)
        while(a%b!=0)
        {n=a%b;
        a=b;
        b=n;}
    else
    if(b>a)
        while(b%a!=0)
        {n=b%a;
        b=a;
        a=n;}
    cout<<n<<endl;
    system("pause");
    return 0;
}
