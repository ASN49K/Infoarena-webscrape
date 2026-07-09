#include<iostream>
#include<fstream>
#include<time.h>
using namespace std;
int main()
{int n1,n2,max,i,j,j1,x1[1024],x2[1024],xmax[1024];
//int t1,t2;
//t1=clock();
ifstream g("cmlsc.in");
g>>n1>>n2; max=0; 
for(i=0;i<n1;i++)
	g>>x1[i];
for(i=0;i<n2;i++)
	g>>x2[i];
j=0; j1=0;
for(i=0;i<n1;i++)
	{while((x1[i]!=x2[j])&&(j<n2))
		  j++;
	if(j<n2)
		{xmax[max]=x2[j];
	     max++;
		 j1=j+1;}
	j=j1;
	}
ofstream t("cmlsc.out");
t<<max<<"\n";
for(i=0;i<max;i++)
	t<<xmax[i]<<" ";
g.close();
t.close();
//t2=clock();
//cout<<(double)(t2-t1)/CLOCKS_PER_SEC;
return 0;}
