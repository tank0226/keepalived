/*
 * Soft:        Keepalived is a failover program for the LVS project
 *              <www.linuxvirtualserver.org>. It monitor & manipulate
 *              a loadbalanced server pool using multi-layer checks.
 *
 * Part:        Linux namespace handling.
 *
 * Author:      Quentin Armitage <quentin@armitage.org.uk>
 *
 *              This program is distributed in the hope that it will be useful,
 *              but WITHOUT ANY WARRANTY; without even the implied warranty of
 *              MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.
 *              See the GNU General Public License for more details.
 *
 *              This program is free software; you can redistribute it and/or
 *              modify it under the terms of the GNU General Public License
 *              as published by the Free Software Foundation; either version
 *              2 of the License, or (at your option) any later version.
 *
 * Copyright (C) 2016-2016 Alexandre Cassen, <acassen@gmail.com>
 */

#ifndef _NAMESPACE_H
#define _NAMESPACE_H

#include <stdbool.h>

#ifdef LIBIPVS_USE_NL
#include <netlink/socket.h>
#ifdef _LIBNL_DYNAMIC_
#include "libnl_link.h"
#endif
#ifdef _HAVE_LIBNL1_
#define nl_sock         nl_handle
#endif
#endif

extern void free_dirname(void);
extern bool set_namespaces(const char*);
extern void clear_namespaces(void);
extern int set_netns_name(const char *);
extern void restore_net_namespace(int);
extern int socket_netns_name(const char *, int, int, int);

/* ipvs namespaces */
#ifdef LIBIPVS_USE_NL
extern int nl_ipvs_connect(const char *, struct nl_sock *);
#endif

#endif
