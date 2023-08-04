module q2a(a, b, c, d, f, g);
	input a, b, c, d;
	output f, g;
	nand(h, a, b);
	xor(f, h, c, d);
	nor(g, d, c, b);
endmodule
