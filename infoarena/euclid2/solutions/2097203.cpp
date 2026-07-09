#include<iostream>
using namespace std;
int main()
{
 long long a,b,r;
 cin>>a;
 cin>>b;
 if(b==0 && a==0)
     cout<<"-1";
 else if (b==0)
     cout<<a;
 else if (a==0)
     cout<<b;
 else    
 {
     r=a%b;
 while(r)
 {
 a=b;
 b=r;
 r=a%b;
 }
 
 cout<<b;
 }
 return 0;   

}