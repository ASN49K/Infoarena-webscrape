program balbal;
var a:array[0..1024,0..1024] of word;
    i,j,n,m,b:word;
    x,y:array[1..1024] of byte;

procedure afis(i,j:word);
Begin
if (i>0) and (j>0) and (x[i]=y[i])
 then
   begin
     afis(i-1,j-1);
     write(x[i], ' ');
   end
   else
   if (j>0) and ((i=0) or  (a[i,j-1]>=a[i-1,j]))
    then
    begin
    afis(i,j-1);
    write(y[j], '  ')
    end
    else
    if (i>0) and ((j=0) or (a[i,j-1]<a[i-1,j]))
    then
    begin
    afis(i-1,j);
    write(x[i], ' ');
    end;
end;

BEGIN
assign(input,'cmlsc.in');
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
close(output);
afis(n,m)
end.
