#include <iostream>
#include <fstream>

using namespace std;

int m, n, t;
int mPos;
bool F;

int V[257];
int K[257];
int D[257][2];
int S[257];

int main()
{
      ifstream i("cmlsc.in");
      ofstream o("cmlsc.out");

      i >> m >> n;

      if(m >= n)
      {
            t = m;
            F = true;
      }

      else
      {
            t = n;
            F = false;
      }

      for(int a = 0; a < m; a++)
      {
            i >> V[a];
      }

      for(int a = 0; a < n; a++)
      {
            i >> K[a];
      }

      if(F)
      {
            for(int a = 0; a < t; a++)
            {
                  for(int b = 0; b < n; b++)
                  {
                        if(V[a] == K[b])
                        {
                              D[a][0] = 1;
                        }
                  }

                  if(D[a][0])
                  {
                        for(int b = a; b > 0; b--)
                        {
                              if(V[a] > V[b])
                              {
                                    if(D[b][0] + 1 > D[a][0])
                                    {
                                          D[a][0] = D[b][0] + 1;
                                          D[a][1] = b;
                                    }

                                    if(D[a][0] > D[mPos][0])
                                    {
                                          mPos = a;
                                    }
                              }
                        }
                  }
            }
      }

      else
      {
            for(int a = 0; a < t; a++)
            {
                  for(int b = 0; b < n; b++)
                  {
                        if(K[a] == V[b])
                        {
                              D[a][0] = 1;
                        }
                  }

                  if(D[a][0])
                  {
                        for(int b = a; b > 0; b--)
                        {
                              if(K[a] > K[b])
                              {
                                    if(D[b][0] + 1 > D[a][0])
                                    {
                                          D[a][0] = D[b][0] + 1;
                                          D[a][1] = b;
                                    }

                                    if(D[a][0] > D[mPos][0])
                                    {
                                          mPos = a;
                                    }
                              }
                        }
                  }
            }
      }

      o << D[mPos][0] << '\n';
      int j = D[mPos][0] - 1;
      int p = j;

      while(mPos)
      {
            if(F)
            {
                  S[j] = V[mPos];
                  mPos = D[mPos][1];

                  j = j - 1;
            }

            else
            {
                  S[j] = K[mPos];
                  mPos = D[mPos][1];

                  j = j - 1;
            }
      }

      for(int a = 0; a <= p; a++)
      {
            o << S[a] << " ";
      }

    return 0;
}
