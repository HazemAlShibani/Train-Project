#include <windows.h>		// Header File For Windows
#include <gl.h>			// Header File For The OpenGL32 Library
#include <glu.h>			// Header File For The GLu32 Library
//#include <glaux.h>		// Header File For The Glaux Library
#include <cmath>
#include <texture.h>
#include "box.h"

void box::skybox(float box, int front, int back, int left, int right , int top, int bottom)
{
	
	glBindTexture(GL_TEXTURE_2D, front);
	glBegin(GL_QUADS);
	glTexCoord2d(0, 0);
	glVertex3d(-box, -box, -box);
	glTexCoord2d(1, 0);
	glVertex3d(box, -box, -box);
	glTexCoord2d(1, 1);
	glVertex3d(box, box, -box);
	glTexCoord2d(0, 1);
	glVertex3d(-box, box, -box);
	glEnd();

	glBindTexture(GL_TEXTURE_2D, back);
	glBegin(GL_QUADS);
	glTexCoord2d(0, 0);
	glVertex3d(-box, -box, 25*box);
	glTexCoord2d(1, 0);
	glVertex3d(box, -box, 25*box);
	glTexCoord2d(1, 1);
	glVertex3d(box, box, 25*box);
	glTexCoord2d(0, 1);
	glVertex3d(-box, box, 25*box);
	glEnd();

	glBindTexture(GL_TEXTURE_2D, left);
	glBegin(GL_QUADS);
	glTexCoord2d(0, 0);
	glVertex3d(-box, -box, 25*box);
	glTexCoord2d(1, 0);
	glVertex3d(-box, -box, -box);
	glTexCoord2d(1, 1);
	glVertex3d(-box, box, -box);
	glTexCoord2d(0, 1);
	glVertex3d(-box, box,25* box);
	glEnd();

	glBindTexture(GL_TEXTURE_2D, right);
	glBegin(GL_QUADS);
	glTexCoord2d(1, 0);
	glVertex3d(box, -box, 25*box);
	glTexCoord2d(0, 0);
	glVertex3d(box, -box, -box);
	glTexCoord2d(0, 1);
	glVertex3d(box, box, -box);
	glTexCoord2d(1, 1);
	glVertex3d(box, box,25* box);
	glEnd();

	glBindTexture(GL_TEXTURE_2D, top);
	glBegin(GL_QUADS);
	glTexCoord2d(0, 0);
	glVertex3d(-box, box, -box);
	glTexCoord2d(1, 0);
	glVertex3d(box, box, -box);
	glTexCoord2d(1, 1);
	glVertex3d(box, box,25* box);
	glTexCoord2d(0, 1);
	glVertex3d(-box, box,25* box);
	glEnd();

	glBindTexture(GL_TEXTURE_2D, bottom);
	glBegin(GL_QUADS);
	glTexCoord2d(0, 0);
	glVertex3d(-box, -box, -box);
	glTexCoord2d(1, 0);
	glVertex3d(box, -box, -box);
	glTexCoord2d(1, 1);
	glVertex3d(box, -box,25* box);
	glTexCoord2d(0, 1);
	glVertex3d(-box, -box,25* box);
	glEnd();

}

