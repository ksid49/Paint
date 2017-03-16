#include <gl/glut.h>
#include <math.h>
#include <iostream>
using namespace std;
#define pi 3.14159
#include "draw.h"
#include "transformation.h"
#include<vector>
#include "algo.h"
#include "color.h"

void changeScale(int key, int x, int y)
{
	if (key == GLUT_KEY_UP)
	{
		Sy = Sy + 0.2;
		cout << "\nIncreased Sy";
	}
	if (key == GLUT_KEY_DOWN)
	{
		if (!((Sy - 0.2)<0))
			Sy = Sy - 0.2;
	}
	if (key == GLUT_KEY_LEFT)
	{
		if (!(Sx - 0.2<0))
			Sx = Sx - 0.2;
	}
	if (key == GLUT_KEY_RIGHT)
	{
		Sx = Sx + 0.2;
		cout<<"Increased Sx";
	}
}
void Mouse(int button, int state, int x, int y)
{
    int ch=0;
    int z=y;
    y=650-y;

	if(button == GLUT_LEFT_BUTTON && state == GLUT_DOWN)
    {
        p1.x=x;
        p1.y=y;

        for(i=1;i<=28;i++)
        {
            if(x>b[i].x1&& x<b[i].x2&&y>b[i].y1&& y<b[i].y2)
            ch=i;
        }
        switch(ch)
        {
            case 2:if(drop_down==1)
                    {
                        shape=1;
                        algo=1;
                        drop_down=0;
                    }
                    break;
            case 3:if(drop_down==1)
                    {
                        shape=1;
                        algo=1;
                        drop_down=0;
                    }
                    break;
            case 4:if(drop_down==1)
                    {
                        shape=1;
                        algo=1;
                        drop_down=0;
                    }
                    break;
            case 6:if(drop_down==2)
                    {
                        shape=2;
                        algo=2;
                        drop_down=0;
                    }
                    break;
            case 7:if(drop_down==2)
                    {
                        shape=2;
                        algo=2;
                        drop_down=0;
                    }
                    break;
            case 9:if(drop_down==3)
                    {
                        shape=3;
                        algo=2;
                        drop_down=0;
                    }
                    break;
            case 10:if(drop_down==3)
                    {
                        shape=3;
                        algo=2;
                        drop_down=0;
                    }
                    break;
            case 12:if(drop_down==4)
                    {
                        type=1;
                        drop_down=0;
                    }
                    break;
            case 13:if(drop_down==4)
                    {
                        type=2;
                        drop_down=0;
                    }
                    break;
            case 14:if(drop_down==4)
                    {
                        type=3;
                        drop_down=0;
                    }
                    break;
            case 19:thickness++;
                    break;
            case 20:thickness--;
                    break;
            case 16:if(drop_down==5)
                    {
                        colour=1;
                        drop_down=0;
                    }
                    break;
            case 17:if(drop_down==5)
                    {
                        colour=2;
                        drop_down=0;
                    }
                    break;
            case 18:if(drop_down==5)
                    {
                        colour=3;
                        drop_down=0;
                    }
                    break;
            case 21: glClear(GL_COLOR_BUFFER_BIT);
                    li=0;
                    break;
            case 23:if(drop_down==6)
                    {
                        shape=0;
                        select=0;
                        fill_algo=1;
                        drop_down=0;
                    }
                    break;
            case 24:if(drop_down==6)
                    {
                        shape=0;
                        select=0;
                        fill_algo=2;
                        drop_down=0;
                    }
                    break;
            case 26:if(drop_down==7)
                    {
                        shape=0;
                        select=1;
                        transform=1;
                        drop_down=0;
                    }

                    break;
            case 27:if(drop_down==7)
                    {
                        shape=0;
                        select=1;
                        transform=2;
                        drop_down=0;
                    }

                    break;
            case 28:
                        shape=4;


                    break;


        }


    }




	else if(button == GLUT_LEFT_BUTTON && state == GLUT_UP)
    {
        p2.x=x;
        p2.y=y;
        int slope;
    if(shape==1||shape==2||shape==3)
    {


        if(algo==1)
        {
            if(p2.x!=p1.x)
                slope=abs(p2.y-p1.y)/abs(p2.x-p1.x);


            simple(p1,p2);
            for(i=1;i<=thickness;i++)
            {


                if(slope<=1&&memcmp(&p1,&p2,sizeof(p1)))
                {
                    p1.y++;
                    p2.y++;
                    simple(p1,p2);

                }
                else if(memcmp(&p1,&p2,sizeof(p1)))
                {
                    p1.x++;
                    p2.x++;
                    simple(p1,p2);

                }
            }
        }
        else if(algo==2)
        {
            midpoint(p1,p2);

        }
        else if(algo==3)
        {
            bresenham(p1,p2);
        }
    }
    else if(shape==0)
    {
        if(fill_algo==1&&select==0)
        {


            unsigned char a[3];
            float c[3];
            glReadPixels(p2.x,p2.y,1.0,1.0,GL_RGB,GL_UNSIGNED_BYTE,a);
            c[0] = (float)a[0]/255.0;
            c[1] = (float)a[1]/255.0;
            c[2] = (float)a[2]/255.0;
            floodfill(p2.x,p2.y,c);
        }
        else if(fill_algo==2&&select==0)
        {
            float newcolor[3];
            {
                if(Bcolorcheck==0)
                {
                    BoundaryColor[0]=cl[0];
                    BoundaryColor[1]=cl[1];
                    BoundaryColor[2]=cl[2];
                    Bcolorcheck++;

                }
                colorselection();
                newcolor[0]=cl[0];
                newcolor[1]=cl[1];
                newcolor[2]=cl[2];
                BoundaryFill(p2.x,p2.y,BoundaryColor,newcolor);
            }

        }
        else if(select==1)
        {

            if(transform==1)
            {
                scaleMatrix(Sx,Sy,px,py);
                scale();
            }
            else if(transform==2)
            {
                rotationMatrix(px,py,theta);
                rotate2d();
            }
        }
    }
    else if(shape==4)
    {
//        draw_polygon(p2.x,p2.y);
    }
    }
    else if(button == GLUT_RIGHT_BUTTON && state == GLUT_DOWN)
    {
        px=x;
        py=y;
        p1.x=x;
        p1.y=y;
        shape=0;
       selection(x,y);
    }
    else if(button == GLUT_RIGHT_BUTTON && state == GLUT_UP)
    {
        p2.x=x;
        p2.y=y;
        translation(p1,p2);
    }



}
void reshape (int w, int h)
{
    glViewport (0, 0, (GLsizei) w, (GLsizei) h);
    glMatrixMode (GL_PROJECTION);
    glLoadIdentity ();
    gluOrtho2D(0,GLdouble (w),0,GLdouble (h));
    glMatrixMode(GL_MODELVIEW);


}
void display(void)
{

    //for x-axis and y-axis
    glBegin(GL_LINES);
    glColor3f(0,0,0);
    glVertex2f(0, 275);
    glVertex2f(1300, 275);
    glVertex2f(650, 0);
    glVertex2f(650, 650);
    glEnd();
    glFlush();
    //for taskbar
     glBegin(GL_QUADS);
        glColor3d(0.8,0.8,0.8);
        glVertex2f(0,550);

        glVertex2f(0,650);

        glVertex2f(1300,650);

        glVertex2f(1300,550);
     glEnd();
    glFlush();
    //for buttons
    createbutton(2,70,620,640);
    maketext(20,625,"LINE");
    createbutton(80,150,620,640);
    maketext(90,625,"CIRCLE");
    createbutton(160,230,620,640);
    maketext(170,625,"ELLIPSE");
    createbutton(240,310,620,640);
    maketext(250,625,"TYPE");
    createbutton(320,390,620,640);
    maketext(330,625,"COLOUR");

    createbutton(400,470,620,640);
    maketext(400,625,"THICKNESS++");
    createbutton(480,550,620,640);
    maketext(480,625,"THICKNESS--");
    createbutton(560,630,620,640);
    maketext(560,625,"COLOR-FILL");
    createbutton(640,710,620,640);
    maketext(640,625,"TRANSFORM");
    createbutton(720,790,620,640);
    maketext(725,625,"POLYGON");


    createbutton(1200,1290,610,640);
    maketext(1220,620,"CLEAR");

    glFlush();



}
void passive(int x,int y)
{
    int i,ch=0;
    y=650-y;
    for(i=1;i<=28;i++)
    {
        if(x>b[i].x1&& x<b[i].x2&&y>b[i].y1&& y<b[i].y2)
            ch=i;
    }

    switch (ch)
    {
       case 1: createbutton(2,70,600,620);
               maketext(10,605,"SIMPLE");
               createbutton(2,70,580,600);
               maketext(5,585,"BRESENHAM");
               createbutton(2,70,560,580);
               maketext(10,565,"MIDPOINT");
               drop_down=1;
               break;
       case 5: createbutton(80,150,600,620);
               maketext(85,605,"BRESENHAM");
               createbutton(80,150,580,600);
               maketext(85,585,"MIDPOINT");
               drop_down=2;
               break;
       case 8: createbutton(160,230,600,620);
               maketext(165,605,"BRESENHAM");
               createbutton(160,230,580,600);
               maketext(165,585,"MIDPOINT");
               drop_down=3;
               break;
       case 11: createbutton(240,310,600,620);
               maketext(250,605,"REGULAR");
               createbutton(240,310,580,600);
               maketext(250,585,"DOTTED");
               createbutton(240,310,560,580);
               maketext(250,565,"DASHED");
               drop_down=4;
               break;
       case 15: createbutton(320,390,600,620);
               maketext(330,605,"RED");
               createbutton(320,390,580,600);
               maketext(330,585,"GREEN");
               createbutton(320,390,560,580);
               maketext(330,565,"BLUE");
               drop_down=5;
               break;
        case 22: createbutton(560,630,600,620);
               maketext(565,605,"FLOOD FILL");
               createbutton(560,630,580,600);
               maketext(565,585,"BOUND-FILL");
               drop_down=6;
               break;
        case 25:createbutton(640,710,600,620);
               maketext(645,605,"SCALING");
               createbutton(640,710,580,600);
               maketext(645,585,"ROTATION");
               drop_down=7;
               break;
    }

}


void keyboard(unsigned char key, int x, int y)
{

    switch(key)
    {

        case 'q': theta=theta+5*pi/180;
            break;

        case 'w': theta=theta-5*pi/180;
            break;

        default:
           // cout<<key<<endl;
        break;
    }
    //glutPostRedisplay();
    /* this redraws the scene without
    waiting for the display callback so that any changes appear
    instantly */
}


void init() {
	glClearColor(1.0, 1.0, 1.0, 1.0); //change background color
	glClear(GL_COLOR_BUFFER_BIT);
	glColor3f(1.0f, 1.0f, 1.0f);
	glPointSize(1.0f);
	gluOrtho2D(0.0f, w, 0.0f, h);

}

int main(int argc, char **argv) {
	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_SINGLE|GLUT_RGB);
	glutInitWindowPosition(20,20);
	glutInitWindowSize(1300, 650);
	glutCreateWindow("Draw");
    glutPassiveMotionFunc(passive);
    glutReshapeFunc(reshape);
	glutDisplayFunc(display);
	glutSpecialFunc(changeScale);
    init();
	glutMouseFunc(Mouse);
	glutKeyboardFunc(keyboard);

	glutMainLoop();

	return 0;
}
