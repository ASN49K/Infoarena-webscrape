program celmlungsub;
type vector=array[1..1024]of byte;
var m,n,c,i,j:word;
    a,b,d:vector;
    f:text;
begin
 assign(f,'cmlsc.in');
 reset(f);
 readln(f,m,n);
 for i:=1 to m do
  read(f,a[i]);
 for i:=1 to n do
  read(f,b[i]);
 close(f);
 assign(f,'cmlsc.out');
 rewrite(f);
 c:=0;
 for i:=1 to m do
  for j:=1 to n do
   if a[i]=b[j] then
    begin
     inc(c);
     d[c]:=a[i];
    end;
 writeln(f,c);
 for i:=1 to c do
 write(f,d[i],' ');
 close(f);
 end.
