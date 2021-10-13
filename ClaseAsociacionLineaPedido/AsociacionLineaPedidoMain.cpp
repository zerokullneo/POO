#include "LineaPedido.hpp"

int main()
{
	Articulo Libro001("894333222111","Iniciación a C++", 20.50), MonturaRayban000, MonturaRayban001("RB10AZ","RayBan Clasica", 90.00);
	Pedido Pedido001(1), Pedido002(2);

	LineaPedido LP, LP2;
	LP.asocia(Libro001, Pedido001);
	LP.asocia(MonturaRayban000, Pedido001);

	LP2.asocia(MonturaRayban000, Pedido002);
	LP2.asocia(MonturaRayban001, Pedido002);

	std::cout << "------------------------" << std::endl;
	std::cout << "Lineas Pedido Pedido001" << std::endl;
	std::cout << LP.asocia(MonturaRayban000).begin()->second->NumeroPedido() << std::endl;
	std::cout << LP.asocia(Pedido001).begin()->second->Referencia() << ", " << LP.asocia(Pedido001).begin()->second->Titulo() << std::endl;

	std::cout << "------------------------" << std::endl;
	std::cout << "Lineas Pedido Pedido002" << std::endl;
	std::cout << LP2.asocia(MonturaRayban001).begin()->second->NumeroPedido() << std::endl;
	std::cout << LP2.asocia(Pedido002).begin()->second->Referencia() << ", " << LP2.asocia(Pedido002).begin()->second->Titulo() << std::endl;

	return 0;
}