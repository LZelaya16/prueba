#include <iostream>
#include <iomanip>
#include "funciones.h"
using namespace std;

const int MAX_JUEGOS = 10;

string juegos[MAX_JUEGOS] = {
    "GTA 6",
    "Minecraft",
    "Batman Arkham Origins",
    "Human Fall Flat",
    "Ready or Not",
    "Forza Horizon 6",
    "Peak",
    "Mortal Kombat XL",
    "Dragon Ball X",
    "Doom"
};

double precios[MAX_JUEGOS] = {69.99, 29.99, 19.99, 14.99, 39.99, 59.99, 24.99, 34.99, 44.99, 49.99};
int stock[MAX_JUEGOS] = {10, 20, 8, 15, 12, 9, 18, 11, 7, 14};
int carrito[MAX_JUEGOS] = {0, 0, 0, 0, 0, 0, 0, 0, 0, 0};

double subtotal = 0;
double total = 0;

int main()
{
    int opcion = 0;

    do
    {
        mostrarMenu();
        cin >> opcion;

        if (opcion < 1 || opcion > 7)
        {
            cout << "\nError: Opcion no valida.\n";
        }
        else
        {
            switch (opcion)
            {
            case 1:
                verCatalogo();
                break;
            case 2:
                agregarAlCarrito();
                break;
            case 3:
                calcularTotal();
                break;
            case 4:
                modificarCarrito();
                break;
            case 5:
                vaciarCarrito();
                break;
            case 6:
                confirmarCompra();
                break;
            case 7:
                cout << "\nGracias por visitar la tienda. Hasta pronto.\n";
                break;
            }
        }

    } while (opcion != 7);

    return 0;
}