module q3(clk, q);
	input clk; 
	output [3:0]q;
	tff s0(1'b1, clk, q[0]);
	tff s1(1'b1, q[0], q[1]);
	tff s2(1'b1, q[1], q[2]);
	tff s3(1'b1, q[2], q[3]);
endmodule

module tff(t, clk, q);
	input t, clk;
	output reg q;
	always @(negedge clk)
	begin
	if(!t)
	q<=q;
	else 
	q<=~q;
	end
endmodule