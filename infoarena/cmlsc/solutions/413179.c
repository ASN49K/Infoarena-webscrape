#include <stdio.h>
#include <stdlib.h>

#define INT_S  sizeof(unsigned char)
#define CHAR_S sizeof(int)
#define T unsigned char
#define nill -1

#define max(a, b) a > b ? a : b


/*
 * determina lungimea maxima a subsecventei / subsecventelor cumune
 */
int lcs_len(T* x, T* y, short i, short j, short **c) {
    // caz banal - unul dintre siruri este vid => lungimea este 0
    if (i == nill || j == nill) 
          return 0;

    // daca s-a mai calculat, se intoarce rezultatul calculat, stocat
    // int tabela reprezentata prin matricea c
    if (c[i][j] == nill) {   
        if(x[i] == y[j])  
                  c[i][j] = lcs_len(x, y, i - 1, j - 1, c) + 1;
        else 
                  c[i][j] = max((lcs_len(x, y, i, j - 1, c)), (lcs_len(x, y, i - 1, j, c)));

    }
    return c[i][j];
}

/*
 * determina o subsecventa de lungime maxima, avand tabela cu lungimile 
 * tuturor subsecventelor comune de lungime maxima ale tuturor prefixelor
 * sirurilor x si y
 */
void lcs(T* x, T* y, short i, short j, short **c, T* r, short p, short len) {
     if (c[i][j] == 0 || i == nill || j == nill)   
        return;
        
     if (x[i] == y[j]) {
              r[len - p++ - 1] = x[i]; // sau y[j]
              i--;
              j--;
     }
     else {
          if (i) {
             if (c[i-1][j] > c[i][j - 1]) {
                i--;
             }
             else {
                  if (j) {
                     j--;
                  }
                  else {
                       i--;
                  }
             }
          }
          
          
     }
     lcs(x, y, i, j, c, r, p, len);
}
     
     
               
    

int main() {
    freopen("cmlsc.in", "r", stdin);
    freopen("cmlsc.out", "w", stdout);
    
    // intrari :
    T
        *x, // primul sir
        *y; // al 2 - lea sir
    short
         m, // lungimea primului sir
         n; // lungimea celui de-al doilea sir
        
    // iesiri
    T
        *r; // subsecventa comunade lungime maxima 
        
    // auxiliare
    short
         i, j,
      ** c;
          
    scanf("%hd %hd\n", &m, &n);
    x = (T*)malloc(m * INT_S);
    y = (T*)malloc(n * INT_S);   
    for (i = 0; i < m; i++)
        scanf("%hd ", x + i);
    for (i = 0; i < n; i++)
        scanf("%hd ", y + i);
    c = (short**)malloc(m * sizeof(short*));
    for (i = 0; i < m; i++) {
        c[i] = (short*)malloc(n * INT_S);
        for (j = 0; j < n; j++)
            c[i][j] = nill;
    }
    int len = lcs_len(x, y, m - 1, n - 1, c);
    printf("%hd\n", len);
    r = (T*)malloc(len * INT_S);
    lcs(x, y, m - 1, n - 1, c ,r , 0, len);
    for (i = 0; i < len; i++)
        printf("%hd ", r[i]);
    return 0;
}
