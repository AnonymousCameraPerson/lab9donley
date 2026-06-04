#include <allegro5\allegro.h>
#include <allegro5\allegro_primitives.h>
#include <allegro5\allegro_image.h>
#include "player.h"


player::~player()
{
	al_destroy_bitmap(image);
}
player::player(int HEIGHT)
{
	lives = 5;
	image = al_load_bitmap("Kirby0.png");
	x = 20;
	y = HEIGHT / 2;
	
	speed = 7;
	boundx = al_get_bitmap_width(image);
	boundy = al_get_bitmap_height(image);
	score = 0;
}
void player::increaseHits() {
	hits += 1;
}
void player::DrawPlayer()
{
	if (lives == 5) {
		image = al_load_bitmap("Kirby0.png");
	}
	else if (lives == 4) {
		image = al_load_bitmap("Kirby1.png");
	}
	else if (lives == 3) {
		image = al_load_bitmap("Kirby2.png");
	}
	else if (lives == 2) {
		image = al_load_bitmap("Kirby3.png");
	}
	else if (lives == 1) {
		image = al_load_bitmap("Kirby4.png");
	}
	al_draw_bitmap(image, x, y, 0);
}
int player::getHits() {
	return hits;
}
void player::MoveUp()
{
	y -= speed;
	if (y < 0)
		y = 0;
}
void player::MoveDown(int HEIGHT)
{
	y += speed;
	if (y >= HEIGHT-getBoundY())
		y = HEIGHT- getBoundY();
}
void player::MoveLeft()
{
	x -= speed;
	if (x < 0)
		x = 0;
}
void player::MoveRight()
{
	x += speed;
	if (x > 300)
		x = 300;
}
int player::checkLife() {
	return lives;
}