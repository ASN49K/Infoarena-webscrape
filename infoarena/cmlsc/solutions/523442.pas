program arhiva001;
const nmax=1024;
type tip1=0..nmax;
var a,b,c:array[tip1] of byte;
    v:array[tip1,tip1] of tip1;
    max,m,n,i,j:tip1;

procedure matr(k,i,j:tip1);
var s,t:tip1;
begin
 for s:=i to m do
  for t:=j to n do
   if (v[s,t]<>0) and (v[s,t]<=k) then
          begin v[s,t]:=k+1;
                if max<k+1 then max:=k+1;
                matr(k+1,s+1,t+1);
          end;
end;

procedure sir(k,i,j:tip1);
var s,t:tip1;
begin
 if k=0 then begin for i:=1 to max do write(c[i],' ');
                   writeln();
             end
        else
   begin for s:=i downto k do
          for t:=j downto k do
            if v[s,t]=k then begin c[k]:=a[s];
                                   sir(k-1,s-1,t-1);
                             end;
   end;
end;


begin
 assign(input,'cmlsc.in');
 reset(input);
 read(m); readln(n);
 for i:=1 to m do read(a[i]); readln;
 for j:=1 to n do read(b[j]);
 close(input);
 {1}
 for i:=1 to m do
  for j:=1 to n do
   if a[i]=b[j] then v[i,j]:=1
                else v[i,j]:=0;
 {2}
 max:=1;
 for i:=1 to m do
  for j:=1 to n do
        if v[i,j]=1 then matr(1,i+1,j+1);
 for i:=1 to m do
  begin for j:=1 to n do
          write(v[i,j],' ');
        writeln;
  end;

 assign(output,'cmlsc.out');
 rewrite(output);
 writeln(max);
 {3}
 for i:=m downto 1 do
  for j:=n downto 1 do
   if v[i,j]=max then
       begin c[max]:=a[i];
             sir(max-1,i-1,j-1);
       end;
 close(output);
end.
