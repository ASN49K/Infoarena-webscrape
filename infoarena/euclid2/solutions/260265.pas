var t,a,b,i: integer;
    f,g: text;

   function euclid(x,y: integer):integer;
   var r,aux: integer;
   begin
    repeat
     if x>y then   x:=x-y
            else  y:=y-x;
    until x=y
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
 end.