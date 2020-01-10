#include<bits/stdc++.h>
#include<graphics.h>
using namespace std;
void DDA(int x1,int y1,int x2,int y2)
{
  float dx,dy,steps,xinc,yinc,x,y;
  dx=x2-x1;
  dy=y2-y1;
x=x1;y=y1;
  steps=abs(dx)>abs(dy)?dx:dy;
  xinc=dx/steps;yinc=dy/steps;
  for(int i=0;i<=steps;i++)
  {
	  putpixel(x,y,WHITE);
	  x=x+xinc;
	  y=y+yinc;
	  
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
 delay(1000);
closegraph();
return 0;	
}