//Luis Fernndo Espinosa Elizalde A01375758
//Graficas computacionales
//Tarea 1: Ejercicios simples para aprender C++
#include <iostream>

//Metodo para sacar perimetro de rectangulo con formula 2*base + 2*altura, regresa un valor entero
int PerimetroRectangulo(int base, int altura) {
	//Definicion de variables igual a C# (tipo nombre de variable = valorVariable)
	int perimetro = 2 * base + 2 * altura;
	return perimetro; //regreso de variable entera
}

//Metodo para sacar area de triangulo con formula (base*altura)/2, regresa un valor flotante
float AreaTriangulo(float base, float altura) {
	float area = (base * altura) / 2;
	return area; //regreso de variable flotante
}

//Metodo que regresa el mayor de tres numeros, se implementa la funcion "if"
int Mayor(int numero1, int numero2, int numero3) {
	if (numero1 > numero2) { //Empezar a comparar el primer numero con el segundo numero
		//El primer es mayor al segundo numero
		if (numero1 > numero3) { //Comprar el primer numero con el tercer numero
			return numero1; //El primer numero es mayor al tercer numero, por lo tanto este se regresa
		}
		else {
			return numero3; //El tercer numero es mayor al primer numero, por ende este es el mayor y se debe regresar
		}
	}
	//El primer no es mayor al segundo numero
	else {
		if (numero2 > numero3) { //Comparar el segundo numero con el tercero
			return numero2; //El segundo numero es mayor al tercer numero, este se regresa
		}
		else {
			return numero3; //El tercer numero es mayor al segundo, por eso este se regresa
		}
	}
}

//Metodo que regresa el menor de tres numeros, se implementa la funcion "if"
int Menor(int numero1, int numero2, int numero3) {
	if (numero1 < numero2) { //Empezar a comparar el primer numero con el segundo numero
							 //El primer es mmenor al segundo numero
		if (numero1 < numero3) { //Comprar el primer numero con el tercer numero
			return numero1; //El primer numero es menor al tercer numero, por lo tanto este se regresa
		}
		else {
			return numero3; //El tercer numero es menor al primer numero, este se regresa
		}
	}
	//El primer es mayor al segundo numero
	else {
		if (numero2 < numero3) { //Comparar el segundo numero con el tercero
			return numero2; //El segundo numero es menor al tercer numero, este se regresa
		}
		else {
			return numero3; //El tercer numero es menor al segundo, por eso este se regresa
		}
	}
}

//Metodo que imprime el numero de estrellitas que se pide. Utiliza la funcion "for"
void FilaEstrellas(int n) {
	for (int i = 0; i < n; i++) { //Funcion for
		std::cout << "*"; //Funcion para imprimir en consola
	}
	std::cout << "\n\n"; //Espacio en consola para diferenciar metodos
}

//Metodo que imprime el numero de estrellitas que se pide en forma de matriz. Utiliza la funcion "for" y "while"
void MatrizEstrellas(int n) {
	int loop = n; //Contador del loop, va a llegr a 0
	while (loop > 0) {
		for (int i = 0; i < n; i++) { //Funcion for
			std::cout << "*"; //Funcion para imprimir en consola
		}
		std::cout << "\n"; //Siguiente linea
		loop--; //Reduce loop
	}
	std::cout << "\n"; //Espacio en consola para diferenciar metodos
}

void PiramideEstrellas(int n) {
	int loop = 0; //Contador del loop, va a llegar a n+1
	while (loop < n) {
		for (int i = 0; i <= loop; i++) { //Funcion for
			std::cout << "*"; //Funcion para imprimir en consola
		}
		std::cout << "\n"; //Siguiente linea
		loop++; //Aumenta loop
	}
	std::cout << "\n"; //Espacio en consola para diferenciar metodos
}

//Metodo que cre una flecha del tamaño que se envie por número.
void FlechaEstrellas(int n) {
	int loop = 0; //Contador del loop, va a llegar a n
	int i;
	while (loop < n-1) {
		for (i = 0; i <= loop; i++) { //Funcion for
			std::cout << "*"; //Funcion para imprimir en consola
		}
		//Siguiente linea
		std::cout << "\n";
		loop++; //Aumenta loop
	}
	for (int i = 0; i <= loop; i++) { //Funcion for
		std::cout << "*"; //Funcion para imprimir en consola
	}
	std::cout << "\n"; //Siguiente linea
	//Ahora toca ir de regreso
	while (loop > 0) {
		for (int i = 0; i < loop; i++) { //Funcion for
			std::cout << "*"; //Funcion para imprimir en consola
		}
		std::cout << "\n"; //Siguiente linea
		loop--; //Reduce loop
	}
	std::cout << "\n"; //Espacio en consola para diferenciar metodos
}

//Metodo que imprime en console la serie de fibonancci del numero que se envie.
void Fibonacci(int n) {
	std::cout << "Fibonancci de " << n << ": ";
	int f0 = 0; //Numero previo
	int f1 = 1; //Numero base
	for (int i = 0; i < n; i++) { //Se repite n veces
		if (i == 0) { //La primera vez no hay suma
			std::cout << f1 << " ";
		}
		else { //La segunda ya empieza a suma
			int temp = f1;
			f1 = f1 + f0;
			f0 = temp;
			std::cout << f1 << " ";
		}
	}
	std::cout << "\n\n"; //Espacio en consola para diferenciar metodos
}

//Metodo que dice si un número es primo o no
bool EsPrimo(int numero) {
	for (int i = 2; i < numero; i++) { //Busca un factor divisor
		if (numero % i == 0) { //Si lo encuentra no es primo
			return false;
		}
	}
	return true; //Si no encuentra factor divisor, entonces es primo
}

//Metodo principal para probar otro metodos
int main() {
	int p = PerimetroRectangulo(5, 3); //Llamado de método y asignación de valor regresado por método a variable, el tipo de variable del metodo debe ser igual al tipo de variable creada
	float a = AreaTriangulo(5.0f, 3.0f); //Asignación de area producida por método a variable de tipo flotante.
	int mayor = Mayor(5, 9, 1); //Probar metodo Mayor y asignar variable.
	int menor = Menor(5, 9, 1); //Probar el metodo Menor y asignar variable
	std::cout << "Resultado de perimetro rectangulo de base 5 y altura 3: " << p << "\n\nResultado area triangulo de base 5 y altura 3: " << a << "\n\nResultado numero mayor de 5, 9, 1: " << mayor << "\n\nResultado numero menor de 5, 9, 1: " << menor << "\n\n"; //Imprimir valores en consola,  ya que printf no es un estandar valido e C++, los diferentes valores se separan por un <<
	FilaEstrellas(5); //Llama la función, no regresa nada
	MatrizEstrellas(4); //Llama la función, no regresa nada
	PiramideEstrellas(6); //Llama la función, no regresa nada
	FlechaEstrellas(3); //Llama la función, no regresa nada
	Fibonacci(9); //Llama la función, no regresa nada
	bool primo = EsPrimo(79); //Llama la función, regresa tru o false
	std::cout << "Resultado de si es primo: " << primo << "\n\n"; //Imprime variable primo, 1 es true y 0 es false
	primo = EsPrimo(52); //Llama la función, regresa tru o false
	std::cout << "Resultado de si es primo: " <<  primo << "\n\n"; //Imprime variable primo, 1 es true y 0 es false
	std::cin.get(); //Espera señal para cerrar consola
	return 0;
}