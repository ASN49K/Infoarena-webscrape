#include <iostream>
#include <conio.h>
using namespace std;

int main()
{
    int a,b;
    cout<<"Introduceti primul numar: "<<endl;
    cin>>a;
    cout<<"Introduceti al doilea numar: "<<endl;
    cin>>b;
    while(a!=0,b!=0)
    {if(a>b)
    {
        a=a-b;
    }
    else
    {
        b=b-a;
    }
    }
    if(a==0)
    {
        cout<<"Cmmdc este: "<<b;
    }
    else
    {
        cout<<"Cmmdc este: "<<a;

    }
getch();
}
