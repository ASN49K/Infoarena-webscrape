#include <iostream>
#include <fstream>
using namespace std;
ifstream in("cmlsc.in");
ofstream out("cmlsc.out");
int main(){
	short m, n, i;
	short v[1025], u[1025], x[1025];
	in>>m>>n;
	for(i=1; i<=m; i++){
        in>>v[i];
	}
	for(i=1; i<=n; i++){
        in>>u[i];
	}
	short j, y;
	y=0;
	for(i=1; i<=m; i++){
        for(j=1; j<=n; j++){
            if(u[j]==v[i]){
                y+=1;
                x[y]=u[j];
                break;
            }
        }
	}
	out<<y<<"\n";
	for(i=1; i<=y; i++){
        out<<x[i]<<" ";
	}
	return 0;
}
