#include <fstream.h>
#include <math.h>

int matr[1001][1001], cul[1000][4];
int m, n, i, j,vf,k,cnt,ii,jj, iii, jjj;

char c;

char cautadir(char m){
		if(abs(matr[ii+1][jj])==abs(matr[ii][jj])&&m!='S')
			return 'S';
		if(abs(matr[ii-1][jj])==abs(matr[ii][jj])&&m!='N')
			return 'N';
		if(abs(matr[ii][jj+1])==abs(matr[ii][jj])&&m!='E')
			return 'E';
		if(abs(matr[ii][jj-1])==abs(matr[ii][jj])&&m!='V')
			return 'V';
		return '0';}

void deplaseaza(char m){
	switch(m){
	case 'N': 
		ii--;
		break;
	case 'S':
		ii++;
		break;
	case 'E':
		jj++;
		break;
	case 'V':
		jj--;}
}

bool verifica(char m){
	switch(m){
	case 'N': 
		if(abs(matr[ii-1][jj])==abs(matr[ii][jj]))
			return 1;
		break;
	case 'S':
		if(abs(matr[ii+1][jj])==abs(matr[ii][jj]))
			return 1;
		break;
	case 'E':
		if(abs(matr[ii][jj+1])==abs(matr[ii][jj]))
			return 1;
		break;
	case 'V':
		if(abs(matr[ii][jj-1])==abs(matr[ii][jj]))
			return 1;}
	return 0;}
	
		
		
	

main(){
	freopen("pictura.in", "r", stdin);
	freopen("pictura.out", "w", stdout);
	scanf("%d%d", &m, &n);
	for(i=1;i<=m;i++){
		for(j=1;j<=n;j++){
			scanf("%d", &matr[i][j]);
			if(matr[i][j]!=0&&cul[matr[i][j]][0]==0){
				cul[matr[i][j]][0]=1;
				k++;}}}
	
	for(i=1;i<=m;i++){
		for(j=1;j<=n;j++)
			if(matr[i][j]!=0&&matr[i][j-1]==matr[i][j]&&matr[i][j+1]==matr[i][j]&&matr[i-1][j]==matr[i][j]&&matr[i+1][j]==matr[i][j]){
				cul[matr[i][j]][3]++;
				matr[i][j]=-1*matr[i][j];}}
	
			
	for(i=1;i<=m;i++){
		for(j=1;j<=n;j++){
			if(matr[i][j]!=0){
				ii=i;
				jj=j;
				c='0';
				c=cautadir(c);
				cul[matr[ii][jj]][1]++;
				if(matr[ii][jj]>0)
					matr[ii][jj]=0;
				else
					matr[ii][jj]=-1*matr[ii][jj];
				while(c!='0'){
					deplaseaza(c);
					vf=verifica(c);					
					if(vf==0)
						c=cautadir(c);
					if(c!='0'&&vf==0)
						cul[matr[ii][jj]][2]++;
					if(matr[ii][jj]>0)
						matr[ii][jj]=0;
					else
						matr[ii][jj]=-1*matr[ii][jj];}}}}
	printf("%d\n",k);
	for(cnt=1,i=1;cnt<=k;i++){
		if(cul[i][0]==1){
			printf("%d %d %d\n", cul[i][1], cul[i][2], cul[i][3]);
			cnt++;}}
	
					
}
		
		
				
				
				
	
		
	