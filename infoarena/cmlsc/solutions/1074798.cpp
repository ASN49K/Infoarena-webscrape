#include <fstream>
#include <iostream>

using namespace std;

int M, N, A[1025], B[1025], f=1, st[1025], p=1, sol[1024];

void init(int k)
{
    st[k]=k;
}

int succesor(int k, int c)
{
    if (k<=M && f<=N && c!=M)
        return 1;
    return 0;
}

int valid (int k)
{
    for (int i=f; i<=N; i++)
       {//cout<<st[k]<<" ";
        if (A[st[k]]==B[i])
        {
            f=i+1;
            sol[p++]=B[i];
            return 1;
        }}
    return 0;
}

int solutie (int k)
{
    return (k==M);
}

void tipar(int k)
{
    for (int i=1; i<p; i++)
        cout<<sol[i]<<" ";
}

void back()
{
    int k=1, c=0;
    init(k);
    while (k>0)
    {
        while(succesor(k, c))
        {
            c++;
            if (valid(k))
            {
                if (solutie(k))
                    tipar(k);
            }
            k++;
            init(k);
        }

        k--;
    }

}

int main()
{
    ifstream fin("cmlsc.txt");
    fin>>M>>N;
    for (int i=1; i<=M; i++)
        fin>>A[i];
    for (int i=1; i<=N; i++)
        fin>>B[i];
    fin.close();
    back();
    return 0;
}
