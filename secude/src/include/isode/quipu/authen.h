/* authen.h - parameters for strong authentication */

/*
 * $Header: /xtel/isode/isode/h/quipu/RCS/authen.h,v 9.0 1992/06/16 12:23:11 isode Rel $
 *
 *
 *
 * $Log: authen.h,v $
 * Revision 9.0  1992/06/16  12:23:11  isode
 * Release 8.0
 *
 */

/*
 *				  NOTICE
 *
 *    Acquisition, use, and distribution of this module and related
 *    materials are subject to the restrictions of a license agreement.
 *    Consult the Preface in the User's Manual for the full terms of
 *    this agreement.
 *
 */


#ifndef QUIPUAUTHEN
#define QUIPUAUTHEN
#include "quipu/name.h"

/* Structures for strong authentication */

struct alg_id {
	OID algorithm;
	PE asn;
	int p_type;
#define ALG_PARM_ABSENT  0
#define ALG_PARM_UNKNOWN 1
#define ALG_PARM_NUMERIC 2
	union {
		int numeric;
	} un;
};

struct random_number {
	int n_bits;
	char *value;
};

struct key_info {
	struct alg_id alg;
	int n_bits;
	char *value;
};

struct validity {
	char *not_before;
	char *not_after;
};

struct signature {
	struct alg_id alg;
	PE encoded;
	int n_bits;
	char *encrypted;
};
		
struct certificate {
	struct alg_id alg;
	int version;
	int serial;
	DN issuer;
	DN subject;
	struct validity valid;
	struct key_info key;
	struct signature sig;
};


struct certificate_list {
	struct certificate *cert;
	struct certificate *reverse;
	struct certificate_list *next, *prev;
	struct certificate_list *superior;
};

struct revoked_certificate {
	struct alg_id alg;
	DN subject;
	int serial;
	char *revocation_date;
	struct revoked_certificate *next;
};

struct revocation_list {
	struct alg_id alg;
	DN issuer;
	char *last_update;
	char *next_update; /* For RFC 1040 format only */
	struct revoked_certificate *revoked;
	struct signature sig;
	struct signature sig2;
	char test[1];	/* For pepsy to test for revoked certificate */
};

struct ca_record {
	struct key_info key;
	DN name;
	struct validity valid;
	/* parameters controlling jurisdiction would go here */
	struct ca_record *next;
};

struct protected_password {
	char *passwd;
	int n_octets;
	char is_protected[1];
	char *time1;
	char *time2;
	struct random_number *random1;	
	struct random_number *random2;
	struct alg_id * alg_id;		/* NULL - for pepsy */
};

#endif
