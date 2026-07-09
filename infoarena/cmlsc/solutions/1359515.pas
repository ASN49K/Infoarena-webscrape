program cel_mai_lung_subsir_comun;
const nmax=1024;
var a,b,sir:array[1..nmax] of integer;
    d:array[1..nmax,1..nmax] of integer;
    n,m,i,j,bst,k:integer;
    f,g:text;

function max(a,b:integer):integer;
begin
 if a>b then
  max:=a
 else
  max:=b;
end;

begin
 assign(f,'cmlsc.in'); reset(f);
 assign(g,'cmlsc.out'); rewrite(g);
 readln(f,m,n);
 for i:=1 to m do
  read(f,a[i]);
 for i:=1 to n do
  read(f,b[i]);
 for i:=2 to m+1 do
  for j:=2 to n+1 do
   if a[i-1]=b[j-1] then
    d[i,j]:=1+d[i-1,j-1]
   else
    d[i,j]:=max(d[i-1,j],d[i,j-1]);
 k:=d[i,j]; bst:=k;
 while (i>1) and (j>1) do
  if a[i-1]=b[j-1] then
   begin
    sir[k]:=a[i-1];
    k:=k-1;
    i:=i-1;
    j:=j-1;
   end
  else
   if d[i-1,j]<d[i,j-1] then
    j:=j-1
   else
    i:=i-1;
 writeln(g,bst);
 for i:=1 to bst do
  write(g,sir[i],' ');
 close(f);
 close(g);
end.
