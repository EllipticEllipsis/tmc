#include "entity.h"

void Lamp_Init(Entity* this);
void Lamp_Action1(Entity* this);

void Lamp(Entity* this) {
    static void (*const actionFuncs[])(Entity*) = {
        Lamp_Init,
        Lamp_Action1,
    };

    actionFuncs[this->action](this);
}

void Lamp_Init(Entity* this) {
    this->action = 1;
    UpdateSpriteForCollisionLayer(this);
    InitializeAnimation(this, 0);
}

void Lamp_Action1(Entity* this) {
    GetNextFrame(this);
}
