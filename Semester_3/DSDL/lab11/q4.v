module q3(clear, clk, q);
	input clear, clk;
	output [3:0]q;
	wire [1:0]w;
	tff s0(1, clk, q[0]);
	tff s1(q[0], clk, q[1]);
	assign w[0]=q[0]&q[1];
	tff s2(w[0], clk, q[2]);
	assign w[1]=w[0]&q[2];
	tff s3(w[1], clk, q[3]);
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