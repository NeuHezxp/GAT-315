#include "spring.h"
#include "body.h"
#include "World.h"

#include <stdlib.h>
#include <assert.h>
#include <string.h>

ncSpring_t* ncBodies = NULL;
int ncSpring_tCount = 0;
Vector2 ncGravity;

ncSpring_t* CreateSpring(struct ncBody* body1, struct ncBody* body2, float restLength, float k)
{
	// add element to linklist
	ncSpring_t* spring = (ncSpring_t*)malloc(sizeof(ncSpring_t));
	assert(spring);

	memset(spring, 0, sizeof(ncSpring_t));
	spring->body1 = body1;
	spring->body2 = body2;
	spring->restLength = restLength;
	spring->k = k;


	return spring;
}

void AddSpring(ncSpring_t* spring)
{
	assert(spring);

	spring->prev = NULL;
	spring->next = ncSprings;

	// If the list isn't empty, change previous pointer to current head
	if (ncSprings != NULL) {
		ncBodies->prev = spring;
	}

	// Update head to the new body
	ncSprings = spring;

}

void DestroySpring(ncSpring_t* spring)
{
	assert(spring); // check if pointer is not NULL

	// if next pointer exists 
	if (spring->prev != NULL) {
		spring->prev->next = spring->next;//changes to next pointer of previous body
	}

	// if previous pointer exists 
	if (spring->next != NULL) {
		spring->next->prev = spring->prev;//changes to previous pointer of next body
	}

	// If body is the head, update
	if (spring == ncSprings)
	{
		ncSprings = spring->next;
	}

	ncSpring_tCount--;

	// free memory
	free(spring);
}