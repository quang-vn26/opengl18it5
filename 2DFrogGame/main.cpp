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
//fps dat 50 goi lai ham Display() moi 15s
#define INTERVAL 15

//xu ly thay doi cua cua so, khi goi lai thi ve lai hoan toan
void Display(){
	glClear(GL_COLOR_BUFFER_BIT);
	glLoadIdentity();//reset he toa do
	glutSwapBuffers();//
}

void Init_GL() {
    glClearColor(0.0f, 0.0f, 0.0f, 1.0f);
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    glViewport(0, 0, WIDTH, HEIGHT);
    gluOrtho2D(0, WIDTH, 0, HEIGHT);
    glMatrixMode(GL_MODELVIEW);
    glEnable(GL_BLEND);
    glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);
    glEnable(GL_LINE_SMOOTH);
    glTexParameterf(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_REPEAT);
    glTexParameterf(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_REPEAT);
    glTexParameterf(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_NEAREST);
    glTexParameterf(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_NEAREST);
//    glutIgnoreKeyRepeat(GL_TRUE);
    glEnable(GL_TEXTURE_2D);
    // adfsad

//    Game_State = GAME_PLAY;
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
	Init_GL();
	glutDisplayFunc(Display);
	glutMainLoop();
	return 0;
}
