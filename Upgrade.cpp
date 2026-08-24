#include "Upgrade.h"
#include "CEntity.h"
#include "CPlayer.h"
#include "CObject.h"

int Upgrade::killcount = 0;

void Upgrade::upgrade() {
    if (upg1 = false) {

    }
    else if (upg1 && !upg2) {

    }
}


void Upgrade::unupgrade() {
    killcount = 0;
    int pi = event_dist(gene);
    upg1 = false;
    upg2 = false;
}
