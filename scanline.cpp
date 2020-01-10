#include<bits/stdc++.h>
#include<graphics.h>
using namespace std;
void _boundaryfill(int x,int y,int fill,int boundry)
{
  int current=getpixel(x,y);
  if((current!=fill)&&(current!=boundry))
  {
    putpixel(x,y,fill);
    _boundaryfill(x+1,y,fill,boundry);
    _boundaryfill(x-1,y,fill,boundry);
    _boundaryfill(x,y+1,fill,boundry);
    _boundaryfill(x,y-1,fill,boundry);
  }
}
int main()
{
   int gd=DETECT,gm,color;
   initgraph(&gd,&gm,NULL);

   circle(100,200,50);
   _boundaryfill(100,200,RED,WHITE);
   delay(5000);
   closegraph();

}