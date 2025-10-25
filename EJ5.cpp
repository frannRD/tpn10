#include <iostream>
#include <vector>
#include <string>
using namespace std;

class Empleado {
private:
    string nombre, departamento;
    float salario;

public:
    void cargarDatos() {
        cout << "Nombre: ";
        getline(cin, nombre);
        cout << "Departamento: ";
        getline(cin, departamento);
        cout << "Salario: ";
        cin >> salario;
        cin.ignore();
    }

    float getSalario() {
        return salario;
    }

    void mostrarDatos() {
        cout << nombre << " | " << departamento << " | $" << salario << endl;
    }
};

int main() {
    vector<Empleado> empleados;
    int n;
    cout << "Cantidad de empleados: ";
    cin >> n;
    cin.ignore();

    for (int i = 0; i < n; i++) {
        Empleado e;
        cout << "\n--- Empleado " << i + 1 << " ---" << endl;
        e.cargarDatos();
        empleados.push_back(e);
    }

    // Ordenar de mayor a menor salario
    for (int i = 0; i < empleados.size() - 1; i++) {
        for (int j = i + 1; j < empleados.size(); j++) {
            if (empleados[i].getSalario() < empleados[j].getSalario()) {
                Empleado temp = empleados[i];
                empleados[i] = empleados[j];
                empleados[j] = temp;
            }
        }
    }

    cout << "\n=== Empleados ordenados por salario (mayor a menor) ===" << endl;
    for (int i = 0; i < empleados.size(); i++) {
        empleados[i].mostrarDatos();
    }

    return 0;
}
