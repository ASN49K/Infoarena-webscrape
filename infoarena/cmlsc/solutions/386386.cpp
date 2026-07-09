#include <stdio.h>
using namespace std;
int main()
{	 int a[100],b[100],n,m,i,c[100];
	FILE *fin = fopen("cmlsc.in","r");
	FILE *fout = fopen("cmlsc.out","w");
	fscanf(fin,"%d",&n);
	for(i=0;i<n;i++)
		fscanf(fin,"%d",&a[i]);
	
	fscanf(fin,"%d",&m);
	for(i=0;i<m;i++)
		fscanf(fin,"%d",&b[i]);
	
	int start1,start2,end1,end2;
	int k,j;
	start1 = start2 = end1 = end2=k=-1;
	for(i=0;i<n;i++)
	{	
		for(j=0;j<m;j++)
			if (a[(k==-1?i:k)] == b[j])
			{
				if (start1 == -1)
					{start1=k; start2=j; k=i;}
				end1 = k;end2=j;
				k++;
			}
			else
			{
				// afisam ce avem pana acuma
				if (start1!=-1){
					int p;
					fprintf(fout,"start1: %d end1: %d \n",start1,end1);						
					fprintf(fout,"start2: %d end2: %d \n",start2,end2);
					for(p=start1;p<=end1;p++)
						fprintf(fout,"%d ",a[p]);
					fprintf(fout,"\n");
					//for(p=start2;p<=end2;p++)
					//	fprintf(fout,"%d ",b[p]);
					//fprintf(fout,"\n");
				}
				start1=start2=end1=end2=-1;
			}
	}	
	 
return 0;
}
