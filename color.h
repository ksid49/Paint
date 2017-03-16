void floodfill(float x,float y,float o[3])
{
    vector<int> v;
    unsigned char a[3];
    int i=0;
    float c[3];
    v.push_back(x);
    v.push_back(y);
    glReadPixels(x,y,1.0,1.0,GL_RGB,GL_UNSIGNED_BYTE,a);
    c[0] = (float)a[0]/255.0;
    c[1] = (float)a[1]/255.0;
    c[2] = (float)a[2]/255.0;

    if(x>0&&x<1300&&y>0&&y<550)
    {


    while(i<v.size())
    {
        x=v[i];
            i++;
            y=v[i];i++;
        glReadPixels(x,y,1.0,1.0,GL_RGB,GL_UNSIGNED_BYTE,a);
    c[0] = (float)a[0]/255.0;
    c[1] = (float)a[1]/255.0;
    c[2] = (float)a[2]/255.0;
        if(c[0]==o[0] && c[1]==o[1] && c[2]==o[2])
        {

            draw_point(x,y);
            v.push_back(x+1);
            v.push_back(y);

            v.push_back(x);
            v.push_back(y+1);
            v.push_back(x-1);
            v.push_back(y);
            v.push_back(x);
            v.push_back(y-1);
            glFlush();
       }
    }

    }
}



void BoundaryFill(int x, int y, float BoundaryColor[], float NewColor[])
{
    unsigned char pixelcolour[3];
    float c[3];
    glReadPixels(x,y,1,1,GL_RGB,GL_UNSIGNED_BYTE,pixelcolour);
    c[0] = (float)pixelcolour[0]/255.0;
    c[1] = (float)pixelcolour[1]/255.0;
    c[2] = (float)pixelcolour[2]/255.0;


    if((c[0]==1&&c[1]==1&&c[2]==1||(c[0]==0&&c[1]==0&&c[2]==0))&&(c[0]!=BoundaryColor[0] || c[1]!=BoundaryColor[1] || c[2]!=BoundaryColor[2]))
    {

        glColor3f((GLfloat)NewColor[0],(GLfloat)NewColor[1],(GLfloat)NewColor[2]);

	   draw_point(x,y);
        glFlush();
        BoundaryFill(x-1,y,BoundaryColor,NewColor);
        BoundaryFill(x+1,y,BoundaryColor,NewColor);
        BoundaryFill(x,y+1,BoundaryColor,NewColor);
        BoundaryFill(x,y-1,BoundaryColor,NewColor);

        return;
     }
}
