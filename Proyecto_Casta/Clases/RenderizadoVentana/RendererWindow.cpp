#include <iostream>
#include "SDL.h"
#include <SDL2/SDL_image.h>
#include "RendererWindow.h"
#define fps 120                                        ///#define es una directiva del preprocesador que permite definir constantes y macros.

using namespace std;


RendererWindow::RendererWindow(const char *titulo, int largo, int ancho)
    : window(nullptr), renderer(nullptr)                    ///INICIALIZAMOS LOS MIEMBROS WINDOW Y RENDER EN NULL
{



    window = SDL_CreateWindow(titulo,                       ///CREACION DE VENTANA
                                SDL_WINDOWPOS_UNDEFINED,    ///Posicion de la ventana en eje X
                                SDL_WINDOWPOS_UNDEFINED,    ///Posicion de la ventana en eje Y
                                largo,                      ///Largo
                                ancho,                      ///Ancho
                                SDL_WINDOW_SHOWN            ///Comportamiento de la ventana
                                );

    if( window == nullptr ) cout << "LA VENTANA FALLO EN INICIALIZARSE! Error: " << SDL_GetError() <<endl;

    renderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED); ///CREA EL RENDERIZADOR QUE UTILIZARA LA TARJETA GRAFICA QUE TENGA EL EQUIPO. EN CASO DE TENER.

    if( renderer == nullptr ) cout << "EL RENDERIZADOR FALLO EN INICIALIZARSE! Error: " << SDL_GetError() <<endl;
}

SDL_Texture* RendererWindow::cargar_textura(const char *direccion_archivo)
{
    SDL_Texture *texture = nullptr;

    texture = IMG_LoadTexture(renderer, direccion_archivo);

    if(texture == nullptr) cout << "FALLO EN CARGAR TEXTURA! ERROR: " << SDL_GetError() << endl;

    return texture;
}


void RendererWindow::limpiar()
{
    SDL_DestroyWindow(window);
}


