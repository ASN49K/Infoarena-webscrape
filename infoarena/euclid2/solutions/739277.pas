var f,g:text;
a,b,i,t:longint;

function cmmdc(a,b:longint):longint;
var r:longint;
begin
 r:=1;
  while r<>0 do
   begin
   r:=a mod b;
   a:=b;
   b:=r;
   end;
   cmmdc:=a;
end;


begin
assign(f,'euclid2.in');  reset(f);
assign(g,'euclid2.out');  rewrite(g);
readln(f,t);
for i:=1 to t do
begin
readln(f,a,b);
writeln(g,cmmdc(a,b));

end;

close(f); close(g);

end.