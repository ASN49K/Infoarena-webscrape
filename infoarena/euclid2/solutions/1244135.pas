var i,t,a,b,d:integer;
f,g:text;
begin
assign(f,'euclid2.in');reset(f);
assign(g,'euclid.out');rewrite(g);
read(f,t);
for i:=1 to t do begin
while not eof(f) do readln(f,a,b);
While a<>b do
if (a>b) then a:=a-b else b:=b-a;
d:=a;
if d>1 then writeln(g,d) else writeln(g,'');
end;
close(f);
close(g);
end.
