#include<bits/stdc++.h>
using namespace std;

ifstream in("cmlsc.in");
ofstream out("cmlsc.out");

// 1 7 3 9 8    a=5
// 7 5 8        b=3

// 0 0 0 0 0
// 0 0 0 0 0
// 0 0 0 0 0
// 0 0 0 0 0 
// 0 0 0 0 0

vector<int> LCS(vector<vector<int>>C, vector<int> a, vector<int> b, int x, int y)
{
    if (x == 0 | y == 0)
        return {};
        
    else if (a[x - 1] == b[y - 1]){
        vector<int>k=LCS(C, a, b, x - 1, y - 1);
        k.push_back(a[x-1]);
        return k;
    }
    
    else if (C[x][y - 1] > C[x - 1][y])
        return LCS(C, a, b, x, y - 1);
        
    else return LCS(C, a, b, x - 1, y);
}

void ConstructC(&C, vector<int> a, vector<int> b, int m, int n){
	for (int i = 0; i <= m; i++)
		C[i][0] = 0;
	for (int j = 0; j <= n; j++)
		C[0][j] = 0;
	for (int i = 1; i <= m; i++)
		for (int j = 1; j <= n; j++)
		{
			if (a[i - 1] == b[j - 1])
				C[i][j] = C[i - 1][j - 1] + 1;
			else
				C[i][j] = max(C[i][j - 1], C[i - 1][j]);
		}
	return C[m][n];
}

int main(){
    int m, n;
    in>>m>>n;
    vector<int> a(m);
    vector<int> b(n);
    for(int i=0;i<m;i++){
        in>>a[i];
    }
    for(int i=0;i<n;i++){
        in>>b[i];
    }
    
    vector<vector<int>> C(m, vector<int>(n, 0));
    ConstructC(C, a, b, m, n);
    
    vector<int>rasp=LCS(C, a, b, m, n);
    
    for(int i=0;i<size(rasp);i++){
        out<<rasp[i]<<" ";
    }
}

