program euclid;
var a,b,c : longint;
    f : text;
begin
assign(f,'euclid2.in');
reset(f);
read(f,a,b);
close(f);
while b <> 0 do begin
c := b;
b := a mod b;
a := c;
end;
assign(f,'euclid2.out');
rewrite(f);
write(f,a);
close(f);
end.

