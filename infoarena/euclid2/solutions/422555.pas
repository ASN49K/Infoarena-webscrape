program ada;
var n,a,b,i:longint;
f,g:text;
function cmmdc (x,y:longint):longint;
var r:longint;
begin
while y<>0 do begin
r:=x mod y;
x:=y;
y:=r;
end;
cmmdc:=x;
end;
begin
assign (f,'euclid2.in');
reset (f);
assign (g,'euclid2.out');
rewrite (g);
readln (f,n);
for i:=1 to n do
begin
readln (f,a,b);
writeln (g,cmmdc (a,b));
end;
close (f);
close (g);
end.
