#include <iostream>
#include <fstream>
using namespace std;
ifstream in("cmlsc.in");
ofstream out("cmlsc.out");
int main(){
	short m, n, v[1030], u[1030], i, j, mx, x, p[1030], y;
	in>>m>>n;
	for(i=1; i<=m; i++){in>>v[i];}
	for(i=1; i<=n; i++){in>>u[i];}
	x=1;
	mx=0;
	y=0;
	for(i=1; i<=m; i++){
        for(j=x; j<=n; j++){
            if(v[i]==u[j]){
               mx++;
               y++;
               p[y]=u[j];
               x++;
               break;
            }
        }
	}
	out<<mx<<"\n";
	for(i=1; i<=y; i++)out<<p[i]<<" ";
	return 0;
}
