#include<graphics.h>
#include<bits/stdc++.h>
using namespace std;
void floodfill(int x,int y,int f_color,int o_color)
{
   
	if(getpixel(x,y)==o_color)
	{
		putpixel(x,y,f_color);
		floodfill(x+1,y,f_color,o_color);
		floodfill(x,y+1,f_color,o_color);
		floodfill(x-1,y,f_color,o_color);
		floodfill(x,y-1,f_color,o_color);
	}

}

void mid_ellipse(int ry,int rx,int xc,int yc)
{
  float p1,p2,x,y;
    p1=ry*ry-rx*rx*ry+rx*rx/4;
   x=0;y=ry;
   while(2.0*ry*ry*x <= 2.0*rx*rx*y)
   {
	if(p1 < 0)
	{
		x++;
		p1 = p1+2*ry*ry*x+ry*ry;
	}
	else
	{
		x++;y--;
		p1 = p1+2*ry*ry*x-2*rx*rx*y-ry*ry;
	}
	putpixel(xc+x,yc+y,WHITE);
	putpixel(xc+x,yc-y,WHITE);
	putpixel(xc-x,yc+y,WHITE);
	putpixel(xc-x,yc-y,WHITE);
   }

  //Region 2
   p2=ry*ry*(x+0.5)*(x+0.5)+rx*rx*(y-1)*(y-1)-rx*rx*ry*ry;
   while(y > 0)
   {
	if(p2 <= 0)
	{
		x++;y--;
		p2 = p2+2*ry*ry*x-2*rx*rx*y+rx*rx;
	}
	else
	{
		y--;
		p2 = p2-2*rx*rx*y+rx*rx;
	}
	putpixel(xc+x,yc+y,WHITE);
	putpixel(xc+x,yc-y,WHITE);
	putpixel(xc-x,yc+y,WHITE);
	putpixel(xc-x,yc-y,WHITE);
   }
}
int main()
{

   int gd = DETECT, gm,color;
     initgraph(&gd, &gm, NULL);
  mid_ellipse(10,20,50,50);
 mid_ellipse(20,40,50,50); 
 
 int current=getpixel(80,50);
  floodfill(80,50,4,current);
   delay(1000);
   closegraph();
   return 0;
}