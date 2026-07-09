var i,t,r,a,b:integer;
begin
 assign(input,'euclid2.in');reset(input);
 assign(output,'euclid2.out');rewrite(output);
 readln(t);
 for i:=1 to t do begin
 read(a,b);r:=a mod b;
 while r<>0 do begin
 a:=b;b:=r;r:=a mod b;
 end;
 if b=1 then write('1 ')
        else write(b,' ');
 end;
 close(input);close(output);
end.