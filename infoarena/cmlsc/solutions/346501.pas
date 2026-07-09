Program euclid3;
 var f,g:text; ct:array[1..45]of longint;
     a,b,c,d,j:longint; x,y,z:int64; i,t,n:byte;
 procedure cmmdc (u,v:longint; var w:longint);
  var uu,vv,ww:longint;
  begin
   uu:=u; vv:=v;
   n:=0;
   while (vv<>0) do begin
     inc (n); ct[n]:=uu div vv;
     ww:=uu; uu:=vv; vv:=ww mod vv;
   end;
   w:=uu; dec (n);
  end;
 begin
  assign (f,'euclid3.in'); reset (f);
  assign (g,'euclid3.out'); rewrite (g);
  readln (f,t);
  for i:=1 to t do begin
    readln (f,a,b,c);
    cmmdc (a,b,d);
    if (c mod d)<>0 then writeln (g,'0 0') else begin
      x:=0; y:=1;
      for j:=n downto 1 do begin
        writeln (x,' ',y);
        z:=x;
        x:=y;
        y:=z-y*ct[j];
      end;
      x:=x*(c div d);
      y:=y*(c div d);
      writeln (g,x,' ',y);
    end;
  end;
  close (f); close (g);
 end.