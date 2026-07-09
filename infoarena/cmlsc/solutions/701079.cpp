#include<cstdio>
#include<vector>
#define _MAX 1034
using namespace std;
int nA, nB;
int A[_MAX], B[_MAX];
vector<int > lcs[_MAX][_MAX];

vector<int > *max(vector<int > &a, vector<int > &b)
{
    if (a.size()>b.size())
        return &a;
    else
        return &b;
}

int main()
{
    FILE *f=fopen("cmlsc.in", "r");
    fscanf(f, "%d %d", &nA, &nB);
    for (int i=1;i<=nA;i++)
        fscanf(f,"%d", &A[i]);
    for (int i=1;i<=nB;i++)
        fscanf(f,"%d", &B[i]);
    //solution
    for (int iA=1;iA<=nA;iA++)
        for (int iB=1;iB<=nB;iB++)
            if(A[iA]==B[iB])
            {
                lcs[iA][iB]=lcs[iA-1][iB-1];
                lcs[iA][iB].push_back(A[iA]);
            }
            else
                lcs[iA][iB]=*max(lcs[iA][iB-1], lcs[iA-1][iB]);
    //endsolution
    f=fopen("cmlsc.out", "w");
    fprintf(f, "%d\n", lcs[nA][nB].size());
    for (int i=0;i<lcs[nA][nB].size();i++)
        fprintf(f, "%d ", lcs[nA][nB].at(i));
    return 0;
}
