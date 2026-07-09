program cmmdcol;
type vec=array [1..10000] of longint;
var a,b,cm,i,n,nq,h:longint;
    c:vec;
    f,t:text;
begin
   assign(f,'euclid2.in');
   reset(f);
   assign(t,'euclid2.out');
   rewrite(t);
   read(f,nq);
   for h:=1 to nq do
 begin
   read(f,a,b);
   if a>b then
     for i:=2 to a div 2 do
       begin
         if (a mod i=0) and (b mod i=0)
           then
             begin
               n:=n+1;
               c[n]:=i;
             end;
       end;
  if a<b then
    for i:=2 to b div 2 do
      begin
        if (a mod i=0) and (b mod i=0)
          then
            begin
              n:=n+1;
              c[n]:=i;
            end;
      end;
  cm:=0;
  for i:=1 to c[n] do
     if cm<c[n]
       then cm:=c[n];
   writeln(t,cm);
 end;
  close(f);
  close(t);
end.