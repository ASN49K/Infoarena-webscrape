program euclid2;
var a,b,i,t,aux:longint;
    f,g:text;

  function cmmdc(a,b:longint):longint;
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
      {if a<b then
        begin
          aux:=a;
          a:=b;
          b:=aux;
        end;}
      writeln(g,cmmdc(a,b));
    end;

  close(f);
  close(g);

END.
