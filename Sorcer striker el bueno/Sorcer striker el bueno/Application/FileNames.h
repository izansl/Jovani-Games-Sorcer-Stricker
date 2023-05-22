#pragma once

#ifndef FILENAMES_H
#define FILENAMES_H

#include <string>


// --------|  FILE+TYPE_CATEGORY_NAME = PATH  |--------


#pragma region IMAGES -> FI
//IntroImages
//cambiar a png //cambiar ruta a ImagenesIntro2
const std::string FI_Introimage_1 = "../Assets/Images/Intro/jovani.png";
const std::string FI_Introimage_2 = "../Assets/Images/Intro/Raizing.png";
const std::string FI_Introimage_3 = "../Assets/Images/Intro/PrimertextoColor.png";
const std::string FI_Introimage_4 = "../Assets/Images/Intro/primertextoBlanco.png";
const std::string FI_Introimage_5 = "../Assets/Images/Intro/alienarribafondo.png";
const std::string FI_Introimage_6 = "../Assets/Images/Intro/cuartotextoColor.png";
const std::string FI_Introimage_7 = "../Assets/Images/Intro/explosiones.png";
const std::string FI_Introimage_8 = "../Assets/Images/Intro/fondobatman.png";
const std::string FI_Introimage_9 = "../Assets/Images/Intro/jovani.png";
const std::string FI_Introimage_10 = "../Assets/Images/Intro/primertextoblanco.png";
const std::string FI_Introimage_11 = "../Assets/Images/Intro/PrimertextoColor.png";
const std::string FI_Introimage_12 = "../Assets/Images/Intro/quintotextoBlanco.png";
const std::string FI_Introimage_13 = "../Assets/Images/Intro/quintotextoColor.png";
const std::string FI_Introimage_14 = "../Assets/Images/Intro/Raizing.png";
const std::string FI_Introimage_15 = "../Assets/Images/Intro/segundotextoBlanco.png";
const std::string FI_Introimage_16 = "../Assets/Images/Intro/segundotextoColor.png";
const std::string FI_Introimage_17 = "../Assets/Images/Intro/tercertextoBlanco.png";
const std::string FI_Introimage_18 = "../Assets/Images/Intro/tercertextoColor.png";

//Start
const std::string FI_Start_1 = "../Assets/Images/Intro/pantallainiciouno.png";
const std::string FI_Start_2 = "../Assets/Images/Intro/pantallainiciodos.png";

//Menu Player
const std::string FI_choseplayer_1 = "../Assets/Images/Intro/playerpcik.png";
const std::string FI_choseplayer_2 = "../Assets/Images/Intro/onepcolor.png";

// Backgrounds
//const std::string FI_background_beach = "../Assets/Images/Beach.png";//revisar
const std::string FI_background_sea = "../Assets/Images/pre-castillo/mar.png";
const std::string FI_background_forest1 = "../Assets/Images/pre-castillo/bosque.png";
const std::string FI_background_castle = "../Assets/Images/pre-castillo/castillo.png";
const std::string FI_background_pre = "../Assets/Images/pre-castillo/comienzodeljuegofondo.png";
const std::string FI_background_precolumnas = "../Assets/Images/pre-castillo/columnas-inicio.png";
const std::string FI_background_playerpick = "../Assets/Images/pre-castillo/playerpick.png";
const std::string FI_background_personas = "../Assets/Images/pre-castillo/personas.png";

//const int Height_background_beach = 3000;
const int Height_background_sea = 10000;
const int Height_background_forest1 = 3000;
const int Height_background_castle = 10000;
const int Height_background_pre = 2850;
const int Height_background_precolumnas = 2850;

//HUD
const std::string FI_HUD_font1 = "../Assets/Images/Fonts/rtype_font.png";
const std::string FI_HUD_font2 = "../Assets/Images/Fonts/rtype_font2.png";
const std::string FI_HUD_stage1 = "../Assets/Images/Fonts/stage1.png";

// Sprites player
const std::string FI_spritePlayer_1 = "../Assets/Images/pre-castillo/naves.png";//actual

const std::string FI_spritePlayer_shoots = "../Assets/Images/pre-castillo/disparos_nave.png";

const std::string FI_spritePlayer_explosions = "../Assets/Images/pre-castillo/Explosions.png";

//Sprites enemies

const std::string FI_spriteEnemy_reds = "../Assets/Images/pre-castillo/enemies.png";
//red ball
//({29, 357, 82, 104})
//({140, 357, 82, 104})
// 
//mago
//({0, 798, 131, 132})frente
//({0, 955, 131, 132})frente
//({159, 802, 131, 132})giro derecha inicio
//({320, 801, 131, 132})giro derecha medio
//({493, 802, 131, 132})giro derecha final
//({197, 956, 131, 132}) giro izquierda inicio
//({324, 956, 131, 132})giro izquierda medio
//({491, 957, 131, 132})giro izquierda final
// 
//mago herido
//({0, 487, 131, 132})frente
//({0, 635, 131, 132}) frente
//({170, 497, 131, 132})giro derecha inicio
//({325, 647, 131, 132})giro derecha medio
//({493, 648, 131, 132})giro derecha final
//({167, 650, 131, 132})giro izquierda inicio
//({329, 493, 131, 132})giro izquierda medio
//({491, 495, 131, 132})giro izquierda final
// 
// disparo mago
//({640, 521, 99, 79})
//({861, 521, 99, 79 })
//({1007, 528, 99, 79})
//({933, 528, 99, 79 })
//({731, 527, 99, 79})
// 
//explosion
//({1, 136, 139, 137})
//({155, 140, 139, 137})
//({335, 142, 139, 137})
//({586, 139, 139, 137})
//({644, 142, 139, 137})
//({798, 142, 139, 137})


const std::string FI_spriteEnemy_dragon = "../Assets/Images/pre-castillo/dragon.png";

const std::string FI_spriteEnemy_enemiesvar_1 = "../Assets/Images/castillo/enemigos_varios.png";

const std::string FI_spriteEnemy_ = "../Assets/Images/castillo/tanque.png";

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
//const std::string FI_spriteEnemy_3 = "../Assets/Images/3rd_enemy.png";
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
//const std::string FI_spritebonus_pickups = "../Assets/Images/Chests.png";
/*	-Bluechest
		-Hada con cofre
			1-({2, 7, 43, 39 })
			2-({47, 7, 43, 39 })
			3-({94, 7, 43, 39 })
		-Librobuff
			1-({58, 20, 15, 20 })
			2-({72, 54, 15, 20})
*/
const std::string FI_spritebonus_pickups = "../Assets/Images/pre-castillo/allprops.png";
/*
* -cofreverde
1-({15, 25, 118, 99}) oscuro
2-({132, 20, 118, 99}) medio
3-({260, 17, 118, 99})brillante
-buff verde
1-({40, 137, 63, 78}) oscuro
2-({155, 138, 63, 78})brillante
* -cofreazul
1-({14, 251, 118, 99}) oscuro
2-({140, 257, 118, 99}) medio
3-({244, 246, 118, 99})brillante
-buff azul
1-({42, 369, 62, 78}) oscuro
2-({161, 365, 62, 78})brillante
* -cofrerojo
1-({17, 501, 118, 99}) oscuro
2-({135, 498, 118, 99}) medio
3-({258, 493, 118, 99})brillante
-buff rojo
1-({40, 137, 63, 78}) oscuro
2-({155, 138, 63, 78})brillante
*/

// Sprites Bosses
const std::string FI_spriteEnemy_boss = "../Assets/Images/final-boss/finalbossnuevo.png";

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