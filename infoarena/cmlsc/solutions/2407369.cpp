#include <iostream>
#include <vector>
#include <fstream>


#define maxim(a,b) ((a) > (b) ? (a) : (b))

using namespace std;

ofstream out("cmlsc.out");

void solutie(vector < vector <int >> v ,  int *v1 ,int *v2 , int i , int j)
{

if ( i && j)
    if(v1[i] == v2[j])
    {
        solutie(v,v1,v2, i-1, j-1 );
       out<<v1[i]<<" ";

    }
    else
        if(v[i-1][j] > v[i][j-1])
                solutie(v,v1,v2, i-1, j);
        else
                solutie(v,v1,v2, i, j-1 );


}

int main()
{
    ifstream in("cmlsc.in");

    int n, m ;

    in>>n>>m;
    int v1[n], v2[m] ;

    for(int i = 1 ; i <= n ; i++)
        in>>v1[i];


    for(int i = 1 ; i <= n ; i++)
        in>>v2[i];



    vector<vector<int > > v(n+1);


    for(int  i = 0 ; i <=n ; i++)
    {
        v[i].reserve(m+1);

        for(int j =0 ; j <=m ; j++)
            v[i].push_back(0);

    }

    for(int i = 1; i <= n ; i++)

        for(int j =1 ; j <= m ; j++)
           {
               if(v1[i] == v2[j]) v[i][j] = 1 + v[i-1][j-1];

               else
                        v[i][j] = maxim(v[i-1][j] , v[i][j-1]);

           }

           out<<v[n][m] <<'\n';


        solutie(v,v1,v2, n, m );



    return 0;
}
