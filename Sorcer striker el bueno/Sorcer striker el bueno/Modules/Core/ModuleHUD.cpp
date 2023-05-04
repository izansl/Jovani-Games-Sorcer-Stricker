#include "ModuleHUD.h"

ModuleHUD::ModuleHUD() {
    // Inicializa las variables de puntuación
    score = 0;
    highScore = 0;
}

ModuleHUD::~ModuleHUD() {
    // Destructor
}

void ModuleHUD::UpdateScore(int newScore) {
    // Actualiza la puntuación del jugador
    score = newScore;
}

void ModuleHUD::UpdateHighScore(int newHighScore) {
    // Actualiza el high score
    highScore = newHighScore;
}

void ModuleHUD::Render(SDL_Renderer* renderer) {
    // Renderiza la HUD en pantalla
    // Aquí puedes usar funciones de SDL para dibujar el high score y la puntuación actual
    // en la posición deseada en la pantalla

    // Carga la imagen de la fuente (.png)
    SDL_Surface* fontSurface = IMG_Load("../Assets/Images/Fonts/rtype_font.png");
    if (fontSurface == nullptr) {
        // Manejo de error si no se puede cargar la imagen de fuente
        return;
    }

    // Crea una textura a partir de la superficie de la fuente
    SDL_Texture* fontTexture = SDL_CreateTextureFromSurface(renderer, fontSurface);
    if (fontTexture == nullptr) {
        // Manejo de error si no se puede crear la textura de la fuente
        SDL_FreeSurface(fontSurface);
        return;
    }

    // Obtén el ancho y alto de cada carácter de la fuente
    int charWidth = fontSurface->w;
    int charHeight = fontSurface->h;

    // Calcula la posición de renderizado del primer carácter (por ejemplo, en la esquina superior izquierda)
    int xPos = 176;
    int yPos = 1;

    // Renderiza cada dígito de la puntuación en la posición calculada
    std::string scoreString = std::to_string(score);
    for (char digit : scoreString) {
        int digitValue = digit - '0'; // Convierte el carácter a su valor entero correspondiente
        int srcX = xPos * charWidth; // Calcula la posición en X del carácter en la imagen de la fuente

        SDL_Rect srcRect = { srcX, 0, charWidth, charHeight };
        SDL_Rect dstRect = { xPos, yPos, charWidth, charHeight };

        SDL_RenderCopy(renderer, fontTexture, &srcRect, &dstRect);

        xPos += charWidth; // Aumenta la posición X para el siguiente carácter
    }

    // Libera la textura y la superficie de la fuente
    SDL_DestroyTexture(fontTexture);
    SDL_FreeSurface(fontSurface);
}

int ModuleHUD::poslletra(char lletraBuscar)
{
    return 0;
}

void ModuleHUD::carregarVector()
{
}

void ModuleHUD::EscriureString(char* fraseAPintar, iPoint posicioAPintar)
{
}