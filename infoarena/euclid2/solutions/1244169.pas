var a,b,d:longint;
i,t:smallint;
f,g:text;
begin
assign(f,'euclid2.in');reset(f);
assign(g,'euclid2.out');rewrite(g);
read(f,t);
for i:=1 to t do begin
while not eof(f) do begin
readln(f,a,b);
While a<>b do
if (a>b) then a:=a-b else b:=b-a;
d:=a;
writeln(g,d);
end;
end;
close(f);
close(g);
end.
