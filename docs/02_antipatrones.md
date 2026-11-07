# Antipatrones detectados

Durante la revisión del sistema de ventas de TechStore se identificaron distintas deficiencias de diseño que podrían afectar el correcto desarrollo y mantenimiento del sistema.

## 1. Objeto Dios

Cuando una sola clase reúne la gestión de productos, clientes, ventas y pagos, el sistema se vuelve más complejo de mantener y verificar. Esto limita el crecimiento y la capacidad de expansión del proyecto.

## 2. Copia y pega de lógica

La repetición de fragmentos de código destinados a comprobar precios, existencias o descuentos puede provocar inconsistencias y fallos difíciles de detectar.

## 3. Acoplamiento fuerte

Cuando una clase depende de un conocimiento excesivo sobre el funcionamiento interno de otra, cualquier cambio resulta más complejo y puede afectar múltiples componentes del sistema.

## 4. Falta de encapsulamiento
Puede ocasionar fallos y complicar el desarrollo futuro del sistema.

## 5. Solución propuesta

El objetivo del proyecto es prevenir estos inconvenientes mediante la división adecuada de responsabilidades, el uso del encapsulamiento y la implementación de patrones de diseño como Factory Method, Strategy y Observer, según las necesidades de cada caso de uso.
