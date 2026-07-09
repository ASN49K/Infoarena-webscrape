program cmlsc;
var a,b,p:array [1..100] of integer;
    f1,f2:text;
    n,m,o,z,i:integer;
begin
assign(f1,'cmlsc.in');
assign(f2,'cmlsc.out');
reset(f1);
rewrite(f2);
read(f1,n);
readln(f1,m);
for i:=1 to n do
  read(f1,a[i]);
for i:=1 to m do
  read(f1,b[i]);
z:=0;
for i:=1 to n do
  for o:=i to m do
    if a[i]=b[o] then begin
      p[z]:=a[i];
      z:=z+1;
      end;
writeln(f2,z);
for i:=0 to z-1 do
write(f2,p[i],' ');
close(f1);
close(f2);
end.
