#include <stdio.h>
using namespace std;
short int v3[1100];

short int cmlsc(short int n, short int m, short int v1[], 
      short int v2[]) {
     short int poz, poz1, poz2; 
      
     if ((n == 0) || (m == 0)) {
        return 0;   
     }
      
     if (v1[n-1] == v2[m-1]) {
        poz = cmlsc(n-1, m-1, v1, v2);
        v3[poz] = v1[n-1];
        return poz + 1;
     }
     else {
         poz1 = cmlsc(n-1, m, v1, v2);
         poz = cmlsc(n, m-1, v1, v2);
         return poz1 > poz? poz1 : poz;
     }               
}

int main()
{
    FILE* f = fopen("cmlsc.in", "r");
    FILE* g = fopen("cmlsc.out", "w");
    
    short int n, m;
    short int v1[1100], v2[1100];
    
    fscanf(f, "%hd%hd", &n, &m);
    
    for (int i = 0; i < n; i++) {
        fscanf(f, "%hd", &v1[i]);
    } 
    for (int i = 0; i < m; i++) {
        fscanf(f, "%hd", &v2[i]);
    }
    
    short int poz = cmlsc(n, m, v1, v2);
    fprintf(g, "%hd\n", poz);
    for (int i = 0; i < poz; i++) {
        fprintf(g, "%hd ", v3[i]);
    } 
    fclose(f);
    fclose(g);   
}
