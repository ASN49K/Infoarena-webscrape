#include <iostream>
#include <fstream>

using namespace std;

ifstream fin("flip.in");
ofstream fout("flip.out");


int main()
{
    int tabla[100][100];
    int N, M, scoloana=0, sran=0, minim = 0, randc ,randl,Suma_totala = 0;
    fin >> N;
    fin >> M;
        for(int i = 1 ; i<=N ; i++)
            for(int  j = 1; j<=M ; ++j) //--------------------------- GENERARE MATRICE---------------------------//
                fin >> tabla[i][j];

                for(int j = 1; j <= M ; ++j)
                {
                    minim = minim + tabla[1][j];
                    randl = 1;
                }


        for(int i = 2 ; i<=N ; i++)
        {
            sran = 0;
                                     //---------------------------------SUMA MINIMA RAND-------------------------//
            for(int  j = 1; j<=M ; j++)
                sran = sran + tabla[i][j];

            if(sran < minim)
            {
                minim = sran;
                randl = i;
            }


        }




            minim = 0;

            for(int i = 1; i<=N ; i++)
            {
                minim = minim + tabla[i][1];
                randc = 1;
            }


        for(int  j = 2; j<=M ; ++j)
        {
                    scoloana = 0;      //----------------------------------- SUMA MINIMA COLOANA ---------------------------//
         for(int i = 1 ; i<=N ; i++)
                scoloana = scoloana + tabla[i][j];


                        if(scoloana < minim)
                        {
                            minim = scoloana;
                            randc = j;
                        }


        }






            for(int j = 1 ; j<= M; ++j)
            {
                 tabla[randl][j]= tabla[randl][j]*(-1);

            }

            for(int i = 1; i<=N ; ++i)
            {
                tabla[i][randc] = tabla[i][randc]*(-1);

            }

          for(int i = 1 ; i<=N ; i++)
          {
            for(int  j = 1; j<=M ; j++) //--------------------------- Rezultat Final ---------------------------//
                Suma_totala = Suma_totala + tabla[i][j];


          }

                fout << Suma_totala;


}
