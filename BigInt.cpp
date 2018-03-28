#include<iostream>
#include<bitset>
#include<algorithm>
#include<cstdio>
#include<cmath>
#include<cstring>
using namespace std;

#define BigInt bitset<B>

const int F=520,B=F+1;

bool operator<(const BigInt& a,const BigInt& b)
{
	if(a[F]!=b[F])
		return a[F]>b[F];
	int i;
	for(i=F-1;(~i)&&a[i]==b[i];--i);
	return ~i&&a[i]<b[i];
}

bool operator>(const BigInt& a,const BigInt& b)
{
	return b<a;
}

bool operator<=(const BigInt& a,const BigInt& b)
{
	return (a==b)||a<b;
}

bool operator>=(const BigInt& a,const BigInt& b)
{
	return b<=a;
}

BigInt operator+(BigInt a,BigInt b)
{
	BigInt t;
	while(!b.none())
	{
		t=a;
		a^=b;
		(b&=t)<<=1;
	}
	return a;
}

void operator+=(BigInt& a,const BigInt& b)
{
	a=a+b;
}

void A1(BigInt& a)
{
	int i;
	for(i=0;a[i];++i)
		a[i]=0;
	a[i]=1;
}

BigInt operator-(BigInt a)
{
	a.flip();
	A1(a);
	return a;
}

BigInt operator-(const BigInt& a,const BigInt& b)
{
	return a+(-b);
}

void operator-=(BigInt& a,const BigInt& b)
{
	a=a-b;
}

BigInt operator*(BigInt a,BigInt b)
{
	int fl(a[F]^b[F]);
	if(a[F])
		a=-a;
	if(b[F])
		b=-b;
	BigInt res;
	for(;!b.none();b>>=1,a<<=1)if(b[0])
		res+=a;
	return fl?(-res):res;
}

void operator*=(BigInt& a,const BigInt& b)
{
	a=a*b;
}

BigInt toBigInt(int x)
{
	if(x>=0)
		return BigInt(x);
	else
		return -BigInt(-x);
}

BigInt operator/(BigInt a,BigInt b)
{
	int fl(a[F]^b[F]);
	if(a[F])
		a=-a;
	if(b[F])
		b=-b;
	BigInt L,M,R(a),A;
	while(L<=R)
	{
		M=(L+R)>>1;
		if(M*b<=a)
		{
			L=A=M;
			A1(L);
		}
		else
			R=M-BigInt(1);
	}
	return fl?(-A):A;
}

void operator/=(BigInt& a,const BigInt& b)
{
	a=a/b;
}

int d[3333],l;

void song()
{
	for(int i=0;i<l;++i)
		if(d[i]>=10)
		{
			d[i]-=10;
			++d[i+1];
		}
	if(d[l])
		++l;
}

void M2()
{
	for(int i=0;i<l;++i)
		d[i]<<=1;
	song();
}

void A1()
{
	++d[0];
	song();
}

void print(BigInt a)
{
	memset(d,0,sizeof d);l=1;
	int fl(a[F]),i;
	if(fl)
		a=-a;
	for(i=F-1;~i;--i)
	{
		M2();
		if(a[i])
			A1();
	}
	if(fl)
		putchar('-');
	for(i=l-1;~i;--i)
		putchar(d[i]+48);
}

BigInt gcd(BigInt a,BigInt b)
{
	return b.none()?a:gcd(b,a-a/b*b);
}

int main()
{
	return 0;
}
