 #include<stdio.h> 
  int a,b,i,n ; FILE *f,*t ;
 main() {
   t=fopen("euclid2.out","w") ; 
   f=fopen("euclid2.in","r") ; fscanf(f,"%d",&n) ; 
    for(i=1 ; i<=n ; i++) { fscanf(f,"%d%d",&a,&b) ; 
         while ((a!=0) && (b!=0)) 
       if (a>b) a=a%b ; else b=b%a ;  
         if (b!=0) a=b ; fprintf(t,"%d\n",a) ;     }
   fclose(f) ;  fclose(t) ; return 0 ;        
}
  
