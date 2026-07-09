program euclid2;
var nr,i:longint;
     a,b,r:longint;
     f,g:text;

function cmmdc(a,b:longint):longint;
begin
  if b=0 then
    cmmdc:=a
  else
    cmmdc:=cmmdc(b,a mod b);
end;

begin
  assign(f,'euclid2.in');
  assign(g,'euclid2.out');
  reset(f);
  rewrite(g);
  readln(f,nr);
  for i:=1 to nr do
    begin
      readln(f,a,b);
      writeln(g,cmmdc(a,b));
    end;
  close(f);
  close(g);
end.