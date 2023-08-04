module q2(a, b, c, d, f);
	input a, b, c, d;
	output f;
	nor(g1, d, d);
	nor(g2, c, b);
	nor(g3, b, d);
	nor(g4, c, g1, a);
	nor(g5, g2, g3, g4);
	nor(f, g5, g5);
	
endmodule