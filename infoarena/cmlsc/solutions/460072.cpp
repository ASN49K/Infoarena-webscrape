#include<iostream.h>
#include<conio.h>
int s, a, v[100]; 

main()
{      cout<<"suma: "; 
       cin>>s;
       cout<<"nr.: ";
       cin>>a;
       for(int i=1;i<=a;i++) cin>>v[i];
       for(int i=1;i<=a;i++)
           for(int j=i+1;j<=a;j++) 
                   if(v[i]>v[j]) 
                   {             int m;
                                 m=v[i];
                                 v[i]=v[j];
                                 v[j]=m;
                   }
       int i=a,c,d=0;
       while((i!=0) || (s!=0) )
       {
                   
           if(s>=v[i]) 
           {           c=s/v[i];
                       s=s-c*v[i];
                       d=d+c;
                       cout<<"s:"<<v[i]<<endl;
           }
           i--;            
       }
       cout<<"nr.min:"<<d;
       
 getch(); 
 return 0;
} 
      
