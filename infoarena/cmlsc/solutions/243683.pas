program cmlsc;
type vector=array[1..1024]of byte;
var a,b:vector;
    f:text;
    m,n,i,j,c:word;
begin
 assign(f,'cmlsc.in');
 reset(f);
 readln(f,m,n);
 for i:=1 to m do
  read(f,a[i]);
 for i:=1 to n do
  read(f,b[i]);
 close(f);
 c:=0;
 for i:=1 to m do
  for j:=1 to n do
   if a[i]=b[j] then
    begin
     inc(c);
     a[c]:=b[j];
    end;
 assign(f,'cmlsc.out');
 rewrite(f);
 writeln(f,c);
 for i:=1 to c do
  write(f,a[i],' ');
 close(f);
 end.

