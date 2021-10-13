#include <iostream>
#include <string>

using namespace std;

class Pedido
{
	public:
		Pedido(unsigned int num = 1, double pvp = 0.0):num_(num), total_(pvp){};
		const unsigned int NumeroPedido() const { return num_;}
		const double Total() const{ return total_;}

	private:
		unsigned int num_;
		double total_;
};