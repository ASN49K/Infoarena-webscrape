program euclid;
var f,g:text;
    a,b,d,t,i:integer;
function divizor(a,b:integer):integer;
  begin
   if b=0 then
     divizor:=a
   else
     divizor:=divizor(b,a mod b);
  end;
begin
  assign(f,'euclid.in'); reset(f);
  assign(g,'euclid.out'); rewrite(g);
  readln(f,t);
    for i:=1 to t do
      begin
        readln(f,a,b);
        writeln(g,divizor(a,b));
      end;
  close(f);
  close(g);
end.