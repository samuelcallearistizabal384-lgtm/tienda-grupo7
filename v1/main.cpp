#include <iostream>
#include <string>
#include <vector>

class Producto {
public:
    Producto(const std::string& nombre, double precio)
        : nombre_(nombre), precio_(precio) {}

    std::string nombre() const { return nombre_; }
    double precio() const { return precio_; }

private:
    std::string nombre_;
    double precio_;
};

class Cliente {
public:
    Cliente(const std::string& nombre)
        : nombre_(nombre) {}

    std::string nombre() const { return nombre_; }

private:
    std::string nombre_;
};

class MetodoPago {
public:
    MetodoPago(const std::string& tipo)
        : tipo_(tipo) {}

    std::string tipo() const { return tipo_; }

private:
    std::string tipo_;
};

class Venta {
public:
    Venta(const Cliente& cliente, const MetodoPago& metodoPago, const Producto& producto, int cantidad)
        : cliente_(cliente), metodoPago_(metodoPago), producto_(producto), cantidad_(cantidad) {}

    void mostrarResumen() const {
        std::cout << "TechStore Online\n";
        std::cout << "Cliente: " << cliente_.nombre() << "\n";
        std::cout << "Producto: " << producto_.nombre() << "\n";
        std::cout << "Cantidad: " << cantidad_ << "\n";
        std::cout << "Subtotal: " << producto_.precio() * cantidad_ << "\n";
        std::cout << "Descuento: 0\n";
        std::cout << "Total: " << producto_.precio() * cantidad_ << "\n";
        std::cout << "Método de pago: " << metodoPago_.tipo() << "\n";
        std::cout << "Estado: confirmada\n";
    }

private:
    Cliente cliente_;
    MetodoPago metodoPago_;
    Producto producto_;
    int cantidad_;
};

class Tienda {
public:
    void agregarProducto(const Producto& producto) {
        catalogo_.push_back(producto);
    }

    Venta crearVenta(const Cliente& cliente, const MetodoPago& metodoPago, const std::string& nombreProducto, int cantidad) const {
        for (const auto& producto : catalogo_) {
            if (producto.nombre() == nombreProducto) {
                return Venta(cliente, metodoPago, producto, cantidad);
            }
        }

        throw std::runtime_error("Producto no encontrado");
    }

private:
    std::vector<Producto> catalogo_;
};

int main() {
    Tienda tienda;
    tienda.agregarProducto(Producto("Laptop Gamer", 1800000.0));
    tienda.agregarProducto(Producto("Mouse Inalámbrico", 85000.0));
    tienda.agregarProducto(Producto("Monitor 27\"", 420000.0));

    try {
        Venta venta = tienda.crearVenta(Cliente("Ana"), MetodoPago("Tarjeta"), "Laptop Gamer", 1);
        venta.mostrarResumen();
    } catch (const std::exception& ex) {
        std::cerr << "Error: " << ex.what() << "\n";
        return 1;
    }

    return 0;
}
