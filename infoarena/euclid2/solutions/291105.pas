program cmmdcol;
type vec=array [1..5000] of longint;
var a,b,j,cm,i,na,nb,n,nq,h,nc:longint;
    av,bv,c:vec;
    f,t:text;
begin
   assign(f,'euclid2.in');
   reset(f);
   assign(t,'euclid2.out');
   rewrite(t);
   read(f,nq);
   for h:=1 to nq do
 begin
   for i:=1 to na do
     av[i]:=0;
   for i:=1 to nb do
     bv[i]:=0;
   for i:=1 to n do
     c[n]:=0;
   na:=0;nb:=0;n:=0;
   read(f,a,b);
   if a>b
     then
       for i:=1 to a div 2 do
          begin
            if a mod i =0
              then
                begin
                  na:=na+1;
                  av[na]:=i;
                end;
            if b mod i =0
              then
                begin
                  nb:=nb+1;
                  bv[nb]:=i;
                end;
          end;
   if a<b
     then
       for i:=1 to b div 2 do
          begin
            if a mod i =0
              then
                begin
                  na:=na+1;
                  av[na]:=i;
                end;
            if b mod i =0
              then
                begin
                  nb:=nb+1;
                  bv[nb]:=i;
                end;
          end;
  n:=1;c[1]:=1;
  for i:=1 to nb do
    for j:=1 to na do
      if bv[i]=av[j]
        then
          begin
            n:=n+1;
            c[n]:=bv[i];
          end;
  cm:=0;
  for i:=1 to n do
     if cm<c[n]
       then cm:=c[i];
   writeln(t,cm);
 end;
  close(f);
  close(t);
end.