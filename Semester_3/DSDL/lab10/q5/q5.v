module q5(w, clk, Q);
	input [5:0]w;
	input clk;
	output [5:0]Q;
	wire [5:0]f1, f2, f3;
	Dff stage0(w[0], clk, f1[0]);
	Dff stage1(f1[0], clk, f1[1]);
	Dff stage2(f1[1], clk, f1[2]);
	Dff stage3(f1[2], clk, f1[3]);
	Dff stage4(f1[3], clk, f1[4]);
	Dff stage5(f1[4], clk, Q[5]);
endmodule


module Dff(d, clk, q);
	input d;
	input clk; 
	output reg q;
	always @(posedge clk)
	begin
	q<=d;
	end
endmodule