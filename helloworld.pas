program test;
var
  x : Integer;
  y : Integer;



function G(x : Integer) : Integer;
begin
  G := x * 2;
end;

function F(x : Integer) : Real;
begin
  F := G(x);
end;

procedure P(var y : Integer);
begin
  y := y * 2;
end;


begin
  x := -1;
  x := F(x);
  y := -5;
  P(y);
end
.
