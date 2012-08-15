/*
 * Python object definition of the libevt record
 *
 * Copyright (c) 2009-2012, Joachim Metz <joachim.metz@gmail.com>
 *
 * Refer to AUTHORS for acknowledgements.
 *
 * This software is free software: you can redistribute it and/or modify
 * it under the terms of the GNU Lesser General Public License as published by
 * the Free Software Foundation, either version 3 of the License, or
 * (at your option) any later version.
 * 
 * This software is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 * 
 * You should have received a copy of the GNU Lesser General Public License
 * along with this software.  If not, see <http://www.gnu.org/licenses/>.
 */

#include <common.h>
#include <memory.h>
#include <types.h>

#if defined( HAVE_STDLIB_H ) || defined( HAVE_WINAPI )
#include <stdlib.h>
#endif

#include "pyevt.h"
#include "pyevt_datetime.h"
#include "pyevt_libcerror.h"
#include "pyevt_libcstring.h"
#include "pyevt_libevt.h"
#include "pyevt_python.h"
#include "pyevt_record.h"

PyMethodDef pyevt_record_object_methods[] = {

	/* Functions to access the record values */

	{ "get_identifier",
	  (PyCFunction) pyevt_record_get_identifier,
	  METH_NOARGS,
	  "get_identifier() -> Integer\n"
	  "\n"
	  "Retrieves the identifier (number)" },

	{ "get_creation_time",
	  (PyCFunction) pyevt_record_get_creation_time,
	  METH_NOARGS,
	  "get_creation_time() -> Datetime\n"
	  "\n"
	  "Returns the creation date and time" },

	{ "get_written_time",
	  (PyCFunction) pyevt_record_get_written_time,
	  METH_NOARGS,
	  "get_written_time() -> Datetime\n"
	  "\n"
	  "Returns the written date and time" },

	{ "get_event_identifier",
	  (PyCFunction) pyevt_record_get_event_identifier,
	  METH_NOARGS,
	  "get_event_identifier() -> Integer\n"
	  "\n"
	  "Retrieves the event identifier" },

	{ "get_event_type",
	  (PyCFunction) pyevt_record_get_event_type,
	  METH_NOARGS,
	  "get_event_type() -> Integer\n"
	  "\n"
	  "Retrieves the event type" },

	{ "get_source_name",
	  (PyCFunction) pyevt_record_get_source_name,
	  METH_NOARGS,
	  "get_source_name -> Unicode string or None\n"
	  "\n"
	  "Retrieves the source name" },

	{ "get_computer_name",
	  (PyCFunction) pyevt_record_get_computer_name,
	  METH_NOARGS,
	  "get_computer_name -> Unicode string or None\n"
	  "\n"
	  "Retrieves the computer name" },

	{ "get_user_security_identifier",
	  (PyCFunction) pyevt_record_get_user_security_identifier,
	  METH_NOARGS,
	  "get_user_security_identifier -> Unicode string or None\n"
	  "\n"
	  "Retrieves the user security identifier (SID)" },

	/* Functions to access the string */

	{ "get_number_of_strings",
	  (PyCFunction) pyevt_record_get_number_of_strings,
	  METH_NOARGS,
	  "get_number_of_strings() -> Integer\n"
	  "\n"
	  "Retrieves the number of strings" },

	{ "get_string",
	  (PyCFunction) pyevt_record_get_string,
	  METH_VARARGS | METH_KEYWORDS,
	  "get_string(string_index) -> Object or None\n"
	  "\n"
	  "Retrieves a specific string" },

	/* Sentinel */
	{ NULL, NULL, 0, NULL }
};

PyGetSetDef pyevt_record_object_get_set_definitions[] = {

	{ "identifier",
	  (getter) pyevt_record_get_identifier,
	  (setter) 0,
	  "The identifier (number)",
	  NULL },

	{ "creation_time",
	  (getter) pyevt_record_get_creation_time,
	  (setter) 0,
	  "The creation date and time",
	  NULL },

	{ "written_time",
	  (getter) pyevt_record_get_written_time,
	  (setter) 0,
	  "The written date and time",
	  NULL },

	{ "event_identifier",
	  (getter) pyevt_record_get_event_identifier,
	  (setter) 0,
	  "The event identifier",
	  NULL },

	{ "event_type",
	  (getter) pyevt_record_get_event_type,
	  (setter) 0,
	  "The event type",
	  NULL },

	{ "source_name",
	  (getter) pyevt_record_get_source_name,
	  (setter) 0,
	  "The source name",
	  NULL },

	{ "computer_name",
	  (getter) pyevt_record_get_computer_name,
	  (setter) 0,
	  "The computer name",
	  NULL },

	{ "user_security_identifier",
	  (getter) pyevt_record_get_user_security_identifier,
	  (setter) 0,
	  "The user security identifier (SID)",
	  NULL },

	{ "number_of_strings",
	  (getter) pyevt_record_get_number_of_strings,
	  (setter) 0,
	  "The number of strings",
	  NULL },

	/* Sentinel */
	{ NULL, NULL, NULL, NULL, NULL }
};

PyTypeObject pyevt_record_type_object = {
	PyObject_HEAD_INIT( NULL )

	/* ob_size */
	0,
	/* tp_name */
	"pyevt.record",
	/* tp_basicsize */
	sizeof( pyevt_record_t ),
	/* tp_recordsize */
	0,
	/* tp_dealloc */
	(destructor) pyevt_record_free,
	/* tp_print */
	0,
	/* tp_getattr */
	0,
	/* tp_setattr */
	0,
	/* tp_compare */
	0,
	/* tp_repr */
	0,
	/* tp_as_number */
	0,
	/* tp_as_sequence */
	0,
	/* tp_as_mapping */
	0,
	/* tp_hash */
	0,
	/* tp_call */
	0,
	/* tp_str */
	0,
	/* tp_getattro */
	0,
	/* tp_setattro */
	0,
	/* tp_as_buffer */
	0,
        /* tp_flags */
	Py_TPFLAGS_DEFAULT,
	/* tp_doc */
	"pyevt record object (wraps libevt_record_t)",
	/* tp_traverse */
	0,
	/* tp_clear */
	0,
	/* tp_richcompare */
	0,
	/* tp_weaklistoffset */
	0,
	/* tp_iter */
	0,
	/* tp_iternext */
	0,
	/* tp_methods */
	pyevt_record_object_methods,
	/* tp_members */
	0,
	/* tp_getset */
	pyevt_record_object_get_set_definitions,
	/* tp_base */
	0,
	/* tp_dict */
	0,
	/* tp_descr_get */
	0,
	/* tp_descr_set */
	0,
	/* tp_dictoffset */
	0,
	/* tp_init */
	(initproc) pyevt_record_init,
	/* tp_alloc */
	0,
	/* tp_new */
	0,
	/* tp_free */
	0,
	/* tp_is_gc */
	0,
	/* tp_bases */
	NULL,
	/* tp_mro */
	NULL,
	/* tp_cache */
	NULL,
	/* tp_subclasses */
	NULL,
	/* tp_weaklist */
	NULL,
	/* tp_del */
	0
};

/* Creates a new record object
 * Returns a Python object if successful or NULL on error
 */
PyObject *pyevt_record_new(
           PyObject *self )
{
	pyevt_record_t *pyevt_record = NULL;
	static char *function    = "pyevt_record_new";

	pyevt_record = PyObject_New(
	              struct pyevt_record,
	              &pyevt_record_type_object );

	if( pyevt_record == NULL )
	{
		PyErr_Format(
		 PyExc_MemoryError,
		 "%s: unable to initialize record.",
		 function );

		return( NULL );
	}
	if( pyevt_record_init(
	     pyevt_record ) != 0 )
	{
		PyErr_Format(
		 PyExc_MemoryError,
		 "%s: unable to initialize record.",
		 function );

		goto on_error;
	}
	return( (PyObject *) pyevt_record );

on_error:
	if( pyevt_record != NULL )
	{
		Py_DecRef(
		 (PyObject *) pyevt_record );
	}
	return( NULL );
}

/* Intializes an record object
 * Returns 0 if successful or -1 on error
 */
int pyevt_record_init(
     pyevt_record_t *pyevt_record )
{
	static char *function = "pyevt_record_init";

	if( pyevt_record == NULL )
	{
		PyErr_Format(
		 PyExc_TypeError,
		 "%s: invalid record.",
		 function );

		return( -1 );
	}
	/* Make sure libevt record is set to NULL
	 */
	pyevt_record->record = NULL;

	return( 0 );
}

/* Frees an record object
 */
void pyevt_record_free(
      pyevt_record_t *pyevt_record )
{
	char error_string[ PYEVT_ERROR_STRING_SIZE ];

	libcerror_error_t *error = NULL;
	static char *function    = "pyevt_record_free";

	if( pyevt_record == NULL )
	{
		PyErr_Format(
		 PyExc_TypeError,
		 "%s: invalid record.",
		 function );

		return;
	}
	if( pyevt_record->ob_type == NULL )
	{
		PyErr_Format(
		 PyExc_TypeError,
		 "%s: invalid record - missing ob_type.",
		 function );

		return;
	}
	if( pyevt_record->ob_type->tp_free == NULL )
	{
		PyErr_Format(
		 PyExc_TypeError,
		 "%s: invalid record - invalid ob_type - missing tp_free.",
		 function );

		return;
	}
	if( pyevt_record->record == NULL )
	{
		PyErr_Format(
		 PyExc_TypeError,
		 "%s: invalid record - missing libevt record.",
		 function );

		return;
	}
	if( libevt_record_free(
	     &( pyevt_record->record ),
	     &error ) != 1 )
	{
		if( libcerror_error_backtrace_sprint(
		     error,
		     error_string,
		     PYEVT_ERROR_STRING_SIZE ) == -1 )
                {
			PyErr_Format(
			 PyExc_IOError,
			 "%s: unable to free libevt record.",
			 function );
		}
		else
                {
			PyErr_Format(
			 PyExc_IOError,
			 "%s: unable to free libevt record.\n%s",
			 function,
			 error_string );
		}
		libcerror_error_free(
		 &error );
	}
	pyevt_record->ob_type->tp_free(
	 (PyObject*) pyevt_record );
}

/* Retrieves the identifier
 * Returns a Python object if successful or NULL on error
 */
PyObject *pyevt_record_get_identifier(
           pyevt_record_t *pyevt_record )
{
	char error_string[ PYEVT_ERROR_STRING_SIZE ];

	libcerror_error_t *error = NULL;
	static char *function    = "pyevt_record_get_identifier";
	uint32_t identifier      = 0;
	int result               = 0;

	if( pyevt_record == NULL )
	{
		PyErr_Format(
		 PyExc_TypeError,
		 "%s: invalid record.",
		 function );

		return( NULL );
	}
	Py_BEGIN_ALLOW_THREADS

	result = libevt_record_get_identifier(
	          pyevt_record->record,
	          &identifier,
	          &error );

	Py_END_ALLOW_THREADS

	if( result != 1 )
	{
		if( libcerror_error_backtrace_sprint(
		     error,
		     error_string,
		     PYEVT_ERROR_STRING_SIZE ) == -1 )
                {
			PyErr_Format(
			 PyExc_IOError,
			 "%s: unable to retrieve identifier.",
			 function );
		}
		else
		{
			PyErr_Format(
			 PyExc_IOError,
			 "%s: unable to retrieve identifier.\n%s",
			 function,
			 error_string );
		}
		libcerror_error_free(
		 &error );

		return( NULL );
	}
	return( PyInt_FromLong(
	         (long) identifier ) );
}

/* Retrieves the creation date and time
 * Returns a Python object holding the offset if successful or NULL on error
 */
PyObject *pyevt_record_get_creation_time(
           pyevt_record_t *pyevt_record )
{
	char error_string[ PYEVT_ERROR_STRING_SIZE ];

	libcerror_error_t *error   = NULL;
	PyObject *date_time_object = NULL;
	static char *function      = "pyevt_record_get_creation_time";
	uint32_t posix_time        = 0;
	int result                 = 0;

	if( pyevt_record == NULL )
	{
		PyErr_Format(
		 PyExc_ValueError,
		 "%s: invalid record.",
		 function );

		return( NULL );
	}
	Py_BEGIN_ALLOW_THREADS

	result = libevt_record_get_creation_time(
	          pyevt_record->record,
	          &posix_time,
	          &error );

	Py_END_ALLOW_THREADS

	if( result != 1 )
	{
		if( libcerror_error_backtrace_sprint(
		     error,
		     error_string,
		     PYEVT_ERROR_STRING_SIZE ) == -1 )
		{
			PyErr_Format(
			 PyExc_IOError,
			 "%s: unable to retrieve creation time.",
			 function );
		}
		else
		{
			PyErr_Format(
			 PyExc_IOError,
			 "%s: unable to retrieve creation time.\n%s",
			 function,
			 error_string );
		}
		libcerror_error_free(
		 &error );

		return( NULL );
	}
	date_time_object = pyevt_datetime_new_from_posix_time(
	                    posix_time );

	return( date_time_object );
}

/* Retrieves the written date and time
 * Returns a Python object holding the offset if successful or NULL on error
 */
PyObject *pyevt_record_get_written_time(
           pyevt_record_t *pyevt_record )
{
	char error_string[ PYEVT_ERROR_STRING_SIZE ];

	libcerror_error_t *error   = NULL;
	PyObject *date_time_object = NULL;
	static char *function      = "pyevt_record_get_written_time";
	uint32_t posix_time        = 0;
	int result                 = 0;

	if( pyevt_record == NULL )
	{
		PyErr_Format(
		 PyExc_ValueError,
		 "%s: invalid record.",
		 function );

		return( NULL );
	}
	Py_BEGIN_ALLOW_THREADS

	result = libevt_record_get_written_time(
	          pyevt_record->record,
	          &posix_time,
	          &error );

	Py_END_ALLOW_THREADS

	if( result != 1 )
	{
		if( libcerror_error_backtrace_sprint(
		     error,
		     error_string,
		     PYEVT_ERROR_STRING_SIZE ) == -1 )
		{
			PyErr_Format(
			 PyExc_IOError,
			 "%s: unable to retrieve written time.",
			 function );
		}
		else
		{
			PyErr_Format(
			 PyExc_IOError,
			 "%s: unable to retrieve written time.\n%s",
			 function,
			 error_string );
		}
		libcerror_error_free(
		 &error );

		return( NULL );
	}
	date_time_object = pyevt_datetime_new_from_posix_time(
	                    posix_time );

	return( date_time_object );
}

/* Retrieves the event identifier
 * Returns a Python object if successful or NULL on error
 */
PyObject *pyevt_record_get_event_identifier(
           pyevt_record_t *pyevt_record )
{
	char error_string[ PYEVT_ERROR_STRING_SIZE ];

	libcerror_error_t *error  = NULL;
	static char *function     = "pyevt_record_get_event_identifier";
	uint32_t event_identifier = 0;
	int result                = 0;

	if( pyevt_record == NULL )
	{
		PyErr_Format(
		 PyExc_TypeError,
		 "%s: invalid record.",
		 function );

		return( NULL );
	}
	Py_BEGIN_ALLOW_THREADS

	result = libevt_record_get_event_identifier(
	          pyevt_record->record,
	          &event_identifier,
	          &error );

	Py_END_ALLOW_THREADS

	if( result != 1 )
	{
		if( libcerror_error_backtrace_sprint(
		     error,
		     error_string,
		     PYEVT_ERROR_STRING_SIZE ) == -1 )
                {
			PyErr_Format(
			 PyExc_IOError,
			 "%s: unable to retrieve event identifier.",
			 function );
		}
		else
		{
			PyErr_Format(
			 PyExc_IOError,
			 "%s: unable to retrieve event identifier.\n%s",
			 function,
			 error_string );
		}
		libcerror_error_free(
		 &error );

		return( NULL );
	}
	return( PyInt_FromLong(
	         (long) event_identifier ) );
}

/* Retrieves the event type
 * Returns a Python object if successful or NULL on error
 */
PyObject *pyevt_record_get_event_type(
           pyevt_record_t *pyevt_record )
{
	char error_string[ PYEVT_ERROR_STRING_SIZE ];

	libcerror_error_t *error = NULL;
	static char *function    = "pyevt_record_get_event_type";
	uint16_t event_type      = 0;
	int result               = 0;

	if( pyevt_record == NULL )
	{
		PyErr_Format(
		 PyExc_TypeError,
		 "%s: invalid record.",
		 function );

		return( NULL );
	}
	Py_BEGIN_ALLOW_THREADS

	result = libevt_record_get_event_type(
	          pyevt_record->record,
	          &event_type,
	          &error );

	Py_END_ALLOW_THREADS

	if( result != 1 )
	{
		if( libcerror_error_backtrace_sprint(
		     error,
		     error_string,
		     PYEVT_ERROR_STRING_SIZE ) == -1 )
                {
			PyErr_Format(
			 PyExc_IOError,
			 "%s: unable to retrieve event type.",
			 function );
		}
		else
		{
			PyErr_Format(
			 PyExc_IOError,
			 "%s: unable to retrieve event type.\n%s",
			 function,
			 error_string );
		}
		libcerror_error_free(
		 &error );

		return( NULL );
	}
	return( PyInt_FromLong(
	         (long) event_type ) );
}

/* Retrieves the source name
 * Returns a Python object if successful or NULL on error
 */
PyObject *pyevt_record_get_source_name(
           pyevt_record_t *pyevt_record )
{
	char error_string[ PYEVT_ERROR_STRING_SIZE ];

	libcerror_error_t *error = NULL;
	PyObject *string_object  = NULL;
	const char *errors       = NULL;
	uint8_t *source_name     = NULL;
	static char *function    = "pyevt_record_get_source_name";
	size_t source_name_size  = 0;
	int result               = 0;

	if( pyevt_record == NULL )
	{
		PyErr_Format(
		 PyExc_TypeError,
		 "%s: invalid record.",
		 function );

		return( NULL );
	}
	Py_BEGIN_ALLOW_THREADS

	result = libevt_record_get_utf8_source_name_size(
	          pyevt_record->record,
	          &source_name_size,
	          &error );

	Py_END_ALLOW_THREADS

	if( result == -1 )
	{
		if( libcerror_error_backtrace_sprint(
		     error,
		     error_string,
		     PYEVT_ERROR_STRING_SIZE ) == -1 )
                {
			PyErr_Format(
			 PyExc_IOError,
			 "%s: unable to retrieve source name size.",
			 function );
		}
		else
                {
			PyErr_Format(
			 PyExc_IOError,
			 "%s: unable to retrieve source name size.\n%s",
			 function,
			 error_string );
		}
		libcerror_error_free(
		 &error );

		goto on_error;
	}
	else if( ( result == 0 )
	      || ( source_name_size == 0 ) )
	{
		Py_IncRef(
		 Py_None );

		return( Py_None );
	}
	source_name = (uint8_t *) memory_allocate(
	                           sizeof( uint8_t ) * source_name_size );

	if( source_name == NULL )
	{
		PyErr_Format(
		 PyExc_IOError,
		 "%s: unable to create source name.",
		 function );

		goto on_error;
	}
	Py_BEGIN_ALLOW_THREADS

	result = libevt_record_get_utf8_source_name(
		  pyevt_record->record,
		  source_name,
		  source_name_size,
		  &error );

	Py_END_ALLOW_THREADS

	if( result != 1 )
	{
		if( libcerror_error_backtrace_sprint(
		     error,
		     error_string,
		     PYEVT_ERROR_STRING_SIZE ) == -1 )
                {
			PyErr_Format(
			 PyExc_IOError,
			 "%s: unable to retrieve source name.",
			 function );
		}
		else
                {
			PyErr_Format(
			 PyExc_IOError,
			 "%s: unable to retrieve source name.\n%s",
			 function,
			 error_string );
		}
		libcerror_error_free(
		 &error );

		goto on_error;
	}
	/* Pass the string length to PyUnicode_DecodeUTF8
	 * otherwise it makes the end of string character is part
	 * of the string
	 */
	string_object = PyUnicode_DecodeUTF8(
			 (char *) source_name,
			 (Py_ssize_t) source_name_size - 1,
			 errors );

	memory_free(
	 source_name );

	return( string_object );

on_error:
	if( source_name != NULL )
	{
		memory_free(
		 source_name );
	}
	return( NULL );
}

/* Retrieves the computer name
 * Returns a Python object if successful or NULL on error
 */
PyObject *pyevt_record_get_computer_name(
           pyevt_record_t *pyevt_record )
{
	char error_string[ PYEVT_ERROR_STRING_SIZE ];

	libcerror_error_t *error  = NULL;
	PyObject *string_object   = NULL;
	const char *errors        = NULL;
	uint8_t *computer_name    = NULL;
	static char *function     = "pyevt_record_get_computer_name";
	size_t computer_name_size = 0;
	int result                = 0;

	if( pyevt_record == NULL )
	{
		PyErr_Format(
		 PyExc_TypeError,
		 "%s: invalid record.",
		 function );

		return( NULL );
	}
	Py_BEGIN_ALLOW_THREADS

	result = libevt_record_get_utf8_computer_name_size(
	          pyevt_record->record,
	          &computer_name_size,
	          &error );

	Py_END_ALLOW_THREADS

	if( result == -1 )
	{
		if( libcerror_error_backtrace_sprint(
		     error,
		     error_string,
		     PYEVT_ERROR_STRING_SIZE ) == -1 )
                {
			PyErr_Format(
			 PyExc_IOError,
			 "%s: unable to retrieve computer name size.",
			 function );
		}
		else
                {
			PyErr_Format(
			 PyExc_IOError,
			 "%s: unable to retrieve computer name size.\n%s",
			 function,
			 error_string );
		}
		libcerror_error_free(
		 &error );

		goto on_error;
	}
	else if( ( result == 0 )
	      || ( computer_name_size == 0 ) )
	{
		Py_IncRef(
		 Py_None );

		return( Py_None );
	}
	computer_name = (uint8_t *) memory_allocate(
	                             sizeof( uint8_t ) * computer_name_size );

	if( computer_name == NULL )
	{
		PyErr_Format(
		 PyExc_IOError,
		 "%s: unable to create computer name.",
		 function );

		goto on_error;
	}
	Py_BEGIN_ALLOW_THREADS

	result = libevt_record_get_utf8_computer_name(
		  pyevt_record->record,
		  computer_name,
		  computer_name_size,
		  &error );

	Py_END_ALLOW_THREADS

	if( result != 1 )
	{
		if( libcerror_error_backtrace_sprint(
		     error,
		     error_string,
		     PYEVT_ERROR_STRING_SIZE ) == -1 )
                {
			PyErr_Format(
			 PyExc_IOError,
			 "%s: unable to retrieve computer name.",
			 function );
		}
		else
                {
			PyErr_Format(
			 PyExc_IOError,
			 "%s: unable to retrieve computer name.\n%s",
			 function,
			 error_string );
		}
		libcerror_error_free(
		 &error );

		goto on_error;
	}
	/* Pass the string length to PyUnicode_DecodeUTF8
	 * otherwise it makes the end of string character is part
	 * of the string
	 */
	string_object = PyUnicode_DecodeUTF8(
			 (char *) computer_name,
			 (Py_ssize_t) computer_name_size - 1,
			 errors );

	memory_free(
	 computer_name );

	return( string_object );

on_error:
	if( computer_name != NULL )
	{
		memory_free(
		 computer_name );
	}
	return( NULL );
}

/* Retrieves the user security identifier
 * Returns a Python object if successful or NULL on error
 */
PyObject *pyevt_record_get_user_security_identifier(
           pyevt_record_t *pyevt_record )
{
	char error_string[ PYEVT_ERROR_STRING_SIZE ];

	libcerror_error_t *error             = NULL;
	PyObject *string_object              = NULL;
	const char *errors                   = NULL;
	uint8_t *user_security_identifier    = NULL;
	static char *function                = "pyevt_record_get_user_security_identifier";
	size_t user_security_identifier_size = 0;
	int result                           = 0;

	if( pyevt_record == NULL )
	{
		PyErr_Format(
		 PyExc_TypeError,
		 "%s: invalid record.",
		 function );

		return( NULL );
	}
	Py_BEGIN_ALLOW_THREADS

	result = libevt_record_get_utf8_user_security_identifier_size(
	          pyevt_record->record,
	          &user_security_identifier_size,
	          &error );

	Py_END_ALLOW_THREADS

	if( result == -1 )
	{
		if( libcerror_error_backtrace_sprint(
		     error,
		     error_string,
		     PYEVT_ERROR_STRING_SIZE ) == -1 )
                {
			PyErr_Format(
			 PyExc_IOError,
			 "%s: unable to retrieve user security identifier size.",
			 function );
		}
		else
                {
			PyErr_Format(
			 PyExc_IOError,
			 "%s: unable to retrieve user security identifier size.\n%s",
			 function,
			 error_string );
		}
		libcerror_error_free(
		 &error );

		goto on_error;
	}
	else if( ( result == 0 )
	      || ( user_security_identifier_size == 0 ) )
	{
		Py_IncRef(
		 Py_None );

		return( Py_None );
	}
	user_security_identifier = (uint8_t *) memory_allocate(
	                                        sizeof( uint8_t ) * user_security_identifier_size );

	if( user_security_identifier == NULL )
	{
		PyErr_Format(
		 PyExc_IOError,
		 "%s: unable to create user security identifier.",
		 function );

		goto on_error;
	}
	Py_BEGIN_ALLOW_THREADS

	result = libevt_record_get_utf8_user_security_identifier(
		  pyevt_record->record,
		  user_security_identifier,
		  user_security_identifier_size,
		  &error );

	Py_END_ALLOW_THREADS

	if( result != 1 )
	{
		if( libcerror_error_backtrace_sprint(
		     error,
		     error_string,
		     PYEVT_ERROR_STRING_SIZE ) == -1 )
                {
			PyErr_Format(
			 PyExc_IOError,
			 "%s: unable to retrieve user security identifier.",
			 function );
		}
		else
                {
			PyErr_Format(
			 PyExc_IOError,
			 "%s: unable to retrieve user security identifier.\n%s",
			 function,
			 error_string );
		}
		libcerror_error_free(
		 &error );

		goto on_error;
	}
	/* Pass the string length to PyUnicode_DecodeUTF8
	 * otherwise it makes the end of string character is part
	 * of the string
	 */
	string_object = PyUnicode_DecodeUTF8(
			 (char *) user_security_identifier,
			 (Py_ssize_t) user_security_identifier_size - 1,
			 errors );

	memory_free(
	 user_security_identifier );

	return( string_object );

on_error:
	if( user_security_identifier != NULL )
	{
		memory_free(
		 user_security_identifier );
	}
	return( NULL );
}

/* Retrieves the number of strings
 * Returns a Python object if successful or NULL on error
 */
PyObject *pyevt_record_get_number_of_strings(
           pyevt_record_t *pyevt_record )
{
	char error_string[ PYEVT_ERROR_STRING_SIZE ];

	libcerror_error_t *error = NULL;
	static char *function    = "pyevt_record_get_number_of_strings";
	int number_of_strings    = 0;
	int result               = 0;

	if( pyevt_record == NULL )
	{
		PyErr_Format(
		 PyExc_TypeError,
		 "%s: invalid record.",
		 function );

		return( NULL );
	}
	Py_BEGIN_ALLOW_THREADS

	result = libevt_record_get_number_of_strings(
	          pyevt_record->record,
	          &number_of_strings,
	          &error );

	Py_END_ALLOW_THREADS

	if( result != 1 )
	{
		if( libcerror_error_backtrace_sprint(
		     error,
		     error_string,
		     PYEVT_ERROR_STRING_SIZE ) == -1 )
                {
			PyErr_Format(
			 PyExc_IOError,
			 "%s: unable to retrieve number of strings.",
			 function );
		}
		else
		{
			PyErr_Format(
			 PyExc_IOError,
			 "%s: unable to retrieve number of strings.\n%s",
			 function,
			 error_string );
		}
		libcerror_error_free(
		 &error );

		return( NULL );
	}
	return( PyInt_FromLong(
	         (long) number_of_strings ) );
}

/* Retrieves a specific string
 * Returns a Python object if successful or NULL on error
 */
PyObject *pyevt_record_get_string(
           pyevt_record_t *pyevt_record,
           PyObject *arguments,
           PyObject *keywords )
{
	char error_string[ PYEVT_ERROR_STRING_SIZE ];

	libcerror_error_t *error    = NULL;
	PyObject *string_object     = NULL;
	uint8_t *string             = NULL;
	const char *errors          = NULL;
	static char *keyword_list[] = { "string_index", NULL };
	static char *function       = "pyevt_record_get_string";
	size_t string_size          = 0;
	int string_index            = 0;
	int result                  = 0;

	if( pyevt_record == NULL )
	{
		PyErr_Format(
		 PyExc_TypeError,
		 "%s: invalid record.",
		 function );

		return( NULL );
	}
	if( PyArg_ParseTupleAndKeywords(
	     arguments,
	     keywords,
	     "i",
	     keyword_list,
	     &string_index ) == 0 )
        {
		goto on_error;
        }
	Py_BEGIN_ALLOW_THREADS

	result = libevt_record_get_utf8_string_size(
	          pyevt_record->record,
	          string_index,
	          &string_size,
	          &error );

	Py_END_ALLOW_THREADS

	if( result == -1 )
	{
		if( libcerror_error_backtrace_sprint(
		     error,
		     error_string,
		     PYEVT_ERROR_STRING_SIZE ) == -1 )
                {
			PyErr_Format(
			 PyExc_IOError,
			 "%s: unable to retrieve string: %d size.",
			 function,
			 string_index );
		}
		else
                {
			PyErr_Format(
			 PyExc_IOError,
			 "%s: unable to retrieve string: %d size.\n%s",
			 function,
			 string_index,
			 error_string );
		}
		libcerror_error_free(
		 &error );

		goto on_error;
	}
	else if( ( result == 0 )
	      || ( string_size == 0 ) )
	{
		Py_IncRef(
		 Py_None );

		return( Py_None );
	}
	string = (uint8_t *) memory_allocate(
	                      sizeof( uint8_t ) * string_size );

	if( string == NULL )
	{
		PyErr_Format(
		 PyExc_IOError,
		 "%s: unable to create string: %d.",
		 function,
		 string_index );

		goto on_error;
	}
	Py_BEGIN_ALLOW_THREADS

	result = libevt_record_get_utf8_string(
		  pyevt_record->record,
		  string_index,
		  string,
		  string_size,
		  &error );

	Py_END_ALLOW_THREADS

	if( result != 1 )
	{
		if( libcerror_error_backtrace_sprint(
		     error,
		     error_string,
		     PYEVT_ERROR_STRING_SIZE ) == -1 )
                {
			PyErr_Format(
			 PyExc_IOError,
			 "%s: unable to retrieve string: %d.",
			 function,
			 string_index );
		}
		else
                {
			PyErr_Format(
			 PyExc_IOError,
			 "%s: unable to retrieve string: %d.\n%s",
			 function,
			 string_index,
			 error_string );
		}
		libcerror_error_free(
		 &error );

		goto on_error;
	}
	/* Pass the string length to PyUnicode_DecodeUTF8
	 * otherwise it makes the end of string character is part
	 * of the string
	 */
	string_object = PyUnicode_DecodeUTF8(
			 (char *) string,
			 (Py_ssize_t) string_size - 1,
			 errors );

	memory_free(
	 string );

	return( string_object );

on_error:
	if( string != NULL )
	{
		memory_free(
		 string );
	}
	return( NULL );
}
