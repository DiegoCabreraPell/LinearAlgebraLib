# LinearAlgebraLib

A basic linear algebra library.

## Errors

Functions return -1 if an error occured, 0 if no errors occured.
An error will occur if any of the input vectors are uniitialized. However, the result vector may be uninitialized.

Unitilized result vectors will initialized to match the type of vector with the greatest precisions (ie: float vector and int vector will initialized the result vector to float).

Errors may also occur for other reasons, such as a vector being of an improper size in the case of cross products and projections.