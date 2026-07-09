var t,a,b,i,r:longint;
f,g: text;
begin
assign(f,'euclid2.in');
assign(g,'euclid2.out');
reset(f);rewrite(g);
readln(f,t);
for i:=1 to t do begin
readln(f,a,b);
while a<>b do begin if a>b then a:=a-b
                           else b:=b-a;end;
writeln(g,a);
end;
close(f);close(g);
end.
