program euclid2;
var t,a,b:longint;
     i:integer;
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
                 if (a=0) or (b=0) then writeln(g,a+b) else
                 writeln(g,cmmdc(a,b));
                 end;
close(f);
close(g);
end.