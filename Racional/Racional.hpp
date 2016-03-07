#ifndef RACIONAL_HPP
#define RACIONAL_HPP

class Racional
{
	public:
		Racional(long nu = 0, long de = 1);
		
		long num()const {return n_;}
		long den()const {return d_;}
		
		friend Racional operator +(const Racional& r, const Racional& s);
		friend Racional operator *(const Racional& r, const Racional& s);
		friend Racional operator -(const Racional& r);
		friend Racional inversa(const Racional& r);
		~Racional();

	private:
		long n_, d_;
		static long mcd(long, long);
		static long mcm(long, long);
};

inline bool operator ==(const Racional& r, const Racional& s)
{
	return(r.num() == s.num()) and (r.den() == s.den());
}

inline bool operator <(const Racional& r, const Racional& s)
{
	return Racional(r + -s).num() < 0;
}

#endif // RACIONAL_HPP
