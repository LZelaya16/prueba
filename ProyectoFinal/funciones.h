#ifndef FUNCIONES_H
#define FUNCIONES_H
#include <string>
using namespace std;

extern const int MAX_JUEGOS;
extern string juegos[];
extern double precios[];
extern int stock[];
extern int carrito[];
extern double subtotal;
extern double total;

void mostrarMenu();
void verCatalogo();
void agregarAlCarrito();
void calcularTotal();
void modificarCarrito();
void vaciarCarrito();
void generarFactura();
void confirmarCompra();
#endif