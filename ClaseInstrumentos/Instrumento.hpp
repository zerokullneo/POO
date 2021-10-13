#include <iostream>
#include <string>
#include <vector>

using namespace std;

class Instrumento
{
	public:
		enum tclase{instrumento, percusion, cuerda, viento};
		Instrumento(string n): nom(n), clase_(instrumento){};
		void tocar() const{
			std::cout << "Soy un " << nombre() << " y pertenezco a " << clase() << std::endl;
		};
		string nombre() const { return nom; }
		string clase() const 
		{
			switch (clase_)
			{
				case percusion:
					return "Percusión";
				case cuerda:
					return "Cuerda";
				case viento:
					return "Viento";
				default:
					return "Instrumento";
			}
		}

	protected:
		string nom;
		tclase clase_;
};

class Percusion: public Instrumento
{
	public:
		Percusion(string n): Instrumento(n) { clase_ = percusion;}
};

class Cuerda: public Instrumento
{
	public:
		Cuerda(string n): Instrumento(n) { clase_ = cuerda;}
};

class Viento: public Instrumento
{
	public:
		Viento(string n): Instrumento(n) { clase_ = viento;}
};