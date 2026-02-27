1bool isPowerOfTwo(int n) {
2    for ( int x = 0; x <= 31; x++){
3    int pow2 = pow(2,x); 
4    if(pow2 == n)
5    return true;
6    if(pow2 > n)
7    return false;
8    }
9    return false;
10}