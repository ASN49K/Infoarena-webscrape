program euclid;
type buf=array[0..1 shl 17] of char;
var a,b,n,i:longint; b1,b2:buf;
function cmmdc(a,b:longint):longint;
var r:longint;
begin
while b>0 do begin
r:=a mod b;
a:=b;
b:=r;
end;
cmmdc:=a;
end;
begin
assign (input,'euclid2.in');
assign (output,'euclid2.out');
reset (input);
rewrite (output);
settextbuf(input,b1);
settextbuf(output,b2);
readln (n);
for i:=1 to n do begin
readln (a,b);
writeln (cmmdc(a,b));
end;
close (input);
close (output);
end.
