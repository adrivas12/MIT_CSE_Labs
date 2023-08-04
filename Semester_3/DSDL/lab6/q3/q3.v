module q3(w, s, f);
	input [15:0]w;
	input [3:0]s;
	output f;
	wire[1:0]m;
	mux8to1 stage0(w[7:0], s[2:0], m[0]);
	mux8to1 stage1(w[15:8], s[2:0], m[1]);
	mux2to1 stage2(m[0], m[1], s[3], f);
endmodule

module mux8to1(w, s, f);
	input [7:0]w;
	input [2:0]s;
	output reg f;
	always @(w or s)
		case(s)
		0:f=w[0];
		1:f=w[1];
		2:f=w[2];
		3:f=w[3];
		4:f=w[4];
		5:f=w[5];
		6:f=w[6];
		7:f=w[7];
		endcase
endmodule

module mux2to1(w0, w1, s, f);
	input w0, w1, s;
	output f;
	reg f;
	always @(w0 or w1 or s)
		 f = s?w1:w0;
endmodule