/*

#ifndef FOODCELL_H
#define FOODCELL_H

#include <vector>
#include "cell.h"
#include <glad/glad.h>

class Food_Cell : Cell
{

private:
	float energy;
	float burnRate = 0.001f;

public:
	Food_Cell(const unsigned int& row, const unsigned int& col, const unsigned int& blockOffset)\
	{
	};


	void turnOn() override
	{

		if (this->state == false) {
			this->state = true;

			Vertex* bufferData = static_cast<Vertex*>(glMapBuffer(GL_ARRAY_BUFFER, GL_READ_WRITE));

			// Check if the mapping was successful
			if (bufferData != nullptr) {

				// Update all vertices in the buffer
				for (int i = this->offset, newOffset = this->offset + 4; i < newOffset; i++) {
					bufferData[i].color = glm::vec3(0.53f, 0.33f, 0.35f);
				}

				// Unmap the buffer to apply the changes
				glUnmapBuffer(GL_ARRAY_BUFFER);
			}
		}

	};

};

#endif
*/