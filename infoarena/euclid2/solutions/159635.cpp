#include<iostream.h>
#include<stdio.h>
int main()
{
 freopen("euclid2.in","r",stdin);
 freopen("euclid2.out","w",stdout);


 long a,t,b,i,r;
 cin>>t;
 for(i=1;i<=t;i++)
 {
  cin>>a>>b;
  r=a%b;
   while(r!=0)
   {
	a=b;
	b=r;
	r=a%b;
   }
   cout<<b<<endl;

 }

return 0;

}