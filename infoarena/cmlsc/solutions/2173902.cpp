#include <fstream>
#include <deque>

using namespace std;

ifstream fin("cmlsc.in");
ofstream fout("cmlsc.out");

int N,M;
int a[1030];
int b[1030];
int lg[1030][1030];

deque <int> nr;

void Read()
{
  fin>>N>>M;

  for(int i=1; i<=N; ++i)
    fin>>a[i];

  for(int j=1; j<=M; ++j)
    fin>>b[j];

  fin.close();
}

void Do()
{
  for(int i=1; i<=N; ++i)
    for(int j=1; j<=M; ++j)
      if(a[i]==b[j]) lg[i][j]=1+lg[i-1][j-1];
      else lg[i][j]=max(lg[i-1][j],lg[i][j-1]);

}

void Remake()
{
  int L,C;

  L=N; C=M;

  while(lg[L][C]>0)
  {
    if(a[L]==b[C])
    {
      //fout<<a[L]<<' ';
      nr.push_back(a[L]);

      --L;
      --C;
    }
    else
     if(lg[L-1][C]>lg[L][C-1]) --L;
     else --C;
  }
}

void Print()
{
  fout<<lg[N][M]<<'\n';

  Remake();
  while(nr.size()>0)
  {
    fout<<nr.back()<<' ';
    nr.pop_back();
  }
}

void Test()
{
  for(int i=1; i<=N; ++i)
  {
    for(int j=1; j<=M; ++j)
      fout<<lg[i][j]<<' ';
      fout<<'\n';
  }
}

int main()
{
    Read();
    Do();
    Print();
    //Test();

    return 0;
}
