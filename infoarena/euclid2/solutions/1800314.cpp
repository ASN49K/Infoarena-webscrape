#include <iostream>
#include <stdlib.h>
#include <math.h>
using namespace std;
int a,b,T,i;
int main()
{

    cout<<"Dati nr-ul de perechi:"<<endl;
    cin>>T;
    for(i=1;i<=T;i++)
    {
        cin>>a;cout<<endl;
        cin>>b;cout<<endl;
        while(a!=b)
        {
            if(a>b)
              a=a-b;
             if(a<b)
                b=b-a;

        }
        cout<<"Cmmdc este:"<<a<<endl;
    }
}
