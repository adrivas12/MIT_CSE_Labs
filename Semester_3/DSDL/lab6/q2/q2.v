module q2(w, s, f);
	input [15:0]w;
	input [3:0]s;
	output f;
	wire [3:0]m;
	mux4to1 stage0(w[0], w[1], w[2], w[3], s[0],s[1], m[0]);
	mux4to1 stage1(w[4], w[5], w[6], w[7], s[0], s[1], m[1]);
	mux4to1 stage2(w[8], w[9], w[10], w[11], s[0], s[1], m[2]);
	mux4to1 stage3(w[12], w[13], w[14], w[15], s[0], s[1], m[3]);
	mux4to1 stage4(m[0], m[1], m[2], m[3], s[2], s[3], f);
endmodule

module mux4to1(w0, w1, w2, w3, s0, s1, f);
	input w0, w1, w2, w3;
	input s0, s1;
	output f;
	reg f;
	always @(*)
	begin
	f = s1?(s0?w3:w2):(s0?w1:w0);
	end
endmodule