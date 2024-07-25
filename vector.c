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

/*
Allocates an array which is returned
*/
int* LAL_field_to_ints_helper(VecField f, VecType t, size_t size)
{
	int* is = (int*)malloc(size * sizeof(int));

	if (VecType == FLOAT)
	{
		float* flts = f.floats;
		for (int i = 0; i < size; i++)
		{
			is[i] = (int)flts[i];
		}
	}
	else if (VecType == DOUBLE)
	{
		double* dbls = f.doubles;
		for (int i = 0; i < size; i++)
		{
			is[i] = (double)dbls[i];
		}
	}
	else
	{
		int* ins = f.ints;
		for (int i = 0; i < size; i++)
		{
			is[i] = ins[i];
		}
	}

	return is;
}

/*
Allocates an array which is returned
*/
float* LAL_field_to_floats_helper(VecField f, VecType t, size_t size)
{
	float* fs = (float*)malloc(size * sizeof(float));

	if (VecType == INT)
	{
		int* ins = f.ints;
		for (int i = 0; i < size; i++)
		{
			fs[i] = (float)ins[i];
		}
	}
	else if (VecType == DOUBLE)
	{
		double* dbls = f.doubles;
		for (int i = 0; i < size; i++)
		{
			fs[i] = (float)dbls[i];
		}
	}
	else
	{
		float* flts = f.floats;
		for (int i = 0; i < size; i++)
		{
			fs[i] = flts[i];
		}
	}

	return fs;
}

/*
Allocates an array which is returned
*/
double* LAL_field_to_doubles_helper(VecField f, VecType t, size_t size)
{
	double* ds = (double*)malloc(size * sizeof(double));

	if (VecType == INT)
	{
		int* ins = f.ints;
		for (int i = 0; i < size; i++)
		{
			ds[i] = (double)ins[i];
		}
	}
	else if (VecType == FLOAT)
	{
		double* flts = f.floats;
		for (int i = 0; i < size; i++)
		{
			ds[i] = (double)flts[i];
		}
	}
	else
	{
		double* dbls = f.doubles;
		for (int i = 0; i < size; i++)
		{
			ds[i] = (float)dbls[i];
		}
	}

	return ds;
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

	if (res->type == INT)
	{
		int* ints1, *ints2, *resInts;

		ints1 = LAL_field_to_ints_helper(v1->field, v1->type, smallest);
		ints2 = LAL_field_to_ints_helper(v2->field, v2->type, smallest);
		resInts = res->field.ints;

		for (int i = 0; i < smallest; i++)
		{
			resInts[i] = ints1[i] + ints2[i];
		}
	}
	else if (res->type == FLOAT)
	{
		float* flts1, *flts2, *resflts;

		flts1 = LAL_field_to_floats_helper(v1->field, v1->type, smallest);
		flts2 = LAL_field_to_floats_helper(v2->field, v2->type, smallest);
		resflts = res->field.floats;

		for (int i = 0; i < smallest; i++)
		{
			resflts[i] = flts1[i] + flts2[i];
		}
	}
	else
	{
		double* dbls1, *dbls2, *resdbls;

		dbls1 = LAL_field_to_doubles_helper(v1->field, v1->type, smallest);
		dbls2 = LAL_field_to_doubles_helper(v2->field, v2->type, smallest);
		resdbls = res->field.dbls;

		for (int i = 0; i < smallest; i++)
		{
			resdbls[i] = dbls1[i] + dbls2[i];
		}
	}

	return 0;
}

int LAL_vector_subtract(Vector* v1, Vector* v2, Vector* res)
{
	size_t smallest = min(v1->size, v2->size);

	if (v1->type == UNINIT || v2->type == UNINIT)
		return -1;

	if (res->type == UNINIT)
	{
		VecType most_precise = max(v1->type, v2->type);
		LAL_vector_init(res, most_precise, smallest);
	}

	if (res->type == INT)
	{
		int* ints1, *ints2, *resInts;

		ints1 = LAL_field_to_ints_helper(v1->field, v1->type, smallest);
		ints2 = LAL_field_to_ints_helper(v2->field, v2->type, smallest);
		resInts = res->field.ints;

		for (int i = 0; i < smallest; i++)
		{
			resInts[i] = ints1[i] - ints2[i];
		}
	}
	else if (res->type == FLOAT)
	{
		float* flts1, *flts2, *resflts;

		flts1 = LAL_field_to_floats_helper(v1->field, v1->type, smallest);
		flts2 = LAL_field_to_floats_helper(v2->field, v2->type, smallest);
		resflts = res->field.floats;

		for (int i = 0; i < smallest; i++)
		{
			resflts[i] = flts1[i] - flts2[i];
		}
	}
	else
	{
		double* dbls1, *dbls2, *resdbls;

		dbls1 = LAL_field_to_doubles_helper(v1->field, v1->type, smallest);
		dbls2 = LAL_field_to_doubles_helper(v2->field, v2->type, smallest);
		resdbls = res->field.dbls;

		for (int i = 0; i < smallest; i++)
		{
			resdbls[i] = dbls1[i] - dbls2[i];
		}
	}

	return 0;
}


int LAL_vector_scale(Vector* v, double scalar){}


int LAL_vector_dot(Vector* v1, Vector* v2, Vector* res){}

int LAL_vector_cross(Vector* v1, Vector* v2, Vector* res){}

int LAL_vector_magi(Vector* v, int* res){}

int LAL_vector_magf(Vector* v, float* res){}

int LAL_vector_magd(Vector* v, double* res){}


int LAL_vector_proj(Vector* v1, Vector* v2, Vector* res){}