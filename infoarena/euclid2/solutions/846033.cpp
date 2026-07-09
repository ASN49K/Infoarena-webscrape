#include <stdio.h>

void OpenFiles(int);
int Cmmdc(int,int);

int main(int arg,char *argv[])
{
	OpenFiles(arg);
		int n,x,y;
		scanf("%d",&n);
		while(n--)
		{
			scanf("%d %d",&x,&y);
			printf("%d\n",Cmmdc(x,y));
		}
	return 0;
}

int Cmmdc(int x,int y){
	if(y==0)return x; else return Cmmdc(y,x%y);
}

void OpenFiles(int arg){
	freopen("test.in","r",stdin);
	if(arg==1)
	{
		freopen("test.out","w",stdout);
	}
}
