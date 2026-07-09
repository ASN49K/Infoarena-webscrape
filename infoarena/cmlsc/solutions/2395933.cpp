#include <stdio.h>

int main()
{
    FILE* input  = fopen("cmlsc.in" , "r");
    FILE* output = fopen("cmlsc.out", "w");

    unsigned n, m;
    fscanf(input, "%d %d", &n, &m);
    
    unsigned* sir = new unsigned[n];
    unsigned* subsir = new unsigned[m];
    unsigned contor_sir = 0;
    unsigned contor_subsir = 0;

    for(unsigned i=0; i<n; i++)
        if( fscanf(input, "%d", &sir[i]) == EOF )
            return -1;

    for(unsigned i=0; i<m; i++)
    {
       unsigned element_subsir = sir[0]+1;
       if( fscanf(input, "%d", &element_subsir) == EOF )
            return -1;

       for(unsigned j = contor_sir; j<n; j++)
       {
           if(element_subsir == sir[j])
           {
                subsir[contor_subsir++] = element_subsir;
                contor_sir++;
                break;
           }
       } 
    }

    fprintf(output, "%d\n", contor_subsir);
    for(unsigned i=0; i<contor_subsir; i++)
        fprintf(output, "%d ", subsir[i]);

    fclose(input);
    fclose(output);
    delete[] sir;
    delete[] subsir;

}
