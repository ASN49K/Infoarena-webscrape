program pascal;
var f,g:text;
    i,j,k,l,p,max,maxim,n,m:longint;
    v,a,b,sol:array[1..1024] of longint;

 procedure test1;
 begin
   for i:=1 to n do
     begin
      for j:=1 to m do
       if b[i]=a[j] then
               begin
                k:=k+1;
                sol[k]:=j;
               end;
    end;

      v[k]:=1;
    for l:=k-1 downto 1 do
     begin
      max:=0;
      for j:=l+1 to k do
       if (sol[l]<=sol[j]) and (v[j]>max) then max:=v[j];
      v[l]:=max+1;
     end;

   max:=0;
   for i:=1 to k do
    if v[i]>max then
     begin
        max:=v[i];
        p:=i;
     end;
   writeln(g,max);
   write(g,a[sol[p]],' ');
   i:=p;
   maxim:=sol[p];
   while max<>1 do
    begin
      i:=i+1;
      if (sol[i]>maxim) and (v[i]=max-1) then
           begin
              maxim:=sol[i];
              max:=max-1;
              write(g,a[sol[i]],' ');
           end;
    end;
 end;

 procedure test2;
  begin
   for i:=1 to m do
     begin
      for j:=1 to n do
       if a[i]=b[j] then
               begin
                k:=k+1;
                sol[k]:=j;
               end;
    end;
      v[k]:=1;
    for l:=k-1 downto 1 do
     begin
      max:=0;
      for j:=l+1 to k do
       if (sol[l]<=sol[j]) and (v[j]>max) then max:=v[j];
      v[l]:=max+1;
     end;

   max:=0;
   for i:=1 to k do
    if v[i]>max then
     begin
        max:=v[i];
        p:=i;
     end;

   writeln(g,max);
   write(g,b[sol[p]],' ');
   i:=p;
   maxim:=sol[p];
   while max<>1 do
    begin
      i:=i+1;
      if (sol[i]>maxim) and (v[i]=max-1) then
           begin
              maxim:=sol[i];
              max:=max-1;
              write(g,b[sol[i]],' ');
           end;
    end;
 end;

begin
 assign(f,'cmlsc.in'); reset(f);
 assign(g,'cmlsc.out'); rewrite(g);
 readln(f,m,n);
 for i:=1 to m do
    read(f,a[i]);
 readln(f);
 for i:=1 to n do
    read(f,b[i]);
   k:=0;
  if n<m then test1
         else test2;

 close(f);
 close(g);
end.












