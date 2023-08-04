`timescale 1ns/1ns
`include "q1.v"

module q1_tb();
reg [2:0]W;
reg En;
wire [0:7]Y;
q1 q1(W, En, Y);
initial 
begin

	$dumpfile("q1_tb.vcd");
	$dumpvars(0, q1_tb);

	W=3'b000; En=1'b1;
	#10;
	W=3'b001; En=1'b1;
	#10;
	W=3'b010; En=1'b1;
	#10;
	W=3'b011; En=1'b1;
	#10;
	W=3'b100; En=1'b1;
	#10;
	W=3'b101; En=1'b1;
	#10;
	W=3'b110; En=1'b1;
	#10;
	W=3'b111; En=1'b1;
	#10;

	$display("Test Completed");

end 
endmodule