program cmmdc_euclid;
var
a,b,i,n:integer;
f,g:text;
function cmmdc(x,y:integer):integer;
begin
        if y=0 then cmmdc:=x
               else cmmdc:=cmmdc(y,x mod y);
               end;

begin
assign(f,'euclid2.in');reset(f);
assign(g,'euclid2.out');rewrite(g);
read(f,n);
for i:=1 to n do
        begin
        readln(f,a,b);
        writeln(g,cmmdc(a,b));
        end;
        close(f);close(g);
        end.