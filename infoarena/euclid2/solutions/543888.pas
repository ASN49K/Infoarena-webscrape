program pascal;
var a,b:integer;
    fin,fout:text;

function cmmdc(aa:integer; bb:integer):integer;
begin
  if not(bb) then cmmdc:=aa else cmmdc:=cmmdc(bb, aa mod bb);
end;

begin
assign(fin, 'euclid2.in'); reset(fin);
readln(fin, a, b);
close(fin);
assign(fout, 'euclid2.out'); rewrite(fout);
write(fout, cmmdc(a,b));
close(fout);
end.