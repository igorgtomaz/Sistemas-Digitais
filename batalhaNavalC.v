`include "codificaJogadaC.v"
module batalhaNaval (
  input [2:0]Jogada1,
  input [2:0]Jogada2,
  output R
  );

  wire [2:0]J1;
  wire R;

  codificaJogada cJ (Jogada1, J1);

  assign R = (~J1 & ~Jogada2) | (J1 & Jogada2);

  initial begin
    #10;
    if (R == 1)
      begin
        #10 $display("Jogador 2 venceu.");
      end
    else
      begin
        #10 $display("Jogador 1 venceu.");
      end
  end

endmodule

module teste ();

reg [2:0]TJ1;
reg [2:0]TJ2;
wire R;

initial begin
  $dumpvars;
  #2 TJ1 <= 3'b000;
  #2 TJ2 <= 3'b001;
end

batalhaNaval bN (TJ1, TJ2, R);

endmodule //
