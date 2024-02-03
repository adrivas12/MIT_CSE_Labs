__kernel void octal(__global int *A, __global int *C) {
  int id = get_global_id(0);
  int oct = 0;
  int i = 1, j = 0, q = 0, r = 0;
  int octn[100];
  q = A[id];
  while (q != 0) {
    octn[i++] = q % 8;
    q = q / 8;
  }
  for (j = i - 1; j > 0; j--)
    oct = oct * 10 + octn[j];
  C[id] = oct;
}
