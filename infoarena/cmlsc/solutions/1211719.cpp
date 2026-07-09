#include <iostream>
#include <stdio.h>
using namespace std;

int table[1024 + 10][1024 + 10],a[1024],b[1024],n,m;

void get_lcs(){
	for(int i = 0; i < n; i++){
		for(int j = 0; j < m; j++){
			if(a[i] == b[j]){
				table[i + 1][j + 1] = table[i][j] + 1 ;
			}
			else
				table[i + 1][j + 1] = max(table[i][j + 1], table[i + 1][j]);
		}
		
	}
	int maxim = 0;
	for(int i = 0; i <= m; i++)
		maxim = maxim < table[n][i] ? table[n][i] : maxim;
	cout<<maxim<<'\n';
	int k = 0,*v = new int[max(n,m)];
	int i = n, j = m;
    while ( (i > 0) && (j > 0) ) {
        if (table[i][j] == table[i-1][j])  
			i--;
        else if (table[i][j] == table[i][j-1]) 
			j--;
        else {
            v[k++] = a[i-1];
            i--; j--;
        }
    }
	for(i = k - 1; i >= 0; i--) 
		printf("%d ",v[i]);
}

int main(){
	freopen("cmlsc.in","r",stdin);
	freopen("cmlsc.out","w",stdout);
	scanf("%d%d",&n,&m);
	for(int i = 0; i < n; i++)
		scanf("%d",&a[i]);
	for(int i = 0; i < m; i++)
		scanf("%d",&b[i]);
	get_lcs();

	return 0;
}