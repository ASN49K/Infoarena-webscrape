program subsir;
var f,g:text;
    n,m,i,j,k:integer;
    a,b:array[1..1024] of integer;
    v:array[0..1024,0..1024] of integer;
    solutie:array[1..1024] of integer;

function det_max (a,b:integer):integer;
begin
 if a>b then
  det_max:=a
 else
  det_max:=b;
end;

begin
 assign (f,'cmlsc.in'); reset (F);
 assign (g,'cmlsc.out'); rewrite (G);
 readln (f,m,n);
 for i:=1 to m do
  read (f,a[i]);
 readln (f);
 for j:=1 to n do
  read (f,b[j]);
 for i:=1 to m do
  for j:=1 to n do
   if a[i]=b[j] then
    v[i,j]:=1+v[i-1,j-1]
   else
    v[i,j]:=det_max(v[i-1,j],v[i,j-1]);
  writeln (g,v[m,n]);
  i:=m; j:=n;
  for k:=1 to v[m,n] do
  begin
   while v[i,j]=v[i-1,j] do
    i:=i-1;
   while v[i,j-1]=v[i,j] do
    j:=j-1;
   solutie[k]:=a[i];
   i:=i-1;
  end;
  for i:=v[m,n] downto 1 do
   write (g,solutie[i], ' ');
  close (F); close (G);
end.