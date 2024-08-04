// SPDX-License-Identifier: GPL-2.0-or-later
/*
 * Copyright (C) 2024        Okda Networks
 *                           Amjad Daraiseh
 */

#include "northbound.h"

#include "ospfd/ospf_nb.h"
#include "ospfd/ospfd.h"
#include "ospfd/ospf_dump.h"
#include "ospfd/ospf_interface.h"
#include "ospfd/ospf_lsa.h"
#include "ospfd/ospf_lsdb.h"
#include "ospfd/ospf_neighbor.h"
#include "ospfd/ospf_asbr.h"
#include "ospfd/ospf_zebra.h"

#include "lib/vrf.h"
#include "defaults.h"
#include "zclient.h"

FRR_CFG_DEFAULT_BOOL(OSPF_LOG_ADJACENCY_CHANGES,
		     {
			     .val_bool = true,
			     .match_profile = "datacenter",
		     },
		     { .val_bool = false }, );

int routing_control_plane_protocols_name_validate(struct nb_cb_create_args *args)
{
	const char *vrf_name;
	const char *instance_str;
	unsigned short instance = 0;

	instance_str = yang_dnode_get_string(args->dnode, "name");
	instance = strtoul(instance_str, NULL, 10);
	vrf_name = yang_dnode_get_string(args->dnode, "vrf");

	/* check instance mode */
	if (!ospf_instance && instance) {
		snprintf(args->errmsg, args->errmsg_len,
			 "OSPF is not running in instance mode");
		return NB_ERR_VALIDATION;
	}

	/* check vrf on instance mode */
	if (instance && instance == ospf_instance) {
		if (strcmp(vrf_name, VRF_DEFAULT_NAME)) {
			snprintf(args->errmsg, args->errmsg_len,
				 "VRF is not supported in instance mode");
			return NB_ERR_VALIDATION;
		}
	}
	return NB_OK;
}

/*
 * XPath: /frr-interface:lib/interface/frr-ospfd:ospf/instance
 */
int lib_interface_ospf_instance_create(struct nb_cb_create_args *args)
{
	switch (args->event) {
	case NB_EV_VALIDATE:
	case NB_EV_PREPARE:
	case NB_EV_ABORT:
	case NB_EV_APPLY:
		/* TODO: implement me. */
		break;
	}

	return NB_OK;
}

int lib_interface_ospf_instance_destroy(struct nb_cb_destroy_args *args)
{
	switch (args->event) {
	case NB_EV_VALIDATE:
	case NB_EV_PREPARE:
	case NB_EV_ABORT:
	case NB_EV_APPLY:
		/* TODO: implement me. */
		break;
	}

	return NB_OK;
}

/*
 * XPath: /frr-interface:lib/interface/frr-ospfd:ospf/instance/bfd
 */
int lib_interface_ospf_instance_bfd_modify(struct nb_cb_modify_args *args)
{
	switch (args->event) {
	case NB_EV_VALIDATE:
	case NB_EV_PREPARE:
	case NB_EV_ABORT:
	case NB_EV_APPLY:
		/* TODO: implement me. */
		break;
	}

	return NB_OK;
}

/*
 * XPath: /frr-interface:lib/interface/frr-ospfd:ospf/instance/network
 */
int lib_interface_ospf_instance_network_modify(struct nb_cb_modify_args *args)
{
	switch (args->event) {
	case NB_EV_VALIDATE:
	case NB_EV_PREPARE:
	case NB_EV_ABORT:
	case NB_EV_APPLY:
		/* TODO: implement me. */
		break;
	}

	return NB_OK;
}

int lib_interface_ospf_instance_network_destroy(struct nb_cb_destroy_args *args)
{
	switch (args->event) {
	case NB_EV_VALIDATE:
	case NB_EV_PREPARE:
	case NB_EV_ABORT:
	case NB_EV_APPLY:
		/* TODO: implement me. */
		break;
	}

	return NB_OK;
}

/*
 * XPath: /frr-interface:lib/interface/frr-ospfd:ospf/instance/area
 */
int lib_interface_ospf_instance_area_modify(struct nb_cb_modify_args *args)
{
	switch (args->event) {
	case NB_EV_VALIDATE:
	case NB_EV_PREPARE:
	case NB_EV_ABORT:
	case NB_EV_APPLY:
		/* TODO: implement me. */
		break;
	}

	return NB_OK;
}

int lib_interface_ospf_instance_area_destroy(struct nb_cb_destroy_args *args)
{
	switch (args->event) {
	case NB_EV_VALIDATE:
	case NB_EV_PREPARE:
	case NB_EV_ABORT:
	case NB_EV_APPLY:
		/* TODO: implement me. */
		break;
	}

	return NB_OK;
}

/*
 * XPath: /frr-interface:lib/interface/frr-ospfd:ospf/instance/authentication
 */
int lib_interface_ospf_instance_authentication_create(
	struct nb_cb_create_args *args)
{
	switch (args->event) {
	case NB_EV_VALIDATE:
	case NB_EV_PREPARE:
	case NB_EV_ABORT:
	case NB_EV_APPLY:
		/* TODO: implement me. */
		break;
	}

	return NB_OK;
}

int lib_interface_ospf_instance_authentication_destroy(
	struct nb_cb_destroy_args *args)
{
	switch (args->event) {
	case NB_EV_VALIDATE:
	case NB_EV_PREPARE:
	case NB_EV_ABORT:
	case NB_EV_APPLY:
		/* TODO: implement me. */
		break;
	}

	return NB_OK;
}

/*
 * XPath: /frr-interface:lib/interface/frr-ospfd:ospf/instance/authentication/message-digest
 */
int lib_interface_ospf_instance_authentication_message_digest_modify(
	struct nb_cb_modify_args *args)
{
	switch (args->event) {
	case NB_EV_VALIDATE:
	case NB_EV_PREPARE:
	case NB_EV_ABORT:
	case NB_EV_APPLY:
		/* TODO: implement me. */
		break;
	}

	return NB_OK;
}

int lib_interface_ospf_instance_authentication_message_digest_destroy(
	struct nb_cb_destroy_args *args)
{
	switch (args->event) {
	case NB_EV_VALIDATE:
	case NB_EV_PREPARE:
	case NB_EV_ABORT:
	case NB_EV_APPLY:
		/* TODO: implement me. */
		break;
	}

	return NB_OK;
}

/*
 * XPath: /frr-interface:lib/interface/frr-ospfd:ospf/instance/authentication/null
 */
int lib_interface_ospf_instance_authentication_null_modify(
	struct nb_cb_modify_args *args)
{
	switch (args->event) {
	case NB_EV_VALIDATE:
	case NB_EV_PREPARE:
	case NB_EV_ABORT:
	case NB_EV_APPLY:
		/* TODO: implement me. */
		break;
	}

	return NB_OK;
}

int lib_interface_ospf_instance_authentication_null_destroy(
	struct nb_cb_destroy_args *args)
{
	switch (args->event) {
	case NB_EV_VALIDATE:
	case NB_EV_PREPARE:
	case NB_EV_ABORT:
	case NB_EV_APPLY:
		/* TODO: implement me. */
		break;
	}

	return NB_OK;
}

/*
 * XPath: /frr-interface:lib/interface/frr-ospfd:ospf/instance/message-digest-key
 */
int lib_interface_ospf_instance_message_digest_key_create(
	struct nb_cb_create_args *args)
{
	switch (args->event) {
	case NB_EV_VALIDATE:
	case NB_EV_PREPARE:
	case NB_EV_ABORT:
	case NB_EV_APPLY:
		/* TODO: implement me. */
		break;
	}

	return NB_OK;
}

int lib_interface_ospf_instance_message_digest_key_destroy(
	struct nb_cb_destroy_args *args)
{
	switch (args->event) {
	case NB_EV_VALIDATE:
	case NB_EV_PREPARE:
	case NB_EV_ABORT:
	case NB_EV_APPLY:
		/* TODO: implement me. */
		break;
	}

	return NB_OK;
}

/*
 * XPath: /frr-interface:lib/interface/frr-ospfd:ospf/instance/message-digest-key/mds-key
 */
int lib_interface_ospf_instance_message_digest_key_mds_key_modify(
	struct nb_cb_modify_args *args)
{
	switch (args->event) {
	case NB_EV_VALIDATE:
	case NB_EV_PREPARE:
	case NB_EV_ABORT:
	case NB_EV_APPLY:
		/* TODO: implement me. */
		break;
	}

	return NB_OK;
}

int lib_interface_ospf_instance_message_digest_key_mds_key_destroy(
	struct nb_cb_destroy_args *args)
{
	switch (args->event) {
	case NB_EV_VALIDATE:
	case NB_EV_PREPARE:
	case NB_EV_ABORT:
	case NB_EV_APPLY:
		/* TODO: implement me. */
		break;
	}

	return NB_OK;
}

/*
 * XPath: /frr-interface:lib/interface/frr-ospfd:ospf/instance/authentication-key
 */
int lib_interface_ospf_instance_authentication_key_modify(
	struct nb_cb_modify_args *args)
{
	switch (args->event) {
	case NB_EV_VALIDATE:
	case NB_EV_PREPARE:
	case NB_EV_ABORT:
	case NB_EV_APPLY:
		/* TODO: implement me. */
		break;
	}

	return NB_OK;
}

int lib_interface_ospf_instance_authentication_key_destroy(
	struct nb_cb_destroy_args *args)
{
	switch (args->event) {
	case NB_EV_VALIDATE:
	case NB_EV_PREPARE:
	case NB_EV_ABORT:
	case NB_EV_APPLY:
		/* TODO: implement me. */
		break;
	}

	return NB_OK;
}

/*
 * XPath: /frr-interface:lib/interface/frr-ospfd:ospf/instance/cost
 */
int lib_interface_ospf_instance_cost_modify(struct nb_cb_modify_args *args)
{
	switch (args->event) {
	case NB_EV_VALIDATE:
	case NB_EV_PREPARE:
	case NB_EV_ABORT:
	case NB_EV_APPLY:
		/* TODO: implement me. */
		break;
	}

	return NB_OK;
}

int lib_interface_ospf_instance_cost_destroy(struct nb_cb_destroy_args *args)
{
	switch (args->event) {
	case NB_EV_VALIDATE:
	case NB_EV_PREPARE:
	case NB_EV_ABORT:
	case NB_EV_APPLY:
		/* TODO: implement me. */
		break;
	}

	return NB_OK;
}

/*
 * XPath: /frr-interface:lib/interface/frr-ospfd:ospf/instance/dead-interval/interval
 */
int lib_interface_ospf_instance_dead_interval_interval_modify(
	struct nb_cb_modify_args *args)
{
	switch (args->event) {
	case NB_EV_VALIDATE:
	case NB_EV_PREPARE:
	case NB_EV_ABORT:
	case NB_EV_APPLY:
		/* TODO: implement me. */
		break;
	}

	return NB_OK;
}

int lib_interface_ospf_instance_dead_interval_interval_destroy(
	struct nb_cb_destroy_args *args)
{
	switch (args->event) {
	case NB_EV_VALIDATE:
	case NB_EV_PREPARE:
	case NB_EV_ABORT:
	case NB_EV_APPLY:
		/* TODO: implement me. */
		break;
	}

	return NB_OK;
}

/*
 * XPath: /frr-interface:lib/interface/frr-ospfd:ospf/instance/dead-interval/minimal/hello-multiplier
 */
int lib_interface_ospf_instance_dead_interval_minimal_hello_multiplier_modify(
	struct nb_cb_modify_args *args)
{
	switch (args->event) {
	case NB_EV_VALIDATE:
	case NB_EV_PREPARE:
	case NB_EV_ABORT:
	case NB_EV_APPLY:
		/* TODO: implement me. */
		break;
	}

	return NB_OK;
}

int lib_interface_ospf_instance_dead_interval_minimal_hello_multiplier_destroy(
	struct nb_cb_destroy_args *args)
{
	switch (args->event) {
	case NB_EV_VALIDATE:
	case NB_EV_PREPARE:
	case NB_EV_ABORT:
	case NB_EV_APPLY:
		/* TODO: implement me. */
		break;
	}

	return NB_OK;
}

/*
 * XPath: /frr-interface:lib/interface/frr-ospfd:ospf/instance/hello-interval
 */
int lib_interface_ospf_instance_hello_interval_modify(
	struct nb_cb_modify_args *args)
{
	switch (args->event) {
	case NB_EV_VALIDATE:
	case NB_EV_PREPARE:
	case NB_EV_ABORT:
	case NB_EV_APPLY:
		/* TODO: implement me. */
		break;
	}

	return NB_OK;
}

int lib_interface_ospf_instance_hello_interval_destroy(
	struct nb_cb_destroy_args *args)
{
	switch (args->event) {
	case NB_EV_VALIDATE:
	case NB_EV_PREPARE:
	case NB_EV_ABORT:
	case NB_EV_APPLY:
		/* TODO: implement me. */
		break;
	}

	return NB_OK;
}

/*
 * XPath: /frr-interface:lib/interface/frr-ospfd:ospf/instance/retransmit-interval
 */
int lib_interface_ospf_instance_retransmit_interval_modify(
	struct nb_cb_modify_args *args)
{
	switch (args->event) {
	case NB_EV_VALIDATE:
	case NB_EV_PREPARE:
	case NB_EV_ABORT:
	case NB_EV_APPLY:
		/* TODO: implement me. */
		break;
	}

	return NB_OK;
}

int lib_interface_ospf_instance_retransmit_interval_destroy(
	struct nb_cb_destroy_args *args)
{
	switch (args->event) {
	case NB_EV_VALIDATE:
	case NB_EV_PREPARE:
	case NB_EV_ABORT:
	case NB_EV_APPLY:
		/* TODO: implement me. */
		break;
	}

	return NB_OK;
}

/*
 * XPath: /frr-interface:lib/interface/frr-ospfd:ospf/instance/transmit-delay
 */
int lib_interface_ospf_instance_transmit_delay_modify(
	struct nb_cb_modify_args *args)
{
	switch (args->event) {
	case NB_EV_VALIDATE:
	case NB_EV_PREPARE:
	case NB_EV_ABORT:
	case NB_EV_APPLY:
		/* TODO: implement me. */
		break;
	}

	return NB_OK;
}

int lib_interface_ospf_instance_transmit_delay_destroy(
	struct nb_cb_destroy_args *args)
{
	switch (args->event) {
	case NB_EV_VALIDATE:
	case NB_EV_PREPARE:
	case NB_EV_ABORT:
	case NB_EV_APPLY:
		/* TODO: implement me. */
		break;
	}

	return NB_OK;
}

/*
 * XPath: /frr-interface:lib/interface/frr-ospfd:ospf/instance/mtu-ignore
 */
int lib_interface_ospf_instance_mtu_ignore_modify(struct nb_cb_modify_args *args)
{
	switch (args->event) {
	case NB_EV_VALIDATE:
	case NB_EV_PREPARE:
	case NB_EV_ABORT:
	case NB_EV_APPLY:
		/* TODO: implement me. */
		break;
	}

	return NB_OK;
}

int lib_interface_ospf_instance_mtu_ignore_destroy(struct nb_cb_destroy_args *args)
{
	switch (args->event) {
	case NB_EV_VALIDATE:
	case NB_EV_PREPARE:
	case NB_EV_ABORT:
	case NB_EV_APPLY:
		/* TODO: implement me. */
		break;
	}

	return NB_OK;
}

/*
 * XPath: /frr-interface:lib/interface/frr-ospfd:ospf/instance/priority
 */
int lib_interface_ospf_instance_priority_modify(struct nb_cb_modify_args *args)
{
	switch (args->event) {
	case NB_EV_VALIDATE:
	case NB_EV_PREPARE:
	case NB_EV_ABORT:
	case NB_EV_APPLY:
		/* TODO: implement me. */
		break;
	}

	return NB_OK;
}

int lib_interface_ospf_instance_priority_destroy(struct nb_cb_destroy_args *args)
{
	switch (args->event) {
	case NB_EV_VALIDATE:
	case NB_EV_PREPARE:
	case NB_EV_ABORT:
	case NB_EV_APPLY:
		/* TODO: implement me. */
		break;
	}

	return NB_OK;
}

/*
 * XPath: /frr-interface:lib/interface/frr-ospfd:ospf/instance/interface-address
 */
int lib_interface_ospf_instance_interface_address_create(
	struct nb_cb_create_args *args)
{
	switch (args->event) {
	case NB_EV_VALIDATE:
	case NB_EV_PREPARE:
	case NB_EV_ABORT:
	case NB_EV_APPLY:
		/* TODO: implement me. */
		break;
	}

	return NB_OK;
}

int lib_interface_ospf_instance_interface_address_destroy(
	struct nb_cb_destroy_args *args)
{
	switch (args->event) {
	case NB_EV_VALIDATE:
	case NB_EV_PREPARE:
	case NB_EV_ABORT:
	case NB_EV_APPLY:
		/* TODO: implement me. */
		break;
	}

	return NB_OK;
}

/*
 * XPath: /frr-interface:lib/interface/frr-ospfd:ospf/instance/interface-address/area
 */
int lib_interface_ospf_instance_interface_address_area_modify(
	struct nb_cb_modify_args *args)
{
	switch (args->event) {
	case NB_EV_VALIDATE:
	case NB_EV_PREPARE:
	case NB_EV_ABORT:
	case NB_EV_APPLY:
		/* TODO: implement me. */
		break;
	}

	return NB_OK;
}

int lib_interface_ospf_instance_interface_address_area_destroy(
	struct nb_cb_destroy_args *args)
{
	switch (args->event) {
	case NB_EV_VALIDATE:
	case NB_EV_PREPARE:
	case NB_EV_ABORT:
	case NB_EV_APPLY:
		/* TODO: implement me. */
		break;
	}

	return NB_OK;
}

/*
 * XPath: /frr-interface:lib/interface/frr-ospfd:ospf/instance/interface-address/authentication
 */
int lib_interface_ospf_instance_interface_address_authentication_create(
	struct nb_cb_create_args *args)
{
	switch (args->event) {
	case NB_EV_VALIDATE:
	case NB_EV_PREPARE:
	case NB_EV_ABORT:
	case NB_EV_APPLY:
		/* TODO: implement me. */
		break;
	}

	return NB_OK;
}

int lib_interface_ospf_instance_interface_address_authentication_destroy(
	struct nb_cb_destroy_args *args)
{
	switch (args->event) {
	case NB_EV_VALIDATE:
	case NB_EV_PREPARE:
	case NB_EV_ABORT:
	case NB_EV_APPLY:
		/* TODO: implement me. */
		break;
	}

	return NB_OK;
}

/*
 * XPath: /frr-interface:lib/interface/frr-ospfd:ospf/instance/interface-address/authentication/message-digest
 */
int lib_interface_ospf_instance_interface_address_authentication_message_digest_modify(
	struct nb_cb_modify_args *args)
{
	switch (args->event) {
	case NB_EV_VALIDATE:
	case NB_EV_PREPARE:
	case NB_EV_ABORT:
	case NB_EV_APPLY:
		/* TODO: implement me. */
		break;
	}

	return NB_OK;
}

int lib_interface_ospf_instance_interface_address_authentication_message_digest_destroy(
	struct nb_cb_destroy_args *args)
{
	switch (args->event) {
	case NB_EV_VALIDATE:
	case NB_EV_PREPARE:
	case NB_EV_ABORT:
	case NB_EV_APPLY:
		/* TODO: implement me. */
		break;
	}

	return NB_OK;
}

/*
 * XPath: /frr-interface:lib/interface/frr-ospfd:ospf/instance/interface-address/authentication/null
 */
int lib_interface_ospf_instance_interface_address_authentication_null_modify(
	struct nb_cb_modify_args *args)
{
	switch (args->event) {
	case NB_EV_VALIDATE:
	case NB_EV_PREPARE:
	case NB_EV_ABORT:
	case NB_EV_APPLY:
		/* TODO: implement me. */
		break;
	}

	return NB_OK;
}

int lib_interface_ospf_instance_interface_address_authentication_null_destroy(
	struct nb_cb_destroy_args *args)
{
	switch (args->event) {
	case NB_EV_VALIDATE:
	case NB_EV_PREPARE:
	case NB_EV_ABORT:
	case NB_EV_APPLY:
		/* TODO: implement me. */
		break;
	}

	return NB_OK;
}

/*
 * XPath: /frr-interface:lib/interface/frr-ospfd:ospf/instance/interface-address/message-digest-key
 */
int lib_interface_ospf_instance_interface_address_message_digest_key_create(
	struct nb_cb_create_args *args)
{
	switch (args->event) {
	case NB_EV_VALIDATE:
	case NB_EV_PREPARE:
	case NB_EV_ABORT:
	case NB_EV_APPLY:
		/* TODO: implement me. */
		break;
	}

	return NB_OK;
}

int lib_interface_ospf_instance_interface_address_message_digest_key_destroy(
	struct nb_cb_destroy_args *args)
{
	switch (args->event) {
	case NB_EV_VALIDATE:
	case NB_EV_PREPARE:
	case NB_EV_ABORT:
	case NB_EV_APPLY:
		/* TODO: implement me. */
		break;
	}

	return NB_OK;
}

/*
 * XPath: /frr-interface:lib/interface/frr-ospfd:ospf/instance/interface-address/message-digest-key/mds-key
 */
int lib_interface_ospf_instance_interface_address_message_digest_key_mds_key_modify(
	struct nb_cb_modify_args *args)
{
	switch (args->event) {
	case NB_EV_VALIDATE:
	case NB_EV_PREPARE:
	case NB_EV_ABORT:
	case NB_EV_APPLY:
		/* TODO: implement me. */
		break;
	}

	return NB_OK;
}

int lib_interface_ospf_instance_interface_address_message_digest_key_mds_key_destroy(
	struct nb_cb_destroy_args *args)
{
	switch (args->event) {
	case NB_EV_VALIDATE:
	case NB_EV_PREPARE:
	case NB_EV_ABORT:
	case NB_EV_APPLY:
		/* TODO: implement me. */
		break;
	}

	return NB_OK;
}

/*
 * XPath: /frr-interface:lib/interface/frr-ospfd:ospf/instance/interface-address/authentication-key
 */
int lib_interface_ospf_instance_interface_address_authentication_key_modify(
	struct nb_cb_modify_args *args)
{
	switch (args->event) {
	case NB_EV_VALIDATE:
	case NB_EV_PREPARE:
	case NB_EV_ABORT:
	case NB_EV_APPLY:
		/* TODO: implement me. */
		break;
	}

	return NB_OK;
}

int lib_interface_ospf_instance_interface_address_authentication_key_destroy(
	struct nb_cb_destroy_args *args)
{
	switch (args->event) {
	case NB_EV_VALIDATE:
	case NB_EV_PREPARE:
	case NB_EV_ABORT:
	case NB_EV_APPLY:
		/* TODO: implement me. */
		break;
	}

	return NB_OK;
}

/*
 * XPath: /frr-interface:lib/interface/frr-ospfd:ospf/instance/interface-address/cost
 */
int lib_interface_ospf_instance_interface_address_cost_modify(
	struct nb_cb_modify_args *args)
{
	switch (args->event) {
	case NB_EV_VALIDATE:
	case NB_EV_PREPARE:
	case NB_EV_ABORT:
	case NB_EV_APPLY:
		/* TODO: implement me. */
		break;
	}

	return NB_OK;
}

int lib_interface_ospf_instance_interface_address_cost_destroy(
	struct nb_cb_destroy_args *args)
{
	switch (args->event) {
	case NB_EV_VALIDATE:
	case NB_EV_PREPARE:
	case NB_EV_ABORT:
	case NB_EV_APPLY:
		/* TODO: implement me. */
		break;
	}

	return NB_OK;
}

/*
 * XPath: /frr-interface:lib/interface/frr-ospfd:ospf/instance/interface-address/dead-interval/interval
 */
int lib_interface_ospf_instance_interface_address_dead_interval_interval_modify(
	struct nb_cb_modify_args *args)
{
	switch (args->event) {
	case NB_EV_VALIDATE:
	case NB_EV_PREPARE:
	case NB_EV_ABORT:
	case NB_EV_APPLY:
		/* TODO: implement me. */
		break;
	}

	return NB_OK;
}

int lib_interface_ospf_instance_interface_address_dead_interval_interval_destroy(
	struct nb_cb_destroy_args *args)
{
	switch (args->event) {
	case NB_EV_VALIDATE:
	case NB_EV_PREPARE:
	case NB_EV_ABORT:
	case NB_EV_APPLY:
		/* TODO: implement me. */
		break;
	}

	return NB_OK;
}

/*
 * XPath: /frr-interface:lib/interface/frr-ospfd:ospf/instance/interface-address/dead-interval/minimal/hello-multiplier
 */
int lib_interface_ospf_instance_interface_address_dead_interval_minimal_hello_multiplier_modify(
	struct nb_cb_modify_args *args)
{
	switch (args->event) {
	case NB_EV_VALIDATE:
	case NB_EV_PREPARE:
	case NB_EV_ABORT:
	case NB_EV_APPLY:
		/* TODO: implement me. */
		break;
	}

	return NB_OK;
}

int lib_interface_ospf_instance_interface_address_dead_interval_minimal_hello_multiplier_destroy(
	struct nb_cb_destroy_args *args)
{
	switch (args->event) {
	case NB_EV_VALIDATE:
	case NB_EV_PREPARE:
	case NB_EV_ABORT:
	case NB_EV_APPLY:
		/* TODO: implement me. */
		break;
	}

	return NB_OK;
}

/*
 * XPath: /frr-interface:lib/interface/frr-ospfd:ospf/instance/interface-address/hello-interval
 */
int lib_interface_ospf_instance_interface_address_hello_interval_modify(
	struct nb_cb_modify_args *args)
{
	switch (args->event) {
	case NB_EV_VALIDATE:
	case NB_EV_PREPARE:
	case NB_EV_ABORT:
	case NB_EV_APPLY:
		/* TODO: implement me. */
		break;
	}

	return NB_OK;
}

int lib_interface_ospf_instance_interface_address_hello_interval_destroy(
	struct nb_cb_destroy_args *args)
{
	switch (args->event) {
	case NB_EV_VALIDATE:
	case NB_EV_PREPARE:
	case NB_EV_ABORT:
	case NB_EV_APPLY:
		/* TODO: implement me. */
		break;
	}

	return NB_OK;
}

/*
 * XPath: /frr-interface:lib/interface/frr-ospfd:ospf/instance/interface-address/retransmit-interval
 */
int lib_interface_ospf_instance_interface_address_retransmit_interval_modify(
	struct nb_cb_modify_args *args)
{
	switch (args->event) {
	case NB_EV_VALIDATE:
	case NB_EV_PREPARE:
	case NB_EV_ABORT:
	case NB_EV_APPLY:
		/* TODO: implement me. */
		break;
	}

	return NB_OK;
}

int lib_interface_ospf_instance_interface_address_retransmit_interval_destroy(
	struct nb_cb_destroy_args *args)
{
	switch (args->event) {
	case NB_EV_VALIDATE:
	case NB_EV_PREPARE:
	case NB_EV_ABORT:
	case NB_EV_APPLY:
		/* TODO: implement me. */
		break;
	}

	return NB_OK;
}

/*
 * XPath: /frr-interface:lib/interface/frr-ospfd:ospf/instance/interface-address/transmit-delay
 */
int lib_interface_ospf_instance_interface_address_transmit_delay_modify(
	struct nb_cb_modify_args *args)
{
	switch (args->event) {
	case NB_EV_VALIDATE:
	case NB_EV_PREPARE:
	case NB_EV_ABORT:
	case NB_EV_APPLY:
		/* TODO: implement me. */
		break;
	}

	return NB_OK;
}

int lib_interface_ospf_instance_interface_address_transmit_delay_destroy(
	struct nb_cb_destroy_args *args)
{
	switch (args->event) {
	case NB_EV_VALIDATE:
	case NB_EV_PREPARE:
	case NB_EV_ABORT:
	case NB_EV_APPLY:
		/* TODO: implement me. */
		break;
	}

	return NB_OK;
}

/*
 * XPath: /frr-interface:lib/interface/frr-ospfd:ospf/instance/interface-address/mtu-ignore
 */
int lib_interface_ospf_instance_interface_address_mtu_ignore_modify(
	struct nb_cb_modify_args *args)
{
	switch (args->event) {
	case NB_EV_VALIDATE:
	case NB_EV_PREPARE:
	case NB_EV_ABORT:
	case NB_EV_APPLY:
		/* TODO: implement me. */
		break;
	}

	return NB_OK;
}

int lib_interface_ospf_instance_interface_address_mtu_ignore_destroy(
	struct nb_cb_destroy_args *args)
{
	switch (args->event) {
	case NB_EV_VALIDATE:
	case NB_EV_PREPARE:
	case NB_EV_ABORT:
	case NB_EV_APPLY:
		/* TODO: implement me. */
		break;
	}

	return NB_OK;
}

/*
 * XPath: /frr-interface:lib/interface/frr-ospfd:ospf/instance/interface-address/priority
 */
int lib_interface_ospf_instance_interface_address_priority_modify(
	struct nb_cb_modify_args *args)
{
	switch (args->event) {
	case NB_EV_VALIDATE:
	case NB_EV_PREPARE:
	case NB_EV_ABORT:
	case NB_EV_APPLY:
		/* TODO: implement me. */
		break;
	}

	return NB_OK;
}

int lib_interface_ospf_instance_interface_address_priority_destroy(
	struct nb_cb_destroy_args *args)
{
	switch (args->event) {
	case NB_EV_VALIDATE:
	case NB_EV_PREPARE:
	case NB_EV_ABORT:
	case NB_EV_APPLY:
		/* TODO: implement me. */
		break;
	}

	return NB_OK;
}

/*
 * XPath:
 * /frr-routing:routing/control-plane-protocols/control-plane-protocol
 */
int routing_control_plane_protocols_ospfd_create(struct nb_cb_create_args *args)
{
	const char *vrf_name;
	unsigned short instance = 0;
	bool created = false;
	struct ospf *ospf;

	vrf_name = yang_dnode_get_string(args->dnode, "vrf");
	instance = strtoul(yang_dnode_get_string(args->dnode, "name"), NULL, 10);

	/* not my instance */
	if (instance != ospf_instance)
		return NB_ERR_NO_CHANGES;

	ospf = ospf_get(instance, vrf_name, &created);
	nb_running_set_entry(args->dnode, ospf);
	if (created) {
		if (DFLT_OSPF_LOG_ADJACENCY_CHANGES)
			SET_FLAG(ospf->config, OSPF_LOG_ADJACENCY_CHANGES);
	} else {
		return NB_ERR_NO_CHANGES;
	}

	if (IS_DEBUG_OSPF_EVENT)
		zlog_debug("Config command 'router ospf %d' received, vrf %s id %u oi_running %u",
			   ospf->instance, ospf_get_name(ospf), ospf->vrf_id,
			   ospf->oi_running);

	return NB_OK;
}

int routing_control_plane_protocols_ospfd_destroy(struct nb_cb_destroy_args *args)
{
	struct ospf *ospf;

	ospf = nb_running_get_entry(args->dnode, NULL, false);
	if (ospf) {
		if (ospf->instance != ospf_instance)
			return NB_ERR_NO_CHANGES;
		else {
			if (ospf->gr_info.restart_support)
				ospf_gr_nvm_delete(ospf);

			ospf_finish(ospf);
		}
	} else {
		return NB_ERR_NOT_FOUND;
	}

	return NB_OK;
}

/*
 * XPath: /frr-routing:routing/control-plane-protocols/control-plane-protocol/frr-ospfd:ospf/auto-cost-reference-bandwidth
 */
int routing_control_plane_protocols_control_plane_protocol_ospf_auto_cost_reference_bandwidth_modify(
	struct nb_cb_modify_args *args)
{
	struct ospf *ospf;
	struct vrf *vrf;
	uint32_t refbw;
	struct interface *ifp;

	switch (args->event) {
	case NB_EV_VALIDATE:
	case NB_EV_PREPARE:
	case NB_EV_ABORT:
		break;
	case NB_EV_APPLY:
		ospf = nb_running_get_entry(args->dnode, NULL, true);
		if (ospf->instance != ospf_instance)
			return NB_OK;

		vrf = vrf_lookup_by_id(ospf->vrf_id);
		refbw = yang_dnode_get_uint32(args->dnode, NULL);

		/* If reference bandwidth is changed. */
		if ((refbw) == ospf->ref_bandwidth)
			return NB_ERR_NO_CHANGES;

		ospf->ref_bandwidth = refbw;
		FOR_ALL_INTERFACES (vrf, ifp)
			ospf_if_recalculate_output_cost(ifp);
		break;
	}

	return NB_OK;
}

int routing_control_plane_protocols_control_plane_protocol_ospf_auto_cost_reference_bandwidth_destroy(
	struct nb_cb_destroy_args *args)
{
	struct ospf *ospf;
	struct vrf *vrf;
	struct interface *ifp;

	switch (args->event) {
	case NB_EV_VALIDATE:
	case NB_EV_PREPARE:
	case NB_EV_ABORT:
		break;
	case NB_EV_APPLY:
		ospf = nb_running_get_entry(args->dnode, NULL, true);
		if (ospf->instance != ospf_instance)
			return NB_OK;

		vrf = vrf_lookup_by_id(ospf->vrf_id);
		if (ospf->ref_bandwidth == OSPF_DEFAULT_REF_BANDWIDTH) {
			return NB_OK;
		}

		ospf->ref_bandwidth = OSPF_DEFAULT_REF_BANDWIDTH;
		FOR_ALL_INTERFACES (vrf, ifp)
			ospf_if_recalculate_output_cost(ifp);
		break;
	}

	return NB_OK;
}

/*
 * XPath: /frr-routing:routing/control-plane-protocols/control-plane-protocol/frr-ospfd:ospf/use-arp
 */
int routing_control_plane_protocols_control_plane_protocol_ospf_use_arp_modify(
	struct nb_cb_modify_args *args)
{
	struct ospf *ospf;
	bool use_arp;
	switch (args->event) {
	case NB_EV_VALIDATE:
	case NB_EV_PREPARE:
	case NB_EV_ABORT:
		break;
	case NB_EV_APPLY:
		ospf = nb_running_get_entry(args->dnode, NULL, true);
		if (ospf->instance != ospf_instance)
			return NB_OK;

		use_arp = yang_dnode_get_bool(args->dnode, NULL);
		ospf->proactive_arp = use_arp;
		break;
	}

	return NB_OK;
}

/*
 * XPath: /frr-routing:routing/control-plane-protocols/control-plane-protocol/frr-ospfd:ospf/capability-opaque
 */
int routing_control_plane_protocols_control_plane_protocol_ospf_capability_opaque_modify(
	struct nb_cb_modify_args *args)
{
	struct ospf *ospf;
	bool opaque_capable;
	switch (args->event) {
	case NB_EV_VALIDATE:
	case NB_EV_PREPARE:
	case NB_EV_ABORT:
		break;
	case NB_EV_APPLY:
		ospf = nb_running_get_entry(args->dnode, NULL, true);
		if (ospf->instance != ospf_instance)
			return NB_OK;

		opaque_capable = yang_dnode_get_bool(args->dnode, NULL);

		/* Check that OSPF is using default VRF */
		if (ospf->vrf_id != VRF_DEFAULT) {
			snprintf(args->errmsg, args->errmsg_len,
				 "OSPF Opaque LSA is only supported in default VRF");
			return NB_ERR;
		}
		if (opaque_capable) {
			/* Turn on the "master switch" of opaque-lsa capability. */
			if (!CHECK_FLAG(ospf->config, OSPF_OPAQUE_CAPABLE)) {
				if (IS_DEBUG_OSPF_EVENT)
					zlog_debug(
						"Opaque capability: OFF -> ON");

				SET_FLAG(ospf->config, OSPF_OPAQUE_CAPABLE);
				ospf_renegotiate_optional_capabilities(ospf);
			}
		} else {
			/* Turn off the "master switch" of opaque-lsa capability. */
			if (CHECK_FLAG(ospf->config, OSPF_OPAQUE_CAPABLE)) {
				if (IS_DEBUG_OSPF_EVENT)
					zlog_debug(
						"Opaque capability: ON -> OFF");

				UNSET_FLAG(ospf->config, OSPF_OPAQUE_CAPABLE);
				ospf_renegotiate_optional_capabilities(ospf);
			}
		}
		break;
	}

	return NB_OK;
}

/*
 * XPath: /frr-routing:routing/control-plane-protocols/control-plane-protocol/frr-ospfd:ospf/compatible-rfc1583
 */
int routing_control_plane_protocols_control_plane_protocol_ospf_compatible_rfc1583_modify(
	struct nb_cb_modify_args *args)
{
	struct ospf *ospf;
	bool rfc1583_compatible;
	switch (args->event) {
	case NB_EV_VALIDATE:
	case NB_EV_PREPARE:
	case NB_EV_ABORT:
		break;
	case NB_EV_APPLY:
		ospf = nb_running_get_entry(args->dnode, NULL, true);
		if (ospf->instance != ospf_instance)
			return NB_OK;

		rfc1583_compatible = yang_dnode_get_bool(args->dnode, NULL);
		if (rfc1583_compatible) {
			if (!CHECK_FLAG(ospf->config, OSPF_RFC1583_COMPATIBLE)) {
				SET_FLAG(ospf->config, OSPF_RFC1583_COMPATIBLE);
				ospf_spf_calculate_schedule(ospf,
							    SPF_FLAG_CONFIG_CHANGE);
			}
		} else {
			if (CHECK_FLAG(ospf->config, OSPF_RFC1583_COMPATIBLE)) {
				UNSET_FLAG(ospf->config,
					   OSPF_RFC1583_COMPATIBLE);
				ospf_spf_calculate_schedule(ospf,
							    SPF_FLAG_CONFIG_CHANGE);
			}
		}
		break;
	}

	return NB_OK;
}

int routing_control_plane_protocols_control_plane_protocol_ospf_compatible_rfc1583_destroy(
	struct nb_cb_destroy_args *args)
{
	struct ospf *ospf;
	switch (args->event) {
	case NB_EV_VALIDATE:
	case NB_EV_PREPARE:
	case NB_EV_ABORT:
		break;
	case NB_EV_APPLY:
		ospf = nb_running_get_entry(args->dnode, NULL, true);
		if (ospf->instance != ospf_instance)
			return NB_OK;

		if (CHECK_FLAG(ospf->config, OSPF_RFC1583_COMPATIBLE)) {
			UNSET_FLAG(ospf->config, OSPF_RFC1583_COMPATIBLE);
			ospf_spf_calculate_schedule(ospf,
						    SPF_FLAG_CONFIG_CHANGE);
		}
		break;
	}

	return NB_OK;
}

/*
 * XPath: /frr-routing:routing/control-plane-protocols/control-plane-protocol/frr-ospfd:ospf/default-metric
 */
int routing_control_plane_protocols_control_plane_protocol_ospf_default_metric_modify(
	struct nb_cb_modify_args *args)
{
	struct ospf *ospf;
	int metric = -1;
	switch (args->event) {
	case NB_EV_VALIDATE:
	case NB_EV_PREPARE:
	case NB_EV_ABORT:
		break;
	case NB_EV_APPLY:
		ospf = nb_running_get_entry(args->dnode, NULL, true);
		if (ospf->instance != ospf_instance)
			return NB_OK;

		metric = yang_dnode_get_uint32(args->dnode, NULL);
		ospf->default_metric = metric;
		ospf_schedule_asbr_redist_update(ospf);
		break;
	}

	return NB_OK;
}

int routing_control_plane_protocols_control_plane_protocol_ospf_default_metric_destroy(
	struct nb_cb_destroy_args *args)
{
	struct ospf *ospf;
	switch (args->event) {
	case NB_EV_VALIDATE:
	case NB_EV_PREPARE:
	case NB_EV_ABORT:
		break;
	case NB_EV_APPLY:
		ospf = nb_running_get_entry(args->dnode, NULL, true);
		if (ospf->instance != ospf_instance)
			return NB_OK;

		ospf->default_metric = -1;
		ospf_schedule_asbr_redist_update(ospf);
		break;
	}

	return NB_OK;
}

/*
 * XPath: /frr-routing:routing/control-plane-protocols/control-plane-protocol/frr-ospfd:ospf/write-multiplier
 */
int routing_control_plane_protocols_control_plane_protocol_ospf_write_multiplier_modify(
	struct nb_cb_modify_args *args)
{
	struct ospf *ospf;
	switch (args->event) {
	case NB_EV_VALIDATE:
	case NB_EV_PREPARE:
	case NB_EV_ABORT:
		break;
	case NB_EV_APPLY:
		uint32_t write_oi_count;
		ospf = nb_running_get_entry(args->dnode, NULL, true);
		if (ospf->instance != ospf_instance)
			return NB_OK;

		write_oi_count = yang_dnode_get_uint8(args->dnode, NULL);
		ospf->write_oi_count = write_oi_count;
		break;
	}

	return NB_OK;
}

int routing_control_plane_protocols_control_plane_protocol_ospf_write_multiplier_destroy(
	struct nb_cb_destroy_args *args)
{
	struct ospf *ospf;
	switch (args->event) {
	case NB_EV_VALIDATE:
	case NB_EV_PREPARE:
	case NB_EV_ABORT:
		break;
	case NB_EV_APPLY:
		ospf = nb_running_get_entry(args->dnode, NULL, true);
		if (ospf->instance != ospf_instance)
			return NB_OK;

		ospf->write_oi_count = OSPF_WRITE_INTERFACE_COUNT_DEFAULT;
		break;
	}

	return NB_OK;
}

/*
 * XPath: /frr-routing:routing/control-plane-protocols/control-plane-protocol/frr-ospfd:ospf/router-info
 */
int routing_control_plane_protocols_control_plane_protocol_ospf_router_info_modify(
	struct nb_cb_modify_args *args)
{
	switch (args->event) {
	case NB_EV_VALIDATE:
	case NB_EV_PREPARE:
	case NB_EV_ABORT:
		break;
	case NB_EV_APPLY:
		/* TODO: implement me. */
		break;
	}

	return NB_OK;
}

int routing_control_plane_protocols_control_plane_protocol_ospf_router_info_destroy(
	struct nb_cb_destroy_args *args)
{
	switch (args->event) {
	case NB_EV_VALIDATE:
	case NB_EV_PREPARE:
	case NB_EV_ABORT:
		break;
	case NB_EV_APPLY:
		/* TODO: implement me. */
		break;
	}

	return NB_OK;
}

/*
 * XPath: /frr-routing:routing/control-plane-protocols/control-plane-protocol/frr-ospfd:ospf/default-information
 */
void routing_control_plane_protocols_control_plane_protocol_ospf_default_information_apply_finish(
	struct nb_cb_apply_finish_args *args)
{
	struct ospf *ospf;
	ospf = nb_running_get_entry(args->dnode, NULL, true);

	int default_originate = DEFAULT_ORIGINATE_ZEBRA;
	int type = -1;
	int metric = -1;
	struct ospf_redist *red;
	int cur_originate = ospf->default_originate;
	bool sameRtmap = false;
	const char *rtmap = NULL;
	bool originate = false;
	
	if (yang_dnode_exists(args->dnode, "originate"))
		originate = yang_dnode_get_bool(args->dnode, "originate");

	/* check if "originate" was enabled */
	if (originate) {
		red = ospf_redist_add(ospf, DEFAULT_ROUTE, 0);
		/* Check whether "always" was specified */
		if (yang_dnode_exists(args->dnode, "always")) {
			bool always = yang_dnode_get_bool(args->dnode, "always");
			if (always)
				default_originate = DEFAULT_ORIGINATE_ALWAYS;
		}

		if (yang_dnode_exists(args->dnode, "metric"))
			metric = yang_dnode_get_uint32(args->dnode, "metric");

		if (yang_dnode_exists(args->dnode, "metric-type"))
			type = yang_dnode_get_enum(args->dnode, "metric-type");

		if (yang_dnode_exists(args->dnode, "route-map"))
			rtmap = yang_dnode_get_string(args->dnode, "route-map");

		/* To check if user is providing same route map */
		if ((!rtmap && !ROUTEMAP_NAME(red)) ||
		    (rtmap && ROUTEMAP_NAME(red) &&
		     (strcmp(rtmap, ROUTEMAP_NAME(red)) == 0)))
			sameRtmap = true;

		/* Don't allow if the same lsa is already originated. */
		if ((sameRtmap) && (red->dmetric.type == type) &&
		    (red->dmetric.value == metric) &&
		    (cur_originate == default_originate))
			return;

		/* Updating Metric details */
		red->dmetric.type = type;
		red->dmetric.value = metric;

		/* updating route map details */
		if (rtmap)
			ospf_routemap_set(red, rtmap);
		else
			ospf_routemap_unset(red);

		ospf_redistribute_default_set(ospf, default_originate, type,
					      metric);
	} else {
		/* originate is disabled */
		red = ospf_redist_lookup(ospf, DEFAULT_ROUTE, 0);
		if (!red)
			return;

		ospf_routemap_unset(red);
		ospf_redist_del(ospf, DEFAULT_ROUTE, 0);

		ospf_redistribute_default_set(ospf, DEFAULT_ORIGINATE_NONE, 0,
					      0);
	}
}

/*
 * XPath: /frr-routing:routing/control-plane-protocols/control-plane-protocol/frr-ospfd:ospf/default-information/originate
 */
int routing_control_plane_protocols_control_plane_protocol_ospf_default_information_originate_modify(
	struct nb_cb_modify_args *args)
{
	/* implmented in default_information_apply_finish */
	return NB_OK;
}

int routing_control_plane_protocols_control_plane_protocol_ospf_default_information_originate_destroy(
	struct nb_cb_destroy_args *args)
{
	/* implmented in default_information_apply_finish */
	return NB_OK;
}

/*
 * XPath: /frr-routing:routing/control-plane-protocols/control-plane-protocol/frr-ospfd:ospf/default-information/always
 */
int routing_control_plane_protocols_control_plane_protocol_ospf_default_information_always_modify(
	struct nb_cb_modify_args *args)
{
	/* implmented in default_information_apply_finish */
	return NB_OK;
}

int routing_control_plane_protocols_control_plane_protocol_ospf_default_information_always_destroy(
	struct nb_cb_destroy_args *args)
{
	/* implmented in default_information_apply_finish */
	return NB_OK;
}

/*
 * XPath: /frr-routing:routing/control-plane-protocols/control-plane-protocol/frr-ospfd:ospf/default-information/metric
 */
int routing_control_plane_protocols_control_plane_protocol_ospf_default_information_metric_modify(
	struct nb_cb_modify_args *args)
{
	/* implmented in default_information_apply_finish */
	return NB_OK;
}

int routing_control_plane_protocols_control_plane_protocol_ospf_default_information_metric_destroy(
	struct nb_cb_destroy_args *args)
{
	/* implmented in default_information_apply_finish */
	return NB_OK;
}

/*
 * XPath: /frr-routing:routing/control-plane-protocols/control-plane-protocol/frr-ospfd:ospf/default-information/metric-type
 */
int routing_control_plane_protocols_control_plane_protocol_ospf_default_information_metric_type_modify(
	struct nb_cb_modify_args *args)
{
	/* implmented in default_information_apply_finish */
	return NB_OK;
}

int routing_control_plane_protocols_control_plane_protocol_ospf_default_information_metric_type_destroy(
	struct nb_cb_destroy_args *args)
{
	/* implmented in default_information_apply_finish */
	return NB_OK;
}

/*
 * XPath: /frr-routing:routing/control-plane-protocols/control-plane-protocol/frr-ospfd:ospf/default-information/route-map
 */
int routing_control_plane_protocols_control_plane_protocol_ospf_default_information_route_map_modify(
	struct nb_cb_modify_args *args)
{
	/* implmented in default_information_apply_finish */
	return NB_OK;
}

int routing_control_plane_protocols_control_plane_protocol_ospf_default_information_route_map_destroy(
	struct nb_cb_destroy_args *args)
{
	/* implmented in default_information_apply_finish */
	return NB_OK;
}

/*
 * XPath: /frr-routing:routing/control-plane-protocols/control-plane-protocol/frr-ospfd:ospf/redistribute
 */
int routing_control_plane_protocols_control_plane_protocol_ospf_redistribute_create(
	struct nb_cb_create_args *args)
{
	switch (args->event) {
	case NB_EV_VALIDATE:
	case NB_EV_PREPARE:
	case NB_EV_ABORT:
	case NB_EV_APPLY:
		/* TODO: implement me. */
		break;
	}

	return NB_OK;
}

int routing_control_plane_protocols_control_plane_protocol_ospf_redistribute_destroy(
	struct nb_cb_destroy_args *args)
{
	switch (args->event) {
	case NB_EV_VALIDATE:
	case NB_EV_PREPARE:
	case NB_EV_ABORT:
	case NB_EV_APPLY:
		/* TODO: implement me. */
		break;
	}

	return NB_OK;
}

/*
 * XPath: /frr-routing:routing/control-plane-protocols/control-plane-protocol/frr-ospfd:ospf/redistribute/metric
 */
int routing_control_plane_protocols_control_plane_protocol_ospf_redistribute_metric_modify(
	struct nb_cb_modify_args *args)
{
	switch (args->event) {
	case NB_EV_VALIDATE:
	case NB_EV_PREPARE:
	case NB_EV_ABORT:
	case NB_EV_APPLY:
		/* TODO: implement me. */
		break;
	}

	return NB_OK;
}

int routing_control_plane_protocols_control_plane_protocol_ospf_redistribute_metric_destroy(
	struct nb_cb_destroy_args *args)
{
	switch (args->event) {
	case NB_EV_VALIDATE:
	case NB_EV_PREPARE:
	case NB_EV_ABORT:
	case NB_EV_APPLY:
		/* TODO: implement me. */
		break;
	}

	return NB_OK;
}

/*
 * XPath: /frr-routing:routing/control-plane-protocols/control-plane-protocol/frr-ospfd:ospf/redistribute/metric-type
 */
int routing_control_plane_protocols_control_plane_protocol_ospf_redistribute_metric_type_modify(
	struct nb_cb_modify_args *args)
{
	switch (args->event) {
	case NB_EV_VALIDATE:
	case NB_EV_PREPARE:
	case NB_EV_ABORT:
	case NB_EV_APPLY:
		/* TODO: implement me. */
		break;
	}

	return NB_OK;
}

int routing_control_plane_protocols_control_plane_protocol_ospf_redistribute_metric_type_destroy(
	struct nb_cb_destroy_args *args)
{
	switch (args->event) {
	case NB_EV_VALIDATE:
	case NB_EV_PREPARE:
	case NB_EV_ABORT:
	case NB_EV_APPLY:
		/* TODO: implement me. */
		break;
	}

	return NB_OK;
}

/*
 * XPath: /frr-routing:routing/control-plane-protocols/control-plane-protocol/frr-ospfd:ospf/redistribute/route-map
 */
int routing_control_plane_protocols_control_plane_protocol_ospf_redistribute_route_map_modify(
	struct nb_cb_modify_args *args)
{
	switch (args->event) {
	case NB_EV_VALIDATE:
	case NB_EV_PREPARE:
	case NB_EV_ABORT:
	case NB_EV_APPLY:
		/* TODO: implement me. */
		break;
	}

	return NB_OK;
}

int routing_control_plane_protocols_control_plane_protocol_ospf_redistribute_route_map_destroy(
	struct nb_cb_destroy_args *args)
{
	switch (args->event) {
	case NB_EV_VALIDATE:
	case NB_EV_PREPARE:
	case NB_EV_ABORT:
	case NB_EV_APPLY:
		/* TODO: implement me. */
		break;
	}

	return NB_OK;
}

/*
 * XPath: /frr-routing:routing/control-plane-protocols/control-plane-protocol/frr-ospfd:ospf/redistribute/table
 */
int routing_control_plane_protocols_control_plane_protocol_ospf_redistribute_table_create(
	struct nb_cb_create_args *args)
{
	switch (args->event) {
	case NB_EV_VALIDATE:
	case NB_EV_PREPARE:
	case NB_EV_ABORT:
	case NB_EV_APPLY:
		/* TODO: implement me. */
		break;
	}

	return NB_OK;
}

int routing_control_plane_protocols_control_plane_protocol_ospf_redistribute_table_destroy(
	struct nb_cb_destroy_args *args)
{
	switch (args->event) {
	case NB_EV_VALIDATE:
	case NB_EV_PREPARE:
	case NB_EV_ABORT:
	case NB_EV_APPLY:
		break;
	}

	return NB_OK;
}

/*
 * XPath: /frr-routing:routing/control-plane-protocols/control-plane-protocol/frr-ospfd:ospf/redistribute/table/metric
 */
int routing_control_plane_protocols_control_plane_protocol_ospf_redistribute_table_metric_modify(
	struct nb_cb_modify_args *args)
{
	switch (args->event) {
	case NB_EV_VALIDATE:
	case NB_EV_PREPARE:
	case NB_EV_ABORT:
	case NB_EV_APPLY:
		/* TODO: implement me. */
		break;
	}

	return NB_OK;
}

int routing_control_plane_protocols_control_plane_protocol_ospf_redistribute_table_metric_destroy(
	struct nb_cb_destroy_args *args)
{
	switch (args->event) {
	case NB_EV_VALIDATE:
	case NB_EV_PREPARE:
	case NB_EV_ABORT:
	case NB_EV_APPLY:
		/* TODO: implement me. */
		break;
	}

	return NB_OK;
}

/*
 * XPath: /frr-routing:routing/control-plane-protocols/control-plane-protocol/frr-ospfd:ospf/redistribute/table/metric-type
 */
int routing_control_plane_protocols_control_plane_protocol_ospf_redistribute_table_metric_type_modify(
	struct nb_cb_modify_args *args)
{
	switch (args->event) {
	case NB_EV_VALIDATE:
	case NB_EV_PREPARE:
	case NB_EV_ABORT:
	case NB_EV_APPLY:
		/* TODO: implement me. */
		break;
	}

	return NB_OK;
}

int routing_control_plane_protocols_control_plane_protocol_ospf_redistribute_table_metric_type_destroy(
	struct nb_cb_destroy_args *args)
{
	switch (args->event) {
	case NB_EV_VALIDATE:
	case NB_EV_PREPARE:
	case NB_EV_ABORT:
	case NB_EV_APPLY:
		/* TODO: implement me. */
		break;
	}

	return NB_OK;
}

/*
 * XPath: /frr-routing:routing/control-plane-protocols/control-plane-protocol/frr-ospfd:ospf/redistribute/table/route-map
 */
int routing_control_plane_protocols_control_plane_protocol_ospf_redistribute_table_route_map_modify(
	struct nb_cb_modify_args *args)
{
	switch (args->event) {
	case NB_EV_VALIDATE:
	case NB_EV_PREPARE:
	case NB_EV_ABORT:
	case NB_EV_APPLY:
		/* TODO: implement me. */
		break;
	}

	return NB_OK;
}

int routing_control_plane_protocols_control_plane_protocol_ospf_redistribute_table_route_map_destroy(
	struct nb_cb_destroy_args *args)
{
	switch (args->event) {
	case NB_EV_VALIDATE:
	case NB_EV_PREPARE:
	case NB_EV_ABORT:
	case NB_EV_APPLY:
		/* TODO: implement me. */
		break;
	}

	return NB_OK;
}

/*
 * XPath: /frr-routing:routing/control-plane-protocols/control-plane-protocol/frr-ospfd:ospf/redistribute/instance
 */
int routing_control_plane_protocols_control_plane_protocol_ospf_redistribute_instance_create(
	struct nb_cb_create_args *args)
{
	switch (args->event) {
	case NB_EV_VALIDATE:
	case NB_EV_PREPARE:
	case NB_EV_ABORT:
	case NB_EV_APPLY:
		/* TODO: implement me. */
		break;
	}

	return NB_OK;
}

int routing_control_plane_protocols_control_plane_protocol_ospf_redistribute_instance_destroy(
	struct nb_cb_destroy_args *args)
{
	switch (args->event) {
	case NB_EV_VALIDATE:
	case NB_EV_PREPARE:
	case NB_EV_ABORT:
	case NB_EV_APPLY:
		break;
	}

	return NB_OK;
}

/*
 * XPath: /frr-routing:routing/control-plane-protocols/control-plane-protocol/frr-ospfd:ospf/redistribute/instance/metric
 */
int routing_control_plane_protocols_control_plane_protocol_ospf_redistribute_instance_metric_modify(
	struct nb_cb_modify_args *args)
{
	switch (args->event) {
	case NB_EV_VALIDATE:
	case NB_EV_PREPARE:
	case NB_EV_ABORT:
	case NB_EV_APPLY:
		/* TODO: implement me. */
		break;
	}

	return NB_OK;
}

int routing_control_plane_protocols_control_plane_protocol_ospf_redistribute_instance_metric_destroy(
	struct nb_cb_destroy_args *args)
{
	switch (args->event) {
	case NB_EV_VALIDATE:
	case NB_EV_PREPARE:
	case NB_EV_ABORT:
	case NB_EV_APPLY:
		/* TODO: implement me. */
		break;
	}

	return NB_OK;
}

/*
 * XPath: /frr-routing:routing/control-plane-protocols/control-plane-protocol/frr-ospfd:ospf/redistribute/instance/metric-type
 */
int routing_control_plane_protocols_control_plane_protocol_ospf_redistribute_instance_metric_type_modify(
	struct nb_cb_modify_args *args)
{
	switch (args->event) {
	case NB_EV_VALIDATE:
	case NB_EV_PREPARE:
	case NB_EV_ABORT:
	case NB_EV_APPLY:
		/* TODO: implement me. */
		break;
	}

	return NB_OK;
}

int routing_control_plane_protocols_control_plane_protocol_ospf_redistribute_instance_metric_type_destroy(
	struct nb_cb_destroy_args *args)
{
	switch (args->event) {
	case NB_EV_VALIDATE:
	case NB_EV_PREPARE:
	case NB_EV_ABORT:
	case NB_EV_APPLY:
		/* TODO: implement me. */
		break;
	}

	return NB_OK;
}

/*
 * XPath: /frr-routing:routing/control-plane-protocols/control-plane-protocol/frr-ospfd:ospf/redistribute/instance/route-map
 */
int routing_control_plane_protocols_control_plane_protocol_ospf_redistribute_instance_route_map_modify(
	struct nb_cb_modify_args *args)
{
	switch (args->event) {
	case NB_EV_VALIDATE:
	case NB_EV_PREPARE:
	case NB_EV_ABORT:
	case NB_EV_APPLY:
		/* TODO: implement me. */
		break;
	}

	return NB_OK;
}

int routing_control_plane_protocols_control_plane_protocol_ospf_redistribute_instance_route_map_destroy(
	struct nb_cb_destroy_args *args)
{
	switch (args->event) {
	case NB_EV_VALIDATE:
	case NB_EV_PREPARE:
	case NB_EV_ABORT:
	case NB_EV_APPLY:
		/* TODO: implement me. */
		break;
	}

	return NB_OK;
}

/*
 * XPath: /frr-routing:routing/control-plane-protocols/control-plane-protocol/frr-ospfd:ospf/distance/admin-value
 */
int routing_control_plane_protocols_control_plane_protocol_ospf_distance_admin_value_modify(
	struct nb_cb_modify_args *args)
{
	switch (args->event) {
	case NB_EV_VALIDATE:
	case NB_EV_PREPARE:
	case NB_EV_ABORT:
	case NB_EV_APPLY:
		/* TODO: implement me. */
		break;
	}

	return NB_OK;
}

int routing_control_plane_protocols_control_plane_protocol_ospf_distance_admin_value_destroy(
	struct nb_cb_destroy_args *args)
{
	switch (args->event) {
	case NB_EV_VALIDATE:
	case NB_EV_PREPARE:
	case NB_EV_ABORT:
	case NB_EV_APPLY:
		/* TODO: implement me. */
		break;
	}

	return NB_OK;
}

/*
 * XPath: /frr-routing:routing/control-plane-protocols/control-plane-protocol/frr-ospfd:ospf/distance/ospf/external
 */
int routing_control_plane_protocols_control_plane_protocol_ospf_distance_ospf_external_modify(
	struct nb_cb_modify_args *args)
{
	switch (args->event) {
	case NB_EV_VALIDATE:
	case NB_EV_PREPARE:
	case NB_EV_ABORT:
	case NB_EV_APPLY:
		/* TODO: implement me. */
		break;
	}

	return NB_OK;
}

int routing_control_plane_protocols_control_plane_protocol_ospf_distance_ospf_external_destroy(
	struct nb_cb_destroy_args *args)
{
	switch (args->event) {
	case NB_EV_VALIDATE:
	case NB_EV_PREPARE:
	case NB_EV_ABORT:
	case NB_EV_APPLY:
		/* TODO: implement me. */
		break;
	}

	return NB_OK;
}

/*
 * XPath: /frr-routing:routing/control-plane-protocols/control-plane-protocol/frr-ospfd:ospf/distance/ospf/inter-area
 */
int routing_control_plane_protocols_control_plane_protocol_ospf_distance_ospf_inter_area_modify(
	struct nb_cb_modify_args *args)
{
	switch (args->event) {
	case NB_EV_VALIDATE:
	case NB_EV_PREPARE:
	case NB_EV_ABORT:
	case NB_EV_APPLY:
		/* TODO: implement me. */
		break;
	}

	return NB_OK;
}

int routing_control_plane_protocols_control_plane_protocol_ospf_distance_ospf_inter_area_destroy(
	struct nb_cb_destroy_args *args)
{
	switch (args->event) {
	case NB_EV_VALIDATE:
	case NB_EV_PREPARE:
	case NB_EV_ABORT:
	case NB_EV_APPLY:
		/* TODO: implement me. */
		break;
	}

	return NB_OK;
}

/*
 * XPath: /frr-routing:routing/control-plane-protocols/control-plane-protocol/frr-ospfd:ospf/distance/ospf/intra-area
 */
int routing_control_plane_protocols_control_plane_protocol_ospf_distance_ospf_intra_area_modify(
	struct nb_cb_modify_args *args)
{
	switch (args->event) {
	case NB_EV_VALIDATE:
	case NB_EV_PREPARE:
	case NB_EV_ABORT:
	case NB_EV_APPLY:
		/* TODO: implement me. */
		break;
	}

	return NB_OK;
}

int routing_control_plane_protocols_control_plane_protocol_ospf_distance_ospf_intra_area_destroy(
	struct nb_cb_destroy_args *args)
{
	switch (args->event) {
	case NB_EV_VALIDATE:
	case NB_EV_PREPARE:
	case NB_EV_ABORT:
	case NB_EV_APPLY:
		/* TODO: implement me. */
		break;
	}

	return NB_OK;
}

/*
 * XPath: /frr-routing:routing/control-plane-protocols/control-plane-protocol/frr-ospfd:ospf/distribute-list/dlist
 */
int routing_control_plane_protocols_control_plane_protocol_ospf_distribute_list_dlist_create(
	struct nb_cb_create_args *args)
{
	switch (args->event) {
	case NB_EV_VALIDATE:
	case NB_EV_PREPARE:
	case NB_EV_ABORT:
	case NB_EV_APPLY:
		/* TODO: implement me. */
		break;
	}

	return NB_OK;
}

int routing_control_plane_protocols_control_plane_protocol_ospf_distribute_list_dlist_destroy(
	struct nb_cb_destroy_args *args)
{
	switch (args->event) {
	case NB_EV_VALIDATE:
	case NB_EV_PREPARE:
	case NB_EV_ABORT:
	case NB_EV_APPLY:
		/* TODO: implement me. */
		break;
	}

	return NB_OK;
}

/*
 * XPath: /frr-routing:routing/control-plane-protocols/control-plane-protocol/frr-ospfd:ospf/max-metric/router-lsa/administrative
 */
int routing_control_plane_protocols_control_plane_protocol_ospf_max_metric_router_lsa_administrative_modify(
	struct nb_cb_modify_args *args)
{
	switch (args->event) {
	case NB_EV_VALIDATE:
	case NB_EV_PREPARE:
	case NB_EV_ABORT:
	case NB_EV_APPLY:
		/* TODO: implement me. */
		break;
	}

	return NB_OK;
}

int routing_control_plane_protocols_control_plane_protocol_ospf_max_metric_router_lsa_administrative_destroy(
	struct nb_cb_destroy_args *args)
{
	switch (args->event) {
	case NB_EV_VALIDATE:
	case NB_EV_PREPARE:
	case NB_EV_ABORT:
	case NB_EV_APPLY:
		/* TODO: implement me. */
		break;
	}

	return NB_OK;
}

/*
 * XPath: /frr-routing:routing/control-plane-protocols/control-plane-protocol/frr-ospfd:ospf/max-metric/router-lsa/on-shutdown
 */
int routing_control_plane_protocols_control_plane_protocol_ospf_max_metric_router_lsa_on_shutdown_modify(
	struct nb_cb_modify_args *args)
{
	switch (args->event) {
	case NB_EV_VALIDATE:
	case NB_EV_PREPARE:
	case NB_EV_ABORT:
	case NB_EV_APPLY:
		/* TODO: implement me. */
		break;
	}

	return NB_OK;
}

int routing_control_plane_protocols_control_plane_protocol_ospf_max_metric_router_lsa_on_shutdown_destroy(
	struct nb_cb_destroy_args *args)
{
	switch (args->event) {
	case NB_EV_VALIDATE:
	case NB_EV_PREPARE:
	case NB_EV_ABORT:
	case NB_EV_APPLY:
		/* TODO: implement me. */
		break;
	}

	return NB_OK;
}

/*
 * XPath: /frr-routing:routing/control-plane-protocols/control-plane-protocol/frr-ospfd:ospf/max-metric/router-lsa/on-startup
 */
int routing_control_plane_protocols_control_plane_protocol_ospf_max_metric_router_lsa_on_startup_modify(
	struct nb_cb_modify_args *args)
{
	switch (args->event) {
	case NB_EV_VALIDATE:
	case NB_EV_PREPARE:
	case NB_EV_ABORT:
	case NB_EV_APPLY:
		/* TODO: implement me. */
		break;
	}

	return NB_OK;
}

int routing_control_plane_protocols_control_plane_protocol_ospf_max_metric_router_lsa_on_startup_destroy(
	struct nb_cb_destroy_args *args)
{
	switch (args->event) {
	case NB_EV_VALIDATE:
	case NB_EV_PREPARE:
	case NB_EV_ABORT:
	case NB_EV_APPLY:
		/* TODO: implement me. */
		break;
	}

	return NB_OK;
}

/*
 * XPath: /frr-routing:routing/control-plane-protocols/control-plane-protocol/frr-ospfd:ospf/mpls-te/on
 */
int routing_control_plane_protocols_control_plane_protocol_ospf_mpls_te_on_modify(
	struct nb_cb_modify_args *args)
{
	switch (args->event) {
	case NB_EV_VALIDATE:
	case NB_EV_PREPARE:
	case NB_EV_ABORT:
	case NB_EV_APPLY:
		/* TODO: implement me. */
		break;
	}

	return NB_OK;
}

int routing_control_plane_protocols_control_plane_protocol_ospf_mpls_te_on_destroy(
	struct nb_cb_destroy_args *args)
{
	switch (args->event) {
	case NB_EV_VALIDATE:
	case NB_EV_PREPARE:
	case NB_EV_ABORT:
	case NB_EV_APPLY:
		/* TODO: implement me. */
		break;
	}

	return NB_OK;
}

/*
 * XPath: /frr-routing:routing/control-plane-protocols/control-plane-protocol/frr-ospfd:ospf/mpls-te/router-address
 */
int routing_control_plane_protocols_control_plane_protocol_ospf_mpls_te_router_address_modify(
	struct nb_cb_modify_args *args)
{
	switch (args->event) {
	case NB_EV_VALIDATE:
	case NB_EV_PREPARE:
	case NB_EV_ABORT:
	case NB_EV_APPLY:
		/* TODO: implement me. */
		break;
	}

	return NB_OK;
}

int routing_control_plane_protocols_control_plane_protocol_ospf_mpls_te_router_address_destroy(
	struct nb_cb_destroy_args *args)
{
	switch (args->event) {
	case NB_EV_VALIDATE:
	case NB_EV_PREPARE:
	case NB_EV_ABORT:
	case NB_EV_APPLY:
		/* TODO: implement me. */
		break;
	}

	return NB_OK;
}

/*
 * XPath: /frr-routing:routing/control-plane-protocols/control-plane-protocol/frr-ospfd:ospf/mpls-te/inter-as/as
 */
int routing_control_plane_protocols_control_plane_protocol_ospf_mpls_te_inter_as_as_modify(
	struct nb_cb_modify_args *args)
{
	switch (args->event) {
	case NB_EV_VALIDATE:
	case NB_EV_PREPARE:
	case NB_EV_ABORT:
	case NB_EV_APPLY:
		/* TODO: implement me. */
		break;
	}

	return NB_OK;
}

int routing_control_plane_protocols_control_plane_protocol_ospf_mpls_te_inter_as_as_destroy(
	struct nb_cb_destroy_args *args)
{
	switch (args->event) {
	case NB_EV_VALIDATE:
	case NB_EV_PREPARE:
	case NB_EV_ABORT:
	case NB_EV_APPLY:
		/* TODO: implement me. */
		break;
	}

	return NB_OK;
}

/*
 * XPath: /frr-routing:routing/control-plane-protocols/control-plane-protocol/frr-ospfd:ospf/mpls-te/inter-as/area
 */
int routing_control_plane_protocols_control_plane_protocol_ospf_mpls_te_inter_as_area_modify(
	struct nb_cb_modify_args *args)
{
	switch (args->event) {
	case NB_EV_VALIDATE:
	case NB_EV_PREPARE:
	case NB_EV_ABORT:
	case NB_EV_APPLY:
		/* TODO: implement me. */
		break;
	}

	return NB_OK;
}

int routing_control_plane_protocols_control_plane_protocol_ospf_mpls_te_inter_as_area_destroy(
	struct nb_cb_destroy_args *args)
{
	switch (args->event) {
	case NB_EV_VALIDATE:
	case NB_EV_PREPARE:
	case NB_EV_ABORT:
	case NB_EV_APPLY:
		/* TODO: implement me. */
		break;
	}

	return NB_OK;
}

/*
 * XPath: /frr-routing:routing/control-plane-protocols/control-plane-protocol/frr-ospfd:ospf/ospf/abr-type
 */
int routing_control_plane_protocols_control_plane_protocol_ospf_ospf_abr_type_modify(
	struct nb_cb_modify_args *args)
{
	switch (args->event) {
	case NB_EV_VALIDATE:
	case NB_EV_PREPARE:
	case NB_EV_ABORT:
	case NB_EV_APPLY:
		/* TODO: implement me. */
		break;
	}

	return NB_OK;
}

int routing_control_plane_protocols_control_plane_protocol_ospf_ospf_abr_type_destroy(
	struct nb_cb_destroy_args *args)
{
	switch (args->event) {
	case NB_EV_VALIDATE:
	case NB_EV_PREPARE:
	case NB_EV_ABORT:
	case NB_EV_APPLY:
		/* TODO: implement me. */
		break;
	}

	return NB_OK;
}

/*
 * XPath: /frr-routing:routing/control-plane-protocols/control-plane-protocol/frr-ospfd:ospf/ospf/opaque-lsa
 */
int routing_control_plane_protocols_control_plane_protocol_ospf_ospf_opaque_lsa_modify(
	struct nb_cb_modify_args *args)
{
	switch (args->event) {
	case NB_EV_VALIDATE:
	case NB_EV_PREPARE:
	case NB_EV_ABORT:
	case NB_EV_APPLY:
		/* TODO: implement me. */
		break;
	}

	return NB_OK;
}

int routing_control_plane_protocols_control_plane_protocol_ospf_ospf_opaque_lsa_destroy(
	struct nb_cb_destroy_args *args)
{
	switch (args->event) {
	case NB_EV_VALIDATE:
	case NB_EV_PREPARE:
	case NB_EV_ABORT:
	case NB_EV_APPLY:
		/* TODO: implement me. */
		break;
	}

	return NB_OK;
}

/*
 * XPath: /frr-routing:routing/control-plane-protocols/control-plane-protocol/frr-ospfd:ospf/ospf/rfc1583compatibility
 */
int routing_control_plane_protocols_control_plane_protocol_ospf_ospf_rfc1583compatibility_modify(
	struct nb_cb_modify_args *args)
{
	switch (args->event) {
	case NB_EV_VALIDATE:
	case NB_EV_PREPARE:
	case NB_EV_ABORT:
	case NB_EV_APPLY:
		/* TODO: implement me. */
		break;
	}

	return NB_OK;
}

int routing_control_plane_protocols_control_plane_protocol_ospf_ospf_rfc1583compatibility_destroy(
	struct nb_cb_destroy_args *args)
{
	switch (args->event) {
	case NB_EV_VALIDATE:
	case NB_EV_PREPARE:
	case NB_EV_ABORT:
	case NB_EV_APPLY:
		/* TODO: implement me. */
		break;
	}

	return NB_OK;
}

/*
 * XPath: /frr-routing:routing/control-plane-protocols/control-plane-protocol/frr-ospfd:ospf/ospf/router-id
 */
int routing_control_plane_protocols_control_plane_protocol_ospf_ospf_router_id_modify(
	struct nb_cb_modify_args *args)
{
	switch (args->event) {
	case NB_EV_VALIDATE:
	case NB_EV_PREPARE:
	case NB_EV_ABORT:
	case NB_EV_APPLY:
		/* TODO: implement me. */
		break;
	}

	return NB_OK;
}

int routing_control_plane_protocols_control_plane_protocol_ospf_ospf_router_id_destroy(
	struct nb_cb_destroy_args *args)
{
	switch (args->event) {
	case NB_EV_VALIDATE:
	case NB_EV_PREPARE:
	case NB_EV_ABORT:
	case NB_EV_APPLY:
		/* TODO: implement me. */
		break;
	}

	return NB_OK;
}

/*
 * XPath: /frr-routing:routing/control-plane-protocols/control-plane-protocol/frr-ospfd:ospf/ospf/write-multiplier
 */
int routing_control_plane_protocols_control_plane_protocol_ospf_ospf_write_multiplier_modify(
	struct nb_cb_modify_args *args)
{
	switch (args->event) {
	case NB_EV_VALIDATE:
	case NB_EV_PREPARE:
	case NB_EV_ABORT:
	case NB_EV_APPLY:
		/* TODO: implement me. */
		break;
	}

	return NB_OK;
}

int routing_control_plane_protocols_control_plane_protocol_ospf_ospf_write_multiplier_destroy(
	struct nb_cb_destroy_args *args)
{
	switch (args->event) {
	case NB_EV_VALIDATE:
	case NB_EV_PREPARE:
	case NB_EV_ABORT:
	case NB_EV_APPLY:
		/* TODO: implement me. */
		break;
	}

	return NB_OK;
}

/*
 * XPath: /frr-routing:routing/control-plane-protocols/control-plane-protocol/frr-ospfd:ospf/timers/refresh-interval
 */
int routing_control_plane_protocols_control_plane_protocol_ospf_timers_refresh_interval_modify(
	struct nb_cb_modify_args *args)
{
	switch (args->event) {
	case NB_EV_VALIDATE:
	case NB_EV_PREPARE:
	case NB_EV_ABORT:
	case NB_EV_APPLY:
		/* TODO: implement me. */
		break;
	}

	return NB_OK;
}

int routing_control_plane_protocols_control_plane_protocol_ospf_timers_refresh_interval_destroy(
	struct nb_cb_destroy_args *args)
{
	switch (args->event) {
	case NB_EV_VALIDATE:
	case NB_EV_PREPARE:
	case NB_EV_ABORT:
	case NB_EV_APPLY:
		/* TODO: implement me. */
		break;
	}

	return NB_OK;
}

/*
 * XPath: /frr-routing:routing/control-plane-protocols/control-plane-protocol/frr-ospfd:ospf/timers/lsa-min-arrival
 */
int routing_control_plane_protocols_control_plane_protocol_ospf_timers_lsa_min_arrival_modify(
	struct nb_cb_modify_args *args)
{
	switch (args->event) {
	case NB_EV_VALIDATE:
	case NB_EV_PREPARE:
	case NB_EV_ABORT:
	case NB_EV_APPLY:
		/* TODO: implement me. */
		break;
	}

	return NB_OK;
}

int routing_control_plane_protocols_control_plane_protocol_ospf_timers_lsa_min_arrival_destroy(
	struct nb_cb_destroy_args *args)
{
	switch (args->event) {
	case NB_EV_VALIDATE:
	case NB_EV_PREPARE:
	case NB_EV_ABORT:
	case NB_EV_APPLY:
		/* TODO: implement me. */
		break;
	}

	return NB_OK;
}

/*
 * XPath: /frr-routing:routing/control-plane-protocols/control-plane-protocol/frr-ospfd:ospf/timers/throttle/lsa-all
 */
int routing_control_plane_protocols_control_plane_protocol_ospf_timers_throttle_lsa_all_modify(
	struct nb_cb_modify_args *args)
{
	switch (args->event) {
	case NB_EV_VALIDATE:
	case NB_EV_PREPARE:
	case NB_EV_ABORT:
	case NB_EV_APPLY:
		/* TODO: implement me. */
		break;
	}

	return NB_OK;
}

int routing_control_plane_protocols_control_plane_protocol_ospf_timers_throttle_lsa_all_destroy(
	struct nb_cb_destroy_args *args)
{
	switch (args->event) {
	case NB_EV_VALIDATE:
	case NB_EV_PREPARE:
	case NB_EV_ABORT:
	case NB_EV_APPLY:
		/* TODO: implement me. */
		break;
	}

	return NB_OK;
}

/*
 * XPath: /frr-routing:routing/control-plane-protocols/control-plane-protocol/frr-ospfd:ospf/timers/throttle/spf
 */
int routing_control_plane_protocols_control_plane_protocol_ospf_timers_throttle_spf_modify(
	struct nb_cb_modify_args *args)
{
	switch (args->event) {
	case NB_EV_VALIDATE:
	case NB_EV_PREPARE:
	case NB_EV_ABORT:
	case NB_EV_APPLY:
		/* TODO: implement me. */
		break;
	}

	return NB_OK;
}

int routing_control_plane_protocols_control_plane_protocol_ospf_timers_throttle_spf_destroy(
	struct nb_cb_destroy_args *args)
{
	switch (args->event) {
	case NB_EV_VALIDATE:
	case NB_EV_PREPARE:
	case NB_EV_ABORT:
	case NB_EV_APPLY:
		/* TODO: implement me. */
		break;
	}

	return NB_OK;
}

/*
 * XPath: /frr-routing:routing/control-plane-protocols/control-plane-protocol/frr-ospfd:ospf/segment-routing/global-block/lower-bound
 */
int routing_control_plane_protocols_control_plane_protocol_ospf_segment_routing_global_block_lower_bound_modify(
	struct nb_cb_modify_args *args)
{
	switch (args->event) {
	case NB_EV_VALIDATE:
	case NB_EV_PREPARE:
	case NB_EV_ABORT:
	case NB_EV_APPLY:
		/* TODO: implement me. */
		break;
	}

	return NB_OK;
}

/*
 * XPath: /frr-routing:routing/control-plane-protocols/control-plane-protocol/frr-ospfd:ospf/segment-routing/global-block/upper-bound
 */
int routing_control_plane_protocols_control_plane_protocol_ospf_segment_routing_global_block_upper_bound_modify(
	struct nb_cb_modify_args *args)
{
	switch (args->event) {
	case NB_EV_VALIDATE:
	case NB_EV_PREPARE:
	case NB_EV_ABORT:
	case NB_EV_APPLY:
		/* TODO: implement me. */
		break;
	}

	return NB_OK;
}

/*
 * XPath: /frr-routing:routing/control-plane-protocols/control-plane-protocol/frr-ospfd:ospf/segment-routing/srlb/lower-bound
 */
int routing_control_plane_protocols_control_plane_protocol_ospf_segment_routing_srlb_lower_bound_modify(
	struct nb_cb_modify_args *args)
{
	switch (args->event) {
	case NB_EV_VALIDATE:
	case NB_EV_PREPARE:
	case NB_EV_ABORT:
	case NB_EV_APPLY:
		/* TODO: implement me. */
		break;
	}

	return NB_OK;
}

/*
 * XPath: /frr-routing:routing/control-plane-protocols/control-plane-protocol/frr-ospfd:ospf/segment-routing/srlb/upper-bound
 */
int routing_control_plane_protocols_control_plane_protocol_ospf_segment_routing_srlb_upper_bound_modify(
	struct nb_cb_modify_args *args)
{
	switch (args->event) {
	case NB_EV_VALIDATE:
	case NB_EV_PREPARE:
	case NB_EV_ABORT:
	case NB_EV_APPLY:
		/* TODO: implement me. */
		break;
	}

	return NB_OK;
}

/*
 * XPath: /frr-routing:routing/control-plane-protocols/control-plane-protocol/frr-ospfd:ospf/segment-routing/node-msd
 */
int routing_control_plane_protocols_control_plane_protocol_ospf_segment_routing_node_msd_modify(
	struct nb_cb_modify_args *args)
{
	switch (args->event) {
	case NB_EV_VALIDATE:
	case NB_EV_PREPARE:
	case NB_EV_ABORT:
	case NB_EV_APPLY:
		/* TODO: implement me. */
		break;
	}

	return NB_OK;
}

int routing_control_plane_protocols_control_plane_protocol_ospf_segment_routing_node_msd_destroy(
	struct nb_cb_destroy_args *args)
{
	switch (args->event) {
	case NB_EV_VALIDATE:
	case NB_EV_PREPARE:
	case NB_EV_ABORT:
	case NB_EV_APPLY:
		/* TODO: implement me. */
		break;
	}

	return NB_OK;
}

/*
 * XPath: /frr-routing:routing/control-plane-protocols/control-plane-protocol/frr-ospfd:ospf/segment-routing/on
 */
int routing_control_plane_protocols_control_plane_protocol_ospf_segment_routing_on_modify(
	struct nb_cb_modify_args *args)
{
	switch (args->event) {
	case NB_EV_VALIDATE:
	case NB_EV_PREPARE:
	case NB_EV_ABORT:
	case NB_EV_APPLY:
		/* TODO: implement me. */
		break;
	}

	return NB_OK;
}

int routing_control_plane_protocols_control_plane_protocol_ospf_segment_routing_on_destroy(
	struct nb_cb_destroy_args *args)
{
	switch (args->event) {
	case NB_EV_VALIDATE:
	case NB_EV_PREPARE:
	case NB_EV_ABORT:
	case NB_EV_APPLY:
		/* TODO: implement me. */
		break;
	}

	return NB_OK;
}

/*
 * XPath: /frr-routing:routing/control-plane-protocols/control-plane-protocol/frr-ospfd:ospf/segment-routing/prefix-sid
 */
int routing_control_plane_protocols_control_plane_protocol_ospf_segment_routing_prefix_sid_create(
	struct nb_cb_create_args *args)
{
	switch (args->event) {
	case NB_EV_VALIDATE:
	case NB_EV_PREPARE:
	case NB_EV_ABORT:
	case NB_EV_APPLY:
		/* TODO: implement me. */
		break;
	}

	return NB_OK;
}

int routing_control_plane_protocols_control_plane_protocol_ospf_segment_routing_prefix_sid_destroy(
	struct nb_cb_destroy_args *args)
{
	switch (args->event) {
	case NB_EV_VALIDATE:
	case NB_EV_PREPARE:
	case NB_EV_ABORT:
	case NB_EV_APPLY:
		/* TODO: implement me. */
		break;
	}

	return NB_OK;
}

/*
 * XPath: /frr-routing:routing/control-plane-protocols/control-plane-protocol/frr-ospfd:ospf/segment-routing/prefix-sid/prefix
 */
int routing_control_plane_protocols_control_plane_protocol_ospf_segment_routing_prefix_sid_prefix_modify(
	struct nb_cb_modify_args *args)
{
	switch (args->event) {
	case NB_EV_VALIDATE:
	case NB_EV_PREPARE:
	case NB_EV_ABORT:
	case NB_EV_APPLY:
		/* TODO: implement me. */
		break;
	}

	return NB_OK;
}

int routing_control_plane_protocols_control_plane_protocol_ospf_segment_routing_prefix_sid_prefix_destroy(
	struct nb_cb_destroy_args *args)
{
	switch (args->event) {
	case NB_EV_VALIDATE:
	case NB_EV_PREPARE:
	case NB_EV_ABORT:
	case NB_EV_APPLY:
		/* TODO: implement me. */
		break;
	}

	return NB_OK;
}

/*
 * XPath: /frr-routing:routing/control-plane-protocols/control-plane-protocol/frr-ospfd:ospf/segment-routing/prefix-sid/last-hop-behavior
 */
int routing_control_plane_protocols_control_plane_protocol_ospf_segment_routing_prefix_sid_last_hop_behavior_modify(
	struct nb_cb_modify_args *args)
{
	switch (args->event) {
	case NB_EV_VALIDATE:
	case NB_EV_PREPARE:
	case NB_EV_ABORT:
	case NB_EV_APPLY:
		/* TODO: implement me. */
		break;
	}

	return NB_OK;
}

/*
 * XPath: /frr-routing:routing/control-plane-protocols/control-plane-protocol/frr-ospfd:ospf/neighbor
 */
int routing_control_plane_protocols_control_plane_protocol_ospf_neighbor_create(
	struct nb_cb_create_args *args)
{
	switch (args->event) {
	case NB_EV_VALIDATE:
	case NB_EV_PREPARE:
	case NB_EV_ABORT:
	case NB_EV_APPLY:
		/* TODO: implement me. */
		break;
	}

	return NB_OK;
}

int routing_control_plane_protocols_control_plane_protocol_ospf_neighbor_destroy(
	struct nb_cb_destroy_args *args)
{
	switch (args->event) {
	case NB_EV_VALIDATE:
	case NB_EV_PREPARE:
	case NB_EV_ABORT:
	case NB_EV_APPLY:
		/* TODO: implement me. */
		break;
	}

	return NB_OK;
}

/*
 * XPath: /frr-routing:routing/control-plane-protocols/control-plane-protocol/frr-ospfd:ospf/neighbor/priority
 */
int routing_control_plane_protocols_control_plane_protocol_ospf_neighbor_priority_modify(
	struct nb_cb_modify_args *args)
{
	switch (args->event) {
	case NB_EV_VALIDATE:
	case NB_EV_PREPARE:
	case NB_EV_ABORT:
	case NB_EV_APPLY:
		/* TODO: implement me. */
		break;
	}

	return NB_OK;
}

int routing_control_plane_protocols_control_plane_protocol_ospf_neighbor_priority_destroy(
	struct nb_cb_destroy_args *args)
{
	switch (args->event) {
	case NB_EV_VALIDATE:
	case NB_EV_PREPARE:
	case NB_EV_ABORT:
	case NB_EV_APPLY:
		/* TODO: implement me. */
		break;
	}

	return NB_OK;
}

/*
 * XPath: /frr-routing:routing/control-plane-protocols/control-plane-protocol/frr-ospfd:ospf/neighbor/poll-interval
 */
int routing_control_plane_protocols_control_plane_protocol_ospf_neighbor_poll_interval_modify(
	struct nb_cb_modify_args *args)
{
	switch (args->event) {
	case NB_EV_VALIDATE:
	case NB_EV_PREPARE:
	case NB_EV_ABORT:
	case NB_EV_APPLY:
		/* TODO: implement me. */
		break;
	}

	return NB_OK;
}

int routing_control_plane_protocols_control_plane_protocol_ospf_neighbor_poll_interval_destroy(
	struct nb_cb_destroy_args *args)
{
	switch (args->event) {
	case NB_EV_VALIDATE:
	case NB_EV_PREPARE:
	case NB_EV_ABORT:
	case NB_EV_APPLY:
		/* TODO: implement me. */
		break;
	}

	return NB_OK;
}

/*
 * XPath: /frr-routing:routing/control-plane-protocols/control-plane-protocol/frr-ospfd:ospf/network
 */
int routing_control_plane_protocols_control_plane_protocol_ospf_network_create(
	struct nb_cb_create_args *args)
{
	switch (args->event) {
	case NB_EV_VALIDATE:
	case NB_EV_PREPARE:
	case NB_EV_ABORT:
	case NB_EV_APPLY:
		/* TODO: implement me. */
		break;
	}

	return NB_OK;
}

int routing_control_plane_protocols_control_plane_protocol_ospf_network_destroy(
	struct nb_cb_destroy_args *args)
{
	switch (args->event) {
	case NB_EV_VALIDATE:
	case NB_EV_PREPARE:
	case NB_EV_ABORT:
	case NB_EV_APPLY:
		/* TODO: implement me. */
		break;
	}

	return NB_OK;
}

/*
 * XPath: /frr-routing:routing/control-plane-protocols/control-plane-protocol/frr-ospfd:ospf/network/area
 */
int routing_control_plane_protocols_control_plane_protocol_ospf_network_area_modify(
	struct nb_cb_modify_args *args)
{
	switch (args->event) {
	case NB_EV_VALIDATE:
	case NB_EV_PREPARE:
	case NB_EV_ABORT:
	case NB_EV_APPLY:
		/* TODO: implement me. */
		break;
	}

	return NB_OK;
}

int routing_control_plane_protocols_control_plane_protocol_ospf_network_area_destroy(
	struct nb_cb_destroy_args *args)
{
	switch (args->event) {
	case NB_EV_VALIDATE:
	case NB_EV_PREPARE:
	case NB_EV_ABORT:
	case NB_EV_APPLY:
		/* TODO: implement me. */
		break;
	}

	return NB_OK;
}

/*
 * XPath: /frr-routing:routing/control-plane-protocols/control-plane-protocol/frr-ospfd:ospf/passive-interface
 */
int routing_control_plane_protocols_control_plane_protocol_ospf_passive_interface_create(
	struct nb_cb_create_args *args)
{
	switch (args->event) {
	case NB_EV_VALIDATE:
	case NB_EV_PREPARE:
	case NB_EV_ABORT:
	case NB_EV_APPLY:
		/* TODO: implement me. */
		break;
	}

	return NB_OK;
}

int routing_control_plane_protocols_control_plane_protocol_ospf_passive_interface_destroy(
	struct nb_cb_destroy_args *args)
{
	switch (args->event) {
	case NB_EV_VALIDATE:
	case NB_EV_PREPARE:
	case NB_EV_ABORT:
	case NB_EV_APPLY:
		/* TODO: implement me. */
		break;
	}

	return NB_OK;
}

/*
 * XPath: /frr-routing:routing/control-plane-protocols/control-plane-protocol/frr-ospfd:ospf/passive-interface/address
 */
int routing_control_plane_protocols_control_plane_protocol_ospf_passive_interface_address_modify(
	struct nb_cb_modify_args *args)
{
	switch (args->event) {
	case NB_EV_VALIDATE:
	case NB_EV_PREPARE:
	case NB_EV_ABORT:
	case NB_EV_APPLY:
		/* TODO: implement me. */
		break;
	}

	return NB_OK;
}

int routing_control_plane_protocols_control_plane_protocol_ospf_passive_interface_address_destroy(
	struct nb_cb_destroy_args *args)
{
	switch (args->event) {
	case NB_EV_VALIDATE:
	case NB_EV_PREPARE:
	case NB_EV_ABORT:
	case NB_EV_APPLY:
		/* TODO: implement me. */
		break;
	}

	return NB_OK;
}

/*
 * XPath: /frr-routing:routing/control-plane-protocols/control-plane-protocol/frr-ospfd:ospf/areas/area
 */
int routing_control_plane_protocols_control_plane_protocol_ospf_areas_area_create(
	struct nb_cb_create_args *args)
{
	switch (args->event) {
	case NB_EV_VALIDATE:
	case NB_EV_PREPARE:
	case NB_EV_ABORT:
	case NB_EV_APPLY:
		/* TODO: implement me. */
		break;
	}

	return NB_OK;
}

int routing_control_plane_protocols_control_plane_protocol_ospf_areas_area_destroy(
	struct nb_cb_destroy_args *args)
{
	switch (args->event) {
	case NB_EV_VALIDATE:
	case NB_EV_PREPARE:
	case NB_EV_ABORT:
	case NB_EV_APPLY:
		/* TODO: implement me. */
		break;
	}

	return NB_OK;
}

/*
 * XPath: /frr-routing:routing/control-plane-protocols/control-plane-protocol/frr-ospfd:ospf/areas/area/authentication
 */
int routing_control_plane_protocols_control_plane_protocol_ospf_areas_area_authentication_create(
	struct nb_cb_create_args *args)
{
	switch (args->event) {
	case NB_EV_VALIDATE:
	case NB_EV_PREPARE:
	case NB_EV_ABORT:
	case NB_EV_APPLY:
		/* TODO: implement me. */
		break;
	}

	return NB_OK;
}

int routing_control_plane_protocols_control_plane_protocol_ospf_areas_area_authentication_destroy(
	struct nb_cb_destroy_args *args)
{
	switch (args->event) {
	case NB_EV_VALIDATE:
	case NB_EV_PREPARE:
	case NB_EV_ABORT:
	case NB_EV_APPLY:
		/* TODO: implement me. */
		break;
	}

	return NB_OK;
}

/*
 * XPath: /frr-routing:routing/control-plane-protocols/control-plane-protocol/frr-ospfd:ospf/areas/area/authentication/message-digest
 */
int routing_control_plane_protocols_control_plane_protocol_ospf_areas_area_authentication_message_digest_modify(
	struct nb_cb_modify_args *args)
{
	switch (args->event) {
	case NB_EV_VALIDATE:
	case NB_EV_PREPARE:
	case NB_EV_ABORT:
	case NB_EV_APPLY:
		/* TODO: implement me. */
		break;
	}

	return NB_OK;
}

int routing_control_plane_protocols_control_plane_protocol_ospf_areas_area_authentication_message_digest_destroy(
	struct nb_cb_destroy_args *args)
{
	switch (args->event) {
	case NB_EV_VALIDATE:
	case NB_EV_PREPARE:
	case NB_EV_ABORT:
	case NB_EV_APPLY:
		/* TODO: implement me. */
		break;
	}

	return NB_OK;
}

/*
 * XPath: /frr-routing:routing/control-plane-protocols/control-plane-protocol/frr-ospfd:ospf/areas/area/default-cost
 */
int routing_control_plane_protocols_control_plane_protocol_ospf_areas_area_default_cost_modify(
	struct nb_cb_modify_args *args)
{
	switch (args->event) {
	case NB_EV_VALIDATE:
	case NB_EV_PREPARE:
	case NB_EV_ABORT:
	case NB_EV_APPLY:
		/* TODO: implement me. */
		break;
	}

	return NB_OK;
}

int routing_control_plane_protocols_control_plane_protocol_ospf_areas_area_default_cost_destroy(
	struct nb_cb_destroy_args *args)
{
	switch (args->event) {
	case NB_EV_VALIDATE:
	case NB_EV_PREPARE:
	case NB_EV_ABORT:
	case NB_EV_APPLY:
		/* TODO: implement me. */
		break;
	}

	return NB_OK;
}

/*
 * XPath: /frr-routing:routing/control-plane-protocols/control-plane-protocol/frr-ospfd:ospf/areas/area/export-list
 */
int routing_control_plane_protocols_control_plane_protocol_ospf_areas_area_export_list_modify(
	struct nb_cb_modify_args *args)
{
	switch (args->event) {
	case NB_EV_VALIDATE:
	case NB_EV_PREPARE:
	case NB_EV_ABORT:
	case NB_EV_APPLY:
		/* TODO: implement me. */
		break;
	}

	return NB_OK;
}

int routing_control_plane_protocols_control_plane_protocol_ospf_areas_area_export_list_destroy(
	struct nb_cb_destroy_args *args)
{
	switch (args->event) {
	case NB_EV_VALIDATE:
	case NB_EV_PREPARE:
	case NB_EV_ABORT:
	case NB_EV_APPLY:
		/* TODO: implement me. */
		break;
	}

	return NB_OK;
}

/*
 * XPath: /frr-routing:routing/control-plane-protocols/control-plane-protocol/frr-ospfd:ospf/areas/area/import-list
 */
int routing_control_plane_protocols_control_plane_protocol_ospf_areas_area_import_list_modify(
	struct nb_cb_modify_args *args)
{
	switch (args->event) {
	case NB_EV_VALIDATE:
	case NB_EV_PREPARE:
	case NB_EV_ABORT:
	case NB_EV_APPLY:
		/* TODO: implement me. */
		break;
	}

	return NB_OK;
}

int routing_control_plane_protocols_control_plane_protocol_ospf_areas_area_import_list_destroy(
	struct nb_cb_destroy_args *args)
{
	switch (args->event) {
	case NB_EV_VALIDATE:
	case NB_EV_PREPARE:
	case NB_EV_ABORT:
	case NB_EV_APPLY:
		/* TODO: implement me. */
		break;
	}

	return NB_OK;
}

/*
 * XPath: /frr-routing:routing/control-plane-protocols/control-plane-protocol/frr-ospfd:ospf/areas/area/filter-list/prefix
 */
int routing_control_plane_protocols_control_plane_protocol_ospf_areas_area_filter_list_prefix_modify(
	struct nb_cb_modify_args *args)
{
	switch (args->event) {
	case NB_EV_VALIDATE:
	case NB_EV_PREPARE:
	case NB_EV_ABORT:
	case NB_EV_APPLY:
		/* TODO: implement me. */
		break;
	}

	return NB_OK;
}

int routing_control_plane_protocols_control_plane_protocol_ospf_areas_area_filter_list_prefix_destroy(
	struct nb_cb_destroy_args *args)
{
	switch (args->event) {
	case NB_EV_VALIDATE:
	case NB_EV_PREPARE:
	case NB_EV_ABORT:
	case NB_EV_APPLY:
		/* TODO: implement me. */
		break;
	}

	return NB_OK;
}

/*
 * XPath: /frr-routing:routing/control-plane-protocols/control-plane-protocol/frr-ospfd:ospf/areas/area/filter-list/in
 */
int routing_control_plane_protocols_control_plane_protocol_ospf_areas_area_filter_list_in_modify(
	struct nb_cb_modify_args *args)
{
	switch (args->event) {
	case NB_EV_VALIDATE:
	case NB_EV_PREPARE:
	case NB_EV_ABORT:
	case NB_EV_APPLY:
		/* TODO: implement me. */
		break;
	}

	return NB_OK;
}

int routing_control_plane_protocols_control_plane_protocol_ospf_areas_area_filter_list_in_destroy(
	struct nb_cb_destroy_args *args)
{
	switch (args->event) {
	case NB_EV_VALIDATE:
	case NB_EV_PREPARE:
	case NB_EV_ABORT:
	case NB_EV_APPLY:
		/* TODO: implement me. */
		break;
	}

	return NB_OK;
}

/*
 * XPath: /frr-routing:routing/control-plane-protocols/control-plane-protocol/frr-ospfd:ospf/areas/area/filter-list/out
 */
int routing_control_plane_protocols_control_plane_protocol_ospf_areas_area_filter_list_out_modify(
	struct nb_cb_modify_args *args)
{
	switch (args->event) {
	case NB_EV_VALIDATE:
	case NB_EV_PREPARE:
	case NB_EV_ABORT:
	case NB_EV_APPLY:
		/* TODO: implement me. */
		break;
	}

	return NB_OK;
}

int routing_control_plane_protocols_control_plane_protocol_ospf_areas_area_filter_list_out_destroy(
	struct nb_cb_destroy_args *args)
{
	switch (args->event) {
	case NB_EV_VALIDATE:
	case NB_EV_PREPARE:
	case NB_EV_ABORT:
	case NB_EV_APPLY:
		/* TODO: implement me. */
		break;
	}

	return NB_OK;
}

/*
 * XPath: /frr-routing:routing/control-plane-protocols/control-plane-protocol/frr-ospfd:ospf/areas/area/nssa
 */
int routing_control_plane_protocols_control_plane_protocol_ospf_areas_area_nssa_create(
	struct nb_cb_create_args *args)
{
	switch (args->event) {
	case NB_EV_VALIDATE:
	case NB_EV_PREPARE:
	case NB_EV_ABORT:
	case NB_EV_APPLY:
		/* TODO: implement me. */
		break;
	}

	return NB_OK;
}

int routing_control_plane_protocols_control_plane_protocol_ospf_areas_area_nssa_destroy(
	struct nb_cb_destroy_args *args)
{
	switch (args->event) {
	case NB_EV_VALIDATE:
	case NB_EV_PREPARE:
	case NB_EV_ABORT:
	case NB_EV_APPLY:
		/* TODO: implement me. */
		break;
	}

	return NB_OK;
}

/*
 * XPath: /frr-routing:routing/control-plane-protocols/control-plane-protocol/frr-ospfd:ospf/areas/area/nssa/no-summary
 */
int routing_control_plane_protocols_control_plane_protocol_ospf_areas_area_nssa_no_summary_modify(
	struct nb_cb_modify_args *args)
{
	switch (args->event) {
	case NB_EV_VALIDATE:
	case NB_EV_PREPARE:
	case NB_EV_ABORT:
	case NB_EV_APPLY:
		/* TODO: implement me. */
		break;
	}

	return NB_OK;
}

/*
 * XPath: /frr-routing:routing/control-plane-protocols/control-plane-protocol/frr-ospfd:ospf/areas/area/nssa/translate-always
 */
int routing_control_plane_protocols_control_plane_protocol_ospf_areas_area_nssa_translate_always_modify(
	struct nb_cb_modify_args *args)
{
	switch (args->event) {
	case NB_EV_VALIDATE:
	case NB_EV_PREPARE:
	case NB_EV_ABORT:
	case NB_EV_APPLY:
		/* TODO: implement me. */
		break;
	}

	return NB_OK;
}

/*
 * XPath: /frr-routing:routing/control-plane-protocols/control-plane-protocol/frr-ospfd:ospf/areas/area/nssa/translate-candidate
 */
int routing_control_plane_protocols_control_plane_protocol_ospf_areas_area_nssa_translate_candidate_modify(
	struct nb_cb_modify_args *args)
{
	switch (args->event) {
	case NB_EV_VALIDATE:
	case NB_EV_PREPARE:
	case NB_EV_ABORT:
	case NB_EV_APPLY:
		/* TODO: implement me. */
		break;
	}

	return NB_OK;
}

/*
 * XPath: /frr-routing:routing/control-plane-protocols/control-plane-protocol/frr-ospfd:ospf/areas/area/nssa/translate-never
 */
int routing_control_plane_protocols_control_plane_protocol_ospf_areas_area_nssa_translate_never_modify(
	struct nb_cb_modify_args *args)
{
	switch (args->event) {
	case NB_EV_VALIDATE:
	case NB_EV_PREPARE:
	case NB_EV_ABORT:
	case NB_EV_APPLY:
		/* TODO: implement me. */
		break;
	}

	return NB_OK;
}

/*
 * XPath: /frr-routing:routing/control-plane-protocols/control-plane-protocol/frr-ospfd:ospf/areas/area/ranges/range
 */
int routing_control_plane_protocols_control_plane_protocol_ospf_areas_area_ranges_range_create(
	struct nb_cb_create_args *args)
{
	switch (args->event) {
	case NB_EV_VALIDATE:
	case NB_EV_PREPARE:
	case NB_EV_ABORT:
	case NB_EV_APPLY:
		/* TODO: implement me. */
		break;
	}

	return NB_OK;
}

int routing_control_plane_protocols_control_plane_protocol_ospf_areas_area_ranges_range_destroy(
	struct nb_cb_destroy_args *args)
{
	switch (args->event) {
	case NB_EV_VALIDATE:
	case NB_EV_PREPARE:
	case NB_EV_ABORT:
	case NB_EV_APPLY:
		/* TODO: implement me. */
		break;
	}

	return NB_OK;
}

/*
 * XPath: /frr-routing:routing/control-plane-protocols/control-plane-protocol/frr-ospfd:ospf/areas/area/ranges/range/advertise
 */
int routing_control_plane_protocols_control_plane_protocol_ospf_areas_area_ranges_range_advertise_modify(
	struct nb_cb_modify_args *args)
{
	switch (args->event) {
	case NB_EV_VALIDATE:
	case NB_EV_PREPARE:
	case NB_EV_ABORT:
	case NB_EV_APPLY:
		/* TODO: implement me. */
		break;
	}

	return NB_OK;
}

int routing_control_plane_protocols_control_plane_protocol_ospf_areas_area_ranges_range_advertise_destroy(
	struct nb_cb_destroy_args *args)
{
	switch (args->event) {
	case NB_EV_VALIDATE:
	case NB_EV_PREPARE:
	case NB_EV_ABORT:
	case NB_EV_APPLY:
		/* TODO: implement me. */
		break;
	}

	return NB_OK;
}

/*
 * XPath: /frr-routing:routing/control-plane-protocols/control-plane-protocol/frr-ospfd:ospf/areas/area/ranges/range/not-advertise
 */
int routing_control_plane_protocols_control_plane_protocol_ospf_areas_area_ranges_range_not_advertise_modify(
	struct nb_cb_modify_args *args)
{
	switch (args->event) {
	case NB_EV_VALIDATE:
	case NB_EV_PREPARE:
	case NB_EV_ABORT:
	case NB_EV_APPLY:
		/* TODO: implement me. */
		break;
	}

	return NB_OK;
}

/*
 * XPath: /frr-routing:routing/control-plane-protocols/control-plane-protocol/frr-ospfd:ospf/areas/area/ranges/range/cost
 */
int routing_control_plane_protocols_control_plane_protocol_ospf_areas_area_ranges_range_cost_modify(
	struct nb_cb_modify_args *args)
{
	switch (args->event) {
	case NB_EV_VALIDATE:
	case NB_EV_PREPARE:
	case NB_EV_ABORT:
	case NB_EV_APPLY:
		/* TODO: implement me. */
		break;
	}

	return NB_OK;
}

int routing_control_plane_protocols_control_plane_protocol_ospf_areas_area_ranges_range_cost_destroy(
	struct nb_cb_destroy_args *args)
{
	switch (args->event) {
	case NB_EV_VALIDATE:
	case NB_EV_PREPARE:
	case NB_EV_ABORT:
	case NB_EV_APPLY:
		/* TODO: implement me. */
		break;
	}

	return NB_OK;
}

/*
 * XPath: /frr-routing:routing/control-plane-protocols/control-plane-protocol/frr-ospfd:ospf/areas/area/ranges/range/substitute
 */
int routing_control_plane_protocols_control_plane_protocol_ospf_areas_area_ranges_range_substitute_modify(
	struct nb_cb_modify_args *args)
{
	switch (args->event) {
	case NB_EV_VALIDATE:
	case NB_EV_PREPARE:
	case NB_EV_ABORT:
	case NB_EV_APPLY:
		/* TODO: implement me. */
		break;
	}

	return NB_OK;
}

int routing_control_plane_protocols_control_plane_protocol_ospf_areas_area_ranges_range_substitute_destroy(
	struct nb_cb_destroy_args *args)
{
	switch (args->event) {
	case NB_EV_VALIDATE:
	case NB_EV_PREPARE:
	case NB_EV_ABORT:
	case NB_EV_APPLY:
		/* TODO: implement me. */
		break;
	}

	return NB_OK;
}

/*
 * XPath: /frr-routing:routing/control-plane-protocols/control-plane-protocol/frr-ospfd:ospf/areas/area/stub
 */
int routing_control_plane_protocols_control_plane_protocol_ospf_areas_area_stub_create(
	struct nb_cb_create_args *args)
{
	switch (args->event) {
	case NB_EV_VALIDATE:
	case NB_EV_PREPARE:
	case NB_EV_ABORT:
	case NB_EV_APPLY:
		/* TODO: implement me. */
		break;
	}

	return NB_OK;
}

int routing_control_plane_protocols_control_plane_protocol_ospf_areas_area_stub_destroy(
	struct nb_cb_destroy_args *args)
{
	switch (args->event) {
	case NB_EV_VALIDATE:
	case NB_EV_PREPARE:
	case NB_EV_ABORT:
	case NB_EV_APPLY:
		/* TODO: implement me. */
		break;
	}

	return NB_OK;
}

/*
 * XPath: /frr-routing:routing/control-plane-protocols/control-plane-protocol/frr-ospfd:ospf/areas/area/stub/no-summary
 */
int routing_control_plane_protocols_control_plane_protocol_ospf_areas_area_stub_no_summary_modify(
	struct nb_cb_modify_args *args)
{
	switch (args->event) {
	case NB_EV_VALIDATE:
	case NB_EV_PREPARE:
	case NB_EV_ABORT:
	case NB_EV_APPLY:
		/* TODO: implement me. */
		break;
	}

	return NB_OK;
}

/*
 * XPath: /frr-routing:routing/control-plane-protocols/control-plane-protocol/frr-ospfd:ospf/areas/area/shortcut/default
 */
int routing_control_plane_protocols_control_plane_protocol_ospf_areas_area_shortcut_default_modify(
	struct nb_cb_modify_args *args)
{
	switch (args->event) {
	case NB_EV_VALIDATE:
	case NB_EV_PREPARE:
	case NB_EV_ABORT:
	case NB_EV_APPLY:
		/* TODO: implement me. */
		break;
	}

	return NB_OK;
}

/*
 * XPath: /frr-routing:routing/control-plane-protocols/control-plane-protocol/frr-ospfd:ospf/areas/area/shortcut/disable
 */
int routing_control_plane_protocols_control_plane_protocol_ospf_areas_area_shortcut_disable_modify(
	struct nb_cb_modify_args *args)
{
	switch (args->event) {
	case NB_EV_VALIDATE:
	case NB_EV_PREPARE:
	case NB_EV_ABORT:
	case NB_EV_APPLY:
		/* TODO: implement me. */
		break;
	}

	return NB_OK;
}

int routing_control_plane_protocols_control_plane_protocol_ospf_areas_area_shortcut_disable_destroy(
	struct nb_cb_destroy_args *args)
{
	switch (args->event) {
	case NB_EV_VALIDATE:
	case NB_EV_PREPARE:
	case NB_EV_ABORT:
	case NB_EV_APPLY:
		/* TODO: implement me. */
		break;
	}

	return NB_OK;
}

/*
 * XPath: /frr-routing:routing/control-plane-protocols/control-plane-protocol/frr-ospfd:ospf/areas/area/shortcut/enable
 */
int routing_control_plane_protocols_control_plane_protocol_ospf_areas_area_shortcut_enable_modify(
	struct nb_cb_modify_args *args)
{
	switch (args->event) {
	case NB_EV_VALIDATE:
	case NB_EV_PREPARE:
	case NB_EV_ABORT:
	case NB_EV_APPLY:
		/* TODO: implement me. */
		break;
	}

	return NB_OK;
}

int routing_control_plane_protocols_control_plane_protocol_ospf_areas_area_shortcut_enable_destroy(
	struct nb_cb_destroy_args *args)
{
	switch (args->event) {
	case NB_EV_VALIDATE:
	case NB_EV_PREPARE:
	case NB_EV_ABORT:
	case NB_EV_APPLY:
		/* TODO: implement me. */
		break;
	}

	return NB_OK;
}

/*
 * XPath: /frr-routing:routing/control-plane-protocols/control-plane-protocol/frr-ospfd:ospf/areas/area/virtual-link
 */
int routing_control_plane_protocols_control_plane_protocol_ospf_areas_area_virtual_link_create(
	struct nb_cb_create_args *args)
{
	switch (args->event) {
	case NB_EV_VALIDATE:
	case NB_EV_PREPARE:
	case NB_EV_ABORT:
	case NB_EV_APPLY:
		/* TODO: implement me. */
		break;
	}

	return NB_OK;
}

int routing_control_plane_protocols_control_plane_protocol_ospf_areas_area_virtual_link_destroy(
	struct nb_cb_destroy_args *args)
{
	switch (args->event) {
	case NB_EV_VALIDATE:
	case NB_EV_PREPARE:
	case NB_EV_ABORT:
	case NB_EV_APPLY:
		/* TODO: implement me. */
		break;
	}

	return NB_OK;
}

/*
 * XPath: /frr-routing:routing/control-plane-protocols/control-plane-protocol/frr-ospfd:ospf/areas/area/virtual-link/authentication
 */
int routing_control_plane_protocols_control_plane_protocol_ospf_areas_area_virtual_link_authentication_create(
	struct nb_cb_create_args *args)
{
	switch (args->event) {
	case NB_EV_VALIDATE:
	case NB_EV_PREPARE:
	case NB_EV_ABORT:
	case NB_EV_APPLY:
		/* TODO: implement me. */
		break;
	}

	return NB_OK;
}

int routing_control_plane_protocols_control_plane_protocol_ospf_areas_area_virtual_link_authentication_destroy(
	struct nb_cb_destroy_args *args)
{
	switch (args->event) {
	case NB_EV_VALIDATE:
	case NB_EV_PREPARE:
	case NB_EV_ABORT:
	case NB_EV_APPLY:
		/* TODO: implement me. */
		break;
	}

	return NB_OK;
}

/*
 * XPath: /frr-routing:routing/control-plane-protocols/control-plane-protocol/frr-ospfd:ospf/areas/area/virtual-link/authentication/message-digest
 */
int routing_control_plane_protocols_control_plane_protocol_ospf_areas_area_virtual_link_authentication_message_digest_modify(
	struct nb_cb_modify_args *args)
{
	switch (args->event) {
	case NB_EV_VALIDATE:
	case NB_EV_PREPARE:
	case NB_EV_ABORT:
	case NB_EV_APPLY:
		/* TODO: implement me. */
		break;
	}

	return NB_OK;
}

int routing_control_plane_protocols_control_plane_protocol_ospf_areas_area_virtual_link_authentication_message_digest_destroy(
	struct nb_cb_destroy_args *args)
{
	switch (args->event) {
	case NB_EV_VALIDATE:
	case NB_EV_PREPARE:
	case NB_EV_ABORT:
	case NB_EV_APPLY:
		/* TODO: implement me. */
		break;
	}

	return NB_OK;
}

/*
 * XPath: /frr-routing:routing/control-plane-protocols/control-plane-protocol/frr-ospfd:ospf/areas/area/virtual-link/authentication/null
 */
int routing_control_plane_protocols_control_plane_protocol_ospf_areas_area_virtual_link_authentication_null_modify(
	struct nb_cb_modify_args *args)
{
	switch (args->event) {
	case NB_EV_VALIDATE:
	case NB_EV_PREPARE:
	case NB_EV_ABORT:
	case NB_EV_APPLY:
		/* TODO: implement me. */
		break;
	}

	return NB_OK;
}

int routing_control_plane_protocols_control_plane_protocol_ospf_areas_area_virtual_link_authentication_null_destroy(
	struct nb_cb_destroy_args *args)
{
	switch (args->event) {
	case NB_EV_VALIDATE:
	case NB_EV_PREPARE:
	case NB_EV_ABORT:
	case NB_EV_APPLY:
		/* TODO: implement me. */
		break;
	}

	return NB_OK;
}

/*
 * XPath: /frr-routing:routing/control-plane-protocols/control-plane-protocol/frr-ospfd:ospf/areas/area/virtual-link/message-digest-key
 */
int routing_control_plane_protocols_control_plane_protocol_ospf_areas_area_virtual_link_message_digest_key_create(
	struct nb_cb_create_args *args)
{
	switch (args->event) {
	case NB_EV_VALIDATE:
	case NB_EV_PREPARE:
	case NB_EV_ABORT:
	case NB_EV_APPLY:
		/* TODO: implement me. */
		break;
	}

	return NB_OK;
}

int routing_control_plane_protocols_control_plane_protocol_ospf_areas_area_virtual_link_message_digest_key_destroy(
	struct nb_cb_destroy_args *args)
{
	switch (args->event) {
	case NB_EV_VALIDATE:
	case NB_EV_PREPARE:
	case NB_EV_ABORT:
	case NB_EV_APPLY:
		/* TODO: implement me. */
		break;
	}

	return NB_OK;
}

/*
 * XPath: /frr-routing:routing/control-plane-protocols/control-plane-protocol/frr-ospfd:ospf/areas/area/virtual-link/message-digest-key/mds-key
 */
int routing_control_plane_protocols_control_plane_protocol_ospf_areas_area_virtual_link_message_digest_key_mds_key_modify(
	struct nb_cb_modify_args *args)
{
	switch (args->event) {
	case NB_EV_VALIDATE:
	case NB_EV_PREPARE:
	case NB_EV_ABORT:
	case NB_EV_APPLY:
		/* TODO: implement me. */
		break;
	}

	return NB_OK;
}

int routing_control_plane_protocols_control_plane_protocol_ospf_areas_area_virtual_link_message_digest_key_mds_key_destroy(
	struct nb_cb_destroy_args *args)
{
	switch (args->event) {
	case NB_EV_VALIDATE:
	case NB_EV_PREPARE:
	case NB_EV_ABORT:
	case NB_EV_APPLY:
		/* TODO: implement me. */
		break;
	}

	return NB_OK;
}

/*
 * XPath: /frr-routing:routing/control-plane-protocols/control-plane-protocol/frr-ospfd:ospf/areas/area/virtual-link/authentication-key
 */
int routing_control_plane_protocols_control_plane_protocol_ospf_areas_area_virtual_link_authentication_key_modify(
	struct nb_cb_modify_args *args)
{
	switch (args->event) {
	case NB_EV_VALIDATE:
	case NB_EV_PREPARE:
	case NB_EV_ABORT:
	case NB_EV_APPLY:
		/* TODO: implement me. */
		break;
	}

	return NB_OK;
}

int routing_control_plane_protocols_control_plane_protocol_ospf_areas_area_virtual_link_authentication_key_destroy(
	struct nb_cb_destroy_args *args)
{
	switch (args->event) {
	case NB_EV_VALIDATE:
	case NB_EV_PREPARE:
	case NB_EV_ABORT:
	case NB_EV_APPLY:
		/* TODO: implement me. */
		break;
	}

	return NB_OK;
}

/*
 * XPath: /frr-routing:routing/control-plane-protocols/control-plane-protocol/frr-ospfd:ospf/areas/area/virtual-link/timers/dead-interval
 */
int routing_control_plane_protocols_control_plane_protocol_ospf_areas_area_virtual_link_timers_dead_interval_modify(
	struct nb_cb_modify_args *args)
{
	switch (args->event) {
	case NB_EV_VALIDATE:
	case NB_EV_PREPARE:
	case NB_EV_ABORT:
	case NB_EV_APPLY:
		/* TODO: implement me. */
		break;
	}

	return NB_OK;
}

int routing_control_plane_protocols_control_plane_protocol_ospf_areas_area_virtual_link_timers_dead_interval_destroy(
	struct nb_cb_destroy_args *args)
{
	switch (args->event) {
	case NB_EV_VALIDATE:
	case NB_EV_PREPARE:
	case NB_EV_ABORT:
	case NB_EV_APPLY:
		/* TODO: implement me. */
		break;
	}

	return NB_OK;
}

/*
 * XPath: /frr-routing:routing/control-plane-protocols/control-plane-protocol/frr-ospfd:ospf/areas/area/virtual-link/timers/hello-interval
 */
int routing_control_plane_protocols_control_plane_protocol_ospf_areas_area_virtual_link_timers_hello_interval_modify(
	struct nb_cb_modify_args *args)
{
	switch (args->event) {
	case NB_EV_VALIDATE:
	case NB_EV_PREPARE:
	case NB_EV_ABORT:
	case NB_EV_APPLY:
		/* TODO: implement me. */
		break;
	}

	return NB_OK;
}

int routing_control_plane_protocols_control_plane_protocol_ospf_areas_area_virtual_link_timers_hello_interval_destroy(
	struct nb_cb_destroy_args *args)
{
	switch (args->event) {
	case NB_EV_VALIDATE:
	case NB_EV_PREPARE:
	case NB_EV_ABORT:
	case NB_EV_APPLY:
		/* TODO: implement me. */
		break;
	}

	return NB_OK;
}

/*
 * XPath: /frr-routing:routing/control-plane-protocols/control-plane-protocol/frr-ospfd:ospf/areas/area/virtual-link/timers/retransmit-interval
 */
int routing_control_plane_protocols_control_plane_protocol_ospf_areas_area_virtual_link_timers_retransmit_interval_modify(
	struct nb_cb_modify_args *args)
{
	switch (args->event) {
	case NB_EV_VALIDATE:
	case NB_EV_PREPARE:
	case NB_EV_ABORT:
	case NB_EV_APPLY:
		/* TODO: implement me. */
		break;
	}

	return NB_OK;
}

int routing_control_plane_protocols_control_plane_protocol_ospf_areas_area_virtual_link_timers_retransmit_interval_destroy(
	struct nb_cb_destroy_args *args)
{
	switch (args->event) {
	case NB_EV_VALIDATE:
	case NB_EV_PREPARE:
	case NB_EV_ABORT:
	case NB_EV_APPLY:
		/* TODO: implement me. */
		break;
	}

	return NB_OK;
}

/*
 * XPath: /frr-routing:routing/control-plane-protocols/control-plane-protocol/frr-ospfd:ospf/areas/area/virtual-link/timers/transmit-delay
 */
int routing_control_plane_protocols_control_plane_protocol_ospf_areas_area_virtual_link_timers_transmit_delay_modify(
	struct nb_cb_modify_args *args)
{
	switch (args->event) {
	case NB_EV_VALIDATE:
	case NB_EV_PREPARE:
	case NB_EV_ABORT:
	case NB_EV_APPLY:
		/* TODO: implement me. */
		break;
	}

	return NB_OK;
}

int routing_control_plane_protocols_control_plane_protocol_ospf_areas_area_virtual_link_timers_transmit_delay_destroy(
	struct nb_cb_destroy_args *args)
{
	switch (args->event) {
	case NB_EV_VALIDATE:
	case NB_EV_PREPARE:
	case NB_EV_ABORT:
	case NB_EV_APPLY:
		/* TODO: implement me. */
		break;
	}

	return NB_OK;
}
