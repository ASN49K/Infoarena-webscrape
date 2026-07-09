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

  return max(lg[lgA][lgB-1],lg[lgA-1][lgB]);
}

int main()
{
    Read();
    fout<<Lg(N,M)<<'\n';
    while(val.size()>0)
    {
      fout<<val.front()<<' ';
      val.pop_front();
    }


    return 0;
}
