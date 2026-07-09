#include <iostream>
#include <fstream>

using namespace std;
int div(int a,int b)
{

   if(a>b)
   {
       return a%b;
   }
   else
    return b%a;

}
int main()
{int a,b;
cin>>a>>b;
cout<<div(a,b);




    return 0;
}
