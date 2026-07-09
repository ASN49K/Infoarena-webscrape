program euclid_algoritmus;
var
n,a,b,i,c:longword;
f,g:text;

begin
Assign(f,'euclid2.in'); reset(f);
Assign(g,'euclid2.out'); rewrite(g);
readln(f,n);

For i:=1 to n do begin
 readln(f,a,b);
 if b>a then begin c:=a; a:=b; b:=c; end;
 repeat
  c:=a mod b;
  a:=b; b:=c;
 until b=0;
 Writeln(g,a);
end;
close(f);close(g);
end.