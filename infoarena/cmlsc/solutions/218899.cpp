   1. #include <fstream.h>  
   2. short int a[1024],b[1024],x[1024],l[1024][1024],i,j,n,m,k;  
   3.   
   4.   
   5. int main()  
   6. {  
   7.  ifstream fin("cmlsc.in");  
   8.  fin>>n>>m;  
   9.  for(i=1;i<=n;i++)  
  10.   fin>>a[i];  
  11.  for(i=1;i<=m;i++)  
  12.   fin>>b[i];  
  13.  fin.close();  
  14.   
  15.  for(i=1;i<=n;i++)  
  16.   for(j=1;j<=m;j++)  
  17.    if(a[i]==b[j])  
  18.     l[i][j]=l[i-1][j-1]+1;  
  19.    else  
  20.     if(l[i-1][j]>l[i][j-1])  
  21.      l[i][j]=l[i-1][j];  
  22.     else  
  23.      l[i][j]=l[i][j-1];  
  24.   
  25.  k=l[n][m];  
  26.  i=n; j=m;  
  27.  while(k!=0)  
  28.   if(a[i]==b[j])  
  29.   {  
  30.    x[k]=a[i];  
  31.    k--; i--; j--;  
  32.   }  
  33.   else  
  34.    if(l[i][j]==l[i][j-1])  
  35.     j--;  
  36.    else  
  37.     i--;  
  38.   
  39.  ofstream fout("cmlsc.out");  
  40.  fout<<l[n][m]<<'\n';  
  41.  for(i=1;i<=l[n][m];i++)  
  42.   fout<<x[i]<<" ";  
  43.   
  44.  return 0;  
  45. }  
