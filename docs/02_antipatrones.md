# Antipatrones detectados

Durante el análisis del sistema de venta de TechStore se identifican varios antipatrones que pueden afectar la calidad del diseño.

## 1. Objeto Dios

Cuando una única clase concentra la lógica de productos, clientes, ventas y pagos, el sistema se vuelve difícil de mantener y probar. Esto afecta la escalabilidad del proyecto.

## 2. Copia y pega de lógica

La duplicación de bloques de lógica para validar precios, stock o descuentos puede generar inconsistencias y errores difíciles de detectar.

## 3. Acoplamiento fuerte

Si una clase dependiente conoce demasiados detalles internos de otra, los cambios son costosos y cada modificación puede romper varias partes del sistema.

## 4. Falta de encapsulamiento

Exponer directamente atributos internos sin métodos adecuados aumenta la posibilidad de errores y dificulta la evolución.

## 5. Solución propuesta

El proyecto busca evitar estos problemas usando separación de responsabilidades, encapsulamiento y patrones como Factory, Strategy y Observer según la necesidad del caso de uso.
