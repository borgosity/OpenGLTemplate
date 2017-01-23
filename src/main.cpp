#include <iostream>

#define GLEW_STATIC 0
// opengl includes
#include <glew.h>
#include <glfw3.h>
#include <glm.hpp>


int main()
{
	std::cout << "Hello World" << std::endl;

	if (!glfwInit()) {
		std::cout << "GLFW failed to initialise" << std::endl;
		return -1;
	}
	//// 4 x AntiAlising
	glfwWindowHint(GLFW_SAMPLES, 4);
	// set opengl version and profile
	glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 4);
	glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 0);
	glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);
	// open a window
	GLFWwindow * window;
	window = glfwCreateWindow(640, 480, "OpengGL Template Project", NULL, NULL);

	if (!window) {
		std::cout << "window failed" << std::endl;
		glfwTerminate();
		return -1;
	}
	// set current context to window
	glfwMakeContextCurrent(window);

	// draw triangle
	GLuint VertexArrayID = 0;
	glGenVertexArrays(1, &VertexArrayID);
	glBindVertexArray(VertexArrayID);
	// An array of 3 vectors which represents 3 vertices
	static const GLfloat g_vertex_buffer_data[] = {
		-1.0f, -1.0f, 0.0f,
		1.0f, -1.0f, 0.0f,
		0.0f,  1.0f, 0.0f,
	};
	//// This will identify our vertex buffer
	//GLuint vertexbuffer;
	//// Generate 1 buffer, put the resulting identifier in vertexbuffer
	//glGenBuffers(1, &vertexbuffer);
	//// The following commands will talk about our 'vertexbuffer' buffer
	//glBindBuffer(GL_ARRAY_BUFFER, vertexbuffer);
	//// Give our vertices to OpenGL.
	//glBufferData(GL_ARRAY_BUFFER, sizeof(g_vertex_buffer_data), g_vertex_buffer_data, GL_STATIC_DRAW);

	do {
		//// 1rst attribute buffer : vertices
		//glEnableVertexAttribArray(0);
		//glBindBuffer(GL_ARRAY_BUFFER, vertexbuffer);
		//glVertexAttribPointer(
		//	0,                  // attribute 0. No particular reason for 0, but must match the layout in the shader.
		//	3,                  // size
		//	GL_FLOAT,           // type
		//	GL_FALSE,           // normalized?
		//	0,                  // stride
		//	(void*)0            // array buffer offset
		//);
		//// Draw the triangle !
		//glDrawArrays(GL_TRIANGLES, 0, 3); // Starting from vertex 0; 3 vertices total -> 1 triangle
		//glDisableVertexAttribArray(0);
		glfwSwapBuffers(window);
		glfwPollEvents();
	} 
	while (glfwGetKey(window, GLFW_KEY_ESCAPE) != GLFW_PRESS && glfwWindowShouldClose(window) == 0);

	std::cout << "Finished!! \n\n" << std::endl;

	return 0;
}