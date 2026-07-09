program subsir_comun;
var f,g:text;
    a,b:array[1..1024] of byte;
    c:array[0..1024,0..1024] of integer;
    n,m,i,j,k:integer;
    sol:array [1..1024] of byte;

function max (a,b:byte):byte;
begin
 if a>b then
  max:=a
 else
  max:=b;
end;

begin
 assign (f,'cmlsc.in'); reset (f);
 assign (g,'cmlsc.out'); rewrite (g);
 readln (f,n,m);
 for i:=1 to n do
  read (f,a[i]);
  readln (f);
 for i:=1 to m do
  read (f,b[i]);
 for i:=1 to n do
  for j:=1 to m do
   if a[i]=b[j] then
    c[i,j]:=1+c[i-1,j-1]
   else
    c[i,j]:=max(c[i-1,j],c[i,j-1]);
  writeln (g,c[n,m]);
  i:=n; j:=m;
  for k:=1 to c[n,m] do
  begin
   while c[i,j]=c[i-1,j] do
    dec(i);
   while c[i,j]=c[i,j-1] do
    dec(j);
   sol[k]:=a[i];
   dec(i);
  end;
  for k:=c[n,m] downto 1 do
   write (g,sol[k],' ');
 close (f); close (g);
end.