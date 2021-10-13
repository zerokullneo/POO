#include <iostream>
#include <string>
#include <vector>

using namespace std;

class Instrumento
{
	public:
		enum tclase{instrumento, percusion, cuerda, viento};
		
		Instrumento(string n): nom(n), clase_(instrumento){};
		virtual void tocar() const{
			std::cout << "Soy un " << nombre() << " y pertenezco a " << clase() << std::endl;
		};
		string nombre() const { return nom; }
		string clase() const {string printclase_[] = {"instrumento", "percusión", "cuerda", "viento"}; return printclase_[clase_] ; }

	protected:
		string nom;
		tclase clase_;
};

class Percusion: public Instrumento
{
	public:
		Percusion(string n): Instrumento(n) { clase_ = percusion;}
		void tocar() const{
			std::cout << "Soy un " << nombre() << " y pertenezco a " << clase() << std::endl;
			//std::cout << "Soy un " << nombre() << " y pertenezco a percusión" << std::endl;
		};
};

class Cuerda: public Instrumento
{
	public:
		Cuerda(string n): Instrumento(n) { clase_ = cuerda;}
		void tocar() const{
			std::cout << "Soy un " << nombre() << " y pertenezco a " << clase() << std::endl;
			//std::cout << "Soy un " << nombre() << " y pertenezco a cuerda" << std::endl;
		};
};

class Viento: public Instrumento
{
	public:
		Viento(string n): Instrumento(n) { clase_ = viento;}
		void tocar() const{
			std::cout << "Soy un " << nombre() << " y pertenezco a " << clase() << std::endl;
			//std::cout << "Soy un " << nombre() << " y pertenezco a viento" << std::endl;
		};
};