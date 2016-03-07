#include <cstdlib>
#include <cassert>
#include "Racional.hpp"

Racional::Racional(long nu, long de): n_(nu), d_(de)
{
	assert(d_ != 0);
	
	if(n_ == 0)
		d_ = 1;
	else
	{
		if(d_ < 0)
		{
			n_ = -n_;
			d_ = -d_;
		}
		long m = mcd(abs(n_), d_);
		n_ /= m;
		d_ /= m;
	}
}

Racional operator +(const Racional& r, const Racional& s)
{
	Racional t;
	
	long m = Racional::mcd(r.d_, s.d_);
	t.n_ = s.d_ / m * r.n_ + r.d_ / m * s.n_;
	t.d_ = t.n_ == 0 ? 1 : Racional::mcm(r.d_, s.d_);
	return t;
}

Racional operator *(const Racional& r, const Racional& s)
{
	Racional t;
	
	if(r.n_ && s.n_)
	{
		long a = Racional::mcd(abs(r.n_), s.d_);
		long b = Racional::mcd(r.d_, abs(s.n_));
		t.n_ = (r.n_ / a) * (s.n_ / b);
		t.d_ = (r.d_ / b) * (s.d_ / a);
	}
	
	return t;
}

Racional operator -(const Racional& r)
{
	Racional s;
	
	if(r.n_ != 0)
	{
		s.n_ = -r.n_;
		s.d_ = r.d_;
	}
	return s;
}

Racional inversa(const Racional& r)
{
	Racional s;
	
	assert(r.n_ != 0);
	
	if(r.n_ > 0)
	{
		s.n_ = r.d_;
		s.d_ = r.n_;
	}
	else
	{
		s.n_ = -r.d_;
		s.d_ = -r.n_;
	}
	return s;
}

Racional::~Racional()
{
}

long Racional::mcd(long x, long y)
{
	long a{};
	
	if(x < y)
	{
		a = x;
		x = y;
		y = a;
	}
	
	while(a != x % y)
	{
		x = y;
		y = a;
	}
	
	return y;
}

long Racional::mcm(long x, long y)
{
	return x / mcd(x,y) * y;
}