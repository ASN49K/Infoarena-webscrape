type matrix=array[0.. 1024,0..1024] of integer;
vektor=array[0..1024]of integer;
var a,b:vektor;
x:matrix;
m,n,i,j,max:integer;
f,g:text;


begin
assign(f,'cmlsc.in');
reset(f);

read(f,m);
readln(f,n);
for i:=1 to m do read(f,a[i]);
readln(f);
for i:=1 to n do read(f,b[i]);
close(f);

for i:=1 to m do
begin
  for j:=1 to n do
  if i=j
  then
    x[i,j]:=x[i-1,j]+1
  else x[i,j]:=x[i-1,j];
end;
assign(g,'cmlsc.out');
rewrite(g);
max:=x[m,n];
writeln(g,max);


i:=m;
for j:=1 to n do
if x[i,j]>x[i,j-1]
then
writeln(g,b[j]);
close(g);
end.
