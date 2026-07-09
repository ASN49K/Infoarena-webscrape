program euclid2;
var t,a,b,i:longint;
    f,g:text;
function cmmdc(x,z:longint):longint;
begin
  if x mod z=0 then cmmdc:=z
      else cmmdc:=cmmdc(z,x mod z);
end;
begin
assign(f,'euclid2.in'); reset(f);
assign(g,'euclid2.out'); rewrite(g);
readln(f,t);
for i:=1 to t do begin
                 readln(f,a,b);
                 writeln(g,cmmdc(a,b));
                 end;
close(f);
close(g);
end.
