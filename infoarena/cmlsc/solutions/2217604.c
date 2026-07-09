#include<stdio.h>
#include<stdlib.h>

short min(short a, short b){
  return a>b ? b : a;
}
short max(short a, short b){
  return a<b ? b : a;
}


int main(){

  FILE *f = fopen("cmlsc.in","r");
  FILE *g = fopen("cmlsc.out","w");

  short m,n,*a,*b,*c,mn;
  fscanf(f,"%hd %hd\n",&m,&n);
  mn = min(n,m);
  a = malloc(m*sizeof(short));
  b = malloc(n*sizeof(short));
  c = malloc(mn*sizeof(short));

  short i,j,**db = malloc(m * sizeof(short *));
  
  for (i = 0; i < m; i++) {
    db[i] = calloc(n, sizeof(int));
  }
  
  for(i=0;i<m;i++){
    fscanf(f,"%hd ",a+i);
  }
  for(i=0;i<n;i++){
    fscanf(f,"%hd ",b+i);
  }
  short q=0;
  for(i=0;i<n;i++){
    if(a[0]==b[i]){
      q=1;
    }
    db[0][i]=q;
  }
  short ff,maxn=-1,maxi,maxj;
  for(i=1;i<m;i++){
    q = db[i-1][0];
    for(j=0;j<n;j++){
      if(a[i]==b[j]){
	db[i][j] = db[i-1][j] + 1;
	q = db[i][j];
	if(maxn<q){
	  maxn = q;
	  maxi=i;
	  maxj=j;
	}
      }else{
	q = max(db[i-1][j],q);
	db[i][j]=q;
      }
    }
    
  }
  /*
  for (i=0;i<m;i++){
    for(j=0;j<n;j++){
      printf("%hd ",db[i][j]);
    }
    printf("\n");
  }
  */
  ff=maxn;
  fprintf(g,"%hd\n",maxn);

  c[--maxn] = a[maxi];
  j = maxj;
  for(i=maxi-1;i>=0;i--){
    for(;j>0;j--){
      if(db[i][j-1]<db[i][j]){
	if(i==0 || db[i][j]>db[i-1][j]){
	  c[--maxn] = a[i];
	  break;
	}else{
	  break;
	}
      }
    }
    if(j==0 && maxn){
      for(;i>0;i--){
	if(db[i][j]!=db[i-1][j])
	  break;
      }
      c[--maxn] = a[i];
    }
  }
  
  for(i=0;i<ff;i++){
    fprintf(g,"%hd ",c[i]);
  }
  
  return 0;
}
