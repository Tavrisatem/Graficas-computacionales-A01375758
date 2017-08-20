#include "InputFile.h"

#include <fstream>
#include <sstream>

//Método que lee un archivo y guarda su contenido en la variable "_contents"
bool InputFile::Read(std::string filename)
{
	std::string line; //linea
	std::fstream fs; //stream de archivos
	fs.open(filename, std::fstream::in | std::fstream::out | std::fstream::app); //Abre los archivos
	//Guardar el contenido si pudo leer el archivo
	if (fs.is_open()) {
		std::ostringstream oss; //stream de cadenas de lineas
		//Guardar linea por linea en archivo
		while (getline(fs, line)) {
			oss << line << "\n";
		}
		_contents = oss.str();
		return true;
	}
	//Si no, regresa un string vacio
	_contents = "";
	return false;
}

//Método que regresa el valor de "_contents"
std::string InputFile::GetContents()
{
	return _contents;
}
