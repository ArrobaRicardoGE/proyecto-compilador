# Proyecto Compilador

Para detalles sobre la sintaxis, consultar la [Definición de Sintaxis](Definicion_Sintaxis.pdf).

### Uso:
Descargar el [binario](https://github.com/ArrobaRicardoGE/proyecto-compilador/releases/tag/1.1), o bien, clonar el repositiorio y compilarlo.

El código a ejecutar tiene que estar en un archivo de texto. Consultar los [ejemplos](examples/) para mayor referencia.

Para compilar y ejecutar un programa, indicar en la linea de comandos el nombre del archivo, utilizando la ruta relativa al directorio en donde se encuentra el compilador, o bien, proporcionando la ruta completa.
Ejemplo:

```
> ./interprete.exe examples/promedio.txt
> ./interprete.exe C:/ruta/al/archivo/archivo.txt
```

Se puede añadir la opción `-d` para que el programa muestre cada una de las fases del intérprete.
```
> ./interprete.exe examples/promedio.txt -d
```
