#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <vector>
#include <utility>

int *seq1, *seq2;
int size1, size2;

// Anti-chains implementation of LCS()
void LCS_a()
{
    using namespace std;

    int i, j, l = 0, curr_ch, old_sl;
    int* s;
    int** f;
    vector<pair<int, int> >* A;
    vector<pair<int, int> > :: iterator it;

    // Computing the f table

    // Allocating the memory for f[][]
    f = (int**) malloc(sizeof(int*)*257);
    f[0] = (int*) calloc(sizeof(int)*257*(size2+1),4);
    for (i = 1; i < 257; ++i)
        f[i] = f[i-1] + size2+1;
    
    // Computing the f table in O(s*n)
    for (i = 0; i < 257; ++i)
    {
        int tmpval = size2;
        int tmpch = i;
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
        curr_ch = seq1[i];
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

    //free(f);

    // Logging the anti-chains to stderr
    for(i = 0; i < size2; i++)
    {
        if (A[i].size())
        {
            l = i;
            fprintf(stderr, "%d:",i);
            for (it=A[i].begin(); it != A[i].end(); it++)
                fprintf(stderr,"[%d,%d] ", it->first, it->second);
            fprintf(stderr,"\n");
        }
    }


    // Constructing a solution by iterating through the anti-chains
    int* result = new int[l+1];
    int last_x = size1, last_y = size2;
    for (i = l; i >= 0; i--)
    {
        for (it = A[i].begin(); it != A[i].end(); it++)
        {
            if ((it->first < last_x) && (it->second < last_y))
            {
                result[i] = seq1[it->first];
                last_x = it->first;
                last_y = it->second;
                break;
            }
        }
    }

    // Printing the result
    printf("%d\n",l+1);
    for (i = 0; i <= l; i++)
        printf("%d ",result[i]);
    printf("\n");
    // Freeing the result array
}


int main(int argc, char* argv[])
{
    int i;

    freopen("cmlsc.in", "r", stdin);
    freopen("cmlsc.out", "w", stdout);

    scanf("%d", &size1);
    scanf("%d", &size2);

    seq1 = new int[size1];
    seq2 = new int[size2];

    for (i = 0; i < size1; i++)
    {
        scanf("%d", &seq1[i]);
    }

    for (i = 0; i < size2; i++)
    {
        scanf("%d", &seq2[i]);
    }

    LCS_a();

    delete []seq1;
    delete []seq2;
    return 0;
}
