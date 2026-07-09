var t,a,b: integer;
    f,g: text;

   function euclid(x,y: integer):integer;
   var r,aux: integer;
   begin
    if x<y then
     begin
       aux:=x;
       x:=y;
       y:=aux;
     end;
   repeat
     r:=x mod y;
     x:=y;
     y:=r;
  until r=0;
  euclid:=x;
  end;

begin
 assign(f,'euclid2.in');
 assign(g,'euclid2.out');
 reset(f);
 rewrite(g);
 read(f,t);
 for i:=1 to t do
  begin
   read(f,a,b);
   writeln(g,euclid(a,b));
   readln(f);
  end;
  close(f);
  close(g);
 end;