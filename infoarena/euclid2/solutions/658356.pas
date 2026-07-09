program info;
var a,b,r:int64;  
    i,n:longint; 
    f,g:text;
begin   
   assign(f,'euclid2.in'); reset(f);   
   assign(g,'euclid2.out'); rewrite(g);  
      readln(f,n);
for i:=1 to n do
        begin
            readln(f,a,b);
            repeat 
            r:=a mod b;  
            a:=b; 
            b:=r;  
        until b=0;   
        writeln(g,a);
      end; 
   close(f);  
   close(g);
end.
