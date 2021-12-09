#include "global.h"
#include "entity.h"
#include "room.h"
#include "functions.h"

void BladeTrap(Entity* this) {
    if (this->action == 0) {
        this->action = 1;
        this->child = GetCurrentRoomProperty(this->type);
        sub_080A2CC0(this, &this->child, &this->field_0x74.HWORD);
    }
    if (!(this->direction & 0x80)) {
        sub_0806F69C(this);
    }

    if (!(--this->field_0x74.HWORD)) {
        if (!(this->direction & 0x80)) {
            EnqueueSFX(0x74);
        }
        sub_080A2CC0(this, &this->child, &this->field_0x74.HWORD);
    }
}
