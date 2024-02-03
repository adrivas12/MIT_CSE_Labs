__kernel void swap(__global int *A, __global int *C) {
  int thd = get_global_id(0);
  int oct = 0;
  if(thd%2==0){
    oct = A[thd];
    A[thd]=A[thd+1];
    A[thd+1]=oct;
  }  
  C[thd]= A[thd];
}