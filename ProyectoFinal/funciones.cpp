#include "iostream"
#include <iomanip>
#include "funciones.h"
using namespace std;

void mostrarMenu() {
    cout << "\n===== TIENDA DE VIDEOJUEGOS DIGITAL BLM =====\n";
    cout << "1. Ver catalogo\n";
    cout << "2. Agregar al carrito\n";
    cout << "3. Calcular total\n";
    cout << "4. Modificar carrito\n";
    cout << "5. Vaciar carrito\n";
    cout << "6. Confirmar compra\n";
    cout << "7. Salir\n";
    cout << "Seleccione una opcion: ";
}

//===================================================================================================================

void verCatalogo() {
    cout << "\n===== CATALOGO DE VIDEOJUEGOS =====\n";
    cout << left << setw(5) << "ID" << setw(30) << "Juego"
         << setw(12) << "Precio" << setw(10) << "Stock" << endl;

    for (int i = 0; i < MAX_JUEGOS; i++) {
        cout << left << setw(5) << (i + 1) << setw(30) << juegos[i]
             << "$" << setw(11) << fixed << setprecision(2) << precios[i]
             << setw(10) << stock[i] << endl;
    }
}

//===================================================================================================================

void agregarAlCarrito() {
    char otro;

    do {
        int id, cantidad;

        verCatalogo();
        cout << "\nIngrese el ID del juego: ";
        cin >> id;
        cout << "Ingrese la cantidad de copias: ";
        cin >> cantidad;

        if (id < 1 || id > MAX_JUEGOS) {
            cout << "\nError: Opcion no valida.\n";
        } else {
            int indice = id - 1;

            if (cantidad <= 0 || cantidad > stock[indice]) {
                cout << "\nError: juego sin stock.\n";
            } else {
                carrito[indice] = carrito[indice] + cantidad;
                stock[indice] = stock[indice] - cantidad;
                cout << "\nSe agrego " << cantidad << " unidad(es) de "
                     << juegos[indice] << " al carrito.\n";
            }
        }

        cout << "\nDesea agregar otro juego? (s/n): ";
        cin >> otro;

    } while (otro == 's' || otro == 'S');
}

//===================================================================================================================

void calcularTotal() {
    total = 0;

    for (int i = 0; i < MAX_JUEGOS; i++) {
        subtotal = carrito[i] * precios[i];
        total = total + subtotal;
    }

    cout << "\nTotal de la compra: $" << fixed << setprecision(2) << total << endl;
}

//===================================================================================================================

void modificarCarrito() {
    int id, nuevaCantidad;

    cout << "\n===== CARRITO ACTUAL =====\n";
    for (int i = 0; i < MAX_JUEGOS; i++) {
        if (carrito[i] > 0) {
            cout << (i + 1) << ". " << juegos[i] << " - Cantidad: " << carrito[i] << endl;
        }
    }

    cout << "\nIngrese el ID del juego que desea modificar: ";
    cin >> id;

    if (id < 1 || id > MAX_JUEGOS) {
        cout << "\nError: Opcion no valida.\n";
        return;
    }

    int indice = id - 1;
    int disponible = stock[indice] + carrito[indice];

    cout << "Ingrese la nueva cantidad de copias: ";
    cin >> nuevaCantidad;

    if (nuevaCantidad < 0 || nuevaCantidad > disponible) {
        cout << "\nError: juego sin stock.\n";
    } else {
        stock[indice] = disponible - nuevaCantidad;
        carrito[indice] = nuevaCantidad;
        cout << "\nCarrito y stock actualizados correctamente.\n";
    }
}

//===================================================================================================================

void vaciarCarrito() {
    char confirmacion;

    cout << "\nConfirma cancelar la compra? (s/n): ";
    cin >> confirmacion;

    if (confirmacion == 's' || confirmacion == 'S') {
        for (int i = 0; i < MAX_JUEGOS; i++) {
            stock[i] = stock[i] + carrito[i];
            carrito[i] = 0;
        }
        cout << "\nEl carrito ha sido vaciado.\n";
    } else {
        cout << "\nOperacion cancelada. El carrito sigue igual.\n";
    }
}

//===================================================================================================================

void generarFactura() {
    cout << "\n===== FACTURA =====\n";
    cout << left << setw(30) << "Juego" << setw(10) << "Cantidad"
         << setw(12) << "Precio" << setw(12) << "Subtotal" << endl;

    for (int i = 0; i < MAX_JUEGOS; i++) {
        if (carrito[i] > 0) {
            subtotal = carrito[i] * precios[i];
            cout << left << setw(30) << juegos[i] << setw(10) << carrito[i]
                 << "$" << setw(11) << fixed << setprecision(2) << precios[i]
                 << "$" << setw(11) << subtotal << endl;
        }
    }

    cout << "\nTOTAL A PAGAR: $" << fixed << setprecision(2) << total << endl;
}

//===================================================================================================================

void confirmarCompra() {
    char confirmacion;
    bool carritoVacio = true;

    for (int i = 0; i < MAX_JUEGOS; i++) {
        if (carrito[i] > 0) {
            carritoVacio = false;
        }
    }

    if (carritoVacio) {
        cout << "\nEl carrito esta vacio. No se puede confirmar la compra.\n";
        return;
    }

    calcularTotal();

    cout << "\nConfirma la compra? (s/n): ";
    cin >> confirmacion;

    if (confirmacion == 's' || confirmacion == 'S') {
        generarFactura();

        for (int i = 0; i < MAX_JUEGOS; i++) {
            carrito[i] = 0;
        }

        cout << "\nCompra registrada. Gracias por su compra.\n";
    } else {
        cout << "\nSaliendo sin confirmar la compra.\n";
    }
}