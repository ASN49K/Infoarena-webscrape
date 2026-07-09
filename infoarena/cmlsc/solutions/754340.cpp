                                                     
#include <fstream>
using namespace std;

char Drum[1025][1025];
int Len[1025][1025];

int main(void)
{
 fstream fin("cmlsc.in",ios::in);
 fstream fout("cmlsc.out",ios::out);
 int a,b,c,ret;
 int M,N;
 int NrM[1025],NrN[1025],Res[1025];

 fin >> M >> N;
 for (a = 0;a < M;a += 1)
  {
   fin >> NrM[a];
  }
 for (a = 0;a < N;a += 1)
  {
   fin >> NrN[a];
  }

 for (a = 0;a < 1025;a += 1)
  {
   Drum[a][0] = 0;
   Drum[0][a] = 0;
   Len[a][0] = 0;
   Len[0][a] = 0;
  }
 for (a = 0;a < M;a += 1)
  {
   for (b = 0;b < N;b += 1)
    {
     if (NrM[a] == NrN[b])
       {
        Drum[a][b] = 'D';
        Len[a][b] = Len[a - 1][b - 1] + 1;
       }
      else
       {
        if (Len[a - 1][b] > Len[a][b - 1])
          {
           Drum[a][b] = 'U';
           Len[a][b] = Len[a - 1][b];
          }
         else
          {
           Drum[a][b] = 'L';
           Len[a][b] = Len[a][b - 1];
          }
       }
    }
  }
 a = M - 1;
 b = N - 1;
 c = 0;
 ret = 0;
 while (ret == 0)
  {
   if (NrM[a] == NrN[b])
     {
      Res[c] = NrM[a];
      c += 1;
     }
   switch (Drum[a][b])
    {
     case 'D' :
       {
        a -= 1;
        b -= 1;
       }
      break;
     case 'U' :
       {
        a -= 1;
       }
      break;
     case 'L' :
       {
        b -= 1;
       }
      break;
     case 0 :
       {
        ret = 1;
       }
    };
  }
 fout << Len[M - 1][N - 1] << "\n";
 for (a = Len[M - 1][N - 1] - 1;a >= 0;a -= 1)
  {
   fout << Res[a] << " ";
  }

 fin.close();
 fout.close();
 return 0;
}
