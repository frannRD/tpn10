#include <iostream>
#include <vector>
using namespace std;

class Rectangulo {
private:
    float base, altura;

public:
    void cargarDatos() {
        cout << "Base: ";
        cin >> base;
        cout << "Altura: ";
        cin >> altura;
    }

    float area() const { return base * altura; }
    float perimetro() const { return 2 * (base + altura); }

    void mostrarDatos() const {
        cout << "Base: " << base << " | Altura: " << altura
             << " | Area: " << area()
             << " | Perimetro: " << perimetro() << endl;
    }
};

int main() {
    vector<Rectangulo> rectangulos;
    int n;
    cout << "Cantidad de rectangulos: ";
    cin >> n;

    for (int i = 0; i < n; i++) {
        Rectangulo r;
        cout << "\n--- Rectangulo " << i + 1 << " ---" << endl;
        r.cargarDatos();
        rectangulos.push_back(r);
    }

    cout << "\n=== Resultados ===" << endl;
    for (const Rectangulo &r : rectangulos)
        r.mostrarDatos();

    return 0;
}
