#include"fstream"
#define in "euclid2.in"
#define out "euclid.out"
using namespace std;
long a,b,c;
int main()
{
    FILE *fin=fopen(in ,"r");
    fscanf(fin ,"%ld%ld", &a, &b);
    fclose(fin);
    
    while(b)
       {
           c=a%b;
           a=b;
           b=c;
       }
    FILE *fout=fopen(out, "w");
    fprintf(fout,"%ld", a);
    fclose(fout);
    return 0;
}            
