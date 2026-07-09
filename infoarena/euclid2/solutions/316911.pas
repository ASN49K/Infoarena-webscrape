program euclid;
var a,b,n:longint;
begin
assign(input,'euclid2.in');
assign(output,'euclid2.out');
reset(input);
rewrite(output);
readln(input,n);
while n<>0 do begin
readln(input,a,b);
while a<>b do
 if a>b then a:=a- b else b:=b - a;
writeln(output,a);
n:=n-1;
end;
close(input);
close(output);
end.