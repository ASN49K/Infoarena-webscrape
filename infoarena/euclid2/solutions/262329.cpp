   1. #include <stdio.h>  
   2. int main()  
   3. {  
   4.     int a,b,t;  
   5.     freopen("euclid2.in","r",stdin);  
   6.     freopen("euclid2.out","w",stdout);  
   7.     scanf("%d",&t);  
   8.     for (int i=1 ; i<=t ; ++i)  
   9.     {  
  10.         scanf("%d%d",&a,&b);  
  11.         while (a!=b)  
  12.             if (a>b)   
  13.                 a-=b;  
  14.             else  
  15.                 b-=a;  
  16.         printf("%d\n",a);  
  17.     }  
  18.     return 0;  
  19. }  