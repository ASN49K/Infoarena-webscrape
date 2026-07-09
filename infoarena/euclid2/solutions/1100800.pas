program Euclid;
type qw=array[1..100] of integer;
var
a,b,s:qw;
r,n,k,i,l:integer;
f,g:text;

procedure euclid(x,y:integer);
begin
r:=x mod y;
if r=0 then
       begin
       s[i]:=y;
       exit;
       end
       else
       begin
       x:=y;
       y:=r;
       euclid(x,y);
       end;
end;

begin
assign(f,'euclid2.in'); reset(f);
readln(f,n);
for i:=1 to n do
read(f,a[i],b[i]);
close(f);
for i:=1 to n do
euclid(a[i],b[i]);
for i:=1 to n do
writeln(s[i]);
readln;
end.