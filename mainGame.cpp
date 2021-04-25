#include <SDL.h>
#include <bits/stdc++.h>
#include <fstream>
#include "textObject.h"
#include "commonFunc.h"
#include "imageObject.h"
using namespace std;

const string S="image";
const string T=".bmp";
const string WINDOW_TITLE = "GAME MEMORIZE of Penny";

const string image1="image/";
const string LV1="level1/";
const string LV2="level2/";
const string LV3="level3/";
const string LV4="level4/";
const string LV5="level5/";
const string LV6="level6/";

const string OP="output";
const string alice="alice";

const string _1="1";
const string _2="2";
const string _3="3";
const string _4="4";
const string _5="5";
const string _6="6";
const string _7="7";
const string _8="8";
const string _9="9";
const string _10="10";

const char NU[]="nu.txt";
TTF_Font* font_word1 = NULL;
TTF_Font* font_word2 = NULL;
TTF_Font* font_word3 = NULL;
TTF_Font* font_word4 = NULL;
imageObject g_background;
//**************************************************************************************************************
void logSDLError(std::ostream& os,const std::string &msg, bool fatal = false);
void quitSDL(SDL_Window* window, SDL_Renderer* renderer);
bool initData()
{
    bool success = true;
    int ret = SDL_Init(SDL_INIT_VIDEO);
    if (ret<0)
    {
        return false;
    }
    SDL_SetHint(SDL_HINT_RENDER_SCALE_QUALITY, "1");
    window = SDL_CreateWindow("Game Memorize of Penny",
                                SDL_WINDOWPOS_UNDEFINED,
                                SDL_WINDOWPOS_UNDEFINED,
                                SCREEN_WIDTH,SCREEN_HEIGHT,
                                SDL_WINDOW_SHOWN);
    if (window == NULL)
    {
        success = false;
    } else
    {
        renderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED);
        if (renderer == NULL)
        {
            success = false;
        } else
        {
            SDL_SetRenderDrawColor(renderer,0,0,0,0);
            //int imgFlags = IMG_INIT_PNG;
            //if (!(IMG_INIT(imgFlags) && imgFlags)){success = false;}
        }
        if (TTF_Init() == -1)
        {
            success = false;
        }
        font_word1 = TTF_OpenFont("WordType/ariblk.ttf",30);
        if (font_word1 == NULL)
        {
            success = false;
        }
        font_word2 = TTF_OpenFont("WordType/lazy.ttf",30);
        if (font_word2 == NULL)
        {
            success = false;
        }
        font_word3 = TTF_OpenFont("WordType/lazy.ttf",70);
        if (font_word3 == NULL)
        {
            success = false;
        }
        font_word4 = TTF_OpenFont("WordType/FREESCPT.ttf",150);
        if (font_word4 == NULL)
        {
            success = false;
        }
    }
    return success;
}

void waitUntilKeyPressed();
void waitUntilKeyPressed1();
//*************************************************************************************************************
SDL_Texture* loadTexture(const std::string &file, SDL_Renderer *ren);
void renderTexture(SDL_Texture *tex, SDL_Renderer *ren, int x, int y);
void renderTexture(SDL_Texture *tex, SDL_Renderer *ren, int x, int y, int w, int h);
//*************************************************************************************************************
vector<string> memeList;

vector<string> nuList;
void chooseNu(const char* fileName)
{
    ifstream file(fileName);
  	if (file.is_open()) {
	    string nu;
		while (file >> nu) {
            nuList.push_back(nu);
        }
    	file.close();
  	}
}
//**********************************************************************************************************
void start();
void introduce();
//***************************************************************************************************
void repeat(int k,int level)
{

    int n,t;
    if (level==1){n=6;t=18;} else
    if (level==2){n=9;t=18;} else
    if (level==3){n=24;t=9;} else
    if (level==4){n=36;t=9;} else
    if (level==5){n=54;t=6;} else
    if (level==6){n=81;t=6;}

    //random n numbers
    int c[n+1];
    srand((int)time(0));
    int r;
    map<int, bool> vis;

    for (int h = 0; h < n; ++h)
    {
        do
        {
            r = 1 + rand() % (n + 1 - 1);
        }while(vis.find(r) != vis.end());
        c[h]=r;
        vis[r] = true;
    }

    //pick a random number
    int ra=rand() % 10 +1;
    string ran;
    ostringstream conv;
    conv << ra;
    ran = conv.str();

    //pick a picture and write level
    textObject lev;
    lev.setColor(textObject::WHITE_TEXT);

    SDL_Texture *LEV_1_1a[n+1]; //mảng chứa n mảnh màu
    SDL_Texture *LEV_1_1b[n+1]; //mảng chứa n mảnh mất màu

    if (level==1)
    {
        for (int i=0;i<n;i++)
        {
            LEV_1_1a[i]=loadTexture("image/level_1/ver_"+ran+"_1/alice"+ran+nuList[i]+T, renderer);
        }
        for (int i=0;i<n;i++)
        {
            LEV_1_1b[i]=loadTexture("image/level_1/ver_"+ran+"_2/alice"+ran+nuList[i]+T, renderer);
        }
        lev.setText("LEVEL 1");
        lev.loadFromRenderText(font_word1,renderer);
        lev.renderText(renderer,30,30);
    } else
    if (level==2)
    {
        for (int i=0;i<n;i++)
        {
            LEV_1_1a[i]=loadTexture("image/level_2/ver_"+ran+"_1/alice"+ran+nuList[i]+T, renderer);
        }
        for (int i=0;i<n;i++)
        {
            LEV_1_1b[i]=loadTexture("image/level_2/ver_"+ran+"_2/alice"+ran+nuList[i]+T, renderer);
        }
        lev.setText("LEVEL 2");
        lev.loadFromRenderText(font_word1,renderer);
        lev.renderText(renderer,30,30);
    } else
    if (level==3)
    {
        for (int i=0;i<n;i++)
        {
            LEV_1_1a[i]=loadTexture("image/level_3/ver_"+ran+"_1/alice"+ran+nuList[i]+T, renderer);
        }
        for (int i=0;i<n;i++)
        {
            LEV_1_1b[i]=loadTexture("image/level_3/ver_"+ran+"_2/alice"+ran+nuList[i]+T, renderer);
        }
        lev.setText("LEVEL 3");
        lev.loadFromRenderText(font_word1,renderer);
        lev.renderText(renderer,30,30);
    } else
    if (level==4)
    {
        for (int i=0;i<n;i++)
        {
            LEV_1_1a[i]=loadTexture("image/level_4/ver_"+ran+"_1/alice"+ran+nuList[i]+T, renderer);
        }
        for (int i=0;i<n;i++)
        {
            LEV_1_1b[i]=loadTexture("image/level_4/ver_"+ran+"_2/alice"+ran+nuList[i]+T, renderer);
        }
        lev.setText("LEVEL 4");
        lev.loadFromRenderText(font_word1,renderer);
        lev.renderText(renderer,30,30);
    } else
    if (level==5)
    {
        for (int i=0;i<n;i++)
        {
            LEV_1_1a[i]=loadTexture("image/level_5/ver_"+ran+"_1/alice"+ran+nuList[i]+T, renderer);
        }
        for (int i=0;i<n;i++)
        {
            LEV_1_1b[i]=loadTexture("image/level_5/ver_"+ran+"_2/alice"+ran+nuList[i]+T, renderer);
        }
        lev.setText("LEVEL 5");
        lev.loadFromRenderText(font_word1,renderer);
        lev.renderText(renderer,30,30);
    } else
    if (level==6)
    {
        for (int i=0;i<n;i++)
        {
            LEV_1_1a[i]=loadTexture("image/level_6/ver_"+ran+"_1/alice"+ran+nuList[i]+T, renderer);
        }
        for (int i=0;i<n;i++)
        {
            LEV_1_1b[i]=loadTexture("image/level_6/ver_"+ran+"_2/alice"+ran+nuList[i]+T, renderer);
        }
        lev.setText("LEVEL 6");
        lev.loadFromRenderText(font_word1,renderer);
        lev.renderText(renderer,30,30);
    }

    //mảng chứa các mảnh màu được sắp xếp ngãu nhiên
    SDL_Texture *d[81];
    for (int k=0;k<n;k++)
    {
        d[k]=LEV_1_1a[c[k]-1];
    }
    //in ra n mảnh sắp xếp lộn xộn
    int k1=0;
    for (int i=80;i<SCREEN_HEIGHT-t*10;i=i+t*10)
    {
        for (int j=30;j<SCREEN_WIDTH-t*10;j=j+t*10)
        {
            renderTexture(d[k1], renderer, j, i, t*10, t*10);
            k1++;
        }
    }
    //vẽ ra các vạch đỏ ngăn cách
    if ((n==6)||(n==24)||(n==54))
    {
     SDL_SetRenderDrawColor(renderer, 255, 0, 0, 255);
    for (int i=30;i<SCREEN_WIDTH;i=i+t*10)
    {
        SDL_RenderDrawLine(renderer, i, 80, i, 440);
    }
    for (int i=80;i<SCREEN_HEIGHT-180;i=i+t*10)
    {
        SDL_RenderDrawLine(renderer, 30, i, 570, i);
    }

    SDL_RenderPresent(renderer);
    } else
    if ((n==9)||(n==36)||(n==81))
    {
     SDL_SetRenderDrawColor(renderer, 255, 0, 0, 255);
    for (int i=30;i<SCREEN_WIDTH;i=i+t*10)
    {
        SDL_RenderDrawLine(renderer, i, 80, i, 620);
    }
    for (int i=80;i<SCREEN_HEIGHT;i=i+t*10)
    {
        SDL_RenderDrawLine(renderer, 30, i, 570, i);
    }

    SDL_RenderPresent(renderer);
    }
    //bắt đầu sắp xếp
    SDL_Event e;
    int o;
    int p=0;
    int e1[2];
    Uint32 tim = SDL_GetTicks()/1000;
    int dem=0;
    while (true)
    {
        SDL_Delay(10);
        if ( SDL_WaitEvent(&e) == 0) continue;
        if (e.type == SDL_QUIT) {quitSDL(window,renderer);}
        if (e.type == SDL_KEYDOWN && e.key.keysym.sym == SDLK_ESCAPE) break;
        if (e.type == SDL_MOUSEBUTTONDOWN)
        {
        if ((n==9)||(n==36)||(n==81))
            {
            if ((e.button.x>=30)&&(e.button.x<=570)&&(e.button.y>=80)&&(e.button.y<=620))
            {
                if (e.button.button == SDL_BUTTON_LEFT)
                {
                    int x1=e.button.x;
                    int y1=e.button.y;
                    for (int i=80;i<SCREEN_HEIGHT-t*10;i=i+t*10)
                    {
                        for (int j=30;j<SCREEN_WIDTH-t*10;j=j+t*10)
                        {
                            if (x1==j || y1==i) {x1=j+1;y1=i+1;if (x1>570||y1>620){x1=x1-2;y1=y1-2;}}
                        }
                    }
                    int nuB[100][100];
                    //int t=54/sqrt(n);
                    int r1=0;
                    for (int w=8;w<62;w=w+t)
                    {
                        for (int v=3;v<57;v=v+t)
                        {
                            nuB[v][w]=r1;

                            r1++;//cout<<"["<<v<<"]"<<"["<<w<<"]="<<r1<<" ";
                        }
                        //cout<<endl;
                    }

                    for (int w=8;w<62;w=w+t)
                    {
                        if (((y1-10*w)<t*10) &&((y1-10*w)>0)){y1=w;break;}
                    }
                    for (int v=3;v<57;v=v+t)
                    {
                        if (((x1-10*v)<t*10)&&((x1-10*v)>0)){x1=v;break;}
                    }

                    int o=nuB[x1][y1];
                    //cout<<x1<<" "<<y1<<" "<<o<<endl;;
                    p++;
                    if (p==1){e1[0]=o;} else if (p==2){e1[1]=o;}
                    int k2=0;
                    for (int i=80;i<SCREEN_HEIGHT-t*10;i=i+t*10)
                    {
                        for (int j=30;j<SCREEN_WIDTH-t*10;j=j+t*10)
                        {
                            if (k2==o){d[k2]=LEV_1_1b[c[o]-1];}
                            renderTexture(d[k2], renderer, j, i, t*10, t*10);
                            k2++;
                        }
                    }
                     SDL_SetRenderDrawColor(renderer, 255, 0, 0, 255);
                    for (int i=30;i<SCREEN_WIDTH;i=i+t*10)
                    {
                        SDL_RenderDrawLine(renderer, i, 80, i, 620);
                    }
                    for (int i=80;i<SCREEN_HEIGHT;i=i+t*10)
                    {
                        SDL_RenderDrawLine(renderer, 30, i, 570, i);
                    }
                    SDL_RenderPresent(renderer);

                }
                if ((e.button.button == SDL_BUTTON_RIGHT)&&(p==1))
                    {
                        p=0;
                        int k3=0;
                        for (int i=80;i<SCREEN_HEIGHT-t*10;i=i+t*10)
                        {
                            for (int j=30;j<SCREEN_WIDTH-t*10;j=j+t*10)
                            {
                                if (k3==o){d[k3]=LEV_1_1a[c[o]-1];}
                                renderTexture(d[k3], renderer, j, i, t*10, t*10);
                                k3++;
                            }
                        }
                         SDL_SetRenderDrawColor(renderer, 255, 0, 0, 255);
                        for (int i=30;i<SCREEN_WIDTH;i=i+t*10)
                        {
                            SDL_RenderDrawLine(renderer, i, 80, i, 620);
                        }
                        for (int i=80;i<SCREEN_HEIGHT;i=i+t*10)
                        {
                            SDL_RenderDrawLine(renderer, 30, i, 570, i);
                        }
                        SDL_RenderPresent(renderer);
                    }
            }

            if ((p%2==0)&&(p>0))
            {
                int k4=0;
                int f1=0;
                int f2=0;
                f1=e1[0];f2=e1[1];

                //cout<<" => "<<e1[0]<<" "<<e1[1]<<" "<<f1<<" "<<f2<<endl;

                for (int i=80;i<SCREEN_HEIGHT-t*10;i=i+t*10)
                {
                    for (int j=30;j<SCREEN_WIDTH-t*10;j=j+t*10)
                    {
                        if(k4==e1[0]){d[k4]=LEV_1_1a[c[f2]-1];}
                        if(k4==e1[1]){d[k4]=LEV_1_1a[c[f1]-1];}
                        renderTexture(d[k4], renderer, j, i, t*10, t*10);
                        k4++;
                    }
                }
                 SDL_SetRenderDrawColor(renderer, 255, 0, 0, 255);
                for (int i=30;i<SCREEN_WIDTH;i=i+t*10)
                {
                    SDL_RenderDrawLine(renderer, i, 80, i, 620);
                }
                for (int i=80;i<SCREEN_HEIGHT;i=i+t*10)
                {
                    SDL_RenderDrawLine(renderer, 30, i, 570, i);
                }

                SDL_RenderPresent(renderer);
                dem++;
                int f3;
                f3=c[f1];c[f1]=c[f2];c[f2]=f3;
                e1[0]=0;e1[1]=0;
                p=0;
            }
            SDL_RenderPresent(renderer);
        } else
        if ((n==6)||(n==24)||(n==54))
            {
            if ((e.button.x>=30)&&(e.button.x<=570)&&(e.button.y>=80)&&(e.button.y<=440))
            {
                if (e.button.button == SDL_BUTTON_LEFT)
                {
                    int x1=e.button.x;
                    int y1=e.button.y;
                    for (int i=80;i<SCREEN_HEIGHT-180-t*10;i=i+t*10)
                    {
                        for (int j=30;j<SCREEN_WIDTH-t*10;j=j+t*10)
                        {
                            if (x1==j || y1==i) {x1=j+1;y1=i+1;if (x1>570||y1>440){x1=x1-2;y1=y1-2;}}
                        }
                    }
                    int nuB[100][100];
                    //int t=54/sqrt(n);
                    int r1=0;
                    for (int w=8;w<44;w=w+t)
                    {
                        for (int v=3;v<57;v=v+t)
                        {
                            nuB[v][w]=r1;

                            r1++;//cout<<"["<<v<<"]"<<"["<<w<<"]="<<r1<<" ";
                        }
                        //cout<<endl;
                    }

                    for (int w=8;w<44;w=w+t)
                    {
                        if (((y1-10*w)<t*10) &&((y1-10*w)>0)){y1=w;break;}
                    }
                    for (int v=3;v<57;v=v+t)
                    {
                        if (((x1-10*v)<t*10)&&((x1-10*v)>0)){x1=v;break;}
                    }

                    int o=nuB[x1][y1];
                    //cout<<x1<<" "<<y1<<" "<<o<<endl;;
                    p++;
                    if (p==1){e1[0]=o;} else if (p==2){e1[1]=o;}
                    int k2=0;
                    for (int i=80;i<SCREEN_HEIGHT-180-t*10;i=i+t*10)
                    {
                        for (int j=30;j<SCREEN_WIDTH-t*10;j=j+t*10)
                        {
                            if (k2==o){d[k2]=LEV_1_1b[c[o]-1];}
                            renderTexture(d[k2], renderer, j, i, t*10, t*10);
                            k2++;
                        }
                    }
                    SDL_SetRenderDrawColor(renderer, 255, 0, 0, 255);
                    for (int i=30;i<SCREEN_WIDTH;i=i+t*10)
                    {
                        SDL_RenderDrawLine(renderer, i, 80, i, 440);
                    }
                    for (int i=80;i<SCREEN_HEIGHT-180;i=i+t*10)
                    {
                        SDL_RenderDrawLine(renderer, 30, i, 570, i);
                    }

                    SDL_RenderPresent(renderer);

                }
                if ((e.button.button == SDL_BUTTON_RIGHT)&&(p==1))
                    {
                        p=0;
                        int k3=0;
                        for (int i=80;i<SCREEN_HEIGHT-180-t*10;i=i+t*10)
                        {
                            for (int j=30;j<SCREEN_WIDTH-t*10;j=j+t*10)
                            {
                                if (k3==o){d[k3]=LEV_1_1a[c[o]-1];}
                                renderTexture(d[k3], renderer, j, i, t*10, t*10);
                                k3++;
                            }
                        }
                        SDL_SetRenderDrawColor(renderer, 255, 0, 0, 255);
                        for (int i=30;i<SCREEN_WIDTH;i=i+t*10)
                        {
                            SDL_RenderDrawLine(renderer, i, 80, i, 440);
                        }
                        for (int i=80;i<SCREEN_HEIGHT-180;i=i+t*10)
                        {
                            SDL_RenderDrawLine(renderer, 30, i, 570, i);
                        }

                        SDL_RenderPresent(renderer);
                    }
            }

            if ((p%2==0)&&(p>0))
            {
                int k4=0;
                int f1=0;
                int f2=0;
                f1=e1[0];f2=e1[1];

                //cout<<" => "<<e1[0]<<" "<<e1[1]<<" "<<f1<<" "<<f2<<endl;

                for (int i=80;i<SCREEN_HEIGHT-180-t*10;i=i+t*10)
                {
                    for (int j=30;j<SCREEN_WIDTH-t*10;j=j+t*10)
                    {
                        if(k4==e1[0]){d[k4]=LEV_1_1a[c[f2]-1];}
                        if(k4==e1[1]){d[k4]=LEV_1_1a[c[f1]-1];}
                        renderTexture(d[k4], renderer, j, i, t*10, t*10);
                        k4++;
                    }
                }
                 SDL_SetRenderDrawColor(renderer, 255, 0, 0, 255);
                for (int i=30;i<SCREEN_WIDTH;i=i+t*10)
                {
                    SDL_RenderDrawLine(renderer, i, 80, i, 440);
                }
                for (int i=80;i<SCREEN_HEIGHT-180;i=i+t*10)
                {
                    SDL_RenderDrawLine(renderer, 30, i, 570, i);
                }

                SDL_RenderPresent(renderer);
                dem++;
                int f3;
                f3=c[f1];c[f1]=c[f2];c[f2]=f3;
                e1[0]=0;e1[1]=0;
                p=0;
            }
            SDL_RenderPresent(renderer);
        }
        }

        bool kt=0;
        for (int j=0;j<n;j++) if (c[j]!=j+1) kt=1;
        if (kt==0)
        {
            SDL_SetRenderDrawColor(renderer, 255, 255, 255, 255);
            SDL_RenderClear(renderer);
            string str_start1 ="PASS LEVEL";
            textObject pAK1;
            pAK1.setColor(textObject::BLACK_TEXT);
            pAK1.setText(str_start1);
            pAK1.loadFromRenderText(font_word1,renderer);
            pAK1.renderText(renderer, 200,25);
            int k5=0;
            for (int i=80;i<SCREEN_HEIGHT-t*10;i=i+t*10)
            {
                for (int j=30;j<SCREEN_WIDTH-t*10;j=j+t*10)
                {
                    renderTexture(d[k5], renderer, j, i, t*10, t*10);
                    k5++;
                }
            }
            SDL_SetRenderDrawColor(renderer, 255, 255, 255, 255);
                for (int i=30;i<SCREEN_WIDTH;i=i+t*10)
                {
                    if ((n==6)||(n==24)||(n==54)){SDL_RenderDrawLine(renderer, i, 80, i, 440);} else
                    if ((n==9)||(n==36)||(n==81)){SDL_RenderDrawLine(renderer, i, 80, i, 620);}
                }
                for (int i=80;i<SCREEN_HEIGHT-180;i=i+t*10)
                {
                    SDL_RenderDrawLine(renderer, 30, i, 570, i);
                }

            SDL_RenderPresent(renderer);
            SDL_Delay(2000);
            SDL_SetRenderDrawColor(renderer, 255, 255, 255, 255);
            SDL_RenderClear(renderer);
            string xy="CONGRATULATIONS!!!";
            textObject congra;
            congra.setColor(textObject::BLACK_TEXT);
            congra.setText(xy);
            congra.loadFromRenderText(font_word3,renderer);
            congra.renderText(renderer,20,50);

            int ra1=rand() % (24 + 1 -1);
            string ran1;
            ostringstream conv;
            conv << ra1;
            ran1 = conv.str();

            g_background.loadImg("image/meme/meme"+ran1+".jpg",renderer);
            g_background.render(renderer,60, 150, 500, 500, NULL);
            SDL_Delay(2000);

            string str_start ="(PRESS A KEY TO CONTINUE)";
            textObject pAK;
            pAK.setColor(textObject::BLACK_TEXT);
            pAK.setText(str_start);
            pAK.loadFromRenderText(font_word1,renderer);
            pAK.renderText(renderer, 60,600);

            SDL_RenderPresent(renderer);
            waitUntilKeyPressed1();

            break;
        }
    }
    SDL_SetRenderDrawColor(renderer, 255, 255, 255, 255);
    SDL_RenderClear(renderer);
    SDL_SetRenderDrawColor(renderer, 0, 0, 0, 0);
    for (int i=30;i<SCREEN_WIDTH;i=i+190)
    {
        SDL_RenderDrawLine(renderer, i-2, 428, i+163, 428);
    }
    for (int i=30;i<SCREEN_WIDTH;i=i+190)
    {
        SDL_RenderDrawLine(renderer, i-2, 522, i+163, 522);
    }
    for (int i=30;i<SCREEN_WIDTH;i=i+190)
    {
        SDL_RenderDrawLine(renderer, i-2, 428, i-2, 522);
    }
    for (int i=190;i<SCREEN_WIDTH;i=i+190)
    {
        SDL_RenderDrawLine(renderer, i+3, 428, i+3, 522);
    }
    SDL_Texture* imageAUS = loadTexture(S+"/areUSure.bmp",renderer);
    SDL_Texture* imageNote1 = loadTexture(S+"/exit.bmp",renderer);
    SDL_Texture* imageNote2 = loadTexture(S+"/playAgain.bmp",renderer);

    renderTexture(imageAUS, renderer, 110, 40, 380, 380);
    renderTexture(imageNote1, renderer, 30, 430, 161, 90);
    renderTexture(imageNote2, renderer, 220, 430, 161, 90);
    if (level<6)
    {
        SDL_Texture* imageNote3 = loadTexture(S+"/nextLevel.bmp",renderer);
        renderTexture(imageNote3, renderer, 410, 430, 161, 90);
    }
    SDL_RenderPresent(renderer);

    SDL_Event f;
    while (true)
    {
        SDL_Delay(10);
        if ( SDL_WaitEvent(&f) == 0) continue;
        if (f.type == SDL_QUIT) break;
        if (f.type == SDL_KEYDOWN && f.key.keysym.sym == SDLK_ESCAPE) break;

        if (f.type == SDL_MOUSEBUTTONDOWN)
        {
            if ((f.button.x>=30)&&(f.button.x<=570)&&(f.button.y>=430)&&(f.button.y<=520))
            {
                if (f.button.x>=30 && f.button.x<=190){quitSDL(window,renderer);} else
                if (f.button.x>=220 && f.button.x<=380)
                {
                    SDL_DestroyTexture(imageAUS);
                    SDL_DestroyTexture(imageNote1);
                    SDL_DestroyTexture(imageNote2);

                    SDL_SetRenderDrawColor(renderer, 0, 0, 0, 0);
                    SDL_RenderClear(renderer);
                    //introduce();
                    repeat(k+1,level);
                } else
                if (f.button.x>=410 && f.button.x<=570)
                {
                    SDL_DestroyTexture(imageAUS);
                    SDL_DestroyTexture(imageNote1);
                    SDL_DestroyTexture(imageNote2);

                    SDL_SetRenderDrawColor(renderer, 0, 0, 0, 0);
                    SDL_RenderClear(renderer);
                    //introduce();
                    repeat(k,level+1);
                }
            }
        }
    }
    if (k==10){quitSDL(window,renderer);}
}
//***********************************************************************************************************************
int main(int argc, char* argv[])
{
    if (initData() == false) return -1;
    chooseNu(NU);

    introduce();
    start();
    repeat(1,1);
    quitSDL(window, renderer);
    return 0;
}
//***********************************************************************************************************************

void start()
{
        SDL_SetRenderDrawColor(renderer, 0, 0, 0, 0);
        SDL_RenderClear(renderer);
        string s1="My project used material from";
        string s2=" many sources on the Internet";
        for (int i=0;i<s1.length();i++)
        {
            string s3="";
            textObject intro;
            intro.setColor(textObject::WHITE_TEXT);
            for (int j=0;j<=i;j++)
            {
                s3+=s1[j];
            }
            intro.setText(s3);
            intro.loadFromRenderText(font_word2, renderer);
            intro.renderText(renderer, 80, 100);
            SDL_RenderPresent(renderer);
            SDL_Delay(50);

        }
        for (int i=0;i<s2.length();i++)
        {
            string s4="";
            textObject intro;
            intro.setColor(textObject::WHITE_TEXT);
            for (int j=0;j<=i;j++)
            {
                s4+=s2[j];
            }
            intro.setText(s4);
            intro.loadFromRenderText(font_word2, renderer);
            intro.renderText(renderer, 80, 150);
            SDL_RenderPresent(renderer);
            SDL_Delay(50);
        }
        SDL_Delay(1000);
        SDL_Rect filled_rect;
        filled_rect.x = 15;
        filled_rect.y = 250;
        filled_rect.w = 560;
        filled_rect.h = 150;
        SDL_SetRenderDrawColor(renderer, 255, 255, 255, 255);
        SDL_RenderDrawRect(renderer, &filled_rect);
        string str_start1 ="MEMORIZE";
        textObject pAK1;
        pAK1.setColor(textObject::WHITE_TEXT);
        pAK1.setText(str_start1);
        pAK1.loadFromRenderText(font_word4,renderer);
        pAK1.renderText(renderer, 20,250);

        SDL_RenderPresent(renderer);
        SDL_Delay(2000);

        string str_start ="(PRESS A KEY TO START)";
        textObject pAK;
        pAK.setColor(textObject::WHITE_TEXT);
        pAK.setText(str_start);
        pAK.loadFromRenderText(font_word1,renderer);
        pAK.renderText(renderer, 100,600);

        SDL_RenderPresent(renderer);
        waitUntilKeyPressed1();
        SDL_SetRenderDrawColor(renderer, 0, 0, 0, 0);
        SDL_RenderClear(renderer);
}

void introduce()
{
    g_background.loadImg("image/meme/BG.jpg",renderer);
    g_background.render(renderer,0, 0, 600, 650, NULL);
    SDL_Rect filled_rect;
    filled_rect.x = 40;
    filled_rect.y = 500;
    filled_rect.w = 525;
    filled_rect.h = 50;
    SDL_SetRenderDrawColor(renderer, 255, 255, 255, 255);
    SDL_RenderDrawRect(renderer, &filled_rect);
    filled_rect.w = 0;
    std::string s="This's an achiement made by PENNY";

    for (int i=0;i<s.length();i++)
    {
        string s1="";
        textObject intro;
        intro.setColor(textObject::WHITE_TEXT);
        for (int j=0;j<=i;j++)
        {
            s1+=s[j];
        }
        intro.setText(s1);
        intro.loadFromRenderText(font_word2, renderer);
        intro.renderText(renderer, 50, 450);

        filled_rect.w +=i;
        SDL_RenderFillRect(renderer, &filled_rect);
        SDL_RenderPresent(renderer);
        SDL_Delay(150);
    }
}
//***********************************************************************************************************************
void logSDLError(std::ostream& os,const std::string &msg, bool fatal)
{
	os << msg << " Error: " << SDL_GetError() << std::endl;
	if (fatal)
	{
		SDL_Quit();
		exit(1);
	}
}
void quitSDL(SDL_Window* window, SDL_Renderer* renderer)
{
	SDL_DestroyRenderer(renderer);
	SDL_DestroyWindow(window);
	SDL_Quit();
}
void waitUntilKeyPressed()
{
	SDL_Event e;
	while (true)
	{
		if ( SDL_WaitEvent(&e) != 0 &&(e.type == SDL_KEYDOWN || e.type == SDL_QUIT) )
		return;
		SDL_Delay(100);
	}
}
void waitUntilKeyPressed1()
{
 	SDL_Event e;
	while (true)
	{
		if ( SDL_WaitEvent(&e) != 0 &&
		(e.type == SDL_KEYDOWN || e.type == SDL_QUIT) )
		return;
		SDL_Delay(10);
	}
}
//***************************************************************************************************
SDL_Texture* loadTexture(const std::string &file, SDL_Renderer *ren)
{
	SDL_Texture *texture = nullptr;
	SDL_Surface *loadedImage = SDL_LoadBMP(file.c_str());
	if (loadedImage != nullptr)
		{
		texture = SDL_CreateTextureFromSurface(ren, loadedImage);
		SDL_FreeSurface(loadedImage);

		if (texture == nullptr){
			logSDLError(std::cout, "CreateTextureFromSurface");
		}
	}
	else
	{
		logSDLError(std::cout, "LoadBMP");
	}
	return texture;
}
void renderTexture(SDL_Texture *tex, SDL_Renderer *ren, int x, int y)
{
	SDL_Rect dst;
	dst.x = x;
	dst.y = y;
	SDL_QueryTexture(tex, NULL, NULL, &dst.w, &dst.h);
	SDL_RenderCopy(ren, tex, NULL, &dst);
}

void renderTexture(SDL_Texture *tex, SDL_Renderer *ren, int x, int y, int w, int h)
{
	SDL_Rect dst;
	dst.x = x;
	dst.y = y;
    	dst.w = w;
    	dst.h = h;
	SDL_RenderCopy(ren, tex, NULL, &dst);
}
//***************************************************************************************************

