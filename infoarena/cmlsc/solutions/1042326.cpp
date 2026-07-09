 #include<stdio.h> 
 #define int1 1030
 #define maxim(a, b) ((a > b) ? a : b)
 
   int a[int1],b[int1],d[int1][int1],c[int1],m,i,j,n,x ; FILE *f ;
  main(){ x=1 ; 
    for (i=1 ; i<=1024 ; i++) for (j=1 ; j<=1024 ; j++) d[i][j]=0 ; 
   f=fopen("cmlsc.in","r") ; fscanf(f,"%d%d",&m,&n) ; 
    for (i=1 ; i<=m ; i++) fscanf(f,"%d",&a[i]) ; 
     for (i=1 ; i<=n ; i++) fscanf(f,"%d",&b[i]) ; fclose(f) ; 
    for (i=1 ; i<=m ; i++) for (j=1 ; j<=n ; j++)
     { if (a[i]==b[j])
      d[i][j]=d[i-1][j-1]+1 ; else
      d[i][j]=maxim(d[i-1][j],d[i][j-1]) ;  }      
    f=fopen("cmlsc.out","w") ; fprintf(f,"%d\n",d[m][n]) ;  
   for (i=1 ; i<=m ; i++) for (j=1 ; j<=n ; j++) if (d[i][j]==x) {
    fprintf(f,"%d ",a[i]) ; x++ ; } 
        fclose(f) ;
     return 0 ; 
  }
