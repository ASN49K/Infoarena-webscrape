program p;
var fi,fo:text;
    a,b:integer;
function  pr(a,b:integer):integer;
var max,min:integer;
begin
   if a>b then begin
                 max:=a;
                 min:=b;
               end
          else begin
                 max:=b;
                 min:=a;
               end;
    if max mod min =0 then pr:=min
                      else pr:=pr(trunc(max/min),min);
end;
begin
assign(fi,'euclid2.in');
reset(fi);
assign(fo,'euclid2.out');
rewrite(fo);
while not seekeof(fi) do begin
   read(fi,a);
   read(fi,b);
   writeln(fo,pr(a,b));
close(fo);
                         end;
end.



