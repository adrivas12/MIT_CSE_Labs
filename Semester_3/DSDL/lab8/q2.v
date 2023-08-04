module q2(W, En, Y);
	input [3:0]W;
	input En;
	output [0:15]Y;

	dec3to8 stage0(W[2:0], (~W[3]&En), Y[0:7]);
	dec3to8 stage1(W[2:0], (W[3]&En), Y[8:15]);
endmodule

module dec3to8(W, En, Y);
	input [2:0]W;
	input En;
	output [0:7]Y;
	reg [0:7]Y;
	integer k;
	always @(W or En)
		for(k=0; k<=7; k=k+1)
			if((W==k)&&(En==1))
				Y[k]=1;
			else 
				Y[k]=0;

endmodule

