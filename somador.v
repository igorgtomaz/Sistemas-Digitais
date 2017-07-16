module meioSomador(
  input x,
  input y,
  output S,
  output C
);

assign S = x ^ y;
assign C = x * y;

endmodule

module somadorCompleto (
    input Cin,
    input x,
    input y,
    output Cout,
    output S
  );

  wire C1 = 0;
  wire C2 = 0;
  wire S1 = 0;

  meioSomador M1(x, y, S1, C1);
  meioSomador M2(Cin, S1, S, C2);

  assign Cout = C2 | C1;

endmodule

module somador (
    input [3:0] A,
    input [3:0] B,
    output [4:0] S
  );

  reg GND = 0;
  wire [3:0] out = 0;

  somadorCompleto S1(GND, A[0], B[0], out[0], S[0]);
  somadorCompleto S2(S[0], A[1], B[1], out[1], S[1]);
  somadorCompleto S3(S[1], A[2], B[2], out[2], S[2]);
  somadorCompleto S4(S[2], A[3], B[3], out[3], S[3]);

  assign S[4] = out[3];
endmodule
