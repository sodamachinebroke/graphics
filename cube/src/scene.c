#include "scene.h"

#include <obj/load.h>
#include <obj/draw.h>

void init_scene(Scene *scene)
{

    // Load in the cube model
    load_model(&(scene->objects[0].model), "assets/models/garagetriangle.obj");
    scene->objects[0].texture_id = load_texture("assets/textures/gay.jpg");
    scene->objects[0].material.ambient = (Color){0.1, 0.1, 0.1};
    scene->objects[0].material.diffuse = (Color){0.6, 0.6, 0.6};
    scene->objects[0].material.specular = (Color){0.2, 0.2, 0.2};
    scene->objects[0].material.shininess = 0.0;

    // Load in the buggy model
    load_model(&(scene->objects[1].model), "assets/models/buggy.obj");
    scene->objects[1].texture_id = load_texture("assets/textures/white.png");
    scene->objects[1].material.ambient = (Color){0.1, 0.1, 0.1};
    scene->objects[1].material.diffuse = (Color){0.8, 0.8, 0.8};
    scene->objects[1].material.specular = (Color){0.2, 0.2, 0.2};
    scene->objects[1].material.shininess = 0.2;

    // Load in the V12 engine's model
    load_model(&(scene->objects[2].model), "assets/models/v12stripped.obj");
    scene->objects[2].texture_id = load_texture("assets/textures/white.png");
    scene->objects[2].material.ambient = (Color){0.2, 0.2, 0.2};
    scene->objects[2].material.diffuse = (Color){0.8, 0.8, 0.8};
    scene->objects[2].material.specular = (Color){0.0, 0.0, 0.0};
    scene->objects[2].material.shininess = 0.0;

    // Load in the cube model for science
    load_model(&(scene->objects[3].model), "assets/models/electric_motor.obj");
    scene->objects[3].texture_id = load_texture("assets/textures/eMotor.jpg");
    scene->objects[3].material.ambient = (Color){0.2, 0.2, 0.2};
    scene->objects[3].material.diffuse = (Color){0.8, 0.8, 0.8};
    scene->objects[3].material.specular = (Color){0.2, 0.2, 0.2};
    scene->objects[3].material.shininess = 0.3;
}

void set_lighting(Light *light)
{
    light->lsources[0].ambient[0] = 1.0f;
    light->lsources[0].ambient[1] = 1.0f;
    light->lsources[0].ambient[2] = 1.0f;
    light->lsources[0].ambient[3] = 1.0f;

    light->lsources[0].diffuse[0] = 1.0f;
    light->lsources[0].diffuse[1] = 1.0f;
    light->lsources[0].diffuse[2] = 1.0f;
    light->lsources[0].diffuse[3] = 1.0f;

    light->lsources[0].specular[0] = 1.0f;
    light->lsources[0].specular[1] = 1.0f;
    light->lsources[0].specular[2] = 1.0f;
    light->lsources[0].specular[3] = 1.0f;

    light->lsources[0].position[0] = 3.0f;
    light->lsources[0].position[1] = -4.0f;
    light->lsources[0].position[2] = 2.0f;
    light->lsources[0].position[3] = 1.0f;

    light->lsources[0].direction[0] = 0.0f;
    light->lsources[0].direction[1] = 0.0f;
    light->lsources[0].direction[2] = -10.0f;
    light->lsources[0].direction[3] = 0.0f;

    light->lsources[0].angle = 90.0f;
    light->lsources[0].exponent = 0.5f;

    light->lsources[1].ambient[0] = 1.0f;
    light->lsources[1].ambient[1] = 1.0f;
    light->lsources[1].ambient[2] = 1.0f;
    light->lsources[1].ambient[3] = 1.0f;

    light->lsources[1].diffuse[0] = 1.0f;
    light->lsources[1].diffuse[1] = 1.0f;
    light->lsources[1].diffuse[2] = 1.0f;
    light->lsources[1].diffuse[3] = 1.0f;

    light->lsources[1].specular[0] = 1.0f;
    light->lsources[1].specular[1] = 1.0f;
    light->lsources[1].specular[2] = 1.0f;
    light->lsources[1].specular[3] = 1.0f;

    light->lsources[1].position[0] = -3.2f;
    light->lsources[1].position[1] = -4.0f;
    light->lsources[1].position[2] = 2.0f;
    light->lsources[1].position[3] = 1.0f;

    light->lsources[1].direction[0] = 0.0f;
    light->lsources[1].direction[1] = 0.0f;
    light->lsources[1].direction[2] = -10.0f;
    light->lsources[1].direction[3] = 0.0f;

    light->lsources[1].angle = 90.0f;
    light->lsources[1].exponent = 0.5f;

    glLightfv(GL_LIGHT0, GL_AMBIENT, light->lsources[0].ambient);
    glLightfv(GL_LIGHT0, GL_DIFFUSE, light->lsources[0].diffuse);
    glLightfv(GL_LIGHT0, GL_SPECULAR, light->lsources[0].specular);
    glLightfv(GL_LIGHT0, GL_POSITION, light->lsources[0].position);
    glLightfv(GL_LIGHT0, GL_SPOT_DIRECTION, light->lsources[0].direction);
    glLightf(GL_LIGHT0, GL_SPOT_CUTOFF, light->lsources[0].angle);
    glLightf(GL_LIGHT0, GL_SPOT_EXPONENT, light->lsources[0].exponent);

    glLightfv(GL_LIGHT1, GL_AMBIENT, light->lsources[1].ambient);
    glLightfv(GL_LIGHT1, GL_DIFFUSE, light->lsources[1].diffuse);
    glLightfv(GL_LIGHT1, GL_SPECULAR, light->lsources[1].specular);
    glLightfv(GL_LIGHT1, GL_POSITION, light->lsources[1].position);
    glLightfv(GL_LIGHT1, GL_SPOT_DIRECTION, light->lsources[1].direction);
    glLightf(GL_LIGHT1, GL_SPOT_CUTOFF, light->lsources[1].angle);
    glLightf(GL_LIGHT1, GL_SPOT_EXPONENT, light->lsources[1].exponent);
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

void render_scene(const Scene *scene, const Light *light)
{

    set_material(&(scene->objects[0].material));
    glEnable(GL_LIGHT0);
    glEnable(GL_LIGHT1);
    set_lighting((Light *)light);
    draw_origin();
    /*// Spotlight0 origin
    {
        glPushMatrix();
        glTranslatef(light->lsources[0].position[0],
                     light->lsources[0].position[1],
                     light->lsources[0].position[2]);
        glScalef(0.2f, 0.2f, 0.2f);
        glBindTexture(GL_TEXTURE_2D, scene->objects[3].texture_id);
        draw_model(&(scene->objects[3].model));
        glPopMatrix();
    }*/

    // Garage
    {
        glPushMatrix();
        glRotatef(90, 1, 0, 0);
        glTranslatef(0.0f, 0.0f, 0.0f);
        glScalef(0.5f, 0.5f, 0.5f);
        glBindTexture(GL_TEXTURE_2D, scene->objects[0].texture_id);
        draw_model(&(scene->objects[0].model));
        glPopMatrix();
    }

    // Buggy
    {
        glPushMatrix();
        glRotatef(90, 1, 0, 0);
        glTranslatef(1.0f, 0.25f, 4.0f);
        glScalef(0.7f, 0.7f, 0.7f);
        glBindTexture(GL_TEXTURE_2D, scene->objects[1].texture_id);
        draw_model(&(scene->objects[1].model));
        glPopMatrix();
    }

    // V12
    {
        glPushMatrix();
        glRotatef(90, 1, 0, 0);
        glTranslatef(-3.0f, -0.2f, 5.0f);
        glScalef(0.02f, 0.02f, 0.02f);
        glBindTexture(GL_TEXTURE_2D, scene->objects[2].texture_id);
        draw_model(&(scene->objects[2].model));
        glPopMatrix();
    }

    // Electric motor
    {
        glPushMatrix();
        glRotatef(90, 1, 0, 0);
        glTranslatef(-3.0f, -0.2f, 3.0f);
        glScalef(0.01f, 0.01f, 0.01f);
        glBindTexture(GL_TEXTURE_2D, scene->objects[3].texture_id);
        draw_model(&(scene->objects[3].model));
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