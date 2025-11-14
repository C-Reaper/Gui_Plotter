#include "/home/codeleaded/System/Static/Library/WindowEngine1.0.h"
#include "/home/codeleaded/System/Static/Library/Plotter.h"


Plotter p;

void Setup(AlxWindow* w){
	p = Plotter_New((Rect){ {0.0f,0.0f},{1000.0f,1000.0f} });

	Plotter_AddSet(&p,sinf,F32_PI2,RED,0);
}
void Update(AlxWindow* w){
	
	Clear(DARK_BLUE);

	Plotter_Render(WINDOW_STD_ARGS,&p);
}
void Delete(AlxWindow* w){
	Plotter_Free(&p);
}

int main(){
    if(Create("Plotter",1000,1000,1,1,Setup,Update,Delete))
        Start();
    return 0;
}