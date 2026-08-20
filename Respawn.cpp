#include "Respawn.h"
#include "CEntity.h"
#include "CPlayer.h"
#include "CObject.h"



void Respawn::Respawning() {
	//delete everything and recreate
	setKarma(100);

	setCoordX(103);
	setCoordY(1);

	sethealth(100);
}

void Respawn::SecretRespawn() {
	if (getKarma()) {

	}
}
