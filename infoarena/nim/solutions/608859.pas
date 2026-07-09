Program jucul_nim;
 var n,t,a,s,i,j:longint;
     b1,b2:array [1..1 shl 10] of char;
     fi,fo:text;
begin
 assign(fi,'nim.in');
  assign(fo,'nim.out');
 settextbuf(fi,b1);
 settextbuf(fo,b2);
 reset(fi);
 rewrite(fo);
 readln(fi,t);
 for i:=1 to t do begin
  s:=0; readln(fi,n);
   for j:=1 to n do begin
                     read(fi,a);
                     s:=s xor a;
                     end;
   if s>0 then writeln(fo,'DA')
    else writeln(fo,'NU');
                     end;
close(fo);
end.