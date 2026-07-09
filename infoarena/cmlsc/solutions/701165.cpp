#include<cstdio>
#include<vector>
#define _MAX 1034
using namespace std;
int nA, nB;
int A[_MAX], B[_MAX];
int lcs[_MAX][_MAX];
vector<int > lcs_cont;

int max(int a, int b)
{
    if (a>b) return a;
    else return b;
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
                lcs[iA][iB]++;
            }
            else
                lcs[iA][iB]=max(lcs[iA][iB-1], lcs[iA-1][iB]);
    //backtrack
    int curA=nA, curB=nB;
    while(curA>0&&curB>0)
    {
        if (lcs[curA][curB]==lcs[curA-1][curB-1]+1)
        {
            lcs_cont.push_back(A[curA]);
            curA--; curB--;
        }
        else
            if (lcs[curA-1][curB]>lcs[curA][curB-1])
                curA--;
            else
                curA--;
    }
    //endsolution
    f=fopen("cmlsc.out", "w");
    fprintf(f, "%d\n", lcs[nA][nB]);
    for (int i=0;i<lcs_cont.size();i++)
        fprintf(f, "%d ", lcs_cont.at(i));
    return 0;
}
