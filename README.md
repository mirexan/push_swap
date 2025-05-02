# push_swap

# Índice
- [Enunciado](#Enunciado)
- [¿Cómo lo he hecho?](#¿Cómo-lo-he-hecho?)
  - [Recopilar ingredientes](#Recopilar-ingredientes)
  - [Procesar argumentos](#Procesar-argumentos)
  - [Funciones de movimiento](#Funciones-de-movimiento)

## Enunciado

Hay que crear un programa que reciba una serie de números y que los ordene utilizando dos pilas mediante un algoritmo de ordenamiento.

![image](https://github.com/user-attachments/assets/c67b8367-03e5-427d-9d97-9772925da724)

1. Se tiene que entregar un Makefile que compile tus archivos fuente. No debe hacer relink. (Es decir, si un objeto o funcion no ha sido modificada, no deberia volver a compilarla cada vez que se llame a make  gracias a `clang $(CFLAGS) -c $< -o $@`.
2. Las variables globales están prohibidas.
3. Tenemos dos stacks, llamados stack_a y stack_b.
4. Mi programa push_swap  **recibe como argumento en el stack_a una lista de enteros.** **El primer argumento debe ser el que queda encima del stack.**
5. Primero :
    1. El **stack a contiene** una **cantidad aleatoria** de **números** positivos y/o negativos, no duplicados.
    2. El **stack b** está **vacío.**

6.  Si **no** se especifican **parámetros**, el programa no debe **mostrar nada** y debe **devolver** el **control al usuario**.
<aside>


> 🚨 **En caso de error** , debe **mostar “Error”** seguido de **\n en** la **salida de errores estándar (stderr).** **Posibles errores:** **Argumentos** que **no** son **enteros**, **superiores a** un número **entero** **y/o** números **duplicados**.

</aside>

El objetivo es **ordenar el stack en orden ascendente, con el mínimo número de operaciones** posible. Durante la evaluación se compara el número de instrucciones obtenido por nuestro programa con un rango de instrucciones máximo.

El ordenamiento se debe realizar mediante las siguientes ordenes (deben separarse mediant \n) :
- **SA (swap a)**: **Intercambia**r los dos **primeros elementos** de **stack a**. (No hace nada si hay 1 o menos elementos)
- **SB (swap b):** Intercambiar los dos **primeros elementos** de **stack b**. (No hace nada si hay 1 o menos elementos)
- **SS (swap a y swap b a la vez)**
- **PA (push a)** : Toma el **primer elemento del stack b** y **lo pone el primero** de **stack** **a.**(No hace nada si b está vacio)
- **PB (push b)**:  Toma el **primer elemento del stack a** y **lo pone el primero** de **stack** b**.**(No hace nada si a está vacio)
- **RA** (**rotate a)**: **Desplaza hacia arriba** todos los **elementos del stack_a una posicion**. De forma que el primer elemento se convierte el ultimo (y el segundo en primero).
- **RB** (**rotate b)**: **Desplaza hacia arriba** todos los **elementos del stack b** **una posicion**. De forma que el primer elemento se convierte el ultimo (y el segundo en primero).
- **RR : ra** y **rb** a la vez.
- **RRA (reverse rotate a)** : **Desplaza** hacia **abajo todos los elemento**s del **stack a una posición**, de forma que el último elemento se convierte en el primero.
- **RRB (reverse rotate b)** : **Desplaza hacia abajo** todos los **elementos del stack b** **una posición**, de forma que el último elemento se convierte en el primero.
- **RRR**  **rra** y **rrb** a la vez.

![Repositorio](https://github.com/user-attachments/assets/d31722f5-f1f7-4ac5-990d-c4a6e07b0d18)





## ¿Cómo lo he hecho?

### Recopilar ingredientes

Primero de todo me dediqué a recopilar los ingredientes de los anteriores proyectos que tenia permitido utilizar. En este caso varias funciones de libft y el ft_printf entero. 

- En el directorio **SRCS_LIBT** se encuentran algunas funciones del proyecto libft y su bonus, así mismo es dónde he ido colocando las funciones que he creado para los movimientos de los stacks y las liberaciones de memoria.
- ft_printf contiene directamente la version entregada del proyecto (disponible en otro de mis repositorios).
- Ambos directorios tienen su archivo .h que van asociados a un push_swap.h en la raiz. Así que cada vez que he hecho una funcion solo he hecho un include a push_swap.h.

captura de push_swap.h :
![Screenshot from 2025-05-02 18-26-27](https://github.com/user-attachments/assets/d27f8b31-395d-4a36-a6e4-429fd3ff357e)

### Procesar argumentos

Una vez agrupados los ingredientes decidí hacer el mainps.c para poder ir comprobando cada paso realizado. Cuando cree el main, me di cuenta de que tenia que crear una funcion que procesase los argumentos. Ya sea para **comprobar los errores**, **si son numeros**, **si estan duplicados** o **si se pasan como una sola string**. Asi que cree la funcion ft_treat_args, que junto con el main tiene en cuenta el manejo de errores (devolviendo NULL) y detecta si stack_a se va a llenar directamente con los argmentos o requiere un split .

Dentro de la funcion ft_treat_args.c me encontre con la necesidad de crear una funcion llamada ft_add_to_stack.c. Que lo que hace es crear un nodo que guarde un valor num y que quede en la ultima posicion de la lista.

### Funciones de movimiento

Una vez creada la stack_a con sus nodos pensé que lo lógico seria implementar las funciones que permitan realizar los movimientos del enunciado. Por ello, inicialmente solo cree las funciones con los movimientos en sí, por eso se llaman ft_push.c o ft_swap.c. Tras crearlas y comprobar que funcionan con el main, pasé a crear la version definitiva que con su llamamiento hace el movimiento e imprime su nombre con salto de linea.

Ejemplo:
```
#include "push_swap.h"

//Parte de movimiento especifico

void	pa(t_stack **stack_b, t_stack **stack_a)
{
	ft_push(stack_b, stack_a);
	ft_printf("pa\n");
}

void	pb(t_stack **stack_a, t_stack **stack_b)
{
	ft_push(stack_a, stack_b);
	ft_printf("pb\n");
}

// Parte general

void	ft_push(t_stack **taker, t_stack **receiver)
{
	t_stack	*newnode;

	if (!*taker)
		return ;
	newnode = *taker;
	*taker = (*taker)->next;
	newnode->next = *receiver;
	*receiver = newnode;
}
```

