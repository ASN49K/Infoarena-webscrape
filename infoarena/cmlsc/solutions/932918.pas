program subsir;
var f,g:text;
    n,m,i,j,k:integer;
    x,y:array[1..1024] of byte;
    a:array[0..1024,0..1024] of integer;
    sol:array[1..1024] of byte;

function max (a,b:integer):integer;
begin
 if a>b then max:=a
 else max:=b;
end;

begin
 assign (f,'cmlsc.in'); reset (f);
 assign (g,'cmlsc.out'); rewrite  (g);
 readln (f,n,m);
 for i:=1 to n do read (f,x[i]);
 for i:=1 to m do read (f,y[i]);
 for i:=1 to n do
  for j:=1 to m do
   if x[i]=y[j] then
    a[i,j]:=1+a[i-1,j-1]
   else a[i,j]:=max(a[i-1,j],a[i,j-1]);
  writeln (g,a[n,m]);
  i:=n; j:=m;
  for k:=1 to a[n,m] do
  begin
   while a[i,j]=a[i-1,j] do dec(i);
   while a[i,j]=a[i,j-1] do dec(j);
   sol[k]:=x[i];
   dec(i);
  end;
  for i:=a[n,m] downto 1 do write (g,sol[i],' ');
  close (F); close (g);
end.
