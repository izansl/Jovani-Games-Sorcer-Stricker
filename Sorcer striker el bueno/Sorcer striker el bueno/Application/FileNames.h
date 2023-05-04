#pragma once

#ifndef FILENAMES_H
#define FILENAMES_H

#include <string>


// --------|  FILE+TYPE_CATEGORY_NAME = PATH  |--------


#pragma region IMAGES -> FI
//IntroImages
//cambiar a png //cambiar ruta a ImagenesIntro2
const std::string FI_Introimage_1 = "../Assets/Images/ImagenesIntro2/intro1.png";
const std::string FI_Introimage_2 = "../Assets/Images/ImagenesIntro2/intro2.png";
const std::string FI_Introimage_3 = "../Assets/Images/ImagenesIntro2/intro3.png";
const std::string FI_Introimage_4 = "../Assets/Images/ImagenesIntro2/intro4.png";
const std::string FI_Introimage_5 = "../Assets/Images/ImagenesIntro2/intro5.png";
const std::string FI_Introimage_6 = "../Assets/Images/ImagenesIntro2/intro6.png";
const std::string FI_Introimage_7 = "../Assets/Images/ImagenesIntro2/intro7.png";
const std::string FI_Introimage_8 = "../Assets/Images/ImagenesIntro2/intro8.png";
const std::string FI_Introimage_9 = "../Assets/Images/ImagenesIntro2/intro9.png";
const std::string FI_Introimage_10 = "../Assets/Images/ImagenesIntro2/intro10.png";
const std::string FI_Introimage_11 = "../Assets/Images/ImagenesIntro2/intro11.png";
const std::string FI_Introimage_12 = "../Assets/Images/ImagenesIntro2/intro12.png";

// Backgrounds
const std::string FI_background_beach = "../Assets/Images/Beach.png";
const std::string FI_background_sea = "../Assets/Images/Sea.png";
const std::string FI_background_forest1 = "../Assets/Images/Forest_1.png";
const std::string FI_background_forest2 = "../Assets/Images/Forest_2.png";
const std::string FI_background_castle = "../Assets/Images/Castle.png";
const int Height_background_beach = 3000;
const int Height_background_sea = 4500;
const int Height_background_forest1 = 3000;
const int Height_background_forest2 = 3000;
const int Height_background_castle = 4500;

//HUD


// Sprites player
const std::string FI_spritePlayer_player1 = "../Assets/Images/Character.png";
const std::string FI_spritePlayer_player2 = "../Assets/Images/Character.png";

// Sprites enemys
const std::string FI_spriteEnemy_1 = "../Assets/Images/1st_enemy.png";
/*-Movement
1 - ({ 43, 12, 32, 32 })
2 - ({ 73, 12, 32, 32 })
- Explosion
1 - ({ 7, 50, 32, 32 })
2 - ({ 42, 50, 32, 32 })
3 - ({ 77, 51, 32, 32 })
4 - ({ 111, 52, 32, 32 })
*/
const std::string FI_spriteEnemy_2 = "../Assets/Images/2nd_enemy.png";
/*-Movement
		1-({4, 22, 36, 36})
		2-({41, 22, 36, 36 })
	-Explosion
		1-({3, 71, 36, 36})
		2-({39, 72, 36, 36 })
		3-({75, 72, 36, 36 })
		4-({111, 71, 36, 36})
	Atack
		1-({82, 30 , 20, 20})
		2-({102, 31, 20, 20})
		3-({121, 30, 20, 20})	*/
const std::string FI_spriteEnemy_3 = "../Assets/Images/3rd_enemy.png";
/*	-Movement
		1-({15, 24, 90, 90})
		2-({115, 24, 90, 90})
	-Explosion
		1-({17, 121, 90, 90})
		2-({111, 124, 90, 90})
		3-({204, 123, 90, 90})
	Atack
		1-({229, 77, 15, 15})
		2-({245, 77, 15, 15})*/
		//Sprites chest
const std::string FI_spritechest_blue = "../Assets/Images/Chests.png";
/*	-Bluechest
		-Hada con cofre
			1-({2, 7, 43, 39 })
			2-({47, 7, 43, 39 })
			3-({94, 7, 43, 39 })
		-Librobuff
			1-({58, 20, 15, 20 })
			2-({72, 54, 15, 20})
*/


// Sprites Bosses
const std::string FI_spriteBoss_boss1 = "../Assets/Images/Beach.png";

//explosion enemiga
const std::string FI_spriteExplosion_enemies = "../Assets/Images/2nd_enemy.png";
#pragma endregion



#pragma region AUDIOS -> FA
// General
const std::string FA_Fx_token = "../Assets/Audios/FX/token-insertado.wav";

// Init
const std::string FA_Music_introTitle = "../Assets/Audios/Hud-music/musica-menu.ogg";

// Level 1
const std::string FA_Music_stage1 = "../Assets/Audios/Stage-1/stage1.ogg";

// Explosion enemiga
const std::string FA_Fx_explosion = "../Assets/Audios/FX/explosion-muerte-enemiga.wav";

//Explosion jugador
const std::string FA_Fx_explosionJ = "../Assets/Audios/FX/explosion(jugador-muerto).wav";
// Level 2

// Level 3

// Level 4

// Level 5

// Level 6

// Level 7

#pragma endregion



#endif