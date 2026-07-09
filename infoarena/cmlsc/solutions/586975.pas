program p1;
var f1,f2:text;
    i,n,k,m,j:integer;
    a,b,c:array[1..2000]of integer;
begin
 assign(f1,'cmlsc.in'); reset(f1);
 assign(f2,'cmlsc.out'); rewrite(f2);
 read(f1,n,m);
 for i:=1 to n do
  read(f1,a[i]);
 for i:=1 to m do
  read(f1,b[i]);

 for i:=1 to n do
  for j:=1 to m do
   if a[i]=b[j] then begin
                      inc(k);
                      c[k]:=a[i];
                     end;
 writeln(f2,k);
 for i:=1 to k do
  write(f2,c[i],' ');

 close(f1); close(f2);
End.