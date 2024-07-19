#ifndef LAL_VECTOR
#define LAL_VECTOR

enum VecType {
	UNINIT,
	INT,
	FLOAT,
	DOUBLE
};

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

int LAL_vector_null(Vector* v);


int LAL_vector_add(Vector* v1, Vector* v2, Vector* res);

int LAL_vector_subtract(Vector* v1, Vector* v2, Vector* res);


int LAL_vector_scalei(Vector* v, int scalar);

int LAL_vector_scalef(Vector* v, float scalar);

int LAL_vector_scaled(Vector* v, double scalar);


int LAL_vector_dot(Vector* v1, Vector* v2, Vector* res);

int LAL_vector_cross(Vector* v1, Vector* v2, Vector* res);

int LAL_vector_magi(Vector* v, int* res);

int LAL_vector_magf(Vector* v, float* res);

int LAL_vector_magd(Vector* v, double* res);


int LAL_vector_proj(Vector* v1, Vector* v2, Vector* res);
#endif