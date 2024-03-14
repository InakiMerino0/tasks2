#include <iostream>
#include <sstream>
#include <fstream>
#include <string>

using namespace std;

class Employees {
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

	int getSalary() {
		return salary;
	}
};

int main() {
	
	Employees employee;
	string employeeName = "";
	float employeeSalary = 0;

	//crea el archivo archivo.txt, referenciado con el objeto archivoEntrada, al ser ofstream permite la entrada de datos
	fstream binaryStream("file.dat", ios::binary | ios::in | ios::out | ios::app);
	binaryStream.seekp(0, ios::end);
	if (binaryStream.is_open()) {

		cout << "Ingrese nombre del empleado" << endl;
		cin >> employeeName;
		cout << "Ingrese sueldo del empleado" << endl;
		cin >> employeeSalary;
		employee.enterName(employeeName);
		employee.enterSalary(employeeSalary);

		binaryStream.write(reinterpret_cast<char*>(&employee), sizeof(employee));
	}

	employee.getSalary();

	int i = 0;
	int masTres = 0;
	int masDos = 0;	
	int masUno = 0;
	binaryStream.seekg(0, ios::beg);
	int salary = 0;
	while (binaryStream.read(reinterpret_cast<char*>(&employee), sizeof(employee))) {
		salary = employee.getSalary();
		if (salary > 3000) {
			masTres++;
		}
		else if (employee.getSalary() > 2000){
			masDos++;
		}
		else if (employee.getSalary() > 999) {
			masUno++;
		}
	}

	cout << "Hay " << masTres << " empleados con un sueldo mayor a 3000" << endl;
	cout << "Hay " << masDos << " empleados con un sueldo mayor a 2000" << endl;
	cout << "Hay " << masUno << " empleados con un sueldo mayor a 1000" << endl;

	binaryStream.close();
}