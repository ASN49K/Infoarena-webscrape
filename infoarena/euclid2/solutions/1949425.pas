Program Euclid;
var A,B,C,i,t: Longint;
f,g: text;
begin
assign(f,'euclid2.in');
assign(g,'euclid2.out');
reset(f);
rewrite(g);
read(f,T);
{if A < B then begin
 C:= A;
 A:= B;
 B:= C;
 end;}
for i:=1 to t do begin 
 while B <> 0 do begin
  C:= A mod B;
  A:= B;
  B:= C;
  end;
 writeln(g,A);
end;
 close(g);
end.