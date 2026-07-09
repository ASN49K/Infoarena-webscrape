Program impartire;
var
a,b,r,i,n:longint;
cin,cout:text;
begin
assign(cin,'euclid.in');
reset(cin);
assign(cout,'euclid.out');
rewrite(cout);
read(cin,n);

for i:=1 to n do
  begin
  read(cin,a,b);
  r:=a mod b;
  while r<>0 do
    begin
    a:=b;
    b:=r;
    r:=a mod b;
    end;
    writeln(cout,b);
  end;

close(cin);
close(cout);
end.