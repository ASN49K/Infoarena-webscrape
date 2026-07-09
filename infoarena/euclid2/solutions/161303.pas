program euclid2;
var a,b,i,T : longint;
    f,g : text;
function cmmdc(x,y:longint):longint;
var c : longint;
begin

while y<>0 do begin
c := y mod x;
x := y;
y := c;
end;
cmmdc := x;
end;

begin
assign(f,'euclid2.in');
reset(f);
assign(g,'euclid2.out');
rewrite(g);

readln(f,T);

for i := 1 to T do begin
readln(f,a,b);
writeln(g,cmmdc(a,b));
end;

close(f);
close(g);

end.
