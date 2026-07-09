Program Cmlsc;
var A,B,C:array[byte] of 1..1024;
n,m,i,j,nr: byte;
f,g:text;
begin
assign(f,'cmlsc.in');
assign(g,'cmlsc.out');
reset(f);
rewrite(g);
readln(f,n,m);
for i:=1 to n do
 read(f,A[i]);
readln;
for i:=1 to m do
 read(f,B[i]);
nr := 0;
for i:=1 to n do
 for j:=1 to m do
  if A[i] = B[j] then begin
  nr:= nr + 1;
  C[nr]:= A[i];
  end;
writeln(nr);
for i:=1 to nr do
 write(g,C[i]);
close(f);
close(g);
end.