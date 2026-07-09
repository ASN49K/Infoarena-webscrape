#include <bits/stdc++.h>

using namespace std;

ifstream f("cmlsc.in");
ofstream g("cmlsc.out");

int a[1025], b[1025];
int N, M;

void LSCM(){

    int L[N + 1][M + 1];

    for(int i = 0;i <= N;i++)
        for(int j = 0;j <= M;j++){

            if(i == 0 || j == 0) L[i][j] = 0;
            else if(a[i] == b[j]) L[i][j] = L[i - 1][j - 1] + 1;
            else L[i][j] = max(L[i - 1][j], L[i][j - 1]);
        }


    g << L[N][M] << "\n";

    int lscm[1025];
    int LL = L[N][M], i = N, j = M;

    while(i > 0 && j > 0){

        if(a[i] == b[j]){

            lscm[LL] = a[i];
            i--, j--, LL--;
        }
        else if(L[i - 1][j] > L[i][j - 1])  i--;
        else j--;
    }

    for(int i = 1;i <= L[N][M];i++)
    	g << lscm[i] << " ";
    
}

int main(){
	f >> N >> M;
	for(int i = 1;i <= N;i++)
		f >> a[i];
	for(int i = 1;i <= M;i++)
		f >> b[i];

	LSCM();


}