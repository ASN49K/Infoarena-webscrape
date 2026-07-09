program euclid2;
var a,b,i,T : longint;
    f,g : text;

function cmmdc(a,b:longint):longint;
var r : longint;
begin
r := 1;
while r<>0 do begin
r := a mod b;
a := b;
b := r;
end;
cmmdc := a;
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
