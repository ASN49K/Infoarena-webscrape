 #include<stdio.h> 
 #define int1 1030
   int a[int1],b[int1],d[int1][int1],m,i,j,o,p,n ; FILE *f ;
  main(){ 
    for (i=1 ; i<=1024 ; i++) for (j=1 ; j<=1024 ; j++) d[i][j]=0 ; 
   f=fopen("cmlsc.in","r") ; fscanf(f,"%d%d",&m,&n) ; 
    for (i=1 ; i<=m ; i++) fscanf(f,"%d",&a[i]) ; 
     for (i=1 ; i<=n ; i++) fscanf(f,"%d",&b[i]) ; fclose(f) ; 
    for (i=1 ; i<=m ; i++) for (j=1 ; j<=n ; j++)
     { if (a[i]==b[j]) { d[i][j]+=1 ; 
         for (o=i ; o<=m ; o++) for (p=j ; p<=n ; p++) 
     if (d[i][j]>d[o][p]) d[o][p]=d[i][j] ; }}
    f=fopen("cmlsc.out","w") ;   
     fprintf(f,"%d\n",d[m][n]) ; p=1 ; 
    for (i=1 ; i<=m ; i++) for (j=1 ; j<=n ; j++)
      if (d[i][j]==p) { fprintf(f,"%d ",a[i]) ; p+=1 ; }
        fclose(f) ;
      return 0 ; 
  }
