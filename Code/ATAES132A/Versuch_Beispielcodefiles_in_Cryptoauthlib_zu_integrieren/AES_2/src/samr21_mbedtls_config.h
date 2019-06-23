#ifndef SAMR21_MBEDTLS_CONFIG_H
#define SAMR21_MBEDTLS_CONFIG_H

/**
 * \def MBEDTLS_AES_ALT
 *
 * Enable hardware acceleration for the AES block cipher
 *
 * Module:  sl_crypto/src/sl_aes.c
 *          or
 *          sl_crypto/src/slcl_aes.c if MBEDTLS_SLCL_PLUGINS is defined.
 *
 * See MBEDTLS_AES_C for more information.
 */
#define MBEDTLS_AES_ALT

#define MBEDTLS_CTR_DRBG_USE_128_BIT_KEY

#endif