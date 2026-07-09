using namespace std;
#include <fstream>
#include <string.h>
#define MAX 500
ifstream f ("cmlsc.in");
ofstream g ("cmlsc.out");


int main ()
{

    char s1[MAX], s2[MAX], d[MAX][MAX], sir[MAX];
    int x, y, i, j, aux=0;

    f.getline (s1, MAX);
    f.getline (s2, MAX);

    x = strlen(s1);
    y = strlen(s2);

    for (i = 1; i <= x; i++)
    {
        for (j = 1; j <= y; j++)
        {
            if (s1[i-1] == s2[j-1])
            {
                d[i][j] = d[i-1][j-1] + 1;
            }
            else
            {
                if (d[i-1][j] < d[i][j-1]) d[i][j] = d[i][j-1];
                else d[i][j] = d[i-1][j];
            }
        }
    }
    for (i = x, j = y; i; )
    {
        if (s1[i-1] == s2[j-1])
        {
            sir[++aux] = s1[i-1];
            i--;
            j--;
        }
        else if (d[i-1][j] < d[i][j-1]) j--;
        else i--;
    }

    for (i = aux; i >= 1; i--) g << sir[i];
    f.close();
    g.close();
    return 0;
}