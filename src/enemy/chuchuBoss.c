#define NENT_DEPRECATED
/**
 * @file chuchuBoss.c
 * @ingroup Enemies
 *
 * @brief Chuchu Boss enemy
 */
#include "global.h"
#include "enemy.h"
#include "object.h"
#include "functions.h"

typedef struct {
    u8 unk_00[1];
    u8 unk_01;
    u8 unk_02[1];
    u8 unk_03;
    u8 unk_04;
    s8 unk_05;
    u8 unk_06;
    u8 unk_07[7];
    u16 unk_0e;
} Helper;

static_assert(sizeof(Helper) == 0x10);

typedef struct _ChuchuBossEntity {
    Entity base;
    struct _ChuchuBossEntity* unk_68;
    u8 unk_6c[1];
    struct {
        u8 unk0 : 1;
        u8 unk1 : 1;
    } PACKED unk_6d;
    u8 unk_6e[2];
    u8 unk_70[0x4];
    union SplitWord unk_74;
    union SplitWord unk_78;
    u8 unk_7c[1];
    u8 unk_7d;
    u16 unk_7e;
    u8 unk_80[4];
    Helper* unk_84;
} ChuchuBossEntity;

extern void (*const ChuchuBoss_Functions[])(ChuchuBossEntity*);
extern void (*const gUnk_080CC1B0[])(ChuchuBossEntity*);
typedef struct {
    u8 unk_00, unk_01, unk_2, unk_03;
} struct_080CC1B8;
extern const struct_080CC1B8 gUnk_080CC1B8[];
extern void (*const gUnk_080CC1C8[])(ChuchuBossEntity*);
extern void (*const gUnk_080CC1DC[])(ChuchuBossEntity*);
extern void (*const gUnk_080CC20C[])(ChuchuBossEntity*);
extern const u8 gUnk_080CC234[];
extern const u8 gUnk_080CC24F[];
extern void (*const gUnk_080CC258[])(ChuchuBossEntity*);
extern void (*const gUnk_080CC264[])(ChuchuBossEntity*);
extern void (*const gUnk_080CC26C[])(ChuchuBossEntity*);
extern const u8 gUnk_080CC278[];
extern const u16 gUnk_080CC27C[];
extern const u16 gUnk_080CC29C[];
extern const u16 gUnk_080CC2BC[];
extern const s8 gUnk_080CC2DC[];
extern Hitbox gUnk_080FD238;

void ChuchuBoss(Entity* this);
void ChuchuBoss_OnKnockback(ChuchuBossEntity* this);
void ChuchuBoss_OnTick(ChuchuBossEntity*);
void ChuchuBoss_OnDeath(ChuchuBossEntity*);
void sub_08025DD8(ChuchuBossEntity*);
void sub_08026060(ChuchuBossEntity*);
void sub_08026090(ChuchuBossEntity*);
void sub_08026110(ChuchuBossEntity*);
void sub_0802626C(ChuchuBossEntity*);
void sub_080262A8(ChuchuBossEntity*);
void sub_08026328(ChuchuBossEntity*);
void sub_08026358(ChuchuBossEntity*);
void sub_080263B4(ChuchuBossEntity*);
void sub_08026414(ChuchuBossEntity*);
void sub_0802647C(ChuchuBossEntity*);
void sub_080264AC(ChuchuBossEntity*);
void sub_080264D4(ChuchuBossEntity*);
void sub_0802650C(ChuchuBossEntity*);
void sub_0802653C(ChuchuBossEntity*);
void sub_08026580(ChuchuBossEntity*);
void sub_08026634(ChuchuBossEntity*);
void sub_08026750(ChuchuBossEntity*);
void sub_08026774(ChuchuBossEntity*);
void sub_080267D0(ChuchuBossEntity*);
void sub_08026808(ChuchuBossEntity*);
void sub_0802686C(ChuchuBossEntity*);
void sub_080268C8(ChuchuBossEntity*);
void sub_080268EC(ChuchuBossEntity*);
void sub_08026914(ChuchuBossEntity*);
void sub_0802694C(ChuchuBossEntity*);
void sub_08026968(ChuchuBossEntity*);
void sub_080269CC(ChuchuBossEntity*);
void sub_08026BE8(ChuchuBossEntity*);
void sub_08026C40(ChuchuBossEntity*);
void sub_08026E1C(ChuchuBossEntity*);
void sub_08026F1C(ChuchuBossEntity*);
void sub_08026FA4(ChuchuBossEntity*);
void sub_08027064(ChuchuBossEntity*);
void sub_0802720C(ChuchuBossEntity*);
void sub_080272D4(ChuchuBossEntity*);

// as-yet unknown types (could return things)
void sub_08027548();
void sub_0802757C();
void sub_080276F4();
void sub_080277B8();
void sub_080277F8();
void sub_08027870();
void sub_08027984();
void sub_080279AC();
void sub_080279E8();
void sub_08027A60();
void sub_08027AA4();
void sub_08027B98();
void sub_08027BBC();
void sub_08027C54();
void sub_08027C7C(ChuchuBossEntity*, u32);
void sub_08027C9C();
void sub_08027D20();

// clang-format off
void (*const ChuchuBoss_Functions[])(ChuchuBossEntity*) = {
    ChuchuBoss_OnTick,
    ChuchuBoss_OnTick,
    ChuchuBoss_OnKnockback,
    ChuchuBoss_OnDeath,
    (void (*)(ChuchuBossEntity*)) GenericConfused,
};

void (*const gUnk_080CC1B0[])(ChuchuBossEntity*) = {
    sub_08025DD8,
    sub_08026060,
};

const struct_080CC1B8 gUnk_080CC1B8[] = {
    {0, 4, 0, 0},
    {0, 4, 0, 0},
    {1, 4, 0, 0},
    {2, 4, 0, 0},
};

void (*const gUnk_080CC1C8[])(ChuchuBossEntity*) = {
    sub_08026110,
    sub_080272D4,
    sub_0802720C,
    sub_0802720C,
    sub_08026090,
};

void (*const gUnk_080CC1DC[])(ChuchuBossEntity*) = {
    sub_0802626C,
    sub_08026580,
    sub_08026634,
    sub_08026750,
    sub_0802686C,
    sub_080268C8,
    sub_0802694C,
    sub_08026C40,
    sub_08026E1C,
    sub_08026FA4,
    sub_08027064,
    sub_08026F1C,
};

void (*const gUnk_080CC20C[])(ChuchuBossEntity*) = {
    sub_080262A8,
    sub_08026328,
    sub_08026358,
    sub_080263B4,
    sub_08026414,
    sub_0802647C,
    sub_080264AC,
    sub_080264D4,
    sub_0802650C,
    sub_0802653C,
};

const u8 gUnk_080CC234[] = {
    0x3C, 0x1E, 0x1E, 0x1E,
    0x1E, 0x0F, 0x0F, 0x0F,
    0x04, 0x04, 0x04, 0x04,
    0x04, 0x04, 0x0A, 0x0A,
    0x0A, 0x0F, 0x0F, 0x0F,
    0x1E, 0x1E, 0x2D, 0x0A,
    0x5A, 0x1E, 0xFF,
};

const u8 gUnk_080CC24F[] = {
    2, 2, 4, 4,
    4, 6, 6, 8,
};

void (*const gUnk_080CC258[])(ChuchuBossEntity*) = {
    sub_08026774,
    sub_080267D0,
    sub_08026808,
};

void (*const gUnk_080CC264[])(ChuchuBossEntity*) = {
    sub_080268EC,
    sub_08026914,
};

void (*const gUnk_080CC26C[])(ChuchuBossEntity*) = {
    sub_08026968,
    sub_080269CC,
    sub_08026BE8,
};

const u8 gUnk_080CC278[] = {
    150, 180, 210, 250,
};

const u16 gUnk_080CC27C[] = {
     0x80,  0x8, 0x100,  0x6,
     0x80, 0x18, 0x100,  0x8,
    0x180,  0x6, 0x100, 0x10,
      0x0,  0x0,  0xA0, 0x18,
};

const u16 gUnk_080CC29C[] = {
     0x80, 0x8, 0x100,  0x4,
     0x80, 0xC,  0x80,  0x6,
    0x200, 0x6, 0x100,  0xC,
      0x0, 0x0,  0xA0, 0x14,
};

const u16 gUnk_080CC2BC[] = {
     0x80, 0x8, 0x100,  0x0,
     0x60, 0x2,  0x80,  0x2,
    0x200, 0x6, 0x100,  0x8,
      0x0, 0x0,  0xA0, 0x10,
};


const s8 gUnk_080CC2DC[] = {
    -7, -9, -7,
};
// clang-format on

void ChuchuBoss(Entity* this) {
    ChuchuBoss_Functions[GetNextFunction(this)]((ChuchuBossEntity*)this);
}

void ChuchuBoss_OnKnockback(ChuchuBossEntity* this) {
    GenericKnockback(super);
    if (super->type == 0) {
        sub_08027870(super);
    }
}

NONMATCH("asm/non_matching/chuchuBoss/ChuchuBoss_OnDeath.inc", void ChuchuBoss_OnDeath(ChuchuBossEntity* this)) {
    sub_08078B48();
    if (super->type == 0) {
        if (super->subAction != 0xC) {
            super->subAction = 0xC;
            this->unk_84->unk_03 = 0;
            InitAnimationForceUpdate(super->child, 9);
        } else {
            switch (this->unk_84->unk_03) {
                case 0:
                    sub_08027C7C(this, 0x3F);
                    this->unk_84->unk_03 = 1;
                    this->unk_7d = 0x78;
                    break;
                case 1:
                    if (this->unk_7d-- == 0) {
                        ((GenericEntity*)super->child)->field_0x6c.HALF.HI |= 2;
                        this->unk_68->unk_6d.unk1 = 1;
                        ((GenericEntity*)super->parent)->field_0x6c.HALF.HI |= 2;
                        super->child->health = 0;
                        this->unk_68->base.health = 0;
                        super->parent->health = 0;
                        gPauseMenuOptions.disabled = 0;
                        SoundReq(SFX_BOSS_DIE);
                        GenericDeath(super);
                    } else {
                        u32 tmp = 0x3F;
                        if (this->unk_7d <= 0x50) {
                            tmp = 0xF;
                            if (this->unk_7d > 0x1E) {
                                tmp = 0x1F;
                            }
                        }
                        sub_08027C7C(this, tmp);
                    }
                    break;
                default:
                    break;
            }
        }
        sub_08027870(super);
    } else {
        if (this->unk_6d.unk1) {
            this->unk_6d.unk1 = 1;
            DeleteThisEntity();
        }
    }
}
END_NONMATCH

void ChuchuBoss_OnTick(ChuchuBossEntity* this) {
    gUnk_080CC1B0[super->action](this);
}

NONMATCH("asm/non_matching/chuchuBoss/sub_08025DD8.inc", void sub_08025DD8(ChuchuBossEntity* this)) {
    super->action = 1;
    if (super->type == 8) {
        super->type = 4;
        super->hitbox = super->child->hitbox;
    } else {
        super->spritePriority.b0 = gUnk_080CC1B8[super->type & 3].unk_01;
        this->unk_74.HALF.HI = 0xa0;
        this->unk_78.HALF.HI = 0xa0;
        this->unk_7e = 0;
        super->spriteRendering.b0 = 3;
        if ((super->type & 3) == 1) {
            InitAnimationForceUpdate(super, 0);
        } else {
            InitializeAnimation(super, gUnk_080CC1B8[super->type & 3].unk_00);
        }
        switch (super->type & 3) {
            Hitbox* hitbox;
            case 0:
                super->type2 = super->type & 3;
                this->unk_84 = zMalloc(sizeof(Helper));
                if (!this->unk_84 || !AllocMutableHitbox(super)) {
                    GenericDeath(super);
                    return;
                }
                super->myHeap = this->unk_84;
                super->hitbox->offset_x = gUnk_080FD238.offset_x;
                super->hitbox->offset_y = gUnk_080FD238.offset_y;
                super->hitbox->unk2[0] = gUnk_080FD238.unk2[0];
                super->hitbox->unk2[1] = gUnk_080FD238.unk2[1];
                super->hitbox->unk2[2] = gUnk_080FD238.unk2[2];
                super->hitbox->unk2[3] = gUnk_080FD238.unk2[3];
                super->hitbox->width = gUnk_080FD238.width;
                super->hitbox->height = gUnk_080FD238.height;
                super->subAction = 0;
                this->unk_6d.unk0 = 1;
                this->unk_84->unk_06 = 0;
                this->unk_84->unk_05 = 0;
                this->unk_84->unk_01 = 0xF;
                this->unk_84->unk_03 = 0;
                this->unk_84->unk_04 = 0;
                this->unk_84->unk_0e = super->x.HALF.HI;
                this->unk_68 = (ChuchuBossEntity*)CreateEnemy(CHUCHU_BOSS, super->type | 3);
                if (this->unk_68) {
                    this->unk_68->base.collisionLayer = super->collisionLayer;
                    this->unk_68->base.x.HALF.HI = super->x.HALF.HI;
                    this->unk_68->base.y.HALF.HI = super->y.HALF.HI - 0xE;
                    this->unk_68->base.timer = 0xE;
                    this->unk_68->base.parent = super;
                    this->unk_68->unk_68 = this;
                }
                super->parent = CreateEnemy(CHUCHU_BOSS, super->type | 2);
                if (super->parent) {
                    super->parent->collisionLayer = super->collisionLayer;
                    super->parent->x.HALF.HI = super->x.HALF.HI;
                    super->parent->y.HALF.HI = this->unk_68->base.y.HALF.HI - 0x12;
                    super->parent->timer = 0x12;
                    super->parent->parent = (Entity*)this->unk_68;
                    this->unk_68->base.child = super->parent;
                    ((ChuchuBossEntity*)super->parent)->unk_68 = this;
                }
                super->child = CreateEnemy(CHUCHU_BOSS, super->type | 1);
                if (super->child) {
                    super->child->collisionLayer = super->collisionLayer;
                    super->child->x.HALF.HI = super->x.HALF.HI;
                    super->child->y.HALF.HI = super->parent->y.HALF.HI - 0xe;
                    super->child->timer = 0xe;
                    super->child->parent = super->parent;
                    super->child->child = super;
                    super->parent->child = super->child;
                    ((ChuchuBossEntity*)super->child)->unk_68 = this;
                }
                {
                    Entity* tmp;
                    tmp = CreateEnemy(CHUCHU_BOSS, 8);
                    if (tmp) {
                        tmp->child = super;
                    }
                    tmp = CreateObjectWithParent(super, OBJECT_49, 1, 0);
                    if (tmp) {
                        tmp->child = super->child;
                    }
                    if (super->type != 0) {
                        tmp = CreateObjectWithParent(super, OBJECT_49, 3, 0);
                        if (tmp) {
                            tmp->child = super->child;
                        }
                    }
                }
                break;
            case 1 ... 3:
                hitbox = super->hitbox;
                if (!AllocMutableHitbox(super)) {
                    this->unk_68->base.health = 0;
                    return;
                }
                super->hitbox->offset_x = hitbox->offset_x;
                super->hitbox->offset_y = hitbox->offset_y;
                super->hitbox->unk2[0] = hitbox->unk2[0];
                super->hitbox->unk2[1] = hitbox->unk2[1];
                super->hitbox->unk2[2] = hitbox->unk2[2];
                super->hitbox->unk2[3] = hitbox->unk2[3];
                super->hitbox->width = hitbox->width;
                super->hitbox->height = hitbox->height;
                break;
        }
        super->type &= 3;
        sub_08026060(this);
    }
}
END_NONMATCH

void sub_08026060(ChuchuBossEntity* this) {
    gUnk_080CC1C8[super->type](this);
    SetAffineInfo(super, this->unk_74.HALF_U.HI, this->unk_78.HALF_U.HI, this->unk_7e);
}

void sub_08026090(ChuchuBossEntity* this) {
    if (super->subAction == 0) {
        if (super->child->health == 0) {
            super->flags &= ~0x80;
            super->subAction = 1;
            super->timer = 250;
            gRoomControls.camera_target = super;
        }
        super->flags = super->child->flags;
        super->hitbox = super->child->hitbox;
        if (super->child->hitType == 0x7E) {
            super->hitType = 0x7E;
        } else {
            super->hitType = 0x7C;
        }
        CopyPosition(super->child, super);
    } else {
        sub_08078B48();
        if (super->timer-- == 0) {
            gRoomControls.camera_target = &gPlayerEntity;
            DeleteThisEntity();
        }
    }
}
