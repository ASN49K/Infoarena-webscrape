var f:text; i,t:longint;  k:array[1..100000] of longint; a,b,c:qword;
   procedure calculare(x,y:qword; var z:qword);
      var min:qword;
       begin
       i:=0;
       if x>y then min:=y else min:=x;
       while i<>x do
          begin
          if (x mod i=0) and (y mod i=0) then z:=i;
          i:=i+1;
          end;
       x:=0;y:=0;
       end;
  procedure citire;
    begin
    assign(f,'euclid2.in');
    reset(f);
    readln(f,t);
    for i:=1 to t do
      begin
      readln(f,a,b);
      calculare(a,b,c);
      k[i]:=c;
      a:=0; b:=0; c:=0;
      end;
    close(f);
    end;

    procedure afisare;
      begin
      assign(f,'euclid2.out');
      rewrite(f);
      for i:=1 to t do
      writeln(f,k[i]);
      close(f);
      end;
begin
    citire;
    afisare;
end.
