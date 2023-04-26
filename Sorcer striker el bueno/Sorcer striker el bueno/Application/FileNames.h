#pragma once

#ifndef FILENAMES_H
#define FILENAMES_H

#include <string>


// --------|  FILE+TYPE_CATEGORY_NAME = PATH  |--------


#pragma region IMAGES -> FI
// Backgrounds
const std::string FI_background_beach = "../Assets/Images/Playa.png";
const std::string FI_background_sea = "../Assets/Images/Playa.png";
const std::string FI_background_forest1 = "../Assets/Images/Playa.png";
const std::string FI_background_forest2 = "../Assets/Images/Playa.png";
const std::string FI_background_castle = "../Assets/Images/Playa.png";

// Sprites player
const std::string FI_spritePlayer_player1 = "../Assets/Images/Playa.png";
const std::string FI_spritePlayer_player2 = "../Assets/Images/Playa.png";

// Sprites enemys
const std::string FI_spriteEnemy_red = "../Assets/Images/Playa.png";
const std::string FI_spriteEnemy_brown = "../Assets/Images/Playa.png";

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
const std::string FTA_fx_token = "../Assets/Audios/FX/token-insertado.wav";

const std::string FTA_Music_introTitle = "../Assets/Audios/Hud-music/musica-menu.ogg";
const std::string FTA_Music_stage1 = "../Assets/Audios/Stage-1/stage1.ogg";
#pragma endregion

#endif