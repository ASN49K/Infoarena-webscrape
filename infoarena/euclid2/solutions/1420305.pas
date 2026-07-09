program euclid;
type buf=array[0..1 shl 17] of char;
var a,b,n,i:longint;
function cmmdc(a,b:longint):longint;
begin
if b=0 then cmmdc:=a else cmmdc:=cmmdc(b,a mod b);
end;
begin
assign (input,'euclid2.in');
assign (output,'euclid2.out');
reset (input);
rewrite (output);
readln (n);
for i:=1 to n do begin
readln (a,b);
writeln (cmmdc(a,b));
end;
close (input);
close (output);
end.
