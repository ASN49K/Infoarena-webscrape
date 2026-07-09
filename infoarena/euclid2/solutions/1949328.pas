Program Euclid;
var T,i:1..100000;
A,B,C: 2..2000000000{array [1..100000,1..2] of 2..2000000000;};
f,g: text;
procedure cmmdc;
begin
  C:= A mod B;
  A:= B;
  B:= C;
  if A mod B <> 0 then cmmdc;
end;
begin
assign(f,'euclid2.in');
assign(g,'euclid2.out');
reset(f);
rewrite(g);
readln(f,T);
{if A < B then begin
 C:= A;
 A:= B;
 B:= C;
 end;}
for i:=1 to t do begin 
  readln(f,A,B);
 cmmdc;
 writeln(g,B);
end;
close(f);
 close(g);
end.