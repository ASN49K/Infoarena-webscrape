program subsir1;
var f,g:text;
    a,b,solutie:array [1..1024] of integer;
    m,n,i,j,k:integer;
    c:array[0..1024,0..1024] of integer;


function maxim (a,b:integer):integer;
begin
 if a>b then
  maxim:=a
 else
  maxim:=b;
end;

begin
  assign (f,'cmlsc.in');reset (F);
  assign (g,'cmlsc.out'); rewrite (G);
  readln (f,m,n);
  for i:=1 to m do
   read (f,a[i]);
  readln (f);
  for i:=1 to n do
   read (f,b[i]);
  for i:=1 to m do
   for j:=1 to n do
    if a[i]=b[j] then
     c[i,j]:=1+c[i-1,j-1]
    else
     c[i,j]:=maxim (c[i-1,j],c[i,j-1]);
    writeln (g,c[m,n]);
    i:=m; j:=n;
    for k:=1 to c[m,n] do
    begin
     while c[i,j]=c[i-1,j] do
      i:=i-1;
     while c[i,j]=c[i,j-1] do
      j:=j-1;
     solutie[k]:=a[i];
     i:=i-1;
    end;
    for i:=c[m,n] downto 1 do
     write (g,solutie[i], ' ');
  close (f); close (g);
end.