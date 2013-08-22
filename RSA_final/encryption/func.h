#ifndef FUNC_H
#define FUNC_H
#define MAX 5000
int isPrime(long long a);
void display();
int gcd(long long a,long long b);
void input(long long num[]);
long long generating_coprime(long long m);
long long gen_d(long  long e,long long m,long long n);
long long encrypt(long long e,long long n,long long num);
void decrypt(long long d,long long n,long long val);

long long input_str(long long num);
void read();
void write_e_file(long long e_array[]);
//int* convert_string_ascii(char s[]);
#endif
