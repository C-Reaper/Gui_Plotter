#include "/home/codeleaded/System/Static/Library/WindowEngine1.0.h"
#include "/home/codeleaded/System/Static/Library/Plotter.h"
#include "/home/codeleaded/System/Static/Library/Random.h"


Plotter p;
Sprite plottsp;

float Squ_Noise(float x){
	return x * x + (float)Random_f64_MinMax(0.2,0.8);
}
float Exp_Noise(float x){
	return expf(x) + expf(x) * (float)Random_f64_MinMax(0.2,0.8);
}
float Sin_Noise(float x){
	return sinf(x) + (float)Random_f64_MinMax(-0.2,0.2);
}

void Setup(AlxWindow* w){
	p = Plotter_New((Rect){ {0.0f,0.0f},{1000.0f,1000.0f} },PLOTTER_ORIENT_UP);
	
	//Plotter_AddSet(&p,cosf,0.0f,2.0f * F32_PI2,0.1f,RED,0);
	Plotter_AddSet(&p,F32_Sigmoid,-2.0f * F32_PI2,2.0f * F32_PI2,0.1f,BLUE,0);
	//Plotter_LoadSet(&p,"./data/Dataset.txt",GREEN,4);

	//Plotter_AddSet(&p,Squ_Noise,0.0f,F32_PI2,0.1f,GREEN,4);
	//Plotter_Regression(&p,0,MFunction_New_Lin());

	//Plotter_AddSet(&p,Exp_Noise,0.0f,F32_PI2,0.1f,GREEN,4);
	//Plotter_Regression(&p,0,MFunction_New_Exp());

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