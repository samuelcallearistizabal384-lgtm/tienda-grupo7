#include <iostream>
#include <vector>
#include <string>
#include <iomanip>
#include <memory>

using namespace std;

// ==========================================
// 1. PATRÓN CREACIONAL: FACTORY METHOD
// ==========================================
class ProductoBase {
protected:
    string codigo;
    string nombre;
    double precioBase;
    int stock;
public:
    ProductoBase(string cod, string nom, double precio, int st) 
        : codigo(cod), nombre(nom), precioBase(precio), stock(st) {}
    
    virtual ~ProductoBase() {}
    
    string getCodigo() const { return codigo; }
    string getNombre() const { return nombre; }
    virtual double getPrecioBase() const { return precioBase; }
    int getStock() const { return stock; }
    void reducirStock(int cantidad) { stock -= cantidad; }
    
    virtual string getTipoDescripcion() const = 0;
};

class ProductoHardware : public ProductoBase {
public:
    ProductoHardware(string cod, string nom, double precio, int st) 
        : ProductoBase(cod, nom, precio, st) {}
    string getTipoDescripcion() const override { return "Hardware Fisico"; }
};

class ProductoLicenciaDigital : public ProductoBase {
public:
    ProductoLicenciaDigital(string cod, string nom, double precio, int st) 
        : ProductoBase(cod, nom, precio, st) {}
    string getTipoDescripcion() const override { return "Licencia Digital"; }
};

class ProductoGarantia : public ProductoBase {
public:
    ProductoGarantia(string cod, string nom, double precio, int st) 
        : ProductoBase(cod, nom, precio, st) {}
    string getTipoDescripcion() const override { return "Componente con Garantia"; }
};

// Fábrica para instanciar productos tecnológicos
class ProductoFactory {
public:
    static shared_ptr<ProductoBase> crearProducto(int tipo, string codigo, string nombre, double precio, int stock) {
        if (tipo == 1) return make_shared<ProductoHardware>(codigo, nombre, precio, stock);
        if (tipo == 2) return make_shared<ProductoLicenciaDigital>(codigo, nombre, precio, stock);
        if (tipo == 3) return make_shared<ProductoGarantia>(codigo, nombre, precio, stock);
        return nullptr;
    }
};

// ==========================================
// 2. PATRÓN ESTRUCTURAL: DECORATOR
// ==========================================
class ItemVenta {
public:
    virtual ~ItemVenta() {}
    virtual double calcularCostoTotal() const = 0;
    virtual string getDescripcion() const = 0;
};

class ItemConcreto : public ItemVenta {
private:
    shared_ptr<ProductoBase> producto;
    int cantidad;
public:
    ItemConcreto(shared_ptr<ProductoBase> prod, int cant) : producto(prod), cantidad(cant) {}
    double calcularCostoTotal() const override {
        return producto->getPrecioBase() * cantidad;
    }
    string getDescripcion() const override {
        return producto->getNombre() + " (Cant: " + to_string(cantidad) + ")";
    }
};

class ImpuestoDecorator : public ItemVenta {
protected:
    shared_ptr<ItemVenta> item;
public:
    ImpuestoDecorator(shared_ptr<ItemVenta> it) : item(it) {}
    double calcularCostoTotal() const override { return item->calcularCostoTotal(); }
    string getDescripcion() const override { return item->getDescripcion(); }
};

class IVAdecorator : public ImpuestoDecorator {
public:
    IVAdecorator(shared_ptr<ItemVenta> it) : ImpuestoDecorator(it) {}
    double calcularCostoTotal() const override {
        return item->calcularCostoTotal() * 1.19; // Aplica IVA 19%
    }
    string getDescripcion() const override {
        return item->getDescripcion() + " + IVA 19%";
    }
};

class ImpuestoDigitalDecorator : public ImpuestoDecorator {
public:
    ImpuestoDigitalDecorator(shared_ptr<ItemVenta> it) : ImpuestoDecorator(it) {}
    double calcularCostoTotal() const override {
        return item->calcularCostoTotal() * 1.05; // Aplica impuesto digital 5%
    }
    string getDescripcion() const override {
        return item->getDescripcion() + " + Impuesto Digital 5%";
    }
};

// ==========================================
// 3. PATRÓN DE COMPORTAMIENTO: STRATEGY
// ==========================================
class EstrategiaPago {
public:
    virtual ~EstrategiaPago() {}
    virtual double procesarPago(double totalSubtotal) = 0;
    virtual string getNombreMetodo() const = 0;
};

class PagoTarjeta : public EstrategiaPago {
public:
    double procesarPago(double totalSubtotal) override {
        return totalSubtotal; // Sin descuento ni recargo
    }
    string getNombreMetodo() const override { return "Tarjeta de Credito / Debito"; }
};

class PagoTransferencia : public EstrategiaPago {
public:
    double procesarPago(double totalSubtotal) override {
        return totalSubtotal * 0.97; // 3% de descuento
    }
    string getNombreMetodo() const override { return "Transferencia Bancaria (3% Desc)"; }
};

class PagoPasarelaExterna : public EstrategiaPago {
public:
    double procesarPago(double totalSubtotal) override {
        return (totalSubtotal * 0.97) + 5000; // 3% descuento + pasarela fija
    }
    string getNombreMetodo() const override { return "Pasarela Externa / Cripto"; }
};

// ==========================================
// CONTROLADOR DE LA TIENDA TECNOLÓGICA
// ==========================================
struct DetalleVentaInfo {
    string descripcion;
    double subtotal;
};

struct VentaInfo {
    int idVenta;
    vector<DetalleVentaInfo> detalles;
    string metodoPago;
    double totalPagado;
};

class TechStoreOnlineV1 {
private:
    vector<shared_ptr<ProductoBase>> catalogo;
    vector<VentaInfo> historialVentas;
    double acumuladoFinanciero = 0;
    int contadorVentas = 1;

public:
    void registrarProducto() {
        string cod, nom;
        double precio;
        int stock, tipo;
        cout << "\n--- REGISTRAR PRODUCTO (VERSION PATRONES) ---\n";
        cout << "Codigo (ej. LAP01): "; cin >> cod;
        cout << "Nombre: "; cin.ignore(); getline(cin, nom);
        cout << "Precio ($): "; cin >> precio;
        cout << "Stock inicial: "; cin >> stock;
        cout << "Tipo (1: Hardware, 2: Licencia Digital, 3: Componente Garantia): "; cin >> tipo;

        auto p = ProductoFactory::crearProducto(tipo, cod, nom, precio, stock);
        if (p) {
            catalogo.push_back(p);
            cout << "¡Producto tecnológico registrado con Factory Method exitosamente!\n";
        }
    }

    void consultarInventario() {
        cout << "\n================ INVENTARIO TECHSTORE V1 ================\n";
        cout << left << setw(10) << "CODIGO" << setw(22) << "NOMBRE" << setw(12) << "PRECIO" << setw(10) << "STOCK" << setw(20) << "TIPO" << "\n";
        cout << "---------------------------------------------------------\n";
        for (const auto& p : catalogo) {
            cout << left << setw(10) << p->getCodigo() 
                 << setw(22) << p->getNombre() 
                 << "$ " << setw(10) << fixed << setprecision(2) << p->getPrecioBase() 
                 << setw(10) << p->getStock() 
                 << setw(20) << p->getTipoDescripcion() << "\n";
        }
        cout << "=========================================================\n";
    }

    void registrarVenta() {
        if (catalogo.empty()) {
            cout << "\nNo hay productos disponibles.\n";
            return;
        }

        VentaInfo nuevaVenta;
        nuevaVenta.idVenta = contadorVentas++;
        char continuar = 's';
        double subtotalTemporal = 0;
        vector<shared_ptr<ItemVenta>> itemsComprados;

        cout << "\n--- CHECKOUT DE VENTA CON DECORATORS Y STRATEGY ---\n";
        while (continuar == 's' || continuar == 'S') {
            string cod;
            int cant;
            cout << "Codigo del producto a comprar: "; cin >> cod;

            shared_ptr<ProductoBase> productoEncontrado = nullptr;
            for (auto& p : catalogo) {
                if (p->getCodigo() == cod) {
                    productoEncontrado = p;
                    break;
                }
            }

            if (!productoEncontrado) {
                cout << "Producto no encontrado.\n";
            } else {
                cout << "Cantidad deseada: "; cin >> cant;
                if (productoEncontrado->getStock() >= cant) {
                    productoEncontrado->reducirStock(cant);

                    // Patrón Decorator aplicado dinámicamente según la categoría tecnológica
                    shared_ptr<ItemVenta> item = make_shared<ItemConcreto>(productoEncontrado, cant);
                    if (productoEncontrado->getTipoDescripcion() == "Hardware Fisico") {
                        item = make_shared<IVAdecorator>(item);
                    } else if (productoEncontrado->getTipoDescripcion() == "Licencia Digital") {
                        item = make_shared<ImpuestoDigitalDecorator>(item);
                    } else {
                        item = make_shared<IVAdecorator>(item); // Garantía lleva IVA base
                    }

                    subtotalTemporal += item->calcularCostoTotal();
                    itemsComprados.push_back(item);
                    nuevaVenta.detalles.push_back({item->getDescripcion(), item->calcularCostoTotal()});

                    if (productoEncontrado->getStock() < 5) {
                        cout << " >>> ¡ALERTA DE STOCK BAJO! Quedan " << productoEncontrado->getStock() << " unidades. <<<\n";
                    }
                    cout << "¡Item agregado correctamente con impuestos decorados!\n";
                } else {
                    cout << "Stock insuficiente. Disponible: " << productoEncontrado->getStock() << "\n";
                }
            }
            cout << "¿Desea agregar otro producto? (s/n): "; cin >> continuar;
        }

        if (itemsComprados.empty()) {
            contadorVentas--;
            return;
        }

        // Selección de pago con Patrón Strategy
        int opcionPago;
        cout << "\nSeleccione el metodo de pago (Strategy):\n";
        cout << "1. Tarjeta de Credito / Debito\n";
        cout << "2. Transferencia Bancaria (3% desc)\n";
        cout << "3. Pasarela Externa / Cripto\n";
        cout << "Opcion: "; cin >> opcionPago;

        shared_ptr<EstrategiaPago> estrategia;
        if (opcionPago == 2) estrategia = make_shared<PagoTransferencia>();
        else if (opcionPago == 3) estrategia = make_shared<PagoPasarelaExterna>();
        else estrategia = make_shared<PagoTarjeta>();

        nuevaVenta.metodoPago = estrategia->getNombreMetodo();
        nuevaVenta.totalPagado = estrategia->procesarPago(subtotalTemporal);
        acumuladoFinanciero += nuevaVenta.totalPagado;

        historialVentas.push_back(nuevaVenta);
        cout << "\n-------------------------------------------------\n";
        cout << " ¡Orden #" << nuevaVenta.idVenta << " procesada con Strategy exitosamente!\n";
        cout << " Total pagado con descuento/recargo: $" << fixed << setprecision(2) << nuevaVenta.totalPagado << "\n";
        cout << "-------------------------------------------------\n";
    }

    void reporteDeVentas() {
        cout << "\n================ REPORTE FINANCIERO V1 ================\n";
        if (historialVentas.empty()) {
            cout << "Sin transacciones registradas.\n";
        } else {
            for (const auto& v : historialVentas) {
                cout << "Orden ID: " << v.idVenta << " | Metodo: " << v.metodoPago << "\n";
                for (const auto& d : v.detalles) {
                    cout << " - " << d.descripcion << " -> Subtotal con impuesto: $" << d.subtotal << "\n";
                }
                cout << " Total Orden: $" << v.totalPagado << "\n-------------------------------------------------------\n";
            }
            cout << "INGRESOS TOTALES ACUMULADOS: $" << fixed << setprecision(2) << acumuladoFinanciero << "\n";
        }
        cout << "=======================================================\n";
    }
};

int main() {
    TechStoreOnlineV1 tienda;
    int opcion = 0;
    do {
        cout << "\n===== TECHSTORE ONLINE - VERSION 1 (PATRONES) =====\n";
        cout << "1. Registrar producto tecnológico (Factory Method)\n";
        cout << "2. Consultar inventario\n";
        cout << "3. Registrar venta / Checkout (Decorator + Strategy)\n";
        cout << "4. Ver reporte financiero\n";
        cout << "5. Salir\n";
        cout << "Seleccione una opcion: "; cin >> opcion;

        switch (opcion) {
            case 1: tienda.registrarProducto(); break;
            case 2: tienda.consultarInventario(); break;
            case 3: tienda.registrarVenta(); break;
            case 4: tienda.reporteDeVentas(); break;
            case 5: cout << "Saliendo de la plataforma...\n"; break;
            default: cout << "Opcion no valida.\n"; break;
        }
    } while (opcion != 5);
    return 0;
}
