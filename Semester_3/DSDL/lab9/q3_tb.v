`timescale 1ns/1ns
`include "q3.v"

module q3_tb();
reg [2:0]W;
reg En;
wire f;
q3 q3(W, En, f);
initial 
begin
	$dumpfile("q3_tb.vcd");
	$dumpvars(0, q3_tb);

	W=3'b000; En=1'b1; #10;
	W=3'b001; En=1'b1; #10;
	W=3'b010; En=1'b1; #10;
	W=3'b011; En=1'b1; #10;
	W=3'b100; En=1'b1; #10;
	W=3'b101; En=1'b1; #10;
	W=3'b110; En=1'b1; #10;
	W=3'b111; En=1'b1; #10;

	$display("test complete");

end 
endmodule
