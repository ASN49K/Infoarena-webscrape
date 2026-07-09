Program euclid;
var t,a,b,i:longint;
        f,g:text;
function cmmdc(a,b:longint):longint;
begin
  if b=0 then cmmdc:=a
        else cmmdc:=cmmdc(b, a mod b);
end;

begin
assign(f,'date.in');
reset(f);
readln(f,t);
assign(g,'date.out');
rewrite(g);
for i:=1 to t do begin
  readln(f,a,b);
  writeln(g,cmmdc(a,b));
end;
close(f); close(g);
end.