#include <fstream>
#include <deque>

using namespace std;

ifstream fin("cmlsc.in");
ofstream fout("cmlsc.out");

int N,M;
int lg[1030][1030];
int a[1030];
int b[1030];

deque <int> val;

void Read()
{
  fin>>N>>M;

  for(int i=1; i<=N; ++i)
    fin>>a[i];

  for(int i=1; i<=M; ++i)
    fin>>b[i];

  for(int i=0; i<=N+1; ++i)
    for(int j=0; j<=M+1; ++j)
      lg[i][j]=-1;

  fin.close();
}

int Lg(int lgA,int lgB)
{
  if(lg[lgA][lgB]>0) return lg[lgA][lgB];

  if(lgA==0 || lgB==0)
  {
    lg[lgA][lgB]=0;
    return 0;
  }

  if(a[lgA]==b[lgB])
  {
    lg[lgA][lgB]=1+Lg(lgA-1,lgB-1);

    val.push_back(a[lgA]);

    return lg[lgA][lgB];
  }

  lg[lgA][lgB-1]=Lg(lgA,lgB-1);
  lg[lgA-1][lgB]=Lg(lgA-1,lgB);

  lg[lgA][lgB]=max(lg[lgA][lgB-1],lg[lgA-1][lgB]);

  return lg[lgA][lgB];
}

void Remake(int nrA,int nrB)
{
  if(nrA==0 || nrB==0) return;

  if(a[nrA]==b[nrB])
  {
    Remake(nrA-1,nrB-1);
    fout<<a[nrA]<<' ';

    return;
  }

  if(lg[nrA][nrB-1]>lg[nrA-1][nrB]) Remake(nrA,nrB-1);
  else Remake(nrA-1,nrB);

}

void Test()
{
  Lg(N,M);
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
    fout<<Lg(N,M)<<'\n';
    Remake(N,M);
    //Test();


    return 0;
}
