#include<bits/stdc++.h>
#include<graphics.h>
using namespace std;
void DDA(int x1,int y1,int x2,int y2)
{
int x,y,dx,dy,p;
  x=x1;y=y1;
  dx=x2-x1;dy=y2-y1;

  p=2*dy-dx;
  while(x<=x2)
  {
      putpixel(x,y,WHITE);
      x++;
      if(p<0)
        p=p+2*dy;
      else{
       p=p+2*dy-2*dx;
      y++;}
      
  }
}

int main()
{
  int x1,y1,x2,y2;
cout<<"Enter x coordinates=";
cin>>x1>>x2;
cout<<"Enter y coordinates=";
cin>>y1>>y2;
int i,gd=DETECT,gm;
 
	initgraph(&gd,&gm,NULL);
 DDA(x1,y1,x2,y2);
delay(5000);
 closegraph();

return 0;	
}