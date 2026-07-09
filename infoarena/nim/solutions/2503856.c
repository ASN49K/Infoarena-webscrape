#include<stdio.h>

int nr_teste, nr_gramezi, nr_pietre;

int main() {
    freopen("nim.in", "r", stdin);
    freopen("nim.out", "w", stdout);

    scanf("%d", &nr_teste);
    while(nr_teste--) {
        scanf("%d", &nr_gramezi);
        int sumaXor = 0;
        for(int i = 0; i < nr_gramezi; ++i) {
            scanf("%d", &nr_pietre);
            sumaXor ^= nr_pietre;
        }
        if(sumaXor != 0) {
            printf("DA\n");
        } else {
            printf("NU\n");
        }
    }

    return 0;
}