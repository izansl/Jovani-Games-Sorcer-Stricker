#include "ModuleHUD.h"

ModuleHUD::ModuleHUD(bool startEnabled) : Module(startEnabled) {
	// Inicializa las variables de puntuación
	score = 0;
	highScore = 0;

	LoadVector();
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

Update_Status ModuleHUD::PostUpdate()
{
	return Update_Status();
}

int ModuleHUD::PosLetter(char leterToSearch)
{
	for (int i = 0; i < NUM_LETTERS; i++)
	{
		if (vectorABC[i].lletra == leterToSearch)
		{
			return i;
			break;
		}
	}
	return 0;
}

void ModuleHUD::LoadVector()
{
	vectorABC.push_back({ '!', 0 });
	vectorABC.push_back({ '$', 1 });
	vectorABC.push_back({ '%', 2 });
	vectorABC.push_back({ '&', 3 });
	vectorABC.push_back({ '-', 4 });
	vectorABC.push_back({ '.', 5 });
	vectorABC.push_back({ '/', 6 });

	vectorABC.push_back({ '0', 7 });
	vectorABC.push_back({ '1', 8 });
	vectorABC.push_back({ '2', 9 });
	vectorABC.push_back({ '3', 10 });
	vectorABC.push_back({ '4', 11 });
	vectorABC.push_back({ '5', 12 });
	vectorABC.push_back({ '6', 13 });
	vectorABC.push_back({ '7', 14 });
	vectorABC.push_back({ '8', 15 });
	vectorABC.push_back({ '9', 16 });

	vectorABC.push_back({ '*', 17 }); //star
	vectorABC.push_back({ ';', 18 });
	vectorABC.push_back({ '<', 19 }); //arrow
	vectorABC.push_back({ 'º', 20 }); //heart
	vectorABC.push_back({ '?', 21 });

	vectorABC.push_back({ 'A', 22 });
	vectorABC.push_back({ 'B', 23 });
	vectorABC.push_back({ 'C', 24 });
	vectorABC.push_back({ 'D', 25 });
	vectorABC.push_back({ 'E', 26 });
	vectorABC.push_back({ 'F', 27 });
	vectorABC.push_back({ 'G', 28 });
	vectorABC.push_back({ 'H', 29 });
	vectorABC.push_back({ 'I', 30 });
	vectorABC.push_back({ 'J', 31 });
	vectorABC.push_back({ 'K', 32 });
	vectorABC.push_back({ 'L', 33 });
	vectorABC.push_back({ 'M', 34 });
	vectorABC.push_back({ 'N', 35 });
	vectorABC.push_back({ 'O', 36 });
	vectorABC.push_back({ 'P', 37 });
	vectorABC.push_back({ 'Q', 38 });
	vectorABC.push_back({ 'R', 39 });
	vectorABC.push_back({ 'S', 40 });
	vectorABC.push_back({ 'T', 41 });
	vectorABC.push_back({ 'U', 42 });
	vectorABC.push_back({ 'V', 43 });
	vectorABC.push_back({ 'W', 44 });
	vectorABC.push_back({ 'X', 45 });
	vectorABC.push_back({ 'Y', 46 });
	vectorABC.push_back({ 'Z', 47 });
}

void ModuleHUD::WriteStringToScreen(char* sentenceToPaint, iPoint positionToPaint)
{
}