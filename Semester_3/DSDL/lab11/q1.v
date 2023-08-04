module q1(clk, A);
	input clk;
	output [3:0]A;
	jkff s0(1'b1, 1'b1, clk, A[0]);
	jkff s1(1'b1, 1'b1, A[0], A[1]);
	jkff s2(1'b1, 1'b1, A[1], A[2]);
	jkff s3(1'b1, 1'b1, A[2], A[3]);
endmodule

module jkff(j, k, clk, q);
	input j, k, clk;
	output reg q;
	always @(negedge clk)
	begin
	casex({j,k})
			3'b1xx:q<=0;
			3'b001:q<=0;
			3'b010:q<=1;
			3'b011:q<=~q;
			3'b000:q<=q;
		endcase
	end
endmodule