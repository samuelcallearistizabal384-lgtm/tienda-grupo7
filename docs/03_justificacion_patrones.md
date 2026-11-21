## Justificación de los patrones de diseño
La arquitectura propuesta para TechStore Online incorpora diversos patrones de diseño con el propósito de mejorar la organización del sistema, facilitar su mantenimiento y permitir futuras ampliaciones de forma más sencilla.

## 1. Factory Method
UBICACION:class ProductoFactory {
public:
    static shared_ptr<ProductoBase> crearProducto(...)
Líneas 47–54
PROBLEMA QUE RESUELVE:
Evita que el sistema tenga que crear objetos específicos directamente mediante
new ProductoHardware(...)
new ProductoLicenciaDigital(...)
new ProductoGarantia(...)
EVIDENCIA DE FLUJO:
auto p = ProductoFactory::crearProducto(
1    tipo,
2    cod,
3   nom,
4   precio,
5    stock
);
Línea 193
## 2. Strategy
## UBICACION:
class EstrategiaPago
class PagoTarjeta
class PagoTransferencia
class PagoPasarelaExterna
Líneas 321–326
PROBLEMA QUE RESUELVE:
Cada método de pago tiene una regla diferente.
## Sin Strategy:
if (...)
else if (...)
else if (...)
## Con strategy:
estrategia->procesarPago()
## Beneficio
Agregar nuevos métodos de pago sin modificar el código existente:
PagoPayPal
PagoNequi
PagoPSE
PagoBitcoin

Su función es encapsular distintos algoritmos o reglas de negocio, como cálculos de descuentos o métodos de procesamiento. Esto permite intercambiar comportamientos específicos sin afectar el resto del sistema.

## 3. Decorator
## UBICACION:
class ItemVenta
class ItemConcreto
class ImpuestoDecorator
class IVAdecorator
class ImpuestoDigitalDecorator
Líneas 58–63

Este patrón permite añadir funcionalidades adicionales a un producto o proceso sin modificar su estructura principal. Puede utilizarse para aplicar descuentos, promociones o impuestos de forma flexible y reutilizable.

## 4. Ventajas obtenidas
Reducción del acoplamiento entre componentes.
Mayor facilidad para realizar tareas de mantenimiento.
Incremento de la flexibilidad y capacidad de crecimiento del sistema.
Distribución más clara de las responsabilidades.
Incorporación de nuevas funcionalidades con un impacto mínimo sobre el código existente.
Diseño más comprensible para las actividades de prueba y mantenimiento.

## 5. Conclusión
La implementación de patrones de diseño contribuye significativamente al mejoramiento de la calidad del software. Además de optimizar la estructura interna de la aplicación, permite representar de forma más adecuada los procesos del negocio y desarrollar una solución robusta, flexible y sostenible a largo plazo.
