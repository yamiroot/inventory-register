#include <iostream>
#include <fstream>
#include <string.h>
#include <stdlib.h>
#include <locale.h> // Librería de la función: setlocale(LC_ALL,"").

using namespace std;

//Prototipos
void menuPrincipal();
int menu();
int menuAdicional();
void registro_producto();
void registro_clientes();
void registro_ventas();
void relacion_clientes();
void relacion_productos();
void cliente_especifico();
void datos_cliente(string);
void ventas_diaras();
void ventas_mes_anio();
void reporte_dia(int);
void reporte_mes_anio(int, int);
float retornar_precio(string);
bool validar_producto(string);
bool validar_cliente(string);
string retornar_nombre(string);
string retornar_nombre_cliente(string);


using namespace std;

int main(){
	
	system ("color 8F") ; // Defino color para la consola y letra.
	
	setlocale(LC_ALL,"") ; // Función que permite imprimir tildes y caracteres raros en consola.
	
	menuPrincipal();
	
	system("pause");
	return 0;
}

void menuPrincipal(){
	int rpt, option;
	
	do{
		system("CLS");
		rpt = menu();
		
	}while((rpt < 1) || (rpt > 5));
	
	switch(rpt){
		case 1:
			registro_producto();
			break;
			
		case 2:
			registro_clientes();
			break;
			
		case 3:
			registro_ventas();
			break;
			
			
		case 4:		
			menuAdicional();
			break;
									
		case 5:
			cout << "\nSaliendo del programa..." << endl << endl;
			exit(1);
			break;				
	}
	
	
}

int menu(){
	
	int opcion;
	
	cout << "Bienvenido al sistema de gestión de inventario" << endl;
	cout << "------------------------------------------------" << endl;
	cout << "\n1.- Registrar nuevos productos" << endl;
	cout << "2.- Registrar nuevos clientes" << endl;
	cout << "3.- Registro de ventas" << endl;
	cout << "4.- Información adicional" << endl;
	cout << "5.- Salir" << endl;
	cout << "Opción: ";
	cin >> opcion;
	
	return opcion;
}

int menuAdicional(){
				
			int option;
								
			do{			
			system("CLS");
			cout << "Información adicional" << endl;
			cout << "---------------------" << endl;
			cout << "\n1.- Relación de clientes" << endl;
			cout << "2.- Relación de productos" << endl;
			cout << "3.- Relación de ventas por año y mes" << endl;
			cout << "4.- Número de ventas realizadas a un cliente específico" << endl;
			cout << "5.- Detalles de ventas diaras" << endl;
			cout << "6.- Volver al menú principal" << endl;	
			cout << "7.- Salir" << endl;	
			cout << "Opción: ";
			cin >> option;
			
			}while((option < 1) || (option > 7));
			
			switch (option){
				
				case 1:
					relacion_clientes();
					break;
					
				case 2:
					relacion_productos();
					break;
					
				case 3:
					ventas_mes_anio();
					break;
					
				case 4:
					cliente_especifico();
					break;
					
				case 5:
					ventas_diaras();
					break;
					
				case 6:
					main();
					break;
					
				case 7:
					cout << "\n\nSaliendo del programa..." << endl << endl;
					exit(1);
					break;				
			}
			
			return option;
}

void registro_producto(){
	system("CLS");
	
	//Variables 
	string codigo, descripcion;
	float precio;
	char rpt;
	int opcion;
		
	//Fichero
	ofstream productos;
	
	//Abriendo
	productos.open("productos.txt", ios::app);
	
	//Ejecución
	if(productos.is_open()){
		
		cout << "Bienvenido al sistema de registro de productos" << endl;
		cout << "----------------------------------------------" << endl;
		
		do{
			
			fflush(stdin);
			cout <<"\n*Código: ";
			cin >> codigo;
				
			if(validar_producto(codigo)){
				cout << "\n****************************************" << endl;
				cout << "El producto ya se encuentra registrado" << endl;
				cout << "Regresando al menú principal..." << endl << endl;
				system("pause");
				main();		
			}
			
			else{
				
			
			cout <<"*Precio: ";
			cin >> precio;
			
			fflush(stdin);
			cout << "*Descripción:";
			getline(cin, descripcion);
			
			//Impresion de datos en el fichero
			productos << codigo << " " << precio << " " << descripcion << " "<< endl;									
					
			cout << "Desea registrar otro producto?(S/N): ";
			cin >> rpt;					
			cout << endl;
			}
			
		}while((rpt == 's') || (rpt =='S'));
		
		//Cerramos el archivo
		productos.close();
		
		do{
		cout << endl;
		cout << "******************************" << endl;
		cout << "Sistema de registro completado" << endl << endl;	
		cout << "1.- Volver al menú Principal" << endl; 
		cout << "2.- Salir de la aplicación" << endl;	
		cout << "Opción: ";
		cin >> opcion;
		}while((opcion < 1) || (opcion > 2));
		
		switch(opcion){
			case 1:
				main();
				break;
			case 2:
				cout << "\n\n";
				cout << "Saliendo del sistema..." << endl;				
				exit(1);
		}	
	}
	
	else{		
		cout << "\n¡Archivo no encontrado!" << endl;
		cout << "Regresando al menú principal" << endl << endl;		
		
		system("pause");
		
		//Llamamos la funcion principal		
		main();
	}
	
}

void registro_clientes(){

	system("CLS");
	
	//Variables 
	string ruc, nombre;
	char rpt;
	int opcion;
		
	//Fichero
	ofstream clientes;
	
	//Abriendo
	clientes.open("clientes.txt", ios::app);
	
	//Ejecución
	if(clientes.is_open()){
		
		cout << "Bienvenido al sistema de registro de clientes" << endl;
		cout << "----------------------------------------------" << endl;
		
		do{
			
			cout <<"\n*RUC del cliente: ";
			cin >> ruc;                          
										        
			if(validar_cliente(ruc)){
				cout << endl;
				cout << "****************************************" << endl;
				cout << "El cliente ya se encuentra registrado" << endl;
				cout << "Regresando al menú principal..." << endl << endl;
				system("pause");
				main();		
			}
			
			else{
				
				fflush(stdin);
					
				cout << "*Apellidos y nombre(s): ";
				getline(cin, nombre);
					
				//Impresion de datos en el fichero
				clientes << ruc << " " << nombre << endl;									
						
				cout << "Desea registrar otro cliente?(S/N): ";
				cin >> rpt;					
				cout << endl;
				
			}
			
		}while((rpt == 's') || (rpt =='S'));
		
		//Cerramos el archivo
		clientes.close();
		
		do{
			
			cout << endl;
			cout << "******************************" << endl;
			cout << "Sistema de registro completado" << endl << endl;	
			cout << "1.- Volver al menú Principal" << endl; 
			cout << "2.- Salir de la aplicación" << endl;	
			cout << "Opción: ";
			cin >> opcion;
			}while((opcion < 1) || (opcion > 2));
			
			switch(opcion){
				case 1:
					main();
					break;
				case 2:
					cout << "\n\n";
					cout << "Saliendo del sistema..." << endl;				
					exit(1);
			}
			
	}
	
	else{		
		cout << "\n\n¡Archivo no encontrado!" << endl;
		cout << "Regresando al menú principal" << endl << endl;		
		
		system("pause");
		
		//Llamamos la funcion principal		
		main();
	}
	

}

void registro_ventas(){
	system("CLS");
	
	//Variables
	string nombre, ruc, codigo, producto;
	short int dia, mes, anio;
	char rpt, respuesta;
	int cantidad, opcion, contador=0;
	float precio;
	float total = 1;
	
	//Fichero
	ofstream ventas;
	
	//Abriendo
	ventas.open("ventas.txt" , ios::app);
	
	//Ejecución
	if(ventas.is_open()){
		
		cout << "Bienvenido al sistema de registro de ventas" << endl;
		cout << "-------------------------------------------" << endl << endl;
		
		do{
					
			fflush(stdin);			
			cout <<"*RUC: ";
			cin >> ruc;
			
			cout << endl;
			cout << "******************************************" << endl;
			cout << "Verificando cliente en la base de datos..." << endl << endl;
			system("pause");
			
			//Comprobación de cliente existente en la BD
			if(validar_cliente(ruc)){
				
				system("CLS");
								
				cout << "Cliente verificado" << endl;
				cout << "------------------" << endl << endl;
				
				cout << "*RUC: " << ruc << endl;				
				cout << "*Cliente:" << retornar_nombre_cliente(ruc) << endl;
				cout << endl << endl;
				
				cout << "Registre fecha de venta"<< endl;
				cout << "-----------------------" << endl;
				
				
				do{
					cout << "\n*Día: ";
					cin >> dia;	
					
				}while((dia < 1) || (dia > 31));
				
				do{
					cout << "*Mes(1-12): ";
					cin >> mes;	
				}while((mes < 1) || (mes > 12));
								
					cout << "*Año: ";
					cin >> anio;					
				
				do{
										
					cout << "*Digite el código del producto: ";
					cin >> codigo;
					
					cout << "\n\n********************************************************" << endl;
				 	cout << "verificando si existe el producto en la base de datos..." << endl << endl;
					system("pause");
					
					if(validar_producto(codigo)){
						
						system("cls");
						cout << "\nProducto verificado"<< endl;
						cout << "---------------------" << endl << endl;
						cout << "*N# Código:" << codigo << endl;
						
						producto = retornar_nombre(codigo);
						precio = retornar_precio(codigo);
						
						cout << "*Producto:" << producto << endl;
						cout << "*Precio por unidad (S/.): " << precio << endl;
																	
						cout << "*¿Cuántas unidades desea adquirir?: ";
						cin >> cantidad;
																	
						total = precio * cantidad;
						
						contador++;
						
						//Impresion en fichero
						ventas << ruc << " " << dia << " " << mes << " " << anio << " " << codigo << " " << cantidad << " " << precio << " " << total << " " << contador<< endl;
						
						cout <<"\n***************************" << endl;						
						cout << "Total: " << total << endl;
						
					}
					
					else{
							
						cout << "\n****************************************" << endl;
						cout << "Este producto no se encuentra registrado" << endl;
						cout << "Regresando al menú principal..." << endl << endl;
						system("pause");
						main();	
					
					}
					
					cout << endl;
					cout << "¿Desea facturar otro producto?(S/N): ";
					cin >> respuesta;					
					cout << endl;
																
				}while((respuesta == 's') || (respuesta == 'S'));
			}
			
			else{		
				system("cls");
				cout << "*************************************" << endl;
				cout << "El cliente no se encuentra registrado" << endl;
				cout << "Redireccionando al menú principal..." << endl << endl;
				system("pause");
				main();
				
			}
			
			cout << endl ;
			cout << "**********************************************" << endl;
			cout << "¿Desea registrar compra de otro cliente?(S/N): ";
			cin >> rpt;					
			cout << endl;
									
		}while((rpt == 's') || (rpt =='S'));
		
	//Cerramos el fichero
	ventas.close();
	
		do{
			cout << "\n\n******************************" << endl;
			cout << "Sistema de registro completado" << endl << endl;	
			cout << "1.- Volver al menú Principal" << endl; 
			cout << "2.- Salir de la aplicación" << endl;	
			cout << "Opción: ";
			cin >> opcion;
			}while((opcion < 1) || (opcion > 2));
		
		switch(opcion){
			case 1:
				main();
				break;
			case 2:
				cout << "\n\n";
				cout << "Saliendo del sistema..." << endl;				
				exit(1);
		}	
	}	
	else{
		
		cout << "\n\n¡Archivo no encontrado!" << endl;
		cout << "Regresando al menú principal..." << endl << endl;		
		
		system("pause");
		//Llamamos la funcion principal	
		main();	
	}
	
	
}

void relacion_clientes(){
	system("CLS");
	//Variables
	string ruc, nombre;
	int opcion;
	
	//Fichero
	ifstream clientes;
	
	//Abriendo
	clientes.open("clientes.txt", ios::in);
	
	//Ejecución
	if(clientes.is_open()){	
				
		cout << "Listado de clientes registrados" << endl;
		cout << "-------------------------------" << endl;
				
			while(!clientes.eof()){
			
				clientes >> ruc;
				getline(clientes, nombre);
			
				if(clientes.eof()){
					break;
				}
				
				if(validar_cliente(ruc)){
					cout << endl;
					cout << "*Datos:" << nombre << endl;
					cout << "*RUC:" <<  ruc << endl;					
				}
			}
		
		do{
			cout << "\n\n******************************" << endl;
			cout << "Sistema de búsqueda completada" << endl << endl;	
			cout << "1.- Volver al menú adicional" << endl; 
			cout << "2.- Salir de la aplicación" << endl;	
			cout << "Opcion: ";
			cin >> opcion;
			}while((opcion < 1) || (opcion > 2));
			
			switch(opcion){
				case 1:
					menuAdicional();
					break;
				case 2:
					cout << "\n\n";
					cout << "Saliendo del sistema..." << endl;				
					exit(1);
			}	
	}
	
	else{
		
		cout << "\n\n¡Archivo no encontrado!" << endl;
		cout << "Regresando al menú adicional" << endl << endl;		
		
		system("pause");
		//Llamamos la funcion menuadicional()
		menuAdicional();	
	}
	
	//Cerramos el fichero
	clientes.close();
}

void relacion_productos(){
	
	system("cls");
	//Variables
	string codigo,descripcion, clave;
	float precio;
	int opcion;
	
	//Fichero
	ifstream productos;
	   
	//Abriendo              
	productos.open("productos.txt", ios::in);
	
	//Ejecución
	if(productos.is_open()){
		
		cout << "Listado de productos registrados" << endl;
		cout << "--------------------------------" << endl;	
		
			while(!productos.eof()){
			
				productos >> codigo;
				productos >> precio;
				getline(productos, descripcion);
			
				if(productos.eof()){
					break;
				}
			
				if(validar_producto(codigo)){
					cout << endl;
					cout << "*#CÓDIGO: " << codigo << endl;
					cout << "*NOMBRE:" << descripcion << endl;
					cout << "*PRECIO POR UNIDAD(S/.): " << precio << endl;					
				}
			}
			
		do{
			cout << "\n\n******************************" << endl;
			cout << "Sistema de busqueda completada" << endl << endl;		
			cout << "1.- Volver al menú adicional" << endl; 
			cout << "2.- Salir de la aplicación" << endl;	
			cout << "Opción: ";
			cin >> opcion;
		}while((opcion < 1) || (opcion > 2));
			
			switch(opcion){
				case 1:
					menuAdicional();
					break;
				case 2:
					cout << endl;
					cout << "\n\n";
					cout << "Saliendo del sistema..." << endl;				
					exit(1);
			}	
	}
	
	else{
		cout << "\n\n¡Archivo no encontrado!" << endl;
		cout << "Regresando al menú adicional" << endl << endl;		
		
		system("pause");
		//Llamamos la funcion principal	
		menuAdicional();	
	}
	
	//Cerramos el fichero
	productos.close();
}

void cliente_especifico(){
	
	system("CLS");	
	
	//Variables
	string ruc;
	
	cout << "Ingrese #RUC para buscar cliente: ";
	cin >> ruc;
	
	cout << "\n\n************************************" << endl;
	cout << "Verificando #RUC en la base de datos" << endl << endl;	
	system("pause");
	
	if(validar_cliente(ruc)){
		datos_cliente(ruc);
	}
	
	else{
		
		cout << endl << endl;
		cout << "**********************" << endl;
		cout << "¡Cliente no encontrado!" << endl;
		cout << "Regresando al menú adicional" << endl << endl;		
		
		system("pause");
		
		//Llamamos la funcion principal		
		menuAdicional();		
		
	}
}

void ventas_diaras(){
	system("CLS");	
	
	//Variables
	short int dia;
	
	cout << "Reporte diario de ventas" << endl;
	cout << "------------------------" << endl;
	
	do{
		cout << "Ingrese N# Dia: ";
		cin >> dia;
		
	}while((dia < 1) || (dia > 31));
	
	cout << "\n\n************************************" << endl;
	cout << "Recolectando datos..." << endl << endl;	
	system("pause");	
	reporte_dia(dia);
}

void ventas_mes_anio(){
	system("CLS");	
	
	//Variables
	short int mes, anio;
	
	do{
		
		system("cls");
		cout << "Reporte de ventas por mes y año" << endl;
		cout << "--------------------------------" << endl;
		cout << "Ingrese #Mes: ";
		cin >> mes; 		
		
	}while((mes < 1) || (mes > 12));
	
	cout << "Ingrese #Año: ";
	cin >> anio;
			
	cout << "\n\n************************************" << endl;
	cout << "Recolectando datos..." << endl << endl;	
	system("pause");
	reporte_mes_anio(mes, anio);
}

void datos_cliente(string cadena){
	
	system("CLS");
	
	//Variables producto
	string ruc, codigo, nombre, clave,rucSolo ;
	char rpt;	
	short int dia, mes, anio;
	int cantidad, opcion, contador=0, venta_numero;
	float precio;
	float total = 0, totalUnico;
	
	clave = cadena;
	
	//Fichero
	ifstream ventas;
	
	//Abriendo
	ventas.open("ventas.txt" , ios::in);
	
	//Ejecución
	if(ventas.is_open()){
		
		cout << "#RUC encontrado en la base de datos:" << endl;
		cout << "------------------------------------" << endl;
			
				totalUnico = 0;
				while(!ventas.eof()){
					
					ventas >> ruc;
					ventas >> dia;
					ventas >> mes;
					ventas >> anio;
					ventas >> codigo;
					ventas >> cantidad;
					ventas >> precio;
					ventas >> total;
					ventas >> contador;
					
					if(ventas.eof()){	
						break;				
					}
					
					if(ruc == clave){								
						nombre = retornar_nombre_cliente(ruc);						
						rucSolo = ruc;
						venta_numero = contador;
						totalUnico = total + totalUnico;
						contador++;
						
					}
							
				}					
				
	//Cerramos el fichero
	ventas.close();	
	cout << endl;
	cout << "*N# RUC: " << rucSolo << endl;
	cout << "*N# de Ventas: " << venta_numero << endl;		
	cout << "*Datos:" << nombre << endl;	
	cout << "*Total: " << totalUnico << endl;
	
		do{
			
			cout << "\n\n******************************" << endl;
			cout << "Sistema de búsqueda completada" << endl << endl;	
			cout << "1.- Volver al menú adicional" << endl; 
			cout << "2.- Salir de la aplicación" << endl;	
			cout << "Opcion: ";
			cin >> opcion;
			
		}while((opcion < 1) || (opcion > 2));
		
		switch(opcion){
			case 1:
				menuAdicional();
				break;
			case 2:
				cout << "\n\n";
				cout << "Saliendo del sistema..." << endl;				
				exit(1);
		}	
	}	
	
	else{
		
		cout << "\n\n¡Archivo no encontrado!" << endl;
		cout << "Regresando al menú adicional..." << endl << endl;		
		
		system("pause");
		//Llamamos la funcion principal	
		menuAdicional();	
	}

}

void reporte_dia(int day){

	//Variables producto
	string ruc, codigo, nombre, clave;
	short int dia, mes, anio;
	int cantidad, opcion, contador=1, unico;
	float precio;
	float total = 1;	
	unico = day;
	
	//Fichero
	ifstream ventas;
	
	//Abriendo
	ventas.open("ventas.txt" , ios::in);
	
	//Ejecución
	if(ventas.is_open()){
		
		system("cls");
		cout << "Reporte de venta" << endl;
		cout << "****************" << endl;
		
		while(!ventas.eof()){
			ventas >> ruc;
			ventas >> dia;
			ventas >> mes;
			ventas >> anio;
			ventas >> codigo;
			ventas >> cantidad;
			ventas >> precio;
			ventas >> total;
			ventas >> contador;
			
			if(ventas.eof()){	
				break;				
			}
			
			if(unico == dia){		
												
					cout << endl;
					cout << "*N# Mes: " << mes << endl;
					cout << "*N# Año: " << anio << endl;					
					cout << "*Producto:" << retornar_nombre(codigo) << endl;
					cout << "*N# Código: " << codigo << endl;
					cout << "*N# Cantidad: " << cantidad << endl;
					cout << "*Cliente:" << retornar_nombre_cliente(ruc) << endl;
					cout << "*Monto(S/.): " << total << endl;
					
					break;
			}
			
			else{
				cout << endl << endl;				
				cout << "¡No se encontraron registro de ventas en este dia!" << endl;
				cout << "Regresando al menú adicional..." << endl << endl << endl;
				system("pause");
				menuAdicional();
				
			}					
					
		}
				
		//Cerramos el fichero
		ventas.close();	
		
		cout << endl;
		system("pause");
		cout << endl << endl << endl;
		
			do{			
				cout << "*******************************" << endl;
				cout << "Sistema de búsqueda  completada" << endl << endl;	
				cout << "1.- Volver al menú adicional" << endl; 
				cout << "2.- Salir de la aplicación" << endl;	
				cout << "Opción: ";
				cin >> opcion;
				
			}while((opcion < 1) || (opcion > 2));
			
			switch(opcion){
				
				case 1:
					menuAdicional();
					break;
					
				case 2:
					cout << "\n\n";
					cout << "Saliendo del sistema..." << endl << endl;
					system("pause");								
					exit(1);
			}	
	}	
	
	else{
		
		cout << "\n\n¡Archivo no encontrado!" << endl;
		cout << "Regresando al menú adicional..." << endl << endl;				
		system("pause");
		//Llamamos la funcion menuAdicional	
		menuAdicional();	
	}
}

void reporte_mes_anio(int menor, int mayor){
	
	//Variables producto
	string ruc, codigo, nombre, clave;
	short int dia, mes, anio, meses, anios;
	int cantidad, opcion, contador=0, unico;
	float precio;
	float total = 1;	
	meses = menor;
	anios = mayor;
	
	//Fichero
	ifstream ventas;
	
	//Abriendo
	ventas.open("ventas.txt" , ios::in);
	
	//Ejecución
	if(ventas.is_open()){
		
		system("cls");
		cout << "Reporte de venta" << endl;
		cout << "****************" << endl;
		
		while(!ventas.eof()){
			ventas >> ruc;
			ventas >> dia;
			ventas >> mes;
			ventas >> anio;
			ventas >> codigo;
			ventas >> cantidad;
			ventas >> precio;
			ventas >> total;
			ventas >> contador;
			
			if(ventas.eof()){	
				break;				
			}
																
			else if((mes == meses)){			
			
				if(anio == anios){
					cout << endl;
					cout << "*N#Día: " << dia << endl;
					cout << "*N# Código: " << codigo << endl;
					cout << "*Producto:" << retornar_nombre(codigo) << endl;
					cout << "*Cantidad(Unidad): " << cantidad << endl;
					cout << "*Cliente:" << retornar_nombre_cliente(ruc) << endl;
					cout << "*Monto(S/.): " << total << endl;					
				}							
			}
			
			else{
				
				cout << endl;				
				cout << "¡No se encontraron registro de ventas en este dia!" << endl;
				cout << "Regresando al menú adicional..." << endl << endl << endl;
				system("pause");
				menuAdicional();
				
			}							
		}
				
	//Cerramos el fichero
	ventas.close();	
	
	cout << endl;
	system("pause");
	cout << endl << endl << endl;
	
		do{			
			cout << "*******************************" << endl;
			cout << "Sistema de búsqueda  completada" << endl << endl;	
			cout << "1.- Volver al menú adicional" << endl; 
			cout << "2.- Salir de la aplicación" << endl;	
			cout << "Opción: ";
			cin >> opcion;
			
		}while((opcion < 1) || (opcion > 2));
		
		switch(opcion){
			
			case 1:
				menuAdicional();
				break;
				
			case 2:
				cout << "\n\n";
				cout << "Saliendo del sistema..." << endl << endl;		
				system("pause");
				exit(1);
		}	
	}	
	
	else{
		
		cout << "\n\n¡Archivo no encontrado!" << endl;
		cout << "Regresando al menú adicional..." << endl << endl;				
		system("pause");
		//Llamamos la funcion menuAdicional	
		menuAdicional();	
	}
}

bool validar_producto(string cadena){
	//Variables
	string codigo,descripcion, clave;
	float precio;
	bool validar = false;		
	clave = cadena;
	
	//Fichero
	ifstream productos;
	   
	//Abriendo              
	productos.open("productos.txt", ios::in);
	
	//Ejecución
	if(productos.is_open()){		
		while(!productos.eof()){
			
			productos >> codigo;
			productos >> precio;
			getline(productos, descripcion);
			
			if(productos.eof()){
				break;
			}
			
			if(codigo == clave){
				validar = true;
				break;
			}
		}
	}
	
	else{
		cout << "\n\n¡Archivo no encontrado!" << endl;
		cout << "Regresando al menú principal" << endl << endl;		
		
		system("pause");
		//Llamamos la funcion principal	
		main();	
	}
	
	//Cerramos el fichero
	productos.close();
	return validar;

}

bool validar_cliente(string cadena){
	//Variables
	string ruc, nombre, clave;
	bool validar = false;		
	clave = cadena;
	
	//Fichero
	ifstream clientes;
	
	//Abriendo
	clientes.open("clientes.txt", ios::in);
	
	//Ejecución
	if(clientes.is_open()){		
		while(!clientes.eof()){
			
			clientes >> ruc;
			getline(clientes, nombre);
			
			if(clientes.eof()){
				break;
			}
			
			if(ruc == clave){
				validar = true;
				break;
			}
		}
	}
	
	else{
		
		cout << "\n\n¡Archivo no encontrado!" << endl;
		cout << "Regresando al menú principal" << endl << endl;		
		
		system("pause");
		//Llamamos la funcion principal	
		main();	
	}
	
	//Cerramos el fichero
	clientes.close();
	return validar;

}

float retornar_precio(string cadena){
	//Variables
	string codigo,descripcion, clave;
	float precio, monto;	
	clave = cadena;
	
	//Fichero
	ifstream productos;
	   
	//Abriendo              
	productos.open("productos.txt", ios::in);
	
	//Ejecución
	if(productos.is_open()){		
		while(!productos.eof()){
			
			productos >> codigo;
			productos >> precio;
			getline(productos, descripcion);
			
			if(productos.eof()){
				break;
			}
			
			if(codigo == clave){
				monto = precio;
				break;
			}
		}
	}
	
	else{
		cout << "\n\n¡Archivo no encontrado!" << endl;
		cout << "Regresando al menú principal" << endl << endl;		
		
		system("pause");
		
		//Llamamos la funcion principal	
		main();	
	}
	
	//Cerramos el fichero
	productos.close();
	return monto;

}

string retornar_nombre_cliente(string cadena){
	//Variables
	string ruc, nombre, clave;
	string validar = "¡NO ENCONTRADO!";		
	clave = cadena;
	
	//Fichero
	ifstream clientes;
	
	//Abriendo
	clientes.open("clientes.txt", ios::in);
	
	//Ejecución
	if(clientes.is_open()){		
		while(!clientes.eof()){
			
			clientes >> ruc;
			getline(clientes, nombre);
			
			if(clientes.eof()){
				break;
			}
			
			if(ruc == clave){
				validar = nombre;
				break;
			}
		}
	}
	
	else{
		
		cout << "\n\n¡Archivo no encontrado!" << endl;
		cout << "Regresando al menú principal" << endl << endl;		
		
		system("pause");
		//Llamamos la funcion principal	
		main();	
	}
	
	//Cerramos el fichero
	clientes.close();
	return validar;
}

string retornar_nombre(string cadena){
	
	//Variables
	string codigo,descripcion, clave;
	float precio;
	string validar = "¡NO ENCONTRADO!";		
	clave = cadena;
	
	//Fichero
	ifstream productos;
	   
	//Abriendo              
	productos.open("productos.txt", ios::in);
	
	//Ejecución
	if(productos.is_open()){		
		while(!productos.eof()){
			
			productos >> codigo;
			productos >> precio;
			getline(productos, descripcion);
			
			if(productos.eof()){
				break;
			}
			
			if(codigo == clave){
				validar = descripcion;
				break;
			}
		}
	}
	
	else{
		cout << "\n\n¡Archivo no encontrado!" << endl;
		cout << "Regresando al menú principal" << endl << endl;		
		
		system("pause");
		//Llamamos la funcion principal	
		main();	
	}
	
	//Cerramos el fichero
	productos.close();
	return validar;

}	


