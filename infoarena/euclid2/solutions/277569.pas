program cmmdc_euclid;
var t,de,im,ca,re,i,x,y:longint;
    f,g:text;

begin
assign(f,'euclid2.in');
assign(g,'euclid2.out');
reset(f);
rewrite(g);
readln(f,t);
for i:=1 to t do begin
  readln(f,x,y);
  if x=y then writeln(g,x)
  else begin
    if x>y then begin
      de:=x;
      im:=y;
      end
    else begin
      de:=y;
      im:=x;
      end;
  re:=de mod im;
  while re<>0 do begin
    de:=im;
    im:=re;
    re:=de mod im;
    end;
  writeln(g,im);
  end;
  end;
close(g);
end.