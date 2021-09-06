#include "estudiante.hpp"
#include "doctorando.hpp"

int main()
{
	Estudiante e("María Pérez Sánchez", 31682034);
	Doctorando d("José López González", 32456790, "Dr. Juan Jiménez", 134);

	Estudiante* pe = &e;
	pe->mostrar(); // e . mostrar()
	pe = &d; // conversión <hacia arriba>
	pe->mostrar(); // d. estudiante :: mostrar()

	Doctorando* pd = &d;
	pd->mostrar(); // d.mostrar()
	pd->Estudiante::mostrar(); // d.estudiante :: mostrar()
}

/*int main()
{
	Estudiante e("María Pérez Sánchez", 31682034), *pe;
	Doctorando d("José López González", 32456790, "Dr. Juan Jiménez", 134), *pd;

	pe = &d; //bien
	pd = pe; //ERROR - Incompatible pointer types assigning to 'Doctorando *' from 'Estudiante
	pd = static_cast<Doctorando*>(pe); //bien
	e = d; //bien
	d = e;	//ERROR - No viable overloaded '=' Candidate function (the implicit copy assignment operator)
			//not viable: no known conversion from 'Estudiante' to 'const Doctorando' for 1st argument
	d = Doctorando(e); //ERROR - No matching conversion for functional-style cast from 'Estudiante' to 'Doctorando'
					//Candidate constructor (the implicit copy constructor)
					//not viable: no known conversion from 'Estudiante' to 'const Doctorando' for 1st argument
	d = static_cast<Doctorando>(e);	//ERROR - No matching conversion for static_cast from 'Estudiante' to 'Doctorando'
								//Candidate constructor (the implicit copy constructor)
								//not viable: no known conversion from 'Estudiante' to 'const Doctorando' for 1st argument
	d = reinterpret_cast<Doctorando>(e); //ERROR - Reinterpret_cast from 'Estudiante' to 'Doctorando' is not allowed
}*/