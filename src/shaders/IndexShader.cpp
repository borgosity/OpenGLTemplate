#include "IndexShader.h"

// Rainbow Shader files
const GLchar * INDEX_VERTEX_FILE = "src/shaders/vertexShader_Rainbow.txt";
const GLchar * INDEX_FRAGMENT_FILE = "src/shaders/fragmentShader_Rainbow.txt";


IndexShader::IndexShader() : ShaderProgram(INDEX_VERTEX_FILE, INDEX_FRAGMENT_FILE)
{
	// attributes bound in shader file
}


IndexShader::~IndexShader()
{
}

void IndexShader::bindAttributes()
{
	//bindAttribute(0, "position");	// bind the 'position' variable to position 0
	//bindAttribute(1, "color");		// bind the 'color' variable to position 1
}


