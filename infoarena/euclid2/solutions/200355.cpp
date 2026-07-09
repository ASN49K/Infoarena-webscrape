  #include<stdio.h>  
   long int x,y,t,i;  
   long int cmmdc(long int a, long int b);  
   int main()  
   {   freopen("euclid2.in","r",stdin); freopen("euclid2.out","w",stdout);
	scanf("%ld",&t);
	for(i=1;i<=t;i++)
	{  scanf("%ld%ld",&x,&y);  
           printf("%ld\n",cmmdc(x,y));
	}  
       fcloseall();  
       return 0;  
   }  
   long int cmmdc(long int a, long int b)  
   {    if(!b) return a;  
        return cmmdc(b,a%b);  
   }  