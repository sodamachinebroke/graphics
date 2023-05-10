#include "scene.h"

#include <obj/load.h>
#include <obj/draw.h>

void init_scene(Scene *scene)
{

    // Load in the cube model
    load_model(&(scene->objects[0].model), "assets/models/cube.obj");
    scene->objects[0].texture_id = load_texture("assets/textures/grille.jpg");
    scene->objects[0].material.ambient = (Color){1.0, 1.0, 1.0};
    scene->objects[0].material.diffuse = (Color){1.0, 1.0, 1.0};
    scene->objects[0].material.specular = (Color){0.0, 0.0, 0.0};
    scene->objects[0].material.shininess = 0.0;

    // Load in the minitruck model
    load_model(&(scene->objects[1].model), "assets/models/minitruck.obj");
    scene->objects[0].texture_id = load_texture("assets/textures/cube.png");
    scene->objects[0].material.ambient = (Color){0.2, 0.2, 0.2};
    scene->objects[0].material.diffuse = (Color){0.8, 0.8, 0.8};
    scene->objects[0].material.specular = (Color){0.0, 0.0, 0.0};
    scene->objects[0].material.shininess = 0.0;
}

void set_lighting()
{
    float ambient_light[] = {1.0f, 1.0f, 1.0f, 1.0f};
    float diffuse_light[] = {1.0f, 1.0f, 1.0, 1.0f};
    float specular_light[] = {1.0f, 1.0f, 1.0f, 1.0f};
    float position[] = {0.0f, -50.0f, 10.0f, 1.0f};

    glLightfv(GL_LIGHT0, GL_AMBIENT, ambient_light);
    glLightfv(GL_LIGHT0, GL_DIFFUSE, diffuse_light);
    glLightfv(GL_LIGHT0, GL_SPECULAR, specular_light);
    glLightfv(GL_LIGHT0, GL_POSITION, position);
}

void set_material(const Material *material)
{
    float ambient_material_color[] = {
        material->ambient.red,
        material->ambient.green,
        material->ambient.blue};

    float diffuse_material_color[] = {
        material->diffuse.red,
        material->diffuse.green,
        material->diffuse.blue};

    float specular_material_color[] = {
        material->specular.red,
        material->specular.green,
        material->specular.blue};

    glMaterialfv(GL_FRONT_AND_BACK, GL_AMBIENT, ambient_material_color);
    glMaterialfv(GL_FRONT_AND_BACK, GL_DIFFUSE, diffuse_material_color);
    glMaterialfv(GL_FRONT_AND_BACK, GL_SPECULAR, specular_material_color);

    glMaterialfv(GL_FRONT_AND_BACK, GL_SHININESS, &(material->shininess));
}

void update_scene(Scene *scene)
{
}

void render_scene(const Scene *scene)
{
    set_material(&(scene->objects[0].material));
    set_lighting();
    draw_origin();

    // Cube
    {
        glPushMatrix();
        glTranslatef(0.0f, 0.0f, 0.0f);
        glScalef(1, 1, 1);
        glBindTexture(GL_TEXTURE_2D, scene->objects[0].texture_id);
        draw_model(&(scene->objects[0].model));
        glPopMatrix();
    }

    // Truck
    {
        glPushMatrix();
        glRotatef(90,1,0,0);
        glScalef(0.2f,0.2f,0.2f);
        glBindTexture(GL_TEXTURE_2D, scene->objects[1].texture_id);
        draw_model(&(scene->objects[1].model));
        glPopMatrix();
    }
}

void draw_origin()
{
    glBegin(GL_LINES);

    glColor3f(1.0f, 1.0f, 1.0f);
    glVertex3f(0, 0, 0);
    glVertex3f(1, 0, 0);

    glColor3f(1.0f, 1.0f, 1.0f);
    glVertex3f(0, 0, 0);
    glVertex3f(0, 1, 0);

    glColor3f(1.0f, 1.0f, 1.0f);
    glVertex3f(0, 0, 0);
    glVertex3f(0, 0, 1);

    glEnd();
}