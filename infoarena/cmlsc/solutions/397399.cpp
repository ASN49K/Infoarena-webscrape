#include<stdlib.h>
#include<stdio.h>

#define max(a,b)  ((a > b) ? a : b) 
#define nmax 1024

int m,n,ct,a[nmax],b[nmax],sir[nmax],l[nmax][nmax],lun;

int main()
{
    int i,j;
    
    freopen("cmlsc.in","r",stdin);
    freopen("cmlsc.out","w",stdout);
    
    scanf("%d %d",&m,&n);
    
    for(i=1;i<=m;i++)
    scanf("%d",&a[i]);
    
    for (i=1;i<=n;i++)
    scanf("%d",&b[i]);
      
    for (i=1;i<=m;i++) 
        for (j=1;j<=n;j++)
        
            if (a[i] == b[j])
           
                           l[i][j] = 1 + l[i-1][j-1];
           else 
                           l[i][j]= max(l[i-1][j],l[i][j-1]);
          
        //for (i=m,j=n;i;)
     i=m;j=n;
     while(i && j)
         if (a[i]==b[j])
         {
            sir[++lun] = a[i];
            --i;
            --j;
            }
         else if (l[i-1][j]<l[i][j-1]) 
            --j;
         else
            --i;
            
        printf("%d\n",lun);
  for (i=lun;i;--i)
        printf("%d ",sir[i]);

return 0;
}                               
