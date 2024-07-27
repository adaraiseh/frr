// SPDX-License-Identifier: GPL-2.0-or-later
/*
 * OSPF daemon CLI implementation.
 *
 * Copyright (C) 2024 Okda Networks
 *                    Amjad Daraiseh
 */

#include <zebra.h>

#include "if.h"
#include "vrf.h"
#include "log.h"
#include "prefix.h"
#include "command.h"
#include "northbound_cli.h"
#include "libfrr.h"

#include "ospfd/ospfd.h"
#include "ospfd/ospf_cli.h"
#include "ospfd/ospf_cli_clippy.c"

void ospf_cli_init(void)
{
}
