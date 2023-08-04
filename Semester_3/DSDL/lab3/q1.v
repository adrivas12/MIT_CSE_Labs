module q1(a, b, c, d, f);
    input a, b, c, d;
    output f;
    nand(g1, ~a, ~c);
    nand(g2, ~a, d);
    nand(g3, b, ~c);
    nand(g4, b, d);
    nand(f, g1, g2, g3, g4);
endmodule
