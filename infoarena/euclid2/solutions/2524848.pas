var a,b,t,d:longint;
begin
assign(input,'euclid2.in');
assign(output,'euclid2.out');
reset(input);
rewrite(output);
read(t);
while t<>0 do begin
read(a,b);
d:=a mod b;
while(d<>0) do begin
a:=b;
b:=d;
d:=a mod b end;
writeln(b);
dec(t);
end;
close(input);
close(output);
end.