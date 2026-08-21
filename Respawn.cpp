#include "Respawn.h"
#include "CEntity.h"
#include "CPlayer.h"
#include "CObject.h"



void Respawn::upgrade() {
	if (upg1 = false) {

	}
	else if (upg1 && !upg2) {

	}
}


void Respawn::unupgrade() {
	killcount = 0;
	upg1 = false;
	upg2 = false;
}
