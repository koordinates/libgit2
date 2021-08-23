/*
 * Copyright (C) the libgit2 contributors. All rights reserved.
 *
 * This file is part of libgit2, distributed under the GNU GPL v2 with
 * a Linking Exception. For full terms see the included COPYING file.
 */
#ifndef INCLUDE_threadstate_h__
#define INCLUDE_threadstate_h__

#include "common.h"

typedef struct {
    unsigned pack_promisor:1;
} git_last_read_object_flags;

typedef struct {
	git_error *last_error;
	git_error error_t;
	git_str error_buf;
    char oid_fmt[GIT_OID_SHA1_HEXSIZE+1];
    git_last_read_object_flags last_read_object_flags;
} git_threadstate;

extern int git_threadstate_global_init(void);
extern git_threadstate *git_threadstate_get(void);

#define GIT_THREADSTATE (git_threadstate_get())

#endif
