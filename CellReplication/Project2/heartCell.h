/*
#ifndef HEARTCELL_H
#define HEARTCELL_H

#include <vector>
#include "cell.h"
#include <glad/glad.h>

class Heart_Cell : Cell
{
	
	private:
		float energy;
		float burnRate = 0.001f;
		unsigned int MAX_CELLS;
		Cell*** CELL_POOL;
		std::vector<Cell*> NEIGHBORS;


	public:
		Heart_Cell(const unsigned int& row, const unsigned int& col, const unsigned int& blockOffset, Cell***& cells, const unsigned int& maxCells) : Cell(row, col, blockOffset, 'H')
		{

			this->CELL_POOL = cells;
			this->MAX_CELLS = maxCells;

			if ((int)(col - 1) > -1) {

				if ((int)(row - 1) > -1) {
					this->NEIGHBORS.push_back(this->CELL_POOL[row-1][col - 1]);
				}

				this->NEIGHBORS.push_back(this->CELL_POOL[row][col-1]);

				if ((row + 1) < this->MAX_CELLS) {
					this->NEIGHBORS.push_back(this->CELL_POOL[row + 1][col - 1]);
					this->NEIGHBORS.push_back(this->CELL_POOL[row + 1][col]);
				}

			}

			if ((col + 1) < this->MAX_CELLS) {

				if (row + 1 < this->MAX_CELLS) {
					this->NEIGHBORS.push_back(this->CELL_POOL[row + 1][col + 1]);
				}

				this->NEIGHBORS.push_back(this->CELL_POOL[row][col + 1]);

				if ((int)(row - 1) > -1) {
					this->NEIGHBORS.push_back(this->CELL_POOL[row - 1][col + 1]);
				}
				
			}

			if ((int)(row - 1) > -1) {
				this->NEIGHBORS.push_back(this->CELL_POOL[row - 1][col]);
			}

			this->grow();
		
		};

		void grow()
		{

			int* handler = this->think();
			

			this->cellRow -= handler[0];
			this->cellCol -= handler[1];


			((Heart_Cell*)this->CELL_POOL[handler[0]][handler[1]])->turnOn();

			delete handler;

			

		}

		int* think()
		{


			for (int r = 0; r < this->MAX_CELLS; r++) {

				for (int c = 0; c < this->MAX_CELLS; c++) {
					
				
					if (this->CELL_POOL[r][c]->getType() == 'F') {

						return (new int[2] { (int)(this->CELL_POOL[r][c]->cellRow - this->cellRow), (int)(this->CELL_POOL[r][c]->cellCol - this->cellCol) });
					}

				}


			}


			return (new int[2]{ 0, 0 });

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
						bufferData[i].color = glm::vec3(0.53f, 1.0f, 0.35f);
					}

					// Unmap the buffer to apply the changes
					glUnmapBuffer(GL_ARRAY_BUFFER);
				}
			}

		};

};

#endif
*/