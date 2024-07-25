#ifndef LAL_VECTOR
#define LAL_VECTOR

#include <stddef.h>

typedef enum VecType VecType;
enum VecType {
	UNINIT,
	INT,
	FLOAT,
	DOUBLE
};

typedef union VecField VecField;
union VecField {
	int* ints;
	float* floats;
	double* doubles;
};

typedef struct Vector Vector;
struct Vector {
	VecType type;
	size_t size;
	VecField field;
};


int LAL_vector_init(Vector* v, VecType v_type, size_t v_size);

void LAL_vector_null(Vector* v);


int LAL_vector_add(Vector* v1, Vector* v2, Vector* res);

int LAL_vector_subtract(Vector* v1, Vector* v2, Vector* res);


int LAL_vector_scale(Vector* v, double scalar);


int LAL_vector_dot(Vector* v1, Vector* v2, Vector* res);

int LAL_vector_cross(Vector* v1, Vector* v2, Vector* res);

int LAL_vector_magi(Vector* v, int* res);

int LAL_vector_magf(Vector* v, float* res);

int LAL_vector_magd(Vector* v, double* res);


int LAL_vector_proj(Vector* v1, Vector* v2, Vector* res);
#endif