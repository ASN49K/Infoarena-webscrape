#include <iostream>
#include <fstream>

#define nMax 1025
#define MAX(a,b) (a>b? a:b)

using namespace std;

ifstream fin("cmlsc.in");
ofstream fout("cmlsc.out");

int v1[nMax], v2[nMax], d[nMax][nMax];
int main(){
	int n, m;
	fin>>n>>m;
	for(int i = 1; i <= n; i++){
        fin>>v1[i];
	}
	for(int j = 1; j <= m; j++){
        fin>>v2[j];
	}
	for(int i = 1; i <= n; i++){
        for(int j = 1; j <= m; j++){
            if(v1[i] == v2[j]){
                d[i][j] = d[i - 1][j - 1] + 1;
            }
            else{
                d[i][j]=MAX(d[i][j - 1], d[i - 1][j]);
            }
        }
	}
	cout<<d[n][m];
    int i = n, j = m;
    while(i || j){
        if(v1[i] == v2[j]){
            fout<<v1[i]<<" ";
            i--;
            j--;
        }
        else{
            if(d[i - 1][j] == MAX(d[i][j - 1], d[i - 1][j])){
                i--;
            }
            else{
                j--;
            }
        }
    }
	return 0;
}
