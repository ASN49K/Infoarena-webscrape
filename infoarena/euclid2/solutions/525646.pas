program euclid2;
var n,a,b,i:longint;
    fin,fout:text;
begin
assign(fin,'euclid2.in');
reset(fin);
assign(fout,'euclid2.out');
rewrite(fout);
read(fin,n);
for i:=1 to n do
begin
read(fin,a,b);
  while a<>b do
    begin
      if a>b then
        a:=a-b
      else
        b:=b-a;
    end;


writeln(fout,a);
end;
close(fin);
close(fout);

end.