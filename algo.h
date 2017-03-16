void colorselection()
{
    if(colour==1)
    {
        float b[]={1.0,0.0,0.0};

        for(int i=0;i<3;i++)
            cl[i]=b[i];
    }
    if(colour==2)
    {
        float b[]={0.0,1.0,0.0};
        for(int i=0;i<3;i++)
            cl[i]=b[i];
    }
    if(colour==3)
    {
        float b[]={0.0,0.0,1.0};
        for(int i=0;i<3;i++)
            cl[i]=b[i];
    }
}


void simple(Point p1, Point p2) {


    dash=1;
    lj=0;


	float dx = p2.x - p1.x;
	float dy = p2.y - p1.y;

	float x1 = p1.x;
	float y1 = p1.y;

	float step = 0;

	if(abs(dx) > abs(dy)) {
		step = abs(dx);
	} else {
		step = abs(dy);
	}

	float xInc = dx/step;
	float yInc = dy/step;
    l[li].p[lj][0]=x1;
    l[li].p[lj][1]=y1;
    lj++;
    draw_point(x1,y1);
	for(float i = 2; i <= step; i++)
    {
        x1 += xInc;
		y1 += yInc;
		l[li].p[lj][0]=x1;
        l[li].p[lj][1]=y1;
        lj++;
		draw_point(x1,y1);
	}
	l[li].counter=lj;
    li++;

}


void circleplot(float xc,float yc,float x, float y)
{
    l[li].p[lj][0]=xc+x;
    l[li].p[lj][1]=yc+y;
    draw_point(xc+x,yc+y);
    lj++;
    l[li].p[lj][0]=xc-x;
    l[li].p[lj][1]=yc+y;
    draw_point(xc-x,yc+y);
    lj++;
    l[li].p[lj][0]=xc+x;
    l[li].p[lj][1]=yc-y;
    draw_point(xc+x,yc-y);
    lj++;
    l[li].p[lj][0]=xc-x;
    l[li].p[lj][1]=yc-y;
    draw_point(xc-x,yc-y);
    lj++;
    l[li].p[lj][0]=xc+y;
    l[li].p[lj][1]=yc+x;
    draw_point(xc+y,yc+x);
    lj++;
    l[li].p[lj][0]=xc-y;
    l[li].p[lj][1]=yc+x;
    draw_point(xc-y,yc+x);
    lj++;
    l[li].p[lj][0]=xc+y;
    l[li].p[lj][1]=yc-x;
    draw_point(xc+y,yc-x);
    lj++;
    l[li].p[lj][0]=xc-y;
    l[li].p[lj][1]=yc-x;
    draw_point(xc-y,yc-x);
    lj++;
    dot++;
}

void ellipseplot(float xc,float yc, float x, float y)
{
    l[li].p[lj][0]=xc+x;
    l[li].p[lj][1]=yc+y;
    draw_point(xc+x,yc+y);
    lj++;
    l[li].p[lj][0]=xc-x;
    l[li].p[lj][1]=yc+y;
    draw_point(xc-x,yc+y);
    lj++;
    l[li].p[lj][0]=xc+x;
    l[li].p[lj][1]=yc-y;
    draw_point(xc+x,yc-y);
    lj++;
    l[li].p[lj][0]=xc-x;
    l[li].p[lj][1]=yc-y;
    draw_point(xc-x,yc-y);
    lj++;
    dot++;
}


void midpoint(Point p1,Point p2)
{
    if(shape==1)
    {


         int x1=p1.x,x2=p2.x,y1=p1.y,y2=p2.y;
         int dy = y2-y1;
         int dx = x2-x1;
         int p=dy-dx/2;
         int y=y1;
         for (int x=x1; x <=x2; x++) {
           draw_point(x, y);
           if(p > 0) {
            y++;
            p=p+ (dy-dx);
           }
           else
            p += dy;
         }
    }
    else if(shape==2)
    {
        lj=0;

        float radius,r,z;
		r=abs(p2.x-p1.x);
		r=pow(r,2);
		z=abs(p2.y-p1.y);
		z=pow(z,2);
		radius=sqrt(r+z);

        for(i=0;i<=thickness;i++)
        {
             float x=0,y=radius,p=1-radius;
            circleplot(p1.x,p1.y,x,y);
            while(x<y)
            {
                x++;
                if(p<0)
                    p+=2*x+1;
                else
                {
                    y--;
                    p+=2*(x-y)+1;
                }
                circleplot(p1.x,p1.y,x,y);

            }
            radius+=0.5;
        }
        l[li].counter=lj;
        li++;
    }
    else if(shape==3)
    {
        lj=0;

    for(i=0;i<=thickness;i++)
    {
        float xc=p1.x,yc=p1.y;
        float rx=abs(p2.x-p1.x);
        float ry=abs(p2.y-p1.y);
        float rx2=rx*rx;
        float ry2=ry*ry;
        float twoRx2=2*rx2;
        float twoRy2=2*ry2;
        float p,x=0,y=ry,px=0,py=twoRx2*y;
        ellipseplot(xc,yc,x,y);
        p=ry2-(rx2*ry)+(0.25*rx2);
        while(px<py)
        {
            x++;
            px+=twoRy2;
            if(p<0)
                p+=ry2+px;
            else
            {
                y--;
                py-=twoRx2;
                p+=ry2+px-py;
            }
                ellipseplot(xc,yc,x,y);
        }
         p=ry2*(x+0.5)*(x+0.5)+rx2*(y-1)*(y-1)-rx2*ry2;
        while(y>0)
        {
            y--;
            py-=twoRx2;
            if(p>0)
                p+=rx2-py;
            else
            {
                x++;
                px+=twoRy2;
                p+=rx2-py+px;
            }
                ellipseplot(xc,yc,x,y);
        }
     p2.x++;
     p2.y++;
    }
    l[li].counter=lj;
    li++;
    }
}

void bresenham(Point p1,Point p2)
{
    if(shape==1)
    {


        int dx,dy,p0,pk,pk1,i,last;
        int x1,y1,flag;
        float m;

        dx=abs(p2.x-p1.x);
        dy=abs(p2.y-p1.y);
        m =(float)(p2.y-p1.y)/(p2.x-p1.x);
        if(m>=0)
        {
            flag=0;

        }
        else
        {
            flag=1;

        }

        if(dx>dy)
        {


        if(p2.x<p1.x)
        {
           x1=p2.x;
           y1=p2.y;
           last=p1.x;
        }
        else
        {
            x1=p1.x;
            y1=p1.y;
            last=p2.x;
        }


        p0=2*dy-dx;
        pk=p0;
        int counter=1;
        while(x1<=last)
        {
           if(pk<0)
           {


             pk=pk+(2*dy);
           }
           if(pk>=0)
           {
               if(flag==0)
                 {
                    ++y1;
                 }
               else
               {
                 --y1;
               }


               pk=pk+(2*dy)-(2*dx);

           }
           draw_point(x1,y1);

           x1++;
           counter++;
        }
        glEnd();
        }
        else
        {
            if(p2.y<p1.y)
            {
                x1=p2.x;
                y1=p2.y;
                last=p1.y;
            }
            else
            {
                x1=p1.x;
                y1=p1.y;
                last=p2.y;
            }




            p0=2*dx-dy;
            pk=p0;

            while(y1<=last)
            {
               if(pk<0)
               {


                 pk=pk+(2*dx);
               }
               if(pk>=0)
               {
                   if(flag==0)
                 {
                    ++x1;
                 }
               else
               {
                 --x1;
               }

                   pk=pk+(2*dx)-(2*dy);

               }
              draw_point(x1,y1);
               y1++;
            }
        glEnd();


        }
    }
    else if(shape==2)
    {
        float d,r,x,y;
        float xc=p1.x,yc=p1.y;
        float radius,z;
		r=abs(p2.x-p1.x);
		r=pow(r,2);
		z=abs(p2.y-p1.y);
		z=pow(z,2);
		radius=sqrt(r+z);

        d=3-2*radius;
        x=0;
        y=r;
        while(x<=y)
        {
            draw_point(xc+x,yc+y);
            draw_point(xc-y,yc-x);
            draw_point(xc+y,yc-x);
            draw_point(xc-y,yc+x);
            draw_point(xc+y,yc+x);
            draw_point(xc-x,yc-y);
            draw_point(xc+x,yc-y);
            draw_point(xc-x,yc+y);
            if(d<=0)
            {
                d=d+4*x+6;
            }
            else
            {
                d=d+4*x-4*y+10;
                y=y-1;
            }
            x=x+1;
        }
    }
    else if(shape==3)
    {
        float d1,d2;
    float i,x,y;
    float rx,ry,rxsq,rysq,tworxsq,tworysq,dx,dy;
    float xc=p1.x,yc=p1.y;
    rx=abs(p2.x-p1.x);
    ry=abs(p2.y-p1.y);

    rxsq=rx*rx;
    rysq=ry*ry;
    tworxsq=2*rxsq;
    tworysq=2*rysq;
    x=0;
    y=ry;
    d1=rysq - (rxsq * ry) + (0.25 * rxsq);
    dx= tworysq * x;
    dy= tworxsq * y;
    do
    {
      draw_point(xc+x,yc+y);
      draw_point(xc-x,yc-y);
      draw_point(xc-x,yc+y);
      draw_point(xc+x,yc-y);

      if (d1 < 0)
       {
        x=x+1;
        y=y;
         dx=dx + tworysq;
         d1=d1 + dx + rysq;
         }
       else
       {
        x=x+1;
        y=y-1;
        dx= dx + tworysq;
        dy= dy - tworxsq;
        d1= d1 + dx - dy + rysq;
        }

        }while (dx < dy);
       d2 = rysq * ( x + 0.5) * ( x + 0.5 ) + rxsq * (y - 1) * (y-1) - rxsq * rysq;
        do
        {
          draw_point(xc+x,yc+y);
          draw_point(xc-x,yc-y);
          draw_point(xc-x,yc+y);
          draw_point(xc+x,yc-y);

          if (d2 >0)
          {
          x=x;
          y=y-1;
          dy = dy - tworxsq;
          d2 = d2 - dy + rxsq;
          }
          else
          {
          x= x+1;
          y=y-1;
          dy=dy - tworxsq;
          dx= dx + tworysq;
          d2 = d2 + dx -dy + rxsq;
          }

        } while ( y> 0);

    }
}










