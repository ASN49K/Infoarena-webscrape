program euclid2;
var  f,g:text;
     a,b,t,i:longint;
function euclid(a,b:longint):longint;
   begin
     if b=0 then euclid:=a
       else euclid:=euclid(b,a mod b);
   end;
begin
assign(f,'euclid2.in'); reset(f);
assign(g,'euclid2.out'); rewrite(g);
readln(f,t);
for i:=1 to t do
  begin
    readln(f,a,b);
    writeln(g,euclid(a,b));
  end;
close(g);
close(f);
end.