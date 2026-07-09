var buf1: array[1..1 shl 10] of char;
    fi: text;
    r, i, n, k, a, b:longint;
begin
assign(fi,'euclid2.in');
assign(output,'euclid2.out');
reset(fi);
rewrite(output);
settextbuf(fi,buf1);
 readln(fi, n);
 for k:=1 to n do
 begin
  readln(fi,a,b);
   begin
     repeat
       r:=a mod b;
       a:=b;
       b:=r;
     until r=0;
    writeln(a);
   end;
  end;
close(fi);
close(output);
end.