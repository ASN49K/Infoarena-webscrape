program dsa;
const fi='cmlsc.in';
      fo='cmlsc.out';
var f,g:text;
    d:array[0..1024,0..1024] of integer;
    sir,v,x:array[1..1024] of integer;
    n,i,j,m,bst,i1:longint;
begin
assign(f,fi);
reset(f);
assign(g,fo);
rewrite(g);
read(f,n,m);
for i:=1 to n do
read(f,v[i]);
for j:=1 to n do
read(f,x[j]);
for i:=1 to n do
   for j:=1 to m do
     if v[i]=x[j] then
        d[i,j]:=1+d[i-1,j-1]
        else
        begin
        if d[i-1,j]>d[i,j-1] then
        d[i,j]:=d[i-1,j]
        else
        d[i,j]:=d[i,j-1];
        end;
writeln(g,d[n,m]);
i:=n; j:=m;
for i1:=d[n,m] downto 1 do
  begin
  while d[i, j]=d[i, j-1] do
  dec(j);
  while d[i, j]=d[i-1, j] do
  dec(i);
  sir[i1]:=v[i];
  dec(i);
  end;
for i := 1 to d[n, m] do write
(g,sir[i],' ');

   close(f);
   close(g);
   end.
