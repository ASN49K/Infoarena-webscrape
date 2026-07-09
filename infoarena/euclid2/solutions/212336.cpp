// This is the main project file for VC++ application project 
// generated using an Application Wizard.

#include <iostream>
#include <stdio.h>

using namespace std;

int main()
{
	int t,a,b,r,i;
    FILE *f1,*f2;
	f1=fopen("euclid2.in","r");
    f2=fopen("euclid2.out","w");
	fscanf(f1,"%d",&t);
    i=1;
	while(i<=t){
				fscanf(f1,"%d %d",&a,&b);
               while(b!=0){
                           r=a%b;
                           a=b;
                           b=r;
                           };  
               i=i+1;
               fprintf(f2,"%d\n",a);
               };

    fclose(f1);
    fclose(f2);
	return 0;
}