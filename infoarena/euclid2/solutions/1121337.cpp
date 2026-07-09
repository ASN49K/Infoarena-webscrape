#include <fstream>
#include <stdio.h>
using namespace std;

int main()
{
    int n,a,b,i,c;
    ifstream input;
    ofstream output;
    output.open("euclid2.out");
    input.open("euclid2.in");
    FILE *fin = fopen("euclid2.in", "r");
    FILE *fout = fopen("euclid2.out", "w");

    //input>>n;
    fscanf(fin,"%d\n", &n);
    for (i=0;i<n;i++)
    {
        //input>>a>>b;
        fscanf(fin, "%d %d\n", &a, &b);
        if (a<b)
        {
            c = a;
            a = b;
            b = c;
        }
        while (b != 0)
        {
            c=a%b;
            a=b;
            b=c;
        }
        fprintf(fout,"%d\n", a);
        //output<<a<<endl;
    }
    fclose(fin);
    fclose(fout);

    //input.close();
    //output.close();
    return 0;
}
