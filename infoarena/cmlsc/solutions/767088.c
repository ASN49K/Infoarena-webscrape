#include <stdio.h>

#define MAXLEN 1024
#define DIAG 0
#define SUS 1
#define STANGA 2

void scrie_cmlsc(int dim_rs, 
                 int refacere_subsir[][dim_rs], 
                 int sir1[], 
                 int i, 
                 int j,
                 FILE *g){

    if ((i == 0) || (j == 0))
        return;

    if (refacere_subsir[i][j] == DIAG){
        scrie_cmlsc(dim_rs, refacere_subsir, sir1, i - 1, j - 1, g);
        fprintf(g, "%i ", sir1[i - 1]);
    }
    else{
        if (refacere_subsir[i][j] == SUS)
            scrie_cmlsc(dim_rs, refacere_subsir, sir1, i - 1, j, g);
        else
            scrie_cmlsc(dim_rs, refacere_subsir, sir1, i, j - 1, g);
    }
}

int main(){
    
    FILE *f, *g;
    int i, j;
    int dim_sir_1, dim_sir_2;

    f = fopen("cmlsc.in", "rt");
    if (!f)
        perror("Nu merge deschis fisierul de intrare.\n");
    g = fopen("cmlsc.out", "wt");
    if (!g)
        perror("Nu merge deschis fisierul de iesire.\n");

    /* Citim dimensiunile celor doua siruri. */
    fscanf(f, "%i %i", &dim_sir_1, &dim_sir_2);

    int sir1[dim_sir_1 + 1], sir2[dim_sir_2 + 1];
    int mat_pd[dim_sir_1 + 1][dim_sir_2 + 1];
    int refacere_subsir[dim_sir_1 + 1][dim_sir_2 + 1];

    /* Citim primul sir. */
    for (i = 0; i < dim_sir_1; i++)
        fscanf(f, "%i", &sir1[i]);

    /* Citim al doilea sir. */
    for (i = 0; i < dim_sir_2; i++)
        fscanf(f, "%i", &sir2[i]);

    /* Utilizand programare dinamica, aflam lungimea maxima. */
    for (i = 0; i <= dim_sir_1; i++)
        mat_pd[i][0] = 0;
    for (j = 0; j <= dim_sir_2; j++)
        mat_pd[0][j] = 0;
    for (i = 1; i <= dim_sir_1; i++)
        for (j = 1; j <= dim_sir_2; j++)
            if (sir1[i - 1] == sir2[j - 1]){
                mat_pd[i][j] = mat_pd[i - 1][j - 1] + 1;
                refacere_subsir[i][j] = DIAG;
            }
            else{
                if (mat_pd[i -1][j] >= mat_pd[i][j - 1]){
                    mat_pd[i][j] = mat_pd[i - 1][j];
                    refacere_subsir[i][j] = SUS;
                }
                else{
                    mat_pd[i][j] = mat_pd[i][j -1];
                    refacere_subsir[i][j] = STANGA;
                }
            }
    fprintf(g, "%i\n", mat_pd[dim_sir_1][dim_sir_2]);
    
    /* Construim subsirul de lungime maxima pe baza lui refacere_subsir. */
    scrie_cmlsc(dim_sir_2 + 1, refacere_subsir, sir1, dim_sir_1, dim_sir_2, g);

    fclose(g);
    fclose(f);

    return 0;
}
