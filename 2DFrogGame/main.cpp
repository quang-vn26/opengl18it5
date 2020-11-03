#include <math.h>//ap dung 1 so thuat toan ...

#include <GL/glut.h>

#include <iostream>

#include <vector>

//them mot so thu vien vao
#include "../Library/Loadpng.h"
#include "../Library/process_image.h"
#include "../Library/gl_texture.h"

//xac dinh kich thuoc cua so
#define WIDTH 720
#define HEIGHT 384
//xu ly thay doi cua cua so, khi goi lai thi ve lai hoan toan
void Display(){
	glClear(GL_COLOR_BUFFER_BIT);
	glLoadIdentity();//reset he toa do
	glutSwapBuffers();//
}

void init() {
    glClearColor(1.0, 1.0, 1.0, 0.0);
    glColor3f(0.0f, 0.0f, 0.0f);
    glPointSize(1.0f);
    gluOrtho2D(0.0f, 640.0f, 0.0f, 480.0f);
}
int main(int argc, char **argv) {
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_DEPTH|GLUT_DOUBLE|GLUT_RGB);

	//lap toa do cho window
	int POS_X = (glutGet(GLUT_SCREEN_WIDTH)-WIDTH)>>1;//dich sang phai 1 tuc la chia cho 2
	int POS_Y = (glutGet(GLUT_SCREEN_HEIGHT)-HEIGHT)>>1;
	glutInitWindowPosition(POS_X,POS_Y);
	glutInitWindowSize(WIDTH,HEIGHT);
	glutCreateWindow("FROG 2D Game");
	glutDisplayFunc(Display);
	glutMainLoop();
	init();
	return 0;
}
