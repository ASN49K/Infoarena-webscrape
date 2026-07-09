#include<stdio.h>
#include<algorithm>
long n,m,a[1034],b[1034],l[1034][1034];
FILE*f=fopen("cmlsc.in","r"),*g=fopen("cmlsc.out","w");

using namespace std;

 void citire(){
	fscanf(f,"%ld %ld ",&n,&m);
	for(long i=1;i<=n;i++){
	   fscanf(f,"%ld ",&a[i]);
	}
	for(long i=1;i<=m;i++){
	   fscanf(f,"%ld ",&b[i]);
	}
	fclose(f);
 }

void determinare_cmlsc(){
    for(long i=1;i<=n;i++){
	   for(long j=1;j<=m;j++){
	      if(a[i]==b[j]){
		    l[i][j]=l[i-1][j-1]+1;
		  }
		  else{
		    l[i][j]=max(l[i-1][j],l[i][j-1]);
		  }
	   }
	}
	fprintf(g,"%ld\n",l[n][m]);
}
 
void afisare(long i,long j){
  if(i!=0&&j!=0){
	if(a[i]==b[j]){
	  afisare(i-1,j-1);
	  fprintf(g,"%ld ",a[i]);
	}
	else{
	    if(l[i-1][j]>l[i][j-1]){
		  afisare(i-1,j);
		}
		else{
		    afisare(i,j-1);
		}
	}
   }
}

int main(){
citire();
determinare_cmlsc();
afisare(n,m);
return 0;
}