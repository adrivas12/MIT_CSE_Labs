`timescale 1ns/1ns
`include "q4.v"

module q4_tb();
reg [2:0]W;
reg [0:7]I;
reg En;
wire f;
q4 q4(W, I, En, f);
initial 
begin
	$dumpfile("q4_tb.vcd");
	$dumpvars(0, q4_tb);

	I=8'b00000111; W=3'b000; En=1'b1; #10;
	I=8'b00000111; W=3'b001; En=1'b1; #10;
	I=8'b00000111; W=3'b010; En=1'b1; #10;
	I=8'b00000111; W=3'b011; En=1'b1; #10;
	I=8'b00000111; W=3'b100; En=1'b1; #10;
	I=8'b00000111; W=3'b101; En=1'b1; #10;
	I=8'b00000111; W=3'b110; En=1'b1; #10;
	I=8'b00000111; W=3'b111; En=1'b1; #10;

	$display("test complete");

end 
endmodule
