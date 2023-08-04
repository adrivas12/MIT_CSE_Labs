module q3(W, En, Y);
	input [3:0]W;
	input En;
	output [0:15]Y;
	wire [0:3]en;
	dec2to4 stage0(W[3:2], En, en[0:3]);
	dec2to4 stage1(W[1:0], ~en[0], Y[0:3]);
	dec2to4 stage2(W[1:0], ~en[1], Y[4:7]);
	dec2to4 stage3(W[1:0], ~en[2], Y[8:11]);
	dec2to4 stage4(W[1:0], ~en[3], Y[12:15]);
endmodule

module dec2to4(W, En, Y);
	input [1:0]W;
	input En;
	output [0:3]Y;
	reg [0:3]Y;
	always @(W or En)
	begin
	if(En==0)
		Y=4'b1111;
	else
	begin
	case(W)
		0:Y=4'b0111;
		1:Y=4'b1011;
		2:Y=4'b1101;
		3:Y=4'b1110;
	endcase	
	end
	end
endmodule