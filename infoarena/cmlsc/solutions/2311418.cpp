#include<cstdio>
#define N 1025
#define M(a,b) (a<b?b:a)
#define L 2000000
unsigned char v[N],s[N][N],x[N],y[N];
int n,m,i=-1,j,k,l;
char p[L];
int A()
{
  	int s=0;
  	for(i++;p[i]>='0';i++)
  		s=s*10+p[i]-48;
  	return s;
}
void S(int b,char c)
{
	char e[100];
	int j;
	for(j=0;b;b/=10,j++)
		e[j]=b%10+48;
	for(j--;j>=0;j--)
		p[k++]=e[j];
	p[k++]=c;
}
int main()
{
    freopen("cmlsc.in","r",stdin),freopen("cmlsc.out","w",stdout),fread(p,1,L,stdin),n=A(),m=A();
    for(j=1;j<=n;j++)
        x[j]=A();
    for(j=1;j<=m;j++)
        y[j]=A();
    for(l=1;l<=n;l++)
        for(j=1;j<=m;j++)
            s[l][j]=(x[l]==y[j]?1+s[l-1][j-1]:M(s[l][j-1],s[l-1][j]));
    while(n)
        if(x[n]==y[m])
            v[++v[0]]=x[n--],m--;
        else
            s[n-1][m]<s[n][m-1]?m--:n--;
    S(v[0],'\n');
    for(i=v[0];i;i--)
    	S(v[i],' ');
    fwrite(p,1,k,stdout);
}
