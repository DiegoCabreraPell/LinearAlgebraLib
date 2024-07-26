#include "vector.h"
#include <stdlib.h>
#include <math.h>


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

		free(ints1);
		free(ints2);
		ints1 = NULL;
		ints2 = NULL;
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

		free(flts1);
		free(flts2);
		flts1 = NULL;
		flts2 = NULL;
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

		free(dbls1);
		free(dbls2);
		dbls1 = NULL;
		dbls2 = NULL;
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

		free(ints1);
		free(ints2);
		ints1 = NULL;
		ints2 = NULL;
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

		free(flts1);
		free(flts2);
		flts1 = NULL;
		flts2 = NULL;
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

		free(dbls1);
		free(dbls2);
		dbls1 = NULL;
		dbls2 = NULL;
	}

	return 0;
}


int LAL_vector_scale(Vector* v, scalar c)
{
	switch (v->type)
	{
	case INT:
		int intc, *is;
		intc = (int)c;
		is = v->field.ints;
		for (int i = 0; i < v->size; i++)
		{
			is[i] *= intc;
		}
		break;

	case FLOAT:
		float fltc, *fs;
		fltc = (float) c;
		fs = v->field.floats;
		for (int i = 0; i < v->size; i++)
		{
			fs[i] *= fltc;
		}
		break;

	case DOUBLE:
		double dblc, *ds;
		dblc = (double)c;
		ds = v->field.doubles;
		for (int i = 0; i < v->size; i++)
		{
			ds[i] *= dblc;
		}
		break;

	default:
		return -1;
	}

	return 0;
}


int LAL_vector_dot(Vector* v1, Vector* v2, scalar* res)
{
	double *dbls1, *dbls2, sum;
	size_t smallest = min(v1->size, v2->size);

	if (v1->type == UNINIT || v2->type == UNINIT)
		return -1;

	sum = 0;

	dbls1 = LAL_field_to_doubles_helper(v1->field, v1->type, smallest);
	dbls2 = LAL_field_to_doubles_helper(v2->field, v2->type, smallest);

	for (int i = 0; i < smallestl; i++)
	{
		sum += dbls1[i] * dbls2[i];
	}

	free(dbls1);
	free(dbls2);
	dbls1 = NULL;
	dbls2 = NULL;

	*res = sum;

	return 0;
}

int LAL_vector_cross(Vector* v1, Vector* v2, Vector* res)
{
	if (v1->size < 3 || v2->size < 3 || v1->type == UNINIT || v2->type == UNINIT)
		return -1;

	if (res->type == UNINIT)
	{
		VecType most_precise = max(v1->type, v2->type);
		LAL_vector_init(res, most_precise, 3);
	}
	else if (res->size < 3)
		return -1;

	switch (res->type) 
	{
	case INT:
		int* ints1, * ints2, resInts;
		ints1 = LAL_field_to_ints_helper(v1->field, v1->type, 3);
		ints2 = LAL_field_to_ints_helper(v2->field, v2->type, 3);

		resInts = res->field.ints;

		resInts[0] = (ints1[1] * ints2[2]) - (ints1[2] - ints2[1]);
		resInts[1] = (ints1[2] * ints2[0]) - (ints1[0] - ints2[2]);
		resInts[2] = (ints1[0] * ints2[1]) - (ints1[1] - ints2[0]);

		free(ints1);
		free(ints2);
		ints1 = NULL;
		ints2 = NULL;
		break;
	case FLOAT:
		float* flts1, * flts2, resflts;
		flts1 = LAL_field_to_floats_helper(v1->field, v1->type, 3);
		flts2 = LAL_field_to_floats_helper(v2->field, v2->type, 3);

		resflts = res->field.flts;

		resflts[0] = (flts1[1] * flts2[2]) - (flts1[2] - flts2[1]);
		resflts[1] = (flts1[2] * flts2[0]) - (flts1[0] - flts2[2]);
		resflts[2] = (flts1[0] * flts2[1]) - (flts1[1] - flts2[0]);

		free(flts1);
		free(flts2);
		flts1 = NULL;
		flts2 = NULL;
		break;
	case DOUBLE:
		double* dbls1, * dbls2, resdbls;
		dbls1 = LAL_field_to_doubles_helper(v1->field, v1->type, 3);
		dbls2 = LAL_field_to_doubles_helper(v2->field, v2->type, 3);

		resdbls = res->field.dbls;

		resdbls[0] = (dbls1[1] * dbls2[2]) - (dbls1[2] - dbls2[1]);
		resdbls[1] = (dbls1[2] * dbls2[0]) - (dbls1[0] - dbls2[2]);
		resdbls[2] = (dbls1[0] * dbls2[1]) - (dbls1[1] - dbls2[0]);

		free(dbls1);
		free(dbls2);
		dbls1 = NULL;
		dbls2 = NULL;
		break;
	}

	return 0;
}

int LAL_vector_mag(Vector* v, scalar* res) 
{
	if (v->type == UNINIT)
		return -1;

	size_t s = v->size;
	double* dbls, val;
	dbls = LAL_field_to_doubles_helper(v->field, v->type, s);

	scalar sum = 0;

	for (int i = 0; i < s; i++)
	{
		val = dbls[i];
		sum += val * val;
	}

	free(dbls);
	dbls = NULL;

	*res = sqrt(sum);

	return 0;
}


int LAL_vector_proj(Vector* v1, Vector* v2, Vector* res){}