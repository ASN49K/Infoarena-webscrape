#include <stdio.h>
 
int main()
{
    FILE* input  = fopen("cmlsc.in" , "r");
    FILE* output = fopen("cmlsc.out", "w");
 
    unsigned n, m;
    fscanf(input, "%d %d", &n, &m);
    
    int *sir1, *sir2, *subsir;
    sir1 = new int[n];
    sir2 = new int[m];

    unsigned contor_sir1 = 0;
    unsigned contor_subsir = 0;
 
    for(unsigned i=0; i<n; i++)
        if( fscanf(input, "%d", &sir1[i]) == EOF )
 		return -1;
 
    for(unsigned i=0; i<m; i++)
	if( fscanf(input, "%d", &sir2[i]) == EOF )
		return -1;
	
    if(n<m)
    {
	int* aux = sir1;
	sir1 = sir2;
	sir2 = aux;

	int aux_int = n;
	n = m;
	m = aux_int;
    }
    subsir = new int[m];

    for(unsigned i=0; i<m; i++)
    {
       for(unsigned j = contor_sir1; j<n; j++)
       {
           if(sir2[i] == sir1[j])
           {
                subsir[contor_subsir++] = sir2[i];
                contor_sir1 = j + 1;
                break;
           }
       }
    }
 
    fprintf(output, "%d\n", contor_subsir);
    for(unsigned i=0; i<contor_subsir; i++)
        fprintf(output, "%d ", subsir[i]);
 
    fclose(input);
    fclose(output);
    delete[] sir1, sir2, subsir;
}
