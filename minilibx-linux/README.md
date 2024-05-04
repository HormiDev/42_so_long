[![Build](https://github.com/42Paris/minilibx-linux/actions/workflows/ci.yml/badge.svg)](https://github.com/42Paris/minilibx-linux/actions/workflows/ci.yml)

Esto es MinilibX, una sencilla API de programación X-Window (X11R6) en C, diseñada para estudiantes, adecuada para principiantes en X.



Contenido

- código fuente en C para crear la biblioteca mlx
- páginas de manual (en el directorio man/)
- un programa de prueba (en el directorio test/) se construye con la biblioteca
- un archivo de inclusión público mlx.h
- un pequeño script de configuración para generar un Makefile.gen apropiado



Requisitos para Linux

- MinilibX solo soporta el tipo de visual TrueColor (profundidad de 8,15,16,24 o 32 bits)
- gcc
- make
- archivos de inclusión de X11 (paquete xorg)
- La extensión XShm debe estar presente (paquete libxext-dev)
- Funciones de utilidad de los sistemas BSD - archivos de desarrollo (paquete libbsd-dev)
- por ejemplo, sudo apt-get install gcc make xorg libxext-dev libbsd-dev (Debian/Ubuntu)



Requisitos para MacOS

- Xquartz(https://www.xquartz.org/)

```bash
➜  ~ Brew install Xquartz
➜  ~ reboot
➜  ~ xeyes # ejecuta una aplicación X11 de hola mundo
```



Opacidad / Transparencia / Alfa de color MlX (profundidad de 32 bits)

- 0xFF (totalmente transparente) o 0x00 (totalmente opaco)



Compilar MinilibX

- ejecutar ./configure o make ambos harán algunas pruebas, crearán Makefile.gen y luego automáticamente ejecutarán make en este Makefile.gen generado. Se crean libmlx.a y libmlx_$(HOSTTYPE).a. También se crea el binario test/mlx-test.



Instalar MinilibX

- no se proporciona un script de instalación. Es posible que desees instalar
- libmlx.a y/o libmlx_$(HOSTTYPE).a en /usr/X11/lib o /usr/local/lib
- mlx.h en /usr/X11/include o /usr/local/include
- man/man3/mlx*.1 en /usr/X11/man/man3 o /usr/local/man/man3



Olivier CROUZET - 2014-01-06 -