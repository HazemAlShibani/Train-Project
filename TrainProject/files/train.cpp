#include <windows.h>		// Header File For Windows
#include <gl.h>			// Header File For The OpenGL32 Library
#include <glu.h>			// Header File For The GLu32 Library
//#include <glaux.h>		// Header File For The Glaux Library
#include <cmath>
#include <texture.h>
#include "train.h"

void train::lastStroller(float box,
						 int front, int back,
						 int bottomWindow, int topWindow, int centerWindow, int rightAndLeftWindow,
						 int floorStroller, int ceilStroller,
						 int bottomWindowOut, int topWindowOut, int backTrainOut
						 ) {
	// The Front:
		// - InSide Stroller:						
	glBindTexture(GL_TEXTURE_2D, front);
	glBegin(GL_QUADS);
	glTexCoord2d(0, 0);
	glVertex3d(-2*box, -box, -box);
	glTexCoord2d(1, 0);
	glVertex3d(box, -box, -box);
	glTexCoord2d(1, 1);
	glVertex3d(box, box, -box);
	glTexCoord2d(0, 1);
	glVertex3d(-2*box, box, -box);
	glEnd();

		// - outSide Stroller:
		glBindTexture(GL_TEXTURE_2D, backTrainOut);
	glBegin(GL_QUADS);
	glTexCoord2d(0, 0);
	glVertex3d(-2*box, -box, -box - 5);
	glTexCoord2d(1, 0);
	glVertex3d(box, -box, -box - 5);
	glTexCoord2d(1, 1);
	glVertex3d(box, box, -box - 5);
	glTexCoord2d(0, 1);
	glVertex3d(-2*box, box, -box - 5);
	glEnd();


	glBindTexture(GL_TEXTURE_2D, back);
	glBegin(GL_QUADS);
	glTexCoord2d(0, 0);
	glVertex3d(-2*box, -box, 4*box);
	glTexCoord2d(1, 0);
	glVertex3d(0, -box, 4*box);
	glTexCoord2d(1, 1);
	glVertex3d(0, box, 4*box);
	glTexCoord2d(0, 1);
	glVertex3d(-2*box, box, 4*box);
	glEnd();

	// The Ceil:
		// - InSide Stroller:
	glBindTexture(GL_TEXTURE_2D, ceilStroller);
	glBegin(GL_QUADS);
	glTexCoord2d(0, 0);
	glVertex3d(-2*box, box, -box);
	glTexCoord2d(1, 0);
	glVertex3d(box, box, -box);
	glTexCoord2d(1, 1);
	glVertex3d(box, box, 4*box);
	glTexCoord2d(0, 1);
	glVertex3d(-2*box, box, 4*box);
	glEnd();

		// - OutSide Stroller:
	glBindTexture(GL_TEXTURE_2D, bottomWindowOut);
	glBegin(GL_QUADS);
	glTexCoord2d(0, 0);
	glVertex3d(-2*box, box + 5, -box);
	glTexCoord2d(1, 0);
	glVertex3d(box, box + 5, -box);
	glTexCoord2d(1, 1);
	glVertex3d(box, box + 5, 4*box);
	glTexCoord2d(0, 1);
	glVertex3d(-2*box, box + 5, 4*box);
	glEnd();
		// ----------------------------------
		
	// The Floor:
	glBindTexture(GL_TEXTURE_2D, floorStroller);
	glBegin(GL_QUADS);
	glTexCoord2d(0, 0);
	glVertex3d(-2*box, -box, -box);
	glTexCoord2d(10, 0);
	glVertex3d(box, -box, -box);
	glTexCoord2d(10, 10);
	glVertex3d(box, -box, 4*box);
	glTexCoord2d(0, 10);
	glVertex3d(-2*box, -box, 4*box);
	glEnd();
	
	// The Left Window

		// The bottom wall:
				// - InSide Stroller:
	glBindTexture(GL_TEXTURE_2D, bottomWindow);
	glBegin(GL_QUADS);
	glTexCoord2d(0, 0);
	glVertex3d(-2*box, -box, 4*box);
	glTexCoord2d(1, 0);
	glVertex3d(-2*box, -box, -box);
	glTexCoord2d(1, 1);
	glVertex3d(-2*box, 0, -box);
	glTexCoord2d(0, 1);
	glVertex3d(-2*box, 0, 4*box);
	glEnd();
				// - Outside Stroller:
	glBindTexture(GL_TEXTURE_2D, bottomWindowOut);
	glBegin(GL_QUADS);
	glTexCoord2d(0, 0);
	glVertex3d(-2*box-5, -box, 4*box);
	glTexCoord2d(1, 0);
	glVertex3d(-2*box-5, -box, -box);
	glTexCoord2d(1, 1);
	glVertex3d(-2*box-5, 0, -box);
	glTexCoord2d(0, 1);
	glVertex3d(-2*box-5, 0, 4*box);
	glEnd();
		//------------------------------------------

		// The top Wall:
			// - InSide Stroller:
	glBindTexture(GL_TEXTURE_2D, topWindow);
	glBegin(GL_QUADS);
	glTexCoord2d(0, 0);
	glVertex3d(-2*box, box -100, 4*box);
	glTexCoord2d(1, 0);
	glVertex3d(-2*box, box -100, -box);
	glTexCoord2d(1, 1);
	glVertex3d(-2*box, box, -box);
	glTexCoord2d(0, 1);
	glVertex3d(-2*box, box, 4*box);
	glEnd();
		
			// - OutSide Stroller:
	glBindTexture(GL_TEXTURE_2D, topWindowOut);
	glBegin(GL_QUADS);
	glTexCoord2d(0, 0);
	glVertex3d(-2*box - 5, box -100, 4*box);
	glTexCoord2d(1, 0);
	glVertex3d(-2*box - 5, box -100, -box);
	glTexCoord2d(1, 1);
	glVertex3d(-2*box - 5, box, -box);
	glTexCoord2d(0, 1);
	glVertex3d(-2*box - 5, box, 4*box);
	glEnd();
		//------------------------------------------

		// The Center Wall:
			// - InSide Stroller:
	glBindTexture(GL_TEXTURE_2D, centerWindow);
	glBegin(GL_QUADS);
	glTexCoord2d(0, 0);
	glVertex3d(-2*box, -10, box + 200);
	glTexCoord2d(1, 0);
	glVertex3d(-2*box, -10, 2*box - 100);
	glTexCoord2d(1, 1);
	glVertex3d(-2*box, box - 90, 2*box - 100);
	glTexCoord2d(0, 1);
	glVertex3d(-2*box, box - 90, box + 200);
	glEnd();

			// - OutSide Stroller:
	glBindTexture(GL_TEXTURE_2D, bottomWindowOut);
	glBegin(GL_QUADS);
	glTexCoord2d(0, 0);
	glVertex3d(-2*box - 5, -10, box + 200);
	glTexCoord2d(1, 0);
	glVertex3d(-2*box - 5, -10,  2*box - 100);
	glTexCoord2d(1, 1);
	glVertex3d(-2*box - 5, box - 90,  2*box - 100);
	glTexCoord2d(0, 1);
	glVertex3d(-2*box - 5, box - 90, box + 200);
	glEnd();
		//------------------------------------------

		// The LeftAndRight - right Window:
			// - InSide Stroller:
	glBindTexture(GL_TEXTURE_2D, rightAndLeftWindow);
	glBegin(GL_QUADS);
	glTexCoord2d(0, 0);
	glVertex3d(-2*box, -10, -box);
	glTexCoord2d(1, 0);
	glVertex3d(-2*box, -10, -box + 100);
	glTexCoord2d(1, 1);
	glVertex3d(-2*box, box - 90, -box + 100);
	glTexCoord2d(0, 1);
	glVertex3d(-2*box, box - 90, -box);
	glEnd();

			// - OutSide Stroller:
	glBindTexture(GL_TEXTURE_2D, bottomWindowOut);
	glBegin(GL_QUADS);
	glTexCoord2d(0, 0);
	glVertex3d(-2*box - 5, -10, -box);
	glTexCoord2d(1, 0);
	glVertex3d(-2*box - 5, -10, -box + 100);
	glTexCoord2d(1, 1);
	glVertex3d(-2*box - 5, box - 90, -box + 100);
	glTexCoord2d(0, 1);
	glVertex3d(-2*box - 5, box - 90, -box);
	glEnd();



		// The LeftAndRight - right Window:
			// - InSide Stroller:
	glBindTexture(GL_TEXTURE_2D, rightAndLeftWindow);
	glBegin(GL_QUADS);
	glTexCoord2d(0, 0);
	glVertex3d(-2*box, -10, 4*box);
	glTexCoord2d(1, 0);
	glVertex3d(-2*box, -10, 4*box -100);
	glTexCoord2d(1, 1);
	glVertex3d(-2*box, box - 90, 4*box -100);
	glTexCoord2d(0, 1);
	glVertex3d(-2*box, box - 90, 4*box);
	glEnd();

			// - OutSide Stroller:
	glBindTexture(GL_TEXTURE_2D, bottomWindowOut);
	glBegin(GL_QUADS);
	glTexCoord2d(0, 0);
	glVertex3d(-2*box - 5, -10, 4*box);
	glTexCoord2d(1, 0);
	glVertex3d(-2*box - 5, -10, 4*box -100);
	glTexCoord2d(1, 1);
	glVertex3d(-2*box - 5, box - 90, 4*box -100);
	glTexCoord2d(0, 1);
	glVertex3d(-2*box - 5, box - 90, 4*box);
	glEnd();
		// --------------------------------------------
	

	// The Right Window
		// The bottom wall:
				// - InSide Stroller:
	glBindTexture(GL_TEXTURE_2D, bottomWindow);
	glBegin(GL_QUADS);
	glTexCoord2d(0, 0);
	glVertex3d(box, -box, 4*box);
	glTexCoord2d(1, 0);
	glVertex3d(box, -box, -box);
	glTexCoord2d(1, 1);
	glVertex3d(box, 0, -box);
	glTexCoord2d(0, 1);
	glVertex3d(box, 0, 4*box);
	glEnd();
				// - Outside Stroller:
	glBindTexture(GL_TEXTURE_2D, bottomWindowOut);
	glBegin(GL_QUADS);
	glTexCoord2d(0, 0);
	glVertex3d(box+5, -box, 4*box);
	glTexCoord2d(1, 0);
	glVertex3d(box+5, -box, -box);
	glTexCoord2d(1, 1);
	glVertex3d(box+5, 0, -box);
	glTexCoord2d(0, 1);
	glVertex3d(box+5, 0, 4*box);
	glEnd();
		//------------------------------------------

		// The top Wall:
			// - InSide Stroller:
	glBindTexture(GL_TEXTURE_2D, topWindow);
	glBegin(GL_QUADS);
	glTexCoord2d(0, 0);
	glVertex3d(box, box -100, 4*box);
	glTexCoord2d(1, 0);
	glVertex3d(box, box -100, -box);
	glTexCoord2d(1, 1);
	glVertex3d(box, box, -box);
	glTexCoord2d(0, 1);
	glVertex3d(box, box, 4*box);
	glEnd();
		
			// - OutSide Stroller:
	glBindTexture(GL_TEXTURE_2D, topWindowOut);
	glBegin(GL_QUADS);
	glTexCoord2d(0, 0);
	glVertex3d(box + 5, box -100, 4*box);
	glTexCoord2d(1, 0);
	glVertex3d(box + 5, box -100, -box);
	glTexCoord2d(1, 1);
	glVertex3d(box + 5, box, -box);
	glTexCoord2d(0, 1);
	glVertex3d(box + 5, box, 4*box);
	glEnd();
		//------------------------------------------

		// The Center Wall:
			// - InSide Stroller:
	glBindTexture(GL_TEXTURE_2D, centerWindow);
	glBegin(GL_QUADS);
	glTexCoord2d(0, 0);
	glVertex3d(box, -10, box + 200);
	glTexCoord2d(1, 0);
	glVertex3d(box, -10, 2*box -100);
	glTexCoord2d(1, 1);
	glVertex3d(box, box - 90, 2*box -100);
	glTexCoord2d(0, 1);
	glVertex3d(box, box - 90, box + 200);
	glEnd();

			// - OutSide Stroller:
	glBindTexture(GL_TEXTURE_2D, bottomWindowOut);
	glBegin(GL_QUADS);
	glTexCoord2d(0, 0);
	glVertex3d(box + 5, -10, box + 200);
	glTexCoord2d(1, 0);
	glVertex3d(box + 5, -10, 2*box -100);
	glTexCoord2d(1, 1);
	glVertex3d(box + 5, box - 90, 2*box -100);
	glTexCoord2d(0, 1);
	glVertex3d(box + 5, box - 90, box + 200);
	glEnd();
		//------------------------------------------

		// The LeftAndRight -right Window:
			// - InSide Stroller:
	glBindTexture(GL_TEXTURE_2D, rightAndLeftWindow);
	glBegin(GL_QUADS);
	glTexCoord2d(0, 0);
	glVertex3d(box, -10, -box);
	glTexCoord2d(1, 0);
	glVertex3d(box, -10, -box + 100);
	glTexCoord2d(1, 1);
	glVertex3d(box, box - 90, -box + 100);
	glTexCoord2d(0, 1);
	glVertex3d(box, box - 90, -box);
	glEnd();

			// - OutSide Stroller:
	glBindTexture(GL_TEXTURE_2D, bottomWindowOut);
	glBegin(GL_QUADS);
	glTexCoord2d(0, 0);
	glVertex3d(box + 5, -10, -box);
	glTexCoord2d(1, 0);
	glVertex3d(box + 5, -10, -box + 100);
	glTexCoord2d(1, 1);
	glVertex3d(box + 5, box - 90, -box + 100);
	glTexCoord2d(0, 1);
	glVertex3d(box + 5, box - 90, -box);
	glEnd();



		// The LeftAndRight - left Window:
			// - InSide Stroller:
	glBindTexture(GL_TEXTURE_2D, rightAndLeftWindow);
	glBegin(GL_QUADS);
	glTexCoord2d(0, 0);
	glVertex3d(box, -10, 4*box);
	glTexCoord2d(1, 0);
	glVertex3d(box, -10, 4*box - 100);
	glTexCoord2d(1, 1);
	glVertex3d(box, box - 90, 4*box-100);
	glTexCoord2d(0, 1);
	glVertex3d(box, box - 90, 4*box);
	glEnd();

			// - OutSide Stroller:
	glBindTexture(GL_TEXTURE_2D, bottomWindowOut);
	glBegin(GL_QUADS);
	glTexCoord2d(0, 0);
	glVertex3d(box + 5, -10, 4*box);
	glTexCoord2d(1, 0);
	glVertex3d(box + 5, -10, 4*box-100);
	glTexCoord2d(1, 1);
	glVertex3d(box + 5, box - 90, 4*box-100);
	glTexCoord2d(0, 1);
	glVertex3d(box + 5, box - 90, 4*box);
	glEnd();
		// --------------------------------------------	
	}

void train::stroller(float box,
					 int front, int back,
					 int bottomWindow, int topWindow, int centerWindow,  int rightAndLeftWindow,
					 int floorStroller, int ceilStroller,
					 int bottomWindowOut, int topWindowOut
					 ) {
	
	glBindTexture(GL_TEXTURE_2D, front);
	glBegin(GL_QUADS);
	glTexCoord2d(0, 0);
	glVertex3d(-2*box, -box, -box);
	glTexCoord2d(1, 0);
	glVertex3d(0, -box, -box);
	glTexCoord2d(1, 1);
	glVertex3d(0, box, -box);
	glTexCoord2d(0, 1);
	glVertex3d(-2*box, box, -box);
	glEnd();

	glBindTexture(GL_TEXTURE_2D, back);
	glBegin(GL_QUADS);
	glTexCoord2d(0, 0);
	glVertex3d(-2*box, -box, 4*box);
	glTexCoord2d(1, 0);
	glVertex3d(0, -box, 4*box);
	glTexCoord2d(1, 1);
	glVertex3d(0, box, 4*box);
	glTexCoord2d(0, 1);
	glVertex3d(-2*box, box, 4*box);
	glEnd();

	// The Ceil:
		// - InSide Stroller:
	glBindTexture(GL_TEXTURE_2D, ceilStroller);
	glBegin(GL_QUADS);
	glTexCoord2d(0, 0);
	glVertex3d(-2*box, box, -box);
	glTexCoord2d(1, 0);
	glVertex3d(box, box, -box);
	glTexCoord2d(1, 1);
	glVertex3d(box, box, 4*box);
	glTexCoord2d(0, 1);
	glVertex3d(-2*box, box, 4*box);
	glEnd();

		// - OutSide Stroller:
	glBindTexture(GL_TEXTURE_2D, bottomWindowOut);
	glBegin(GL_QUADS);
	glTexCoord2d(0, 0);
	glVertex3d(-2*box, box + 5, -box);
	glTexCoord2d(1, 0);
	glVertex3d(box, box + 5, -box);
	glTexCoord2d(1, 1);
	glVertex3d(box, box + 5, 4*box);
	glTexCoord2d(0, 1);
	glVertex3d(-2*box, box + 5, 4*box);
	glEnd();
		// ----------------------------------
		
	// The Floor:
	glBindTexture(GL_TEXTURE_2D, floorStroller);
	glBegin(GL_QUADS);
	glTexCoord2d(0, 0);
	glVertex3d(-2*box, -box, -box);
	glTexCoord2d(10, 0);
	glVertex3d(box, -box, -box);
	glTexCoord2d(10, 10);
	glVertex3d(box, -box, 4*box);
	glTexCoord2d(0, 10);
	glVertex3d(-2*box, -box, 4*box);
	glEnd();
	
	// The Left Window

		// The bottom wall:
				// - InSide Stroller:
	glBindTexture(GL_TEXTURE_2D, bottomWindow);
	glBegin(GL_QUADS);
	glTexCoord2d(0, 0);
	glVertex3d(-2*box, -box, 4*box);
	glTexCoord2d(1, 0);
	glVertex3d(-2*box, -box, -box);
	glTexCoord2d(1, 1);
	glVertex3d(-2*box, 0, -box);
	glTexCoord2d(0, 1);
	glVertex3d(-2*box, 0, 4*box);
	glEnd();
				// - Outside Stroller:
	glBindTexture(GL_TEXTURE_2D, bottomWindowOut);
	glBegin(GL_QUADS);
	glTexCoord2d(0, 0);
	glVertex3d(-2*box-5, -box, 4*box);
	glTexCoord2d(1, 0);
	glVertex3d(-2*box-5, -box, -box);
	glTexCoord2d(1, 1);
	glVertex3d(-2*box-5, 0, -box);
	glTexCoord2d(0, 1);
	glVertex3d(-2*box-5, 0, 4*box);
	glEnd();
		//------------------------------------------

		// The top Wall:
			// - InSide Stroller:
	glBindTexture(GL_TEXTURE_2D, topWindow);
	glBegin(GL_QUADS);
	glTexCoord2d(0, 0);
	glVertex3d(-2*box, box -100, 4*box);
	glTexCoord2d(1, 0);
	glVertex3d(-2*box, box -100, -box);
	glTexCoord2d(1, 1);
	glVertex3d(-2*box, box, -box);
	glTexCoord2d(0, 1);
	glVertex3d(-2*box, box, 4*box);
	glEnd();
		
			// - OutSide Stroller:
	glBindTexture(GL_TEXTURE_2D, topWindowOut);
	glBegin(GL_QUADS);
	glTexCoord2d(0, 0);
	glVertex3d(-2*box - 5, box -100, 4*box);
	glTexCoord2d(1, 0);
	glVertex3d(-2*box - 5, box -100, -box);
	glTexCoord2d(1, 1);
	glVertex3d(-2*box - 5, box, -box);
	glTexCoord2d(0, 1);
	glVertex3d(-2*box - 5, box, 4*box);
	glEnd();
		//------------------------------------------

		// The Center Wall:
			// - InSide Stroller:
	glBindTexture(GL_TEXTURE_2D, centerWindow);
	glBegin(GL_QUADS);
	glTexCoord2d(0, 0);
	glVertex3d(-2*box, -10, box + 200);
	glTexCoord2d(1, 0);
	glVertex3d(-2*box, -10, 2*box - 100);
	glTexCoord2d(1, 1);
	glVertex3d(-2*box, box - 90, 2*box - 100);
	glTexCoord2d(0, 1);
	glVertex3d(-2*box, box - 90, box + 200);
	glEnd();

			// - OutSide Stroller:
	glBindTexture(GL_TEXTURE_2D, bottomWindowOut);
	glBegin(GL_QUADS);
	glTexCoord2d(0, 0);
	glVertex3d(-2*box - 5, -10, box + 200);
	glTexCoord2d(1, 0);
	glVertex3d(-2*box - 5, -10, 2*box - 100);
	glTexCoord2d(1, 1);
	glVertex3d(-2*box - 5, box - 90, 2*box - 100);
	glTexCoord2d(0, 1);
	glVertex3d(-2*box - 5, box - 90, box + 200);
	glEnd();
		//------------------------------------------

		// The LeftAndRight - right Window:
			// - InSide Stroller:
	glBindTexture(GL_TEXTURE_2D, rightAndLeftWindow);
	glBegin(GL_QUADS);
	glTexCoord2d(0, 0);
	glVertex3d(-2*box, -10, -box);
	glTexCoord2d(1, 0);
	glVertex3d(-2*box, -10, -box + 100);
	glTexCoord2d(1, 1);
	glVertex3d(-2*box, box - 90, -box + 100);
	glTexCoord2d(0, 1);
	glVertex3d(-2*box, box - 90, -box);
	glEnd();

			// - OutSide Stroller:
	glBindTexture(GL_TEXTURE_2D, bottomWindowOut);
	glBegin(GL_QUADS);
	glTexCoord2d(0, 0);
	glVertex3d(-2*box - 5, -10, -box);
	glTexCoord2d(1, 0);
	glVertex3d(-2*box - 5, -10, -box + 100);
	glTexCoord2d(1, 1);
	glVertex3d(-2*box - 5, box - 90, -box + 100);
	glTexCoord2d(0, 1);
	glVertex3d(-2*box - 5, box - 90, -box);
	glEnd();



		// The LeftAndRight - right Window:
			// - InSide Stroller:
	glBindTexture(GL_TEXTURE_2D, rightAndLeftWindow);
	glBegin(GL_QUADS);
	glTexCoord2d(0, 0);
	glVertex3d(-2*box, -10, 4*box);
	glTexCoord2d(1, 0);
	glVertex3d(-2*box, -10, 4*box - 100);
	glTexCoord2d(1, 1);
	glVertex3d(-2*box, box - 90, 4*box - 100);
	glTexCoord2d(0, 1);
	glVertex3d(-2*box, box - 90, 4*box);
	glEnd();

			// - OutSide Stroller:
	glBindTexture(GL_TEXTURE_2D, bottomWindowOut);
	glBegin(GL_QUADS);
	glTexCoord2d(0, 0);
	glVertex3d(-2*box - 5, -10, 4*box);
	glTexCoord2d(1, 0);
	glVertex3d(-2*box - 5, -10, 4*box - 100);
	glTexCoord2d(1, 1);
	glVertex3d(-2*box - 5, box - 90, 4*box - 100);
	glTexCoord2d(0, 1);
	glVertex3d(-2*box - 5, box - 90, 4*box);
	glEnd();
		// --------------------------------------------
	

	// The Right Window
		// The bottom wall:
				// - InSide Stroller:
	glBindTexture(GL_TEXTURE_2D, bottomWindow);
	glBegin(GL_QUADS);
	glTexCoord2d(0, 0);
	glVertex3d(box, -box, 4*box);
	glTexCoord2d(1, 0);
	glVertex3d(box, -box, -box);
	glTexCoord2d(1, 1);
	glVertex3d(box, 0, -box);
	glTexCoord2d(0, 1);
	glVertex3d(box, 0, 4*box);
	glEnd();
				// - Outside Stroller:
	glBindTexture(GL_TEXTURE_2D, bottomWindowOut);
	glBegin(GL_QUADS);
	glTexCoord2d(0, 0);
	glVertex3d(box+5, -box, 4*box);
	glTexCoord2d(1, 0);
	glVertex3d(box+5, -box, -box);
	glTexCoord2d(1, 1);
	glVertex3d(box+5, 0, -box);
	glTexCoord2d(0, 1);
	glVertex3d(box+5, 0, 4*box);
	glEnd();
		//------------------------------------------

		// The top Wall:
			// - InSide Stroller:
	glBindTexture(GL_TEXTURE_2D, topWindow);
	glBegin(GL_QUADS);
	glTexCoord2d(0, 0);
	glVertex3d(box, box - 100, 4*box);
	glTexCoord2d(1, 0);
	glVertex3d(box, box - 100, -box);
	glTexCoord2d(1, 1);
	glVertex3d(box, box, -box);
	glTexCoord2d(0, 1);
	glVertex3d(box, box, 4*box);
	glEnd();
		
			// - OutSide Stroller:
	glBindTexture(GL_TEXTURE_2D, topWindowOut);
	glBegin(GL_QUADS);
	glTexCoord2d(0, 0);
	glVertex3d(box + 5, box - 100, 4*box);
	glTexCoord2d(1, 0);
	glVertex3d(box + 5, box - 100, -box);
	glTexCoord2d(1, 1);
	glVertex3d(box + 5, box, -box);
	glTexCoord2d(0, 1);
	glVertex3d(box + 5, box, 4*box);
	glEnd();
		//------------------------------------------

		// The Center Wall:
			// - InSide Stroller:
	glBindTexture(GL_TEXTURE_2D, centerWindow);
	glBegin(GL_QUADS);
	glTexCoord2d(0, 0);
	glVertex3d(box, -10, box + 200);
	glTexCoord2d(1, 0);
	glVertex3d(box, -10, 2*box - 100);
	glTexCoord2d(1, 1);
	glVertex3d(box, box - 90, 2*box - 100);
	glTexCoord2d(0, 1);
	glVertex3d(box, box - 90, box + 200);
	glEnd();

			// - OutSide Stroller:
	glBindTexture(GL_TEXTURE_2D, bottomWindowOut);
	glBegin(GL_QUADS);
	glTexCoord2d(0, 0);
	glVertex3d(box + 5, -10, box + 200);
	glTexCoord2d(1, 0);
	glVertex3d(box + 5, -10, 2*box - 100);
	glTexCoord2d(1, 1);
	glVertex3d(box + 5, box - 90, 2*box - 100);
	glTexCoord2d(0, 1);
	glVertex3d(box + 5, box - 90, box + 200);
	glEnd();
		//------------------------------------------

		// The LeftAndRight -right Window:
			// - InSide Stroller:
	glBindTexture(GL_TEXTURE_2D, rightAndLeftWindow);
	glBegin(GL_QUADS);
	glTexCoord2d(0, 0);
	glVertex3d(box, -10, -box);
	glTexCoord2d(1, 0);
	glVertex3d(box, -10, -box + 100);
	glTexCoord2d(1, 1);
	glVertex3d(box, box - 90, -box + 100);
	glTexCoord2d(0, 1);
	glVertex3d(box, box - 90, -box);
	glEnd();

			// - OutSide Stroller:
	glBindTexture(GL_TEXTURE_2D, bottomWindowOut);
	glBegin(GL_QUADS);
	glTexCoord2d(0, 0);
	glVertex3d(box + 5, -10, -box);
	glTexCoord2d(1, 0);
	glVertex3d(box + 5, -10, -box + 100);
	glTexCoord2d(1, 1);
	glVertex3d(box + 5, box - 90, -box + 100);
	glTexCoord2d(0, 1);
	glVertex3d(box + 5, box - 90, -box);
	glEnd();



		// The LeftAndRight - left Window:
			// - InSide Stroller:
	glBindTexture(GL_TEXTURE_2D, rightAndLeftWindow);
	glBegin(GL_QUADS);
	glTexCoord2d(0, 0);
	glVertex3d(box, -10, 4*box);
	glTexCoord2d(1, 0);
	glVertex3d(box, -10, 4*box - 100);
	glTexCoord2d(1, 1);
	glVertex3d(box, box - 90, 4*box - 100);
	glTexCoord2d(0, 1);
	glVertex3d(box, box - 90, 4*box);
	glEnd();

			// - OutSide Stroller:
	glBindTexture(GL_TEXTURE_2D, bottomWindowOut);
	glBegin(GL_QUADS);
	glTexCoord2d(0, 0);
	glVertex3d(box + 5, -10, 4*box);
	glTexCoord2d(1, 0);
	glVertex3d(box + 5, -10, 4*box - 100);
	glTexCoord2d(1, 1);
	glVertex3d(box + 5, box - 90, 4*box - 100);
	glTexCoord2d(0, 1);
	glVertex3d(box + 5, box - 90, 4*box);
	glEnd();
		// --------------------------------------------

}

void train::firstStroller(float box,
						 int front, int back,
						 int bottomWindow, int topWindow, int centerWindow, int rightAndLeftWindow,
						 int floorStroller, int ceilStroller,
						  int bottomWindowOut, int topWindowOut
						 ) {
	glBindTexture(GL_TEXTURE_2D, front);
	glBegin(GL_QUADS);
	glTexCoord2d(0, 0);
	glVertex3d(-2*box, -box, -box);
	glTexCoord2d(1, 0);
	glVertex3d(0, -box, -box);
	glTexCoord2d(1, 1);
	glVertex3d(0, box, -box);
	glTexCoord2d(0, 1);
	glVertex3d(-2*box, box, -box);
	glEnd();

	glBindTexture(GL_TEXTURE_2D, back);
	glBegin(GL_QUADS);
	glTexCoord2d(0, 0);
	glVertex3d(-2*box, -box, 4*box);
	glTexCoord2d(1, 0);
	glVertex3d(box, -box, 4*box);
	glTexCoord2d(1, 1);
	glVertex3d(box, box, 4*box);
	glTexCoord2d(0, 1);
	glVertex3d(-2*box, box, 4*box);
	glEnd();

	// The Ceil:
		// - InSide Stroller:
	glBindTexture(GL_TEXTURE_2D, ceilStroller);
	glBegin(GL_QUADS);
	glTexCoord2d(0, 0);
	glVertex3d(-2*box, box, -box);
	glTexCoord2d(1, 0);
	glVertex3d(box, box, -box);
	glTexCoord2d(1, 1);
	glVertex3d(box, box, 4*box);
	glTexCoord2d(0, 1);
	glVertex3d(-2*box, box, 4*box);
	glEnd();

		// - OutSide Stroller:
	glBindTexture(GL_TEXTURE_2D, bottomWindowOut);
	glBegin(GL_QUADS);
	glTexCoord2d(0, 0);
	glVertex3d(-2*box, box + 5, -box);
	glTexCoord2d(1, 0);
	glVertex3d(box, box + 5, -box);
	glTexCoord2d(1, 1);
	glVertex3d(box, box + 5, 4*box);
	glTexCoord2d(0, 1);
	glVertex3d(-2*box, box + 5, 4*box);
	glEnd();
		// ----------------------------------
		
	// The Floor:
	glBindTexture(GL_TEXTURE_2D, floorStroller);
	glBegin(GL_QUADS);
	glTexCoord2d(0, 0);
	glVertex3d(-2*box, -box, -box);
	glTexCoord2d(10, 0);
	glVertex3d(box, -box, -box);
	glTexCoord2d(10, 10);
	glVertex3d(box, -box, 4*box);
	glTexCoord2d(0, 10);
	glVertex3d(-2*box, -box, 4*box);
	glEnd();
	
	// The Left Window

		// The bottom wall:
				// - InSide Stroller:
	glBindTexture(GL_TEXTURE_2D, bottomWindow);
	glBegin(GL_QUADS);
	glTexCoord2d(0, 0);
	glVertex3d(-2*box, -box, 4*box);
	glTexCoord2d(1, 0);
	glVertex3d(-2*box, -box, -box);
	glTexCoord2d(1, 1);
	glVertex3d(-2*box, 0, -box);
	glTexCoord2d(0, 1);
	glVertex3d(-2*box, 0, 4*box);
	glEnd();
				// - Outside Stroller:
	glBindTexture(GL_TEXTURE_2D, bottomWindowOut);
	glBegin(GL_QUADS);
	glTexCoord2d(0, 0);
	glVertex3d(-2*box-5, -box, 4*box);
	glTexCoord2d(1, 0);
	glVertex3d(-2*box-5, -box, -box);
	glTexCoord2d(1, 1);
	glVertex3d(-2*box-5, 0, -box);
	glTexCoord2d(0, 1);
	glVertex3d(-2*box-5, 0, 4*box);
	glEnd();
		//------------------------------------------

		// The top Wall:
			// - InSide Stroller:
	glBindTexture(GL_TEXTURE_2D, topWindow);
	glBegin(GL_QUADS);
	glTexCoord2d(0, 0);
	glVertex3d(-2*box, box -100, 4*box);
	glTexCoord2d(1, 0);
	glVertex3d(-2*box, box -100, -box);
	glTexCoord2d(1, 1);
	glVertex3d(-2*box, box, -box);
	glTexCoord2d(0, 1);
	glVertex3d(-2*box, box, 4*box);
	glEnd();
		
			// - OutSide Stroller:
	glBindTexture(GL_TEXTURE_2D, topWindowOut);
	glBegin(GL_QUADS);
	glTexCoord2d(0, 0);
	glVertex3d(-2*box - 5, box -100, 4*box);
	glTexCoord2d(1, 0);
	glVertex3d(-2*box - 5, box -100, -box);
	glTexCoord2d(1, 1);
	glVertex3d(-2*box - 5, box, -box);
	glTexCoord2d(0, 1);
	glVertex3d(-2*box - 5, box, 4*box);
	glEnd();
		//------------------------------------------

		// The Center Wall:
			// - InSide Stroller:
	glBindTexture(GL_TEXTURE_2D, centerWindow);
	glBegin(GL_QUADS);
	glTexCoord2d(0, 0);
	glVertex3d(-2*box, -10, box + 200);
	glTexCoord2d(1, 0);
	glVertex3d(-2*box, -10, 2*box - 100);
	glTexCoord2d(1, 1);
	glVertex3d(-2*box, box - 90, 2*box - 100);
	glTexCoord2d(0, 1);
	glVertex3d(-2*box, box - 90, box + 200);
	glEnd();

			// - OutSide Stroller:
	glBindTexture(GL_TEXTURE_2D, bottomWindowOut);
	glBegin(GL_QUADS);
	glTexCoord2d(0, 0);
	glVertex3d(-2*box - 5, -10, box + 200);
	glTexCoord2d(1, 0);
	glVertex3d(-2*box - 5, -10, 2*box - 100);
	glTexCoord2d(1, 1);
	glVertex3d(-2*box - 5, box - 90, 2*box - 100);
	glTexCoord2d(0, 1);
	glVertex3d(-2*box - 5, box - 90, box + 200);
	glEnd();
		//------------------------------------------

		// The LeftAndRight - right Window:
			// - InSide Stroller:
	glBindTexture(GL_TEXTURE_2D, rightAndLeftWindow);
	glBegin(GL_QUADS);
	glTexCoord2d(0, 0);
	glVertex3d(-2*box, -10, -box);
	glTexCoord2d(1, 0);
	glVertex3d(-2*box, -10, -box + 100);
	glTexCoord2d(1, 1);
	glVertex3d(-2*box, box - 90, -box + 100);
	glTexCoord2d(0, 1);
	glVertex3d(-2*box, box - 90, -box);
	glEnd();

			// - OutSide Stroller:
	glBindTexture(GL_TEXTURE_2D, bottomWindowOut);
	glBegin(GL_QUADS);
	glTexCoord2d(0, 0);
	glVertex3d(-2*box - 5, -10, -box);
	glTexCoord2d(1, 0);
	glVertex3d(-2*box - 5, -10, -box + 100);
	glTexCoord2d(1, 1);
	glVertex3d(-2*box - 5, box - 90, -box + 100);
	glTexCoord2d(0, 1);
	glVertex3d(-2*box - 5, box - 90, -box);
	glEnd();



		// The LeftAndRight - right Window:
			// - InSide Stroller:
	glBindTexture(GL_TEXTURE_2D, rightAndLeftWindow);
	glBegin(GL_QUADS);
	glTexCoord2d(0, 0);
	glVertex3d(-2*box, -10, 4*box);
	glTexCoord2d(1, 0);
	glVertex3d(-2*box, -10, 4*box - 100);
	glTexCoord2d(1, 1);
	glVertex3d(-2*box, box - 90, 4*box - 100);
	glTexCoord2d(0, 1);
	glVertex3d(-2*box, box - 90, 4*box);
	glEnd();

			// - OutSide Stroller:
	glBindTexture(GL_TEXTURE_2D, bottomWindowOut);
	glBegin(GL_QUADS);
	glTexCoord2d(0, 0);
	glVertex3d(-2*box - 5, -10, 4*box);
	glTexCoord2d(1, 0);
	glVertex3d(-2*box - 5, -10, 4*box - 100);
	glTexCoord2d(1, 1);
	glVertex3d(-2*box - 5, box - 90, 4*box - 100);
	glTexCoord2d(0, 1);
	glVertex3d(-2*box - 5, box - 90, 4*box);
	glEnd();
		// --------------------------------------------
	


	// The Right Window
		// The top Wall:
			// - InSide Stroller:
	glBindTexture(GL_TEXTURE_2D, topWindow);
	glBegin(GL_QUADS);
	glTexCoord2d(0, 0);
	glVertex3d(box, box - 100, 4*box);
	glTexCoord2d(1, 0);
	glVertex3d(box, box - 100, -box);
	glTexCoord2d(1, 1);
	glVertex3d(box, box, -box);
	glTexCoord2d(0, 1);
	glVertex3d(box, box, 4*box);
	glEnd();
		
			// - OutSide Stroller:
	glBindTexture(GL_TEXTURE_2D, topWindowOut);
	glBegin(GL_QUADS);
	glTexCoord2d(0, 0);
	glVertex3d(box + 5, box - 100, 4*box);
	glTexCoord2d(1, 0);
	glVertex3d(box + 5, box - 100, -box);
	glTexCoord2d(1, 1);
	glVertex3d(box + 5, box, -box);
	glTexCoord2d(0, 1);
	glVertex3d(box + 5, box, 4*box);
	glEnd();
		//------------------------------------------

		// The LeftAndRight -right Window:
			// - InSide Stroller:
	glBindTexture(GL_TEXTURE_2D, rightAndLeftWindow);
	glBegin(GL_QUADS);
	glTexCoord2d(0, 0);
	glVertex3d(box, -box, -box);
	glTexCoord2d(1, 0);
	glVertex3d(box, -box, -box + 100);
	glTexCoord2d(1, 1);
	glVertex3d(box, box - 90, -box + 100);
	glTexCoord2d(0, 1);
	glVertex3d(box, box - 90, -box);
	glEnd();

			// - OutSide Stroller:
	glBindTexture(GL_TEXTURE_2D, bottomWindowOut);
	glBegin(GL_QUADS);
	glTexCoord2d(0, 0);
	glVertex3d(box + 5, -box, -box);
	glTexCoord2d(1, 0);
	glVertex3d(box + 5, -box, -box + 100);
	glTexCoord2d(1, 1);
	glVertex3d(box + 5, box - 90, -box + 100);
	glTexCoord2d(0, 1);
	glVertex3d(box + 5, box - 90, -box);
	glEnd();



		// The LeftAndRight - left Window:
			// - InSide Stroller:
	glBindTexture(GL_TEXTURE_2D, rightAndLeftWindow);
	glBegin(GL_QUADS);
	glTexCoord2d(0, 0);
	glVertex3d(box, -box, 4*box);
	glTexCoord2d(1, 0);
	glVertex3d(box, -box, 4*box - 100);
	glTexCoord2d(1, 1);
	glVertex3d(box, box - 90, 4*box - 100);
	glTexCoord2d(0, 1);
	glVertex3d(box, box - 90, 4*box);
	glEnd();

			// - OutSide Stroller:
	glBindTexture(GL_TEXTURE_2D, bottomWindowOut);
	glBegin(GL_QUADS);
	glTexCoord2d(0, 0);
	glVertex3d(box + 5, -box, 4*box);
	glTexCoord2d(1, 0);
	glVertex3d(box + 5, -box, 4*box - 100);
	glTexCoord2d(1, 1);
	glVertex3d(box + 5, box - 90, 4*box - 100);
	glTexCoord2d(0, 1);
	glVertex3d(box + 5, box - 90, 4*box);
	glEnd();
		// --------------------------------------------	
	}