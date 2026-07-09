program info;
const fi='razboi.in';
      fo='razboi.out';
type li=record
   nod,val:longint;
    end;
var f,g:text;
    v:array of array of  li;
    bufin,bufout:array[1..1000] of char;
    n,m,a,b,c1,i,st,sf,nd,max,x,j,min,poz:longint;
    c,viz,s,v1,vmax:array[1..501] of longint;
    cd:array[1..30000] of longint;
begin

   assign(f,fi);
   reset(f);
   assign(g,fo);
   rewrite(g);
   settextbuf(f,bufin);
   settextbuf(f,bufout);
   read(f,n,m);
   setlength(v,n+1,1);

   for i:=1 to m do
     begin
      read(f,a,b,c1);
      inc(c[a]);
      setlength(v[a],c[a]+1);
      v[a,c[a]].nod:=b;
      v[a,c[a]].val:=c1;
     end;
     readln(f);  readln(f,x);

   max:=-maxlongint;  min:=maxlongint;
   for i:=1 to n do
      vmax[i]:=-maxlongint;

  for j:=1 to n do
   begin
    st:=0;
    sf:=1;
    for i:=1 to n do
      begin
        s[i]:=maxlongint;
        cd[i]:=0;
        viz[i]:=0;
      end;
    s[j]:=0;
    cd[1]:=j;
    viz[j]:=1;
    v1[1]:=1;
    while st<sf do
      begin
         inc(st);
         nd:=cd[st];
         viz[nd]:=0;
         for i:=1 to c[nd] do
           begin
            if s[nd]+v[nd,i].val<s[v[nd,i].nod] then
               begin
                 s[v[nd,i].nod]:=s[nd]+v[nd,i].val;
                 if viz[v[nd,i].nod]=0 then
                   begin
                     inc(sf);
                     cd[sf]:=v[nd,i].nod;
                     viz[v[nd,i].nod]:=1;
                   end;
                end;
           end;

       end;

       if s[x]>max then
          max:=s[x];

       for i:=1 to n do
          begin
              if s[i]>vmax[i] then
                 vmax[i]:=s[i];
          end;


  end;

  for i:=1 to n do
     if vmax[i]<min then
       begin
        min:=vmax[i];
        poz:=i;
       end;

   if max=maxlongint then
      writeln(g,0)
    else
       writeln(g,max);

       if min=maxlongint then
           writeln(g,0)
         else
           writeln(g,poz,' ',min);
   close(f);
   close(g);
end.