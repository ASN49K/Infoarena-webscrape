program euclid2;
var f,g:text; i,n,a,b:longint;
function cmmdc(d,i:longint):longint;
var r:longint;
begin
   r:=d mod i;
  while r<>0 do begin
   d:=i; i:=r; r:=d mod i;
  end;
  cmmdc:=i;
end;
begin
   assign(f,'euclid2.in'); reset(f);
   assign(g,'euclid2.out'); rewrite(g);
   read(f,n);
  for i:=1 to n do begin
    readln(f,a,b);
    writeln(g,cmmdc(a,b));
  end;
  close(f); close(g);
end.