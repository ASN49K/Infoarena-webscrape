program Euclid;
var f,g:text;
    i,t:longint;
    a,b,max,min,aux,x:int64;
begin
assign(f,'euclid2.in');
assign(g,'euclid2.out');
reset(f);
rewrite(g);
readln(f,t);
for i:=1 to t do begin
 readln(f,a,b);
 if a>b then begin max:=a;
                   min:=b;
                   end
        else begin max:=b;
                    min:=a;
             end;
 x:=max;
 aux:=max mod min;
 while aux<>0 do begin
  aux:=max mod min;
  max:=min;
  min:=aux;
  end;
 if x<>max then writeln(g,max)
           else writeln(g,min);
end;
close(f);
close(g);
end.