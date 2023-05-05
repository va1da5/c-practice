#include <stdio.h>

/*
In this example, we define a Shape struct that encapsulates the x and y coordinates
of a shape and a function pointer that prints information about the shape.
We then define a Rectangle and Circle struct that inherit from the Shape struct
by including it as a member in the child struct.

We define three functions shape_print(), rectangle_print(), and circle_print()
that implement polymorphism by printing different information about the shape
depending on its type. We also define a shape_move() function that implements
encapsulation by allowing users to move a shape without exposing its implementation details.

In main(), we create a Rectangle and Circle object and call their respective `
*/

typedef struct
{
    int x;
    int y;
    void (*print)(const void *self);
} Shape;

typedef struct
{
    Shape shape;
    int width;
    int height;
} Rectangle;

typedef struct
{
    Shape shape;
    int radius;
} Circle;

void shape_print(const void *self)
{
    const Shape *s = self;
    printf("Shape at (%d, %d)\n", s->x, s->y);
}

void rectangle_print(const void *self)
{
    const Rectangle *r = self;
    printf("Rectangle at (%d, %d) with width %d and height %d\n",
           r->shape.x, r->shape.y, r->width, r->height);
}

void circle_print(const void *self)
{
    const Circle *c = self;
    printf("Circle at (%d, %d) with radius %d\n",
           c->shape.x, c->shape.y, c->radius);
}

void shape_move(void *self, int x, int y)
{
    Shape *s = self;
    s->x = x;
    s->y = y;
}

int main()
{

    Shape s = {0, 0, rectangle_print};
    Rectangle r = {{0, 0, rectangle_print}, 10, 20};
    Circle c = {{5, 5, circle_print}, 30};

    s.print(&s);
    r.shape.print(&r);
    c.shape.print(&c);

    shape_move(&r, 100, 100);
    r.shape.print(&r);

    return 0;
}
