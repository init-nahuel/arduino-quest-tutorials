# Matriz Led

La libreria utilizada para manejar la matriz led a traves del componente MAX7219 es `MD_MAX72xx`, para incluirla se debe declarar al principio del codigo:

```ino
#include <MD_MAX72xx.h>
```

Luego se debe crear un objeto de la clase `MD_MAX72xx`, para esto llamamos la funcion `MD_MAX72xx(mod, dataPin, clkPin, csPin, numDevices)`, donde los parametros que toma son:

- `mod`: Indica la orientacion para el eje de coordenadas que representa la posicion de los leds en la matriz, existent cuatro opciones comunes que les pueden servir: `MD_MAX72XX::DR0CR0RR0_HW`, `MD_MAX72XX::DR0CR0RR1_HW`, `MD_MAX72XX::DR0CR1RR0_HW` ó `MD_MAX72XX::DR0CR1RR1_HW`. Pueden ir probando las orientaciones encendiendo el led en la coordenada (0, 0) y fijarse donde se enciende en la matriz.
- `dataPin`: Este es el pin DIN que tiene la matriz led y debe ir conectado a cualquiera de los pines digitales del arduino.
- `clkPin`: Este es el pin CLK de la matriz y debe ir conectado a cualquiera de los pines digitales del arduino.
- `csPin`: pin CS de la matriz que tambien debe ir conectado a cualquiera de los pines digitales del arduino.

En el codigo de ejemplo se usa lo siguiente:

```ino
int clkPin = 7, csPin = 6, dinPin = 5;
MD_MAX72XX matrizLed = MD_MAX72XX(MD_MAX72XX::DR0CR1RR0_HW, dinPin, clkPin, csPin, 1);
```

En nuestro caso ocupamos la orientacion `MD_MAX72XX::DR0CR1RR0_HW` donde el led en la posicion (0, 0) se encuentra en la parte inferior izquierda de la matriz, mirandola de forma que los pines que estamos conectando (VCC, GND, DIN, CS, SLK) estan en la posicion inferior.

Por ultimo, debemos usar la funcion `begin()` asociada al objeto que declaramos para inicializarlo dentro de la funcion `setup()`, esto es parecido a cuando utilizamos `pinMode()`.

```ino
void setup() {
    matrizLed.begin();
}
```

**OJO:** Recuerden que la matriz led es de 8x8, por tanto cuando utilicen alguna de las funciones que se nombran abajo y quieran encender el led en alguna posicion especifica, las posiciones van a empezar desde el indice 0, así por ejemplo si quiero encender el led de la parte inferior izquierda, segun la orientacion que dimos, la posicion de ese led será (0, 0).

## Funciones útiles

Las siguientes funciones asociadas al objecto que creamos y guardamos en la variable `matrizLed` pueden ser de utilidad para formar patrones con la matriz led.

**OBS:** Noten que en los ejemplos se usa la funcion `delay()` entremedio de cada funcion que usamos, esto se hace para que se alcancen a mostrar el encendido de leds pues sino cambiaria tan rápido que no lo veriamos :c

- **clear():** Esta funcion apaga todos los leds de la matriz asociada, como dice su nombre nos sirve para "limpiar la matriz" (no recibe parametros). Ej:

    ```ino
    matrizLed.clear();
    ```

- **setRow(r, val):** Esta funcion se encarga encender los leds que indiquemos en una fila en específica, para esto debemos entregarle la fila `r` que queremos manipular y un numero en formato binario de 8 bits, donde los 1's indicaran el encendido de los leds y los 0's indicaran el apagado de los leds, para indicar que estamos escribiendo un numero binario se antepone `0b`, ej: `0b11111111`. Por ejemplo:

    ```ino
    // Encendemos todos los leds de la fila 2 de la matriz
    // Notemos que son 8 bits que corresponden a los 8 bits por fila que existen
    matrizLed.setRow(2, 0b11111111);
    delay(1000);
    // Encendemos leds intercalados
    matrizLed.setRow(2, 0b10101010);
    ```

    En este caso al igual que la funcion `setColumn()` no es necesario usar la funcion `clear()` para apagar y encender los leds de una misma fila.

- **setColumn(r, val):** Esta funcion se encarga de encender los leds que indiquemos en una columna especifica, funciona igual que `setRow()` pero para columnas. Ej:

    ```ino
    // Encendemos todos los leds de la columna 7
    matrizLed.setColumn(7, 0b11111111);
    delay(1000);
    // Encendemos de forma intercalada los leds de la columna 7
    matrizLed.setColumn(7, 0b10101010);
    ```

- **setPoint(r, c, state):** Esta funcion se encarga de encender un led especificando la posicion del led segun la matriz, para esto debemos entregarle la fila `r` y columna `c` del led en conjunto con el estado `state` que queremos tenga el led, es decir, encendido o apagado. Ej:

    ```ino
    // Encendemos el led en la posicion (7,5)
    matrizLed.setPoint(7, 5, HIGH);
    delay(1000);
    // Apagamos el led en la posicion (7,5)
    matrizLed.setPoint(7 , 5, LOW);
    ```

## Crear figuras en la matriz

Para crear figuras puede ser muy dificil/lento si es que usan las funciones de arriba :( asi que una forma es usando la funcion que se encuentra en el codigo de ejemplo:

```ino
void drawImage(byte image[][8], int rows) {
  for (int i=0; i<rows; i++) {
    for (int j=0; j<8; j++) {
      matrizLed.setRow(j, image[i][j]);
    }
    delay(500);
  }
}
```

Con esta funcion pueden crear imagenes usando esta pagina [link](https://xantorohara.github.io/led-matrix-editor/). En esta pagina crean un simbolo en la matriz y luego presionan **Insert** para agregar esa imagen a la animacion, luego en la derecha de la pagina seleccionan la opcion **As byte arrays** y copian el resultado para luego pegarlo en su codigo, asi luego basta con usar la funcion anterior asi:

```ino
drawImage(IMAGES, IMAGES_LEN);
```
