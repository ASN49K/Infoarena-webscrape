#include<stdio.h>

#define nmax 1030

int c[nmax][nmax];
int a[nmax];
int b[nmax];
int sir[nmax];
int n,m, ct;

void read()
{
     int i;
     freopen("cmlsc.in", "r", stdin);
     freopen("cmlsc.out","w",stdout);
     scanf("%d%d",&m, &n);

     for(i=1;i<=m;++i)
       scanf("%d",&a[i]);
     for(i=1;i<=n;i++)
       scanf("%d",&b[i]);
}


void solve()
{
      int i,j;
      for(i=1;i<=m;++i)
        for(j=1;j<=n;++j)
           if(a[i]==b[j])
              c[i][j]=c[i-1][j-1]+1;
           else
           {
               c[i][j]=c[i-1][j];
               if(c[i][j]<c[i][j-1])
                  c[i][j]=c[i][j-1];
          
          }
      
      i=m;
      j=n;
      while(i>0&&j>0)
      {

	  if(a[i]==b[j])
	  {
	    sir[++ct]=a[i];
	    i--, j--;
	  }
          else
            if(c[i-1][j]>c[i][j-1])
               i--;
            else
	       j--;
      }

        
}
          
void print()
{   
     int i;
     printf("%d\n",c[m][n]);
     for(i=ct; i>=1; --i)
       printf("%d ", sir[i]);
     printf("\n");
}

int main()
{
       read();
       solve();
       print();
       return 0;
}




     
     
