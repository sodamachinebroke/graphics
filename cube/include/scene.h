#ifndef SCENE_H
#define SCENE_H

#include "camera.h"
#include "texture.h"

#include <obj/model.h>

typedef struct boundingSphere
{
    vec3 center;
    float radius;
}boundingSphere;

typedef struct Object
{
    Model model;
    Material material;
    GLuint texture_id;
    vec3 position;
    vec3 scale;

} Object;

typedef struct Scene
{
    Object objects[5];
} Scene;

typedef struct LSource
{
    float ambient[4];
    float diffuse[4];
    float specular[4];
    float position[4];
    float direction[4];
    float angle;
    float exponent;
} LSource;

typedef struct Light
{
    LSource lsources[2];
} Light;

/**
 * Initialize the scene by loading models.
 */
void init_scene(Scene *scene);

/**
 * Set the lighting of the scene.
 */
void set_lighting();

/**
 * Set the current material.
 */
void set_material(const Material *material);

/**
 * Update the scene.
 */
void update_scene(Scene *scene);

/**
 * Render the scene objects.
 */
void render_scene(const Scene *scene, const Light *light);

/**
 * Draw the origin of the world coordinate system.
 */
void draw_origin();


//Calculate distance between two vectors
float vec3_distance(vec3 v1, vec3 v2);

//Calculates a bounding sphere for an object
boundingSphere calcBoundSphere(const Object *object);

#endif /* SCENE_H */
