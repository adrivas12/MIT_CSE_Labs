module q4(A, B, C, D, f);
	input A, B, C, D;
	output f;
	nor(g1, ~A, ~C);
	nor(f, g1, ~D);
endmodule