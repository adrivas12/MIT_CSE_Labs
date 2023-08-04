`timescale 1ns/1ns
`include "q1.v"

module q1_tb();
reg [3:0]W;
reg En;
wire f;
q1 q1 (W, En, f);
initial
begin
	$dumpfile("q1_tb.vcd");
	$dumpvars(0, q1_tb);

	W=4'b0011; En=1'b1; #10;
	W=4'b0110; En=1'b1; #10;
	W=4'b1010; En=1'b1; #10;
	W=4'b1001; En=1'b1; #10;

	$display("Test complete");
end 
endmodule