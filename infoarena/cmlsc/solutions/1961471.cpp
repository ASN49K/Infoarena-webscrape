#include <iostream>
#include <cstring>
#include <fstream>

using namespace std;

int main()
{
    ifstream fin ("text4.in");
    ofstream fout ("text4.out");
    char a[10001], b[10001];
    int max, l, i, x, y, nr, nrsp, aux, k, sp, j, aux2, n, p;
    fin >> max;
    fin.get();
    while(1)
    {
        y=0;
        fin.getline(a, 1001);
        if (a[0]==0)
            break;
        while (1)
        {
            k=0;
            nr=0;
            aux=y;
            l=0;
            while (a[y]!=' ' || l<=max)
            {
                p=0;
                if (a[y]==0)
                {
                    if (l<=max)
                    {
                        for (i=aux; i<y; i++)
                            b[k++]=a[i];
                        b[k++]=0;
                        fout << b << "\n";
                    }
                    break;
                }
                if (a[y]==' ')
                {
                    if (a[y+1]!=' ')
                        nr++;
                    x=y;
                }
                y++;
                l++;
            }
            if (a[y]==0 && l<=max)
                break;
            y=x+1;
            l=x-aux+1;
            nrsp=max-l+1;
            if (nrsp%nr==0)
                sp=nrsp/nr;
            else
                sp=nrsp/nr+1;
            nr=0;
            for (i=aux; i<x; i++)
                if (a[i]==' ' && a[i+1]==' ')
                    p=1;
            for (i=aux; i<x; i++)
            {
                b[k++]=a[i];
                if (a[i]==' ' && nr<nrsp)
                {
                    n=0;
                    aux2=i+1;
                    while (a[aux2]==' ')
                    {
                        n++;
                        b[k++]=' ';
                        aux2++;
                    }
                    i=aux2-1;
                    if (p)
                        for (j=1; j<=sp+1-n; j++)
                        {
                            if (nr>=nrsp)
                                break;
                            b[k++]=' ';
                            nr++;
                        }
                    else
                        for (j=1; j<=sp; j++)
                        {
                            if (nr>=nrsp)
                                break;
                            b[k++]=' ';
                            nr++;
                        }
                }
            }
            b[k++]=0;
            fout << b << "\n";
        }
    }
    return 0;
}
