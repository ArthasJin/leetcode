#include <iostream>
#include <limits.h>

using namespace std;

/**
    Set union
    A | B
    Set intersection
    A & B
    Set subtraction
    A & ~B
    Set negation
    ALL_BITS ^ A
    Set bit
    A |= 1 << bit
    Clear bit
    A &= ~(1 << bit)
    Test bit
    (A & 1 << bit) != 0
*/

// Consider the statement
// result = a ? b : c;
// Implement the above statement without using any conditional statements.
int fun1(int a, int b, int c) {
    int result = 0;
    a && (result = b, 1) || (result = c, 0);
    return result;
}

int fun2(int a, int b, int c) {
    int result = a & 1;
    result = b * result + (1 - result) * c;
    return result;
}

// Write a piece of code to find out if the system is x86 architecture of Sparc
// x86 is little endian, while sparc is big endian.
// So question really is asking to find if underlying system is little endian or big endian.
union{
    short s;
    char b[2];
} x;
bool check() {
    x.s = 1; /* 0(MSB)1(LSB) */
    if( x.b[0] == 1 ) { /* lower address has LSB */
        return LITTLE_ENDIAN;
    } else {
        return BIG_ENDIAN;
    }
}

int TestByteOrder() {
    short int word = 0x0001;
    char *byte = (char*)&word;
    return (byte[0] ? LITTLE_ENDIAN : BIG_ENDIAN);
}

int getMaxInt() {
    return (~0u) >> 1;
}

int getMinInt() {
    return 1 << 31;
}

int binayAdd(int a, int b) {
    int res = a ^ b;
    int carry = a & b;
    while (carry) {
        res = (carry) ^ res;
    //     carry =
    }
    return res;
}

int countOne(int num) {
    unsigned int n = num;
    int res = 0;
    while (n) {
        n &= (n - 1);
        res++;
    }
    return res;
}

// template <typename T>
// int sizeOf(T t) {
//     return (char *)(&t + 1) - (char *)(&t);
// }

#define SIZE_OF(type) (char *) (&type + 1) - (char *) (&type)

#define my_sizeof(type) \
    ({type x; (char *)(&x+1)-(char*)(&x);})

int rotateLeftBit(int n, int k) {
    return n << k | (unsigned int) n >> (sizeof (int) * 8 - k);
}

int main() {
    // cout<< TestByteOrder() << endl;
    // cout<< check() << endl;
    // hex(cout);
    // cout << (getMaxInt()) << endl;
    // cout << (getMaxInt() == INT_MAX) << endl;
    // cout << getMinInt() << endl;
    // cout << (getMinInt() == INT_MIN) << endl;
    // cout << binayAdd(11, 12) << endl;
    // cout << binayAdd(111, 112) << endl;
    // cout << binayAdd(76, 239) << endl;
    // cout << binayAdd(123, 999) << endl;
    // cout << binayAdd(43290, 876531) << endl;
    const char *s = "Hello";
    printf("%s\n", s);
    printf(s);

    int x = 1;
    cout << SIZE_OF(x) << endl;
    cout << my_sizeof(float) << endl;
    cout << my_sizeof(double) << endl;

    hex(cout);
    cout << rotateLeftBit(1, 1) << endl;
    cout << rotateLeftBit(1, 31) << endl;
    cout << rotateLeftBit(0xff, 1) << endl;
    cout << rotateLeftBit(1234, 13) << endl;
    return 0;
}

