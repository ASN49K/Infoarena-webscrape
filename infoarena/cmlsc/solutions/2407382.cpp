#include <iostream>
#include <vector>
#include <fstream>
#include <deque>


#define maxim(a,b) ((a) > (b) ? (a) : (b))

using namespace std;



int main()
{
    ifstream in("cmlsc.in");
    ofstream out("cmlsc.out");
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

   deque<int> sir ;

         int i , j ;
         for( i = n , j = m ; i ; )
            if(v1[i] == v2[j])
                {sir.push_front(v1[i]);
                 i--; j--;
                }
                else
                    if(v[i-1][j] > v[i][j-1])
                        i--;
                        else
                        j--;

      out<<sir.size()<<'\n';

      deque<int> :: iterator it ;

      for(it = sir.begin() ; it < sir.end() ; it++)
        out<<*it<<" ";







    return 0;
}
