#include <iostream>
#include <vector>
#include <string>
using namespace std;

class Alumno {
private:
    string nombre;
    float nota1, nota2, nota3;

public:
    void cargarDatos() {
        cout << "Nombre del alumno: ";
        getline(cin, nombre);
        cout << "Nota 1: "; cin >> nota1;
        cout << "Nota 2: "; cin >> nota2;
        cout << "Nota 3: "; cin >> nota3;
        cin.ignore(); // limpiar buffer
    }

    void mostrarDatos() {
        cout << "\nAlumno: " << nombre << endl;
        cout << "Notas: " << nota1 << ", " << nota2 << ", " << nota3 << endl;
    }
};

int main() {
    vector<Alumno> alumnos;
    int cantidad;

    cout << "Ingrese la cantidad de alumnos: ";
    cin >> cantidad;
    cin.ignore();

    for (int i = 0; i < cantidad; i++) {
        Alumno a;
        cout << "\n--- Alumno " << i + 1 << " ---" << endl;
        a.cargarDatos();
        alumnos.push_back(a);
    }

    cout << "\n=== Datos de los alumnos ===" << endl;
    for (Alumno &a : alumnos)
        a.mostrarDatos();

    return 0;
}
