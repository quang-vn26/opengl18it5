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
#define CELL_SIZE 24
#define MAX_X 30
#define MAX_Y 24
#define CLOUD_COUNT 3
#define PLATFORMER_COUNT 6

Rect Rct_Background = {0,720,48,384},Rct_Ground ={0,720,0,48};

Image Img_Background,Img_Ground;

//mang de thiet lap toa do
int Map[MAX_X][MAX_Y];

class c_Platformer {
public:
    static Image Img_Save;
    Rect Rct;
    Image *Img;
 	static void Load_Image() {
        Load_Texture_Swap(&Img_Save, "Images/Platformer.png");
        Zoom_Image(&Img_Save,SCALE);
    }
    void Init(int _x, int _y) {
        Map[_y][_x] = Map[_y][_x + 1] = Map[_y][_x + 2] = Map[_y][_x + 3] = 1;
        Img = &Img_Save;
        float x = START_X + (_x + 2) * CELL_SIZE;
        float y = START_Y + _y * CELL_SIZE;
        Rct.Left = x - Img->w / 2;
        Rct.Right = Rct.Left + Img->w;
        Rct.Bottom = y;
        Rct.Top = Rct.Bottom + Img->h;
    }

    void Draw() {
        Map_Texture(Img);
        Draw_Rect(&Rct);
    }
};

Image c_Platformer::Img_Save;

c_Platformer Platformers[PLATFORMER_COUNT];

//xu ly thay doi cua cua so, khi goi lai thi ve lai hoan toan
void Display(){
	glClear(GL_COLOR_BUFFER_BIT);
	glLoadIdentity();//reset he toa do

    Map_Texture(&Img_Background);
    Draw_Rect(&Rct_Background);
    Map_Texture(&Img_Ground);
    Draw_Rect(&Rct_Ground);

    for(int i =0;i<PLATFORMER_COUNT;i++){
        Platformers[i].Draw();
    }
	glutSwapBuffers();//
}

void Init_Game(){
    //load anh va phong to
    Load_Texture_Swap(&Img_Background,"./Images/Background.png");
    Zoom_Image(&Img_Background,SCALE);
    Load_Texture_Swap(&Img_Ground,"./Images/Ground.png");
    Zoom_Image(&Img_Ground,3);

    //nhung o ben duoi co gia tri 1, 1 la gia tri cua vat can
    for (int i = 0; i < 2; i++)
        for (int j = 0; j < MAX_X; j++)
            Map[i][j] = 1;
    // nhung o ben tren co gia tri 0 nhu khong khi,...        
    for (int i = 2; i < MAX_Y; i++)
        for (int j = 0; j < MAX_X; j++)
            Map[i][j] = 0;
    c_Platformer::Load_Image();  

    //6 cai buc
    Platformers[0].Init(7, 5);
    Platformers[1].Init(19, 5);
    Platformers[2].Init(5, 9);
    Platformers[3].Init(21, 9);
    Platformers[4].Init(9, 13);
    Platformers[5].Init(17, 13);
         
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
//    printf("Hello");
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
