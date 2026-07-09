Program euclid;
var t,a,b,i:integer;
        f,g:text;
function cmmdc(a,b:integer):integer;
begin
  if b=0 then cmmdc:=a
        else cmmdc:=cmmdc(b, a mod b);
end;

begin
assign(f,'euclid2.in');
reset(f);
readln(f,t);
assign(g,'euclid2.out');
rewrite(g);
for i:=1 to t do begin
  readln(f,a,b);
  writeln(g,cmmdc(a,b));
end;
close(f); close(g);
end.