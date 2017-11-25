/*********************************************************

Materia: Graficas Computacionales

Fecha: 24 de noviembre de 2017

Autor: A01375758 Luis Fernando Espinosa Elizalde
A01375640 Brandon Alain Cruz Ruiz

*********************************************************/

#include <GL/glew.h>
#include <GL/freeglut.h>
#include <iostream>
#include <glm/glm.hpp>
#include <vector>
#include <IL/il.h>
#include "Mesh.h"
#include "ShaderProgram.h"
#include "Transform.h"
#include "Camara.h"
#include "Texture2D.h"
#include "Dephtbuffer.h"

Mesh _mesh, _meshDedos, _meshPulgar, _meshPiso;
ShaderProgram _shaderProgram;
ShaderProgram _shaderPuerco;
ShaderProgram _shaderDepth;
Transform _geometriaPalma;
Transform _geometriaPiso;
Transform _geometriaIndice;
Transform _geometriaMedio;
Transform _geometriaMenique;
Transform _geometriaIndiceArriba;
Transform _geometriaMedioArriba;
Transform _geometriaMeniqueArriba;
Transform _geometriaPulgar;
Transform _geometriaPulgarArriba;
Transform _geometriaInvisibleIndice, _geometriaInvisibleIndiceArriba;
Transform _geometriaInvisibleMedio, _geometriaInvisibleMedioArriba;
Transform _geometriaInvisibleMenique, _geometriaInvisibleMeniqueArriba;
Transform _geometriaInvisiblePulgar, _geometriaInvisiblePulgarArriba;
Camara _camara;
Camara _camaraLuz;
Texture2D myTexture;
Texture2D myTexture2;
Texture2D myTexture3;
Dephtbuffer _depthbuffer;

float rotacionIndice = 0.05f, rotacionMedio = 0.04f, rotacionMenique = 0.03f, rotacionPulgar = 0.05f;

void Initialize() {
	//Creando toda la memoria que el programa va a utilizar

	//Creacin del atributo de posiciones de estos vertices. Lista de vec2.
	//Claramente en CPU y RAM
	std::vector<glm::vec3> positionsPiso, positions, positionsDedos, positionsPulgar;
	std::vector<glm::vec3> colors;
	std::vector<glm::vec3> normales;
	std::vector<glm::vec2> textures;

	//Cubo piso
	//Cara derecha
	positionsPiso.push_back(glm::vec3(3.0f, 0, 3.0f));  //Esquina inferior derecha trasera => 0
	positionsPiso.push_back(glm::vec3(3.0f, 0, -3.0f)); //Esquina superior derecha trasera => 1
	positionsPiso.push_back(glm::vec3(3.0f, 6.0f, -3.0f)); //Esquina superior derecha delantera => 2
	positionsPiso.push_back(glm::vec3(3.0f, 6.0f, 3.0f)); //Esquina inferior derecha delantera => 3, conecta triangulo con 0 y 2
														  //Cara de enfrente
	positionsPiso.push_back(glm::vec3(-3.0f, 0, 3.0f)); //Esquina inferior izquierda delantera => 4
	positionsPiso.push_back(glm::vec3(3.0f, 0, 3.0f)); //Esquina inferior derecha delantera => 5
	positionsPiso.push_back(glm::vec3(3.0f, 6.0f, 3.0f)); //Esquina superior derecha delantera => 6
	positionsPiso.push_back(glm::vec3(-3.0f, 6.0f, 3.0f)); //Esquina superior izquierda delantera => 7, conecta triangulo con 4 y 6
														   //Cara izquierda
	positionsPiso.push_back(glm::vec3(-3.0f, 0, -3.0f)); //Esquina inferior izquierda trasera => 8
	positionsPiso.push_back(glm::vec3(-3.0f, 0, 3.0f)); //Esquina inferior izquierda delantera => 9
	positionsPiso.push_back(glm::vec3(-3.0f, 6.0f, 3.0f)); //Esquina superior izquierda delantera => 10
	positionsPiso.push_back(glm::vec3(-3.0f, 6.0f, -3.0f)); //Esquina superior izquierda trasera => 11, conecta triangulo con 8 y 10
															//Cara de atras
	positionsPiso.push_back(glm::vec3(3.0f, 0, -3.0f));  //Esquina inferior derecha trasera => 12
	positionsPiso.push_back(glm::vec3(-3.0f, 0, -3.0f)); //Esquina inferior izquierda trasera => 13
	positionsPiso.push_back(glm::vec3(-3.0f, 6.0f, -3.0f)); //Esquina superior izquierda trasera => 14
	positionsPiso.push_back(glm::vec3(3.0f, 6.0f, -3.0f)); //Esquina superior derecha trasera => 15,conecta triangilo con 12 y 14
														   //Cara de abajo
	positionsPiso.push_back(glm::vec3(3.0f, 0, 3.0f)); //Esquina inferior derecha delantera => 16
	positionsPiso.push_back(glm::vec3(-3.0f, 0, 3.0f)); //Esquina inferior izquierda delantera => 17
	positionsPiso.push_back(glm::vec3(-3.0f, 0, -3.0f)); //Esquina inferior izquierda trasera => 18
	positionsPiso.push_back(glm::vec3(3.0f, 0, -3.0f));  //Esquina inferior derecha trasera => 19, conecta trangulo con 16 y 18
														 //Cara de arriba
	positionsPiso.push_back(glm::vec3(3.0f, 6.0f, 3.0f)); //Esquina superior derecha delantera => 20
	positionsPiso.push_back(glm::vec3(-3.0f, 6.0f, -3.0f)); //Esquina superior izquierda trasera => 21
	positionsPiso.push_back(glm::vec3(-3.0f, 6.0f, 3.0f)); //Esquina superior izquierda delantera => 22
	positionsPiso.push_back(glm::vec3(3.0f, 6.0f, -3.0f)); //Esquina superior derecha trasera => 23,conecta triangulo con 20 y 2

														   //Posiciones Cubo  Palma
														   //Cara derecha
	positions.push_back(glm::vec3(2.0f, -1.0f, 0.25f));  //Esquina inferior derecha delantera => 0
	positions.push_back(glm::vec3(2.0f, -1.0f, -0.25f)); //Esquina inferior derecha trasera => 1
	positions.push_back(glm::vec3(2.0f, 3.0f, -0.25f)); //Esquina superior derecha trasera => 2
	positions.push_back(glm::vec3(2.0f, 3.0f, 0.25f)); //Esquina superrior derecha delantera => 3, conecta triangulo con 0 y 2
													   //Cara de enfrente
	positions.push_back(glm::vec3(-2.0f, -1.0f, 0.25f)); //Esquina inferior izquierda delantera => 4
	positions.push_back(glm::vec3(2.0f, -1.0f, 0.25f)); //Esquina inferior derecha delantera => 5
	positions.push_back(glm::vec3(2.0f, 3.0f, 0.25f)); //Esquina superior derecha delantera => 6
	positions.push_back(glm::vec3(-2.0f, 3.0f, 0.25f)); //Esquina superior izquierda delantera => 7, conecta triangulo con 4 y 6
														//Cara izquierda
	positions.push_back(glm::vec3(-2.0f, -1.0f, -0.25f)); //Esquina inferior izquierda trasera => 8
	positions.push_back(glm::vec3(-2.0f, -1.0f, 0.25f)); //Esquina inferior izquierda delantera => 9
	positions.push_back(glm::vec3(-2.0f, 3.0f, 0.25f)); //Esquina superior izquierda delantera => 10
	positions.push_back(glm::vec3(-2.0f, 3.0f, -0.25f)); //Esquina superior izquierda trasera => 11, conecta triangulo con 8 y 10
														 //Cara de atras
	positions.push_back(glm::vec3(2.0f, -1.0f, -0.25f));  //Esquina inferior derecha trasera => 12
	positions.push_back(glm::vec3(-2.0f, -1.0f, -0.25f)); //Esquina inferior izquierda trasera => 13
	positions.push_back(glm::vec3(-2.0f, 3.0f, -0.25f)); //Esquina superior izquierda trasera => 14
	positions.push_back(glm::vec3(2.0f, 3.0f, -0.25f)); //Esquina superior derecha trasera => 15,conecta triangilo con 12 y 14
														//Cara de abajo
	positions.push_back(glm::vec3(2.0f, -1.0f, 0.25f)); //Esquina inferior derecha delantera => 16
	positions.push_back(glm::vec3(-2.0f, -1.0f, 0.25f)); //Esquina inferior izquierda delantera => 17
	positions.push_back(glm::vec3(-2.0f, -1.0f, -0.25f)); //Esquina inferior izquierda trasera => 18
	positions.push_back(glm::vec3(2.0f, -1.0f, -0.25f));  //Esquina inferior derecha trasera => 19, conecta trangulo con 16 y 18
														  //Cara de arriba
	positions.push_back(glm::vec3(2.0f, 3.0f, 0.25f)); //Esquina superior derecha delantera => 20
	positions.push_back(glm::vec3(-2.0f, 3.0f, -0.25f)); //Esquina superior izquierda trasera => 21
	positions.push_back(glm::vec3(-2.0f, 3.0f, 0.25f)); //Esquina superior izquierda delantera => 22
	positions.push_back(glm::vec3(2.0f, 3.0f, -0.25f)); //Esquina superior derecha trasera => 23,conecta triangulo con 20 y 2

														//Posiciones Cubo Dedos
														//Cara derecha
	positionsDedos.push_back(glm::vec3(0.625f, 0, 0.25f));  //Esquina inferior derecha delantera => 0
	positionsDedos.push_back(glm::vec3(0.625f, 0, -0.25f)); //Esquina inferior derecha trasera => 1
	positionsDedos.push_back(glm::vec3(0.625f, 1.5f, -0.25f)); //Esquina superior derecha trasera => 2
	positionsDedos.push_back(glm::vec3(0.625f, 1.5f, 0.25f)); //Esquina superrior derecha delantera => 3, conecta triangulo con 0 y 2
															  //Cara de enfrente
	positionsDedos.push_back(glm::vec3(-0.625f, 0, 0.25f)); //Esquina inferior izquierda delantera => 4
	positionsDedos.push_back(glm::vec3(0.625f, 0, 0.25f)); //Esquina inferior derecha delantera => 5
	positionsDedos.push_back(glm::vec3(0.625f, 1.5f, 0.25f)); //Esquina superior derecha delantera => 6
	positionsDedos.push_back(glm::vec3(-0.625f, 1.5f, 0.25f)); //Esquina superior izquierda delantera => 7, conecta triangulo con 4 y 6
															   //Cara izquierda
	positionsDedos.push_back(glm::vec3(-0.625f, 0, -0.25f)); //Esquina inferior izquierda trasera => 8
	positionsDedos.push_back(glm::vec3(-0.625f, 0, 0.25f)); //Esquina inferior izquierda delantera => 9
	positionsDedos.push_back(glm::vec3(-0.625f, 1.5f, 0.25f)); //Esquina superior izquierda delantera => 10
	positionsDedos.push_back(glm::vec3(-0.625f, 1.5f, -0.25f)); //Esquina superior izquierda trasera => 11, conecta triangulo con 8 y 10
																//Cara de atras
	positionsDedos.push_back(glm::vec3(0.625f, 0, -0.25f));  //Esquina inferior derecha trasera => 12
	positionsDedos.push_back(glm::vec3(-0.625f, 0, -0.25f)); //Esquina inferior izquierda trasera => 13
	positionsDedos.push_back(glm::vec3(-0.625f, 1.5f, -0.25f)); //Esquina superior izquierda trasera => 14
	positionsDedos.push_back(glm::vec3(0.625f, 1.5f, -0.25f)); //Esquina superior derecha trasera => 15,conecta triangilo con 12 y 14
															   //Cara de abajo
	positionsDedos.push_back(glm::vec3(0.625f, 0, 0.25f)); //Esquina inferior derecha delantera => 16
	positionsDedos.push_back(glm::vec3(-0.625f, 0, 0.25f)); //Esquina inferior izquierda delantera => 17
	positionsDedos.push_back(glm::vec3(-0.625f, 0, -0.25f)); //Esquina inferior izquierda trasera => 18
	positionsDedos.push_back(glm::vec3(0.625f, 0, -0.25f));  //Esquina inferior derecha trasera => 19, conecta trangulo con 16 y 18
															 //Cara de arriba
	positionsDedos.push_back(glm::vec3(0.625f, 1.5f, 0.25f)); //Esquina superior derecha delantera => 20
	positionsDedos.push_back(glm::vec3(-0.625f, 1.5f, -0.25f)); //Esquina superior izquierda trasera => 21
	positionsDedos.push_back(glm::vec3(-0.625f, 1.5f, 0.25f)); //Esquina superior izquierda delantera => 22
	positionsDedos.push_back(glm::vec3(0.625f, 1.5f, -0.25f)); //Esquina superior derecha trasera => 23,conecta triangulo con 20 y 2


															   //Posiciones Cubo Pulgar
															   //Cara derecha
	positionsPulgar.push_back(glm::vec3(0.75f, 0, 0.25f));  //Esquina inferior derecha delantera => 0
	positionsPulgar.push_back(glm::vec3(0.75f, 0, -0.25f)); //Esquina inferior derecha trasera => 1
	positionsPulgar.push_back(glm::vec3(0.75f, 1.0f, -0.25f)); //Esquina superior derecha trasera => 2
	positionsPulgar.push_back(glm::vec3(0.75f, 1.0f, 0.25f)); //Esquina superrior derecha delantera => 3, conecta triangulo con 0 y 2
															  //Cara de enfrente
	positionsPulgar.push_back(glm::vec3(-0.75f, 0, 0.25f)); //Esquina inferior izquierda delantera => 4
	positionsPulgar.push_back(glm::vec3(0.75f, 0, 0.25f)); //Esquina inferior derecha delantera => 5
	positionsPulgar.push_back(glm::vec3(0.75f, 1.0f, 0.25f)); //Esquina superior derecha delantera => 6
	positionsPulgar.push_back(glm::vec3(-0.75f, 1.0f, 0.25f)); //Esquina superior izquierda delantera => 7, conecta triangulo con 4 y 6
															   //Cara izquierda
	positionsPulgar.push_back(glm::vec3(-0.75f, 0, -0.25f)); //Esquina inferior izquierda trasera => 8
	positionsPulgar.push_back(glm::vec3(-0.75f, 0, 0.25f)); //Esquina inferior izquierda delantera => 9
	positionsPulgar.push_back(glm::vec3(-0.75f, 1.0f, 0.25f)); //Esquina superior izquierda delantera => 10
	positionsPulgar.push_back(glm::vec3(-0.75f, 1.0f, -0.25f)); //Esquina superior izquierda trasera => 11, conecta triangulo con 8 y 10
																//Cara de atras
	positionsPulgar.push_back(glm::vec3(0.75f, 0, -0.25f));  //Esquina inferior derecha trasera => 12
	positionsPulgar.push_back(glm::vec3(-0.75f, 0, -0.25f)); //Esquina inferior izquierda trasera => 13
	positionsPulgar.push_back(glm::vec3(-0.75f, 1.0f, -0.25f)); //Esquina superior izquierda trasera => 14
	positionsPulgar.push_back(glm::vec3(0.75f, 1.0f, -0.25f)); //Esquina superior derecha trasera => 15,conecta triangilo con 12 y 14
															   //Cara de abajo
	positionsPulgar.push_back(glm::vec3(0.75f, 0, 0.25f)); //Esquina inferior derecha delantera => 16
	positionsPulgar.push_back(glm::vec3(-0.75f, 0, 0.25f)); //Esquina inferior izquierda delantera => 17
	positionsPulgar.push_back(glm::vec3(-0.75f, 0, -0.25f)); //Esquina inferior izquierda trasera => 18
	positionsPulgar.push_back(glm::vec3(0.75f, 0, -0.25f));  //Esquina inferior derecha trasera => 19, conecta trangulo con 16 y 18
															 //Cara de arriba
	positionsPulgar.push_back(glm::vec3(0.75f, 1.0f, 0.25f)); //Esquina superior derecha delantera => 20
	positionsPulgar.push_back(glm::vec3(-0.75f, 1.0f, -0.25f)); //Esquina superior izquierda trasera => 21
	positionsPulgar.push_back(glm::vec3(-0.75f, 1.0f, 0.25f)); //Esquina superior izquierda delantera => 22
	positionsPulgar.push_back(glm::vec3(0.75f, 1.0f, -0.25f)); //Esquina superior derecha trasera => 23,conecta triangulo con 20 y 2



															   //Colores Cubo
															   //Color cara 1
	colors.push_back(glm::vec3(1.0f, 0.0f, 0.0f));
	colors.push_back(glm::vec3(1.0f, 0.0f, 0.0f));
	colors.push_back(glm::vec3(1.0f, 0.0f, 0.0f));
	colors.push_back(glm::vec3(1.0f, 0.0f, 0.0f));
	//Color cara 2
	colors.push_back(glm::vec3(0.0f, 1.0f, 0.0f));
	colors.push_back(glm::vec3(0.0f, 1.0f, 0.0f));
	colors.push_back(glm::vec3(0.0f, 1.0f, 0.0f));
	colors.push_back(glm::vec3(0.0f, 1.0f, 0.0f));
	//Color cara 3
	colors.push_back(glm::vec3(0.0f, 0.0f, 1.0f));
	colors.push_back(glm::vec3(0.0f, 0.0f, 1.0f));
	colors.push_back(glm::vec3(0.0f, 0.0f, 1.0f));
	colors.push_back(glm::vec3(0.0f, 0.0f, 1.0f));
	//Color cara 4
	colors.push_back(glm::vec3(1.0f, 1.0f, 0.0f));
	colors.push_back(glm::vec3(1.0f, 1.0f, 0.0f));
	colors.push_back(glm::vec3(1.0f, 1.0f, 0.0f));
	colors.push_back(glm::vec3(1.0f, 1.0f, 0.0f));
	//Color cara 5
	colors.push_back(glm::vec3(1.0f, 0.0f, 1.0f));
	colors.push_back(glm::vec3(1.0f, 0.0f, 1.0f));
	colors.push_back(glm::vec3(1.0f, 0.0f, 1.0f));
	colors.push_back(glm::vec3(1.0f, 0.0f, 1.0f));
	//Color cara 6
	colors.push_back(glm::vec3(1.0f, 1.0f, 1.0f));
	colors.push_back(glm::vec3(1.0f, 1.0f, 1.0f));
	colors.push_back(glm::vec3(1.0f, 1.0f, 1.0f));
	colors.push_back(glm::vec3(1.0f, 1.0f, 1.0f));

	//Normales Cubo
	//Cara derecha
	normales.push_back(glm::vec3(1.0f, 0.0f, 0.0f));  //Esquina inferior derecha trasera => 0
	normales.push_back(glm::vec3(1.0f, 0.0f, 0.0f)); //Esquina superior derecha trasera => 1
	normales.push_back(glm::vec3(1.0f, 0.0f, 0.0f)); //Esquina superior derecha delantera => 2
	normales.push_back(glm::vec3(1.0f, 0.0f, 0.0f)); //Esquina inferior derecha delantera => 3, conecta triangulo con 0 y 2
													 //Cara de enfrente
	normales.push_back(glm::vec3(0.0f, 0.0f, 1.0f)); //Esquina inferior izquierda delantera => 4
	normales.push_back(glm::vec3(0.0f, 0.0f, 1.0f)); //Esquina inferior derecha delantera => 5
	normales.push_back(glm::vec3(0.0f, 0.0f, 1.0f)); //Esquina superior derecha delantera => 6
	normales.push_back(glm::vec3(0.0f, 0.0f, 1.0f)); //Esquina superior izquierda delantera => 7, conecta triangulo con 4 y 6
													 //Cara izquierda
	normales.push_back(glm::vec3(-1.0f, 0.0f, 0.0f)); //Esquina inferior izquierda trasera => 8
	normales.push_back(glm::vec3(-1.0f, 0.0f, 0.0f)); //Esquina inferior izquierda delantera => 9
	normales.push_back(glm::vec3(-1.0f, 0.0f, 0.0f)); //Esquina superior izquierda delantera => 10
	normales.push_back(glm::vec3(-1.0f, 0.0f, 0.0f)); //Esquina superior izquierda trasera => 11, conecta triangulo con 8 y 10
													  //Cara de atras
	normales.push_back(glm::vec3(0.0f, 0.0f, -1.0f));  //Esquina inferior derecha trasera => 12
	normales.push_back(glm::vec3(0.0f, 0.0f, -1.0f)); //Esquina inferior izquierda trasera => 13
	normales.push_back(glm::vec3(0.0f, 0.0f, -1.0f)); //Esquina superior izquierda trasera => 14
	normales.push_back(glm::vec3(0.0f, 0.0f, -1.0f)); //Esquina superior derecha trasera => 15,conecta triangilo con 12 y 14
													  //Cara de abajo
	normales.push_back(glm::vec3(0.0f, -1.0f, .0f)); //Esquina inferior derecha delantera => 16
	normales.push_back(glm::vec3(0.0f, -1.0f, .0f)); //Esquina inferior izquierda delantera => 17
	normales.push_back(glm::vec3(0.0f, -1.0f, .0f)); //Esquina inferior izquierda trasera => 18
	normales.push_back(glm::vec3(0.0f, -1.0f, .0f));  //Esquina inferior derecha trasera => 19, conecta trangulo con 16 y 18
													  //Cara de arriba
	normales.push_back(glm::vec3(0.0f, 1.0f, .0f)); //Esquina superior derecha delantera => 20
	normales.push_back(glm::vec3(0.0f, 1.0f, .0f)); //Esquina superior izquierda trasera => 21
	normales.push_back(glm::vec3(0.0f, 1.0f, .0f)); //Esquina superior izquierda delantera => 22
	normales.push_back(glm::vec3(0.0f, 1.0f, .0f)); //Esquina superior derecha trasera => 23,conecta triangulo con 20 y 2

													//Texturas Cubo
													//Cara derecha
	textures.push_back(glm::vec2(0.0f, 0.0f));  //Esquina inferior derecha trasera => 0
	textures.push_back(glm::vec2(1.0f, 0.0f)); //Esquina superior derecha trasera => 1
	textures.push_back(glm::vec2(1.0f, 1.0f)); //Esquina superior derecha delantera => 2
	textures.push_back(glm::vec2(0.0f, 1.0f)); //Esquina inferior derecha delantera => 3, conecta triangulo con 0 y 2
											   //Cara de enfrente
	textures.push_back(glm::vec2(0.0f, 0.0f)); //Esquina inferior izquierda delantera => 4
	textures.push_back(glm::vec2(1.0f, 0.0f)); //Esquina inferior derecha delantera => 5
	textures.push_back(glm::vec2(1.0f, 1.0f)); //Esquina superior derecha delantera => 6
	textures.push_back(glm::vec2(0.0f, 1.0f)); //Esquina superior izquierda delantera => 7, conecta triangulo con 4 y 6
											   //Cara izquierda
	textures.push_back(glm::vec2(0.0f, 0.0f)); //Esquina inferior izquierda trasera => 8
	textures.push_back(glm::vec2(1.0f, 0.0f)); //Esquina inferior izquierda delantera => 9
	textures.push_back(glm::vec2(1.0f, 1.0f)); //Esquina superior izquierda delantera => 10
	textures.push_back(glm::vec2(0.0f, 1.0f)); //Esquina superior izquierda trasera => 11, conecta triangulo con 8 y 10
											   //Cara de atras
	textures.push_back(glm::vec2(0.0f, 0.0f));  //Esquina inferior derecha trasera => 12
	textures.push_back(glm::vec2(1.0f, 0.0f)); //Esquina inferior izquierda trasera => 13
	textures.push_back(glm::vec2(1.0f, 1.0f)); //Esquina superior izquierda trasera => 14
	textures.push_back(glm::vec2(0.0f, 1.0f)); //Esquina superior derecha trasera => 15,conecta triangilo con 12 y 14
											   //Cara de abajo
	textures.push_back(glm::vec2(1.0f, 1.0f)); //Esquina inferior derecha delantera => 16
	textures.push_back(glm::vec2(0.0f, 1.0f)); //Esquina inferior izquierda delantera => 17
	textures.push_back(glm::vec2(0.0f, 0.0f)); //Esquina inferior izquierda trasera => 18
	textures.push_back(glm::vec2(1.0f, 0.0f));  //Esquina inferior derecha trasera => 19, conecta trangulo con 16 y 18
												//Cara de arriba
	textures.push_back(glm::vec2(1.0f, 0.0f)); //Esquina superior derecha delantera => 20
	textures.push_back(glm::vec2(0.0f, 1.0f)); //Esquina superior izquierda trasera => 21
	textures.push_back(glm::vec2(0.0f, 0.0f)); //Esquina superior izquierda delantera => 22
	textures.push_back(glm::vec2(1.0f, 1.0f)); //Esquina superior derecha trasera => 23,conecta triangulo con 20 y 2

											   //Se crea el vector con los ndices de las posiciones
	std::vector<unsigned int> indices = {
		0, 1, 2, 0, 2, 3, //Cara 1
		4, 5, 6, 4, 6, 7, //Cara 2
		8, 9, 10, 8, 10, 11, //Cara 3
		12, 13, 14, 12, 14, 15, //Cara 4
		16, 17, 18, 16, 18, 19, //Cara 5
		20, 21, 22, 20, 23, 21, //Cara 6
	};

	_mesh.CreateMesh(positions.size());
	_mesh.SetPositionAttribute(positions, GL_STATIC_DRAW, 0);
	_mesh.SetColorAttribute(colors, GL_STATIC_DRAW, 1);
	_mesh.SetNormalAttribute(normales, GL_STATIC_DRAW, 2);
	_mesh.SetTexCoordAttribute(textures, GL_STATIC_DRAW, 3);
	_mesh.SetIndices(indices, GL_STATIC_DRAW);

	_meshDedos.CreateMesh(positions.size());
	_meshDedos.SetPositionAttribute(positionsDedos, GL_STATIC_DRAW, 0);
	_meshDedos.SetColorAttribute(colors, GL_STATIC_DRAW, 1);
	_meshDedos.SetNormalAttribute(normales, GL_STATIC_DRAW, 2);
	_meshDedos.SetTexCoordAttribute(textures, GL_STATIC_DRAW, 3);
	_meshDedos.SetIndices(indices, GL_STATIC_DRAW);

	_meshPulgar.CreateMesh(positions.size());
	_meshPulgar.SetPositionAttribute(positionsPulgar, GL_STATIC_DRAW, 0);
	_meshPulgar.SetColorAttribute(colors, GL_STATIC_DRAW, 1);
	_meshPulgar.SetNormalAttribute(normales, GL_STATIC_DRAW, 2);
	_meshPulgar.SetTexCoordAttribute(textures, GL_STATIC_DRAW, 3);
	_meshPulgar.SetIndices(indices, GL_STATIC_DRAW);


	_meshPiso.CreateMesh(positionsPiso.size());
	_meshPiso.SetPositionAttribute(positionsPiso, GL_STATIC_DRAW, 0);
	_meshPiso.SetColorAttribute(colors, GL_STATIC_DRAW, 1);
	_meshPiso.SetNormalAttribute(normales, GL_STATIC_DRAW, 2);
	_meshPiso.SetTexCoordAttribute(textures, GL_STATIC_DRAW, 3);
	_meshPiso.SetIndices(indices, GL_STATIC_DRAW);


	_shaderDepth.CreateProgram();
	_shaderDepth.SetAttribute(0, "VertexPosition");
	_shaderDepth.AttachShader("Depth.vert", GL_VERTEX_SHADER);
	_shaderDepth.AttachShader("Depth.frag", GL_FRAGMENT_SHADER);
	_shaderDepth.LinkProgram();

	_shaderProgram.CreateProgram();
	_shaderProgram.SetAttribute(0, "VertexPosition");
	_shaderProgram.SetAttribute(1, "VertexColor");
	_shaderProgram.SetAttribute(2, "VertexNormal");
	_shaderProgram.SetAttribute(3, "VertexTexCoord");
	_shaderProgram.AttachShader("Shadow.vert", GL_VERTEX_SHADER);
	_shaderProgram.AttachShader("Shadow.frag", GL_FRAGMENT_SHADER);
	_shaderProgram.LinkProgram();

	_shaderProgram.Activate();
	_shaderProgram.SetUniformVector("LightColor", glm::vec3(1.0f, 1.0f, 1.0f));
	_shaderProgram.SetUniformVector("LightPosition", glm::vec3(-5.0f, 5.0f, 5.0f));
	_shaderProgram.SetUniformi("DiffuseTexture", 0);
	_shaderProgram.SetUniformi("ShadowMap", 1);
	_shaderProgram.Deactivate();

	_shaderPuerco.CreateProgram();
	_shaderPuerco.SetAttribute(0, "VertexPosition");
	_shaderPuerco.SetAttribute(1, "VertexColor");
	_shaderPuerco.SetAttribute(2, "VertexNormal");
	_shaderPuerco.SetAttribute(3, "VertexTexCoord");
	_shaderPuerco.AttachShader("ShadowPuerco.vert", GL_VERTEX_SHADER);
	_shaderPuerco.AttachShader("ShadowPuerco.frag", GL_FRAGMENT_SHADER);
	_shaderPuerco.LinkProgram();

	_shaderPuerco.Activate();
	_shaderPuerco.SetUniformVector("LightColor", glm::vec3(1.0f, 1.0f, 1.0f));
	_shaderPuerco.SetUniformVector("LightPosition", glm::vec3(-5.0f, 5.0f, 5.0f));
	_shaderPuerco.SetUniformi("DiffuseTexture", 0);
	_shaderPuerco.SetUniformi("DiffuseTexture2", 1);
	_shaderPuerco.SetUniformi("ShadowMap", 2);
	_shaderPuerco.Deactivate();

	// Creacin y configuracin del buffer de profundidad (framebuffer). Resolucin de 2048 px.
	_depthbuffer.Create(2048);

	/* PALMA DE LA MANO */
	_geometriaPalma.SetPosition(0.0f, 0.0f, 0.0f);
	_geometriaPalma.Rotate(-60.0f, 0, 0, true);

	/* DEDO INDICE */
	_geometriaInvisibleIndice.SetPosition(-1.5f, 2.7f, 0.0f);
	_geometriaIndice.SetPosition(0, 0.4f, 0.0f);
	_geometriaInvisibleIndiceArriba.SetPosition(0, 0.9f, -0.3f);
	_geometriaIndiceArriba.SetPosition(0, 0.9f, 0.0f);

	/* DEDO MEDIO*/
	_geometriaInvisibleMedio.SetPosition(0.0f, 2.7f, 0.0f);
	_geometriaMedio.SetPosition(0.0f, 0.4f, 0.0f);
	_geometriaInvisibleMedioArriba.SetPosition(0, 0.9f, -0.3f);
	_geometriaMedioArriba.SetPosition(0, 0.9f, 0.0f);

	/* DEDO MENIQUE*/
	_geometriaInvisibleMenique.SetPosition(1.5f, 2.7f, 0.0f);
	_geometriaMenique.SetPosition(0.0f, 0.4f, 0.0f);
	_geometriaInvisibleMeniqueArriba.SetPosition(0, 0.9f, -0.3f);
	_geometriaMeniqueArriba.SetPosition(0, 0.9f, 0.0f);

	/* DEDO PULGAR */
	_geometriaInvisiblePulgar.SetPosition(-2.0f, -0.75f, 0.0f);
	_geometriaPulgar.SetPosition(-0.9f, 0.0f, 0.0f);
	_geometriaInvisiblePulgarArriba.SetPosition(-0.45f, 0, 0.0f);
	_geometriaPulgarArriba.SetPosition(-1.2f, 0.0f, 0.0f);

	/* PISO */
	_geometriaPiso.SetScale(8.0f, 0.1f, 8.0f); //Escala piramide 2
	_geometriaPiso.SetPosition(0.0f, -2.5f, 0.0f);

	/* CAMARAS */
	_camara.SetPosition(0.0f, 6.0f, 10.0f);
	_camaraLuz.SetPosition(-3.0f, 7.0f, 5.0f);
	_camara.Rotate(-25.0f, 0.0f, 0.0f, false);
	_camaraLuz.SetOrthographic(15.0f, 1.0f);
	_camaraLuz.Rotate(-75.0f, 0.0f, 0.0f, false);

	myTexture.LoadTexture("caja.jpg");
	myTexture2.LoadTexture("piso.jpg");
	myTexture3.LoadTexture("dino.png");

}

void GameLoop() {
	_geometriaPalma.Rotate(0.0, 0.05f, 0.0, true);
	if (_geometriaInvisibleIndice.GetRotation().x >= 0.70f) {
		rotacionIndice *= -1.0f;
	}
	else if (_geometriaInvisibleIndice.GetRotation().x <= 0.0f) {
		rotacionIndice *= -1.0f;
	}


	if (_geometriaInvisibleMedio.GetRotation().x >= 0.70f) {
		rotacionMedio *= -1.0f;
	}
	else if (_geometriaInvisibleMedio.GetRotation().x <= 0.0f) {
		rotacionMedio *= -1.0f;
	}


	if (_geometriaInvisibleMenique.GetRotation().x >= 0.70f) {
		rotacionMenique *= -1.0f;
	}
	else if (_geometriaInvisibleMenique.GetRotation().x <= 0.0f) {
		rotacionMenique *= -1.0f;
	}

	if (_geometriaInvisiblePulgar.GetRotation().y >= 0.70f) {
		rotacionPulgar *= -1.0f;
	}
	else if (_geometriaInvisiblePulgar.GetRotation().y <= 0.0f) {
		rotacionPulgar *= -1.0f;
	}


	_geometriaInvisibleIndice.Rotate(rotacionIndice, 0.0f, 0, true);
	_geometriaInvisibleMedio.Rotate(rotacionIndice, 0.0f, 0, true);
	_geometriaInvisibleMenique.Rotate(rotacionIndice, 0.0f, 0, true);
	_geometriaInvisiblePulgar.Rotate(0.0f, rotacionIndice, 0.0f, true);

	_geometriaInvisibleIndiceArriba.Rotate(rotacionIndice, 0, 0, true);
	_geometriaInvisibleMedioArriba.Rotate(rotacionMedio, 0, 0, true);
	_geometriaInvisibleMeniqueArriba.Rotate(rotacionMenique, 0, 0, true);
	_geometriaInvisiblePulgarArriba.Rotate(0.0f, rotacionPulgar, 0, true);
	_depthbuffer.Bind();
	//Limpimos el buffer de color y el buffer de profundidad. Siempre hacerlo al inicio del frame.
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

	//Jerarquias de multiplicaciones en las matrices
	// Padre (Palma) * Nodo Invisible (Articulación) * Hijo Bajo (Parte del dedo de abajo) * Hijo Superior (Parte del dedo de arriba)
	//Se tiene que aplicar tanto en sombras como en el dibujado
	//No aplicar escalas a las transformaciones jerarquicas porque se distorsionan las figuras

	_shaderDepth.Activate();
	/* SOMBRA PALMA */
	_shaderDepth.SetUniformMatrix("mvpMatrix", _camaraLuz.GetViewProjection() * _geometriaPalma.GetModelMatrix());
	_mesh.Draw(GL_TRIANGLES);
	/* SOMBRA INDICE */
	_shaderDepth.SetUniformMatrix("mvpMatrix", _camaraLuz.GetViewProjection() * _geometriaPalma.GetModelMatrix() * _geometriaInvisibleIndice.GetModelMatrix() * _geometriaIndice.GetModelMatrix());
	_meshDedos.Draw(GL_TRIANGLES);
	_shaderDepth.SetUniformMatrix("mvpMatrix", _camaraLuz.GetViewProjection() * _geometriaPalma.GetModelMatrix() * _geometriaInvisibleIndice.GetModelMatrix() * _geometriaIndice.GetModelMatrix() * _geometriaInvisibleIndiceArriba.GetModelMatrix() *_geometriaIndiceArriba.GetModelMatrix());
	_meshDedos.Draw(GL_TRIANGLES);
	/* SOMBRA MEDIO */
	_shaderDepth.SetUniformMatrix("mvpMatrix", _camaraLuz.GetViewProjection() *_geometriaPalma.GetModelMatrix() *  _geometriaInvisibleMedio.GetModelMatrix() * _geometriaMedio.GetModelMatrix());
	_meshDedos.Draw(GL_TRIANGLES);
	_shaderDepth.SetUniformMatrix("mvpMatrix", _camaraLuz.GetViewProjection() *_geometriaPalma.GetModelMatrix() *  _geometriaInvisibleMedio.GetModelMatrix() * _geometriaMedio.GetModelMatrix() *  _geometriaInvisibleMedioArriba.GetModelMatrix() * _geometriaMedioArriba.GetModelMatrix());
	_meshDedos.Draw(GL_TRIANGLES);
	/* SOMBRA MENIQUE */
	_shaderDepth.SetUniformMatrix("mvpMatrix", _camaraLuz.GetViewProjection() *_geometriaPalma.GetModelMatrix() * _geometriaInvisibleMenique.GetModelMatrix() *_geometriaMenique.GetModelMatrix());
	_meshDedos.Draw(GL_TRIANGLES);
	_shaderDepth.SetUniformMatrix("mvpMatrix", _camaraLuz.GetViewProjection() *_geometriaPalma.GetModelMatrix() * _geometriaInvisibleMenique.GetModelMatrix() * _geometriaMenique.GetModelMatrix() *  _geometriaInvisibleMeniqueArriba.GetModelMatrix() * _geometriaMeniqueArriba.GetModelMatrix());
	_meshDedos.Draw(GL_TRIANGLES);
	/*SOMBRA PULGAR*/
	_shaderDepth.SetUniformMatrix("mvpMatrix", _camaraLuz.GetViewProjection() *_geometriaPalma.GetModelMatrix() * _geometriaInvisiblePulgar.GetModelMatrix() * _geometriaPulgar.GetModelMatrix());
	_meshDedos.Draw(GL_TRIANGLES);
	_shaderDepth.SetUniformMatrix("mvpMatrix", _camaraLuz.GetViewProjection()* _geometriaPalma.GetModelMatrix() * _geometriaInvisiblePulgar.GetModelMatrix() * _geometriaPulgar.GetModelMatrix() * _geometriaInvisiblePulgarArriba.GetModelMatrix() * _geometriaPulgarArriba.GetModelMatrix());
	_meshDedos.Draw(GL_TRIANGLES);
	/* SOMBRA PISO*/
	_shaderDepth.SetUniformMatrix("mvpMatrix", _camaraLuz.GetViewProjection() * _geometriaPiso.GetModelMatrix());
	_meshPiso.Draw(GL_TRIANGLES);
	_shaderDepth.Deactivate();

	_depthbuffer.Unbind();

	glViewport(0, 0, glutGet(GLUT_WINDOW_WIDTH), glutGet(GLUT_WINDOW_HEIGHT));

	//Limpimos el buffer de color y el buffer de profundidad. Siempre hacerlo al inicio del frame.
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

	/* DIBUJANDO LA PALMA */
	_shaderPuerco.Activate();
	_shaderPuerco.SetUniformMatrix("modelMatrix", _geometriaPalma.GetModelMatrix());
	_shaderPuerco.SetUniformMatrix("LightVPMatrix", _camaraLuz.GetViewProjection());
	_shaderPuerco.SetUniformMatrix("mvpMatrix", _camara.GetViewProjection() * _geometriaPalma.GetModelMatrix());
	_shaderPuerco.SetUniformVector("CamaraPosition", _camara.GetPosition());
	glActiveTexture(GL_TEXTURE0);
	myTexture.Bind();
	glActiveTexture(GL_TEXTURE1);
	myTexture3.Bind();
	glActiveTexture(GL_TEXTURE2);
	_depthbuffer.BindDepthMap();
	_mesh.Draw(GL_TRIANGLES);
	glActiveTexture(GL_TEXTURE0);
	myTexture.Unbind();
	glActiveTexture(GL_TEXTURE1);
	myTexture3.Unbind();
	glActiveTexture(GL_TEXTURE2);
	_depthbuffer.UnbindDepthMap();
	_shaderPuerco.Deactivate();

	/* DEDO INDICE */
	_shaderPuerco.Activate();
	_shaderPuerco.SetUniformMatrix("modelMatrix", _geometriaIndice.GetModelMatrix());
	_shaderPuerco.SetUniformMatrix("LightVPMatrix", _camaraLuz.GetViewProjection());
	_shaderPuerco.SetUniformMatrix("mvpMatrix", _camara.GetViewProjection() * _geometriaPalma.GetModelMatrix() * _geometriaInvisibleIndice.GetModelMatrix() * _geometriaIndice.GetModelMatrix());
	_shaderPuerco.SetUniformVector("CamaraPosition", _camara.GetPosition());
	glActiveTexture(GL_TEXTURE0);
	myTexture.Bind();
	glActiveTexture(GL_TEXTURE1);
	myTexture3.Bind();
	glActiveTexture(GL_TEXTURE2);
	_depthbuffer.BindDepthMap();
	_meshDedos.Draw(GL_TRIANGLES);
	glActiveTexture(GL_TEXTURE0);
	myTexture.Unbind();
	glActiveTexture(GL_TEXTURE1);
	myTexture3.Unbind();
	glActiveTexture(GL_TEXTURE2);
	_depthbuffer.UnbindDepthMap();
	_shaderPuerco.Deactivate();

	_shaderPuerco.Activate();
	_shaderPuerco.SetUniformMatrix("modelMatrix", _geometriaIndiceArriba.GetModelMatrix());
	_shaderPuerco.SetUniformMatrix("LightVPMatrix", _camaraLuz.GetViewProjection());
	_shaderPuerco.SetUniformMatrix("mvpMatrix", _camara.GetViewProjection() * _geometriaPalma.GetModelMatrix() * _geometriaInvisibleIndice.GetModelMatrix() * _geometriaIndice.GetModelMatrix() * _geometriaInvisibleIndiceArriba.GetModelMatrix() * _geometriaIndiceArriba.GetModelMatrix());
	_shaderPuerco.SetUniformVector("CamaraPosition", _camara.GetPosition());
	glActiveTexture(GL_TEXTURE0);
	myTexture.Bind();
	glActiveTexture(GL_TEXTURE1);
	myTexture3.Bind();
	glActiveTexture(GL_TEXTURE2);
	_depthbuffer.BindDepthMap();
	_meshDedos.Draw(GL_TRIANGLES);
	glActiveTexture(GL_TEXTURE0);
	myTexture.Unbind();
	glActiveTexture(GL_TEXTURE1);
	myTexture3.Unbind();
	glActiveTexture(GL_TEXTURE2);
	_depthbuffer.UnbindDepthMap();
	_shaderPuerco.Deactivate();

	/* DIBUJANDO DEDO MEDIO */
	_shaderPuerco.Activate();
	_shaderPuerco.SetUniformMatrix("modelMatrix", _geometriaMedio.GetModelMatrix());
	_shaderPuerco.SetUniformMatrix("LightVPMatrix", _camaraLuz.GetViewProjection());
	_shaderPuerco.SetUniformMatrix("mvpMatrix", _camara.GetViewProjection() * _geometriaPalma.GetModelMatrix() * _geometriaInvisibleMedio.GetModelMatrix() * _geometriaMedio.GetModelMatrix());
	_shaderPuerco.SetUniformVector("CamaraPosition", _camara.GetPosition());
	glActiveTexture(GL_TEXTURE0);
	myTexture.Bind();
	glActiveTexture(GL_TEXTURE1);
	myTexture3.Bind();
	glActiveTexture(GL_TEXTURE2);
	_depthbuffer.BindDepthMap();
	_meshDedos.Draw(GL_TRIANGLES);
	glActiveTexture(GL_TEXTURE0);
	myTexture.Unbind();
	glActiveTexture(GL_TEXTURE1);
	myTexture3.Unbind();
	glActiveTexture(GL_TEXTURE2);
	_depthbuffer.UnbindDepthMap();
	_shaderPuerco.Deactivate();

	_shaderPuerco.Activate();
	_shaderPuerco.SetUniformMatrix("modelMatrix", _geometriaMedioArriba.GetModelMatrix());
	_shaderPuerco.SetUniformMatrix("LightVPMatrix", _camaraLuz.GetViewProjection());
	_shaderPuerco.SetUniformMatrix("mvpMatrix", _camara.GetViewProjection() * _geometriaPalma.GetModelMatrix() *  _geometriaInvisibleMedio.GetModelMatrix() * _geometriaMedio.GetModelMatrix() *  _geometriaInvisibleMedioArriba.GetModelMatrix()  * _geometriaMedioArriba.GetModelMatrix());
	_shaderPuerco.SetUniformVector("CamaraPosition", _camara.GetPosition());
	glActiveTexture(GL_TEXTURE0);
	myTexture.Bind();
	glActiveTexture(GL_TEXTURE1);
	myTexture3.Bind();
	glActiveTexture(GL_TEXTURE2);
	_depthbuffer.BindDepthMap();
	_meshDedos.Draw(GL_TRIANGLES);
	glActiveTexture(GL_TEXTURE0);
	myTexture.Unbind();
	glActiveTexture(GL_TEXTURE1);
	myTexture3.Unbind();
	glActiveTexture(GL_TEXTURE2);
	_depthbuffer.UnbindDepthMap();
	_shaderPuerco.Deactivate();

	/* DIBUJANDO DEDO MENIQUE */
	_shaderPuerco.Activate();
	_shaderPuerco.SetUniformMatrix("modelMatrix", _geometriaMenique.GetModelMatrix());
	_shaderPuerco.SetUniformMatrix("LightVPMatrix", _camaraLuz.GetViewProjection());
	_shaderPuerco.SetUniformMatrix("mvpMatrix", _camara.GetViewProjection() * _geometriaPalma.GetModelMatrix() * _geometriaInvisibleMenique.GetModelMatrix() * _geometriaMenique.GetModelMatrix());
	_shaderPuerco.SetUniformVector("CamaraPosition", _camara.GetPosition());
	glActiveTexture(GL_TEXTURE0);
	myTexture.Bind();
	glActiveTexture(GL_TEXTURE1);
	myTexture3.Bind();
	glActiveTexture(GL_TEXTURE2);
	_depthbuffer.BindDepthMap();
	_meshDedos.Draw(GL_TRIANGLES);
	glActiveTexture(GL_TEXTURE0);
	myTexture.Unbind();
	glActiveTexture(GL_TEXTURE1);
	myTexture3.Unbind();
	glActiveTexture(GL_TEXTURE2);
	_depthbuffer.UnbindDepthMap();
	_shaderPuerco.Deactivate();

	_shaderPuerco.Activate();
	_shaderPuerco.SetUniformMatrix("modelMatrix", _geometriaMeniqueArriba.GetModelMatrix());
	_shaderPuerco.SetUniformMatrix("LightVPMatrix", _camaraLuz.GetViewProjection());
	_shaderPuerco.SetUniformMatrix("mvpMatrix", _camara.GetViewProjection()  * _geometriaPalma.GetModelMatrix() * _geometriaInvisibleMenique.GetModelMatrix() * _geometriaMenique.GetModelMatrix() *  _geometriaInvisibleMeniqueArriba.GetModelMatrix()  * _geometriaMeniqueArriba.GetModelMatrix());
	_shaderPuerco.SetUniformVector("CamaraPosition", _camara.GetPosition());
	glActiveTexture(GL_TEXTURE0);
	myTexture.Bind();
	glActiveTexture(GL_TEXTURE1);
	myTexture3.Bind();
	glActiveTexture(GL_TEXTURE2);
	_depthbuffer.BindDepthMap();
	_meshDedos.Draw(GL_TRIANGLES);
	glActiveTexture(GL_TEXTURE0);
	myTexture.Unbind();
	glActiveTexture(GL_TEXTURE1);
	myTexture3.Unbind();
	glActiveTexture(GL_TEXTURE2);
	_depthbuffer.UnbindDepthMap();
	_shaderPuerco.Deactivate();

	/* DIBUJANDO DEDO PULGAR */
	_shaderPuerco.Activate();
	_shaderPuerco.SetUniformMatrix("modelMatrix", _geometriaPulgar.GetModelMatrix());
	_shaderPuerco.SetUniformMatrix("LightVPMatrix", _camaraLuz.GetViewProjection());
	_shaderPuerco.SetUniformMatrix("mvpMatrix", _camara.GetViewProjection() *_geometriaPalma.GetModelMatrix() * _geometriaInvisiblePulgar.GetModelMatrix() * _geometriaPulgar.GetModelMatrix());
	_shaderPuerco.SetUniformVector("CamaraPosition", _camara.GetPosition());
	glActiveTexture(GL_TEXTURE0);
	myTexture.Bind();
	glActiveTexture(GL_TEXTURE1);
	myTexture3.Bind();
	glActiveTexture(GL_TEXTURE2);
	_depthbuffer.BindDepthMap();
	_meshPulgar.Draw(GL_TRIANGLES);
	glActiveTexture(GL_TEXTURE0);
	myTexture.Unbind();
	glActiveTexture(GL_TEXTURE1);
	myTexture3.Unbind();
	glActiveTexture(GL_TEXTURE2);
	_depthbuffer.UnbindDepthMap();
	_shaderPuerco.Deactivate();

	_shaderPuerco.Activate();
	_shaderPuerco.SetUniformMatrix("modelMatrix", _geometriaPulgarArriba.GetModelMatrix());
	_shaderPuerco.SetUniformMatrix("LightVPMatrix", _camaraLuz.GetViewProjection());
	_shaderPuerco.SetUniformMatrix("mvpMatrix", _camara.GetViewProjection() *_geometriaPalma.GetModelMatrix() * _geometriaInvisiblePulgar.GetModelMatrix() * _geometriaPulgar.GetModelMatrix() * _geometriaInvisiblePulgarArriba.GetModelMatrix() * _geometriaPulgarArriba.GetModelMatrix());
	_shaderPuerco.SetUniformVector("CamaraPosition", _camara.GetPosition());
	glActiveTexture(GL_TEXTURE0);
	myTexture.Bind();
	glActiveTexture(GL_TEXTURE1);
	myTexture3.Bind();
	glActiveTexture(GL_TEXTURE2);
	_depthbuffer.BindDepthMap();
	_meshPulgar.Draw(GL_TRIANGLES);
	glActiveTexture(GL_TEXTURE0);
	myTexture.Unbind();
	glActiveTexture(GL_TEXTURE1);
	myTexture3.Unbind();
	glActiveTexture(GL_TEXTURE2);
	_depthbuffer.UnbindDepthMap();
	_shaderPuerco.Deactivate();

	/* PISO */
	_shaderProgram.Activate();
	_shaderProgram.SetUniformMatrix("mvpMatrix", _camara.GetViewProjection() * _geometriaPiso.GetModelMatrix());
	_shaderProgram.SetUniformMatrix("LightVPMatrix", _camaraLuz.GetViewProjection());
	_shaderProgram.SetUniformMatrix("modelMatrix", _geometriaPiso.GetModelMatrix());
	_shaderProgram.SetUniformVector("CamaraPosition", _camara.GetPosition());
	glActiveTexture(GL_TEXTURE0);
	myTexture2.Bind();
	glActiveTexture(GL_TEXTURE1);
	_depthbuffer.BindDepthMap();
	_meshPiso.Draw(GL_TRIANGLES);
	glActiveTexture(GL_TEXTURE0);
	myTexture2.Unbind();
	glActiveTexture(GL_TEXTURE1);
	_depthbuffer.UnbindDepthMap();
	_shaderProgram.Deactivate();

	//Cuando terminamos de renderear, cambiamos los buffers.
	glutSwapBuffers();
}

void Idle() {
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
	//Solicitando una versin especfica de OpenGL
	glutInitContextVersion(4, 2);
	// Inicializar DevIL. Esto se debe hacer slo una vez.
	ilInit();
	//Iniciar el contexto de OpenGL. El contexto se refiere a las capacidades que va a tener nuestra aplicacin grfica.
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

	//Asociamos una funcin para el cambio de la ventana.  Freeglut la va a mandar a llamar cuando alguien cambie el tamao de la ventana.
	glutReshapeFunc(ReshapeWindow);
	//Asociamos la funcin que mandar a llamar cuando OpenGL entre modo de reposo.
	glutIdleFunc(Idle);
	//Inicializamos GLEW. Esta libreria se encarga de obtener el API de OpenGL de nuestra targeta de video.
	//Shame on you Microsoft
	glewInit();
	//Configurar OpenGL. Este es el color por default del buffer de color en el framebuffer.
	glClearColor(1.0f, 1.0f, 0.5f, 1.0f);

	glEnable(GL_DEPTH_TEST);
	//Activamos el borrado de caras traseras. Ahora todos los triangulos que dibujemos deben de estar CCW
	glEnable(GL_CULL_FACE);
	//No dibujar las caras traseras de la geometra
	glCullFace(GL_BACK);

	// Cambiar el punto de origen de las texturas. Por default, DevIL
	// pone un punto de origen en la esquina superior izquierda.
	// Esto es compatible con el sistema operativo, pero no con el
	// funcionamiento de OpenGL.
	ilEnable(IL_ORIGIN_SET);
	// Configurar el punto de origen de las texturas en la esquina
	// inferior izquierda
	ilOriginFunc(IL_ORIGIN_LOWER_LEFT);

	std::cout << glGetString(GL_VERSION) << std::endl;

	//Configuracin inicial de nuetro programa. 
	Initialize();

	//Iniciar la aplicacion. El main se pausara 
	glutMainLoop();


	return 0;
}

/*float _angulo = 0;
int flag = 1;

//Posiciones de vertices del triangulo
positions.push_back(glm::vec3(1.0f, -1.0f, 1.0f)); //Esquina inferior derecha delantera => 0
positions.push_back(glm::vec3(-1.0f, -1.0f, 1.0f)); //Esquina inferior izquierda delantera => 1
positions.push_back(glm::vec3(-1.0f, -1.0f, -1.0f)); //Esquina inferior izquierda trasera => 2
positions.push_back(glm::vec3(1.0f, -1.0f, -1.0f));  //Esquina inferior derecha trasera => 3
positions.push_back(glm::vec3(0.0f, 1.0f, 0.0f));  //Punta superior => 4

//Colores de vétices
colors.push_back(glm::vec3(1.0f, 0.0f, 0.0f)); //Color vértice 0
colors.push_back(glm::vec3(0.0f, 1.0f, 0.0f)); //Color vértice 1
colors.push_back(glm::vec3(0.0f, 0.0f, 1.0f)); //Color vértice 2
colors.push_back(glm::vec3(1.0f, 1.0f, 0.0f)); //Color vértice 3
colors.push_back(glm::vec3(1.0f, 0.0f, 1.0f)); //Color vértice 4

//Se crea el vector con los índices de las posiciones
std::vector<unsigned int> indices = {
0, 4, 1, //Cara enfrente pirámide
1, 4, 2, //Cara izquierda pirámide
2, 4, 3,  //Cara atrás pirámide
3, 4, 0, //Cara derecha pirámide
0, 1, 3, 0, 3, 2 //Cuadrádo de base
};

//Transformaciones de primer pirámide
_transform.Rotate(0.01f, 0.01f, 0.01f, false);
_transform.SetPosition(5.0f * glm::cos(glm::radians((float)_angulo)), 5.0f * glm::sin(glm::radians((float)_angulo)), 0.0f);
_angulo = _angulo + 0.01f;
if (_angulo > 360.0f) {
_angulo = 0.0f;
}
//Transformaciones de segunda pirámide
_transform2.Rotate(-0.01f, -0.01f, -0.01f, false);
if (flag == 1) {
if (_transform2.GetScale().x >= 1.0f) {
flag = 0;
}
_transform2.SeScale(_transform2.GetScale().x + 0.0001f, _transform2.GetScale().y + 0.0001f, _transform2.GetScale().z + 0.0001f);
}
else {
if (_transform2.GetScale().x <= 0.25f) {
flag = 1;
}
_transform2.SeScale(_transform2.GetScale().x - 0.0001f, _transform2.GetScale().y - 0.0001f, _transform2.GetScale().z - 0.0001f);
}


//Luis Fernndo Espinosa Elizalde A01375758
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

/*
//Cubo 1
//Cara derecha
positions.push_back(glm::vec3(3.0f, 0, 3.0f));  //Esquina inferior derecha trasera => 0
positions.push_back(glm::vec3(3.0f, 0, -3.0f)); //Esquina superior derecha trasera => 1
positions.push_back(glm::vec3(3.0f, 6.0f, -3.0f)); //Esquina superior derecha delantera => 2
positions.push_back(glm::vec3(3.0f, 6.0f, 3.0f)); //Esquina inferior derecha delantera => 3, conecta triangulo con 0 y 2
//Cara de enfrente
positions.push_back(glm::vec3(-3.0f, 0, 3.0f)); //Esquina inferior izquierda delantera => 4
positions.push_back(glm::vec3(3.0f, 0, 3.0f)); //Esquina inferior derecha delantera => 5
positions.push_back(glm::vec3(3.0f, 6.0f, 3.0f)); //Esquina superior derecha delantera => 6
positions.push_back(glm::vec3(-3.0f, 6.0f, 3.0f)); //Esquina superior izquierda delantera => 7, conecta triangulo con 4 y 6
//Cara izquierda
positions.push_back(glm::vec3(-3.0f, 0, -3.0f)); //Esquina inferior izquierda trasera => 8
positions.push_back(glm::vec3(-3.0f, 0, 3.0f)); //Esquina inferior izquierda delantera => 9
positions.push_back(glm::vec3(-3.0f, 6.0f, 3.0f)); //Esquina superior izquierda delantera => 10
positions.push_back(glm::vec3(-3.0f, 6.0f, -3.0f)); //Esquina superior izquierda trasera => 11, conecta triangulo con 8 y 10
//Cara de atras
positions.push_back(glm::vec3(3.0f, 0, -3.0f));  //Esquina inferior derecha trasera => 12
positions.push_back(glm::vec3(-3.0f, 0, -3.0f)); //Esquina inferior izquierda trasera => 13
positions.push_back(glm::vec3(-3.0f, 6.0f, -3.0f)); //Esquina superior izquierda trasera => 14
positions.push_back(glm::vec3(3.0f, 6.0f, -3.0f)); //Esquina superior derecha trasera => 15,conecta triangilo con 12 y 14
//Cara de abajo
positions.push_back(glm::vec3(3.0f, 0, 3.0f)); //Esquina inferior derecha delantera => 16
positions.push_back(glm::vec3(-3.0f, 0, 3.0f)); //Esquina inferior izquierda delantera => 17
positions.push_back(glm::vec3(-3.0f, 0, -3.0f)); //Esquina inferior izquierda trasera => 18
positions.push_back(glm::vec3(3.0f, 0, -3.0f));  //Esquina inferior derecha trasera => 19, conecta trangulo con 16 y 18
//Cara de arriba
positions.push_back(glm::vec3(3.0f, 6.0f, 3.0f)); //Esquina superior derecha delantera => 20
positions.push_back(glm::vec3(-3.0f, 6.0f, -3.0f)); //Esquina superior izquierda trasera => 21
positions.push_back(glm::vec3(-3.0f, 6.0f, 3.0f)); //Esquina superior izquierda delantera => 22
positions.push_back(glm::vec3(3.0f, 6.0f, -3.0f)); //Esquina superior derecha trasera => 23,conecta triangulo con 20 y 2


//Cubo 1
//Color cara 1
colors.push_back(glm::vec3(1.0f, 0.0f, 0.0f));
colors.push_back(glm::vec3(1.0f, 0.0f, 0.0f));
colors.push_back(glm::vec3(1.0f, 0.0f, 0.0f));
colors.push_back(glm::vec3(1.0f, 0.0f, 0.0f));
//Color cara 2
colors.push_back(glm::vec3(0.0f, 1.0f, 0.0f));
colors.push_back(glm::vec3(0.0f, 1.0f, 0.0f));
colors.push_back(glm::vec3(0.0f, 1.0f, 0.0f));
colors.push_back(glm::vec3(0.0f, 1.0f, 0.0f));
//Color cara 3
colors.push_back(glm::vec3(0.0f, 0.0f, 1.0f));
colors.push_back(glm::vec3(0.0f, 0.0f, 1.0f));
colors.push_back(glm::vec3(0.0f, 0.0f, 1.0f));
colors.push_back(glm::vec3(0.0f, 0.0f, 1.0f));
//Color cara 4
colors.push_back(glm::vec3(1.0f, 1.0f, 0.0f));
colors.push_back(glm::vec3(1.0f, 1.0f, 0.0f));
colors.push_back(glm::vec3(1.0f, 1.0f, 0.0f));
colors.push_back(glm::vec3(1.0f, 1.0f, 0.0f));
//Color cara 5
colors.push_back(glm::vec3(1.0f, 0.0f, 1.0f));
colors.push_back(glm::vec3(1.0f, 0.0f, 1.0f));
colors.push_back(glm::vec3(1.0f, 0.0f, 1.0f));
colors.push_back(glm::vec3(1.0f, 0.0f, 1.0f));
//Color cara 6
colors.push_back(glm::vec3(1.0f, 1.0f, 1.0f));
colors.push_back(glm::vec3(1.0f, 1.0f, 1.0f));
colors.push_back(glm::vec3(1.0f, 1.0f, 1.0f));
colors.push_back(glm::vec3(1.0f, 1.0f, 1.0f));

//Se crea el vector con los índices de las posiciones
std::vector<unsigned int> indices = {
0, 1, 2, 0, 2, 3, //Cara 1
4, 5, 6, 4, 6, 7, //Cara 2
8, 9, 10, 8, 10, 11, //Cara 3
12, 13, 14, 12, 14, 15, //Cara 4
16, 17, 18, 16, 18, 19, //Cara 5
20, 21, 22, 20, 23, 21, //Cara 6
};
*/
//Posiciones de Pirámide

/*
std::vector<glm::vec3> positions;
positions.push_back(glm::vec3(3.0f, 0, 3.0f)); //Esquina inferior derecha delantera => 0
positions.push_back(glm::vec3(3.0f, 0, -3.0f));  //Esquina inferior derecha trasera => 1
positions.push_back(glm::vec3(-3.0f, 0, -3.0f)); //Esquina inferior izquierda trasera => 2
positions.push_back(glm::vec3(-3.0f, 0, 3.0f)); //Esquina inferior izquierda delantera => 3
positions.push_back(glm::vec3(3.0f, 6.0f, 3.0f)); //Esquina superior derecha delantera => 4
positions.push_back(glm::vec3(3.0f, 6.0f, -3.0f)); //Esquina superior derecha trasera => 5
positions.push_back(glm::vec3(-3.0f, 6.0f, -3.0f)); //Esquina superior izquierda trasera => 6
positions.push_back(glm::vec3(-3.0f, 6.0f, 3.0f)); //Esquina superior izquierda delantera => 7

//Solo se necesitan 6 colores
std::vector<glm::vec3> colors;
colors.push_back(glm::vec3(1.0f, 0.0f, 0.0f));
colors.push_back(glm::vec3(0.0f, 1.0f, 0.0f));
colors.push_back(glm::vec3(0.0f, 0.0f, 1.0f));
colors.push_back(glm::vec3(1.0f, 1.0f, 0.0f));
colors.push_back(glm::vec3(1.0f, 0.0f, 1.0f));
colors.push_back(glm::vec3(1.0f, 1.0f, 1.0f));


//Se crea el vector con los índices de las posiciones
std::vector<unsigned int> indices = {
0, 1, 5, 0, 5, 4, //Cara 1
3, 0, 4, 3, 4, 7, //Cara 2
2, 3, 7, 2, 7, 6, //Cara 3
1, 2, 6, 1, 6, 5, //Cara 4
0, 3, 2, 0, 2, 1, //Cara 5
4, 6, 7, 4, 5, 6 //Cara 6
};
*/

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