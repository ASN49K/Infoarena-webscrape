var a,b:word;
    f,g:text;
function cmmdc(a,b:word):word;
 begin
 if a mod b=0 then cmmdc:=b
  else cmmdc:=cmmdc(b,a mod b);
 end;
begin
 assign(f,'cmmdc.in');
 reset(f);
 readln(f,a);
 readln(f,b);
 assign(g,'cmmdc.out');
 rewrite(g);
 writeln(g,cmmdc(a,b));
 close(f);
 close(g);
end.

