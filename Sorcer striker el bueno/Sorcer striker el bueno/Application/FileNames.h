#pragma once

#ifndef FILENAMES_H
#define FILENAMES_H

#include <string>


// --------|  FILE+TYPE_CATEGORY_NAME = PATH  |--------


#pragma region IMAGES -> FI
// Backgrounds
const std::string FI_background_beach = "../Assets/Images/Playa.png";
const std::string FI_background_sea = "../Assets/Images/Mar.png";
const std::string FI_background_forest1 = "../Assets/Images/Bosque_1.png";
const std::string FI_background_forest2 = "../Assets/Images/Bosque_2.png";
const std::string FI_background_castle = "../Assets/Images/Castillo.png";

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
const std::string FI_spriteBoss_boss1 = "../Assets/Images/Playa.png";
#pragma endregion



#pragma region AUDIOS -> FA
// Inicio
const std::string FA_menu_noise1 = "../Assets/Sounds/ruido.wav";
const std::string FA_menu_noise2 = "../Assets/Sounds/ruido.wav";

// Nivel 1
#pragma endregion



#pragma region TEMPORAL (NO BORRAR) -> FT
const std::string FTI_sprites_enemies = "../Assets/Sprites/enemies.png";
const std::string FTI_sprites_ship = "../Assets/Sprites/ship.png";
const std::string FTI_sprites_startScreen = "../Assets/Sprites/startScreen.png";
const std::string FTI_sprites_background = "../Assets/Sprites/background.png";
const std::string FTI_sprites_particles = "../../Assets/Sprites/particles.png";

const std::string FTI_font_font3 = "../Assets/Fonts/rtype_font3.png";


const std::string FTA_fx_explosion = "../Assets/Fx/explosion.wav";
const std::string FTA_fx_laser = "../Assets/Fx/laser.wav";

const std::string FTA_Music_introTitle = "../Assets/Music/introTitle.ogg";
const std::string FTA_Music_stage1 = "../Assets/Music/stage1.ogg";
#pragma endregion

#endif