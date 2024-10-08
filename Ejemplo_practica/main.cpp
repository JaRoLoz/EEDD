#include <iostream>
#include <stack>
#include <ctime>
#include <cstdlib>

struct Pedido {
    int id;
    int numeroSeguimiento;
    std::string dniCliente;
    bool esUrgente;
};

// Función para generar un número aleatorio entre min y max
int generarNumeroAleatorio(int min, int max) {
    return min + rand() % (max - min + 1);
}

// Función para crear un pedido aleatorio
Pedido generarPedido() {
    Pedido pedido;
    static int id = 1;
    pedido.id = id++;
    pedido.numeroSeguimiento = generarNumeroAleatorio(1000, 9999);
    pedido.dniCliente = "DNI" + std::to_string(generarNumeroAleatorio(10000000, 99999999));
    pedido.esUrgente = (generarNumeroAleatorio(0, 1) == 1); // 1 para urgente, 0 para estándar
    return pedido;
}

int main() {
    std::stack<Pedido> pilaPedidos;

    // Semilla aleatoria para generar pedidos diferentes cada vez
    srand(time(0));

    // Generar y almacenar pedidos aleatorios en la pila
    for (int i = 0; i < 10; i++) {
        Pedido pedido = generarPedido();
        pilaPedidos.push(pedido);
    }

    // Mostrar los pedidos almacenados en la pila
    std::cout << "Pedidos en la pila:" << std::endl;
    while (!pilaPedidos.empty()) {
        Pedido pedido = pilaPedidos.top();
        pilaPedidos.pop();

        std::cout << "ID: " << pedido.id << " | Numero de seguimiento: " << pedido.numeroSeguimiento
                  << " | DNI del cliente: " << pedido.dniCliente
                  << " | Es urgente: " << (pedido.esUrgente ? "Sí" : "No") << std::endl;
    }

    return 0;
}