#include<cstdio>
#define MAX_N 1024
#define MAX_M 1024

FILE *in =fopen("cmlsc.in", "r"),  //fisierul de intrare
     *out=fopen("cmlsc.out", "w"); //fisierul de iesire

int n, m, min, max, sir1, sir2, sir[2][MAX_N], comb[MAX_M];
bool gasit=false;

void citeste()
{
    fscanf(in, "%d %d", &n, &m);
    for(int i=0; i<n; i++)
        fscanf(in, "%d", &sir[0][i]);
    for(int i=0; i<m; i++)
        fscanf(in, "%d", &sir[1][i]);
    fclose(in);

}

//elementele stivei trebuie sa fie crescatoare si diferite
int valid(int k)
{
    if(k>0)
        if(comb[k]<=comb[k-1])
            return 0;
    return 1;
}
//verific daca subsirul combinarilor este comun
int e_subsir_comun(int w)
{
    int aux, i=0, t=0;
    while(i<max)
    {
        //caut in sirul mai mare subsirul generat din sirul mai mic
        if(sir[sir1][i]==sir[sir2][comb[t]])
            t++;
        i++;
    }
    if(t==w) //numarul elementelor comune trebuie sa fie egal cu nr elementelor
        return 1;           //din solutia de combinari
    else
        return 0;
}

void btrack(int k, int w, int minim)
{
    int t,i;
    if(k==w) //daca am format o solutie prin combinari
    {
        if(e_subsir_comun(w) && !gasit)
        {
            fprintf(out, "%d\n", w); //lungimea subsirului
            for(i=0; i<w; i++)
                fprintf(out, "%d ", sir[sir2][comb[i]]); //subsirul comun il scriu
            gasit=true;                                       // din sirul mai mic
            return;
        }
    }
    else
    {
        comb[k]=-1;
        while(comb[k]<minim) //elementele stivei apartin [0, min-1]
        {
            comb[k]++;
            if(valid(k))
                btrack(k+1, w, minim);
        }
    }
}

int main()
{
    citeste();
    int i, aux;
    sir1=(n>m ? 1:0), //sirul cu lungimea mai mare
    sir2=(n>m ? 0:1), //sirul cu lungimea mai mica
    max=((n>m) ? n:m),min=((n>m) ? m:n);
    if(n<m)
    {
        aux=sir1;
        sir1=sir2;
        sir2=aux;
    }
    for(i=min; i>=2; i--) //fac combinari uitandu-ma in sirul mai mic
        if(!gasit)
            btrack(0, i, min-1);
    fclose(out);
    return 0;
}
