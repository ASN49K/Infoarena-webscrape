#include<iostream.h>
main()
{
 unsigned long t, a, b, c, r;
 cin>>t;
 while(t)
   {cin>>a>>b;
    if(2<=a && 2<=b)
      {r=a%b;
	   while(r) 
         {a=b; b=r;
            r=a%b;
         }
      cout<<b<<endl;
	  }
        else cout<<"Date incorecte"<<endl;
    t--;
	}
}
     
