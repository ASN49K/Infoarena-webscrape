Program divizor;
 var a, b,i,j,t:longint;
     fi, fo:text;
begin
 assign(fi,'euclid2.in');
  reset(fi);
   readln(fi,t);
 assign(fo,'euclid2.out');
  rewrite(fo);
  for j:=1 to t do begin
   readln(fi,a,b);
 if a>=b then begin
  if a mod b=0 then
                  writeln(fo,b)
 else
   for i:=b div 2 downto 1 do
    if (a mod i=0) and (b mod i=0) then begin
                                          writeln(fo,i);
                                          break;
                                         end;
    end;
  if b>=a then begin
  if b mod a=0 then
                     writeln(fo,a)
 else
   for i:=a div 2 downto 1 do
    if (a mod i=0) and (b mod i=0) then begin
                                          writeln(fo,i);
                                          break;
                                         end;
    end;
   end;
 close(fo);
 end.
