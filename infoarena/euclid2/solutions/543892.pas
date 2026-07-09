program pascal;
var a,b:longint;
    fin,fout:text;

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
readln(fin, a, b);
close(fin);
assign(fout, 'euclid2.out'); rewrite(fout);
write(fout, cmmdc(a,b));
close(fout);
end.