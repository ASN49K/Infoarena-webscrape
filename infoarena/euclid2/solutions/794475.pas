program euclid_algoritm;
var
n,a,b,i,c,max,min:longword;
f,g:text;
bufin1,bufin2:array[1..650] of longword;

begin
Assign(f,'euclid2.in'); reset(f);
Assign(g,'euclid2.out'); rewrite(g);
settextbuf(f,bufin1);
settextbuf(g,bufin2);
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
