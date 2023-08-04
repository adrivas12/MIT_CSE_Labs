#include<stdio.h>
#include<stdlib.h>

typedef struct
{
	float real;
	float img;
}complex;

complex sum(complex a, complex b)
{
	complex s;
	s.real = a.real + b.real;
	s.img = a.img + b.img;
	return s;
}

complex diff(complex a, complex b)
{
	complex d;
	d.real = a.real - b.real;
	d.img = a.img - b.img;
	return d;
}

complex product(complex a, complex b)
{
	complex m1;
	m1.real = (a.real * b.real) - (a.img * b.img);
	m1.img = (a.img * b.real) + (a.real * b.img);
	return m1;
}

int main()
{
	complex a, b;

	printf("Enter the real and imaginary parts of complex number 1: \n");
	scanf("%f%f", &a.real, &a.img);
	printf("Enter the real and imaginary parts of complex number 2: \n");
	scanf("%f%f", &b.real, &b.img);

	printf("Sum of the two complex numbers: %.2f + %.2fi \n", sum(a,b).real, sum(a,b).img);
	printf("Difference of the two complex numbers: %.2f + %.2fi \n", diff(a,b).real, diff(a,b).img);
	printf("Product of the two complex numbers: %.2f + %.2fi \n", product(a, b).real, product(a, b).img );

	return 0;
}



  