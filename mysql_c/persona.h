#pragma once
#include <iostream>
using namespace std;
class persona{

protected: string nombres, apellidos, direccion,fecha_nacimiento;
		int telefono=0;
protected:
	persona() {
	}
	persona(string nom, string ape, string dir, int tel,string fn) {
		nombres = nom;
		apellidos = ape;
		direccion = dir;
		telefono = tel;
		fecha_nacimiento = fn;
	}

};

