#ifndef HEADER_H
#define HEADER_H

#include "Scoped_ptr.h"
#include "Auto_ptr.h"
#include "Shared_ptr.h"

#define BYTE (1)
#define KB (BYTE * 1024)
#define MB (KB * 1024)
#define GB (MB * 1024)

void scoped_example();
void auto_example();
void shared_example();

#endif //HEADER_H