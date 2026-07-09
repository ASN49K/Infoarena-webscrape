#include <stdio.h>
#include <stack>
using namespace std;

int main()
{
    freopen("cmlsc.in", "r", stdin);
    freopen("cmlsc.out", "w", stdout);
    stack<short int> s;
        
    short int v1[1020], v2[1020];
    short int v3[1020][1020];
    
    short int n, m, i, j;
    
    scanf("%hd%hd", &n, &m);
    
    for (i = 1; i <= n; i++) {
        scanf("%hd", &v1[i]);
    } 
    for (i = 1; i <= m; i++) {
        scanf("%hd", &v2[i]);
    }
    
    for (i = 0; i <= n; i++) {
        v3[i][0] = 0;
    }
    for (i = 0; i <= m; i++) {
        v3[0][i] = 0;
    }
    
    for (i = 1; i <= n; i++) {
        for (j = 1; j <= m; j++) {
            if (v1[i] == v2[j]) {
                 v3[i][j] = 1 + v3[i-1][j-1];          
            }
            else if (v3[i][j-1] > v3[i-1][j]) {
                 v3[i][j] = v3[i][j-1];
            } 
            else {
                 v3[i][j] = v3[i-1][j];     
            }
        }
    }    
          
    printf("%hd\n", v3[n][m]);
    
    while (n != 0 && m != 0) {
          if (v1[n] == v2[m]) {
               s.push(v2[m]);
               n--;m--;
          }
          else if (v3[n-1][m] > v3[n][m-1]) {
               n--;
          }
          else {
               m--;     
          }
    }
    
    while (!s.empty()) {
          printf("%hd ", s.top());
          s.pop();
    }
    
    return 0;
}
