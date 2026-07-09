var a,b:longint;f,g:text;

Function c(a,b:longint):longint;
var aux:longint;
begin
while b<>0 do
  Begin
  aux:=a;
  a:=b;
  b:=aux mod b;
  end;
c:=a;
end;

Begin
assign(f,'euclid2.in');reset(f);
assign(g,'euclid2.out');rewrite(g);
readln(f,a);

repeat
 readln(f,a,b);
 write(g,c(a,b),chr(10));
until eof(f);

close(f);
close(g);
end.
