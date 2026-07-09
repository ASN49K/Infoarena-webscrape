var b,a,i,j,bst:longint;
    f:text;
    n:array[1..1024] of integer;
    m:array[1..1024] of integer;
    d:array[1..200,1..200] of byte;
    sir:array[1..1024] of integer;
begin
assign(f,'cmlsc.in'); reset(f);
readln(f,a,b); bst:=0;
for i:=1 to a do
read(f,m[i]);
readln(f);
for i:=1 to b do
read(f,n[i]);
close(f);
 for i:=1 to a do
   for j:=1 to b do
    if m[i]=n[j] then begin
      sir[bst]:=m[i];
      inc(bst);
      break;
      end;
assign(f,'cmlsc.out'); rewrite(f);
writeln(f,bst);
for i:=1 to bst do
write(f,sir[i],' ');
close(f);
end.