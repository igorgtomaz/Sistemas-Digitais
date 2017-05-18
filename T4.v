/*
  O programa lê o arquivo de entrada que é o mesmo do T3
  e escreve o resultado na saidaT4.txt conforme pode ser verificado
*/

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

  wire signed [20:0] a;
  wire signed [20:0] b;
  wire signed [20:0] c;

  assign a = ((x - xa) * (yb - ya)) - ((y - ya)*(xb - xa));
  assign b = ((x - xb) * (yc - yb)) - ((y - yb)*(xc - xb));
  assign c = ((x - xc) * (ya - yc)) - ((y - yc)*(xa - xc));

  always @ (a, b, c) begin
    if ((a > 0 && b > 0 && c > 0) || (a < 0 && b < 0 && c < 0))
      begin
        S <= 1;
      end
    else
      begin
        S <= 0;
      end
  end
endmodule

module teste;

  integer entrada;
  integer saida;
  integer resp;
  reg signed [9:0] xa;
  reg signed [9:0] ya;
  reg signed [9:0] xb;
  reg signed [9:0] yb;
  reg signed [9:0] xc;
  reg signed [9:0] yc;
  reg signed [9:0] x;
  reg signed [9:0] y;
  wire S;

  initial begin
    $dumpvars;

    entrada = $fopen("entradaT3.txt", "r");
    saida = $fopen("saidaT4.txt", "w");

    if (entrada == 0)
    begin
      $display("O arquivo não pode ser aberto.");
      $finish;
    end
  end

  always #2 begin
    if(!$feof(entrada)) begin
      resp = $fscanf(entrada, "%f %f %f %f %f %f %f %f\n", xa, ya, xb, yb, xc, yc, x, y);
      #1
      if (S == 1)
        $fwrite(saida, "A(%.1f, %.1f), B(%.1f, %.1f), C(%.1f, %.1f), P(%.1f, %.1f) - Pertence\n", xa, ya, xb, yb, xc, yc, x, y);
      else
        $fwrite(saida, "A(%.1f, %.1f), B(%.1f, %.1f), C(%.1f, %.1f), P(%.1f, %.1f) - Nao Pertence\n", xa, ya, xb, yb, xc, yc, x, y);
    end
    else begin
      $finish;
    end
  end

  pontoTriangulo p(xa, ya, xb, yb, xc, yc, x, y, S);
endmodule
