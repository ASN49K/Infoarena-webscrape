var a,b,r,aux:longint;
    f,g:text;
begin
 assign(f,'cmmdc.in');
 reset(f);
 read(f,a);
 readln(f,b);
 close(f);
 if b>a then begin
  aux:=a;
  a:=b;
  b:=aux;
  end;
 repeat
  r:=a mod b;
  a:=b;
  b:=r;
 until r=0;
 assign(g,'cmmdc.out');
 rewrite(g);
 writeln(g,a);
 close(g);
end.

