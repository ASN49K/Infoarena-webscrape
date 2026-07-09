#include <stdio.h>

FILE* fin;
FILE* fout;

void load()
{
    fin = fopen("euclid2.in","r");
    fout = fopen("euclid2.out","w");
}

int readT()
{
    int t;

    fscanf(fin,"%d",&t);

    return t;
}

int init()
{
    load();
    return readT();
}

unsigned long long cmmdc(unsigned long long a,unsigned long long b)
{
    unsigned long long r;

    while(b!=0)
    {
        r = a % b;
        a = b;
        b = r;
    }

    return a;
}

void write(unsigned long long res)
{
    fprintf(fout,"%llu\n",res);
}

void rezolvare(int t)
{
    unsigned long long a;
    unsigned long long b;

    for(int i=0;i<t;i++)
    {
        fscanf(fin,"%llu %llu",&a,&b);

        write(cmmdc(a,b));
    }
}

void CloseFiles()
{
    fclose(fin);
    fclose(fout);
}

void Terminate()
{
    CloseFiles();
}

int main()
{
    rezolvare(init());
    Terminate();

    return 0;
}
