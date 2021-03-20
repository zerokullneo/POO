class C
{
	public:
		C();
		C(int a, int b, int c, int d);
		int f1(int i) const;
		int f2(int i);
		static void f3(C& c) {m = c.l;}
		static int n;
	private:
		mutable int i;
		const int j;
		mutable int k;
		int l;
		static int m;
};

C::C():j(0) {i = k = l = 0;}

C::C(int a, int b, int c, int d) : i(a), j(b), k(c), l(d) {}

int C::f1(int i) const
{
	//l = i;
	k = i;
	return 0;
}

int C::f2(int i)
{
	k = i; l = i; return 0;
}
