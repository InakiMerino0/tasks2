#include <iostream>
#include <sstream>
#include <fstream>
#include <string>

using namespace std;

class Employes {
private:
	string name = "";
	float salary = 0;
	
public:
	void enterName(string auxName) {
		name = auxName;
	}
	void enterSalary(float auxSalary) {
		salary = auxSalary;
	}

	string getName() {
		return name;
	}

	float getSalary() {
		return salary;
	}
};

int main() {

	Employes employes[5];
	string auxName = "";
	float auxSalary = 0;

	//crea el archivo archivo.txt, referenciado con el objeto archivoEntrada, al ser ofstream permite la entrada de datos
	fstream binaryStream("file.dat", ios::binary | ios::in | ios::out | ios::app);
	if (binaryStream.is_open()) {

		for (int i = 0; i < 5; i++) {
			cout << "Ingrese nombre del empleado numero: " << (i + 1);
			cin >> auxName;
			cout << "Ingrese sueldo del empleado numero: " << (i + 1);
			cin >> auxSalary;
			employes[i].enterName(auxName);
			employes[i].enterSalary(auxSalary);

			seekp(0, ios::end);
			binaryStream.write(employes[i]); //Como escribo una instancia en un archivo de texto
		}
		
		binaryStream.close();
	}

	//if stream permite la lectura de archivo.txt, archivoSalida es el objeto por el que se lo referencia
	ifstream outputFile("archivo.txt");
	if (outputFile.is_open()) {
		int i = 0;
		while (i < 5) {

			//Como leo un objeto de un archivo de texto

			i++;
		}
	}
}