program euclid;
var a,b,n,c:longint;
begin
assign(input,'euclid2.in');
assign(output,'euclid2.out');
reset(input);
rewrite(output);
readln(input,n);
while n<>0 do begin
readln(input,a,b);
while b<>0 do
begin
c:=a div b;
a:=b;
b:=c ;
end;
writeln(output,a);
n:=n-1;
end;
close(input);
close(output);
end.