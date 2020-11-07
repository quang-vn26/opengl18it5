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
#define SCALE 3.0f
#define RAD 57.295780
#define START_X 0
#define START_Y 0
#define CELL_SIZE 8
#define MAX_X 30
#define MAX_Y 16
#define CLOUD_COUNT 3
#define PLATFORMER_COUNT 6

Rect Rct_Background = {0,WIDTH,48,HEIGHT},Rct_Ground ={0,WIDTH,0,48};
Image Img_Background,Img_Ground;
//xu ly thay doi cua cua so, khi goi lai thi ve lai hoan toan
void Display(){
	glClear(GL_COLOR_BUFFER_BIT);
	glLoadIdentity();//reset he toa do

    Map_Texture($Img_Background);
    Draw_Rect(&Rct_Background);
    Map_Texture($Img_Ground);
    Draw_Rect(&Rct_Ground);

	glutSwapBuffers();//
}

void Init_Game(){
    Load_Texture_Swap($Img_Background,"Image/Background.png");
    Zoom_Image($Img_Background,SCALE);
    Load_Texture_Swap($Img_Ground,"Image/Ground.png");
    Zoom_Image($Img_Ground,SCALE);
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
    glEnable(GL_TEXTURE_2D);
 
    Init_Game();
}
void Timer(int value){
    printf("Hello");
    glutPostRedisplay();
    glutTimerFunc(INTERVAL,Timer,0);
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
    glutTimerFunc(0,Timer,0);

	glutMainLoop();
	return 0;
}
