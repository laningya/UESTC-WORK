#pragma once

#include <QtCore/qglobal.h>

#ifndef BUILD_STATIC
# if defined(DATADRIVE_LIB)
#  define DATADRIVE_EXPORT Q_DECL_EXPORT
# else
#  define DATADRIVE_EXPORT Q_DECL_IMPORT
# endif
#else
# define DATADRIVE_EXPORT
#endif
