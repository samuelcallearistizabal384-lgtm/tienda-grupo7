# TechStore Online

**Proyecto final de Patrones de Software**

Sistema de gestión para una tienda tecnológica que permite registrar productos, administrar inventario, procesar ventas y generar reportes mediante la implementación de patrones de diseño.

## 1. Integrantes y roles

- **Erick Santiago Loaiza Ocampo:** Responsable de modelado (documentación y diagramas UML).
- **Samuel Calle Aristizábal:** Responsable de código y responsable de diseño (implementación e integración de patrones).

## 2. Tipo de tienda

TechStore Online es una tienda de tecnología y electrónica dedicada a la venta de dispositivos, accesorios y equipos informáticos.

## 3. Objetivo

Desarrollar una aplicación de consola en C++ para gestionar los productos, inventario y ventas de una tienda tecnológica, utilizando patrones de diseño que permitan mejorar la organización y el mantenimiento del código.

## 4. Patrones de diseño utilizados

### Factory Method (Creacional)
Permite crear diferentes tipos de productos sin tener que realizar directamente su construcción en el resto del sistema.

### Decorator (Estructural)
Permite agregar impuestos y funcionalidades adicionales a los productos sin modificar su estructura principal.

### Strategy (Comportamiento)
Permite utilizar diferentes métodos de pago mediante estrategias intercambiables.

## 5. Estructura del repositorio

- `docs/`: Documentación del proyecto.
  - `01_ficha_cliente.md`: Ficha del cliente y requisitos.
  - `02_antipatrones.md`: Antipatrones encontrados.
  - `03_justificacion_patrones.md`: Justificación de los patrones.
- `uml/`: Diagramas UML del sistema.
- `v0/`: Primera versión sin patrones.
- `v1/`: Versión mejorada con patrones de diseño.

## 6. Requisitos

- Compilador de C++ compatible con C++17.
- Git para clonar el repositorio.

## 7. Compilación y ejecución

Clonar el repositorio:

```bash
git clone https://github.com/samuelcallearistizabal384-lgtm/tienda-grupo7.git
```

Ingresar a la carpeta:

```bash
cd tienda-grupo7
```

Compilar la versión 1:

```bash
g++ -std=c++17 v1/main.cpp -o techstore
```

Ejecutar en Linux:

```bash
./techstore
```

En Windows:

```bash
techstore.exe
```

