# OOP Example

In this example, we define a `Shape` struct that encapsulates the `x` and `y` coordinates of a shape and a function pointer that prints information about the shape. We then define a `Rectangle` and `Circle` struct that inherit from the `Shape` struct by including it as a member in the child struct.

We define three functions `shape_print()`, `rectangle_print()`, and `circle_print()` that implement polymorphism by printing different information about the shape depending on its type. We also define a `shape_move()` function that implements encapsulation by allowing users to move a shape without exposing its implementation details.
