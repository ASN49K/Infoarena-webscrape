var r,a,b:int64;
f,g:text;
t,i:longint;
procedure div(a,b:int64):int64;
begin
if b=0 then div:=1
else div:=div(b,a mod b);
end;
begin
assign(f,'euclid2.in');reset(f);
assign(g,'euclid2.out');rewrite(g);
readln(f,t);
for i:=1 to t do
begin
readln(f,a,b);
writeln(g,euc(a,b));
end;
close(f);
close(g);
end.