/* WARNING: Do not include any other libraries here,
 * otherwise you will get an error while running test.py
 * You can still use printf for debugging without including
 * <stdio.h>, although you might get a compiler warning. In general,
 * it's not good practice to ignore compiler warnings, but in this
 * case it's OK.
 *
 * Using printf will interfere with our script capturing the execution results.
 * At this point, you can only test correctness with ./btest.
 * After confirming everything is correct in ./btest, remove the printf
 * and run the complete tests with test.py.
 */

 /*
 * bitAnd - x & y using only ~ and |
 * Example: bitAnd(4, 5) = 4
 * Legal ops: ~ |
 * Max ops: 7
 * Difficulty: 1
 */
int bitAnd(int x, int y) {
    return ~(~x|~y);
    return 2;
}

/*
 * bitXor - x ^ y using only ~ and &
 *   Example: bitXor(4, 5) = 1
 *   Legal ops: ~ &
 *   Max ops: 7
 *   Difficulty: 1
 */
int bitXor(int x, int y) {
    return ~(~x&~y)&~(x&y);
    return 2;
}

/*
 * samesign - Determines if two integers have the same sign.
 *   0 is not positive, nor negative
 *   Example: samesign(0, 1) = 0, samesign(0, 0) = 1
 *            samesign(-4, -5) = 1, samesign(-4, 5) = 0
 *   Legal ops: >> << ! ^ && if else &
 *   Max ops: 12
 *   Difficulty: 2
 *
 * Parameters:
 *   x - The first integer.
 *   y - The second integer.
 *
 * Returns:
 *   1 if x and y have the same sign , 0 otherwise.
 */
int samesign(int x, int y) {
    if(!x){
        if(!y){
            return 1;
        }
        return 0;
    }
    if(!y){
        return 0;
    }
    return !((x>>31)^(y>>31));
    return 2;
}

/*
 * logtwo - Calculate the base-2 logarithm of a positive integer using bit
 *   shifting. (Think about bitCount)
 *   Note: You may assume that v > 0
 *   Example: logtwo(32) = 5
 *   Legal ops: > < >> << |
 *   Max ops: 25
 *   Difficulty: 4
 */
int logtwo(int v) {
    int ans=0;
    int temp;
    temp=v>0xFFFF;
    ans=ans|(temp<<4);
    v=v>>(temp<<4);
    temp=v>0xFF;
    ans=ans|(temp<<3);
    v=v>>(temp<<3);
    temp=v>0xF;
    ans=ans|(temp<<2);
    v=v>>(temp<<2);
    temp=v>0x3;
    ans=ans|(temp<<1);
    v=v>>(temp<<1);
    temp=v>0x1;
    ans=ans|temp;
    return ans;

    return 2;
}

/*
 *  byteSwap - swaps the nth byte and the mth byte
 *    Examples: byteSwap(0x12345678, 1, 3) = 0x56341278
 *              byteSwap(0xDEADBEEF, 0, 2) = 0xDEEFBEAD
 *    Note: You may assume that 0 <= n <= 3, 0 <= m <= 3
 *    Legal ops: ! ~ & ^ | + << >>
 *    Max ops: 17
 *    Difficulty: 2
 */
int byteSwap(int x, int n, int m) {
    int nn=n<<3;       
    int mm=m<<3;        
    int nmask=0xFF<<nn;  
    int mmask=0xFF<<mm;   
    int nbyte=(x>>nn) & 0xFF; 
    int mbyte=(x>>mm) & 0xFF;  
    return (x&~nmask&~mmask)|(nbyte<<mm)|(mbyte<<nn);

    return 2;
}

/*
 * reverse - Reverse the bit order of a 32-bit unsigned integer.
 *   Example: reverse(0xFFFF0000) = 0x0000FFFF reverse(0x80000000)=0x1 reverse(0xA0000000)=0x5
 *   Note: You may assume that an unsigned integer is 32 bits long.
 *   Legal ops: << | & - + >> for while ! ~ (You can define unsigned in this function)
 *   Max ops: 30
 *   Difficulty: 3
 */
unsigned reverse(unsigned v) {
    unsigned r=0;
    unsigned i=32;
    while(i){
        r=(r<<1)|(v&1);
        v=v>>1;
        i=i-1;
    }
    return r;

    return 2;
}

/*
 * logicalShift - shift x to the right by n, using a logical shift
 *   Examples: logicalShift(0x87654321,4) = 0x08765432
 *   Note: You can assume that 0 <= n <= 31
 *   Legal ops: ! ~ & ^ | + << >>
 *   Max ops: 20
 *   Difficulty: 3
 */
int logicalShift(int x, int n) {
    int temp=x>>n;
    int mask=~(((1<<31)>>n)<<1);
    return temp&mask;
    return 2;
}

/*
 * leftBitCount - returns count of number of consective 1's in left-hand (most) end of word.
 *   Examples: leftBitCount(-1) = 32, leftBitCount(0xFFF0F0F0) = 12,
 *             leftBitCount(0xFE00FF0F) = 7
 *   Legal ops: ! ~ & ^ | + << >>
 *   Max ops: 50
 *   Difficulty: 4
 */
int leftBitCount(int x) {
    int y=~x,n=0,t;
    t=!(y>>16); 
    n=n+(t<<4); 
    y=y<<(t<<4);
    t=!(y>>24); 
    n=n+(t<<3); 
    y=y<<(t<<3);
    t=!(y>>28); 
    n=n+(t<<2); 
    y=y<<(t<<2);
    t=!(y>>30); 
    n=n+(t<<1); 
    y=y<<(t<<1);
    t=!(y>>31); 
    n=n+t; 
    y=y<<t;
    n=n+!y;
    return n;
    return 2;
}

/*
 * float_i2f - Return bit-level equivalent of expression (float) x
 *   Result is returned as unsigned int, but it is to be interpreted as
 *   the bit-level representation of a single-precision floating point values.
 *   Legal ops: if else while for & | ~ + - >> << < > ! ==
 *   Max ops: 30
 *   Difficulty: 4
 */
unsigned float_i2f(int x) {
    if(x==0){
        return 0;
    }
    unsigned s=x&0x80000000,a=x;
    if(x<0){
        a=~x+1;
    }
    int e=0;
    while((a&0x80000000)==0){
        a=a<<1;e=e+1;
    }
    int exp=31-e+127;
    unsigned f=(a>>8)&0x7FFFFF,r=a&0xFF;
    if(r>0x80){
        f=f+1;
    }
    else if(r==0x80){
        if(f&1){
            f=f+1;
        }
    }
    if(f==0x800000){
        f=0;
        exp=exp+1;
    }
    return s|(exp<<23)|f;
    return 2;
}

/*
 * floatScale2 - Return bit-level equivalent of expression 2*f for
 *   floating point argument f.
 *   Both the argument and result are passed as unsigned int's, but
 *   they are to be interpreted as the bit-level representation of
 *   single-precision floating point values.
 *   When argument is NaN, return argument
 *   Legal ops: & >> << | if > < >= <= ! ~ else + ==
 *   Max ops: 30
 *   Difficulty: 4
 */
unsigned floatScale2(unsigned uf) {
    unsigned s=uf&0x80000000;
    unsigned e=uf&0x7F800000;
    unsigned f=uf&0x007FFFFF;
    if(e==0x7F800000){
        return uf;
    }
    if(e==0){
        f=f<<1;
        if(f&0x00800000){
            e=0x00800000;
            f=f&0x007FFFFF;
        }
    }else{
        e=e+0x00800000;
        if(e==0x7F800000){
            f=0;
        }
    }
    return s|e|f;
    return 2;
}

/*
 * float64_f2i - Convert a 64-bit IEEE 754 floating-point number to a 32-bit signed integer.
 *   The conversion rounds towards zero.
 *   Note: Assumes IEEE 754 representation and standard two's complement integer format.
 *   Parameters:
 *     uf1 - The lower 32 bits of the 64-bit floating-point number.
 *     uf2 - The higher 32 bits of the 64-bit floating-point number.
 *   Returns:
 *     The converted integer value, or 0x80000000 on overflow, or 0 on underflow.
 *   Legal ops: >> << | & ~ ! + - > < >= <= if else
 *   Max ops: 60
 *   Difficulty: 3
 */
int float64_f2i(unsigned uf1, unsigned uf2) {
    unsigned s=uf2>>31;
    unsigned e=(uf2>>20)&0x7FF;
    if(!(e-0x7FF)){
        return 0x80000000;
    }
    if(!e){
        return 0;
    }
    int a=e-1023;
    if(a<0){
        return 0;
    }
    if(a>=31){
        return 0x80000000;
    }
    int b=52-a;
    unsigned h=(1<<20)|(uf2&0xFFFFF);
    unsigned l=uf1;
    unsigned r;
    if(b>=32){
        r=h>>(b-32);
    }else{
        r=(h<<(32-b))|(l>>b);
    }
    if(s){
        return ~r+1;
    }
    return r;

    return 2;
}

/*
 * floatPower2 - Return bit-level equivalent of the expression 2.0^x
 *   (2.0 raised to the power x) for any 32-bit integer x.
 *
 *   The unsigned value that is returned should have the identical bit
 *   representation as the single-precision floating-point number 2.0^x.
 *   If the result is too small to be represented as a denorm, return
 *   0. If too large, return +INF.
 *
 *   Legal ops: < > <= >= << >> + - & | ~ ! if else &&
 *   Max ops: 30
 *   Difficulty: 4
 */
unsigned floatPower2(int x) {
    if(x>127){
        return 0x7F800000;
    }
    if(x<-149){
        return 0;
    }
    if(x<-126){
        return 1<<(x+149);
    }   
    return (x+127)<<23;
    return 2;
}
