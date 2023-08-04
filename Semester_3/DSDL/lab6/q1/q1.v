module q1(w, s0, s1, f);
	input [3:0]w;
	input s0, s1;
	output f;
	wire f1, f2;
	mux2to1 stage0(w[0], w[1], s0, f1);
	mux2to1 stage1(w[2], w[3], s0, f2);
	mux2to1 stage2(f1, f2, s1, f);
endmodule


module mux2to1(w0, w1, s, f);
	input w0, w1, s;
	output f;
	reg f;
	always@(w0 or w1 or s)
	begin
	if(s==0)
		assign f = w0;
	else 
		assign f = w1;
	end
endmodule