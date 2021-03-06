#ifndef _LIBNFTNL_SET_INTERNAL_H_
#define _LIBNFTNL_SET_INTERNAL_H_

#include <linux/netfilter/nf_tables.h>

struct nftnl_set {
	struct list_head	head;

	uint32_t		family;
	uint32_t		set_flags;
	const char		*table;
	const char		*name;
	uint32_t		key_type;
	uint32_t		key_len;
	uint32_t		data_type;
	uint32_t		data_len;
	uint32_t		id;
	enum nft_set_policies	policy;
	struct {
		uint32_t	size;
	} desc;
	struct list_head	element_list;

	uint32_t		flags;
	uint32_t		gc_interval;
	uint64_t		timeout;
};

struct nftnl_set_list;
struct nftnl_expr;
int nftnl_set_lookup_id(struct nftnl_expr *e, struct nftnl_set_list *set_list,
		      uint32_t *set_id);

#endif
