var a,b,t,i:integer;
f,g:text;
function divizor(ax,bx:integer):integer;
begin
  if bx = 0 then
    divizor := ax
  else
    divizor := divizor(bx,ax mod bx);
end;
begin
assign(f,'euclid2.in');
assign(g,'euclid2.out');
reset(f);
rewrite(g);
readln(f,t);
for i:=1 to t do begin
  read(f,a);
  readln(f,b);
  writeln(g,divizor(a,b));
end;
close(f);
close(g);
end.