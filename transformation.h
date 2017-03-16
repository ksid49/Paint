int sel_item=-1;
void selection(int x,int y)
{
    int i,j,len,min=9999;

    for(i=0;i<=li;i++)
    {
        for(j=0;j<l[i].counter;j++)
        {
            len=sqrt(pow(l[i].p[j][0]-x,2)+pow(l[i].p[j][1]-y,2));
            /*if(x==l[i].p[j][0]&&y==l[i].p[j][1])
                    {
                        sel_item=i;

                    }
            */
            if(len<min)
            {
                min=len;
                sel_item=i;
            }
        }
    }

}
void translation(Point p1, Point p2)
{

    int tx,ty,a;
    a=sel_item;
    tx=p2.x-p1.x;
    ty=p2.y-p1.y;
    for(int i=0;i<l[a].counter;i++)
    {
        glBegin(GL_POINTS);
        glColor3f(1,1,1);
        glVertex2i(l[a].p[i][0],l[a].p[i][1]);
         glEnd();
        draw_point(l[a].p[i][0]+tx,l[a].p[i][1]+ty);
        l[a].p[i][0]=l[a].p[i][0]+tx;
        l[a].p[i][1]=l[a].p[i][1]+ty;

    }

}

float matrix[3][3];

void scaleMatrix(float sx, float sy, int x, int y)
{
	matrix[0][0] = sx;
	matrix[0][1] = 0;
	matrix[0][2] = x*(1 - sx);

	matrix[1][0] = 0;
	matrix[1][1] = sy;
	matrix[1][2] = y*(1 - sy);

	matrix[2][0] = 0;
	matrix[2][1] = 0;
	matrix[2][2] = 1;
}
void scale()
	{
		int tempX; int tempY,a;

        a=sel_item;
        cout<<Sx<<" "<<Sy;

		 for(int i=0;i<l[a].counter;i++)
		{
		    glBegin(GL_POINTS);
            glColor3f(1,1,1);
            glVertex2i(l[a].p[i][0],l[a].p[i][1]);
            glEnd();

			int tempX = l[a].p[i][0]*matrix[0][0] + l[a].p[i][1]*matrix[0][1] + matrix[0][2];
			int tempY = l[a].p[i][0]*matrix[1][0] + l[a].p[i][1]*matrix[1][1] + matrix[1][2];
			l[a].p[i][0]=tempX;
            l[a].p[i][1]=tempY;
			draw_point(tempX,tempY);
		}
		transform=0;
	}

void rotationMatrix(int x, int y, float theta)
{

	matrix[0][0] = cos(theta);
	//cout << endl << "In matrix" << cos(theta)<<","<<matrix[0][0];
	matrix[0][1] = -sin(theta);
	matrix[0][2] = x*(1 - cos(theta)) + y*sin(theta);

	matrix[1][0] = sin(theta);
	matrix[1][1] = cos(theta);
	matrix[1][2] = y*(1 - cos(theta)) - x*sin(theta);

	matrix[2][0] = 0;
	matrix[2][1] = 0;
	matrix[2][2] = 1;
}

void rotate2d()
	{
		int tempX; int tempY;
		int a=sel_item;

		 for(int i=0;i<l[a].counter;i++)
		{
			glBegin(GL_POINTS);
            glColor3f(1,1,1);
            glVertex2i(l[a].p[i][0],l[a].p[i][1]);
            glEnd();

			int tempX = l[a].p[i][0]*matrix[0][0] + l[a].p[i][1]*matrix[0][1] + matrix[0][2];
			int tempY = l[a].p[i][0]*matrix[1][0] + l[a].p[i][1]*matrix[1][1] + matrix[1][2];
			l[a].p[i][0]=tempX;
            l[a].p[i][1]=tempY;
			draw_point(tempX,tempY);
		}
        transform=0;
	}

void draw_polygon(Point p1, Point p2)
{
  //  if()
}



