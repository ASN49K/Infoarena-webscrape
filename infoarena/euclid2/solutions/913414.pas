program p1;
var fi,fo:text;
    a,b:int64;
    w,i:longint;

function euclid(m:int64; n:int64):int64;
var max,min:int64;
begin
  if m>n then begin
               max:=m;
               min:=n;
              end
         else begin
               max:=n;
               min:=m;
              end;
   if max mod min=0 then euclid:=min
                    else euclid:=euclid(min, max div min);

end;

begin
assign(fi,'euclid2.in');
reset(fi);
assign(fo,'euclid2.out');
rewrite(fo);
readln(fi,w);
for i:=1 to w do
                         begin
             readln(fi,a,b);
             writeln(fo,euclid(a,b));
                         end;
close(fo);
end.
