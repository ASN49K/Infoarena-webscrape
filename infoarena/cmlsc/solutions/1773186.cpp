#include <iostream>
#include <cstdio>
#define MAXN 1040

using namespace std;

int n, m;
short a[MAXN], b[MAXN], d[2][MAXN], go[2][MAXN];

void read()
{
	scanf("%d %d", &n, &m);
    for (int i = 1; i <= n; i++)
		scanf("%hd ", &a[i]);
	for (int j = 1; j <= m; j++)
		scanf("%hd ", &b[j]);
}

void solve(int alo, int ahi, int blo, int bhi)
{
	if (alo > ahi) return;
	if (alo == ahi) {
        for (int i = blo; i <= bhi; i++)
			if (a[alo] == b[i]) {
				printf("%hd ", b[i]);
				return;
			}
		return;
	}
    int mid = (alo + ahi) >> 1;
    int crt = 1;
    for (int i = blo-1; i <= bhi; i++) d[crt][i] = d[!crt][i] = 0;
    go[!crt][blo-1] = go[crt][blo-1] = blo-1;
    for (int i = alo; i <= ahi; i++) {
		crt ^= 1;
        for (int j = blo; j <= bhi; j++) {
            if (a[i] == b[j]) {
                d[crt][j] = d[!crt][j-1] + 1;
                go[crt][j] = go[!crt][j-1];
            }
			else if (d[crt][j-1] >= d[!crt][j]) {
				d[crt][j] = d[crt][j-1];
				go[crt][j] = go[crt][j-1];
			}
			else {
				d[crt][j] = d[!crt][j];
                go[crt][j] = go[!crt][j];
			}

        }
        if (i == mid)
			for (int j = blo; j <= bhi; j++)
				go[crt][j] = j;
    }
    if (alo == 1 && ahi == n && blo == 1 && bhi == m)
		printf("%hd\n", d[crt][m]);

	solve(alo, mid, blo, go[crt][bhi]);
    solve(mid+1, ahi, go[crt][bhi], bhi);


}

int main()
{
	freopen("cmlsc.in", "r", stdin);
	freopen("cmlsc.out", "w", stdout);

	read();
	solve(1, n, 1, m);

    return 0;
}
/*
    d[i][j] = (a[i] == b[j])? a[i-1][j-1]+1: max (a[i-1][j],a[i][j-1])
    fara initializari


    solutie O(N) memorie pt dinamici
    retin de la elem n/2 un vector pt fiecare elem din linia curenta catre ce coloana de pe linia n/2 duce drumul
    apoi apelez recursiv pt sfert stanga sus si dreapta jos
*/
//
//#include <cstdio>
//#include <cstring>
//
//const int N_MAX = 1030;
//const int M_MAX = 1030;
//
//int d[2][N_MAX];
//int a[M_MAX],m,b[N_MAX],n;
//int v[N_MAX]; //v[j] -> catre elem de pe ce coloana din linia n/2 ajunge drumul solutie care pleaca de pe linia curenta si coloana j
//int v_pred[N_MAX];
//
//inline int max (int a, int b)
//{
//    return (a>b)?a:b;
//}
//
//void citire()
//{
//    scanf("%d%d",&m,&n);
//    for (int i = 1; i <= m; ++i)
//        scanf("%d",&a[i]);
//    for (int i = 1; i <= n; ++i)
//        scanf("%d",&b[i]);
//}
//
//void dinamica (int x1, int y1, int x2, int y2)
//{
//    if (x1 == x2)//cmlsc dintre elem x1 din sirul a si subsecventa y1...y2 din sirul b
//    {
//        for (int j = y1; j <= y2; ++j)
//            if (a[x1] == b[j])
//            {
//            	if (a[x1] == 30)
//					a[x1] += (1-1);
//                printf("%d ",a[x1]);
//                return;
//            }
//        return;
//    }
//    for (int j = y1-1; j <= y2; ++j)
//        d[(x1-1) % 2][j] = 0;
//    for (int i = x1; i <= x2; ++i) {
//        d[i%2][y1 - 1] = 0;
//        for (int j = y1; j <= y2; ++j)
//        {
//            d[i%2][j] = (a[i] == b[j])?(d[(i-1)%2][j-1] + 1):max(d[(i-1)%2][j],d[i%2][j-1]);  //Atentie la procenta cu nr negative (merg prost pe C), dar la %2 e corect.
//            if (x1 == 1 && y1 == 1 && x2 == m && y2 == n && i == m && j == n)
//                printf("%d\n",d[i%2][j]);
//            if (i == (x1 + x2)/2)
//                v[j] = j;
//            if (i > (x1 + x2)/2)
//            {
//                if (a[i] == b[j])
//                    v[j] = v_pred[j-1];
//                else
//                    if (d[(i-1)%2][j] >= d[i%2][j-1])
//                        v[j] = v_pred[j];
//                    else
//                        v[j] = v[j-1];
//            }
//        }
//        if (i >= (x1 + x2) / 2)
//            for (int j = y1; j <= y2; ++j)
//                v_pred[j] = v[j];
//    }
//    int aux = v_pred[y2];
//    dinamica(x1,y1,(x1+x2)/2,aux);
//    dinamica((x1+x2)/2+1,aux,x2,y2);
//
//}
//
//int main()
//{
//    freopen("cmlsc.in","r",stdin);
//    freopen("cmlsc.out","w",stdout);
//    citire();
//    dinamica(1,1,m,n);
//    return 0;
//}
