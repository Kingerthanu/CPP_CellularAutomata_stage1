#include <iostream>
#include <glad/glad.h>
#include <GLFW/glfw3.h>
#include <chrono>
#include <thread>

#include "shader.h"
#include "Vertex_Array.h"
#include "Element_Buffer.h"
#include <glm/glm.hpp>
#include <random>
#include "cell.h"
#include "heartCell.h"
#include "foodCell.h"

const unsigned int WINDOW_WIDTH = 1800;
const unsigned int WINDOW_HEIGHT = 1800;


  

int main()
{

	glfwInit();

	glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
	glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
	glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);

	std::vector<Vertex>* vertices = new std::vector<Vertex>;
	std::vector<GLuint>* indices = new std::vector<GLuint>;


	unsigned int MAX_CELLS = 320;

	Cell*** CELL_GRID = new Cell**[MAX_CELLS];

	float width = 0.00625f;

	for (int i = 0.0f; i < MAX_CELLS; i++) {

		CELL_GRID[i] = new Cell*[MAX_CELLS];

		for (int j = 0; j < MAX_CELLS; j++) {

			// Calculate indices for the four vertices of each square
			int bottomLeft = vertices->size();
			int bottomRight = bottomLeft + 1;
			int topLeft = bottomRight + 1;
			int topRight = topLeft + 1;

			// Push vertices for the square with color (assuming it's white)
			vertices->push_back(Vertex{ glm::vec3(-1.0f + (width * j), 1.0f - (width * i), 1.0f), glm::vec3(0.0f, 0.0f, 0.0f )});
			vertices->push_back(Vertex{ glm::vec3(-1.0f + (width * (j+1)), 1.0f - (width * i), 1.0f), glm::vec3(0.0f, 0.0f, 0.0f) });

			vertices->push_back(Vertex{ glm::vec3(-1.0f + (width * j), 1.0f - (width * (i + 1)), 1.0f), glm::vec3(0.0f, 0.0f, 0.0f) });
			vertices->push_back(Vertex{ glm::vec3(-1.0f + (width * (j + 1)), 1.0f - (width * (i + 1)), 1.0f), glm::vec3(0.0f, 0.0f, 0.0f) });


			// Push indices for the square
			indices->push_back(bottomLeft);
			indices->push_back(bottomRight);
			indices->push_back(topLeft);

			indices->push_back(bottomRight);
			indices->push_back(topRight);
			indices->push_back(topLeft);
			
			CELL_GRID[i][j] = new Cell(bottomLeft);

		}
	}

	for (unsigned int i = 0; i < MAX_CELLS; i++) {

		for (unsigned int j = 0; j < MAX_CELLS; j++) {

			CELL_GRID[i][j]->grabNeighbors(CELL_GRID, MAX_CELLS, i, j);

		}
	}
	

	GLFWwindow* window = glfwCreateWindow(WINDOW_WIDTH, WINDOW_HEIGHT, "Cell Division", NULL, NULL);

	if (!window) {

		glfwTerminate();
		return 0;

	}
	
	glfwMakeContextCurrent(window);


	gladLoadGL();

	glViewport(0, 0, WINDOW_WIDTH, WINDOW_HEIGHT);

	
	Shader shaderProg("default.vert", "default.frag");


	VAO VAO1;
	VAO1.Bind();

	VBO VBO1(*vertices);
	EBO EBO1(*indices);

	const unsigned int blockAmount = indices->size();

	delete vertices;
	delete indices;

	VAO1.LinkAttrib(VBO1, 0, 3, GL_FLOAT, sizeof(Vertex), (void*)0);
	VAO1.LinkAttrib(VBO1, 1, 3, GL_FLOAT, sizeof(Vertex), (void*)(3 * sizeof(float)));

	VAO1.unBind();
	VBO1.unBind();
	EBO1.unBind();

	VAO1.Bind();
	VBO1.Bind();

	std::random_device rd;
	std::mt19937 gen(rd());

	std::uniform_int_distribution<int> indexRandom = std::uniform_int_distribution<int>(130, 160);

	for (int i = 0; i < 100; i++) {
		CELL_GRID[indexRandom(gen)][indexRandom(gen)]->spark();
	}


	shaderProg.Activate();

	std::chrono::duration<double> frameDuration(1.0 / 20);

	while (!glfwWindowShouldClose(window)) {

		auto start = std::chrono::high_resolution_clock::now();


		glClearColor(0.07f, 0.13f, 0.17f, 1.0f);
		glClear(GL_COLOR_BUFFER_BIT);
		

		for (unsigned int i = 0; i < MAX_CELLS; i++) {

			for (unsigned int j = 0; j < MAX_CELLS; j++) {

				CELL_GRID[i][j]->think();

			}
		}

		
		glDrawElements(GL_TRIANGLES, blockAmount, GL_UNSIGNED_INT, 0);

		glfwSwapBuffers(window);
		glfwPollEvents();

		auto end = std::chrono::high_resolution_clock::now();
		auto elapsed = std::chrono::duration_cast<std::chrono::duration<double>>(end - start);

		// Sleep to maintain the desired frame rate
		std::this_thread::sleep_for(frameDuration - elapsed);

	}

	VAO1.Delete();
	VBO1.Delete();
	EBO1.Delete();
	shaderProg.Delete();

	glfwDestroyWindow(window);
	glfwTerminate();

	return 0;

}