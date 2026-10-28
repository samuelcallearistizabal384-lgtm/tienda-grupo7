#include <iostream>
#include <string>
#include <vector>

struct Producto {
    std::string nombre;
    double precio;
};

class Carrito {
public:
    void agregarProducto(const Producto& producto) {
        productos_.push_back(producto);
    }

    double total() const {
        double suma = 0.0;
        for (const auto& producto : productos_) {
            suma += producto.precio;
        }
        return suma;
    }

    void mostrar() const {
        std::cout << "Carrito de compra\n";
        for (const auto& producto : productos_) {
            std::cout << "- " << producto.nombre << ": $" << producto.precio << "\n";
        }
        std::cout << "Total: $" << total() << "\n";
    }

private:
    std::vector<Producto> productos_;
};

int main() {
    Carrito carrito;

    carrito.agregarProducto({"Teclado mecánico", 120000.0});
    carrito.agregarProducto({"Monitor 27\"", 320000.0});

    std::cout << "TechStore Online\n";
    carrito.mostrar();

    return 0;
}
