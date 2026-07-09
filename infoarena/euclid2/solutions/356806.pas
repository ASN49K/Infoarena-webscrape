program euclid;

var
    t,i:longint;
    a,b:longint;
    f,g:text;

procedure eucl(a,b:longint);
var r:longint;
begin
repeat
     r:=a mod b;
     a:=b;
     b:=r;
   until b=0;
   writeln(g,a);
end;
begin

assign(f,'euclid2.in');
reset (f);
read(f,t);
assign(g,'euclid2.out');
rewrite(g);
for i:=1 to t do
   begin
   read(f,a,b);
   eucl(a,b);
   end;
close(f);
close(g);
end.
