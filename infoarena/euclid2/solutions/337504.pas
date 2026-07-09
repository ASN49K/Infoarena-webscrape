Program P1;
var a,b,i,n : integer;
    f,g : text;
Function cmmdc(a,b : integer) : integer;
begin
if a=0 then exit(b) else
if b=0 then exit(a) else exit(cmmdc(b,a mod b));
end;


begin
assign(f,'euclid2.in');    assign(g,'euclid.out');
reset(f);                  rewrite(g);
readln(f,n);
for i:=1 to n do
begin
readln(f,a,b);
writeln(g,cmmdc(a,b));
end;
close(f);
close(g);

end.
