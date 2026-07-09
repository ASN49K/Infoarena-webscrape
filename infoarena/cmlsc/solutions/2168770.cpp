#include <fstream>

using namespace std;

ifstream fin("cmlsc.in");
ofstream fout("cmlsc.out");

int N,M;
short a[1030];
short b[1030];

short mat[1030][1030];

void Read()
{
  fin>>N>>M;

  for(int i=1; i<=N; ++i)
    fin>>a[i];

  for(int i=1; i<=M; ++i)
    fin>>b[i];

  fin.close();
}

int LgMax(int lgA,int lgB)
{
  if(mat[lgA][lgB]>0) return mat[lgA][lgB];

  if(lgA==0 || lgB==0)
    { mat[lgA][lgB]=0;
      return mat[lgA][lgB];
    }

  if(a[lgA]==b[lgB])
  {
    mat[lgA][lgB]=1+LgMax(lgA-1,lgB-1);

    return mat[lgA][lgB];
  }

  mat[lgA][lgB-1]=LgMax(lgA,lgB-1);
  mat[lgA-1][lgB]=LgMax(lgA-1,lgB);

  mat[lgA][lgB]=max(mat[lgA][lgB-1],mat[lgA-1][lgB]);
}

void Test()
{
  for(int i=1; i<=N; ++i)
  { for(int j=1; j<=M; ++j)
      fout<<mat[i][j]<<' ';

     fout<<'\n';
  }
}

void Remake(int lgA,int lgB)
{
  if(mat[lgA][lgB]==0) return;

  if(mat[lgA][lgB]-(a[lgA]==b[lgB])==mat[lgA][lgB-1])
    { Remake(lgA,lgB-1);
      fout<<a[lgA]<<' ';
      return;
    }

  if(mat[lgA][lgB]-(a[lgA]==b[lgB])==mat[lgA-1][lgB])
    { Remake(lgA-1,lgB);
     // fout<<b[lgB]<<' ';
      return;
    }

  if(mat[lgA][lgB]-(a[lgA]==b[lgB])==mat[lgA-1][lgB-1])
    { Remake(lgA-1,lgB-1);
      //fout<<a[lgA]<<' ';
      return;
    }
}

int main()
{
    Read();
    fout<<LgMax(N,M)<<'\n';
   // Test();
    Remake(N,M);

    return 0;
}
