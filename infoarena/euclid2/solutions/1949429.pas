{Program Euclid;
var A,B,C,i,t: Longint;
f,g: text;
begin
assign(f,'euclid2.in');
assign(g,'euclid2.out');
reset(f);
rewrite(g);
read(f,T);
if A < B then begin
 C:= A;
 A:= B;
 B:= C;
 end;
for i:=1 to t do begin 
 read(f,A,B);
 while B <> 0 do begin
  C:= A mod B;
  A:= B;
  B:= C;
  end;
 writeln(g,A);
end;
 close(f);
 close(g);
end.}
var a,b,c,i,t : longint;
    f,g : text;
begin
  assign(f,'euclid2.in');reset(f);
  assign(g,'euclid2.out');rewrite(g);
  read(f,t);
  for i:=1 to t do
  begin
  read(f,a,b);
    while b<>0 do
    begin
      c:=a mod b;
      a:=b;
      b:=c;
    end;
  writeln(g,a);
  end;
  close(g);
end.