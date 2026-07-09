{algoritmul lui Euclid}

var f,g:text;

function cmmdc(a,b:longint):longint;
var r:longint;
begin
while b<>0 do
      begin
      r:=a mod b;
      a:=b;
      b:=r;
      end;
cmmdc:=a;
end;

procedure citire_rezolvare;
var a,b,t,i:longint;
begin
assign(f,'euclid2.in'); reset(f);
assign(g,'euclid2.out'); rewrite(g);

readln(f,t);

for i:=1 to t do
    begin
    readln(f,a,b);
    writeln(g,cmmdc(a,b));
    end;

close(f);
close(g);
end;


begin
citire_rezolvare;
end.