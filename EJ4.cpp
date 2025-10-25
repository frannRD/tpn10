#include <iostream>
#include <vector>
#include <string>
using namespace std;

class CuentaBancaria {
private:
    int numeroCuenta;
    string titular;
    float saldo;

public:
    void cargarDatos() {
        cout << "Numero de cuenta: ";
        cin >> numeroCuenta;
        cin.ignore();
        cout << "Nombre del titular: ";
        getline(cin, titular);
        cout << "Saldo inicial: ";
        cin >> saldo;
        cin.ignore();
    }

    void depositar(float monto) {
        saldo += monto;
    }

    void retirar(float monto) {
        if (monto <= saldo) {
            saldo -= monto;
        } else {
            cout << "Fondos insuficientes.\n";
        }
    }

    int getNumeroCuenta() {
        return numeroCuenta;
    }

    void mostrarDatos() {
        cout << "Cuenta N° " << numeroCuenta
             << " | Titular: " << titular
             << " | Saldo: $" << saldo << endl;
    }
};

int main() {
    vector<CuentaBancaria> cuentas;
    int n;
    cout << "Cantidad de cuentas: ";
    cin >> n;
    cin.ignore();

    for (int i = 0; i < n; i++) {
        CuentaBancaria c;
        cout << "\n--- Cuenta " << i + 1 << " ---" << endl;
        c.cargarDatos();
        cuentas.push_back(c);
    }

    cout << "\n=== Cuentas Bancarias ===" << endl;
    for (int i = 0; i < cuentas.size(); i++) {
        cuentas[i].mostrarDatos();
    }

    int cuentaBuscada;
    cout << "\nIngrese el numero de cuenta para operar: ";
    cin >> cuentaBuscada;

    for (int i = 0; i < cuentas.size(); i++) {
        if (cuentas[i].getNumeroCuenta() == cuentaBuscada) {
            int opcion;
            float monto;
            cout << "1. Depositar\n2. Retirar\nOpcion: ";
            cin >> opcion;
            cout << "Monto: ";
            cin >> monto;

            if (opcion == 1) {
                cuentas[i].depositar(monto);
            } else if (opcion == 2) {
                cuentas[i].retirar(monto);
            }
        }
    }

    cout << "\n=== Estado final de las cuentas ===" << endl;
    for (int i = 0; i < cuentas.size(); i++) {
        cuentas[i].mostrarDatos();
    }

    return 0;
}
