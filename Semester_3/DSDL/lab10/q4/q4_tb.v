`timescale 1ns/1ns
`include "q4.v"

module q4_tb();
reg [4:0]w;
reg clk;
wire [4:0]Q;
q4 q4(w, clk, Q);
initial 
begin

	$dumpfile("q4_tb.vcd");
	$dumpvars(0, q4_tb);

	w=5'b10001; clk=0; #20;
	w=5'b10001; clk=1; #20;
	w=5'b10001; clk=0; #20;
	w=5'b10001; clk=1; #20;

	$display("Test complete");
end
endmodule