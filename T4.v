module pontoTriangulo (
  input [9:0] xa,
  input [9:0] ya,
  input [9:0] xb,
  input [9:0] yb,
  input [9:0] xc,
  input [9:0] yc,
  input [9:0] x,
  input [9:0] y,
  output reg S
  );

  integer out;
  wire [20:0] a;
  wire [20:0] b;
  wire [20:0] c;

  initial begin
    out = $fopen("saidaT4.txt", "w");
  end

  assign a = ((x-xa)*(yb-ya))-((y-ya)*(xb-xa));
  assign b = ((x-xb)*(yc-yb))-((y-yb)*(xc-xb));
  assign c = ((x-xc)*(ya-yc))-((y-yc)*(xa-xc));

  always @ ( * ) begin
    if ((a > 0 && b > 0 && c > 0) || (a < 0 && b < 0 && c < 0))
      begin
        S <= 1;
        $fwrite(out, "O ponto (%.1f, %.1f) pertence ao triangulo de coordenadas A(%.1f, %.1f), B(%.1f, %.1f) e C(%.1f, %.1f).\n", x, y, xa, ya, xb, yb, xc, yc);
      end
    else
      begin
        S <= 0;
        $fwrite(out, "O ponto (%.1f, %.1f) não pertence ao triangulo de coordenadas A(%.1f, %.1f), B(%.1f, %.1f) e C(%.1f, %.1f).\n", x, y, xa, ya, xb, yb, xc, yc);
      end
  end
endmodule

module teste;

  integer entrada;
  integer scan_file;
  reg [9:0] xa;
  reg [9:0] ya;
  reg [9:0] xb;
  reg [9:0] yb;
  reg [9:0] xc;
  reg [9:0] yc;
  reg [9:0] x;
  reg [9:0] y;
  reg clk;
  wire S;

  initial begin
      entrada = $fopen("entrada.txt", "r");
  end

  pontoTriangulo p(xa, ya, xb, yb, xc, yc, x, y, S);

  initial begin
    $dumpvars;
      scan_file = $fscanf(entrada, "%f %f %f %f %f %f %f %f\n", xa, ya, xb, yb, xc, yc, x, y);
      #5 scan_file = $fscanf(entrada, "%f %f %f %f %f %f %f %f\n", xa, ya, xb, yb, xc, yc, x, y);
    $finish;
  end

endmodule
