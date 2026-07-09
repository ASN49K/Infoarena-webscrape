var r,a,b:int64;
f,g:text;
t,i:longint;
procedure diviz(a,b:int64):int64;
begin
if b=0 then diviz:=1
else diviz:=diviz(b,a mod b);
end;
begin
assign(f,'euclid2.in');reset(f);
assign(g,'euclid2.out');rewrite(g);
readln(f,t);
for i:=1 to t do
begin
readln(f,a,b);
writeln(g,diviz(a,b));
end;
close(f);
close(g);
end.