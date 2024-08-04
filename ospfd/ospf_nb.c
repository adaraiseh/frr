// SPDX-License-Identifier: GPL-2.0-or-later
/*
 * Copyright (C) 2024        Okda Networks
 *                           Amjad Daraiseh
 */

#include "northbound.h"
#include "ospfd/ospf_nb.h"

/* clang-format off */
const struct frr_yang_module_info frr_ospfd_info = {
	.name = "frr-ospfd",
	.nodes = {
		{
			.xpath = "/frr-interface:lib/interface/frr-ospfd:ospf/instance",
			.cbs = {
				.create = lib_interface_ospf_instance_create,
				.destroy = lib_interface_ospf_instance_destroy,
			}
		},
		{
			.xpath = "/frr-interface:lib/interface/frr-ospfd:ospf/instance/bfd",
			.cbs = {
				.modify = lib_interface_ospf_instance_bfd_modify,
			}
		},
		{
			.xpath = "/frr-interface:lib/interface/frr-ospfd:ospf/instance/network",
			.cbs = {
				.modify = lib_interface_ospf_instance_network_modify,
				.destroy = lib_interface_ospf_instance_network_destroy,
			}
		},
		{
			.xpath = "/frr-interface:lib/interface/frr-ospfd:ospf/instance/area",
			.cbs = {
				.modify = lib_interface_ospf_instance_area_modify,
				.destroy = lib_interface_ospf_instance_area_destroy,
			}
		},
		{
			.xpath = "/frr-interface:lib/interface/frr-ospfd:ospf/instance/authentication",
			.cbs = {
				.create = lib_interface_ospf_instance_authentication_create,
				.destroy = lib_interface_ospf_instance_authentication_destroy,
			}
		},
		{
			.xpath = "/frr-interface:lib/interface/frr-ospfd:ospf/instance/authentication/message-digest",
			.cbs = {
				.modify = lib_interface_ospf_instance_authentication_message_digest_modify,
				.destroy = lib_interface_ospf_instance_authentication_message_digest_destroy,
			}
		},
		{
			.xpath = "/frr-interface:lib/interface/frr-ospfd:ospf/instance/authentication/null",
			.cbs = {
				.modify = lib_interface_ospf_instance_authentication_null_modify,
				.destroy = lib_interface_ospf_instance_authentication_null_destroy,
			}
		},
		{
			.xpath = "/frr-interface:lib/interface/frr-ospfd:ospf/instance/message-digest-key",
			.cbs = {
				.create = lib_interface_ospf_instance_message_digest_key_create,
				.destroy = lib_interface_ospf_instance_message_digest_key_destroy,
			}
		},
		{
			.xpath = "/frr-interface:lib/interface/frr-ospfd:ospf/instance/message-digest-key/mds-key",
			.cbs = {
				.modify = lib_interface_ospf_instance_message_digest_key_mds_key_modify,
				.destroy = lib_interface_ospf_instance_message_digest_key_mds_key_destroy,
			}
		},
		{
			.xpath = "/frr-interface:lib/interface/frr-ospfd:ospf/instance/authentication-key",
			.cbs = {
				.modify = lib_interface_ospf_instance_authentication_key_modify,
				.destroy = lib_interface_ospf_instance_authentication_key_destroy,
			}
		},
		{
			.xpath = "/frr-interface:lib/interface/frr-ospfd:ospf/instance/cost",
			.cbs = {
				.modify = lib_interface_ospf_instance_cost_modify,
				.destroy = lib_interface_ospf_instance_cost_destroy,
			}
		},
		{
			.xpath = "/frr-interface:lib/interface/frr-ospfd:ospf/instance/dead-interval/interval",
			.cbs = {
				.modify = lib_interface_ospf_instance_dead_interval_interval_modify,
				.destroy = lib_interface_ospf_instance_dead_interval_interval_destroy,
			}
		},
		{
			.xpath = "/frr-interface:lib/interface/frr-ospfd:ospf/instance/dead-interval/minimal/hello-multiplier",
			.cbs = {
				.modify = lib_interface_ospf_instance_dead_interval_minimal_hello_multiplier_modify,
				.destroy = lib_interface_ospf_instance_dead_interval_minimal_hello_multiplier_destroy,
			}
		},
		{
			.xpath = "/frr-interface:lib/interface/frr-ospfd:ospf/instance/hello-interval",
			.cbs = {
				.modify = lib_interface_ospf_instance_hello_interval_modify,
				.destroy = lib_interface_ospf_instance_hello_interval_destroy,
			}
		},
		{
			.xpath = "/frr-interface:lib/interface/frr-ospfd:ospf/instance/retransmit-interval",
			.cbs = {
				.modify = lib_interface_ospf_instance_retransmit_interval_modify,
				.destroy = lib_interface_ospf_instance_retransmit_interval_destroy,
			}
		},
		{
			.xpath = "/frr-interface:lib/interface/frr-ospfd:ospf/instance/transmit-delay",
			.cbs = {
				.modify = lib_interface_ospf_instance_transmit_delay_modify,
				.destroy = lib_interface_ospf_instance_transmit_delay_destroy,
			}
		},
		{
			.xpath = "/frr-interface:lib/interface/frr-ospfd:ospf/instance/mtu-ignore",
			.cbs = {
				.modify = lib_interface_ospf_instance_mtu_ignore_modify,
				.destroy = lib_interface_ospf_instance_mtu_ignore_destroy,
			}
		},
		{
			.xpath = "/frr-interface:lib/interface/frr-ospfd:ospf/instance/priority",
			.cbs = {
				.modify = lib_interface_ospf_instance_priority_modify,
				.destroy = lib_interface_ospf_instance_priority_destroy,
			}
		},
		{
			.xpath = "/frr-interface:lib/interface/frr-ospfd:ospf/instance/interface-address",
			.cbs = {
				.create = lib_interface_ospf_instance_interface_address_create,
				.destroy = lib_interface_ospf_instance_interface_address_destroy,
			}
		},
		{
			.xpath = "/frr-interface:lib/interface/frr-ospfd:ospf/instance/interface-address/area",
			.cbs = {
				.modify = lib_interface_ospf_instance_interface_address_area_modify,
				.destroy = lib_interface_ospf_instance_interface_address_area_destroy,
			}
		},
		{
			.xpath = "/frr-interface:lib/interface/frr-ospfd:ospf/instance/interface-address/authentication",
			.cbs = {
				.create = lib_interface_ospf_instance_interface_address_authentication_create,
				.destroy = lib_interface_ospf_instance_interface_address_authentication_destroy,
			}
		},
		{
			.xpath = "/frr-interface:lib/interface/frr-ospfd:ospf/instance/interface-address/authentication/message-digest",
			.cbs = {
				.modify = lib_interface_ospf_instance_interface_address_authentication_message_digest_modify,
				.destroy = lib_interface_ospf_instance_interface_address_authentication_message_digest_destroy,
			}
		},
		{
			.xpath = "/frr-interface:lib/interface/frr-ospfd:ospf/instance/interface-address/authentication/null",
			.cbs = {
				.modify = lib_interface_ospf_instance_interface_address_authentication_null_modify,
				.destroy = lib_interface_ospf_instance_interface_address_authentication_null_destroy,
			}
		},
		{
			.xpath = "/frr-interface:lib/interface/frr-ospfd:ospf/instance/interface-address/message-digest-key",
			.cbs = {
				.create = lib_interface_ospf_instance_interface_address_message_digest_key_create,
				.destroy = lib_interface_ospf_instance_interface_address_message_digest_key_destroy,
			}
		},
		{
			.xpath = "/frr-interface:lib/interface/frr-ospfd:ospf/instance/interface-address/message-digest-key/mds-key",
			.cbs = {
				.modify = lib_interface_ospf_instance_interface_address_message_digest_key_mds_key_modify,
				.destroy = lib_interface_ospf_instance_interface_address_message_digest_key_mds_key_destroy,
			}
		},
		{
			.xpath = "/frr-interface:lib/interface/frr-ospfd:ospf/instance/interface-address/authentication-key",
			.cbs = {
				.modify = lib_interface_ospf_instance_interface_address_authentication_key_modify,
				.destroy = lib_interface_ospf_instance_interface_address_authentication_key_destroy,
			}
		},
		{
			.xpath = "/frr-interface:lib/interface/frr-ospfd:ospf/instance/interface-address/cost",
			.cbs = {
				.modify = lib_interface_ospf_instance_interface_address_cost_modify,
				.destroy = lib_interface_ospf_instance_interface_address_cost_destroy,
			}
		},
		{
			.xpath = "/frr-interface:lib/interface/frr-ospfd:ospf/instance/interface-address/dead-interval/interval",
			.cbs = {
				.modify = lib_interface_ospf_instance_interface_address_dead_interval_interval_modify,
				.destroy = lib_interface_ospf_instance_interface_address_dead_interval_interval_destroy,
			}
		},
		{
			.xpath = "/frr-interface:lib/interface/frr-ospfd:ospf/instance/interface-address/dead-interval/minimal/hello-multiplier",
			.cbs = {
				.modify = lib_interface_ospf_instance_interface_address_dead_interval_minimal_hello_multiplier_modify,
				.destroy = lib_interface_ospf_instance_interface_address_dead_interval_minimal_hello_multiplier_destroy,
			}
		},
		{
			.xpath = "/frr-interface:lib/interface/frr-ospfd:ospf/instance/interface-address/hello-interval",
			.cbs = {
				.modify = lib_interface_ospf_instance_interface_address_hello_interval_modify,
				.destroy = lib_interface_ospf_instance_interface_address_hello_interval_destroy,
			}
		},
		{
			.xpath = "/frr-interface:lib/interface/frr-ospfd:ospf/instance/interface-address/retransmit-interval",
			.cbs = {
				.modify = lib_interface_ospf_instance_interface_address_retransmit_interval_modify,
				.destroy = lib_interface_ospf_instance_interface_address_retransmit_interval_destroy,
			}
		},
		{
			.xpath = "/frr-interface:lib/interface/frr-ospfd:ospf/instance/interface-address/transmit-delay",
			.cbs = {
				.modify = lib_interface_ospf_instance_interface_address_transmit_delay_modify,
				.destroy = lib_interface_ospf_instance_interface_address_transmit_delay_destroy,
			}
		},
		{
			.xpath = "/frr-interface:lib/interface/frr-ospfd:ospf/instance/interface-address/mtu-ignore",
			.cbs = {
				.modify = lib_interface_ospf_instance_interface_address_mtu_ignore_modify,
				.destroy = lib_interface_ospf_instance_interface_address_mtu_ignore_destroy,
			}
		},
		{
			.xpath = "/frr-interface:lib/interface/frr-ospfd:ospf/instance/interface-address/priority",
			.cbs = {
				.modify = lib_interface_ospf_instance_interface_address_priority_modify,
				.destroy = lib_interface_ospf_instance_interface_address_priority_destroy,
			}
		},
		{
			.xpath = "/frr-routing:routing/control-plane-protocols/control-plane-protocol/frr-ospfd:ospf/auto-cost-reference-bandwidth",
			.cbs = {
				.modify = routing_control_plane_protocols_control_plane_protocol_ospf_auto_cost_reference_bandwidth_modify,
				.destroy = routing_control_plane_protocols_control_plane_protocol_ospf_auto_cost_reference_bandwidth_destroy,
			}
		},
		{
			.xpath = "/frr-routing:routing/control-plane-protocols/control-plane-protocol/frr-ospfd:ospf/use-arp",
			.cbs = {
				.modify = routing_control_plane_protocols_control_plane_protocol_ospf_use_arp_modify,
			}
		},
		{
			.xpath = "/frr-routing:routing/control-plane-protocols/control-plane-protocol/frr-ospfd:ospf/capability-opaque",
			.cbs = {
				.modify = routing_control_plane_protocols_control_plane_protocol_ospf_capability_opaque_modify,
			}
		},
		{
			.xpath = "/frr-routing:routing/control-plane-protocols/control-plane-protocol/frr-ospfd:ospf/compatible-rfc1583",
			.cbs = {
				.modify = routing_control_plane_protocols_control_plane_protocol_ospf_compatible_rfc1583_modify,
				.destroy = routing_control_plane_protocols_control_plane_protocol_ospf_compatible_rfc1583_destroy,
			}
		},
		{
			.xpath = "/frr-routing:routing/control-plane-protocols/control-plane-protocol/frr-ospfd:ospf/default-metric",
			.cbs = {
				.modify = routing_control_plane_protocols_control_plane_protocol_ospf_default_metric_modify,
				.destroy = routing_control_plane_protocols_control_plane_protocol_ospf_default_metric_destroy,
			}
		},
		{
			.xpath = "/frr-routing:routing/control-plane-protocols/control-plane-protocol/frr-ospfd:ospf/write-multiplier",
			.cbs = {
				.modify = routing_control_plane_protocols_control_plane_protocol_ospf_write_multiplier_modify,
				.destroy = routing_control_plane_protocols_control_plane_protocol_ospf_write_multiplier_destroy,
			}
		},
		{
			.xpath = "/frr-routing:routing/control-plane-protocols/control-plane-protocol/frr-ospfd:ospf/router-info",
			.cbs = {
				.modify = routing_control_plane_protocols_control_plane_protocol_ospf_router_info_modify,
				.destroy = routing_control_plane_protocols_control_plane_protocol_ospf_router_info_destroy,
			}
		},
		{
			.xpath = "/frr-routing:routing/control-plane-protocols/control-plane-protocol/frr-ospfd:ospf/default-information",
			.cbs = {
				.apply_finish =  routing_control_plane_protocols_control_plane_protocol_ospf_default_information_apply_finish,
			},
		},
		{
			.xpath = "/frr-routing:routing/control-plane-protocols/control-plane-protocol/frr-ospfd:ospf/default-information/originate",
			.cbs = {
				.modify = routing_control_plane_protocols_control_plane_protocol_ospf_default_information_originate_modify,
				.destroy = routing_control_plane_protocols_control_plane_protocol_ospf_default_information_originate_destroy,
			}
		},
		{
			.xpath = "/frr-routing:routing/control-plane-protocols/control-plane-protocol/frr-ospfd:ospf/default-information/always",
			.cbs = {
				.modify = routing_control_plane_protocols_control_plane_protocol_ospf_default_information_always_modify,
				.destroy = routing_control_plane_protocols_control_plane_protocol_ospf_default_information_always_destroy,
			}
		},
		{
			.xpath = "/frr-routing:routing/control-plane-protocols/control-plane-protocol/frr-ospfd:ospf/default-information/metric",
			.cbs = {
				.modify = routing_control_plane_protocols_control_plane_protocol_ospf_default_information_metric_modify,
				.destroy = routing_control_plane_protocols_control_plane_protocol_ospf_default_information_metric_destroy,
			}
		},
		{
			.xpath = "/frr-routing:routing/control-plane-protocols/control-plane-protocol/frr-ospfd:ospf/default-information/metric-type",
			.cbs = {
				.modify = routing_control_plane_protocols_control_plane_protocol_ospf_default_information_metric_type_modify,
				.destroy = routing_control_plane_protocols_control_plane_protocol_ospf_default_information_metric_type_destroy,
			}
		},
		{
			.xpath = "/frr-routing:routing/control-plane-protocols/control-plane-protocol/frr-ospfd:ospf/default-information/route-map",
			.cbs = {
				.modify = routing_control_plane_protocols_control_plane_protocol_ospf_default_information_route_map_modify,
				.destroy = routing_control_plane_protocols_control_plane_protocol_ospf_default_information_route_map_destroy,
			}
		},
		{
			.xpath = "/frr-routing:routing/control-plane-protocols/control-plane-protocol/frr-ospfd:ospf/redistribute",
			.cbs = {
				.create = routing_control_plane_protocols_control_plane_protocol_ospf_redistribute_create,
				.destroy = routing_control_plane_protocols_control_plane_protocol_ospf_redistribute_destroy,
			}
		},
		{
			.xpath = "/frr-routing:routing/control-plane-protocols/control-plane-protocol/frr-ospfd:ospf/redistribute/metric",
			.cbs = {
				.modify = routing_control_plane_protocols_control_plane_protocol_ospf_redistribute_metric_modify,
				.destroy = routing_control_plane_protocols_control_plane_protocol_ospf_redistribute_metric_destroy,
			}
		},
		{
			.xpath = "/frr-routing:routing/control-plane-protocols/control-plane-protocol/frr-ospfd:ospf/redistribute/metric-type",
			.cbs = {
				.modify = routing_control_plane_protocols_control_plane_protocol_ospf_redistribute_metric_type_modify,
				.destroy = routing_control_plane_protocols_control_plane_protocol_ospf_redistribute_metric_type_destroy,
			}
		},
		{
			.xpath = "/frr-routing:routing/control-plane-protocols/control-plane-protocol/frr-ospfd:ospf/redistribute/route-map",
			.cbs = {
				.modify = routing_control_plane_protocols_control_plane_protocol_ospf_redistribute_route_map_modify,
				.destroy = routing_control_plane_protocols_control_plane_protocol_ospf_redistribute_route_map_destroy,
			}
		},
		{
			.xpath = "/frr-routing:routing/control-plane-protocols/control-plane-protocol/frr-ospfd:ospf/distance/admin-value",
			.cbs = {
				.modify = routing_control_plane_protocols_control_plane_protocol_ospf_distance_admin_value_modify,
				.destroy = routing_control_plane_protocols_control_plane_protocol_ospf_distance_admin_value_destroy,
			}
		},
		{
			.xpath = "/frr-routing:routing/control-plane-protocols/control-plane-protocol/frr-ospfd:ospf/distance/ospf/external",
			.cbs = {
				.modify = routing_control_plane_protocols_control_plane_protocol_ospf_distance_ospf_external_modify,
				.destroy = routing_control_plane_protocols_control_plane_protocol_ospf_distance_ospf_external_destroy,
			}
		},
		{
			.xpath = "/frr-routing:routing/control-plane-protocols/control-plane-protocol/frr-ospfd:ospf/distance/ospf/inter-area",
			.cbs = {
				.modify = routing_control_plane_protocols_control_plane_protocol_ospf_distance_ospf_inter_area_modify,
				.destroy = routing_control_plane_protocols_control_plane_protocol_ospf_distance_ospf_inter_area_destroy,
			}
		},
		{
			.xpath = "/frr-routing:routing/control-plane-protocols/control-plane-protocol/frr-ospfd:ospf/distance/ospf/intra-area",
			.cbs = {
				.modify = routing_control_plane_protocols_control_plane_protocol_ospf_distance_ospf_intra_area_modify,
				.destroy = routing_control_plane_protocols_control_plane_protocol_ospf_distance_ospf_intra_area_destroy,
			}
		},
		{
			.xpath = "/frr-routing:routing/control-plane-protocols/control-plane-protocol/frr-ospfd:ospf/distribute-list/dlist",
			.cbs = {
				.create = routing_control_plane_protocols_control_plane_protocol_ospf_distribute_list_dlist_create,
				.destroy = routing_control_plane_protocols_control_plane_protocol_ospf_distribute_list_dlist_destroy,
			}
		},
		{
			.xpath = "/frr-routing:routing/control-plane-protocols/control-plane-protocol/frr-ospfd:ospf/max-metric/router-lsa/administrative",
			.cbs = {
				.modify = routing_control_plane_protocols_control_plane_protocol_ospf_max_metric_router_lsa_administrative_modify,
				.destroy = routing_control_plane_protocols_control_plane_protocol_ospf_max_metric_router_lsa_administrative_destroy,
			}
		},
		{
			.xpath = "/frr-routing:routing/control-plane-protocols/control-plane-protocol/frr-ospfd:ospf/max-metric/router-lsa/on-shutdown",
			.cbs = {
				.modify = routing_control_plane_protocols_control_plane_protocol_ospf_max_metric_router_lsa_on_shutdown_modify,
				.destroy = routing_control_plane_protocols_control_plane_protocol_ospf_max_metric_router_lsa_on_shutdown_destroy,
			}
		},
		{
			.xpath = "/frr-routing:routing/control-plane-protocols/control-plane-protocol/frr-ospfd:ospf/max-metric/router-lsa/on-startup",
			.cbs = {
				.modify = routing_control_plane_protocols_control_plane_protocol_ospf_max_metric_router_lsa_on_startup_modify,
				.destroy = routing_control_plane_protocols_control_plane_protocol_ospf_max_metric_router_lsa_on_startup_destroy,
			}
		},
		{
			.xpath = "/frr-routing:routing/control-plane-protocols/control-plane-protocol/frr-ospfd:ospf/mpls-te/on",
			.cbs = {
				.modify = routing_control_plane_protocols_control_plane_protocol_ospf_mpls_te_on_modify,
				.destroy = routing_control_plane_protocols_control_plane_protocol_ospf_mpls_te_on_destroy,
			}
		},
		{
			.xpath = "/frr-routing:routing/control-plane-protocols/control-plane-protocol/frr-ospfd:ospf/mpls-te/router-address",
			.cbs = {
				.modify = routing_control_plane_protocols_control_plane_protocol_ospf_mpls_te_router_address_modify,
				.destroy = routing_control_plane_protocols_control_plane_protocol_ospf_mpls_te_router_address_destroy,
			}
		},
		{
			.xpath = "/frr-routing:routing/control-plane-protocols/control-plane-protocol/frr-ospfd:ospf/mpls-te/inter-as/as",
			.cbs = {
				.modify = routing_control_plane_protocols_control_plane_protocol_ospf_mpls_te_inter_as_as_modify,
				.destroy = routing_control_plane_protocols_control_plane_protocol_ospf_mpls_te_inter_as_as_destroy,
			}
		},
		{
			.xpath = "/frr-routing:routing/control-plane-protocols/control-plane-protocol/frr-ospfd:ospf/mpls-te/inter-as/area",
			.cbs = {
				.modify = routing_control_plane_protocols_control_plane_protocol_ospf_mpls_te_inter_as_area_modify,
				.destroy = routing_control_plane_protocols_control_plane_protocol_ospf_mpls_te_inter_as_area_destroy,
			}
		},
		{
			.xpath = "/frr-routing:routing/control-plane-protocols/control-plane-protocol/frr-ospfd:ospf/ospf/abr-type",
			.cbs = {
				.modify = routing_control_plane_protocols_control_plane_protocol_ospf_ospf_abr_type_modify,
				.destroy = routing_control_plane_protocols_control_plane_protocol_ospf_ospf_abr_type_destroy,
			}
		},
		{
			.xpath = "/frr-routing:routing/control-plane-protocols/control-plane-protocol/frr-ospfd:ospf/ospf/opaque-lsa",
			.cbs = {
				.modify = routing_control_plane_protocols_control_plane_protocol_ospf_ospf_opaque_lsa_modify,
				.destroy = routing_control_plane_protocols_control_plane_protocol_ospf_ospf_opaque_lsa_destroy,
			}
		},
		{
			.xpath = "/frr-routing:routing/control-plane-protocols/control-plane-protocol/frr-ospfd:ospf/ospf/rfc1583compatibility",
			.cbs = {
				.modify = routing_control_plane_protocols_control_plane_protocol_ospf_ospf_rfc1583compatibility_modify,
				.destroy = routing_control_plane_protocols_control_plane_protocol_ospf_ospf_rfc1583compatibility_destroy,
			}
		},
		{
			.xpath = "/frr-routing:routing/control-plane-protocols/control-plane-protocol/frr-ospfd:ospf/ospf/router-id",
			.cbs = {
				.modify = routing_control_plane_protocols_control_plane_protocol_ospf_ospf_router_id_modify,
				.destroy = routing_control_plane_protocols_control_plane_protocol_ospf_ospf_router_id_destroy,
			}
		},
		{
			.xpath = "/frr-routing:routing/control-plane-protocols/control-plane-protocol/frr-ospfd:ospf/ospf/write-multiplier",
			.cbs = {
				.modify = routing_control_plane_protocols_control_plane_protocol_ospf_ospf_write_multiplier_modify,
				.destroy = routing_control_plane_protocols_control_plane_protocol_ospf_ospf_write_multiplier_destroy,
			}
		},
		{
			.xpath = "/frr-routing:routing/control-plane-protocols/control-plane-protocol/frr-ospfd:ospf/timers/refresh-interval",
			.cbs = {
				.modify = routing_control_plane_protocols_control_plane_protocol_ospf_timers_refresh_interval_modify,
				.destroy = routing_control_plane_protocols_control_plane_protocol_ospf_timers_refresh_interval_destroy,
			}
		},
		{
			.xpath = "/frr-routing:routing/control-plane-protocols/control-plane-protocol/frr-ospfd:ospf/timers/lsa-min-arrival",
			.cbs = {
				.modify = routing_control_plane_protocols_control_plane_protocol_ospf_timers_lsa_min_arrival_modify,
				.destroy = routing_control_plane_protocols_control_plane_protocol_ospf_timers_lsa_min_arrival_destroy,
			}
		},
		{
			.xpath = "/frr-routing:routing/control-plane-protocols/control-plane-protocol/frr-ospfd:ospf/timers/throttle/lsa-all",
			.cbs = {
				.modify = routing_control_plane_protocols_control_plane_protocol_ospf_timers_throttle_lsa_all_modify,
				.destroy = routing_control_plane_protocols_control_plane_protocol_ospf_timers_throttle_lsa_all_destroy,
			}
		},
		{
			.xpath = "/frr-routing:routing/control-plane-protocols/control-plane-protocol/frr-ospfd:ospf/timers/throttle/spf",
			.cbs = {
				.modify = routing_control_plane_protocols_control_plane_protocol_ospf_timers_throttle_spf_modify,
				.destroy = routing_control_plane_protocols_control_plane_protocol_ospf_timers_throttle_spf_destroy,
			}
		},
		{
			.xpath = "/frr-routing:routing/control-plane-protocols/control-plane-protocol/frr-ospfd:ospf/segment-routing/global-block/lower-bound",
			.cbs = {
				.modify = routing_control_plane_protocols_control_plane_protocol_ospf_segment_routing_global_block_lower_bound_modify,
			}
		},
		{
			.xpath = "/frr-routing:routing/control-plane-protocols/control-plane-protocol/frr-ospfd:ospf/segment-routing/global-block/upper-bound",
			.cbs = {
				.modify = routing_control_plane_protocols_control_plane_protocol_ospf_segment_routing_global_block_upper_bound_modify,
			}
		},
		{
			.xpath = "/frr-routing:routing/control-plane-protocols/control-plane-protocol/frr-ospfd:ospf/segment-routing/srlb/lower-bound",
			.cbs = {
				.modify = routing_control_plane_protocols_control_plane_protocol_ospf_segment_routing_srlb_lower_bound_modify,
			}
		},
		{
			.xpath = "/frr-routing:routing/control-plane-protocols/control-plane-protocol/frr-ospfd:ospf/segment-routing/srlb/upper-bound",
			.cbs = {
				.modify = routing_control_plane_protocols_control_plane_protocol_ospf_segment_routing_srlb_upper_bound_modify,
			}
		},
		{
			.xpath = "/frr-routing:routing/control-plane-protocols/control-plane-protocol/frr-ospfd:ospf/segment-routing/node-msd",
			.cbs = {
				.modify = routing_control_plane_protocols_control_plane_protocol_ospf_segment_routing_node_msd_modify,
				.destroy = routing_control_plane_protocols_control_plane_protocol_ospf_segment_routing_node_msd_destroy,
			}
		},
		{
			.xpath = "/frr-routing:routing/control-plane-protocols/control-plane-protocol/frr-ospfd:ospf/segment-routing/on",
			.cbs = {
				.modify = routing_control_plane_protocols_control_plane_protocol_ospf_segment_routing_on_modify,
				.destroy = routing_control_plane_protocols_control_plane_protocol_ospf_segment_routing_on_destroy,
			}
		},
		{
			.xpath = "/frr-routing:routing/control-plane-protocols/control-plane-protocol/frr-ospfd:ospf/segment-routing/prefix-sid",
			.cbs = {
				.create = routing_control_plane_protocols_control_plane_protocol_ospf_segment_routing_prefix_sid_create,
				.destroy = routing_control_plane_protocols_control_plane_protocol_ospf_segment_routing_prefix_sid_destroy,
			}
		},
		{
			.xpath = "/frr-routing:routing/control-plane-protocols/control-plane-protocol/frr-ospfd:ospf/segment-routing/prefix-sid/prefix",
			.cbs = {
				.modify = routing_control_plane_protocols_control_plane_protocol_ospf_segment_routing_prefix_sid_prefix_modify,
				.destroy = routing_control_plane_protocols_control_plane_protocol_ospf_segment_routing_prefix_sid_prefix_destroy,
			}
		},
		{
			.xpath = "/frr-routing:routing/control-plane-protocols/control-plane-protocol/frr-ospfd:ospf/segment-routing/prefix-sid/last-hop-behavior",
			.cbs = {
				.modify = routing_control_plane_protocols_control_plane_protocol_ospf_segment_routing_prefix_sid_last_hop_behavior_modify,
			}
		},
		{
			.xpath = "/frr-routing:routing/control-plane-protocols/control-plane-protocol/frr-ospfd:ospf/neighbor",
			.cbs = {
				.create = routing_control_plane_protocols_control_plane_protocol_ospf_neighbor_create,
				.destroy = routing_control_plane_protocols_control_plane_protocol_ospf_neighbor_destroy,
			}
		},
		{
			.xpath = "/frr-routing:routing/control-plane-protocols/control-plane-protocol/frr-ospfd:ospf/neighbor/priority",
			.cbs = {
				.modify = routing_control_plane_protocols_control_plane_protocol_ospf_neighbor_priority_modify,
				.destroy = routing_control_plane_protocols_control_plane_protocol_ospf_neighbor_priority_destroy,
			}
		},
		{
			.xpath = "/frr-routing:routing/control-plane-protocols/control-plane-protocol/frr-ospfd:ospf/neighbor/poll-interval",
			.cbs = {
				.modify = routing_control_plane_protocols_control_plane_protocol_ospf_neighbor_poll_interval_modify,
				.destroy = routing_control_plane_protocols_control_plane_protocol_ospf_neighbor_poll_interval_destroy,
			}
		},
		{
			.xpath = "/frr-routing:routing/control-plane-protocols/control-plane-protocol/frr-ospfd:ospf/network",
			.cbs = {
				.create = routing_control_plane_protocols_control_plane_protocol_ospf_network_create,
				.destroy = routing_control_plane_protocols_control_plane_protocol_ospf_network_destroy,
			}
		},
		{
			.xpath = "/frr-routing:routing/control-plane-protocols/control-plane-protocol/frr-ospfd:ospf/network/area",
			.cbs = {
				.modify = routing_control_plane_protocols_control_plane_protocol_ospf_network_area_modify,
				.destroy = routing_control_plane_protocols_control_plane_protocol_ospf_network_area_destroy,
			}
		},
		{
			.xpath = "/frr-routing:routing/control-plane-protocols/control-plane-protocol/frr-ospfd:ospf/passive-interface",
			.cbs = {
				.create = routing_control_plane_protocols_control_plane_protocol_ospf_passive_interface_create,
				.destroy = routing_control_plane_protocols_control_plane_protocol_ospf_passive_interface_destroy,
			}
		},
		{
			.xpath = "/frr-routing:routing/control-plane-protocols/control-plane-protocol/frr-ospfd:ospf/passive-interface/address",
			.cbs = {
				.modify = routing_control_plane_protocols_control_plane_protocol_ospf_passive_interface_address_modify,
				.destroy = routing_control_plane_protocols_control_plane_protocol_ospf_passive_interface_address_destroy,
			}
		},
		{
			.xpath = "/frr-routing:routing/control-plane-protocols/control-plane-protocol/frr-ospfd:ospf/areas/area",
			.cbs = {
				.create = routing_control_plane_protocols_control_plane_protocol_ospf_areas_area_create,
				.destroy = routing_control_plane_protocols_control_plane_protocol_ospf_areas_area_destroy,
			}
		},
		{
			.xpath = "/frr-routing:routing/control-plane-protocols/control-plane-protocol/frr-ospfd:ospf/areas/area/authentication",
			.cbs = {
				.create = routing_control_plane_protocols_control_plane_protocol_ospf_areas_area_authentication_create,
				.destroy = routing_control_plane_protocols_control_plane_protocol_ospf_areas_area_authentication_destroy,
			}
		},
		{
			.xpath = "/frr-routing:routing/control-plane-protocols/control-plane-protocol/frr-ospfd:ospf/areas/area/authentication/message-digest",
			.cbs = {
				.modify = routing_control_plane_protocols_control_plane_protocol_ospf_areas_area_authentication_message_digest_modify,
				.destroy = routing_control_plane_protocols_control_plane_protocol_ospf_areas_area_authentication_message_digest_destroy,
			}
		},
		{
			.xpath = "/frr-routing:routing/control-plane-protocols/control-plane-protocol/frr-ospfd:ospf/areas/area/default-cost",
			.cbs = {
				.modify = routing_control_plane_protocols_control_plane_protocol_ospf_areas_area_default_cost_modify,
				.destroy = routing_control_plane_protocols_control_plane_protocol_ospf_areas_area_default_cost_destroy,
			}
		},
		{
			.xpath = "/frr-routing:routing/control-plane-protocols/control-plane-protocol/frr-ospfd:ospf/areas/area/export-list",
			.cbs = {
				.modify = routing_control_plane_protocols_control_plane_protocol_ospf_areas_area_export_list_modify,
				.destroy = routing_control_plane_protocols_control_plane_protocol_ospf_areas_area_export_list_destroy,
			}
		},
		{
			.xpath = "/frr-routing:routing/control-plane-protocols/control-plane-protocol/frr-ospfd:ospf/areas/area/import-list",
			.cbs = {
				.modify = routing_control_plane_protocols_control_plane_protocol_ospf_areas_area_import_list_modify,
				.destroy = routing_control_plane_protocols_control_plane_protocol_ospf_areas_area_import_list_destroy,
			}
		},
		{
			.xpath = "/frr-routing:routing/control-plane-protocols/control-plane-protocol/frr-ospfd:ospf/areas/area/filter-list/prefix",
			.cbs = {
				.modify = routing_control_plane_protocols_control_plane_protocol_ospf_areas_area_filter_list_prefix_modify,
				.destroy = routing_control_plane_protocols_control_plane_protocol_ospf_areas_area_filter_list_prefix_destroy,
			}
		},
		{
			.xpath = "/frr-routing:routing/control-plane-protocols/control-plane-protocol/frr-ospfd:ospf/areas/area/filter-list/in",
			.cbs = {
				.modify = routing_control_plane_protocols_control_plane_protocol_ospf_areas_area_filter_list_in_modify,
				.destroy = routing_control_plane_protocols_control_plane_protocol_ospf_areas_area_filter_list_in_destroy,
			}
		},
		{
			.xpath = "/frr-routing:routing/control-plane-protocols/control-plane-protocol/frr-ospfd:ospf/areas/area/filter-list/out",
			.cbs = {
				.modify = routing_control_plane_protocols_control_plane_protocol_ospf_areas_area_filter_list_out_modify,
				.destroy = routing_control_plane_protocols_control_plane_protocol_ospf_areas_area_filter_list_out_destroy,
			}
		},
		{
			.xpath = "/frr-routing:routing/control-plane-protocols/control-plane-protocol/frr-ospfd:ospf/areas/area/nssa",
			.cbs = {
				.create = routing_control_plane_protocols_control_plane_protocol_ospf_areas_area_nssa_create,
				.destroy = routing_control_plane_protocols_control_plane_protocol_ospf_areas_area_nssa_destroy,
			}
		},
		{
			.xpath = "/frr-routing:routing/control-plane-protocols/control-plane-protocol/frr-ospfd:ospf/areas/area/nssa/no-summary",
			.cbs = {
				.modify = routing_control_plane_protocols_control_plane_protocol_ospf_areas_area_nssa_no_summary_modify,
			}
		},
		{
			.xpath = "/frr-routing:routing/control-plane-protocols/control-plane-protocol/frr-ospfd:ospf/areas/area/nssa/translate-always",
			.cbs = {
				.modify = routing_control_plane_protocols_control_plane_protocol_ospf_areas_area_nssa_translate_always_modify,
			}
		},
		{
			.xpath = "/frr-routing:routing/control-plane-protocols/control-plane-protocol/frr-ospfd:ospf/areas/area/nssa/translate-candidate",
			.cbs = {
				.modify = routing_control_plane_protocols_control_plane_protocol_ospf_areas_area_nssa_translate_candidate_modify,
			}
		},
		{
			.xpath = "/frr-routing:routing/control-plane-protocols/control-plane-protocol/frr-ospfd:ospf/areas/area/nssa/translate-never",
			.cbs = {
				.modify = routing_control_plane_protocols_control_plane_protocol_ospf_areas_area_nssa_translate_never_modify,
			}
		},
		{
			.xpath = "/frr-routing:routing/control-plane-protocols/control-plane-protocol/frr-ospfd:ospf/areas/area/ranges/range",
			.cbs = {
				.create = routing_control_plane_protocols_control_plane_protocol_ospf_areas_area_ranges_range_create,
				.destroy = routing_control_plane_protocols_control_plane_protocol_ospf_areas_area_ranges_range_destroy,
			}
		},
		{
			.xpath = "/frr-routing:routing/control-plane-protocols/control-plane-protocol/frr-ospfd:ospf/areas/area/ranges/range/advertise",
			.cbs = {
				.modify = routing_control_plane_protocols_control_plane_protocol_ospf_areas_area_ranges_range_advertise_modify,
				.destroy = routing_control_plane_protocols_control_plane_protocol_ospf_areas_area_ranges_range_advertise_destroy,
			}
		},
		{
			.xpath = "/frr-routing:routing/control-plane-protocols/control-plane-protocol/frr-ospfd:ospf/areas/area/ranges/range/not-advertise",
			.cbs = {
				.modify = routing_control_plane_protocols_control_plane_protocol_ospf_areas_area_ranges_range_not_advertise_modify,
			}
		},
		{
			.xpath = "/frr-routing:routing/control-plane-protocols/control-plane-protocol/frr-ospfd:ospf/areas/area/ranges/range/cost",
			.cbs = {
				.modify = routing_control_plane_protocols_control_plane_protocol_ospf_areas_area_ranges_range_cost_modify,
				.destroy = routing_control_plane_protocols_control_plane_protocol_ospf_areas_area_ranges_range_cost_destroy,
			}
		},
		{
			.xpath = "/frr-routing:routing/control-plane-protocols/control-plane-protocol/frr-ospfd:ospf/areas/area/ranges/range/substitute",
			.cbs = {
				.modify = routing_control_plane_protocols_control_plane_protocol_ospf_areas_area_ranges_range_substitute_modify,
				.destroy = routing_control_plane_protocols_control_plane_protocol_ospf_areas_area_ranges_range_substitute_destroy,
			}
		},
		{
			.xpath = "/frr-routing:routing/control-plane-protocols/control-plane-protocol/frr-ospfd:ospf/areas/area/stub",
			.cbs = {
				.create = routing_control_plane_protocols_control_plane_protocol_ospf_areas_area_stub_create,
				.destroy = routing_control_plane_protocols_control_plane_protocol_ospf_areas_area_stub_destroy,
			}
		},
		{
			.xpath = "/frr-routing:routing/control-plane-protocols/control-plane-protocol/frr-ospfd:ospf/areas/area/stub/no-summary",
			.cbs = {
				.modify = routing_control_plane_protocols_control_plane_protocol_ospf_areas_area_stub_no_summary_modify,
			}
		},
		{
			.xpath = "/frr-routing:routing/control-plane-protocols/control-plane-protocol/frr-ospfd:ospf/areas/area/shortcut/default",
			.cbs = {
				.modify = routing_control_plane_protocols_control_plane_protocol_ospf_areas_area_shortcut_default_modify,
			}
		},
		{
			.xpath = "/frr-routing:routing/control-plane-protocols/control-plane-protocol/frr-ospfd:ospf/areas/area/shortcut/disable",
			.cbs = {
				.modify = routing_control_plane_protocols_control_plane_protocol_ospf_areas_area_shortcut_disable_modify,
				.destroy = routing_control_plane_protocols_control_plane_protocol_ospf_areas_area_shortcut_disable_destroy,
			}
		},
		{
			.xpath = "/frr-routing:routing/control-plane-protocols/control-plane-protocol/frr-ospfd:ospf/areas/area/shortcut/enable",
			.cbs = {
				.modify = routing_control_plane_protocols_control_plane_protocol_ospf_areas_area_shortcut_enable_modify,
				.destroy = routing_control_plane_protocols_control_plane_protocol_ospf_areas_area_shortcut_enable_destroy,
			}
		},
		{
			.xpath = "/frr-routing:routing/control-plane-protocols/control-plane-protocol/frr-ospfd:ospf/areas/area/virtual-link",
			.cbs = {
				.create = routing_control_plane_protocols_control_plane_protocol_ospf_areas_area_virtual_link_create,
				.destroy = routing_control_plane_protocols_control_plane_protocol_ospf_areas_area_virtual_link_destroy,
			}
		},
		{
			.xpath = "/frr-routing:routing/control-plane-protocols/control-plane-protocol/frr-ospfd:ospf/areas/area/virtual-link/authentication",
			.cbs = {
				.create = routing_control_plane_protocols_control_plane_protocol_ospf_areas_area_virtual_link_authentication_create,
				.destroy = routing_control_plane_protocols_control_plane_protocol_ospf_areas_area_virtual_link_authentication_destroy,
			}
		},
		{
			.xpath = "/frr-routing:routing/control-plane-protocols/control-plane-protocol/frr-ospfd:ospf/areas/area/virtual-link/authentication/message-digest",
			.cbs = {
				.modify = routing_control_plane_protocols_control_plane_protocol_ospf_areas_area_virtual_link_authentication_message_digest_modify,
				.destroy = routing_control_plane_protocols_control_plane_protocol_ospf_areas_area_virtual_link_authentication_message_digest_destroy,
			}
		},
		{
			.xpath = "/frr-routing:routing/control-plane-protocols/control-plane-protocol/frr-ospfd:ospf/areas/area/virtual-link/authentication/null",
			.cbs = {
				.modify = routing_control_plane_protocols_control_plane_protocol_ospf_areas_area_virtual_link_authentication_null_modify,
				.destroy = routing_control_plane_protocols_control_plane_protocol_ospf_areas_area_virtual_link_authentication_null_destroy,
			}
		},
		{
			.xpath = "/frr-routing:routing/control-plane-protocols/control-plane-protocol/frr-ospfd:ospf/areas/area/virtual-link/message-digest-key",
			.cbs = {
				.create = routing_control_plane_protocols_control_plane_protocol_ospf_areas_area_virtual_link_message_digest_key_create,
				.destroy = routing_control_plane_protocols_control_plane_protocol_ospf_areas_area_virtual_link_message_digest_key_destroy,
			}
		},
		{
			.xpath = "/frr-routing:routing/control-plane-protocols/control-plane-protocol/frr-ospfd:ospf/areas/area/virtual-link/message-digest-key/mds-key",
			.cbs = {
				.modify = routing_control_plane_protocols_control_plane_protocol_ospf_areas_area_virtual_link_message_digest_key_mds_key_modify,
				.destroy = routing_control_plane_protocols_control_plane_protocol_ospf_areas_area_virtual_link_message_digest_key_mds_key_destroy,
			}
		},
		{
			.xpath = "/frr-routing:routing/control-plane-protocols/control-plane-protocol/frr-ospfd:ospf/areas/area/virtual-link/authentication-key",
			.cbs = {
				.modify = routing_control_plane_protocols_control_plane_protocol_ospf_areas_area_virtual_link_authentication_key_modify,
				.destroy = routing_control_plane_protocols_control_plane_protocol_ospf_areas_area_virtual_link_authentication_key_destroy,
			}
		},
		{
			.xpath = "/frr-routing:routing/control-plane-protocols/control-plane-protocol/frr-ospfd:ospf/areas/area/virtual-link/timers/dead-interval",
			.cbs = {
				.modify = routing_control_plane_protocols_control_plane_protocol_ospf_areas_area_virtual_link_timers_dead_interval_modify,
				.destroy = routing_control_plane_protocols_control_plane_protocol_ospf_areas_area_virtual_link_timers_dead_interval_destroy,
			}
		},
		{
			.xpath = "/frr-routing:routing/control-plane-protocols/control-plane-protocol/frr-ospfd:ospf/areas/area/virtual-link/timers/hello-interval",
			.cbs = {
				.modify = routing_control_plane_protocols_control_plane_protocol_ospf_areas_area_virtual_link_timers_hello_interval_modify,
				.destroy = routing_control_plane_protocols_control_plane_protocol_ospf_areas_area_virtual_link_timers_hello_interval_destroy,
			}
		},
		{
			.xpath = "/frr-routing:routing/control-plane-protocols/control-plane-protocol/frr-ospfd:ospf/areas/area/virtual-link/timers/retransmit-interval",
			.cbs = {
				.modify = routing_control_plane_protocols_control_plane_protocol_ospf_areas_area_virtual_link_timers_retransmit_interval_modify,
				.destroy = routing_control_plane_protocols_control_plane_protocol_ospf_areas_area_virtual_link_timers_retransmit_interval_destroy,
			}
		},
		{
			.xpath = "/frr-routing:routing/control-plane-protocols/control-plane-protocol/frr-ospfd:ospf/areas/area/virtual-link/timers/transmit-delay",
			.cbs = {
				.modify = routing_control_plane_protocols_control_plane_protocol_ospf_areas_area_virtual_link_timers_transmit_delay_modify,
				.destroy = routing_control_plane_protocols_control_plane_protocol_ospf_areas_area_virtual_link_timers_transmit_delay_destroy,
			}
		},
		{
			.xpath = NULL,
		},
	}
};
