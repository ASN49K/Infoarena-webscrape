//include's
#include <fstream>


//typedef's
typedef char numeFisier[10];


//namespaces
using namespace std;


//declaratii de functii
void citire(numeFisier s);
void afisare(numeFisier s);
int cautare();
int maxim(int i1, int j1, int i2, int j2);



//variabile
numeFisier input="cmlsc.in";
numeFisier output="cmlsc.out";
int N,M;
int matrix[1025][1025];


//main
int main(void)
{
    citire(input);
    afisare(output);


    return 0;
}


//definitii de functii
void citire(numeFisier s)
{
    ifstream fin(s);

    int i, j;

    fin>>M>>N;

    for(j=1; j<=M; j++)
      fin>>matrix[0][j];

    for(i=1; i<=N; i++)
      fin>>matrix[i][0];



    fin.close();
}

void afisare(numeFisier s)
{
    ofstream fout(s);

    fout<<cautare();


    fout.close();
}

int cautare()
{
    int i,j, max = -1;

    //construiesc prima linie
    for(j=1; j<=M; j++)
      if(matrix[1][0] == matrix[0][j])
        matrix[1][j]=1;

    //construiesc prima coloana
    for(i=2; i<=N; i++)
      if(matrix[i][0] == matrix[0][1])
        matrix[1][j]=1;


    //construiesc restul liniilor
    for(i=2; i<=N; i++)
      for(j=2; j<=M; j++)
        if(matrix[i][0] == matrix[0][j])
          {
              matrix[i][j] = maxim(i, j-1, i-1, j-1) + 1;
              if(matrix[i][j]>max)
                max = matrix[i][j];
          }
        else
          {
              matrix[i][j] = maxim(i, j-1, i-1, j-1);
              if(matrix[i][j]>max)
                max = matrix[i][j];
          }

    return max;
}

int maxim(int i1, int j1, int i2, int j2)
{
    if(matrix[i1][j1] > matrix[i2][j2])
      return matrix[i1][j1];

    return matrix[i2][j2];
}

