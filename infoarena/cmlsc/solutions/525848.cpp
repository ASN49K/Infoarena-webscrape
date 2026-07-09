#include<stdio.h>
int v[100],u[100],n,m;
int mat[100][100],mav;

void afiseaza(int i,int j){
    if(mat[i][j])
        if(v[i]==u[j]){
            afiseaza(i-1,j-1);
            printf("%d ", v[i]);
        }
    else{
        if(mat[i][j]==mat[i-1][j])
            afiseaza(i-1,j);
        else
            if(mat[i][j]==mat[i][j-1])
                afiseaza(i,j-1);
    }
}


int main(){
    freopen ("cmlsc.in", "r", stdin);
    freopen ("cmlsc.out", "w", stdout);

    int i, j, l;
    scanf("%d %d ", &n, &m);

	for(i=1; i<=n+m; i++){
		if(i<=n)
			scanf("%d ", &v[i]);
		else
			scanf("%d ", &u[i-n]);
	}

	for(i=1; i<=n; i++)
		for(j=1; j<=m; j++)
			if(v[i]==u[j]){
				mat[i][j]=mat[i-1][j-1]+1;
				l=mat[i][j];
			}
			else
				if(mat[i-1][j]>mat[i][j-1])
					mat[i][j]=mat[i-1][j];
				else
					mat[i][j]=mat[i][j-1];

	printf("%d\n", l);

    afiseaza(n,m);
    return 0;
}
