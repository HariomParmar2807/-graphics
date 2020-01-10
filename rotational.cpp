#include <graphics.h>
#define fl(i, n) for (int i = 0; i < n; i++)
#define PI 3.142

void drawellipse(int xx, int yy, int a, int b, int boundrycolor)
{
    int p10 = pow(b, 2) - pow(a, 2) * b + (pow(a, 2) / 2);
    int p1k1 = p10;
    int p2k1;
    int x = 0,y=b;
    while (y >= 0)
    {
        putpixel(xx+x, yy+y, boundrycolor);
        putpixel(xx+x, yy-y, boundrycolor);
        putpixel(xx-x, yy-y, boundrycolor);
        putpixel(xx-x, yy+y, boundrycolor);

        if ((pow(b, 2) * x) < (pow(a, 2) * y))
        {
            if (p1k1 < 0)
            {
                p1k1 += 2 * pow(b, 2) * (x + 1) + pow(b, 2);
                x++;
            }
            else
            {
                p1k1 += 2 * pow(b, 2) * (x + 1) + pow(b, 2) - 2 * pow(a, 2) * (y - 1);
                x++;
                y--;
            }
            p2k1 = pow(b, 2) * pow((x + (1 / 2)), 2) + pow(a, 2) * pow((y - 1), 2) - pow(a, 2) * pow(b, 2);
        }
        else
        {
            if (p2k1 > 0)
            {
                p2k1 += -2 * pow(a, 2) * (y - 1) + pow(a, 2);
                y--;
            }
            else
            {
                p2k1 += 2 * pow(b, 2) * (x + 1) + pow(a, 2) - 2 * pow(a, 2) * (y - 1);
                x++;
                y--;
            }
        }
    }
}

void midcircle(int xc,int yc,int radious){
    int x = 0 , y = radious;
    int p0 = 1-radious;
    int pk = p0;
    while(y >= radious*cos(PI/4)-1){
        putpixel(x + xc,y + yc,WHITE);
        putpixel(y + xc,x + yc,WHITE);
        putpixel(y + xc,-x + yc,WHITE);
        putpixel(x + xc,-y + yc,WHITE);
        putpixel(-x + xc,-y + yc,WHITE);
        putpixel(-y + xc,-x + yc,WHITE);
        putpixel(-y + xc,x + yc,WHITE);
        putpixel(-x + xc,y + yc,WHITE);
        if(pk < 0){
            pk += 2*x + 3;
        }else {
            y -=1;
            pk += 2*x - 2*y + 5;
        }
        ++x;
    }
    for(int i=radious ;i>=0; i-=5){
        drawellipse(xc,yc,i,radious,WHITE);
        delay(10);
    }
    for(int i=radious ;i>=0; i-=5){
        drawellipse(xc,yc,radious,i,WHITE);
        delay(10);
    }

}
int main()
{
    int gd = DETECT, gm;
    initgraph(&gd, &gm, "");
    /*for(x=0;x<100;x++) // parabola equations
{
y=f(x);
putpixel(x+300, 175-y,GREEN);
putpixel(x+300, 175+y,GREEN);
}
delay(5000);
closegraph();
return 0;
}

float f(int x)
{
return -(x*x);
}*/
    line(0,200,200000,200);
    int  r=20,x=20,y=200;
    midcircle(x,y,r);
    line(0,350,200000,350);
    midcircle(120,460,20);
    midcircle(80,350,20);
    midcircle(350,370,20);
    midcircle(500,460,20);
    midcircle(600,370,20);

    delay(5000);
    closegraph();
}