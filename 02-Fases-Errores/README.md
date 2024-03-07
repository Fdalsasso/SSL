#### 1.b El archivo Hello2.i  contiene todas las declaraciones de las funciones de la libreria <stdio.h>, ademas, los comentarios realizados en el archivo Hello2.c fueron reemplazados por espacios
#### 1.d int printf(const char * restrict s, ...); es una funcion que devuelve un valor entero y espero al menos un parametro, el cual es un puntero de tipo char inmutable. Restrict lo que hace esa darle la informacion de que dicho puntero apunta a un objeto y es el unico q cumple esta funcion, lo que le permite optimizar como el compilador considere
#### 1.e No existe diferencia alguna entre ambos archivos excepto los comentarios que agrega el preprocesador
#### 2.c En el bloque .LC0 prepara las constantes que sera utilizadas en este programa y hace movimientos en la pila para llamar a las funciones. Las primeras instrucciones de main son para "preparar" la pila para posterior llamado de "prontf", luego, se hace un llamado a la funcion "prontf" y el codigo asume un retorno del llamado, para finalmente mover un cero al acumulador y finalizar el programa.
#### 3.a Me genera un error de linker por el "prontf"
#### 3.c Al ejecutar el codigo no me genera el resultado esperado ya que el puntero del printf nunca fue definido/asignado, entonces la funcion nos devuelve un puntero aleatorio
#### 5.b Esto funciona porque el gcc detecta una declaracion implicita de printf, entonces, al estar declarado el printf, pero sin saber que procedimiento seguir, el compilador recomienda incluir la biblioteca "stdio.h" para compilar el codigo y linkea el built-in del printf para que nuestro ejecutable funcione
#### 6.c Si se elimina algun argumento, el comportamiento del programa seria como el de hello5, mientras que si se agregan argumentos funcionaria como se espera. En ambos casos se generan advertencias de declaraciones implicitas
#### 6.d La ventaja de incluir el contrato en los clientes es que les brindamos un "manual de usuario" de como utilizar las funciones. Mientras que al incluirlo en el proveedor podemos verificar que entregamos el producto correcto

Informacion del trabajo:

https://josemariasola.github.io/ssl/assignments/2021/Ssl%20Assignments.pdf#page=27