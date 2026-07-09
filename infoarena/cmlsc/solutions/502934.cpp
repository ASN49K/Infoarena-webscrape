#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <vector>
#include <utility>

char *seq1, *seq2;
int size1, size2;

// Anti-chains implementation of LCS()
void LCS_a()
{
    using namespace std;

    int i, j, l, curr_ch, old_sl;
    int* s;
    int** f;
    vector<pair<int, int> >* A;
    vector<pair<int, int> > :: iterator it;

    // Computing the f table

    // Allocating the memory for f[][]
    f = (int**) malloc(sizeof(int*)*256);
    f[0] = (int*) calloc(sizeof(int)*256*(size2+1),4);
    for (i = 1; i < 256; ++i)
        f[i] = f[i-1] + size2+1;
    
    // Computing the f table in O(s*n)
    for (i = 0; i < 256; ++i)
    {
        int tmpval = size2;
        char tmpch = i;
        for (j = size2; j >= 0; --j)
        {
            if (seq2[j] == tmpch)
                tmpval = j;
            f[i][j] = tmpval;
        }
    }

    // Initializing s
    s = (int*) malloc(sizeof(int)*size2);
    for (i=0; i < size2; ++i)
        s[i] = size2;

    // Allocating A
    A = new vector<pair<int, int> >[size2];

    // The algorithm for determining the anti-chains in A[i]
    for (i = 0; i < size1; ++i)
    {
        l = 0;
        curr_ch = (int)seq1[i];
        j = f[curr_ch][0];
        old_sl = 0;
        while (j < size2)
        {
            if (old_sl == 0)
                old_sl = s[l];

            if (j > old_sl)
            {
                l++;
                old_sl = 0;
            }
            else
            {
                if (j < s[l])
                    s[l] = j;
                A[l].push_back(make_pair(i,j));
                j = f[curr_ch][j+1];
            }
        }
    }

    // Constructing a solution by iterating through the anti-chains
    char* result = (char*) calloc(l+2,1);
    int last_x = size1, last_y = size2;
    for (i = l; i >= 0; i--)
    {
        for (it = A[i].begin(); it != A[i].end(); it++)
        {
            if (it->first < last_x && it->second < last_y)
            {
                result[i] = seq1[it->first];
                last_x = it->first;
                last_y = it->second;
                break;
            }
        }
    }

    // Printing the result
    size1 = strlen(result);
    printf("%d\n",size1);
    for (i = 0; i < size1; i++)
        printf("%d ",result[i]);
    printf("\n");

    // Freeing the result array
    free(result);
}


int main(int argc, char* argv[])
{
    int i, x;

    freopen("cmlsc.in", "r", stdin);
    freopen("cmlsc.out", "w", stdout);

    scanf("%d", &size1);
    scanf("%d", &size2);

    seq1 = (char*) calloc(size1+1,1);
    seq2 = (char*) calloc(size2+1,1);

    for (i = 0; i < size1; i++)
    {
        scanf("%d", &x);
        seq1[i] = (char) x;
    }

    for (i = 0; i < size2; i++)
    {
        scanf("%d", &x);
        seq2[i] = (char) x;
    }

    LCS_a();

    free(seq1);
    free(seq2);
    return 0;
}
