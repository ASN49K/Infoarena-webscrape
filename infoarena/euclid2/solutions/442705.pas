program cmmdc_recursiv;
var d,i,n,j:longint;f,g:text;
function cmmdc(d,i:integer):integer;
var r:integer;
begin
     r:=d mod i;
     if r<>0 then begin
       d:=i;
       i:=r;
       cmmdc:=cmmdc(d,i)
        end
         else cmmdc:=i;
         end;
begin
   assign(f,'euclid2.in');reset(f);
   assign(g,'euclid2.out');rewrite(g);
    readln(f,n);
     for j:=1 to n do begin
    read(f,d);readln(f,i);
   writeln(g,cmmdc(d,i));end;
   close(f);close(g);

     end.