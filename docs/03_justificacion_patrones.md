## Justificación de los patrones de diseño
La arquitectura propuesta para TechStore Online incorpora diversos patrones de diseño con el propósito de mejorar la organización del sistema, facilitar su mantenimiento y permitir futuras ampliaciones de forma más sencilla.

## 1. Factory Method
Este patrón se emplea para gestionar de manera centralizada la creación de objetos relacionados con productos o procesos de venta. Gracias a ello, es posible incorporar nuevos tipos sin alterar significativamente la lógica principal de la aplicación.

## 2. Strategy
Su función es encapsular distintos algoritmos o reglas de negocio, como cálculos de descuentos o métodos de procesamiento. Esto permite intercambiar comportamientos específicos sin afectar el resto del sistema.

## 3. Observer
Este patrón facilita la comunicación entre componentes cuando ocurre un cambio relevante. Por ejemplo, puede utilizarse para informar actualizaciones de inventario o modificaciones en el estado de una venta a otros módulos interesados.

## 4. Ventajas obtenidas
Reducción del acoplamiento entre componentes.
Mayor facilidad para realizar tareas de mantenimiento.
Incremento de la flexibilidad y capacidad de crecimiento del sistema.
Distribución más clara de las responsabilidades.
Incorporación de nuevas funcionalidades con un impacto mínimo sobre el código existente.
Diseño más comprensible para las actividades de prueba y mantenimiento.

## 5. Conclusión
La implementación de patrones de diseño contribuye significativamente al mejoramiento de la calidad del software. Además de optimizar la estructura interna de la aplicación, permite representar de forma más adecuada los procesos del negocio y desarrollar una solución robusta, flexible y sostenible a largo plazo.
