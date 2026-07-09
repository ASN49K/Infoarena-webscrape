var a,b,t,d:longint;
begin
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
end.