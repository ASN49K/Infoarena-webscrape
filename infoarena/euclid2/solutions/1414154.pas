program euclid;
type buf=array[0..1 shl 17] of char;
var ff1,ff2:buf;
    n,x,y,i:longint;
    f1,f2:text;
function cmmdc(x,y:longint):longint;
var r:longint;
begin
while y>0 do begin
r:=x mod y;
x:=y;
y:=r;
end;
cmmdc:=x;
end;
begin
assign (f1,'euclid2.in');
assign (f2,'euclid2.out');
reset (f1);
rewrite (f2);
settextbuf(f1,ff1);
settextbuf(f2,ff2);
readln (f1,n);
for i:=1 to n do begin
readln (f1,x,y);
writeln (f2,cmmdc(x,y));
end;
close (f1);
close (f2);
end.
