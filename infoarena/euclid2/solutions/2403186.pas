program loc;
var i,a,b,t,c,s:longint;
g,f:text;

procedure cm(a,b:longint; var c:longint);
begin
if a>=b then c:=b else c:=a;
end;

procedure divi(a,b:longint; var c,s:longint);
var bo:boolean;
begin
while c>=1 do begin
if (a mod c=0) and (b mod c=0) and (bo=false) then begin s:=c; bo:=true; end;
c:=c-1;
end;
end;




begin
assign(g,'euclid2.in');
assign(f,'euclid2.out');
reset(g);
readln(g,t);
rewrite(f);
for i:=1 to t do begin
  s:=0;
  readln(g,a,b);
  cm(a,b,c);
  divi(a,b,c,s);
  writeln(f,s);
end;
close(f);
close(g);
end.