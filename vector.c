#include "vector.h"
#include <stdlib.h>


//Initializes v by allocating the memory needed for the field
int LAL_vector_init(Vector* v, VecType v_type, size_t v_size)
{
	//Guard Clause
	if (v_type == UNINIT || v_size == 0;)
		return -1;

	//Initialization
	v->type = v_type;
	v->size = v_size;

	switch (v_type) {
		case INT:
			v->field.ints = (int*) calloc(v_size, sizeof(int));
			break;

		case FLOAT:
			v->field.floats = (float*) calloc(v_size, sizeof(float));
			break;

		case DOUBLE:
			v->field.doubles = (double*) calloc(v_size, sizeof(double));
			break;
	}

	return 0;
}

//Nulls the vector, deallocating the memory in its field and prepares it to be deleted/reinitialized.
void LAL_vector_null(Vector* v)
{
	switch (v->type) {
		case INT:
			free(v->field.ints);
			v->field.ints = NULL;
			break;

		case FLOAT:
			free(v->field.floats);
			v->field.floats = NULL;
			break;

		case DOUBLE:
			free(v->field.doubles);
			v->field.doubles = NULL;
			break;
		}
}


int LAL_vector_add(Vector* v1, Vector* v2, Vector* res){}

int LAL_vector_subtract(Vector* v1, Vector* v2, Vector* res){}


int LAL_vector_scalei(Vector* v, int scalar){}

int LAL_vector_scalef(Vector* v, float scalar){}

int LAL_vector_scaled(Vector* v, double scalar){}


int LAL_vector_dot(Vector* v1, Vector* v2, Vector* res){}

int LAL_vector_cross(Vector* v1, Vector* v2, Vector* res){}

int LAL_vector_magi(Vector* v, int* res){}

int LAL_vector_magf(Vector* v, float* res){}

int LAL_vector_magd(Vector* v, double* res){}


int LAL_vector_proj(Vector* v1, Vector* v2, Vector* res){}