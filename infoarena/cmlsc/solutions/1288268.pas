Program clmsc;
Type matrice=array[0..102,0..102] of integer;
     vector=array[1..202] of integer;
Var a:matrice;
    x,y:vector;
    n,m,i,j:integer;
    f,g:text;
Begin
 assign(f,'cmlsc.in');
 reset(f);
 readln(f,n,m);
 for i:=1 to n do
  read(f,x[i]);
 readln(f);
 for i:=1 to m do
  read(f,y[i]);
 close(f);
 for i:=0 to n do
  for j:=0 to m do
    if (i = 0) or (j = 0) then a[i,j]:=0
                          else
                           if x[i] = y[j] then a[i,j]:=a[i-1,j-1] + 1
                                          else
                                           if a[i-1,j] > a[i,j-1] then a[i,j]:=a[i-1,j]
                                                                  else a[i,j]:=a[i,j-1];
 assign(g,'cmlsc.out');
 rewrite(g);
 writeln(g,a[n,m]);
 close(g);
End.
