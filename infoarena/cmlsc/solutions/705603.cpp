#include<fstream> 
using namespace std; 

ifstream in("cmlsc.in"); 
ofstream out("cmlsc.out");  

int d[1024],lcs[1024][1024],n,m,j,k,h,x[1024],y[1024],i; 
 
int main(){    
	in>>n>>m; 
    for(i=1;i<=n;i++) 
		in>>x[i]; 
	for(i=1;i<=m;i++) 
        in>>y[i]; 
    for(i=1;i<=n;i++){ 
		for(int j=1;j<=m;j++) 
            if(x[i]==y[j]) 
                lcs[i][j]=1+lcs[i-1][j-1]; 
            else
                if(lcs[i-1][j]>lcs[i][j-1]) 
                    lcs[i][j]=lcs[i-1][j]; 
                else lcs[i][j]=lcs[i][j-1]; 
    } 
    out<<lcs[n][m]<<'\n'; 
    for(i=0,k=n,h=m;lcs[k][h];) 
        if(x[k]==y[h]){ 
            d[i++]=x[k]; 
            k--; 
            h--; 
		} 
		else if(lcs[k][h]==lcs[k-1][h]) 
			k--; 
			 else h--; 
    for(k=i-1;k>=0;k--) 
        out<<d[k]<<' '; 

return 0;
}