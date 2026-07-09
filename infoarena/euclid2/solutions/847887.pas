var a,b:longint;T:integer; f,g:text;
Begin
assign(f,'euclid2.in');reset(f);
assign(g,'euclid2.out');rewrite(g);
readln(f,T);
Repeat
t:=t-1;
    readln(f,a,b);
    repeat
       If a>b then
          a:=a-b
       else
          b:=b-a;
    until a=b;
    writeln(g,a);
until T=0;
close(f);
close(g);
end.