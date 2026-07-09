Program Euclid;
var i,n,a,b:integer; f,g:text;
function cmmdc(a,b:integer):integer;
begin
  if b=0 then cmmdc:=a
        else cmmdc:=cmmdc(b,a mod b);
end;

procedure citire;
begin
  assign(f,'euclid.in');
  reset(f);
  readln(f,n);
  for i:=1 to n do begin
    readln(f,a,b);
    writeln(g,cmmdc(a,b));
  end;
end;



begin
assign(g,'euclid.out');
rewrite(g);
citire;
close(f); close(g);
end.