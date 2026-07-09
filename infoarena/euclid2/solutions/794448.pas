program euclid_algoritm;
var
n,a,b,i,c,max,min:longword;
f,g:text;

begin
Assign(f,'euclid2.in'); reset(f);
Assign(g,'euclid2.out'); rewrite(g);
readln(f,n);

For i:=1 to n do begin
 readln(f,a,b);
 if b>a then begin max:=b; min:=a; end else begin max:=a; min:=b; end;
 repeat
  c:=max mod min;
  max:=min; min:=c;
 until min=0;
 Writeln(g,max);
end;
close(f);close(g);
end.