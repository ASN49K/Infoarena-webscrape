Program impartire;
var
a,b,r:longint;
cin,cout:text;
begin
assign(cin,'euclid.in');
reset(cin);
assign(cout,'euclid.out');
rewrite(cout);
read(cin,a,b);
r:=a mod b;
while r<>0 do
  begin
  a:=b;
  b:=r;
  r:=a mod b;
  end;
writeln(cout,b);
close(cin);
close(cout);
end.