#include "/home/codeleaded/System/Static/Library/WindowEngine1.0.h"
#include "/home/codeleaded/System/Static/Library/Plotter.h"


Plotter p;
Sprite plottsp;

void Setup(AlxWindow* w){
	p = Plotter_New((Rect){ {0.0f,0.0f},{1000.0f,1000.0f} });
	Plotter_AddSet(&p,sinf,0.0f,F32_PI2,0.1f,RED,5);

	plottsp = Sprite_New(1000,1000);
	Plotter_Render(plottsp.img,plottsp.w,plottsp.h,&p);
}
void Update(AlxWindow* w){
	
	Clear(DARK_BLUE);

	Sprite_Render(WINDOW_STD_ARGS,&plottsp,0.0f,0.0f);
}
void Delete(AlxWindow* w){
	Plotter_Free(&p);
	Sprite_Free(&plottsp);
}

int main(){
    if(Create("Plotter",1000,1000,1,1,Setup,Update,Delete))
        Start();
    return 0;
}