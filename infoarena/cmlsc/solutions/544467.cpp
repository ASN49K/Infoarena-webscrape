#include "hge.h"
#include <vector>
#include <iostream>
#include<cstdlib>
HGE *hge = 0;
float camera_x=0,camera_y=0;
int screen_x=800,screen_y=600;
#include "sprite.h"
HTEXTURE t_hero,t_dirt,t_background,t_flare;
#include "map.h"
sprite *hero;
map *harta;
#include "helpers.h"
#include "light.h"
light *lumina,*lumina2;
HTARGET light_buffer;
HTEXTURE light_texture;
hgeQuad light_quad;
tile*coll;



void Init_deInit(int i){
    if(i==0){
        t_hero=hge->Texture_Load("hero.png");
        t_dirt=hge->Texture_Load("dirt.png");
        t_background=hge->Texture_Load("background.png");
        t_flare=hge->Texture_Load("flare.png");
        lumina=new light(0,0,t_flare,512,64);
        hero=new sprite(t_hero,64*30.5,64*30.5,64,0xFFFFFFFF);
        light_buffer=hge->Target_Create(1024,1024,true);
        light_texture=hge->Target_GetTexture(light_buffer);
        light_quad.tex=light_texture;
        light_quad.blend=BLEND_DARKEN;
        for(int i=0;i<4;i++){light_quad.v[i].z=0;light_quad.v[i].col=0xFFFFFFFF;}
        light_quad.v[0].tx=0;light_quad.v[0].ty=0;
        light_quad.v[1].tx=1;light_quad.v[1].ty=0;
        light_quad.v[2].tx=1;light_quad.v[2].ty=1;
        light_quad.v[3].tx=0;light_quad.v[3].ty=1;
        light_quad.v[0].x=0;   light_quad.v[0].y=0;
        light_quad.v[1].x=1024;light_quad.v[1].y=0;
        light_quad.v[2].x=1024;light_quad.v[2].y=1024;
        light_quad.v[3].x=0;   light_quad.v[3].y=1024;
        harta=new map(250,64);
        harta->Add_Tile(60,60,NONE);
        harta->Add_Tile(61,60,NONE);
        harta->Add_Tile(62,60,NONE);
        harta->Add_Tile(60,62,NONE);
        harta->Add_Tile(61,62,NONE);
        harta->Add_Tile(62,62,NONE);
        harta->Add_Tile(60,61,NONE);
        harta->Add_Tile(62,61,NONE);
    }else{
        hge->Texture_Free(t_hero);
        hge->Texture_Free(t_dirt);
        hge->Target_Free(light_buffer);
        delete lumina;
        delete hero;
        delete harta;
}}

bool FrameFunc(){
camera_x+=(hero->Get_X()-camera_x)/30;
camera_y+=(hero->Get_Y()-camera_y)/30;
for(int i=Get_X_Map(camera_x)-(int)(screen_x/128)-2;i<Get_X_Map(camera_x)+(int)(screen_x/128)+2;i++)
if(harta->Get_Tile(i,Get_Y_Map(camera_y)-(int)(screen_y/128)-1)==NULL)harta->Add_Tile(i,Get_Y_Map(camera_y)-(int)(screen_y/128)-1,DIRT);
for(int i=Get_X_Map(camera_x)-(int)(screen_x/128)-2;i<Get_X_Map(camera_x)+(int)(screen_x/128)+2;i++)
if(harta->Get_Tile(i,Get_Y_Map(camera_y)+(int)(screen_y/128)+1)==NULL)harta->Add_Tile(i,Get_Y_Map(camera_y)+(int)(screen_y/128)+1,DIRT);

for(int i=Get_Y_Map(camera_y)-(int)(screen_y/128)-2;i<Get_Y_Map(camera_y)+(int)(screen_y/128)+2;i++)
if(harta->Get_Tile(Get_X_Map(camera_x)-(int)(screen_x/128)-1,i)==NULL)harta->Add_Tile(Get_X_Map(camera_x)-(int)(screen_x/128)-1,i,DIRT);
for(int i=Get_Y_Map(camera_y)-(int)(screen_y/128)-2;i<Get_Y_Map(camera_y)+(int)(screen_y/128)+2;i++)
if(harta->Get_Tile(Get_X_Map(camera_x)+(int)(screen_x/128)+1,i)==NULL)harta->Add_Tile(Get_X_Map(camera_x)+(int)(screen_x/128)+1,i,DIRT);

coll=harta->Get_Tile(Get_X_Map(hero->Get_X()),Get_Y_Map(hero->Get_Y()));
if(coll!=NULL)if(coll->Get_Type()==DIRT)coll->Set_Type(NONE);

if(hge->Input_GetKeyState(HGEK_RIGHT))hero->Set_Direction(hero->Get_Direction()+5);
if(hge->Input_GetKeyState(HGEK_LEFT))hero->Set_Direction(hero->Get_Direction()-5);
if(hge->Input_GetKeyState(HGEK_UP))hero->Set_Speed(5);
if(hge->Input_GetKeyState(HGEK_DOWN))hero->Set_Speed(-5);
hero->Set_Speed(hero->Get_Speed()/1.2);
hero->Update();
lumina->Set_XY(hero->Get_X(),hero->Get_Y());
if (hge->Input_GetKeyState(HGEK_ESCAPE)) return true;
return false;}

bool RenderFunc(){

    lumina->Update();
    hge->Gfx_BeginScene(light_buffer);
    hge->Gfx_Clear(0);
    lumina->Draw();
    hge->Gfx_EndScene();
    hge->Gfx_BeginScene();
	hge->Gfx_Clear(0);
	std::cout<<Point_Direction(0,0,hero->Get_X(),hero->Get_Y())<<'\n';
	std::cout<<Get_X_Map(camera_x)<<'.'<<Get_Y_Map(camera_y)<<'\n';
	std::cout<<"FPS:"<<hge->Timer_GetFPS()<<'\n';
	for(int i=Get_X_Map(camera_x)-screen_x/harta->Get_Size()/2-1;i<Get_X_Map(camera_x)+screen_x/harta->Get_Size()/2+2;i++)
	for(int j=Get_Y_Map(camera_y)-screen_y/harta->Get_Size()/2-1;j<Get_Y_Map(camera_y)+screen_y/harta->Get_Size()/2+2;j++)
	harta->Draw_Tile(i,j);
	hero->Draw_Rotate(hero->Get_Direction()+180);
    hge->Gfx_RenderQuad(&light_quad);
	hge->Gfx_EndScene();
return false;}

int WINAPI WinMain(HINSTANCE, HINSTANCE, LPSTR, int){
	hge = hgeCreate(HGE_VERSION);
	hge->System_SetState(HGE_LOGFILE, "log.txt");
	hge->System_SetState(HGE_RENDERFUNC, RenderFunc);
	hge->System_SetState(HGE_FRAMEFUNC, FrameFunc);
	hge->System_SetState(HGE_TITLE, "KosmynC64 game");
	hge->System_SetState(HGE_FPS, 50);
	hge->System_SetState(HGE_WINDOWED, true);
	hge->System_SetState(HGE_SCREENWIDTH, screen_x);
    hge->System_SetState(HGE_SCREENHEIGHT, screen_y);
    hge->System_SetState(HGE_SCREENBPP, 32);
	if(hge->System_Initiate()){
	    Init_deInit(0);
		hge->System_Start();
		Init_deInit(1);}
	else MessageBox(NULL, hge->System_GetErrorMessage(), "Error", MB_OK | MB_ICONERROR | MB_APPLMODAL);
	hge->System_Shutdown();
	hge->Release();
	return 0;}
