#include <fstream>

using namespace std;

int gcd(int a, int b)
{
    while(a > 0 && b > 0)
    {
        if(a > b)
        {
            a %= b;
        }
        else
        {
            b %= a;
        }
    }
    return a > b ? a : b;
}

int main()
{
    FILE* fin = fopen("euclid2.in","r");
    FILE* fout = fopen("euclid2.out","w");
    int a, b, size;
    fscanf(fin, "%d", &size);
    for(int i = 0 ; i < size; i++)
    {
        fscanf(fin, "%d", &a);
        fscanf(fin, "%d", &b);
        fprintf(fout, "%d\n", gcd(a,b));
    }

    return 0;
}
