Program cmmdc;
var x, y, n : int64;
    f, g : text;
{Medota scaderii}
function cmmdc(a, b : longint) : longint;
var m : longint;
begin
if a>b then
   begin
     m:=a;
     while m>=0 do
       m:=m-b;
   end
else
   begin
    m:=b;
    while m>=0 do
      m:=m-a;
   end;
cmmdc:=m;
end;
begin
assign(f,'euclid2.in'); assign(g,'euclid2.out');
reset(f); rewrite(g);
readln(f,x,y);
n:=cmmdc(x,y);
if n<0 then
n:=n*-1;
writeln(g,n);
close(f); close(g);
end.
