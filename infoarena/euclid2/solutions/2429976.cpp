
#include <iostream>

int main() {

    int a, b, k1, k2, rezultat, T;
    FILE * fisier_out = fopen("euclid2.out", "w");
    FILE * fisier_in = fopen("euclid2.in", "r");
    fscanf(fisier_in, "%d", &T);

    for(int i = 0; i < T; i++) {
        fscanf(fisier_in, "%d", &a);
        fscanf(fisier_in, "%d", &b);

        if (a - b > 0) {
            k1 = a;
            k2 = b;
        } else {
            k1 = b;
            k2 = a;
        }
        while (1) {
            rezultat = k1 % k2;
            if (rezultat == 0) {
                if (k2 == 1) {
                    fprintf(fisier_out, "%d\n", 1);
                    break;
                }
                fprintf(fisier_out, "%d\n", k2);
                break;
            }
            k1 = k2;
            k2 = rezultat;
        }
    }
    fclose(fisier_in);
    fclose(fisier_out);
    return 0;
}