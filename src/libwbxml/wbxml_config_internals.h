/*
 * Copyright (C) 2008 Michael Bell <michael.bell@opensync.org>
 */

#ifndef WBXML_CONFIG_INTERNALS_H
#define WBXML_CONFIG_INTERNALS_H

/* These are the public details of the configuration. */
#include "wbxml_config.h"

/* Define to 1 if you have the <dlfcn.h> header file. */
/* #undef HAVE_DLFCN_H */

/* Define to 1 if you don't have `vprintf' but do have `_doprnt.' */
/* #undef HAVE_DOPRNT */

/* Define to 1 if you have the <expat.h> header file. */
/* Define to 1 if you have the `expat' library (-lexpat). */
#define HAVE_EXPAT

/* Define to 1 if you have the `iconv' library (sometimes in libc). */
#define HAVE_ICONV

/* Define to 1 if you have the <inttypes.h> header file. */
/* #undef HAVE_INTTYPES_H */

/* Define to 1 if you have the `nsl' library (-lnsl). */
/* #undef HAVE_LIBNSL */

/* Define to 1 if you have the `popt' library (-lpopt). */
/* #undef HAVE_LIBPOPT */

/* Define to 1 if you have the `z' library (-lz). */
/* #undef HAVE_LIBZ */

/* Define to 1 if you have the <limits.h> header file. */
#define HAVE_LIMITS_H

/* Define to 1 if you have the <memory.h> header file. */
/* #undef HAVE_MEMORY_H */

/* Define to 1 if you have the <stdint.h> header file. */
/* #undef HAVE_STDINT_H */

/* Define to 1 if you have the <stdlib.h> header file. */
#define HAVE_STDLIB_H

/* Define to 1 if you have the <strings.h> header file. */
/* #undef HAVE_STRINGS_H */

/* Define to 1 if you have the <string.h> header file. */
/* #undef HAVE_STRING_H */

/* Define to 1 if you have the <sys/stat.h> header file. */
/* #undef HAVE_SYS_STAT_H */

/* Define to 1 if you have the <sys/types.h> header file. */
/* #undef HAVE_SYS_TYPES_H */

/* Define to 1 if you have the <unistd.h> header file. */
/* #undef HAVE_UNISTD_H */

/* Define to 1 if you have the `vprintf' function. */
/* #undef HAVE_VPRINTF */

/* Name of package */
#define PACKAGE "libwbxml"

/* Define to the address where bug reports for this package should be sent. */
#define PACKAGE_BUGREPORT " "

/* Define to the full name of this package. */
#define PACKAGE_NAME "libwbxml"

/* Define to the full name and version of this package. */
#define PACKAGE_STRING "libwbxml 0.11.5"

/* Define to the one symbol short name of this package. */
#define PACKAGE_TARNAME "libwbxml"

/* Define to the version of this package. */
#define PACKAGE_VERSION "0.11.5"

/* Define to 1 if you have the ANSI C header files. */
/* #undef STDC_HEADERS */

/* Version number of package */
#define VERSION "0.11.5"

/* Define to empty if `const' does not conform to ANSI C. */
/* #undef const */

/* Define to `unsigned int' if <sys/types.h> does not define. */
/* #undef size_t */

/* Includes */
#if defined( HAVE_EXPAT)
#include <expat.h>
#endif /* HAVE_EXPAT */

#if defined( HAVE_ICONV )
#include <iconv.h>
#endif /* HAVE_ICONV */


#endif /* WBXML_CONFIG_INTERNALS_H */
