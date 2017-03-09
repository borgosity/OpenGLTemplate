/***************************************************************************************************************
  OpenGL C++ Tutorial followed from https://learnopengl.com/
  OpenGL 3D Game Tutorial was also use https://www.youtube.com/playlist?list=PLRIWtICgwaX0u7Rf9zkZhLoLuZVfUksDP
  - the youtube tutorial is written in Java but has some good explanations
  - the class structure for this project was also taken from that tutorial
****************************************************************************************************************/

#include <iostream>
//#include "tests\tests.h"
#include "tests\ExampleApp.h"
#include "tests\TerrainApp.h"
#include "tests\ModelApp.h"
#include "tests\LightsApp.h"
#include "tests\ProceeduralApp.h"


/// main function
int main()
{
	
	//helloWorld(); 
	//helloTriangle();
	//renderEngineTest(); 
	//indexBuffer();
	//greenTriangleChange();
	//gtShaderTest();
	//rainbowTri();
	//multipleShaders();
	//textures();
	//texturesTute();
	// texturesSplitData(); //## not working
	//dualTextures();
	//dualTextTute();
	//transformsTute();
	//transformsTuteRotation();
	//transformsRotationPlanets();
	//quaterionsTute();
	//threeDeeObjects();
	//camera();

	//ExampleApp * app = new ExampleApp();
	//TerrainApp * app = new TerrainApp();
	//ModelApp * app = new ModelApp();
	//LightsApp * app = new LightsApp();
	ProceeduralApp * app = new ProceeduralApp();


	if (app != nullptr)
	{
		app->run();
	}

	delete app;

	return 0;
}

