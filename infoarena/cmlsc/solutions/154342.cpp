#include <stdio.h>


int m, n;
int a[1025], b[1025], mat[1025][1025], s[1025];
int l;

void read(){
scanf("%d %d", &n, &m);
    for (int i = 1; i <= n; i++)
	scanf("%d", &a[i]);
    for (int i = 1; i <= m; i++)
	scanf("%d", &b[i]);

}

void write () {
    freopen("cmlsc.out", "w", stdout);
    printf("%d\n", l);
    for (int i = l - 1 ; i >= 0; i--)
	printf("%d ", s[i]);
}

int maxim(int a, int b) {
    if(a>b) return a;
	return b;
}

void subsir() {
    for (int i = 1; i <= n; i++)
	for (int j = 1; j <= m; j++)
	    mat[i][j] =  (a[i] == b[j]) ? 1 + mat[i-1][j-1] : maxim(mat[i-1][j], mat[i][j-1]);
    int  i = n, j = m;
    for (; i > 0; ) {
	if (a[i] == b[j]) {
	    s[l++] = a[i--];
	    j--;
	    continue;
	}
	if (mat[i-1][j] < mat[i][j-1]) {
		j--;
		continue;
	}
	i--;
    }

}
int main()
{
freopen("cmlsc.in", "r", stdin);
freopen("cmlsc.out", "w", stdout);
	read();
    subsir();
    write();






    return 0;
}
