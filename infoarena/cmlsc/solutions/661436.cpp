#include <stdio.h>

int main() {
    freopen("cmlsc.in", "r", stdin);
    freopen("cmlsc.out", "w", stdout);
    
    int m, n;
    int a[1024], b[1024];
    scanf("%d %d", &m, &n);
    
    for(int i = 0; i < m; i++)
            scanf("%d", &a[i]);
    
    for(int j = 0; j < n; j++)
            scanf("%d", &b[j]);
            
    int c[1024];
    int index = 0;
    bool gasit = false;
    for(int i = 0; i < m; i++) {
            for(int j = 0; j < n; j++) {
                    if (a[i] == b[j]) {
                       if (a[i] > c[index - 1]){
                          c[index] = a[i];
                          index++;
                          gasit = true;
                          b[j] = -1;
                       }
                    }
            }
            if (gasit == true) {
               continue;
               gasit = false;
            }
    }
    
    printf("%d\n", index);
    for (int i = 0; i < index; i++)
        printf("%d ", c[i]);
} 
