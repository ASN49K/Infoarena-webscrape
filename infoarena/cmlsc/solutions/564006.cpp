#include<stdio.h>

FILE *in=fopen("cmlsc.in", "r");
FILE * out=fopen("cmlsc.out", "w");

int n, m, a[1024], b[1024], d[1024][1024], sir[1024], bst, i, j;

int mx(int a, int b){
if(b>a)return b;
return a;
}

int main(){
fscanf(in, "%d%d", &n, &m);
for(i=1;i<=n;i++)fscanf(in, "%d", &a[i]);
for(i=1;i<=m;i++)fscanf(in, "%d", &b[i]);
for(i=1;i<=n;i++)
for(j=1;j<=n;j++)
{if(a[i]==b[j])d[i][j]=d[i-1][j-1]+1;
else d[i][j]=mx(d[i-1][j], d[i][j-1]);
}
for(i=n,j=m;i&&j;){
	if(a[i]==b[j]){sir[++bst]=a[i];i--;j--;}
	else {if(d[i][j-1]<d[i-1][j])i--;
	else j--;
	}
}
fprintf(out, "%d\n", bst);
for(i=bst;i;i--)fprintf(out, "%d ", sir[i]);
fclose(in);fclose(out);
return 0;
}