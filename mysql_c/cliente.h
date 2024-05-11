#pragma once
#include <mysql.h>
#include <iostream>
#include <string>
#include "conexionBD.h"
#include "persona.h"

using namespace std;
class cliente : persona{
private: string nit;

public:
	cliente() {
	}
	cliente(string nom, string ape, string dir, int tel,string fn, string n) : persona(nom, ape, dir, tel,fn) {
		nit = n;
	}

	void setnit(string n) { nit = n; }
	void setnombres(string nom) { nombres = nom; }
	void setapellidos(string ape) { apellidos = ape; }
	void setdireccion(string dir) { direccion = dir; }
	void settelefono(int tel) { telefono = tel; }

	string getnit() { return nit; }
	string getnombres() { return nombres; }
	string getapellidos() { return apellidos; }
	string getdireccion() { return direccion; }
	int gettelefono() { return telefono; }

	void crear() {
		int q_estado;
		conexionBD cn = conexionBD();
		cn.abrir_conexion();
		if (cn.getconectar()) {
			string t = to_string(telefono);
			string insert = "INSERT INTO clientes(nit,nombres,apellidos,direccion,telefono,fecha_nacimiento)VALUES('"+nit+"','" + nombres + "','" + apellidos + "','" + direccion + "','" + t + "','" + fecha_nacimiento + "',);";
			const char* i = insert.c_str();
			q_estado = mysql_query(cn.getconectar(), i);
			if (!q_estado) {
				cout << "ingreso exitoso..." << endl;
			}
			else {
				cout << "xxxx error al ingresar la informacionxxxx" << endl;
			}
		}else {
			cout << "----error en la conexion----" << endl;
		}
		cn.cerrar_conexion();
	}
	void leer() {
		int q_estado;
		conexionBD cn = conexionBD();
		MYSQL_ROW fila;
		MYSQL_RES* resultado;
		cn.abrir_conexion();
		if (cn.getconectar()) {
			string consulta = "select * from clientes";
			const char* c = consulta.c_str();
			q_estado = mysql_query(cn.getconectar(), c);
			if (!q_estado) {
				resultado = mysql_store_result(cn.getconectar());
				cout << "----------------clientes-------------" << endl;
				while (fila = mysql_fetch_row(resultado)) {
					cout << fila[0] << "," << fila[1] << "," << fila[2] << "," << fila[3] << "," << fila[4] << "," << fila[5] << "," << fila[6] << endl;
				}
			}
			else {
				cout << "error al ingresar la informacion..." << endl;
			}

		}
		else {
			cout << "xxxx error al ingresar xxxx" << endl;
		}
		cn.cerrar_conexion();
	}
};

