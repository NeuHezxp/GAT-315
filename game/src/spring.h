#pragma once
typedef struct ncSpring
{
	struct ncBody* body1;
	struct ncBody* body2;
	float restLength;
	float k; //stiffness

	struct nc_Spring* next;
	struct nc_Spring* prev;
} ncSpring_t;

extern ncSpring_t* ncSprings;
ncSpring_t* CreateSpring(struct ncBody* body1,struct ncBody* body2, float restLength, float k);
void AddSpring(ncSpring_t* body);
void DestroySpring(ncSpring_t* body);
