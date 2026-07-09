program euclid;
var f,g:text;i,j,nr,a,b,di:longint;
begin
 assign(f,'euclid2.in');
 assign(g,'euclid2.out');
 rewrite(g);
 reset(f);
 rewrite(g);
 readln(f,nr);
 for i:=1 to nr do
   begin
   read(f,a,b);
   if a>b
    then
     for j:=1 to b do
       if (b mod j=0) and (a mod j=0) then di:=j;
    if a<b then
     for j:=1 to a do
       if (a mod j=0) and (b mod j=0) then di:=j;
    writeln(g,di);
   end;
   close(f);
   close(g);
end.