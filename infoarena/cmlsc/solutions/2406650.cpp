#include <iostream>
#include <fstream>

#define MAX 1025
#define maxi(a,b) ( (a) > (b) ? (a) : (b));


using namespace std;

ofstream out("cmlsc.out");

 int  n,m ;
    int v[MAX][MAX];
    int vect1[MAX], vect2[MAX];

void solutie(int i , int j)
{
    if(i > 0 && j > 0)
    {
         if( vect1[i] == vect2[j] )
      {
        solutie(i-1, j -1);
        out<<vect1[i] <<" ";

      }
      else
      {
          if(v[i-1][j]  > v[i][j-1])
              solutie(i-1 , j );
           else
             solutie( i , j -1 );

       }

    }


}




int main(void)
{

    ifstream in("cmlsc.in");

    in>>n>>m;
    for(int i = 1 ; i<= n ; i ++)
        in>>vect1[i];

    for(int i = 1 ; i<= n ; i ++)
        in>>vect2[i];




    for(int i = 1 ; i <= n ; i++)
        for(int j =  1 ; j <= m ; j++)
        {
            if(vect1[i] == vect2[j])
                v[i][j] = 1 + v[i-1][j-1];
            else
                v[i][j] = maxi(v[i-1][j], v[i][j-1]);

        }


        out<<v[n][m]<<'\n';

        solutie(n,m);


}

