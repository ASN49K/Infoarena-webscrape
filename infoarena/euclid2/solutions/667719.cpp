#include<stdio.h>
FILE*f=fopen("immortal.in","r");
FILE*g=fopen("immortal.out","w");
int n,m,I,ok,a[23][23],sol[22][5];
struct one{
	int x;
	int y;
}v[16];
int di[4]={-1,0,1,0};
int dj[4]={0,1,0,-1};
void solutie(){
	ok=1;
	for(int i=I;i>1;--i){
		fprintf(g,"%d %d %d %d\n",sol[i][1],sol[i][2],sol[i][3],sol[i][4]);
	}
}
void back(int nr){
	if (nr==1)
		solutie();
	if(!ok)
		for(int i=1;i<=I;++i)
			if(a[v[i].x][v[i].y])
				for(int j=0;j<4;++j)
					if(a[v[i].x+di[j]][v[i].y+dj[j]]&&!a[v[i].x+2*di[j]][v[i].y+2*dj[j]])
						if((v[i].x+2*di[j]>=1)&&(v[i].y+2*dj[j]>=1)){
							sol[nr][1]=v[i].x;sol[nr][2]=v[i].y;							
							a[v[i].x+di[j]][v[i].y+dj[j]]=0;
							a[v[i].x+2*di[j]][v[i].y+2*dj[j]]=1;
							a[v[i].x][v[i].y]=0;
							v[i].x+=2*di[j];v[i].y+=2*dj[j];
							sol[nr][3]=v[i].x;sol[nr][4]=v[i].y;
							back(nr-1);
							v[i].x-=2*di[j];v[i].y-=2*dj[j];
							a[v[i].x+di[j]][v[i].y+dj[j]]=1;
							a[v[i].x+2*di[j]][v[i].y+2*dj[j]]=0;
							a[v[i].x][v[i].y]=1;
						}

}
int main(){
	fscanf(f,"%d%d%d",&n,&m,&I);
	for(int i=1;i<=I;++i){
		fscanf(f,"%d%d",&v[i].x,&v[i].y);
		a[v[i].x][v[i].y]=1;
	}		
	for(int i=0;i<=n+2;++i)	a[i][0]=a[i][m+1]=a[i][m+2]=1;
	for(int i=0;i<=m+2;++i)	a[0][i]=a[n+1][i]=a[n+2][i]=1;
	back(I);	
	fclose(f);
	fclose(g);
	return 0;
}
