`timescale 1ns/1ns
`include "q4.v"

module q4_tb();
reg [3:0]W;
wire [1:0]Y;
wire Z;
q4 q4(W, Z, Y);
initial 
begin

	$dumpfile("q4_tb.vcd");
	$dumpvars(0, q4_tb);

	W=4'b0001; #10;
	W=4'b001x; #10;
	W=4'b01xx; #10;
	W=4'b1xxx; #10;

	$display("Test Completed");

end 
endmodule