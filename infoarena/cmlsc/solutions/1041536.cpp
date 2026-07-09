 #include<stdio.h> 
 #define int1 1030
   void G(int,int,int) ;
   int a[int1],b[int1],c[int1],m,i,n,max ; FILE *f ;
  main(){ 
   f=fopen("cmlsc.in","r") ; fscanf(f,"%d%d",&m,&n) ; 
    for (i=1 ; i<=m ; i++) fscanf(f,"%d",&a[i]) ; 
     for (i=1 ; i<=n ; i++) fscanf(f,"%d",&b[i]) ; fclose(f) ; 
     f=fopen("cmlsc.out","w") ;
      G(m,n,0) ; 
     for (i=max-1 ; i>=0 ; i--) fprintf(f,"%d ",c[i]) ; 
        fclose(f) ;
      return 0 ; 
  }
   void G(int x ,int y ,int l) {  
     if ((x!=0) || (y!=0)) { if (l>max) max=l ; 
    if (a[x]==b[y]) {c[l]=a[x] ; G(x-1,y-1,l+1) ; } else
     { if (x>y) G(x-1,y,l) ; if (x<y) G(x,y-1,l) ; 
       if (x==y) { G(x-1,y,l) ; G(x,y-1,l) ; } } } ; }
    
    
