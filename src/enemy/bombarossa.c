#include "global.h"
#include "entity.h"
#include "enemy.h"
#include "player.h"
#include "object.h"
#include "random.h"
#include "functions.h"

void sub_0803350C(Entity*);
void sub_080333D4(Entity*);
void sub_08033448(Entity*);
void sub_0804A7D4(Entity*);
void nullsub_158(Entity*);

// gUnk_080CEB38
void (*const gBombarossaFunctions[])(Entity*) = {
    sub_080333D4, sub_08033448, sub_08001324, sub_0804A7D4, sub_08001242, nullsub_158,
};

const s8 gUnk_080CEB50[] = {
    0, -1, -2, -3, -4, -3, -2, -1, -18, -19, -20, -21, -22, -21, -20, -19,
};

void Bombarossa(Entity* this) {
    gBombarossaFunctions[GetNextFunction(this)](this);
}

void sub_080333D4(Entity* this) {
    if (this->action == 0) {
        this->action = 1;
        this->actionDelay = Random() & 0xF;
        InitializeAnimation(this, 0);

        if (this->type != 0) {
            this->child = GetCurrentRoomProperty(this->type);
            sub_080A2CC0(this, &this->child, &this->field_0x76.HWORD);
        }
    }

    this->z.HALF.HI = gUnk_080CEB50[((++this->actionDelay >> 4) % 8) + this->type2 * 8];

    GetNextFrame(this);

    if (this->type != 0) {
        sub_0803350C(this);
    }
}

void sub_08033448(Entity* this) {
    Entity* ent;

    switch (this->bitfield & 0x7F) {
        case 0x1:
        case 0xF:
        case 0x13:
        case 0x1B:
        case 0x1D:
        case 0x1E:
            break;

        default:
            ent = CreateObject(OBJECT_20, 0, 0);
            if (ent != NULL) {
                CopyPosition(this, ent);
            }

            DeleteThisEntity();
            break;
    }

    sub_0804AA30(this, gBombarossaFunctions);
}

void nullsub_158(Entity* this) {
}

void sub_0803350C(Entity* this) {
    if (!(this->direction & 0x80)) {
        sub_0806F69C(this);
    }

    this->field_0x76.HWORD--;

    if (this->field_0x76.HWORD == 0) {
        sub_080A2CC0(this, &this->child, &this->field_0x76.HWORD);
    }
}
