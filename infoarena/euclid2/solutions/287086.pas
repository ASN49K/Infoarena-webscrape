var a,b,i,j,k,t:longint;
    v1,v2:array[1..1000]of integer;
begin
 assign(input,'euclid2.in');reset(input);
 assign(output,'euclid2.out');rewrite(output);
 readln(t);
 for i:= 1 to t do
 readln(a,b);
 for j:=1 to a do
 if a mod j=0 then v1[j]:=j;
  for k:=1 to b do
 if b mod k=0 then v2[k]:=k;
 if v1[j]=v2[k] then write(j);
 close(input);close(output);
end.