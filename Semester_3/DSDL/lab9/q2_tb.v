`timescale 1ns/1ns
`include "q2.v"

module q2_tb();
reg [3:0]W;
reg En;
wire F, G, H;
q2 q2(W, En, F, G, H);
initial 
begin
	$dumpfile("q2_tb.vcd");
	$dumpvars(0, q2_tb);

	W=4'b0000;En=1'b1;#10;
	W=4'b0001;En=1'b1;#10;
	W=4'b0010;En=1'b1;#10;
	W=4'b0011;En=1'b1;#10;
	W=4'b0100;En=1'b1;#10;
	W=4'b0101;En=1'b1;#10;
	W=4'b0110;En=1'b1;#10;
	W=4'b0111;En=1'b1;#10;
	W=4'b1000;En=1'b1;#10;
	W=4'b1001;En=1'b1;#10;
	W=4'b1010;En=1'b1;#10;
	W=4'b1011;En=1'b1;#10;
	W=4'b1100;En=1'b1;#10;
	W=4'b1101;En=1'b1;#10;
	W=4'b1110;En=1'b1;#10;
	W=4'b1111;En=1'b1;#10;

	$display("test complete");

end 
endmodule