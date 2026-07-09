#include <stdio.h>
#include <math.h>
int cmmdc(int c, int d){
	int ans = 0;
	while ((c!=d)&&(c!=0)&&(d!=0)){
		if(c>d){ c=c-d;}
		else{ d=d-c;}
	}
	if((c==0)||(d==0)){
		ans = 0;
	}else{ans = c;}
	return ans;	
}
int main()
{
	FILE *fp = fopen("euclid2.in", "r");
	FILE *fo = fopen("euclid2.out", "w");
	int t = 0;
	int a = 0;
	int b = 0;
	
	fscanf(fp, "%d", &t);
	int i=0;
	for(i=0;i<t;i++){
		fscanf(fp, "%d", &a);
		fscanf(fp, "%d", &b);
		fprintf(fo, "%d\n",cmmdc(a,b));
	}	
	return 0;
	fclose(fp);	
	fclose(fo);	
}