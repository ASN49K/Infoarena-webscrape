program euclid2;
var a,b:qword;
    f,g:text;
    i,t:longint;

  function cmmdc(a,b:qword):longint;
  begin
    if b=0 then cmmdc:=a
        else cmmdc:=cmmdc(b,a mod b);
  end;

BEGIN

  assign(f,'euclid2.in');reset(f);
  assign(g,'euclid2.out');rewrite(g);
  readln(f,t);
  for i:=1 to t do
    begin
      readln(f,a,b);
      writeln(g,cmmdc(a,b));
    end;

  close(f);
  close(g);

END.