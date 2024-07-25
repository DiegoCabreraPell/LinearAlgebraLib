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


int LAL_vector_add(Vector* v1, Vector* v2, Vector* res)
{
	size_t smallest = min(v1->size, v2->size);

	if (v1->type == UNINIT || v2->type == UNINIT)
		return -1;

	if (res->type == UNINIT)
	{
		VecType most_precise = max(v1->type, v2->type);
		LAL_vector_init(res, most_precise, smallest);
	}

	int int1, int2;
	int flt1, flt2;
	int dbl1, dbl2;
	for (int i = 0; i < smallest; i++)
	{
		if (res->type == INT)
		{
			if (v1->type == FLOAT)
			{
				int1 = (int) v1->field.floats[i];
			}
			else if (v1->type == DOUBLE)
			{
				int1 = (int) v1->field.doubles[i];
			}
			else
				int1 = v1->field.ints[i];

			if (v2->type == FLOAT)
			{
				int2 = (int) v2->field.floats[i];
			}
			else if (v2->type == DOUBLE)
			{
				int2 = (int) v2->field.doubles[i];
			}
			else
				int2 = v2->field.ints[i];

			res->field.ints[i] = int1 + int2;
		}
		else if (res->type == FLOAT)
		{
			if (v1->type == INT)
			{
				flt1 = (float)v1->field.ints[i];
			}
			else if (v1->type == DOUBLE)
			{
				flt1 = (float) v1->field.doubles[i];
			}
			else
				flt1 = v1->field.floats[i];

			if (v2->type == INT)
			{
				flt2 = (float)v2->field.ints[i];
			}
			else if (v2->type == DOUBLE)
			{
				flt2 = (float)v2->field.doubles[i];
			}
			else
				flt2 = v2->field.floats[i];

			res->field.ints[i] = int1 + int2;
		}
		else if (res->type == DOUBLE)
		{
			if (v1->type == INT)
			{
				dbl1 = (double)v1->field.ints[i];
			}
			else if (v1->type == FLOAT)
			{
				dbl1 = (double)v1->field.floats[i];
			}
			else
				dbl1 = v1->field.doubles[i];

			if (v2->type == INT)
			{
				dbl2 = (double)v2->field.ints[i];
			}
			else if (v2->type == FLOAT)
			{
				dbl2 = (double)v2->field.floats[i];
			}
			else
				dbl2 = v2->field.doubles[i];

			res->field.ints[i] = int1 + int2;
		}
	}
}

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