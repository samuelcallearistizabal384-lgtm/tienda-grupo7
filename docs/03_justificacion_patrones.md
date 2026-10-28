# Justificación de patrones de diseño

La solución planteada para TechStore Online utiliza patrones que ayudan a estructurar el sistema y mantenerlo en evolución.

## 1. Patrón Factory

Se usa para centralizar la creación de instancias de productos o tipos de ventas cuando se requieren distintos tipos de operaciones o configuraciones.

## 2. Patrón Strategy

Permite cambiar la lógica de cálculo o criterio de descuento sin modificar el núcleo de la venta. Esto facilita la extensión del sistema.

## 3. Patrón Observer

Puede resultar útil para notificar cambios de stock o de estado de la venta a otros módulos del sistema, como inventario o administración.

## 4. Beneficios esperados

- Menor acoplamiento entre módulos.
- Mejor reutilización de código.
- Futura extensibilidad.
- Diseño más claro para pruebas y mantenimiento.

## 5. Conclusión

La aplicación de patrones de diseño no solo mejora la calidad del software, sino que también ayuda a modelar mejor el problema real del negocio y a construir una solución más sostenible en el tiempo.
