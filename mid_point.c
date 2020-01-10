//HARIOM PARMAR
#include<stdio.h>
#include<graphics.h>

void Mid_point(int x0,int y0,int r)
{
    int x=0;
    int y=r;
   float p=1.25 - r;			
   
    do {												
	    putpixel(x0+ x, y0+ y ,WHITE);	
	    putpixel(x0- x, y0- y , WHITE);
	    putpixel(x0- x, y0+ y , WHITE);
	    putpixel(x0+ x, y0- y , WHITE);
	    putpixel(x0 +y, y0+ x , WHITE);
	    putpixel(x0 +y,y0 -x , WHITE);
	    putpixel(x0 -y, y0 -x , WHITE);
	    putpixel(x0 -y, y0 +x , WHITE);

	    

	    x++;	 
		
	    if(p<0) {
	        p=p+2*x+1;
	    } else {
	            y--; 
	            p=p+2*(x-y)+1;
	    }
	} while(x<=y);

}
int main()
{    
int x0=10,y0=20,r=5;

int i,gd=DETECT,gm;
initgraph(&gd,&gm,NULL);
 Mid_point(x0,y0,r);
 delay(5000);
closegraph();
return 0;	
}