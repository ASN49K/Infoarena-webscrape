#include<stdio.h>
#include<algorithm>
long n,m,a[1034],b[1034],l[1034][1034],v[10034];
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
			v[0]++;
			v[v[0]]=a[i];
		  }
		  else{
		    l[i][j]=max(l[i-1][j],l[i][j-1]);
		  }
	   }
	}
	fprintf(g,"%ld\n",l[n][m]);
}
 
void afisare(){
    for(long i=1;i<=v[0];i++){
	   fprintf(g,"%ld ",v[i]);
	}
}

int main(){
citire();
determinare_cmlsc();
afisare();
return 0;
}