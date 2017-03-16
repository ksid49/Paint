int w,h,i;
int type=1,algo=1,colour=1,line_width=0,drop_down=0,thickness=0,shape=1,fill_algo=0,select=0;
int dot=1,dash=1;
int q=0,Bcolorcheck=0;
int li=0,lj=0;
int px=650,py=275;
int transform =0;
float Sx=1,Sy=1;
float theta=0;
float BoundaryColor[3],cl[3];
char c;
struct Point {
	int x;
	int y;
};
Point p1, p2;
struct button{
    int x1,x2,y1,y2;
};
struct line {
    int p[2000][2];
    int counter;
};
line l[50];


button b[]={{-1,-1,-1,-1},{2,70,620,640},{2,70,600,620},{2,70,580,600},{2,70,560,580},{80,150,620,640},
{80,150,600,620},{80,150,580,600},{160,230,620,640},{160,230,600,620},{160,230,580,600},{240,310,620,640},
{240,310,600,620},{240,310,580,600},{240,310,560,580},{320,390,620,640},{320,390,600,620},{320,390,580,600},
{320,390,560,580},{400,470,620,640},{480,550,620,640},{1200,1290,610,640},{560,630,620,640},{560,630,600,620},
{560,630,580,600},{640,710,620,640},{640,710,600,620},{640,710,580,600},{720,790,620,640}};
void createbutton(int x1,int x2,int y1,int y2)
{

    glBegin(GL_QUADS);

        glColor3d(0.1,0.6,0.8);

        glVertex2f(x1,y1);
        glVertex2f(x1,y2);
        glVertex2f(x2,y2);
        glVertex2f(x2,y1);

    glEnd();
    glFlush();
    glBegin(GL_LINES);
    glColor3f(0,0,0);
    glVertex2f(x1, y1);
    glVertex2f(x1, y2);
    glVertex2f(x2, y1);
    glVertex2f(x2, y2);

    glVertex2f(x1, y1);
    glVertex2f(x2, y1);
    glVertex2f(x1, y2);
    glVertex2f(x2, y2);
    glEnd();
    glFlush();
}

void maketext(int x, int y,char * string)
{
    glColor3f(1,1,0);
    glRasterPos2f(x, y);
    while(*string!='\0')
    {
    glutBitmapCharacter(GLUT_BITMAP_TIMES_ROMAN_10 ,*string);
    string++;
    }
    glFlush();
}

void draw_point(float x,float y)
{
    glBegin(GL_POINTS);
    if(colour==1)
        glColor3f(1,0,0); //change line color
	else if(colour==2)
        glColor3f(0,1,0);
        else if(colour==3)
        glColor3f(0,0,1);

    if(x>0&&x<1300&&y>0&&y<550)
    {


            if(type==1)
            {
                 glVertex2i(x, y);
            }
            else if(type==2)
            {
                if((dot%2)==0)
                {
                     glVertex2i(x, y);
                }
               // else if((dot%8)==0)
                if(shape==1)
                  dot++;

            }
            else if(type==3)
            {
                if(!(dash%5==0))
                {
                     glVertex2i(x, y);
                }
                dash++;
            }
            glEnd();
    }
	draw_point(x,y);

}

