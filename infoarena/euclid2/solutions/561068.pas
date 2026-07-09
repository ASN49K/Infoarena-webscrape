program cmmdc;
var a,b,d,i,n:longint;
    fin,fout:text;
function cmmdc(a,b:longint):longint;
  begin
    if b=0 then
      cmmdc:=a
    else
      cmmdc:=cmmdc(b,a mod b);
  end;
begin
assign(fin,'euclid2.in');
reset(fin);
assign(fout,'euclid2.out');
rewrite(fout);
read(fin,n);
for i:=1 to n do
  begin
  read(fin,a,b);
  d:=cmmdc(a,b);
  writeln(fout,d);
  end;


close(fin);
close(fout);
end.