program euclid2;
var c,n,a,b,i:longint;
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
  while (a<>0)and(b<>0) do
    begin
      if a>b then
        a:=a mod b
      else
        b:=b mod a;
    end;
  if a>b then
    begin
      if a<>0 then
        c:=a;
    end
  else
	  if b<>0 then
		  c:=b;

writeln(fout,c);
end;
close(fin);
close(fout);

end.