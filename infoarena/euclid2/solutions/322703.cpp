#include<iostream.h>

int main()
{
int n,i,j,r,a[20][20],rr,cmmdc,aux;
cout<<"n=";cin>>n;
cout<<"elem mat:";
for(i=0;i<n;i++)
   for(j=0;j<n;j++)
	   cin>>a[i][j];
for(i=0;i<n;i++)
  { for(j=0;j<n;j++)
		cout<<a[i][j]<<" ";
		cout<<endl;}
cout<<endl;
cout<<endl;
for(j=0;j<n;j++)
   { 
	 for(r=1,i=0;i<n-1;i++)
	 {
		while(r)
		{
			if(a[i][j]>a[i+1][j])
			{
				r=a[i][j]%a[i+1][j];
				a[i][j]=a[i+1][j];
				a[i+1][j]=r;
				cmmdc=a[i][j];
			}
			else
			{
				r=a[i+1][j]%a[i][j];
				a[i+1][j]=a[i][j];
				a[i][j]=r;
				cmmdc=a[i+1][j];
			}
		}
		if(a[i+2][j]>cmmdc)
			{
			a[i+1][j]=a[i+2][j];
			a[i+2][j]=cmmdc;
			}
		else
			a[i+1][j]=cmmdc;
		
	}
		
	  cout<<cmmdc<<" ";
   }
   return 0;

}
