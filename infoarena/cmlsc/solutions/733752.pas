program balbal;
var a:array[0..1024,0..1024] of word;
    i,j,n,m,b:word;
    x,y:array[1..1024] of byte;

BEGIN
assign(input,'clmsc.in');
reset(input);
readln(n,m);

for i:=1 to n do
a[n,0]:=0;
for i:=1 to m do
a[0,m]:=0;
for i:=1 to n do
read(x[i]);
readln;
for i:=1 to m do
read(y[i]);
close(input);

for i:=1 to n do
  for j:=1 to m do
    if x[i]=y[j] then a[i,j]:=1+a[i-1,j-1]
      else
        if a[i-1,j]>a[i,j-1]
          then
            a[i,j]:=a[i-1,j]
          else
            a[i,j]:=a[i,j-1];
b:=1;
assign(output,'cmlsc.out');
rewrite(output);
writeln(a[n,m]);
for i:=1 to n do

    for j:=1 to m do
     if a[i,j]=b then
     begin
     write(x[i],' ');
     inc(b);
     end;
close(output);

end.