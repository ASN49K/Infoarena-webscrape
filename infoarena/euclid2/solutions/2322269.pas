program p1;
uses crt;
var f,g:text;
    i,n,a,b,temp:integer;
begin clrscr;
assign(f,'euclid2in.txt');
assign(g,'euclid2out.txt');
reset(f);
rewrite(g);
readln(f,n);
for i:=1 to n do
begin
 readln(f, a, b);
 if a<b then begin temp:=a; a:=b; b:=temp; end;
 while b<>0 do
  begin
   temp:=b;
   b:= a mod b;
   a:=temp;
  end;
  writeln(g,a);
end;
close(f);
close(g);
readln;
end.