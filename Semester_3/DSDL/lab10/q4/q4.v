module q4(w, clk, Q);
	input [4:0]w;
	input clk;
	output [4:0]Q;
	Dff stage0(w[0], clk, Q[0]);
	Dff stage1(w[1], clk, Q[1]);
	Dff stage2(w[2], clk, Q[2]);
	Dff stage3(w[3], clk, Q[3]);
	Dff stage4(w[4], clk, Q[4]);
endmodule

module Dff(d, clk, q);
	input d, clk; 
	output q;
	reg q;
	always @(negedge clk)
	begin
	q<=d;
	end
endmodule