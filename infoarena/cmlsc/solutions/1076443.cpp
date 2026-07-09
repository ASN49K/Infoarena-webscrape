#include <iostream>
#include <fstream>
using namespace std;
int v[257][257],k;

void reconstruire(int i,int j)
{if(i>0 && j>0)
            {if(v[0][j]==v[i][0])
                        {reconstruire(i-1,j-1);
                        cout<<v[0][j]<<" ";}
            else
                        if(k%2==0)
                                    {k++;
                                    reconstruire(i,j-1);
                                    }
                        else
                                    {k++;
                                    reconstruire(i-1,j);
                                    }
            }
/*if(i>=0 && j>=0)
            reconstruire(i-1, j);*/
}


int main()
{int M,N, i,j;
ifstream f("cmlsc.in");
ofstream g("cmlsc.out");
f>>M>>N;
for(i=1; i<=M; i++)
            f>>v[0][i];
for(i=1; i<=N; i++)
            f>>v[i][0];

for(i=1; i<=M; i++)                             //prima linie
            {if(v[0][i]==v[1][0])
                        v[1][i]=1;
            else
                        if(v[1][i-1]==1)
                                                v[1][i]=1;
                        else
                                    v[1][i]=0;
            }


for(i=1; i<=M; i++)                             //prima coloana
            {if(v[i][0]==v[0][1])
                        v[i][1]=1;
            else
                        if(v[i-1][1]==1 && i-1!=0)
                                                v[i][1]=1;
                        else
                                    v[i][1]=0;
            }



for(i=2; i<=N; i++)
            {for(j=2; j<=M; j++)

                        if(v[0][j]==v[i][0])
                                    v[i][j]=v[i-1][j-1]+1;
                        else
                                    if(v[i][j-1]>v[i-1][j])
                                                            v[i][j]=v[i][j-1];
                                    else
                                                v[i][j]=v[i-1][j];

            }




for(i=0; i<=N; i++)
            {for(j=0; j<=M; j++)
                        cout<<v[i][j]<<" ";
            cout<<endl;
            }

reconstruire(N,M);


return 0;
}
