#include "arithmetic.h"
#include "dsa.h"

DSA_public_part	dsa_public_part[9] = {
{
	{ 0x10, 0xac497bdf, 0x6a442b27, 0x8e6e62e8, 0xfbdce73b, 0x3b0f3b95, 0x3dab72ef, 0x3542889f, 0xf83ed03b, 0xe8e957e0, 0x8e7b151e, 0x98b6a031, 0xff33dcc9, 0xec17d7ed, 0x38e14b26, 0x11a25a18, 0x9acd99d9 } ,
	{ 0x5, 0x430107ff, 0x44a6233c, 0x43ba788a, 0x63bc6594, 0x812a171b } ,
	{ 0x10, 0xae99b8a2, 0xd1fbce2a, 0xf65a74c4, 0xac731624, 0x78611236, 0x5fbe8c57, 0x94ac7732, 0xdfe2128a, 0xc4f0fa99, 0x8f0d03bc, 0x4a90d967, 0x9dcfdb18, 0x61bf580a, 0xf3bef8b7, 0x1bad1480, 0x183e79b9 }
} ,
{
	{ 0x12, 0xf5704e25, 0xf65998c2, 0xbab1dae3, 0x275abd38, 0x8ff96cf9, 0xfd57e36a, 0x22c200f5, 0x41ebd3e, 0x8a1003c7, 0x964c208, 0x90add9f4, 0xee110838, 0x7985a730, 0x4a06cd0d, 0xcbd407a5, 0xf3659504, 0x28eea7e1, 0xa5bd9b05 } ,
	{ 0x5, 0x5592fffd, 0x9b1e00a, 0xf1f678c8, 0x9ac914e3, 0x975216b } ,
	{ 0x12, 0xf5326833, 0x9eb96c67, 0x5a91d12, 0x26fa23c6, 0xb219d897, 0x6229614d, 0xed637178, 0x67d4f436, 0x650616df, 0x4c06d938, 0x38effd04, 0x6bfbb658, 0x5f1b1c98, 0x984ba6b7, 0xbea67af6, 0x83fb4131, 0x5940de5d, 0xa180cda4 }
} ,
{
	{ 0x14, 0x1ce2274d, 0xbc415ce5, 0x57fe2f8b, 0x777ee7d4, 0x98a36281, 0xa8833364, 0x4daf0960, 0x434125af, 0x379c8384, 0x3bb11e36, 0x9836f032, 0x14ee21c7, 0x96e46e04, 0x7d0083f5, 0x823fa8d9, 0xb2a0e5cb, 0x937febfd, 0x73a4ad25, 0x567b42c1, 0xb9bbc48b } ,
	{ 0x5, 0x7ab4e193, 0x17ce91c9, 0xf495efea, 0x27694e70, 0x93318be8 } ,
	{ 0x14, 0x73c3e221, 0xcbab8d55, 0x3ad03471, 0xe61a6c90, 0x766fc72b, 0xff07d95c, 0xde637f4c, 0xc0283ed5, 0x610b33c6, 0x6a34af90, 0xbdb304d1, 0x6ccdd122, 0x27057a56, 0x19f8c380, 0x11636395, 0x77e9ebc, 0xa0167e13, 0x5a53308b, 0x4cb9cc16, 0xb624217b }
} ,
{
	{ 0x16, 0x1edbeba7, 0x41012c85, 0xa68fcdb, 0xaa6da48, 0x5b4fb104, 0x782d1631, 0xa1a83b57, 0xf830b684, 0x89c098f7, 0xfa1b34dc, 0x837b452d, 0xeddf77e2, 0x11af113c, 0x50cb47cf, 0x9461c763, 0xb1997c9, 0x952b6c16, 0xc4b78b21, 0xe5aaaa45, 0xba925e4, 0x3b0b89f2, 0xb636526a } ,
	{ 0x5, 0x463a5fbf, 0x9ab2fb50, 0xbf9eda48, 0xe1fe9873, 0x83d557e1 } ,
	{ 0x16, 0x55c1c029, 0x1e6c2c39, 0xe1a46e74, 0xd319a3b9, 0x653e5234, 0x41115ebd, 0x30c4207, 0x2882a8ef, 0x7eb65119, 0x288ab2c1, 0x254b9c08, 0x742883dc, 0xef260902, 0x71e4373, 0x6eb3830e, 0x7823bd52, 0x3b484668, 0x577bea17, 0x9fa445fa, 0xdbe5ac19, 0xd8809051, 0x9fe63873 }
} ,
{
	{ 0x18, 0x66a1b3c7, 0x77d79f8d, 0xfd3b150d, 0x13fb4e12, 0x5a5d93bc, 0x2d22b27d, 0x21d9c98a, 0x799efbd8, 0xc9306adf, 0x8cbb63ef, 0x18036fa9, 0x27b01a91, 0x8d19561e, 0xebc9dcf3, 0x1d91cb1c, 0xbcdd43cf, 0xeff9f2de, 0x4bb5dd3d, 0xf732e6af, 0xa878d24b, 0x3f6a7d0e, 0x4e13ad4, 0x3910b263, 0xc1ac2882 } ,
	{ 0x5, 0xb02e7191, 0x67be3301, 0x12c07e8e, 0xf1977670, 0x650912e7 } ,
	{ 0x18, 0x3ea58e01, 0xf8bb0e12, 0x749a16, 0xe677eca8, 0xba449c8d, 0x534b1872, 0xae21e398, 0xaeae1c57, 0xc154fa2c, 0xed7a70b5, 0xc2e4ea74, 0xcf8d5d45, 0xf49dacb7, 0xc340b66e, 0xd17b02ed, 0xa1326de0, 0x494864a2, 0xb48d687f, 0x9af615ce, 0x6a0bbd98, 0xd1422e29, 0xef012058, 0xbfca9b54, 0xc16b5b23 }
} ,
{
	{ 0x1a, 0xe1e662db, 0x4097fa7e, 0xd429ce38, 0x96b05ced, 0x91845aab, 0x1242ed9a, 0xe38ca4de, 0x63905f81, 0x48d0f35a, 0xed916094, 0x33dc04c0, 0x653ebb7f, 0xe3750cdd, 0x27d3662e, 0xc9a0f210, 0x804483b6, 0x32f6148a, 0xf70b0bbe, 0xe4f2c7d0, 0x82453354, 0x35ee1607, 0xf46bfbb0, 0x8f8896d9, 0x858324ed, 0xc8a2ebe8, 0x8090abbd } ,
	{ 0x5, 0x781e588b, 0xb6093e02, 0xd1c0e663, 0xdbdc8195, 0x5fb51f46 } ,
	{ 0x1a, 0xf4c8f503, 0xc30f15ff, 0x9c43bac8, 0xb34e9aa3, 0x7e9eb062, 0x10752d0, 0xdd6ad880, 0x6e599294, 0x2edc2e8b, 0x6085543, 0xe8bf2ee6, 0x83b2b7ad, 0x228b40fa, 0xd48f1ae7, 0xbe9c2957, 0x39f75f75, 0xcc74477b, 0xdd391b00, 0xc5a68e99, 0x7ee2d362, 0x4f5bafb1, 0x46a2ce12, 0xb0f74c43, 0x4df5f555, 0xbc067e94, 0xd082369 }
} ,
{
	{ 0x1c, 0x58f786bd, 0xe9035392, 0x4abcc676, 0xc489c57b, 0x7481b0f7, 0x56ce987d, 0xba55d8b0, 0x6da3c495, 0x669efdf3, 0xb6fb32a1, 0x7a988f55, 0x714c9e58, 0x214959a3, 0x3b0437d9, 0x3167c097, 0x65f8df48, 0x9dda4341, 0x4ba6d25f, 0x68df21c8, 0xafe1d5be, 0x76ce4787, 0x1492ecc8, 0xef1d986c, 0x14068f9, 0xc2cca6e3, 0x59b4f6b1, 0xe707b926, 0xb6c1ded0 } ,
	{ 0x5, 0xd6bf0fb3, 0xb777804, 0xadc651ae, 0x1ed27b39, 0xdabb2b1 } ,
	{ 0x1c, 0x83e73571, 0xaa9e8b55, 0x8f10a070, 0xe3a283a7, 0xf2fb48f4, 0xae4c876c, 0x2b94cb36, 0x18cdb50e, 0x30a42a13, 0xa653e7e, 0xa5484faa, 0x5518e6c7, 0xc7949ad5, 0xfa1a0615, 0x482f5f5c, 0x2271fb4c, 0x55797958, 0xdc39390b, 0xbea56dbb, 0x809737b5, 0x3184d3e0, 0x120dd866, 0xd8529a2e, 0x86d2c264, 0x3c2eed68, 0x1f19c6f, 0x2ac663d6, 0xaeeb4d1a }
} ,
{
	{ 0x1e, 0x280d55cb, 0x1cd9abd6, 0xa9ab7398, 0x51b92c60, 0xd6916d56, 0xd87eea9f, 0xffd5658b, 0xa5c46015, 0x98e40d0e, 0x69bb6b9c, 0x9cd3cd1c, 0x704001a2, 0x757a7bdb, 0xc73800e, 0x86c4dcda, 0xe60c68ed, 0xcdfb1e09, 0xecc6e409, 0x17d9b1cc, 0xe1fbe8bd, 0x661f7ab3, 0x7aebc52d, 0x441b4c43, 0x2015db7e, 0x5ac0d55d, 0xcdfd394e, 0x1faf07b0, 0xbda3d305, 0x75f51a9, 0xdb2d78bc } ,
	{ 0x5, 0x93476d85, 0xa9e0b028, 0x920480cf, 0x17abb536, 0x27ea0ec0 } ,
	{ 0x1e, 0xfa9401b9, 0x7ebeafbf, 0xd38032ca, 0xa91198f8, 0x3626fc1c, 0x9876312a, 0xfc1d640a, 0xb6c6b63, 0xb56dae01, 0x4c795a7a, 0x7af85d5e, 0x5898d491, 0x85c07a71, 0x8fea3966, 0xd5359266, 0x9a9c3a2a, 0xf7c543e2, 0xe2bc3467, 0x9904b5d2, 0x649e7dcf, 0x36f1e0e, 0x8142a47b, 0x3fb69b60, 0x22701d67, 0x2682d07, 0xab6414f4, 0x160be9cc, 0x267e2792, 0xf8cb9427, 0xaa0a1abc }
} ,
{
	{ 0x20, 0xbe59cfd9, 0xee7be42b, 0x5745752c, 0x3fdf5fa2, 0x7c705c9a, 0x3d55c884, 0x3970b760, 0x1afe30e8, 0xf79e32c1, 0x6af56795, 0xf62ceb9f, 0xd7268057, 0x660e3623, 0xe460e3a6, 0xfbd085e2, 0x1962d8ed, 0xd448f64d, 0x9f99aa54, 0xfb840006, 0xc7a6e604, 0xbf42ed16, 0xbe2da792, 0xe700bdc1, 0x25d884f8, 0x26bbb207, 0xc742710f, 0x18719253, 0xecf2301c, 0x4b8fdb5a, 0xf6011dbf, 0x76e9dace, 0xfb9441ff } ,
	{ 0x5, 0x4e2f4391, 0x9c6cc85e, 0xeba4939e, 0xc152570d, 0xcb4b1e36 } ,
	{ 0x20, 0xbd7d58a6, 0x64e08aef, 0x9b0e0d27, 0x446fd83d, 0x3429920b, 0x9ab815c0, 0x5668d487, 0x734f80e4, 0xb4f2a376, 0xf7fb4fc9, 0x5330d818, 0xe8ffda56, 0xa9eda5e9, 0x8b9151cf, 0x4f5f0acd, 0x267c5d76, 0x19f2aa9f, 0x1808e06f, 0xa72a81b8, 0xfbe835c, 0x4398ece8, 0xa223c55, 0x5d16bf4, 0x63cc4c95, 0x1bfc61ff, 0x287d4356, 0xb7d9a73b, 0x88641f17, 0x70f2406a, 0x3fe6cd6e, 0x68a92b4a, 0x5e801667 }
} 
};