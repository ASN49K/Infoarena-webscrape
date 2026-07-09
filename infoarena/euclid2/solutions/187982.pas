var a,b,t,i:longint;
        f,g:text;
procedure cmmdc(a,b:longint);
begin
if b=0 then writeln(g,a)
else cmmdc(b,a mod b);
end;
begin
assign(f,'euclid2.in');
assign(g,'euclid2.out');
reset(f);
rewrite(g);
readln(f,t);
for i:=1 to t do
        begin
        readln(f,a,b);
        cmmdc(a,b);
        end;
close(f);
close(g);
end.
