 #include<stdio.h>  
    inline int cmd(int a,int b)  
    {  
        if(!b)  
            return a;  
       return cmd(b,a%b);  
    }  
              
    int main()  
   {  
       freopen("euclid2.in","r",stdin);  
       freopen("euclid2.out","w",stdout);  
       int a,b,i,n;  
      scanf("%d",&n);  
      for(i=0;i<n;i++)
	  {scanf("%d%d",&a,&b);
		  if(a==b)  
           {  
               printf("%d\n",a);  
               continue;  
           }  
      printf("%d\n",cmd(a,b));}
     return 0;  
   }  