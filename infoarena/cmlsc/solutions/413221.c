#include <stdio.h>
#include <stdlib.h>

#define INT_S  sizeof(int)
#define CHAR_S sizeof(char)
#define nill -1 

#define max(a, b) a > b ? a : b
int c[1024][1024], x[1024], y[1024];

/*
 * determina lungimea maxima a subsecventei / subsecventelor cumune
 */
int lcs_len(int* x, int* y, int i, int j) {
// caz banal - unul dintre siruri este vid => lungimea este 0
    if (i == nill || j == nill) {
    return 0;
    }
    
    // daca s-a mai calculat, se intoarce rezultatul calculat, stocat
    // int tabela reprezentata prin matricea c
    if (c[i][j] == nill) {  
       if(x[i] == y[j])  
               c[i][j] = lcs_len(x, y, i - 1, j - 1) + 1;
       else
               c[i][j] = max(lcs_len(x, y, i, j - 1), lcs_len(x, y, i - 1, j));
    }
    return c[i][j];

}

/*
* determina o subsecventa de lungime maxima, avand tabela cu lungimile
* tuturor subsecventelor comune de lungime maxima ale tuturor prefixelor
* sirurilor x si y
*/
void lcs(int* x, int* y, int i, int j) {

     if (c[i][j] == 0 || i == nill || j == nill)  
        return;
        
    if (x[i] == y[j]) {
             lcs(x, y, i - 1, j - 1);
             printf("%d ", x[i]);
             return;
    }

    if (i)
        if (c[i-1][j] > c[i][j - 1])
           lcs(x, y, i - 1, j);
        else
           if (j)
              lcs(x, y, i, j - 1);
           else
               lcs(x, y, i - 1, j);


}

int main() {
    freopen("cmlsc.in", "r", stdin);
    freopen("cmlsc.out", "w", stdout);
    int
        m, // lungimea primului sir
        n, // lungimea celui de-al doilea sir
        i,j;

    scanf("%d %d\n", &m, &n); 
    for (i = 0; i < m; i++)
        scanf("%d ", x + i);
    for (i = 0; i < n; i++)
        scanf("%d ", y + i);
    for (i = 0; i < m; i++) {
        for (j = 0; j < n; j++)
            c[i][j] = nill;
    }
    int len = lcs_len(x, y, m - 1, n - 1);
    printf("%d\n", len);
    lcs(x, y, m - 1, n - 1);
    return 0;
}
