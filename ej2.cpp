#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
using namespace std;

class Persona {
private:
    string nombre;
    int edad;

public:
    void cargarDatos() {
        cout << "Nombre: ";
        getline(cin, nombre);
        cout << "Edad: ";
        cin >> edad;
        cin.ignore();
    }

    int getEdad() const { return edad; }

    void mostrarDatos() const {
        cout << nombre << " - " << edad << " años" << endl;
    }
};

int main() {
    vector<Persona> personas;
    int n;

    cout << "Cantidad de personas: ";
    cin >> n;
    cin.ignore();

    for (int i = 0; i < n; i++) {
        Persona p;
        cout << "\n--- Persona " << i + 1 << " ---" << endl;
        p.cargarDatos();
        personas.push_back(p);
    }

    sort(personas.begin(), personas.end(),
         [](const Persona &a, const Persona &b) { return a.getEdad() < b.getEdad(); });

    cout << "\n=== Personas ordenadas por edad ===" << endl;
    for (const Persona &p : personas)
        p.mostrarDatos();

    return 0;
}
