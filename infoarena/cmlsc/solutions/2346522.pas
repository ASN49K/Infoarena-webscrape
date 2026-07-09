uses crt;
type vector=array[1..100] of longint;
var f,g:text;
    n1,n2,i,j, max:longint;
    v1,v2:vector;
    sem:boolean;
function poz(n,x:integer; v:vector):byte;
var i:integer;
begin
     poz:=0;
     for i:=1 to n do
         if v[i]=x then
            poz:=i;
end;
begin
     assign(f,'cmlsc.in');
     reset(f);
     assign(g,'cmlsc.out');
     rewrite(g);
     readln(f);
     while not eoln(f) do
           begin
                inc(n1);
                read(f,v1[n1]);
           end;
     readln(f);
     while not eoln(f)do
           begin
                inc(n2);
                read(f,v2[n2]);
           end;
     if n1<n2 then
        begin
             i:=n1;
             n1:=n2;
             n2:=i;
        end;
     max:=-maxint;
     i:=1;
     while (i<=n2) do
         begin
              j:=poz(n1,v2[i],v1);
              if j>max then
              begin
                  write(g,v2[i],' ');
                  max:=j;
              end;
              inc(i);
         end;
close(g);
readln;
end.