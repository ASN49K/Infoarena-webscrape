program pascal;
var a,b:longint;
    fin,fout:text;
	n:longint;
	i:longint;

function cmmdc(aa:longint; bb:longint):longint;
var rest:longint;
begin
  while (bb <> 0) do begin
      rest:=aa mod bb;
	  aa:=bb;
	  bb:=rest;
  end;
  cmmdc:=aa;
end;

begin
assign(fin, 'euclid2.in'); reset(fin);
assign(fout, 'euclid2.out'); rewrite(fout);
readln(fin, n);
for i:=1 to n do begin
readln(fin, a, b);
writeln(fout, cmmdc(a,b));
end;
close(fin);
close(fout);
end.