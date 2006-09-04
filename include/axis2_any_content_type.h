/*
 * Copyright 2004,2005 The Apache Software Foundation.
 *
 * Licensed under the Apache License, Version 2.0 (the "License");
 * you may not use this file except in compliance with the License.
 * You may obtain a copy of the License at
 *
 *      http://www.apache.org/licenses/LICENSE-2.0
 *
 * Unless required by applicable law or agreed to in writing, software
 * distributed under the License is distributed on an "AS IS" BASIS,
 * WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 * See the License for the specific language governing permissions and
 * limitations under the License.
 */

#ifndef AXIS2_ANY_CONTENT_TYPE_H
#define AXIS2_ANY_CONTENT_TYPE_H

/**
 * @defgroup axis2_any_content_type any content type
 * @ingroup axis2_addr
 * any content type acts as a container for any type reference parameters that 
 * could be associated with an endpoint reference. The values in the map are 
 * stored in string format, with QNames as key values. 
 * @{
 */


/**
 * @file axis2_any_content_type.h
 */

#include <axis2_defines.h>
#include <axis2_env.h>
#include <axis2_const.h>
#include <axis2_hash.h>
#include <axis2_qname.h>

#ifdef __cplusplus
extern "C"
{
#endif

    /** Type name for axis2_any_content_type */
    typedef struct axis2_any_content_type axis2_any_content_type_t;
    /** Type name for axis2_any_content_type_ops */
    typedef struct axis2_any_content_type_ops axis2_any_content_type_ops_t;

    /**
     * any_content_type ops struct. 
     */
    struct axis2_any_content_type_ops
    {
        /**
         * Adds given value to content value map with given QName.
         * @param any_content_type pointer to any content type struct
         * @param env pointer to environment struct
         * @param qname pointer to QName to be used as key
         * @param value value string to be added
         * @return AXIS2_SUCCESS on success else AXIS2_FAILURE
         */
        axis2_status_t (AXIS2_CALL *
                add_value)(
                    struct axis2_any_content_type *any_content_type,
                    const axis2_env_t *env,
                    const axis2_qname_t *qname,
                    const axis2_char_t *value);

        /**
         * Gets the value corresponding to the given QName from the content 
         * value map.
         * @param any_content_type pointer to any content type struct
         * @param env pointer to environment struct
         * @param qname pointer to QName of the corresponding value to be 
         * retrieved
         * @return value string if present, else returns NULL
         */
        const axis2_char_t *(AXIS2_CALL *
                get_value)(
                    const axis2_any_content_type_t *any_content_type,
                    const axis2_env_t *env,
                    const axis2_qname_t *qname);
        /**
         * Gets the map of all values.
         * @param any_content_type pointer to any content type struct
         * @param env pointer to environment struct
         * @return pointer to hash table containing all values, returns a 
         * reference, not a cloned copy 
         */
        axis2_hash_t *(AXIS2_CALL *
                get_value_map)(
                    const axis2_any_content_type_t *any_content_type,
                    const axis2_env_t *env);

        /**
         * Frees any content type struct.
         * @param any_content_type pointer to any content type struct
         * @param env pointer to environment struct
         * @return AXIS2_SUCCESS on success else AXIS2_FAILURE
         */
        axis2_status_t (AXIS2_CALL *
                free)(
                    struct axis2_any_content_type *any_content_type,
                    const axis2_env_t *env);

    };

    /**
     * axis2 any content type struct.
     */
    struct axis2_any_content_type
    {
        /** operations of axis2 any content type struct */
        axis2_any_content_type_ops_t *ops;
    };


    /**
     * creates an instance of any content type struct.
     * @param env pointer to environment struct
     * @return pointer to the newly created any content type instance
     */
    AXIS2_EXTERN axis2_any_content_type_t *AXIS2_CALL
    axis2_any_content_type_create(
        const axis2_env_t *env);


/** Adds given value with given QName to the value map.
    @sa axis2_any_content_type_ops#add_value */
#define AXIS2_ANY_CONTENT_TYPE_ADD_VALUE(any_content_type, env, qname, value) \
    ((any_content_type)->ops->add_value(any_content_type, env, qname, value))

/** Gets value corresponding to given QName.
    @sa axis2_any_content_type_ops#get_value */
#define AXIS2_ANY_CONTENT_TYPE_GET_VALUE(any_content_type, env, qname) \
    ((any_content_type)->ops->get_value(any_content_type, env, qname))

/** Gets the value map.
    @sa axis2_any_content_type_ops#get_value_map */
#define AXIS2_ANY_CONTENT_TYPE_GET_VALUE_MAP(any_content_type, env) \
    ((any_content_type)->ops->get_value_map(any_content_type, env))

/** Frees any content type struct.
    @sa axis2_any_content_type_ops#free */
#define AXIS2_ANY_CONTENT_TYPE_FREE(any_content_type, env) \
    ((any_content_type)->ops->free(any_content_type, env))


/** @} */

#ifdef __cplusplus
}
#endif

#endif    /* AXIS2_ANY_CONTENT_TYPE_H */
