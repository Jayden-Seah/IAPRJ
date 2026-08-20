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
	setAttack(20);
	setAttackRange(1);
	setDefence(5);
	

}

void Respawn::SecretRespawn() {
	if (getKarma()) {
		setCoordX(103);
		setCoordY(1);

		sethealth(100);
	}
}
