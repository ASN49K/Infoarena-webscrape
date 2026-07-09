program euclid;
var n,a,b,i:longint;
    f,g:text;
  function cmmdc(a,b:longint):longint;
  var rest:longint;
  begin
    rest:=a mod b;
    while rest<>0 do
      begin
        a:=b;
        b:=rest;
        rest:=a mod b;
      end;
    cmmdc:=b;
  end;
begin
  assign(f,'euclid2.in'); reset(f);
  assign(g,'euclid2.out'); rewrite(g);
  readln(f,n);
  for i:=1 to n do
    begin
      readln(f,a,b);
      writeln(g,cmmdc(a,b));
    end;
  close(f);
  close(g);
end.
