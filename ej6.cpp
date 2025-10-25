#include <iostream>
#include <vector>
#include <string>
using namespace std;

class Libro {
private:
    string titulo, autor;
    int anioPublicacion;

public:
    void cargarDatos() {
        cout << "Titulo: ";
        getline(cin, titulo);
        cout << "Autor: ";
        getline(cin, autor);
        cout << "Anio de publicacion: ";
        cin >> anioPublicacion;
        cin.ignore();
    }

    int getAnio() {
        return anioPublicacion;
    }

    void mostrarDatos() {
        cout << anioPublicacion << " - " << titulo
             << " (Autor: " << autor << ")" << endl;
    }
};

int main() {
    vector<Libro> libros;
    int n;
    cout << "Cantidad de libros: ";
    cin >> n;
    cin.ignore();

    for (int i = 0; i < n; i++) {
        Libro l;
        cout << "\n--- Libro " << i + 1 << " ---" << endl;
        l.cargarDatos();
        libros.push_back(l);
    }

   
    for (int i = 0; i < libros.size() - 1; i++) {
        for (int j = i + 1; j < libros.size(); j++) {
            if (libros[i].getAnio() > libros[j].getAnio()) {
                Libro temp = libros[i];
                libros[i] = libros[j];
                libros[j] = temp;
            }
        }
    }

    cout << "\n=== Libros ordenados por año (antiguo a reciente) ===" << endl;
    for (int i = 0; i < libros.size(); i++) {
        libros[i].mostrarDatos();
    }

    return 0;
}
