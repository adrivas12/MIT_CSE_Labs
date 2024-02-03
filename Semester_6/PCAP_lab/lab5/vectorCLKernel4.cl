__kernel void decimal(__global int *A, __global int *C) {
  int id = get_global_id(0);
  int oct = 0;
  int j = 0, q = 0, r = 0;
  q = A[id];
  while (q != 0) {
    r = q % 10;
    oct = oct + (int)pow((double)2,(double)j)*r;
    q = q / 10;
    j++;
  }
  C[id] = oct;
}