-- automatically generated by posy 8.0 #7 (tiber), do not edit!

IF DEFINITIONS ::=

%{
#include "If-types.h"
#include "af.h"  /* required due to OctetString structure below */

static PE	      encode_IF_DER_SET_OF();
OctetString  	    * aux_PE2OctetString();
PE		      aux_OctetString2PE();
%}

PREFIXES encode decode print

BEGIN


ENCODER build

AttributeType [[P struct type_IF_AttributeType *]] ::=
        OBJECT IDENTIFIER
        [[O parm ]]


AttributeValue [[P struct type_IF_AttributeValue *]] ::=
        ANY
        [[a parm ]]


AttributeValueAssertion [[P struct type_IF_AttributeValueAssertion *]] ::=
        SEQUENCE
            %{
            %}
        {
                AttributeType
                [[p parm -> element_IF_0 ]],

                AttributeValue
                [[p parm -> element_IF_1 ]]
        }


Name [[P struct type_IF_Name *]] ::=
        SEQUENCE OF
            <<; parm; parm = parm -> next>>
            RelativeDistinguishedName
            [[p parm -> element_IF_2 ]]


RelativeDistinguishedName [[P struct type_IF_RelativeDistinguishedName *]]
-- non-compliant with DER restriction (X.509, 8.7): 
--	::=
--      SET OF
--      	<<; parm; parm = parm -> next>>
--      	AttributeValueAssertion
--      	[[p parm -> member_IF_0 ]]
-- compliant with DER restriction (X.509, 8.7):
	%{
	PE pe_enc = encode_IF_DER_SET_OF(parm, RDNAME);
	%}
	::=
	ANY [[ a pe_enc ]]
	%{
	pe_free(pe_enc);
	%}


AttributeValues [[P struct type_IF_AttributeValues *]] 
-- non-compliant with DER restriction (X.509, 8.7): 
--	::=
--      SET OF
--            	<<; parm; parm = parm -> next>>
--            	AttributeValue
--            	[[p parm -> member_IF_1 ]]
-- compliant with DER restriction (X.509, 8.7):
	%{
	PE pe_enc = encode_IF_DER_SET_OF(parm, ATTRIBUTEVALUES);
	%}
	::=
	ANY [[ a pe_enc ]]
	%{
	pe_free(pe_enc);
	%}


Attribute [[P struct type_IF_Attribute *]] ::=
        SEQUENCE
            %{
            %}
        {
                AttributeType
                [[p parm -> type ]],

                AttributeValues
                [[p parm -> values ]]
        }



DECODER parse

AttributeType [[P struct type_IF_AttributeType **]] ::=
        OBJECT IDENTIFIER
        [[O (*parm) ]]


AttributeValue [[P struct type_IF_AttributeValue **]] ::=
        ANY
        [[a (*parm) ]]


AttributeValueAssertion [[P struct type_IF_AttributeValueAssertion **]] ::=
    %{
        if ((*(parm) = (struct type_IF_AttributeValueAssertion *)
                calloc (1, sizeof **(parm))) == ((struct type_IF_AttributeValueAssertion *) 0)) {
            advise (NULLCP, "%s", PEPY_ERR_NOMEM);
            return NOTOK;
        }
    %}
        SEQUENCE
            %{
            %}
        {
                AttributeType
                [[p &((*parm) -> element_IF_0)]],

                AttributeValue
                [[p &((*parm) -> element_IF_1)]]
        }


Name [[P struct type_IF_Name **]] ::=
        SEQUENCE OF
            %{
                if ((*(parm) = (struct type_IF_Name *)
                        calloc (1, sizeof **(parm))) == ((struct type_IF_Name *) 0)) {
                    advise (NULLCP, "%s", PEPY_ERR_NOMEM);
                    return NOTOK;
                }
            %}
            RelativeDistinguishedName
            [[p &((*parm) -> element_IF_2)]]
            %{ parm = &((*parm) -> next); %}


RelativeDistinguishedName [[P struct type_IF_RelativeDistinguishedName **]] ::=
        SET OF
            %{
                if ((*(parm) = (struct type_IF_RelativeDistinguishedName *)
                        calloc (1, sizeof **(parm))) == ((struct type_IF_RelativeDistinguishedName *) 0)) {
                    advise (NULLCP, "%s", PEPY_ERR_NOMEM);
                    return NOTOK;
                }
            %}
            AttributeValueAssertion
            [[p &((*parm) -> member_IF_0)]]
            %{ parm = &((*parm) -> next); %}


AttributeValues [[P struct type_IF_AttributeValues **]] ::=
        SET OF
            %{
                if ((*(parm) = (struct type_IF_AttributeValues *)
                        calloc (1, sizeof **(parm))) == ((struct type_IF_AttributeValues *) 0)) {
                    advise (NULLCP, "%s", PEPY_ERR_NOMEM);
                    return NOTOK;
                }
            %}
            AttributeValue
            [[p &((*parm) -> member_IF_1)]]
            %{ parm = &((*parm) -> next); %}


Attribute [[P struct type_IF_Attribute **]] ::=
    %{
        if ((*(parm) = (struct type_IF_Attribute *)
                calloc (1, sizeof **(parm))) == ((struct type_IF_Attribute *) 0)) {
            advise (NULLCP, "%s", PEPY_ERR_NOMEM);
            return NOTOK;
        }
    %}
        SEQUENCE
            %{
            %}
        {
                AttributeType
                [[p &((*parm) -> type)]],

                AttributeValues
                [[p &((*parm) -> values)]]
        }

END


%{
/************************ local functions: ************************/


static
PE encode_IF_DER_SET_OF(arg, type)
caddr_t    arg;
int 	   type;
{
	AttrValues		  * attrvalues, * tmp_attrvalues;
	RDName			  * rdname, * tmp_rdname;
	OctetString 		 ** oSTK, * tmp_ostr;
	PE			    p24 = NULLPE, p25 = NULLPE, pe;
	unsigned char  		    a, b;
	int 	       		    n, i, k, j, s, cnt;


	if (! arg){
		/* Force an empty set to be coded */
		pe = pe_alloc (PE_CLASS_UNIV, PE_FORM_CONS, PE_CONS_SET);
		return(pe);
	}


	/* Individual encoding of components of Set-of type */

	switch(type) {

	case ATTRIBUTEVALUES:
		attrvalues = (AttrValues * )arg;

		for (tmp_attrvalues = attrvalues, cnt = 0; tmp_attrvalues; 
			tmp_attrvalues = tmp_attrvalues->next, cnt++)
			/* count */;
	
		oSTK = (OctetString ** )calloc(cnt, sizeof(OctetString * ));
		if(! oSTK)
			return(NULLPE);
	
		i = 0;
		tmp_attrvalues = attrvalues;

		while (tmp_attrvalues){
			tmp_ostr = aux_PE2OctetString(tmp_attrvalues->member_IF_1);		
			oSTK[i] = aux_cpy_OctetString(tmp_ostr);
			aux_free_OctetString(&tmp_ostr);
			if(! oSTK[i++])
				return(NULLPE);
			tmp_attrvalues = tmp_attrvalues->next;
		}
		break;

	case RDNAME:
		rdname = (RDName * )arg;

		for (tmp_rdname = rdname, cnt = 0; tmp_rdname; 
			tmp_rdname = tmp_rdname->next, cnt++)
			/* count */;
	
		oSTK = (OctetString ** )calloc(cnt, sizeof(OctetString * ));
		if(! oSTK)
			return(NULLPE);
	
		i = 0;
		tmp_rdname = rdname;

		while (tmp_rdname){
			tmp_ostr = e_AttributeValueAssertion(tmp_rdname->member_IF_0);		
			oSTK[i] = aux_cpy_OctetString(tmp_ostr);
			aux_free_OctetString(&tmp_ostr);
			if(! oSTK[i++])
				return(NULLPE);
			tmp_rdname = tmp_rdname->next;
		}
		break;

	default:
		return(NULLPE);

	} /* switch */



	/* sort elements of oSTK in ascending order */

	for (i = 0; i < cnt - 1; i++) {
		k = i;
		tmp_ostr = oSTK[i];
		for (j = i + 1; j < cnt; j++) {

			/* n = min(tmp_ostr->noctets, oSTK[j]->noctets) */
			n = tmp_ostr->noctets;
			if(oSTK[j]->noctets < tmp_ostr->noctets)
				n = oSTK[j]->noctets;

			s = 0;
			while (oSTK[j]->octets[s] == tmp_ostr->octets[s] && s < n)
				s++;
			if(s < n && (a = oSTK[j]->octets[s]) < (b = tmp_ostr->octets[s])){
				k = j;
				tmp_ostr = oSTK[j];
			} /* if */

		}  /* for */
		oSTK[k] = oSTK[i];
		oSTK[i] = tmp_ostr;
	}  /* for */


    	if ((pe = pe_alloc (PE_CLASS_UNIV, PE_FORM_CONS, PE_CONS_SET)) == NULLPE)
        	return NULLPE;

    	for(i = 0; i < cnt; i++) {
		p25 = aux_OctetString2PE(oSTK[i]);

        	(void) set_addon (pe, p24, p25);
        	p24 = p25;
    	}


	for(i = 0; i < cnt; i++)
		aux_free_OctetString(&oSTK[i]);

	free (oSTK);

	return(pe);
}


%}
