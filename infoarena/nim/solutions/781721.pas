program joucl_nim;
var f,g:text;
    t,j:byte;
    n,i:integer;
    s:longint;
    nr:longint;
    bufin,bufout:array[1..65000] of byte;


begin
 assign (f,'nim.in'); reset (f);
 assign (g,'nim.out'); rewrite (g);
 settextbuf (f,bufin); settextbuf (g,bufout);
 readln (f,t);
 for j:=1 to t do
 begin
  readln (f,n);
  s:=0;
  for i:=1 to n do
  begin
   read (f,nr);
   s:=s xor nr;
  end;
  readln (f);
  if s<>0 then
   writeln (G,'DA')
  else
   writelN (g,'NU');
 end;
 close (f); close (G);
end.
