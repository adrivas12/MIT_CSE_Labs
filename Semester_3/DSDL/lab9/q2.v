module q2( W, En, F, G, H);
	input [3:0]W;
	input En;
	wire [0:15]f;
	output F, G, H;
	dec4to16 stage0(W[3:0], En, f[0:15]);
	assign F=(f[3]|f[6]|f[7]|f[10]|f[11]|f[14]);
	assign G=(f[2]|f[3]|f[10]|f[14]);
	assign H=(f[0]|f[1]|f[3]|f[7]|f[14]|f[15]);
endmodule

module dec4to16(W, En, Y);
	input [3:0]W;
	input En;
	output [0:15]Y;
	wire [0:3]en;
	dec2to4 stage0(W[3:2], En, en[0:3]);
	dec2to4 stage1(W[1:0], en[0], Y[0:3]);
	dec2to4 stage2(W[1:0], en[1], Y[4:7]);
	dec2to4 stage3(W[1:0], en[2], Y[8:11]);
	dec2to4 stage4(W[1:0], en[3], Y[12:15]);
endmodule

module dec2to4(W, En, Y);
	input [1:0]W;
	input En;
	output [0:3]Y;
	reg [0:3]Y;
	always @(W or En)
	begin
	if(En==0)
		Y=4'b0000;
	else
	begin
	case(W)
		0:Y=4'b1000;
		1:Y=4'b0100;
		2:Y=4'b0010;
		3:Y=4'b0001;
	endcase	
	end
	end
endmodule