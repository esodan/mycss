/*
 Copyright (C) 2016 Alexander Borisov
 
 This library is free software; you can redistribute it and/or
 modify it under the terms of the GNU Lesser General Public
 License as published by the Free Software Foundation; either
 version 2.1 of the License, or (at your option) any later version.
 
 This library is distributed in the hope that it will be useful,
 but WITHOUT ANY WARRANTY; without even the implied warranty of
 MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the GNU
 Lesser General Public License for more details.
 
 You should have received a copy of the GNU Lesser General Public
 License along with this library; if not, write to the Free Software
 Foundation, Inc., 51 Franklin Street, Fifth Floor, Boston, MA 02110-1301 USA
 
 Author: lex.borisov@gmail.com (Alexander Borisov)
*/

#ifndef MyHTML_MyCSS_MYOSI_H
#define MyHTML_MyCSS_MYOSI_H
#pragma once

#ifdef __cplusplus
extern "C" {
#endif

#include <myhtml/myosi.h>


// base
/*
 Very important!!!
 
 for myhtml             0..00ffff;      MyHTML_STATUS_OK    == 0x000000
 for mycss and modules  010000..01ffff; MyCSS_STATUS_OK     == 0x000000
 for myrender           020000..02ffff; MyRENDER_STATUS_OK  == 0x000000
 for mydom              030000..03ffff; MyDOM_STATUS_OK     == 0x000000
 for mynetwork          040000..04ffff; MyNETWORK_STATUS_OK == 0x000000
 for myecma             050000..05ffff; MyECMA_STATUS_OK    == 0x000000
 not occupied           060000..
*/
enum mycss_status {
    MyCSS_STATUS_OK                                     = 0x000000,
    MyCSS_STATUS_ERROR_MEMORY_ALLOCATION                = 0x010001,
    MyCSS_STATUS_ERROR_TOKENIZER_STATE_ALLOCATION       = 0x010020,
    MyCSS_STATUS_ERROR_TOKENIZER_INCOMING_BUFFER_ADD    = 0x010021,
    MyCSS_STATUS_ERROR_TOKENIZER_TOKEN_ALLOCATION       = 0x010022,
    MyCSS_STATUS_ERROR_INCOMING_BUFFER_INIT             = 0x010030,
    MyCSS_STATUS_ERROR_ENTRY_INCOMING_BUFFER_CREATE     = 0x010039,
    MyCSS_STATUS_ERROR_ENTRY_INCOMING_BUFFER_INIT       = 0x010040,
    MyCSS_STATUS_ERROR_ENTRY_TOKEN_INCOMING_BUFFER_INIT = 0x010041,
    MyCSS_STATUS_ERROR_ENTRY_TOKEN_NODE_ADD             = 0x010042,
    MyCSS_STATUS_ERROR_SELECTORS_CREATE                 = 0x010100,
    MyCSS_STATUS_ERROR_SELECTORS_ENTRIES_CREATE         = 0x010101,
    MyCSS_STATUS_ERROR_SELECTORS_ENTRIES_INIT           = 0x010102,
    MyCSS_STATUS_ERROR_SELECTORS_ENTRIES_NODE_ADD       = 0x010103,
    MyCSS_STATUS_ERROR_NAMESPACE_CREATE                 = 0x010200,
    MyCSS_STATUS_ERROR_NAMESPACE_INIT                   = 0x010201,
    MyCSS_STATUS_ERROR_NAMESPACE_ENTRIES_CREATE         = 0x010202,
    MyCSS_STATUS_ERROR_NAMESPACE_ENTRIES_INIT           = 0x010203,
    MyCSS_STATUS_ERROR_NAMESPACE_NODE_ADD               = 0x010204,
    MyCSS_STATUS_ERROR_RESULT_CREATE                    = 0x010300,
    MyCSS_STATUS_ERROR_RESULT_ENTRIES_CREATE            = 0x010301,
    MyCSS_STATUS_ERROR_RESULT_ENTRIES_INIT              = 0x010302,
    MyCSS_STATUS_ERROR_RESULT_ENTRIES_ADD_NODE          = 0x010303,
    MyCSS_STATUS_ERROR_RULES_CREATE                     = 0x010400,
    MyCSS_STATUS_ERROR_STRING_CREATE                    = 0x010501,
    MyCSS_STATUS_ERROR_STRING_INIT                      = 0x010502,
    MyCSS_STATUS_ERROR_STRING_NODE_INIT                 = 0x010503,
    MyCSS_STATUS_ERROR_AN_PLUS_B_CREATE                 = 0x010600,
    MyCSS_STATUS_ERROR_AN_PLUS_B_INIT                   = 0x010601
}
typedef mycss_status_t;

#define MyCSS_FAILED(_status_) ((_status_) != MyCSS_STATUS_OK)

// entry
typedef struct mycss_entry mycss_entry_t;

enum mycss_entry_type {
    MyCSS_ENTRY_TYPE_CLEAN = 0x0000,
    MyCSS_ENTRY_TYPE_END   = 0x0001
}
typedef mycss_entry_type_t;

// mycss
typedef struct mycss mycss_t;

// mycss_tokenizer
typedef struct mycss_token mycss_token_t;

enum mycss_tokenizer_state {
    MyCSS_TOKENIZER_STATE_DATA                                 = 0x000,
    //
    // generated by Perl script utils/mycss_first_char.pl
    MyCSS_TOKENIZER_STATE_APOSTROPHE                           = 0x001,
    MyCSS_TOKENIZER_STATE_ASTERISK                             = 0x002,
    MyCSS_TOKENIZER_STATE_CIRCUMFLEX_ACCENT                    = 0x003,
    MyCSS_TOKENIZER_STATE_COLON                                = 0x004,
    MyCSS_TOKENIZER_STATE_COMMA                                = 0x005,
    MyCSS_TOKENIZER_STATE_COMMERCIAL_AT                        = 0x006,
    MyCSS_TOKENIZER_STATE_DELIM_SINGLE_CODE_POINT              = 0x007,
    MyCSS_TOKENIZER_STATE_DIGIT                                = 0x008,
    MyCSS_TOKENIZER_STATE_DOLLAR_SIGN                          = 0x009,
    MyCSS_TOKENIZER_STATE_FULL_STOP                            = 0x00a,
    MyCSS_TOKENIZER_STATE_HYPHEN_MINUS                         = 0x00b,
    MyCSS_TOKENIZER_STATE_LEFT_CURLY_BRACKET                   = 0x00c,
    MyCSS_TOKENIZER_STATE_LEFT_PARENTHESIS                     = 0x00d,
    MyCSS_TOKENIZER_STATE_LEFT_SQUARE_BRACKET                  = 0x00e,
    MyCSS_TOKENIZER_STATE_LESS_THAN_SIGN                       = 0x00f,
    MyCSS_TOKENIZER_STATE_NAME_START_CODE_POINT                = 0x010,
    MyCSS_TOKENIZER_STATE_NUMBER_SIGN                          = 0x011,
    MyCSS_TOKENIZER_STATE_PLUS_SIGN                            = 0x012,
    MyCSS_TOKENIZER_STATE_QUOTATION_MARK                       = 0x013,
    MyCSS_TOKENIZER_STATE_REVERSE_SOLIDUS                      = 0x014,
    MyCSS_TOKENIZER_STATE_RIGHT_CURLY_BRACKET                  = 0x015,
    MyCSS_TOKENIZER_STATE_RIGHT_PARENTHESIS                    = 0x016,
    MyCSS_TOKENIZER_STATE_RIGHT_SQUARE_BRACKET                 = 0x017,
    MyCSS_TOKENIZER_STATE_SEMICOLON                            = 0x018,
    MyCSS_TOKENIZER_STATE_SOLIDUS                              = 0x019,
    MyCSS_TOKENIZER_STATE_TILDE                                = 0x01a,
    MyCSS_TOKENIZER_STATE_VERTICAL_LINE                        = 0x01b,
    MyCSS_TOKENIZER_STATE_WHITESPACE                           = 0x01c,
    // end generated code
    //
    
    MyCSS_TOKENIZER_STATE_QUOTATION_MARK_BACK                  = 0x01d,
    
    MyCSS_TOKENIZER_STATE_NUMBER_SIGN_NAME_BACK                = 0x01e,
    MyCSS_TOKENIZER_STATE_NUMBER_SIGN_NAME_RSOLIDUS            = 0x01f,
    
    MyCSS_TOKENIZER_STATE_APOSTROPHE_BACK                      = 0x020,
    
    MyCSS_TOKENIZER_STATE_HYPHEN_MINUS_RSOLIDUS                = 0x021,
    MyCSS_TOKENIZER_STATE_HYPHEN_MINUS_MINUS                   = 0x022,
    MyCSS_TOKENIZER_STATE_HYPHEN_MINUS_MINUS_RSOLIDUS          = 0x023,
    MyCSS_TOKENIZER_STATE_HYPHEN_MINUS_FULL_STOP               = 0x024,
    
    MyCSS_TOKENIZER_STATE_SOLIDUS_COMMENT_END                  = 0x025,
    
    MyCSS_TOKENIZER_STATE_COMMERCIAL_AT_RSOLIDUS               = 0x026,
    MyCSS_TOKENIZER_STATE_COMMERCIAL_AT_BACK                   = 0x027,
    MyCSS_TOKENIZER_STATE_COMMERCIAL_AT_MINUS                  = 0x028,
    MyCSS_TOKENIZER_STATE_COMMERCIAL_AT_MINUS_RSOLIDUS         = 0x029,
    
    MyCSS_TOKENIZER_STATE_LESS_THAN_SIGN_MINUS                 = 0x02a,
    MyCSS_TOKENIZER_STATE_LESS_THAN_SIGN_MINUS_MINUS           = 0x02b,
    
    MyCSS_TOKENIZER_STATE_PLUS_SIGN_FULL_STOP                  = 0x02c,
    
    MyCSS_TOKENIZER_STATE_LETTER_U                             = 0x02d,
    MyCSS_TOKENIZER_STATE_LETTER_U_NEXT                        = 0x02e,
    
    // global
    MyCSS_TOKENIZER_GLOBAL_STATE_NUMBER_DIGIT                  = 0x050,
    MyCSS_TOKENIZER_GLOBAL_STATE_NUMBER_DECIMAL                = 0x051,
    MyCSS_TOKENIZER_GLOBAL_STATE_NUMBER_DOT                    = 0x052,
    MyCSS_TOKENIZER_GLOBAL_STATE_NUMBER_E                      = 0x053,
    MyCSS_TOKENIZER_GLOBAL_STATE_NUMBER_E_PLUS_MINUS           = 0x054,
    MyCSS_TOKENIZER_GLOBAL_STATE_NUMBER_E_DECIMAL              = 0x055,
    
    // Consume a numeric token
    MyCSS_TOKENIZER_GLOBAL_STATE_NUMERIC                       = 0x056,
    MyCSS_TOKENIZER_GLOBAL_STATE_NUMERIC_RSOLIDUS              = 0x057,
    MyCSS_TOKENIZER_GLOBAL_STATE_NUMERIC_MINUS                 = 0x058,
    MyCSS_TOKENIZER_GLOBAL_STATE_NUMERIC_MINUS_RSOLIDUS        = 0x059,
    
    // Consume an ident-like token
    MyCSS_TOKENIZER_GLOBAL_STATE_IDENT                         = 0x05a,
    
    // Consume a url token
    MyCSS_TOKENIZER_GLOBAL_STATE_URL                           = 0x05b,
    MyCSS_TOKENIZER_GLOBAL_STATE_URL_STRING_BACK               = 0x05c,
    MyCSS_TOKENIZER_GLOBAL_STATE_URL_AFTER                     = 0x05d,
    MyCSS_TOKENIZER_GLOBAL_STATE_URL_AFTER_WHITESPACE          = 0x05e,
    MyCSS_TOKENIZER_GLOBAL_STATE_URL_RSOLIDUS                  = 0x05f,
    MyCSS_TOKENIZER_GLOBAL_STATE_BAD_URL                       = 0x060,
    
    // Consume a string token
    MyCSS_TOKENIZER_GLOBAL_STATE_STRING_DOUBLE_QUOTED            = 0x061,
    MyCSS_TOKENIZER_GLOBAL_STATE_STRING_DOUBLE_QUOTED_RSOLIDUS   = 0x062,
    MyCSS_TOKENIZER_GLOBAL_STATE_STRING_DOUBLE_QUOTED_RSOLIDUS_R = 0x063,
    MyCSS_TOKENIZER_GLOBAL_STATE_STRING_SINGLE_QUOTED            = 0x064,
    MyCSS_TOKENIZER_GLOBAL_STATE_STRING_SINGLE_QUOTED_RSOLIDUS   = 0x065,
    MyCSS_TOKENIZER_GLOBAL_STATE_STRING_SINGLE_QUOTED_RSOLIDUS_R = 0x066,
    
    // Consume a name
    MyCSS_TOKENIZER_GLOBAL_STATE_NAME                          = 0x067,
    MyCSS_TOKENIZER_GLOBAL_STATE_NAME_RSOLIDUS                 = 0x068,
    
    // Consume a unicode-range token
    MyCSS_TOKENIZER_GLOBAL_STATE_UNICODE_RANGE_BEFORE          = 0x069,
    MyCSS_TOKENIZER_GLOBAL_STATE_UNICODE_RANGE                 = 0x06a,
    MyCSS_TOKENIZER_GLOBAL_STATE_UNICODE_RANGE_QUESTION        = 0x06b,
    MyCSS_TOKENIZER_GLOBAL_STATE_UNICODE_RANGE_MINUS           = 0x06c,
    
    // back
    MyCSS_TOKENIZER_GLOBAL_BACK                                = 0x080,
    
    MyCSS_TOKENIZER_STATE_FIRST_ENTRY                          = MyCSS_TOKENIZER_STATE_DATA,
    MyCSS_TOKENIZER_STATE_LAST_ENTRY                           = 0x100
}
typedef mycss_tokenizer_state_t;

enum mycss_token_type {
    MyCSS_TOKEN_TYPE_UNDEF                = 0x0000,
    MyCSS_TOKEN_TYPE_WHITESPACE           = 0x0001,
    MyCSS_TOKEN_TYPE_IDENT                = 0x0002,
    MyCSS_TOKEN_TYPE_FUNCTION             = 0x0003,
    MyCSS_TOKEN_TYPE_AT_KEYWORD           = 0x0004,
    MyCSS_TOKEN_TYPE_HASH                 = 0x0005,
    MyCSS_TOKEN_TYPE_STRING               = 0x0006,
    MyCSS_TOKEN_TYPE_URL                  = 0x0007,
    MyCSS_TOKEN_TYPE_NUMBER               = 0x0008,
    MyCSS_TOKEN_TYPE_DIMENSION            = 0x0009,
    MyCSS_TOKEN_TYPE_PERCENTAGE           = 0x000a,
    MyCSS_TOKEN_TYPE_INCLUDE_MATCH        = 0x000b,
    MyCSS_TOKEN_TYPE_DASH_MATCH           = 0x000c,
    MyCSS_TOKEN_TYPE_PREFIX_MATCH         = 0x000d,
    MyCSS_TOKEN_TYPE_SUFFIX_MATCH         = 0x000e,
    MyCSS_TOKEN_TYPE_SUBSTRING_MATCH      = 0x000f,
    MyCSS_TOKEN_TYPE_COLUMN               = 0x0010,
    MyCSS_TOKEN_TYPE_CDO                  = 0x0011,
    MyCSS_TOKEN_TYPE_CDC                  = 0x0012,
    MyCSS_TOKEN_TYPE_BAD_STRING           = 0x0013,
    MyCSS_TOKEN_TYPE_DELIM                = 0x0014,
    MyCSS_TOKEN_TYPE_LEFT_PARENTHESIS     = 0x0015,
    MyCSS_TOKEN_TYPE_RIGHT_PARENTHESIS    = 0x0016,
    MyCSS_TOKEN_TYPE_COMMA                = 0x0017,
    MyCSS_TOKEN_TYPE_COLON                = 0x0018,
    MyCSS_TOKEN_TYPE_SEMICOLON            = 0x0019,
    MyCSS_TOKEN_TYPE_LEFT_SQUARE_BRACKET  = 0x001a,
    MyCSS_TOKEN_TYPE_RIGHT_SQUARE_BRACKET = 0x001b,
    MyCSS_TOKEN_TYPE_LEFT_CURLY_BRACKET   = 0x001c,
    MyCSS_TOKEN_TYPE_RIGHT_CURLY_BRACKET  = 0x001d,
    MyCSS_TOKEN_TYPE_BAD_URL              = 0x001e,
    MyCSS_TOKEN_TYPE_COMMENT              = 0x001f,
    MyCSS_TOKEN_TYPE_UNICODE_RANGE        = 0x0020,
    MyCSS_TOKEN_TYPE_LAST_ENTRY           = 0x0021
}
typedef mycss_token_type_t;

// an+b
typedef struct mycss_an_plus_b mycss_an_plus_b_t;
typedef struct mycss_an_plus_b_entry mycss_an_plus_b_entry_t;

// result
typedef struct mycss_result_list_parser mycss_result_list_parser_t;
typedef struct mycss_result_list mycss_result_list_t;
typedef struct mycss_result_entry mycss_result_entry_t;
typedef struct mycss_result mycss_result_t;

enum mycss_result_entry_type {
    MyCSS_RESULT_ENTRY_TYPE_UNDEF = 0x00,
    MyCSS_RESULT_ENTRY_TYPE_GOOD  = 0x01,
    MyCSS_RESULT_ENTRY_TYPE_BAD   = 0x02
}
typedef mycss_result_entry_type_t;

// mystring
typedef struct mycss_string_escaped_res mycss_string_escaped_res_t;
typedef struct mycss_string_res mycss_string_res_t;

typedef size_t (*mycss_tokenizer_state_f)(mycss_entry_t* entry, mycss_token_t* token, const char* css, size_t css_offset, size_t css_size);
typedef mycss_token_t * (*mycss_token_ready_callback_f)(mycss_entry_t* entry, mycss_token_t* token);
typedef size_t (*mycss_string_process_state_f)(myhtml_string_t* str, const char* data, size_t length, size_t size, mycss_string_res_t *out_res);
typedef bool (*mycss_parser_token_f)(mycss_result_t* result, mycss_token_t* token);
typedef bool (*mycss_an_plus_b_state_f)(mycss_result_t* result, mycss_an_plus_b_t* anb, mycss_an_plus_b_entry_t* anb_entry, mycss_token_t* token);

#ifdef __cplusplus
} /* extern "C" */
#endif

#endif

