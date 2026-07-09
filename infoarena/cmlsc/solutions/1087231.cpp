#include <fstream>
//#include <iostream>

using namespace std;
ifstream fin("cmlsc.txt");
ofstream g("cmlsc.out");
int M, N, A[1025], B[1025], st[1025], sol[1024], c=1, j=1;

void init(int k)
{
    st[k]=0;
}

int succesor(int k)
{
    if (st[k]<=M)
        {
            st[k]++;
            return 1;
        }
    return 0;
}

int valid (int k)
{
    for (int i=j; i<=N; i++)
        if (A[st[k]]==B[i])
        {
            j=i+1;
            sol[c++]=B[i];
           return 1;
        }
    return 0;
}

int solutie (int k)
{
    return 1;
}

void tipar()
{
    for (int i=1; i<c; i++)
        g<<sol[i]<<' ';
    g<<endl;
    g.close();
}

void back()
{
    int k=1;
    init(k);
    while (k>0)
    {
        while(succesor(k))
            if (valid(k));
        k--;
    }
    g<<c-1<<'\n';
    tipar();
}

int main()
{

    fin>>M>>N;
    for (int i=1; i<=M; i++)
        fin>>A[i];
    for (int i=1; i<=N; i++)
        fin>>B[i];
    fin.close();
    back();
    return 0;
}
