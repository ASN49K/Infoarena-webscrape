#include <iostream>
#include <fstream>
#include <vector>

using namespace std;

const int Msize = 1025;

int Arr[Msize][Msize],A[Msize],B[Msize];
vector<int> ans;

void read(int &N,int &M);
void solve(int N,int M);

int main()
{
    int N,M;
    read(N,M);
    solve(N,M);

    return 0;
}


void read(int &N, int &M)
{
   fstream f("cmlsc.in",ios::in);
   f>>N>>M;

   int i;
   for(i=1;i<=N;++i)
    {
    f>>A[i];
    }
   for(i=1;i<=M;++i)
    {
    f>>B[i];
    }

   f.close();
}

void solve(int N,int M)
{
   ofstream g("cmlsc.out");
   int i,j,n;

   for(i=1;i<=N;++i)
    {
     for(j=1;j<=M;++j)
        {
         if(A[i] == B[j])
            {
            Arr[i][j] = Arr[i-1][j-1]+1;
            }
         else Arr[i][j] = max(Arr[i-1][j],Arr[i][j-1]);
        }
    }
    i = N;
    j = M;
    g<<Arr[i][j]<<"\n";

    n = Arr[i][j];
    while(n!=0)
        {
         if(A[i]==B[j])
            {
            --n;
            ans.push_back(A[i]);
            --i;
            --j;
            }
         else
            {
            if(Arr[i-1][j]>Arr[i][j-1])
                --i;
            else
                --j;
            }
        }

    for(vector<int>::reverse_iterator it = ans.rbegin();it!=ans.rend();++it)
        {
        g<<*it<<" ";
        }
}
