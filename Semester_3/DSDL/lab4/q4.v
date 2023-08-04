module q4(Cin, x, y, s, Cout);
	input Cin;
	input [3:0]x,y;
	output Cout;
	output [3:0]s;
	wire k,c4,cc;
	wire[3:0]z,h, ss;
	adder4 stage0(Cin, x, y, z, c4);
	assign k=(c4|(z[3]&z[2])|(z[3]&z[1]));
	assign h[0]=0;
	assign h[1]=k;
	assign h[2]=k;
	assign h[3]=0;
	adder4 stage1(Cin, z, h, ss, cc);
endmodule


module adder4(Cin, x, y, s, Cout);
	input Cin;
	input [3:0]x;
	input [3:0]y;
	output [3:0]s;
	output Cout;
	wire [3:1]c;
	fulladd stage0(Cin, x[0], y[0], s[0], c[1]);
	fulladd stage1(c[1], x[1], y[1], s[1], c[2]);
	fulladd stage2(c[2], x[2], y[2], s[2], c[3]);
	fulladd stage3(c[3], x[3], y[3], s[3], Cout);
endmodule

module fulladd(Cin, x, y, s, Cout);
	input Cin, x, y;
	output s, Cout;
	assign s = x^y^Cin;
	assign Cout = (x&y)|(x&Cin)|(y&Cin);
endmodule