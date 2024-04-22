#include <SDL2/SDL.h>
#include <SDL2/SDL_ttf.h>
#include <algorithm>
#include <vector>
#include <cmath>
#include <iostream>
#include <iomanip>
using namespace std;

const int SCREEN_WIDTH = 1000;
const int SCREEN_HEIGHT = 1000;
const int FONT_SIZE = 60;

double F1(double x) {
    return 1 + pow(2, (x + 5));
}

double F2(double x) {
    return pow((x - 1), 3);
}

void drawGraph(SDL_Renderer* renderer, vector<double>& x_values, vector<double>& y_values, SDL_Color color, const char* label, TTF_Font* font) {
    SDL_SetRenderDrawColor(renderer, color.r, color.g, color.b, color.a);
    
    // Масштабирование координат
    double scaleX = 50;
    double scaleY = 20;

    int prevX = SCREEN_WIDTH / 2 + (x_values[0] * scaleX);
    int prevY = SCREEN_HEIGHT / 2 - (y_values[0] * scaleY);

    for (size_t i = 1; i < x_values.size(); ++i) {
        int x = SCREEN_WIDTH / 2 + (x_values[i] * scaleX);
        int y = SCREEN_HEIGHT / 2 - (y_values[i] * scaleY);
        
        SDL_RenderDrawLine(renderer, prevX, prevY, x, y);
        
        prevX = x;
        prevY = y;
    }
    
    // Отрисовка осей
    SDL_SetRenderDrawColor(renderer, 255, 255, 255, 255);
    SDL_RenderDrawLine(renderer, 0, SCREEN_HEIGHT / 2, SCREEN_WIDTH, SCREEN_HEIGHT / 2);
    SDL_RenderDrawLine(renderer, SCREEN_WIDTH / 2, 0, SCREEN_WIDTH / 2, SCREEN_HEIGHT);
    SDL_SetRenderDrawColor(renderer, color.r, color.g, color.b, color.a);
    
    // Отображение текста

    SDL_Surface* surfaceMessage = TTF_RenderText_Solid(font, label, color);
    SDL_Texture* message = SDL_CreateTextureFromSurface(renderer, surfaceMessage);
    SDL_Rect message_rect;
    message_rect.x = SCREEN_WIDTH - 95;
        
    if (strcmp(label, "F1(x) = 1+2^(x+5)") == 0) {
        message_rect.y = 5;
    } else if (strcmp(label, "F2(x) = (x-1)^3") == 0) {
        message_rect.y = 30;
    }
    message_rect.w = 80;
    message_rect.h = 20;
    SDL_RenderCopy(renderer, message, NULL, &message_rect);
    
    SDL_FreeSurface(surfaceMessage);
    SDL_DestroyTexture(message);
}

void task1() {
    double a = -10;
    double b = 10;
    int n = 1000;
    double step = (b - a) / (n - 1);
    TTF_Font* font = TTF_OpenFont("arial.ttf", FONT_SIZE);
    SDL_Window* window = SDL_CreateWindow("Графики функций", SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, SCREEN_WIDTH, SCREEN_HEIGHT, SDL_WINDOW_SHOWN);
    SDL_Renderer* renderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED);


    vector<double> x_values;
    vector<double> F1_values;
    vector<double> F2_values;

    for (int i = 0; i < n; ++i) {
        double x = a + i * step;
        x_values.push_back(x);
        F1_values.push_back(F1(x));
        F2_values.push_back(F2(x));
    }


    SDL_Color color1 = {255, 0, 0, 255}; // красный цвет для F1(x)
    drawGraph(renderer, x_values, F1_values, color1, "F1(x) = 1+2^(x+5)", font);

    SDL_Color color2 = {0, 255, 0, 255}; // зеленый цвет для F2(x)
    drawGraph(renderer, x_values, F2_values, color2, "F2(x) = (x-1)^3", font);



    SDL_RenderPresent(renderer);
    bool quit = false;
    SDL_Event e;
    while (!quit) {
        while (SDL_PollEvent(&e) != 0) {
            if (e.type == SDL_QUIT) {
                quit = true;
            }
        }
        SDL_Delay(100); 
    }

    SDL_DestroyRenderer(renderer);
    SDL_DestroyWindow(window);
    TTF_CloseFont(font);
}



SDL_Color getRandomColor() {
    SDL_Color color;
    color.r = rand() % 256;
    color.g = rand() % 256;
    color.b = rand() % 256;
    color.a = 255;
    return color;
}

void renderText(SDL_Renderer* renderer, TTF_Font* font, const char* text, int x, int y, SDL_Color color) {
    SDL_Surface* surfaceMessage = TTF_RenderText_Solid(font, text, color);
    SDL_Texture* message = SDL_CreateTextureFromSurface(renderer, surfaceMessage);

    SDL_Rect message_rect;
    message_rect.x = x;
    message_rect.y = y;
    message_rect.w = surfaceMessage->w;
    message_rect.h = surfaceMessage->h;

    SDL_RenderCopy(renderer, message, NULL, &message_rect);

    SDL_FreeSurface(surfaceMessage);
    SDL_DestroyTexture(message);
}

void task2() {

    SDL_Window* window = SDL_CreateWindow("Colorful Numbers", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, SCREEN_WIDTH, SCREEN_HEIGHT, SDL_WINDOW_SHOWN);
    SDL_Renderer* renderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED);
    TTF_Font* font = TTF_OpenFont("arial.ttf", FONT_SIZE);

    bool quit = false;
    SDL_Event e;


    while (!quit) {
        while (SDL_PollEvent(&e) != 0) {
            if (e.type == SDL_QUIT) {
                quit = true;
            }
        }

        SDL_SetRenderDrawColor(renderer, 0, 0, 0, 255);
        SDL_RenderClear(renderer);

        for (int i = 0; i < SCREEN_WIDTH; i += FONT_SIZE) {
            for (int j = 0; j < SCREEN_HEIGHT; j += FONT_SIZE) {
                SDL_Color color = getRandomColor();
                string number = to_string(rand() % 10); // случайное число от 0 до 9
                renderText(renderer, font, number.c_str(), i, j, color);
            }
        }

        SDL_RenderPresent(renderer);

        SDL_Delay(100); 
    }

    TTF_CloseFont(font);
    SDL_DestroyRenderer(renderer);
    SDL_DestroyWindow(window);
}



int main(){
    if (SDL_Init(SDL_INIT_VIDEO) < 0) {
        cerr << SDL_GetError() << endl;
        return 1;
    }
    if (TTF_Init() == -1) {
        cerr << TTF_GetError() << endl;
        return 1;
    }
    task1();
    task2();
    TTF_Quit();
    SDL_Quit();
    return 0;
}