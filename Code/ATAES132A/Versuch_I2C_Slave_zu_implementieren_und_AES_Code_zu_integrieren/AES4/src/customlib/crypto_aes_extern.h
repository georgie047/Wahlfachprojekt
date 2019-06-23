/*********************************************************************************************************************
* DAVE APP Name : CRYPTO_AES       APP Version: 4.0.8
*
* NOTE:
* This file is generated by DAVE. Any manual modification done to this file will be lost when the code is regenerated.
*********************************************************************************************************************/

/**
 * @cond
 ***********************************************************************************************************************
 * Copyright (c) 2015, Infineon Technologies AG
 * All rights reserved.
 *
 * Redistribution and use in source and binary forms, with or without modification,are permitted provided that the
 * following conditions are met:
 *
 *   Redistributions of source code must retain the above copyright notice, this list of conditions and the  following
 *   disclaimer.
 *
 *   Redistributions in binary form must reproduce the above copyright notice, this list of conditions and the
 *   following disclaimer in the documentation and/or other materials provided with the distribution.
 *
 *   Neither the name of the copyright holders nor the names of its contributors may be used to endorse or promote
 *   products derived from this software without specific prior written permission.
 *
 * THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS "AS IS" AND ANY EXPRESS OR IMPLIED WARRANTIES,
 * INCLUDING, BUT NOT LIMITED TO, THE IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE ARE
 * DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT HOLDER OR CONTRIBUTORS BE LIABLE  FOR ANY DIRECT, INDIRECT, INCIDENTAL,
 * SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR
 * SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY,
 * WHETHER IN CONTRACT, STRICT LIABILITY,OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT  OF THE
 * USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.
 *
 * To improve the quality of the software, users are encouraged to share modifications, enhancements or bug fixes
 * with Infineon Technologies AG (dave@infineon.com).
 ***********************************************************************************************************************
 *
 * Change History
 * --------------
 *
 * 2015-02-16:
 *     - Initial version <br>
 *
 * 2015-04-21:
 *     - Name changes: Name changes: crypto_aes_init_vector, crypto_aes_encryption_key <br>
 *
 * 2015-06-20:
 *     - Update license/version information <br>
 *
 * @endcond
 */

#ifndef CRYPTO_AES_EXTERN_H
#define CRYPTO_AES_EXTERN_H

/* Support for C++ interwork */
#ifdef __cplusplus
extern "C" {
#endif

/***********************************************************************************************************************
 * HEADER FILES
 **********************************************************************************************************************/
 
/**********************************************************************************************************************
 * MACROS
 **********************************************************************************************************************/

/*
 * A reference to the init. vector
 * specified in the CRYPTO_AES GUI
 */
extern const uint8_t crypto_aes_init_vector[];
extern const uint8_t crypto_aes_encryption_key[];

/***********************************************************************************************************************
 * EXTERN DECLARATIONS
 ***********************************************************************************************************************/

extern CRYPTO_AES_t CRYPTO_AES_0;
 
/* Support for C++ interwork */
#ifdef __cplusplus
}
#endif 

#endif /* CRYPTO_AES_EXTERN_H */

