#include<stdio.h>
#include<algorithm>
#include<math.h>
using namespace std;
FILE*f=fopen("cerc3.in","r");
FILE*g=fopen("cerc3.out","w");
int n,x,Max,nrmax,nr;
char viz[2001];
struct punct{int x,y,r;}v[2001],w[2001];	
double dist(int x,int y){return sqrt(x*x+y*y);}
int cmp(punct a,punct b){return dist(a.x,a.y)+a.r<dist(b.x,b.y)+b.r;}
int main(){
	fscanf(f,"%d",&n);
	for(int i=1;i<=n;++i) fscanf(f,"%d%d%d",&v[i].x,&v[i].y,&v[i].r);
	nr=n;
	for(int i=1;i<n;++i){
		if(!viz[i]){
			x=0;
			for(int j=i+1;j<=n;++j){
				if(v[i].x*v[j].y==v[j].x*v[i].y){
					--nr; viz[j]=1;
					if(!x) w[++x]=v[i];
					w[++x]=v[j];
				}
			}
			double l=-80;
			int ll=0;
			sort(w+1,w+x+1,cmp);
			for(int j=1;j<=x;++j)
				if(dist(w[j].x,w[j].y)-w[j].r>l){
					l=dist(w[j].x,w[j].y)+w[j].r; ++ll;
				}
			if(ll>Max){
				Max=ll; nrmax=1;
			}else if(ll==Max) ++nrmax;
			
		}
	}
	fprintf(g,"%d %d %d",nr,Max,nrmax);
	fclose(g);
	fclose(f);
	return 0;
}
