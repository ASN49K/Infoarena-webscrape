#include<stdio.h>
#include<string.h>

int n,m,i,j,max,x[1024][1024],y[1024][1024],maxi,I0,J0,imax,jmax,ma,k;
char a[1024],b[1024],aux;

void cautmax( int i,int j,int &i0,int &j0,int &M)
{ 
     int i1,j1;
     M=-1;
     for(i1=1;i1<i;i1++)
         for(j1=1;j1<j;j1++) if(x[i1][j1]>M) { M=x[i1][j1]; 
                                               i0=i1;
                                               j0=j1;
                                             }
}                                                

int main()
{ 
    freopen("cmlsc.in","r",stdin);
    freopen("cmlsc.out","w",stdout);
    
    scanf("%d %d",&n,&m);
    for(i=1;i<=n;i++) scanf("%d",&a[i]);
    for(i=1;i<=m;i++) scanf("%d",&b[i]);
    
    maxi=20000;                    
   
   for(i=1;i<=m;i++) if(a[1]==b[i]) x[1][i]=1;
   for(i=2;i<=n;i++) if(b[1]==a[i]) x[i][1]=1;
   
   for(i=2;i<=n;i++) 
      for(j=2;j<=m;j++)  if(a[i]==b[j]) { cautmax( i,j,I0,J0,ma);
                                          x[i][j]=ma+1;
                                          y[i][j]=(I0-1)*maxi+J0;
                                          if(ma+1>max) { max=ma+1;
                                                         imax=i;
                                                         jmax=j;
                                                       }
                                         }
                                        
   while(x[imax][jmax]) { b[++k]=a[imax];
                          I0=y[imax][jmax]/maxi+1;
                          J0=y[imax][jmax]%maxi;
                          imax=I0;
                          jmax=J0;
                        }        
  
  printf("%d\n",max);                      
  for(i=k;i>=1;i--) printf("%d ",b[i]);
  printf("\n");
  
  fclose(stdin);
  fclose(stdout);
  return 0;
}                      
                                                                        
                                                   
                                           
                                                       
    
    
