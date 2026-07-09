program algoritm_euclid_2_cmmdc;
var a,i,t,b:longint; f,g:text;
function cmmdc(a:integer; b:integer):integer;
begin
if a=b then cmmdc:=a else
 if a>b then cmmdc:=cmmdc(a-b,b) else
  if a<b then cmmdc:=cmmdc(a,b-a);
end;
begin
assign(f,'euclid2.in');
assign(g,'euclid2.out');
reset(f); rewrite(g);
readln(f,t);
for i:= 1 to t do
begin
readln(f,a,b);
writeln(g,cmmdc(a,b));
end;
close(f); close(g);

end.