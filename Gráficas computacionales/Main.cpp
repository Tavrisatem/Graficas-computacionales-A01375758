/*//Luis Fernndo Espinosa Elizalde A01375758
//Graficas computacionales
//Tarea 1: Ejercicios simples para aprender C++
#include <iostream>
#include "Circle.h"
#include "Employee.h"

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

	Circle circulo;
	//Circle circulo2(2.0, "green");
	std::cout << circulo.GetRadius() << circulo.GetColor() << circulo.GetArea() << std::endl;
	Employee empleado(13, "Luis", "Espinosa", 50000);
	
	std::cout << empleado.GetFirstName() << std::endl;
	std::cout << empleado.GetLastName() << std::endl;
	std::cout << empleado.GetName() << std::endl;
	std::cout << empleado.GetID() << std::endl;
	std::cout << empleado.GetSalary() << std::endl;
	std::cout << empleado.GetAnualSalary() << std::endl;
	std::cout << empleado.RaiseSalary(50) << std::endl;
	std::cout << empleado.Print() << std::endl;

	std::cin.get(); //Espera señal para cerrar consola
	return 0;
}*/

//Identificador del manager al que vamos a asociar todos los VBOs
//GLuint vao;

//Identificador del manager de los shaders (shaderProgram)
//GLuint shaderProgram;

//float vertsPerframe = 0.0f;
//float delta = 0.01f;
/*

//Posiciones Circulo
//positions.push_back(glm::vec2(0, 0));
//for (int i = 0; i <= 360; i++) {
//	positions.push_back(glm::vec2(glm::cos(glm::radians((float) i)), glm::sin(glm::radians((float) i))));
//}

//Colores Circulo
//colors.push_back(glm::vec3(1.0f, 1.0f, 1.0f));
//for (int i = 0; i <= 360; i++) {
//colors.push_back(glm::vec3(glm::cos(glm::radians((float)i)), glm::sin(glm::radians((float)i)), 0.0f));
//}

//Queremos generar 1 manager
glGenVertexArrays(1, &vao);
//Utilizar el vao. Apartir de este momento, todos los VBOs creados y configurados se van a asociar a este manager
glBindVertexArray(vao);

//Identificador de VBO de posiciones
GLuint positionsVBO;
//Creacion de VBO de posiciones
glGenBuffers(1, &positionsVBO);
//Activamos el buffer de posiciones para poder utilizarlo
glBindBuffer(GL_ARRAY_BUFFER, positionsVBO);
//Creamos la memoria y la inicializamos con los datos del atributo de posiciones
glBufferData(GL_ARRAY_BUFFER, sizeof(glm::vec2)*positions.size(), positions.data(), GL_STATIC_DRAW);
// Activamos el atributo en l tarjeta de video
glEnableVertexAttribArray(0);
// Configuramos los datos del atributo en la target de video
glVertexAttribPointer(0, 2, GL_FLOAT, GL_FALSE, 0, nullptr);
// Ya no vamos a utilizar este VBO en este  momento.
glBindBuffer(GL_ARRAY_BUFFER, 0);

GLuint colorsVBO;
glGenBuffers(1, &colorsVBO);
glBindBuffer(GL_ARRAY_BUFFER, colorsVBO);
glBufferData(GL_ARRAY_BUFFER, sizeof(glm::vec3)*colors.size(), colors.data(), GL_STATIC_DRAW);
glEnableVertexAttribArray(1);
glVertexAttribPointer(1, 3, GL_FLOAT, GL_FALSE, 0, nullptr);
glBindBuffer(GL_ARRAY_BUFFER, 0);

//Desactivamos el manager.
glBindVertexArray(0);

InputFile ifile;
//VERTEX SHADER
//Leemos el archivo Default.vert donde está el código del vertex shader.
ifile.Read("Default.vert");
//Obtenemos el código fuente y lo guardamos en un string.
std::string vertexSource = ifile.GetContents();
//Creamos un shader de tipo vertex guardamos su identificador en una variable.
GLuint vertexShaderHandle = glCreateShader(GL_VERTEX_SHADER);
//Obtener los datos en el formato correcto
const GLchar *vertexSource_c = (const GLchar*)vertexSource.c_str();
//Le estamos dando el código fuente a OpenGl para que se lo asigne al shader
glShaderSource(vertexShaderHandle, 1, &vertexSource_c, nullptr);
//Compilams el shader en busca de errores.
//Vamos a asumir que no hay ningún error.
glCompileShader(vertexShaderHandle);

ifile.Read("Default.frag");
std::string fragmentSource = ifile.GetContents();
GLuint fragmentShaderHandle = glCreateShader(GL_FRAGMENT_SHADER);
const GLchar *fragmentSource_c = (const GLchar*)fragmentSource.c_str();
glShaderSource(fragmentShaderHandle, 1, &fragmentSource_c, nullptr);
glCompileShader(fragmentShaderHandle);

//Creamos el identificador para el manager de los shader.
shaderProgram = glCreateProgram();
//Adjuntamos el vertex shader al manager (van a trabajar juntos)
glAttachShader(shaderProgram, vertexShaderHandle);
//Adjuntamos el fragment shader al manager (van a trabajar juntos)
glAttachShader(shaderProgram, fragmentShaderHandle);
//Asociamos un buffer con índice 0 (posiciones) a la variable VertexPosition
glBindAttribLocation(shaderProgram, 0, "VertexPosition");
//Asociamos un buffer con índice 1 (colores) a la variable VertexColor
glBindAttribLocation(shaderProgram, 1, "VertexColor");
//Ejecutamos el proceso de linker (asegurarnos que el vertex y fragment son compatibles)
glLinkProgram(shaderProgram);

//Para configurar un uniform tenemosque decirle a OPENGL que vamos a utilizar el shader program (manager)
//glUseProgram(shaderProgram);
//GLint uniformLocation = glGetUniformLocation(shaderProgram, "Resolution");
//glUniform2f(uniformLocation, 400.0f, 400.0f);
//glUseProgram(0);


Game loop

//WARNING!!!! Esto es OpenGL viejito. Solamente lo vamos a ocupar esta clase.
//Prohibido el resto del sementre.
//glBegin(GL_TRIANGLES);
//glColor3f(1.0f, 0.0f, 0.0f);
//glVertex2f(-1.0f,-1.0f);
//glColor3f(0.0f, 1.0f, 0.0f);
//glVertex2f(1.0f, -1.0f);
//glColor3f(0.0f, 0.0f, 1.0f);
//glVertex2f(0.0f, 1.0f);
//glEnd();

//vertsPerframe += delta;
//if (vertsPerframe < 0.0f || vertsPerframe >= 370.0f)
//delta *= -1.0f;

// Activamos el vertex shader y el fragment shader utilizando el manager
glUseProgram(shaderProgram);
//Activamos el manager y en este momento se activan todos los VBOs asociados automáticamente.
glBindVertexArray(vao);
//Función de dibujado sin índices
glDrawArrays(GL_TRIANGLE_STRIP, 0, 12);
//glDrawArrays(GL_TRIANGLE_FAN, 0, glm::clamp(vertsPerframe, 0.0f, 362.0f)); //circulo
//Terminamos de utilizar el manager
glBindVertexArray(0);
//Desactivamos el manager
glUseProgram(0);
*/

#include <GL/glew.h>
#include <GL/freeglut.h>
#include <iostream>
#include <glm/glm.hpp>
#include <vector>
#include "Mesh.h"
#include "ShaderProgram.h"
#include "Transform.h"
#include "Camara.h"

Mesh _mesh;
ShaderProgram _shaderProgram;
Transform _transform;
Camara _camara;

void Initialize() {
	//Creando toda la memoria que el programa va a utilizar

	//Creación del atributo de posiciones de estos vertices. Lista de vec2.
	//Claramente en CPU y RAM
	std::vector<glm::vec2> positions;
	for (int i = 0; i <= 5; i++) {
		float par = i * 72.0f;
		positions.push_back(glm::vec2(glm::cos(glm::radians(378.0f - par)), glm::sin(glm::radians(378.0f - par))));
		positions.push_back(glm::vec2(glm::cos(glm::radians(378.0f - par)) * 0.5f, glm::sin(glm::radians(378.0f - par)) * 0.5f));
	}

	std::vector<glm::vec3> colors;
	for (int i = 0; i < 12; i++) {
		colors.push_back(glm::vec3(1.0f, 0.0f, 0.0f));
	}

	_mesh.CreateMesh(12);
	_mesh.SetPositionAttribute(positions, GL_STATIC_DRAW, 0);
	_mesh.SetColorAttribute(colors, GL_STATIC_DRAW, 1);

	_shaderProgram.CreateProgram();
	_shaderProgram.SetAttribute(0, "VertexPosition");
	_shaderProgram.SetAttribute(1, "VertexColor");
	_shaderProgram.AttachShader("Default.vert", GL_VERTEX_SHADER);
	_shaderProgram.AttachShader("Default.frag", GL_FRAGMENT_SHADER);
	_shaderProgram.LinkProgram();

	//_transform.SetRotation(0.0f, 0.0f, 90.0f);

	_camara.SetOrthographic(2.0f, 1.0f);
}

void GameLoop() {
	//Limpimos el buffer de color y el buffer de profundidad. Siempre hacerlo al inicio del frame.
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);


	//_camara.MoveForward(0.001f);
	_transform.Rotate(0.0f, 0.05f, 0.0f, false);

	_shaderProgram.Activate();
	//_shaderProgram.SetUniformMatrix("modelMatrix", _transform.GetModelMatrix());
	_shaderProgram.SetUniformMatrix("mvpMatrix", _camara.GetViewProjection() * _transform.GetModelMatrix());
	_mesh.Draw(GL_TRIANGLE_STRIP);
	_shaderProgram.Deactivate();

	//Cuando terminamos de renderear, cambiamos los buffers.
	glutSwapBuffers();
}

void Idle(){
	//Cuando OpenGl entre en modo de reposo (para guardar bateria, por ejemplo) le decimos qu vuelva a dibujar
	//Vuelve a mandar a llamar Gameloop
	glutPostRedisplay();
}

void ReshapeWindow(int width, int height) {
	glViewport(0, 0, width, height);
	//Para configurar un uniform tenemosque decirle a OPENGL que vamos a utilizar el shader program (manager)
	//glUseProgram(shaderProgram);
	//GLint uniformLocation = glGetUniformLocation(shaderProgram, "Resolution");
	//glUniform2f(uniformLocation, width, height);
	//glUseProgram(0);
}

int main(int argc, char* argv[]) {
	//Iniciar fleegut
	//Freeglut se encarga de crear ventanas
	// en donde podemos dibujar
	glutInit(&argc, argv);
	//Solicitando una versión específica de OpenGL
	glutInitContextVersion(4, 2);
	//Iniciar el contexto de OpenGL. El contexto se refiere a las capacidades que va a tener nuestra aplicación gráfica.
	//En este caso estamos trabajando con el pipeline clasico.
	//glutInitContextProfile(GLUT_COMPATIBILITY_PROFILE);///
	//En este caso estamos trabajando con el pipeline PROGRAMABLE.
	glutInitContextProfile(GLUT_CORE_PROFILE);
	//Freeglut nos permite configurar eventos que ocurren en la ventana.
	//Un evento que nos interesa es cuando alguien cierra la ventana.
	//En este caso, dejamos de renderear la escena y terminamos el programa.
	glutSetOption(GLUT_ACTION_ON_WINDOW_CLOSE, GLUT_ACTION_GLUTMAINLOOP_RETURNS);
	//Configuramos el frame buffer . En este caso estamos solicitando un buffer true color RGBA, un buffer de profundidad
	//y un segundo buffer para renderear.
	glutInitDisplayMode(GLUT_RGBA | GLUT_DEPTH | GLUT_DOUBLE);
	//Imiciar las dimensiones de la ventana (en pixeles)
	glutInitWindowSize(400, 400);
	//Creamos la ventana y le damos un titulo
	glutCreateWindow("Hello world GL");
	//Asociamos una funcion de render. Esta funcion se llamara para dibujar un frame.
	glutDisplayFunc(GameLoop);

	//Asociamos una función para el cambio de la ventana.  Freeglut la va a mandar a llamar cuando alguien cambie el tamaño de la ventana.
	glutReshapeFunc(ReshapeWindow);
	//Asociamos la función que mandará a llamar cuando OpenGL entre modo de reposo.
	glutIdleFunc(Idle);
	//Inicializamos GLEW. Esta libreria se encarga de obtener el API de OpenGL de nuestra targeta de video.
	//Shame on you Microsoft
	glewInit();
	//Configurar OpenGL. Este es el color por default del buffer de color en el framebuffer.
	glClearColor(1.0f, 1.0f, 0.5f, 1.0f);

	glEnable(GL_DEPTH_TEST);
	//Activamos el borrado de caras traseras. Ahora todos los triangulos que dibujemos deben de estar CCW
	glEnable(GL_CULL_FACE);
	//No dibujar las caras traseras de la geometría
	glCullFace(GL_BACK);

	std::cout << glGetString(GL_VERSION) << std::endl;

	//Configuración inicial de nuetro programa. 
	Initialize();

	//Iniciar la aplicacion. El main se pausara 
	glutMainLoop();


	return 0;
}


/*
//Luis Fernndo Espinosa Elizalde A01375758
//Graficas computacionales
//Tarea 2: Ejercicios de lectura de archivos C++
//Librerias
#include <iostream>
#include <string>
//Headders: InputFiles.h
#include "InputFile.h"


//Metodo principal
int main(int argc, char* argv[])
{
	std::string filename = "Prueba.txt"; //Prueba.txt
	InputFile myFile; //Archivo que se va a abrir
	myFile.Read(filename); //Llama la funcion que lee un archivo de texto
	std::string contents = myFile.GetContents(); //Cargar los datos del contenido del archivo Pruebas.txt en un string
	std::cout << "Contents: " << contents; //Imprimir datos en pantalla
	myFile.Read("Error.txt"); //Llama la funcion que lee un archivo de texto
	//Probar un caso de ERROR
	contents = myFile.GetContents(); //Cargar los datos del contenido del archivo Error.txt en un string, va a regresar una cadena vacia
	std::cout << "Contents: " << contents; //Imprimir datos en pantalla
	std::cin.get(); //Esperar input para terminar
	return 0; //Terminar funcion principal
}*/