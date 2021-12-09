#include "global.h"
#include "entity.h"
#include "player.h"
#include "random.h"
#include "functions.h"

extern u16 gUnk_08123318[];

void LilypadSmall(Entity* this) {
    u32 rand;
    u16* psVar4;

    if (this->action == 0) {
        this->action = 1;
        this->actionDelay = 0x5a;
        rand = Random();
        this->field_0xf = rand;
        this->frameIndex = (rand >> 0x10) & 3;
        this->spriteSettings.draw = TRUE;
        this->spritePriority.b0 = 7;
        this->child = GetCurrentRoomProperty(this->type2);
        sub_080A2CC0(this, &this->child, &this->field_0x70.HALF.LO);
    }
    sub_080A2BE4(this, sub_08097ADC(this));
    sub_08097B24(this);
    psVar4 = (u16*)&this->field_0x70;
    if (--*psVar4 == 0) {
        sub_080A2CC0(this, &this->child, psVar4);
    }
}

u32 sub_08097ADC(Entity* this) {
    if ((gPlayerState.flags & PL_IS_MINISH) == 0) {
        return 0;
    } else if (sub_080041A0(this, &gPlayerEntity, 8, 8) == 0) {
        return 0;
    } else if (sub_08079F8C() == 0) {
        return 0;
    } else {
        gPlayerState.field_0x14 = 1;
        if (gPlayerEntity.z.HALF.HI != 0) {
            return 0;
        } else {
            return 1;
        }
    }
}

void sub_08097B24(Entity* this) {
    u32 temp;
    u32 temp2;
    u16* temp3;

    if (--this->actionDelay == 0) {
        this->actionDelay = 0x5a;
        this->frameIndex = (this->frameIndex + 1) & 3;
    }
    temp3 = gUnk_08123318;
    temp2 = ++this->field_0xf;

    temp = temp3[(temp2 >> 5) & 7];
    sub_0805EC9C(this, temp, temp, 0);
}
