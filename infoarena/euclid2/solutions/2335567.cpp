/*#include <stdio.h>

int main(void)
{
  float a,b,c;
  printf("Scrie 3 numere:\n");
  scanf("%f %f %f", &a, &b, &c);
  printf("Numerele tale sunt: %f %f %f ", a,b,c);
  return 0;
}*/
/*#include<iostream>
using namespace std;

int main(){
    int matrice[10][10], N,M, suma=0;
    cin>>N>>M;
    for(int i=0; i<N; i++)
      for(int j=0; j<M; j++)
          cin>>matrice[i][j];
        cout<<"\n\n\n";
    for(int i=0; i<N; i++){
      for(int j=0; j<M; j++)
          cout<<matrice[i][j]<<' ';
      cout<<'\n';
        }
      cout<<"\n\n\n";
    for (int i = 0;  i<N; i++) {
        suma+=matrice[i][i];
    }
    cout<<suma;
}
#include<stdio.h>
int main (){
  int mat[50][50], suma=0, n, m;
  scanf("%d%d", &n, &m);
  for(int i=0; i<n; i++)
    for(int j=0; j<m; j++)
        scanf("%d",&mat[i][j]);
  for (int i=0; i<n; i++)
    suma+=mat[i][i];
  printf("%d",suma);

  return 0;
}
#include <stdio.h>
int main (void){
  float x,y,t,z;
  int m,n,rest;
  printf("Scrieti 2 numere reale si 2 intregi: ");
  scanf("%f%f%d%d", &x,&y,&m,&n);
  t=x*y; z=x/y;
  printf("produsul nr este : %0.2f iar impartirea lor este : %0.2f \n" , t,z );
  if ( x>m) {
      printf("Numarul mai mare este: %0.2f" ,x );
  }else
  printf ("Numarul mai mare este %d \n" , m);
  rest= m%(2*n);
  printf ("Restul impartirii este: %d\n " , rest);
   if (n%2==1)
    printf("N este impar\n");
    else
     printf("N nu este impar");
  return 0;

}*/
//
//  main.cpp
//  Minesweeper
//
//  Created by Tiberiu Petru Trimbitas on 12/9/18.
//  Copyright © 2018 Wellcode. All rights reserved.
//
/*
#include <iostream>
#include <vector>
#include <algorithm>
#include <ctime>
#include <cstdlib>
#define BOMB '*'
#define UNCOVERED_CELL '+'
#define UP 'w'
#define DOWN 's'
#define LEFT 'a'
#define RIGHT 'd'
#define USER_POS '$'
#define PRESS_COMMAND 'p'
using namespace std;

int lines = 9, columns = 9, bombs = 10, is_game_finished = 0;
char board[100][100], user_board[100][100];
bool uncovered[100][100];
int user_line = 0;
int user_col = 0;

bool is_inside(int line, int col) {
    return 0 <= line && line < lines && 0 <= col && col < columns;
}

void place_bombs() {
    vector<pair<int, int> > positions;
    for (int line = 0; line < lines; ++line)
        for (int col = 0; col < columns; ++col)
            positions.push_back(make_pair(line, col));
    random_shuffle(positions.begin(), positions.end());
    for (int idx = 0; idx < bombs; ++idx)
        board[positions[idx].first][positions[idx].second] = BOMB;
}

int compute_neighbours(int line, int col) {
    int num_bombs = 0;
    for (int line_offset = -1; line_offset <= 1; ++line_offset)
        for (int col_offset = -1; col_offset <= 1; ++col_offset) {
            int next_line = line + line_offset, next_col = col + col_offset;
            if (is_inside(next_line, next_col) && board[next_line][next_col] == BOMB)
                ++num_bombs;
        }
    return num_bombs;
}

void init_board() {
    for (int line = 0; line < lines; ++line)
        for (int col = 0; col < columns; ++col)
            board[line][col] = user_board[line][col] = UNCOVERED_CELL;
    place_bombs();
    for (int line = 0; line < lines; ++line)
        for (int col = 0; col < columns; ++col)
            if (board[line][col] != BOMB)
                board[line][col] = compute_neighbours(line, col) + '0';
}

void print_board() {
    for (int line = 0; line < lines; ++line) {
        for (int col = 0; col < columns; ++col)
            cout << user_board[line][col];
        cout << '\n';
    }
}

void trigger_press(int line, int col) {
    if (uncovered[line][col])
        return;
    if (board[line][col] == BOMB) {
        is_game_finished = 1;
        cout << "GAME OVER!\n";
        for (int line = 0; line < lines; ++line) {
            for (int col = 0; col < columns; ++col)
                if (board[line][col] == BOMB)
                    cout << BOMB;
                else
                    cout << user_board[line][col];
            cout << "\n";
        }
    } else {
        uncovered[line][col] = 1;
        user_board[line][col] = board[line][col];
        if (user_board[line][col] == '0') {
            for (int line_offset = -1; line_offset <= 1; ++line_offset)
                for (int col_offset = -1; col_offset <= 1; ++col_offset) {
                    int next_line = line + line_offset, next_col = col + col_offset;
                    if (is_inside(next_line, next_col))
                        trigger_press(next_line, next_col);
                }
        }
    }
}

void process_command(char command) {
    int next_line = user_line, next_col = user_col;
    if (command == UP) {
        --next_line;
    } else if (command == DOWN) {
        ++next_line;
    } else if (command == LEFT) {
        --next_col;
    } else if (command == RIGHT) {
        ++next_col;
    }
    if (!is_inside(next_line, next_col))
        return;
    if (!uncovered[user_line][user_col])
        user_board[user_line][user_col] = UNCOVERED_CELL;
    else
        user_board[user_line][user_col] = board[user_line][user_col];
    user_line = next_line;
    user_col = next_col;
    user_board[user_line][user_col] = USER_POS;

    if (command == PRESS_COMMAND) {
        trigger_press(user_line, user_col);
    }
}

void start_game() {
    user_line = user_col = 0;
    is_game_finished = 0;
    init_board();
    user_board[user_line][user_col] = USER_POS;
}

bool check_game_finished() {
    int covered = 0;
    for (int line = 0; line < lines; ++line)
        for (int col = 0; col < columns; ++col)
            covered += 1 - uncovered[line][col];
    if (covered == bombs) {
        cout << "Congrats!\nYou won the game!\n";
        is_game_finished = 1;
        return true;
    }
    return false;
}

int main() {
    srand(time(0));
    start_game();
    while (!is_game_finished) {
        print_board();
        char command;
        cout << "Input command: ";
        cin >> command;
        process_command(command);
        is_game_finished = check_game_finished();
    }

    return 0;
}
 */
 /*
 #include<iostream>
 using namespace std;
 bool v[50000000];
 int main(){
     int n,nr=0;
     cin>>n;
     for(int i=2; i*i<=n; i++)
          if(!v[i])
              for(int j=i; j<=n/i; j++)
                      v[i*j]=1;
     for(int i=2; i<=n; i++)
         if(!v[i])
             nr++;
     cout<<nr;
     return 0;
 }
 */
 /*#include<iostream>
 using namespace std;

 int n;
 char sir[10];

 void genereaza(int lg, char ult_lit) {
   if (lg == n) {
     cout<<sir<<"\n";
     return;
   }
   for (char i = ult_lit; i <= 'z'; ++i) {
     sir[lg] = i;
     genereaza(lg + 1, i + 1);
   }
 }

 int main() {
   cin>>n;
   genereaza(0, 'a');
   return 0;
 }
*/
#include<fstream>
std::ifstream f("kfib.in");
std::ofstream g("kfib.out");
int main(){
  int x=0,y=1,z,k;f>>k;
  while(k--%666014)
  z=(x+y)%666013, x=y , y=z;
  g<<x;
}
