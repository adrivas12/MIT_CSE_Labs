`timescale 1ns/1ns
`include "q5.v"

module q5_tb();
reg [5:0]w;
reg clk;
wire [5:0]Q;
q5 q5(w, clk, Q);
initial 
begin

	$dumpfile("q5_tb.vcd");
	$dumpvars(0, q5_tb);

	w=6'b100011; clk=0; #20;
	w=6'b100011; clk=1; #20;
	w=6'b100011; clk=0; #20;
	w=6'b100011; clk=1; #20;

	$display("Test complete");
end
endmodule