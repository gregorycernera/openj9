/*******************************************************************************
 * Copyright (c) 1991, 2022 IBM Corp. and others
 *
 * This program and the accompanying materials are made available under
 * the terms of the Eclipse Public License 2.0 which accompanies this
 * distribution and is available at https://www.eclipse.org/legal/epl-2.0/
 * or the Apache License, Version 2.0 which accompanies this distribution and
 * is available at https://www.apache.org/licenses/LICENSE-2.0.
 *
 * This Source Code may also be made available under the following
 * Secondary Licenses when the conditions for such availability set
 * forth in the Eclipse Public License, v. 2.0 are satisfied: GNU
 * General Public License, version 2 with the GNU Classpath
 * Exception [1] and GNU General Public License, version 2 with the
 * OpenJDK Assembly Exception [2].
 *
 * [1] https://www.gnu.org/software/classpath/license.html
 * [2] http://openjdk.java.net/legal/assembly-exception.html
 *
 * SPDX-License-Identifier: EPL-2.0 OR Apache-2.0 OR GPL-2.0 WITH Classpath-exception-2.0 OR LicenseRef-GPL-2.0 WITH Assembly-exception
 *******************************************************************************/
#include "j9.h"

/* high nybble = branch action, low nybble = instruction size */
const unsigned char J9JavaInstructionSizeAndBranchActionTable[] = {
0x01 /* JBnop = 0 */,
0x01 /* JBaconstnull = 1 */,
0x01 /* JBiconstm1 = 2 */,
0x01 /* JBiconst0 = 3 */,
0x01 /* JBiconst1 = 4 */,
0x01 /* JBiconst2 = 5 */,
0x01 /* JBiconst3 = 6 */,
0x01 /* JBiconst4 = 7 */,
0x01 /* JBiconst5 = 8 */,
0x01 /* JBlconst0 = 9 */,
0x01 /* JBlconst1 = 10 */,
0x01 /* JBfconst0 = 11 */,
0x01 /* JBfconst1 = 12 */,
0x01 /* JBfconst2 = 13 */,
0x01 /* JBdconst0 = 14 */,
0x01 /* JBdconst1 = 15 */,
0x02 /* JBbipush = 16 */,
0x03 /* JBsipush = 17 */,
0x02 /* JBldc = 18 */,
0x03 /* JBldcw = 19 */,
0x03 /* JBldc2lw = 20 */,
0x02 /* JBiload = 21 */,
0x02 /* JBlload = 22 */,
0x02 /* JBfload = 23 */,
0x02 /* JBdload = 24 */,
0x02 /* JBaload = 25 */,
0x01 /* JBiload0 = 26 */,
0x01 /* JBiload1 = 27 */,
0x01 /* JBiload2 = 28 */,
0x01 /* JBiload3 = 29 */,
0x01 /* JBlload0 = 30 */,
0x01 /* JBlload1 = 31 */,
0x01 /* JBlload2 = 32 */,
0x01 /* JBlload3 = 33 */,
0x01 /* JBfload0 = 34 */,
0x01 /* JBfload1 = 35 */,
0x01 /* JBfload2 = 36 */,
0x01 /* JBfload3 = 37 */,
0x01 /* JBdload0 = 38 */,
0x01 /* JBdload1 = 39 */,
0x01 /* JBdload2 = 40 */,
0x01 /* JBdload3 = 41 */,
0x01 /* JBaload0 = 42 */,
0x01 /* JBaload1 = 43 */,
0x01 /* JBaload2 = 44 */,
0x01 /* JBaload3 = 45 */,
0x01 /* JBiaload = 46 */,
0x01 /* JBlaload = 47 */,
0x01 /* JBfaload = 48 */,
0x01 /* JBdaload = 49 */,
0x01 /* JBaaload = 50 */,
0x01 /* JBbaload = 51 */,
0x01 /* JBcaload = 52 */,
0x01 /* JBsaload = 53 */,
0x02 /* JBistore = 54 */,
0x02 /* JBlstore = 55 */,
0x02 /* JBfstore = 56 */,
0x02 /* JBdstore = 57 */,
0x02 /* JBastore = 58 */,
0x01 /* JBistore0 = 59 */,
0x01 /* JBistore1 = 60 */,
0x01 /* JBistore2 = 61 */,
0x01 /* JBistore3 = 62 */,
0x01 /* JBlstore0 = 63 */,
0x01 /* JBlstore1 = 64 */,
0x01 /* JBlstore2 = 65 */,
0x01 /* JBlstore3 = 66 */,
0x01 /* JBfstore0 = 67 */,
0x01 /* JBfstore1 = 68 */,
0x01 /* JBfstore2 = 69 */,
0x01 /* JBfstore3 = 70 */,
0x01 /* JBdstore0 = 71 */,
0x01 /* JBdstore1 = 72 */,
0x01 /* JBdstore2 = 73 */,
0x01 /* JBdstore3 = 74 */,
0x01 /* JBastore0 = 75 */,
0x01 /* JBastore1 = 76 */,
0x01 /* JBastore2 = 77 */,
0x01 /* JBastore3 = 78 */,
0x01 /* JBiastore = 79 */,
0x01 /* JBlastore = 80 */,
0x01 /* JBfastore = 81 */,
0x01 /* JBdastore = 82 */,
0x01 /* JBaastore = 83 */,
0x01 /* JBbastore = 84 */,
0x01 /* JBcastore = 85 */,
0x01 /* JBsastore = 86 */,
0x01 /* JBpop = 87 */,
0x01 /* JBpop2 = 88 */,
0x01 /* JBdup = 89 */,
0x01 /* JBdupx1 = 90 */,
0x01 /* JBdupx2 = 91 */,
0x01 /* JBdup2 = 92 */,
0x01 /* JBdup2x1 = 93 */,
0x01 /* JBdup2x2 = 94 */,
0x01 /* JBswap = 95 */,
0x01 /* JBiadd = 96 */,
0x01 /* JBladd = 97 */,
0x01 /* JBfadd = 98 */,
0x01 /* JBdadd = 99 */,
0x01 /* JBisub = 100 */,
0x01 /* JBlsub = 101 */,
0x01 /* JBfsub = 102 */,
0x01 /* JBdsub = 103 */,
0x01 /* JBimul = 104 */,
0x01 /* JBlmul = 105 */,
0x01 /* JBfmul = 106 */,
0x01 /* JBdmul = 107 */,
0x01 /* JBidiv = 108 */,
0x01 /* JBldiv = 109 */,
0x01 /* JBfdiv = 110 */,
0x01 /* JBddiv = 111 */,
0x01 /* JBirem = 112 */,
0x01 /* JBlrem = 113 */,
0x01 /* JBfrem = 114 */,
0x01 /* JBdrem = 115 */,
0x01 /* JBineg = 116 */,
0x01 /* JBlneg = 117 */,
0x01 /* JBfneg = 118 */,
0x01 /* JBdneg = 119 */,
0x01 /* JBishl = 120 */,
0x01 /* JBlshl = 121 */,
0x01 /* JBishr = 122 */,
0x01 /* JBlshr = 123 */,
0x01 /* JBiushr = 124 */,
0x01 /* JBlushr = 125 */,
0x01 /* JBiand = 126 */,
0x01 /* JBland = 127 */,
0x01 /* JBior = 128 */,
0x01 /* JBlor = 129 */,
0x01 /* JBixor = 130 */,
0x01 /* JBlxor = 131 */,
0x03 /* JBiinc = 132 */,
0x01 /* JBi2l = 133 */,
0x01 /* JBi2f = 134 */,
0x01 /* JBi2d = 135 */,
0x01 /* JBl2i = 136 */,
0x01 /* JBl2f = 137 */,
0x01 /* JBl2d = 138 */,
0x01 /* JBf2i = 139 */,
0x01 /* JBf2l = 140 */,
0x01 /* JBf2d = 141 */,
0x01 /* JBd2i = 142 */,
0x01 /* JBd2l = 143 */,
0x01 /* JBd2f = 144 */,
0x01 /* JBi2b = 145 */,
0x01 /* JBi2c = 146 */,
0x01 /* JBi2s = 147 */,
0x01 /* JBlcmp = 148 */,
0x01 /* JBfcmpl = 149 */,
0x01 /* JBfcmpg = 150 */,
0x01 /* JBdcmpl = 151 */,
0x01 /* JBdcmpg = 152 */,
0x13 /* JBifeq = 153 */,
0x13 /* JBifne = 154 */,
0x13 /* JBiflt = 155 */,
0x13 /* JBifge = 156 */,
0x13 /* JBifgt = 157 */,
0x13 /* JBifle = 158 */,
0x13 /* JBificmpeq = 159 */,
0x13 /* JBificmpne = 160 */,
0x13 /* JBificmplt = 161 */,
0x13 /* JBificmpge = 162 */,
0x13 /* JBificmpgt = 163 */,
0x13 /* JBificmple = 164 */,
0x13 /* JBifacmpeq = 165 */,
0x13 /* JBifacmpne = 166 */,
0x23 /* JBgoto = 167 */,
0x00 /* JBunimplemented = 168 */,
0x00 /* JBunimplemented = 169 */,
0x51 /* JBtableswitch = 170 */,
0x51 /* JBlookupswitch = 171 */,
0x41 /* JBreturn0 = 172 */,
0x41 /* JBreturn1 = 173 */,
0x41 /* JBreturn2 = 174 */,
0x41 /* JBsyncReturn0 = 175 */,
0x41 /* JBsyncReturn1 = 176 */,
0x41 /* JBsyncReturn2 = 177 */,
0x03 /* JBgetstatic = 178 */,
0x03 /* JBputstatic = 179 */,
0x03 /* JBgetfield = 180 */,
0x03 /* JBputfield = 181 */,
0x63 /* JBinvokevirtual = 182 */,
0x63 /* JBinvokespecial = 183 */,
0x63 /* JBinvokestatic = 184 */,
0x63 /* JBinvokeinterface = 185 */,
0x03 /* JBinvokedynamic = 186 */,
0x03 /* JBnew = 187 */,
0x02 /* JBnewarray = 188 */,
0x03 /* JBanewarray = 189 */,
0x01 /* JBarraylength = 190 */,
0x41 /* JBathrow = 191 */,
0x03 /* JBcheckcast = 192 */,
0x03 /* JBinstanceof = 193 */,
0x01 /* JBmonitorenter = 194 */,
0x01 /* JBmonitorexit = 195 */,
0x00 /* JBunimplemented = 196 */,
0x04 /* JBmultianewarray = 197 */,
0x13 /* JBifnull = 198 */,
0x13 /* JBifnonnull = 199 */,
0x25 /* JBgotow = 200 */,
0x00 /* JBunimplemented = 201 */,
0x71 /* JBbreakpoint = 202 */,
0x03 /* JBaconst_init = 203 */,
0x03 /* JBwithfield = 204 */,
0x00 /* JBunimplemented = 205 */,
0x00 /* JBunimplemented = 206 */,
0x00 /* JBunimplemented = 207 */,
0x00 /* JBunimplemented = 208 */,
0x00 /* JBunimplemented = 209 */,
0x00 /* JBunimplemented = 210 */,
0x00 /* JBunimplemented = 211 */,
0x00 /* JBunimplemented = 212 */,
0x06 /* JBiincw = 213 */,
0x00 /* JBunimplemented = 214 */,
0x01 /* JBaload0getfield = 215 */,
0x03 /* JBnewdup = 216 */,
0x04 /* JBiloadw = 217 */,
0x04 /* JBlloadw = 218 */,
0x04 /* JBfloadw = 219 */,
0x04 /* JBdloadw = 220 */,
0x04 /* JBaloadw = 221 */,
0x04 /* JBistorew = 222 */,
0x04 /* JBlstorew = 223 */,
0x04 /* JBfstorew = 224 */,
0x04 /* JBdstorew = 225 */,
0x04 /* JBastorew = 226 */,
0x00 /* JBunimplemented = 227 */,
0x41 /* JBreturnFromConstructor = 228 */,
0x41 /* JBgenericReturn = 229 */,
0x40 /* JBunimplemented = 230 */,
0x65 /* JBinvokeinterface2 = 231 */,
0x03 /* JBinvokehandle = 232 */,
0x03 /* JBinvokehandlegeneric = 233 */,
0x63 /* JBinvokestaticsplit = 234 */,
0x63 /* JBinvokespecialsplit = 235 */,
0x41 /* JBreturnC = 236 */,
0x41 /* JBreturnS = 237 */,
0x41 /* JBreturnB = 238 */,
0x41 /* JBreturnZ = 239 */,
0x00 /* JBunimplemented = 240 */,
0x00 /* JBunimplemented = 241 */,
0x00 /* JBunimplemented = 242 */,
0x00 /* JBunimplemented = 243 */,
0x01 /* JBretFromNative0 = 244 */,
0x01 /* JBretFromNative1 = 245 */,
0x01 /* JBretFromNativeF = 246 */,
0x01 /* JBretFromNativeD = 247 */,
0x01 /* JBretFromNativeJ = 248 */,
0x03 /* JBldc2dw = 249 */,
0x01 /* JBasyncCheck = 250 */,
0x01 /* JBreturnFromJ2I = 251 */,
0x00 /* JBunimplemented = 252 */,
0x00 /* JBunimplemented = 253 */,
0x01 /* JBimpdep1 = 254 */,
0x01 /* JBimpdep2 = 255 */
};

/* Layout:
 * bit 7:	special
 * bit 6:	int/object pushes 0=int, 1=object.
 * bit 4-5:	pushes.
 * bit 0-3: pops
 */
const unsigned char JavaStackActionTable[] = {
0x00 /* JBnop = 0  -- pops: 0 pushes: 0*/ ,
0x50 /* JBaconstnull = 1  -- pops: 0 pushes: 1*/ ,
0x10 /* JBiconstm1 = 2  -- pops: 0 pushes: 1*/ ,
0x10 /* JBiconst0 = 3  -- pops: 0 pushes: 1*/ ,
0x10 /* JBiconst1 = 4  -- pops: 0 pushes: 1*/ ,
0x10 /* JBiconst2 = 5  -- pops: 0 pushes: 1*/ ,
0x10 /* JBiconst3 = 6  -- pops: 0 pushes: 1*/ ,
0x10 /* JBiconst4 = 7  -- pops: 0 pushes: 1*/ ,
0x10 /* JBiconst5 = 8  -- pops: 0 pushes: 1*/ ,
0x20 /* JBlconst0 = 9  -- pops: 0 pushes: 2*/ ,
0x20 /* JBlconst1 = 10  -- pops: 0 pushes: 2*/ ,
0x10 /* JBfconst0 = 11  -- pops: 0 pushes: 1*/ ,
0x10 /* JBfconst1 = 12  -- pops: 0 pushes: 1*/ ,
0x10 /* JBfconst2 = 13  -- pops: 0 pushes: 1*/ ,
0x20 /* JBdconst0 = 14  -- pops: 0 pushes: 2*/ ,
0x20 /* JBdconst1 = 15  -- pops: 0 pushes: 2*/ ,
0x10 /* JBbipush = 16  -- pops: 0 pushes: 1*/ ,
0x10 /* JBsipush = 17  -- pops: 0 pushes: 1*/ ,
0x80 /* JBldc = 18  -- pops: 0 pushes: 0*/ ,
0x80 /* JBldcw = 19  -- pops: 0 pushes: 0*/ ,
0x20 /* JBldc2lw = 20  -- pops: 0 pushes: 2*/ ,
0x10 /* JBiload = 21  -- pops: 0 pushes: 1*/ ,
0x20 /* JBlload = 22  -- pops: 0 pushes: 2*/ ,
0x10 /* JBfload = 23  -- pops: 0 pushes: 1*/ ,
0x20 /* JBdload = 24  -- pops: 0 pushes: 2*/ ,
0x50 /* JBaload = 25  -- pops: 0 pushes: 1*/ ,
0x10 /* JBiload0 = 26  -- pops: 0 pushes: 1*/ ,
0x10 /* JBiload1 = 27  -- pops: 0 pushes: 1*/ ,
0x10 /* JBiload2 = 28  -- pops: 0 pushes: 1*/ ,
0x10 /* JBiload3 = 29  -- pops: 0 pushes: 1*/ ,
0x20 /* JBlload0 = 30  -- pops: 0 pushes: 2*/ ,
0x20 /* JBlload1 = 31  -- pops: 0 pushes: 2*/ ,
0x20 /* JBlload2 = 32  -- pops: 0 pushes: 2*/ ,
0x20 /* JBlload3 = 33  -- pops: 0 pushes: 2*/ ,
0x10 /* JBfload0 = 34  -- pops: 0 pushes: 1*/ ,
0x10 /* JBfload1 = 35  -- pops: 0 pushes: 1*/ ,
0x10 /* JBfload2 = 36  -- pops: 0 pushes: 1*/ ,
0x10 /* JBfload3 = 37  -- pops: 0 pushes: 1*/ ,
0x20 /* JBdload0 = 38  -- pops: 0 pushes: 2*/ ,
0x20 /* JBdload1 = 39  -- pops: 0 pushes: 2*/ ,
0x20 /* JBdload2 = 40  -- pops: 0 pushes: 2*/ ,
0x20 /* JBdload3 = 41  -- pops: 0 pushes: 2*/ ,
0x50 /* JBaload0 = 42  -- pops: 0 pushes: 1*/ ,
0x50 /* JBaload1 = 43  -- pops: 0 pushes: 1*/ ,
0x50 /* JBaload2 = 44  -- pops: 0 pushes: 1*/ ,
0x50 /* JBaload3 = 45  -- pops: 0 pushes: 1*/ ,
0x12 /* JBiaload = 46  -- pops: 2 pushes: 1*/ ,
0x22 /* JBlaload = 47  -- pops: 2 pushes: 2*/ ,
0x12 /* JBfaload = 48  -- pops: 2 pushes: 1*/ ,
0x22 /* JBdaload = 49  -- pops: 2 pushes: 2*/ ,
0x52 /* JBaaload = 50  -- pops: 2 pushes: 1*/ ,
0x12 /* JBbaload = 51  -- pops: 2 pushes: 1*/ ,
0x12 /* JBcaload = 52  -- pops: 2 pushes: 1*/ ,
0x12 /* JBsaload = 53  -- pops: 2 pushes: 1*/ ,
0x01 /* JBistore = 54  -- pops: 1 pushes: 0*/ ,
0x02 /* JBlstore = 55  -- pops: 2 pushes: 0*/ ,
0x01 /* JBfstore = 56  -- pops: 1 pushes: 0*/ ,
0x02 /* JBdstore = 57  -- pops: 2 pushes: 0*/ ,
0x01 /* JBastore = 58  -- pops: 1 pushes: 0*/ ,
0x01 /* JBistore0 = 59  -- pops: 1 pushes: 0*/ ,
0x01 /* JBistore1 = 60  -- pops: 1 pushes: 0*/ ,
0x01 /* JBistore2 = 61  -- pops: 1 pushes: 0*/ ,
0x01 /* JBistore3 = 62  -- pops: 1 pushes: 0*/ ,
0x02 /* JBlstore0 = 63  -- pops: 2 pushes: 0*/ ,
0x02 /* JBlstore1 = 64  -- pops: 2 pushes: 0*/ ,
0x02 /* JBlstore2 = 65  -- pops: 2 pushes: 0*/ ,
0x02 /* JBlstore3 = 66  -- pops: 2 pushes: 0*/ ,
0x01 /* JBfstore0 = 67  -- pops: 1 pushes: 0*/ ,
0x01 /* JBfstore1 = 68  -- pops: 1 pushes: 0*/ ,
0x01 /* JBfstore2 = 69  -- pops: 1 pushes: 0*/ ,
0x01 /* JBfstore3 = 70  -- pops: 1 pushes: 0*/ ,
0x02 /* JBdstore0 = 71  -- pops: 2 pushes: 0*/ ,
0x02 /* JBdstore1 = 72  -- pops: 2 pushes: 0*/ ,
0x02 /* JBdstore2 = 73  -- pops: 2 pushes: 0*/ ,
0x02 /* JBdstore3 = 74  -- pops: 2 pushes: 0*/ ,
0x01 /* JBastore0 = 75  -- pops: 1 pushes: 0*/ ,
0x01 /* JBastore1 = 76  -- pops: 1 pushes: 0*/ ,
0x01 /* JBastore2 = 77  -- pops: 1 pushes: 0*/ ,
0x01 /* JBastore3 = 78  -- pops: 1 pushes: 0*/ ,
0x03 /* JBiastore = 79  -- pops: 3 pushes: 0*/ ,
0x04 /* JBlastore = 80  -- pops: 4 pushes: 0*/ ,
0x03 /* JBfastore = 81  -- pops: 3 pushes: 0*/ ,
0x04 /* JBdastore = 82  -- pops: 4 pushes: 0*/ ,
0x03 /* JBaastore = 83  -- pops: 3 pushes: 0*/ ,
0x03 /* JBbastore = 84  -- pops: 3 pushes: 0*/ ,
0x03 /* JBcastore = 85  -- pops: 3 pushes: 0*/ ,
0x03 /* JBsastore = 86  -- pops: 3 pushes: 0*/ ,
0x01 /* JBpop = 87  -- pops: 1 pushes: 0*/ ,
0x02 /* JBpop2 = 88  -- pops: 2 pushes: 0*/ ,
0x80 /* JBdup = 89  -- pops: 0 pushes: 0*/ ,
0x80 /* JBdupx1 = 90  -- pops: 0 pushes: 0*/ ,
0x80 /* JBdupx2 = 91  -- pops: 0 pushes: 0*/ ,
0x80 /* JBdup2 = 92  -- pops: 0 pushes: 0*/ ,
0x80 /* JBdup2x1 = 93  -- pops: 0 pushes: 0*/ ,
0x80 /* JBdup2x2 = 94  -- pops: 0 pushes: 0*/ ,
0x80 /* JBswap = 95  -- pops: 0 pushes: 0*/ ,
0x12 /* JBiadd = 96  -- pops: 2 pushes: 1*/ ,
0x24 /* JBladd = 97  -- pops: 4 pushes: 2*/ ,
0x12 /* JBfadd = 98  -- pops: 2 pushes: 1*/ ,
0x24 /* JBdadd = 99  -- pops: 4 pushes: 2*/ ,
0x12 /* JBisub = 100  -- pops: 2 pushes: 1*/ ,
0x24 /* JBlsub = 101  -- pops: 4 pushes: 2*/ ,
0x12 /* JBfsub = 102  -- pops: 2 pushes: 1*/ ,
0x24 /* JBdsub = 103  -- pops: 4 pushes: 2*/ ,
0x12 /* JBimul = 104  -- pops: 2 pushes: 1*/ ,
0x24 /* JBlmul = 105  -- pops: 4 pushes: 2*/ ,
0x12 /* JBfmul = 106  -- pops: 2 pushes: 1*/ ,
0x24 /* JBdmul = 107  -- pops: 4 pushes: 2*/ ,
0x12 /* JBidiv = 108  -- pops: 2 pushes: 1*/ ,
0x24 /* JBldiv = 109  -- pops: 4 pushes: 2*/ ,
0x12 /* JBfdiv = 110  -- pops: 2 pushes: 1*/ ,
0x24 /* JBddiv = 111  -- pops: 4 pushes: 2*/ ,
0x12 /* JBirem = 112  -- pops: 2 pushes: 1*/ ,
0x24 /* JBlrem = 113  -- pops: 4 pushes: 2*/ ,
0x12 /* JBfrem = 114  -- pops: 2 pushes: 1*/ ,
0x24 /* JBdrem = 115  -- pops: 4 pushes: 2*/ ,
0x11 /* JBineg = 116  -- pops: 1 pushes: 1*/ ,
0x22 /* JBlneg = 117  -- pops: 2 pushes: 2*/ ,
0x11 /* JBfneg = 118  -- pops: 1 pushes: 1*/ ,
0x22 /* JBdneg = 119  -- pops: 2 pushes: 2*/ ,
0x12 /* JBishl = 120  -- pops: 2 pushes: 1*/ ,
0x23 /* JBlshl = 121  -- pops: 3 pushes: 2*/ ,
0x12 /* JBishr = 122  -- pops: 2 pushes: 1*/ ,
0x23 /* JBlshr = 123  -- pops: 3 pushes: 2*/ ,
0x12 /* JBiushr = 124  -- pops: 2 pushes: 1*/ ,
0x23 /* JBlushr = 125  -- pops: 3 pushes: 2*/ ,
0x12 /* JBiand = 126  -- pops: 2 pushes: 1*/ ,
0x24 /* JBland = 127  -- pops: 4 pushes: 2*/ ,
0x12 /* JBior = 128  -- pops: 2 pushes: 1*/ ,
0x24 /* JBlor = 129  -- pops: 4 pushes: 2*/ ,
0x12 /* JBixor = 130  -- pops: 2 pushes: 1*/ ,
0x24 /* JBlxor = 131  -- pops: 4 pushes: 2*/ ,
0x00 /* JBiinc = 132  -- pops: 0 pushes: 0*/ ,
0x21 /* JBi2l = 133  -- pops: 1 pushes: 2*/ ,
0x11 /* JBi2f = 134  -- pops: 1 pushes: 1*/ ,
0x21 /* JBi2d = 135  -- pops: 1 pushes: 2*/ ,
0x12 /* JBl2i = 136  -- pops: 2 pushes: 1*/ ,
0x12 /* JBl2f = 137  -- pops: 2 pushes: 1*/ ,
0x22 /* JBl2d = 138  -- pops: 2 pushes: 2*/ ,
0x11 /* JBf2i = 139  -- pops: 1 pushes: 1*/ ,
0x21 /* JBf2l = 140  -- pops: 1 pushes: 2*/ ,
0x21 /* JBf2d = 141  -- pops: 1 pushes: 2*/ ,
0x12 /* JBd2i = 142  -- pops: 2 pushes: 1*/ ,
0x22 /* JBd2l = 143  -- pops: 2 pushes: 2*/ ,
0x12 /* JBd2f = 144  -- pops: 2 pushes: 1*/ ,
0x11 /* JBi2b = 145  -- pops: 1 pushes: 1*/ ,
0x11 /* JBi2c = 146  -- pops: 1 pushes: 1*/ ,
0x11 /* JBi2s = 147  -- pops: 1 pushes: 1*/ ,
0x14 /* JBlcmp = 148  -- pops: 4 pushes: 1*/ ,
0x12 /* JBfcmpl = 149  -- pops: 2 pushes: 1*/ ,
0x12 /* JBfcmpg = 150  -- pops: 2 pushes: 1*/ ,
0x14 /* JBdcmpl = 151  -- pops: 4 pushes: 1*/ ,
0x14 /* JBdcmpg = 152  -- pops: 4 pushes: 1*/ ,
0x01 /* JBifeq = 153  -- pops: 1 pushes: 0*/ ,
0x01 /* JBifne = 154  -- pops: 1 pushes: 0*/ ,
0x01 /* JBiflt = 155  -- pops: 1 pushes: 0*/ ,
0x01 /* JBifge = 156  -- pops: 1 pushes: 0*/ ,
0x01 /* JBifgt = 157  -- pops: 1 pushes: 0*/ ,
0x01 /* JBifle = 158  -- pops: 1 pushes: 0*/ ,
0x02 /* JBificmpeq = 159  -- pops: 2 pushes: 0*/ ,
0x02 /* JBificmpne = 160  -- pops: 2 pushes: 0*/ ,
0x02 /* JBificmplt = 161  -- pops: 2 pushes: 0*/ ,
0x02 /* JBificmpge = 162  -- pops: 2 pushes: 0*/ ,
0x02 /* JBificmpgt = 163  -- pops: 2 pushes: 0*/ ,
0x02 /* JBificmple = 164  -- pops: 2 pushes: 0*/ ,
0x02 /* JBifacmpeq = 165  -- pops: 2 pushes: 0*/ ,
0x02 /* JBifacmpne = 166  -- pops: 2 pushes: 0*/ ,
0x00 /* JBgoto = 167  -- pops: 0 pushes: 0*/ ,
0x00 /* JBunimplemented = 168  -- pops: 0 pushes: 0*/ ,
0x00 /* JBunimplemented = 169  -- pops: 0 pushes: 0*/ ,
0x01 /* JBtableswitch = 170  -- pops: 1 pushes: 0*/ ,
0x01 /* JBlookupswitch = 171  -- pops: 1 pushes: 0*/ ,
0x00 /* JBreturn0 = 172  -- pops: 0 pushes: 0*/ ,
0x01 /* JBreturn1 = 173  -- pops: 1 pushes: 0*/ ,
0x02 /* JBreturn2 = 174  -- pops: 2 pushes: 0*/ ,
0x00 /* JBsyncReturn0 = 175  -- pops: 0 pushes: 0*/ ,
0x01 /* JBsyncReturn1 = 176  -- pops: 1 pushes: 0*/ ,
0x02 /* JBsyncReturn2 = 177  -- pops: 2 pushes: 0*/ ,
0x80 /* JBgetstatic = 178  -- pops: 0 pushes: 0*/ ,
0x80 /* JBputstatic = 179  -- pops: 0 pushes: 0*/ ,
0x80 /* JBgetfield = 180  -- pops: 0 pushes: 0*/ ,
0x80 /* JBputfield = 181  -- pops: 0 pushes: 0*/ ,
0x80 /* JBinvokevirtual = 182  -- pops: 0 pushes: 0*/ ,
0x80 /* JBinvokespecial = 183  -- pops: 0 pushes: 0*/ ,
0x80 /* JBinvokestatic = 184  -- pops: 0 pushes: 0*/ ,
0x80 /* JBinvokeinterface = 185  -- pops: 0 pushes: 0*/ ,
0x80 /* JBinvokedynamic = 186  -- pops: 0 pushes: 0*/ ,
0x50 /* JBnew = 187  -- pops: 0 pushes: 1*/ ,
0x51 /* JBnewarray = 188  -- pops: 1 pushes: 1*/ ,
0x51 /* JBanewarray = 189  -- pops: 1 pushes: 1*/ ,
0x11 /* JBarraylength = 190  -- pops: 1 pushes: 1*/ ,
0x11 /* JBathrow = 191  -- pops: 1 pushes: 1*/ ,
0x00 /* JBcheckcast = 192  -- pops: 0 pushes: 0*/ ,
0x11 /* JBinstanceof = 193  -- pops: 1 pushes: 1*/ ,
0x01 /* JBmonitorenter = 194  -- pops: 1 pushes: 0*/ ,
0x01 /* JBmonitorexit = 195  -- pops: 1 pushes: 0*/ ,
0x00 /* JBunimplemented = 196  -- pops: 0 pushes: 0*/ ,
0x80 /* JBmultianewarray = 197  -- pops: 0 pushes: 0*/ ,
0x01 /* JBifnull = 198  -- pops: 1 pushes: 0*/ ,
0x01 /* JBifnonnull = 199  -- pops: 1 pushes: 0*/ ,
0x00 /* JBgotow = 200  -- pops: 0 pushes: 0*/ ,
0x00 /* JBunimplemented = 201  -- pops: 0 pushes: 0*/ ,
0x00 /* JBbreakpoint = 202  -- pops: 0 pushes: 0*/ ,
0x50 /* JBaconst_init = 203 -- pops: 0 pushes: 1*/ ,
0x80 /* JBwithfield = 204  -- pops: 2 pushes: 1*/ ,
0x00 /* JBunimplemented = 205  -- pops: 0 pushes: 0*/ ,
0x00 /* JBunimplemented = 206  -- pops: 0 pushes: 0*/ ,
0x00 /* JBunimplemented = 207  -- pops: 0 pushes: 0*/ ,
0x00 /* JBunimplemented = 208  -- pops: 0 pushes: 0*/ ,
0x00 /* JBunimplemented = 209  -- pops: 0 pushes: 0*/ ,
0x00 /* JBunimplemented = 210  -- pops: 0 pushes: 0*/ ,
0x00 /* JBunimplemented = 211  -- pops: 0 pushes: 0*/ ,
0x00 /* JBunimplemented = 212  -- pops: 0 pushes: 0*/ ,
0x00 /* JBiincw = 213  -- pops: 0 pushes: 0*/ ,
0x00 /* JBunimplemented = 214  -- pops: 0 pushes: 0*/ ,
0x50 /* JBaload0getfield = 215  -- pops: 0 pushes: 1*/ ,
0x50 /* JBnewdup = 216  -- pops: 0 pushes: 1*/ ,
0x10 /* JBiloadw = 217  -- pops: 0 pushes: 1*/ ,
0x20 /* JBlloadw = 218  -- pops: 0 pushes: 2*/ ,
0x10 /* JBfloadw = 219  -- pops: 0 pushes: 1*/ ,
0x20 /* JBdloadw = 220  -- pops: 0 pushes: 2*/ ,
0x50 /* JBaloadw = 221  -- pops: 0 pushes: 1*/ ,
0x01 /* JBistorew = 222  -- pops: 1 pushes: 0*/ ,
0x02 /* JBlstorew = 223  -- pops: 2 pushes: 0*/ ,
0x01 /* JBfstorew = 224  -- pops: 1 pushes: 0*/ ,
0x02 /* JBdstorew = 225  -- pops: 2 pushes: 0*/ ,
0x01 /* JBastorew = 226  -- pops: 1 pushes: 0*/ ,
0x00 /* JBunimplemented = 227  -- pops: 0 pushes: 0*/ ,
0x00 /* JBreturnFromConstructor = 228  -- pops: 0 pushes: 0*/ ,
0x00 /* JBgenericReturn = 229  -- pops: 0 pushes: 0*/ ,
0x00 /* JBunimplemented = 230  -- pops: 0 pushes: 0*/ ,
0x80 /* JBinvokeinterface2 = 231  -- pops: 0 pushes: 0*/ ,
0x80 /* JBinvokehandle = 232  -- pops: 0 pushes: 0*/ ,
0x80 /* JBinvokehandlegeneric = 233  -- pops: 0 pushes: 0*/ ,
0x80 /* JBinvokestaticsplit = 234  -- pops: 0 pushes: 0*/ ,
0x80 /* JBinvokespecialsplit = 235  -- pops: 0 pushes: 0*/ ,
0x01 /* JBreturnC = 236  -- pops: 1 pushes: 0*/ ,
0x01 /* JBreturnS = 237  -- pops: 1 pushes: 0*/ ,
0x01 /* JBreturnB = 238  -- pops: 1 pushes: 0*/ ,
0x01 /* JBreturnZ = 239  -- pops: 1 pushes: 0*/ ,
0x00 /* JBunimplemented = 240  -- pops: 0 pushes: 0*/ ,
0x00 /* JBunimplemented = 241  -- pops: 0 pushes: 0*/ ,
0x00 /* JBunimplemented = 242  -- pops: 0 pushes: 0*/ ,
0x00 /* JBunimplemented = 243  -- pops: 0 pushes: 0*/ ,
0x00 /* JBretFromNative0 = 244  -- pops: 0 pushes: 0*/ ,
0x00 /* JBretFromNative1 = 245  -- pops: 0 pushes: 0*/ ,
0x00 /* JBretFromNativeF = 246  -- pops: 0 pushes: 0*/ ,
0x00 /* JBretFromNativeD = 247  -- pops: 0 pushes: 0*/ ,
0x00 /* JBretFromNativeJ = 248  -- pops: 0 pushes: 0*/ ,
0x20 /* JBldc2dw = 249  -- pops: 0 pushes: 2*/ ,
0x00 /* JBasyncCheck = 250  -- pops: 0 pushes: 0*/ ,
0x00 /* JBreturnFromJ2I = 251  -- pops: 0 pushes: 0*/ ,
0x00 /* JBunimplemented = 252  -- pops: 0 pushes: 0*/ ,
0x00 /* JBunimplemented = 253  -- pops: 0 pushes: 0*/ ,
0x00 /* JBimpdep1 = 254  -- pops: 0 pushes: 0*/ ,
0x00 /* JBimpdep2 = 255  -- pops: 0 pushes: 0*/
};

/* Layout:
 * bit 7:	object slot
 * bit 6:	integer/float slot
 * bit 5:	long/double slot
 * bit 4:	write slot
 * bit 3:  wide slot parameter
 * bit 2:	bytecode has implicit (encoded) slot parameter e.g. aload_0
 * bits 0-1:	implicit (encoded) slot parameter
 */
const unsigned char J9BytecodeSlotUseTable[] = {
	0x0 /* JBnop (16r0) */,
	0x0 /* JBaconstnull (16r1) */,
	0x0 /* JBiconstm1 (16r2) */,
	0x0 /* JBiconst0 (16r3) */,
	0x0 /* JBiconst1 (16r4) */,
	0x0 /* JBiconst2 (16r5) */,
	0x0 /* JBiconst3 (16r6) */,
	0x0 /* JBiconst4 (16r7) */,
	0x0 /* JBiconst5 (16r8) */,
	0x0 /* JBlconst0 (16r9) */,
	0x0 /* JBlconst1 (16rA) */,
	0x0 /* JBfconst0 (16rB) */,
	0x0 /* JBfconst1 (16rC) */,
	0x0 /* JBfconst2 (16rD) */,
	0x0 /* JBdconst0 (16rE) */,
	0x0 /* JBdconst1 (16rF) */,
	0x0 /* JBbipush (16r10) */,
	0x0 /* JBsipush (16r11) */,
	0x0 /* JBldc (16r12) */,
	0x0 /* JBldcw (16r13) */,
	0x0 /* JBldc2lw (16r14) */,
	0x40 /* JBiload (16r15) <islot><read>*/,
	0x20 /* JBlload (16r16) <dslot><read>*/,
	0x40 /* JBfload (16r17) <islot><read>*/,
	0x20 /* JBdload (16r18) <dslot><read>*/,
	0x80 /* JBaload (16r19) <oslot><read>*/,
	0x44 /* JBiload0 (16r1A) <islot><read><encodedparam>*/,
	0x45 /* JBiload1 (16r1B) <islot><read><encodedparam>*/,
	0x46 /* JBiload2 (16r1C) <islot><read><encodedparam>*/,
	0x47 /* JBiload3 (16r1D) <islot><read><encodedparam>*/,
	0x24 /* JBlload0 (16r1E) <dslot><read><encodedparam>*/,
	0x25 /* JBlload1 (16r1F) <dslot><read><encodedparam>*/,
	0x26 /* JBlload2 (16r20) <dslot><read><encodedparam>*/,
	0x27 /* JBlload3 (16r21) <dslot><read><encodedparam>*/,
	0x44 /* JBfload0 (16r22) <islot><read><encodedparam>*/,
	0x45 /* JBfload1 (16r23) <islot><read><encodedparam>*/,
	0x46 /* JBfload2 (16r24) <islot><read><encodedparam>*/,
	0x47 /* JBfload3 (16r25) <islot><read><encodedparam>*/,
	0x24 /* JBdload0 (16r26) <dslot><read><encodedparam>*/,
	0x25 /* JBdload1 (16r27) <dslot><read><encodedparam>*/,
	0x26 /* JBdload2 (16r28) <dslot><read><encodedparam>*/,
	0x27 /* JBdload3 (16r29) <dslot><read><encodedparam>*/,
	0x84 /* JBaload0 (16r2A) <oslot><read><encodedparam>*/,
	0x85 /* JBaload1 (16r2B) <oslot><read><encodedparam>*/,
	0x86 /* JBaload2 (16r2C) <oslot><read><encodedparam>*/,
	0x87 /* JBaload3 (16r2D) <oslot><read><encodedparam>*/,
	0x0 /* JBiaload (16r2E) */,
	0x0 /* JBlaload (16r2F) */,
	0x0 /* JBfaload (16r30) */,
	0x0 /* JBdaload (16r31) */,
	0x0 /* JBaaload (16r32) */,
	0x0 /* JBbaload (16r33) */,
	0x0 /* JBcaload (16r34) */,
	0x0 /* JBsaload (16r35) */,
	0x50 /* JBistore (16r36) <islot><write>*/,
	0x30 /* JBlstore (16r37) <dslot><write>*/,
	0x50 /* JBfstore (16r38) <islot><write>*/,
	0x30 /* JBdstore (16r39) <dslot><write>*/,
	0x90 /* JBastore (16r3A) <oslot><write>*/,
	0x54 /* JBistore0 (16r3B) <islot><write><encodedparam>*/,
	0x55 /* JBistore1 (16r3C) <islot><write><encodedparam>*/,
	0x56 /* JBistore2 (16r3D) <islot><write><encodedparam>*/,
	0x57 /* JBistore3 (16r3E) <islot><write><encodedparam>*/,
	0x34 /* JBlstore0 (16r3F) <dslot><write><encodedparam>*/,
	0x35 /* JBlstore1 (16r40) <dslot><write><encodedparam>*/,
	0x36 /* JBlstore2 (16r41) <dslot><write><encodedparam>*/,
	0x37 /* JBlstore3 (16r42) <dslot><write><encodedparam>*/,
	0x54 /* JBfstore0 (16r43) <islot><write><encodedparam>*/,
	0x55 /* JBfstore1 (16r44) <islot><write><encodedparam>*/,
	0x56 /* JBfstore2 (16r45) <islot><write><encodedparam>*/,
	0x57 /* JBfstore3 (16r46) <islot><write><encodedparam>*/,
	0x34 /* JBdstore0 (16r47) <dslot><write><encodedparam>*/,
	0x35 /* JBdstore1 (16r48) <dslot><write><encodedparam>*/,
	0x36 /* JBdstore2 (16r49) <dslot><write><encodedparam>*/,
	0x37 /* JBdstore3 (16r4A) <dslot><write><encodedparam>*/,
	0x94 /* JBastore0 (16r4B) <oslot><write><encodedparam>*/,
	0x95 /* JBastore1 (16r4C) <oslot><write><encodedparam>*/,
	0x96 /* JBastore2 (16r4D) <oslot><write><encodedparam>*/,
	0x97 /* JBastore3 (16r4E) <oslot><write><encodedparam>*/,
	0x0 /* JBiastore (16r4F) */,
	0x0 /* JBlastore (16r50) */,
	0x0 /* JBfastore (16r51) */,
	0x0 /* JBdastore (16r52) */,
	0x0 /* JBaastore (16r53) */,
	0x0 /* JBbastore (16r54) */,
	0x0 /* JBcastore (16r55) */,
	0x0 /* JBsastore (16r56) */,
	0x0 /* JBpop (16r57) */,
	0x0 /* JBpop2 (16r58) */,
	0x0 /* JBdup (16r59) */,
	0x0 /* JBdupx1 (16r5A) */,
	0x0 /* JBdupx2 (16r5B) */,
	0x0 /* JBdup2 (16r5C) */,
	0x0 /* JBdup2x1 (16r5D) */,
	0x0 /* JBdup2x2 (16r5E) */,
	0x0 /* JBswap (16r5F) */,
	0x0 /* JBiadd (16r60) */,
	0x0 /* JBladd (16r61) */,
	0x0 /* JBfadd (16r62) */,
	0x0 /* JBdadd (16r63) */,
	0x0 /* JBisub (16r64) */,
	0x0 /* JBlsub (16r65) */,
	0x0 /* JBfsub (16r66) */,
	0x0 /* JBdsub (16r67) */,
	0x0 /* JBimul (16r68) */,
	0x0 /* JBlmul (16r69) */,
	0x0 /* JBfmul (16r6A) */,
	0x0 /* JBdmul (16r6B) */,
	0x0 /* JBidiv (16r6C) */,
	0x0 /* JBldiv (16r6D) */,
	0x0 /* JBfdiv (16r6E) */,
	0x0 /* JBddiv (16r6F) */,
	0x0 /* JBirem (16r70) */,
	0x0 /* JBlrem (16r71) */,
	0x0 /* JBfrem (16r72) */,
	0x0 /* JBdrem (16r73) */,
	0x0 /* JBineg (16r74) */,
	0x0 /* JBlneg (16r75) */,
	0x0 /* JBfneg (16r76) */,
	0x0 /* JBdneg (16r77) */,
	0x0 /* JBishl (16r78) */,
	0x0 /* JBlshl (16r79) */,
	0x0 /* JBishr (16r7A) */,
	0x0 /* JBlshr (16r7B) */,
	0x0 /* JBiushr (16r7C) */,
	0x0 /* JBlushr (16r7D) */,
	0x0 /* JBiand (16r7E) */,
	0x0 /* JBland (16r7F) */,
	0x0 /* JBior (16r80) */,
	0x0 /* JBlor (16r81) */,
	0x0 /* JBixor (16r82) */,
	0x0 /* JBlxor (16r83) */,
	0x40 /* JBiinc (16r84) <islot><read>*/,
	0x0 /* JBi2l (16r85) */,
	0x0 /* JBi2f (16r86) */,
	0x0 /* JBi2d (16r87) */,
	0x0 /* JBl2i (16r88) */,
	0x0 /* JBl2f (16r89) */,
	0x0 /* JBl2d (16r8A) */,
	0x0 /* JBf2i (16r8B) */,
	0x0 /* JBf2l (16r8C) */,
	0x0 /* JBf2d (16r8D) */,
	0x0 /* JBd2i (16r8E) */,
	0x0 /* JBd2l (16r8F) */,
	0x0 /* JBd2f (16r90) */,
	0x0 /* JBi2b (16r91) */,
	0x0 /* JBi2c (16r92) */,
	0x0 /* JBi2s (16r93) */,
	0x0 /* JBlcmp (16r94) */,
	0x0 /* JBfcmpl (16r95) */,
	0x0 /* JBfcmpg (16r96) */,
	0x0 /* JBdcmpl (16r97) */,
	0x0 /* JBdcmpg (16r98) */,
	0x0 /* JBifeq (16r99) */,
	0x0 /* JBifne (16r9A) */,
	0x0 /* JBiflt (16r9B) */,
	0x0 /* JBifge (16r9C) */,
	0x0 /* JBifgt (16r9D) */,
	0x0 /* JBifle (16r9E) */,
	0x0 /* JBificmpeq (16r9F) */,
	0x0 /* JBificmpne (16rA0) */,
	0x0 /* JBificmplt (16rA1) */,
	0x0 /* JBificmpge (16rA2) */,
	0x0 /* JBificmpgt (16rA3) */,
	0x0 /* JBificmple (16rA4) */,
	0x0 /* JBifacmpeq (16rA5) */,
	0x0 /* JBifacmpne (16rA6) */,
	0x0 /* JBgoto (16rA7) */,
	0x0 /* JBunimplemented (16rA8) */,
	0x0 /* JBunimplemented (16rA9) */,
	0x0 /* JBtableswitch (16rAA) */,
	0x0 /* JBlookupswitch (16rAB) */,
	0x0 /* JBreturn0 (16rAC) */,
	0x0 /* JBreturn1 (16rAD) */,
	0x0 /* JBreturn2 (16rAE) */,
	0x0 /* JBsyncReturn0 (16rAF) */,
	0x0 /* JBsyncReturn1 (16rB0) */,
	0x0 /* JBsyncReturn2 (16rB1) */,
	0x0 /* JBgetstatic (16rB2) */,
	0x0 /* JBputstatic (16rB3) */,
	0x0 /* JBgetfield (16rB4) */,
	0x0 /* JBputfield (16rB5) */,
	0x0 /* JBinvokevirtual (16rB6) */,
	0x0 /* JBinvokespecial (16rB7) */,
	0x0 /* JBinvokestatic (16rB8) */,
	0x0 /* JBinvokeinterface (16rB9) */,
	0x0 /* JBinvokedynamic (16rBA) */,
	0x0 /* JBnew (16rBB) */,
	0x0 /* JBnewarray (16rBC) */,
	0x0 /* JBanewarray (16rBD) */,
	0x0 /* JBarraylength (16rBE) */,
	0x0 /* JBathrow (16rBF) */,
	0x0 /* JBcheckcast (16rC0) */,
	0x0 /* JBinstanceof (16rC1) */,
	0x0 /* JBmonitorenter (16rC2) */,
	0x0 /* JBmonitorexit (16rC3) */,
	0x0 /* JBunimplemented (16rC4) */,
	0x0 /* JBmultianewarray (16rC5) */,
	0x0 /* JBifnull (16rC6) */,
	0x0 /* JBifnonnull (16rC7) */,
	0x0 /* JBgotow (16rC8) */,
	0x0 /* JBunimplemented (16rC9) */,
	0x0 /* JBbreakpoint (16rCA) */,
	0x0 /* JBaconst_init (16rCB) */,
	0x0 /* JBwithfield (16rCC) */,
	0x0 /* JBunimplemented (16rCD) */,
	0x0 /* JBunimplemented (16rCE) */,
	0x0 /* JBunimplemented (16rCF) */,
	0x0 /* JBunimplemented (16rD0) */,
	0x0 /* JBunimplemented (16rD1) */,
	0x0 /* JBunimplemented (16rD2) */,
	0x0 /* JBunimplemented (16rD3) */,
	0x0 /* JBunimplemented (16rD4) */,
	0x48 /* JBiincw (16rD5) <islot><wide><read>*/,
	0x0 /* JBunimplemented (16rD6) */,
	0x84 /* JBaload0getfield (16rD7) <oslot><read><encodedparam>*/,
	0x0 /* JBnewdup (16rD8) */,
	0x48 /* JBiloadw (16rD9) <islot><wide><read>*/,
	0x28 /* JBlloadw (16rDA) <dslot><wide><read>*/,
	0x48 /* JBfloadw (16rDB) <islot><wide><read>*/,
	0x28 /* JBdloadw (16rDC) <dslot><wide><read>*/,
	0x88 /* JBaloadw (16rDD) <oslot><wide><read>*/,
	0x58 /* JBistorew (16rDE) <islot><wide><write>*/,
	0x38 /* JBlstorew (16rDF) <dslot><wide><write>*/,
	0x58 /* JBfstorew (16rE0) <islot><wide><write>*/,
	0x38 /* JBdstorew (16rE1) <dslot><wide><write>*/,
	0x98 /* JBastorew (16rE2) <oslot><wide><write>*/,
	0x0 /* JBunimplemented (16rE3) */,
	0x0 /* JBreturnFromConstructor (16rE4) */,
	0x0 /* JBgenericReturn (16rE5) */,
	0x0 /* JBunimplemented (16rE6) */,
	0x0 /* JBinvokeinterface2 (16rE7) */,
	0x0 /* JBinvokehandle (16rE8) */,
	0x0 /* JBinvokehandlegeneric (16rE9) */,
	0x0 /* JBinvokestaticsplit (16rEA) */,
	0x0 /* JBinvokespecialsplit (16rEB) */,
	0x0 /* JBunimplemented (16rEC) */,
	0x0 /* JBunimplemented (16rED) */,
	0x0 /* JBunimplemented (16rEE) */,
	0x0 /* JBunimplemented (16rEF) */,
	0x0 /* JBunimplemented (16rF0) */,
	0x0 /* JBunimplemented (16rF1) */,
	0x0 /* JBunimplemented (16rF2) */,
	0x0 /* JBunimplemented (16rF3) */,
	0x0 /* JBretFromNative0 (16rF4) */,
	0x0 /* JBretFromNative1 (16rF5) */,
	0x0 /* JBretFromNativeF (16rF6) */,
	0x0 /* JBretFromNativeD (16rF7) */,
	0x0 /* JBretFromNativeJ (16rF8) */,
	0x0 /* JBldc2dw (16rF9) */,
	0x0 /* JBasyncCheck (16rFA) */,
	0x0 /* JBreturnFromJ2I (16rFB) */,
	0x0 /* JBunimplemented (16rFC) */,
	0x0 /* JBunimplemented (16rFD) */,
	0x0 /* JBimpdep1 (16rFE) */,
	0x0 /* JBimpdep2 (16rFF) */
};
