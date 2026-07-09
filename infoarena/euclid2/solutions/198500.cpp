   #include <stdio.h>  
   int cmmdc(int a, int b)  
   {if (b==0) return(a);  
   return(cmmdc(b,a%b));  
   }  
     
   int main(void)  
   {int n,x,y;  
   freopen("euclid2.in","r",stdin);  
   freopen("euclid2.out","w",stdout);  
   scanf("%d",&n);  
   for (;n;--n)  
   {scanf("%d %d",&x,&y);  
   printf("%d\n",cmmdc(x,y));}  
     
   return(0);  
   }  