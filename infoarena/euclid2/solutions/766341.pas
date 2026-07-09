program cmmdc;
var f,g:text;
    t,i,a,b,max,min,rest:longint;
    bufin,bufout:array [1..65000] of byte;

begin
 assign (f,'euclid2.in'); reset (f);
 assign (g,'euclid2.out'); rewrite (g);
 settextbuf (f,bufin); settextbuf (g,bufout);
 readln (f,t);
 for i:=1 to t do
 begin
  readln (f,a,b);
  if a>b then
  begin
   max:=a; min:=b;
  end
  else
  begin
  max:=b; min:=a;
  end;
  rest:=max mod min;
  while rest<>0 do
  begin
   max:=min; min:=rest;
   rest:=max mod min;
  end;
  writeln (g,min);
 end;
 close (f);
 close (g);
end.
