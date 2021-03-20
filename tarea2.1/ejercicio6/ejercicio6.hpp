class C
{
	public:
		C(int i): n(i), m(0.0){}
		C operator +(const C& c);
	private:
		int n;
		double m;
};

C operator +(const C& c, const C& d);
