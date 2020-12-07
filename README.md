# Proyecto Compilador

Para detalles sobre la sintaxis, consultar la [Definición de Sintaxis](Definicion_Sintaxis.pdf).

### Uso:
Descargar el [binario](link), o bien, clonar el repositiorio y compilarlo.

El código a ejecutar tiene que estar en un archivo de texto. Consultar los [ejemplos](examples/) para mayor referencia.

Para compilar y ejecutar un programa, indicar en la linea de comandos el nombre del archivo, utilizando la ruta relativa al directorio en donde se encuentra el compilador, o bien, proporcionando la ruta completa.
Ejemplo:

```
> ./compilador.exe examples/promedio.txt
> ./compilador.exe C:/ruta/al/archivo/archivo.txt
```

Se puede añadir la opción `-d` para que el programa muestre cada una de las fases del intérprete.
```
> ./compilador.exe examples/promedio.txt -d
```